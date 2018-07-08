#! /bin/bash
revisioncount=`git log --oneline | wc -l`
projectversion=`git describe --tags --long`
cleanversion=${projectversion%%-*}
rev1=`git rev-list --tags --no-walk --max-count=1`
rev2=`git rev-list $rev1..HEAD --count`
rev3=`git log $rev1..HEAD --pretty`
rev_date=`date -u +%Y%m%d%H%M%S`

echo "Version $cleanversion.$rev2" >&2
echo "Time $rev_date" >&2
echo >&2

cat <<EOF > CHANGELOG.md
$rev3
EOF

cat <<EOF > ./source/svnrev.c
#define BUILD_VER "$cleanversion.$rev2"
#define BUILD_TIME "$rev_date"

const char *GetRev()
{
	return BUILD_VER;
}

const char *GetBuildTime()
{
	return BUILD_TIME;
}
EOF
