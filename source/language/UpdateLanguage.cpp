/****************************************************************************
 * languagefile updater
 * for USB Loader GX	*giantpune*
 *                      2015 Cyan
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dir.h>

#include "UpdateLanguage.h"
#include "gettext.h"
#include "IO/fileops.h"
#include "IO/DirList.h"
#include "menu.h"
#include "network/networkops.h"
#include "network/http.h"
#include "network/URL_List.h"
#include "prompts/PromptWindows.h"
#include "prompts/ProgressWindow.h"
#include "utils/ShowError.h"
#include "gecko.h"
#include "svnrev.h"

static const char * LanguageFilesURL = "http://svn.code.sf.net/p/usbloadergx/code/trunk/Languages/";

int DownloadAllLanguageFiles(int revision)
{
	if(!CreateSubfolder(Settings.languagefiles_path))
	{
		ShowError(tr("Could not create path: %s"), Settings.languagefiles_path);
		return -1;
	}

	if(!IsNetworkInit())
	{
		ShowError(tr("Network is not initiated."));
		return -2;
	}
	char fullURL[300];

	URL_List LinkList(LanguageFilesURL);
	int listsize = LinkList.GetURLCount();
	int files_downloaded = 0;
	char target[6];
	if(revision > 0)
		snprintf(target, sizeof(target), "%d", revision);
	else
		snprintf(target, sizeof(target), "%s", GetRev());

	ShowProgress(tr("Updating Language Files:"), 0, 0, 0, listsize, false, true);

	for (int i = 0; i < listsize; i++)
	{
		const char * filename = strrchr(LinkList.GetURL(i), '/');
		if(filename) filename++;
		else filename = LinkList.GetURL(i);

		if(!filename)
			continue;

		const char * FileExt = strrchr(filename, '.');
		if (!FileExt || strcasecmp(FileExt, ".lang") != 0)
			continue;

		gprintf("%s\n", filename);

		ShowProgress(tr("Updating Language Files:"), 0, filename, i, listsize, false, true);

		snprintf(fullURL, sizeof(fullURL), "%s%s?p=%s", LanguageFilesURL, filename, target);

		struct block file = downloadfile(fullURL);
		if (file.data)
		{
			char filepath[300];
			snprintf(filepath, sizeof(filepath), "%s/%s", Settings.languagefiles_path, filename);
			FILE * pfile = fopen(filepath, "wb");
			if(pfile)
			{
				fwrite(file.data, 1, file.size, pfile);
				fclose(pfile);
				files_downloaded++;
			}
			free(file.data);
		}
	}

	ProgressStop();

	// reload current language file
	if(Settings.language_path[0] != 0)
		Settings.LoadLanguage(Settings.language_path, CONSOLE_DEFAULT);
	else
		Settings.LoadLanguage(NULL, CONSOLE_DEFAULT);

	return files_downloaded;
}

int UpdateLanguageFiles()
{
	if(!CreateSubfolder(Settings.languagefiles_path))
	{
		ShowError(tr("Could not create path: %s"), Settings.languagefiles_path);
		return -1;
	}

	if(!IsNetworkInit())
	{
		ShowError(tr("Network is not initiated."));
		return -2;
	}

	DirList Dir(Settings.languagefiles_path, ".lang");

	//give up now if we didn't find any
	if (Dir.GetFilecount() == 0)
	{
		if(WindowPrompt(tr("Error:"), tr("No language files to update on your devices! Do you want to download new language files?"), tr("Yes"), tr("No")))
			return DownloadAllLanguageFiles();

		return -2;
	}

	char savepath[150];
	char codeurl[200];

	//we assume that the network will already be init by another function
	// ( that has gui eletents in it because this one doesn't)
	int done = 0;

	//build the URL, save path, and download each file and save it
	for(int i = 0; i < Dir.GetFilecount(); ++i)
	{
		snprintf(codeurl, sizeof(codeurl), "%s%s?p=%s", LanguageFilesURL, Dir.GetFilename(i), GetRev());
		snprintf(savepath, sizeof(savepath), "%s/%s", Settings.languagefiles_path, Dir.GetFilename(i));

		struct block file = downloadfile(codeurl);

		ShowProgress(tr("Updating Language Files:"), 0, Dir.GetFilename(i), i, Dir.GetFilecount(), false, true);

		if (file.data != NULL)
		{
			FILE * pfile;
			pfile = fopen(savepath, "wb");
			if (pfile != NULL)
			{
				fwrite(file.data, 1, file.size, pfile);
				fclose(pfile);
				done++;
			}
			free(file.data);
		}
	}

	ProgressStop();

	// reload current language file
	if(Settings.language_path[0] != 0)
		Settings.LoadLanguage(Settings.language_path, CONSOLE_DEFAULT);
	else
		Settings.LoadLanguage(NULL, CONSOLE_DEFAULT);

	// return the number of files we updated
	return done;
}

