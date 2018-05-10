#! /bin/bash
revisioncount=`git log --oneline | wc -l`
projectversion=`git describe --tags --long`
cleanversion=${projectversion%%-*}
rev_date=`date -u +%Y%m%d%H%M%S`

echo "Version $cleanversion.$revisioncount" >&2
echo "Time $rev_date" >&2
echo >&2

cat <<EOF > ./source/svnrev.c
#define BUILD_VER "$cleanversion.$revisioncount"

const char *GetRev()
{
	return BUILD_VER;
}
EOF
