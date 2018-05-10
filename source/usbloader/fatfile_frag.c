#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <gccore.h>
#include <fat.h>
#include <ogc/disc_io.h>

#include "fatfile_frag.h"

// Begin import from libfat-1.1.3

// file_allocation_table.h
#define CLUSTER_EOF_16	0xFFFF
#define	CLUSTER_EOF		0x0FFFFFFF
#define CLUSTER_FREE	0x00000000
#define CLUSTER_ROOT	0x00000000
#define CLUSTER_FIRST	0x00000002
#define CLUSTER_ERROR	0xFFFFFFFF

#define CLUSTERS_PER_FAT12 4085
#define CLUSTERS_PER_FAT16 65525
// file_allocation_table.h

// cache.h
typedef struct {
	sec_t        sector;
	unsigned int count;
	unsigned int last_access;
	bool         dirty;
	uint8_t*     cache;
} CACHE_ENTRY;

typedef struct {
	const DISC_INTERFACE* disc;
	sec_t		          endOfPartition;
	unsigned int          numberOfPages;
	unsigned int          sectorsPerPage;
	unsigned int          bytesPerSector;
	CACHE_ENTRY*          cacheEntries;
} CACHE;
// cache.h

// partition.h
// Filesystem type
typedef enum { FS_UNKNOWN, FS_FAT12, FS_FAT16, FS_FAT32 } FS_TYPE;

typedef struct {
	sec_t    fatStart;
	uint32_t sectorsPerFat;
	uint32_t lastCluster;
	uint32_t firstFree;
	uint32_t numberFreeCluster;
	uint32_t numberLastAllocCluster;
} FAT;

typedef struct {
	const DISC_INTERFACE* disc;
	CACHE*                cache;
	// Info about the partition
	FS_TYPE               filesysType;
	uint64_t              totalSize;
	sec_t                 rootDirStart;
	uint32_t              rootDirCluster;
	uint32_t              numberOfSectors;
	sec_t                 dataStart;
	uint32_t              bytesPerSector;
	uint32_t              sectorsPerCluster;
	uint32_t              bytesPerCluster;
	uint32_t              fsInfoSector;
	FAT                   fat;
	// Values that may change after construction
	uint32_t              cwdCluster;			// Current working directory cluster
	int                   openFileCount;
	struct _FILE_STRUCT*  firstOpenFile;		// The start of a linked list of files
	mutex_t               lock;					// A lock for partition operations
	bool                  readOnly;				// If this is set, then do not try writing to the disc
	char                  label[12];			// Volume label
} PARTITION;
// partition.h

// directory.h
typedef enum { FT_DIRECTORY, FT_FILE } FILE_TYPE;

typedef struct {
	uint32_t cluster;
	sec_t    sector;
	int32_t  offset;
} DIR_ENTRY_POSITION;
// directory.h

// fatfile.h
typedef struct {
	u32   cluster;
	sec_t sector;
	s32   byte;
} FILE_POSITION;

struct _FILE_STRUCT;

struct _FILE_STRUCT {
	uint32_t             filesize;
	uint32_t             startCluster;
	uint32_t             currentPosition;
	FILE_POSITION        rwPosition;
	FILE_POSITION        appendPosition;
	DIR_ENTRY_POSITION   dirEntryStart;		// Points to the start of the LFN entries of a file, or the alias for no LFN
	DIR_ENTRY_POSITION   dirEntryEnd;		// Always points to the file's alias entry
	PARTITION*           partition;
	struct _FILE_STRUCT* prevOpenFile;		// The previous entry in a double-linked list of open files
	struct _FILE_STRUCT* nextOpenFile;		// The next entry in a double-linked list of open files
	bool                 read;
	bool                 write;
	bool                 append;
	bool                 inUse;
	bool                 modified;
};

typedef struct _FILE_STRUCT FILE_STRUCT;

#ifndef mutex_t
typedef uint32_t mutex_t;
#endif

extern int _FAT_open_r(struct _reent *r, void *fileStruct, const char *path, int flags, int mode);
extern int _FAT_close_r(struct _reent *r, void *fd);
// fatfile.h

// lock.c
static inline void _FAT_lock(mutex_t *mutex)
{
	LWP_MutexLock(*mutex);
}

static inline void _FAT_unlock(mutex_t *mutex)
{
	LWP_MutexUnlock(*mutex);
}
// lock.c

// file_allocation_table.h
extern uint32_t _FAT_fat_nextCluster(PARTITION* partition, uint32_t cluster);

static inline sec_t _FAT_fat_clusterToSector(PARTITION* partition, uint32_t cluster) {
	return (cluster >= CLUSTER_FIRST) ?
		((cluster - CLUSTER_FIRST) * (sec_t)partition->sectorsPerCluster) + partition->dataStart :
		partition->rootDirStart;
}

static inline bool _FAT_fat_isValidCluster(PARTITION* partition, uint32_t cluster) {
	return (cluster >= CLUSTER_FIRST) && (cluster <= partition->fat.lastCluster /* This will catch CLUSTER_ERROR */);
}
// file_allocation_table.h
// End import 

int _FAT_get_fragments(const char *path, _fat_frag_append_t append_fragment, void *callback_data)
{
	struct _reent r;
	FILE_STRUCT file;
	PARTITION* partition;
	u32 cluster;
	u32 sector;
	u32 offset; // in sectors
	u32 size;   // in sectors
	int ret = -1;
	int fd;

	fd = _FAT_open_r(&r, &file, path, O_RDONLY, 0);
	if (fd == -1) return -1;
	if (fd != (int)&file) return -1;

	partition = file.partition;
	_FAT_lock(&partition->lock);

	size = file.filesize / partition->bytesPerSector;
	cluster = file.startCluster;
	offset = 0;

	do
	{
		if (!_FAT_fat_isValidCluster(partition, cluster))
		{
			// invalid cluster
			goto out;
		}
		// add cluster to fileinfo
		sector = _FAT_fat_clusterToSector(partition, cluster);
		if (append_fragment(callback_data, offset, sector, partition->sectorsPerCluster))
		{
			// too many fragments
			goto out;
		}

		offset += partition->sectorsPerCluster;
		cluster = _FAT_fat_nextCluster(partition, cluster);
	} while (offset < size);

	// set size
	append_fragment(callback_data, size, 0, 0);
	// success
	ret = 0;

out:
	_FAT_unlock(&partition->lock);
	_FAT_close_r(&r, (void *)fd);
	return ret;
}
