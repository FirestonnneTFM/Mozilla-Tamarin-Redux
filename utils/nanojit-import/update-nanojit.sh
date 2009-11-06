#!/bin/bash

if [ $# != 1 ]
then
    echo "usage: $0 -f"
    echo "Pulls and commits the latest nanojit-central changes to this repo"
    exit 1
fi
if [ $1 != '-f' ]; then exit 1; fi

set -x
set -e

# random part of names
RAND="$RANDOM$RANDOM"

SRCDIR=$(hg root)
SCRIPTDIR=$SRCDIR/utils/nanojit-import
TMPDIR=/tmp/nj-$RAND

NANOJIT_CENTRAL_REV=$(cat $SCRIPTDIR/nanojit-import-rev)
NANOJIT_CENTRAL_REPO=http://hg.mozilla.org/projects/nanojit-central
NANOJIT_CENTRAL_LOCAL=$TMPDIR/nanojit-central

mkdir $TMPDIR
rm -Rf $NANOJIT_CENTRAL_LOCAL $TMPDIR/import-splicemap $TMPDIR/import-revmap

hg clone $NANOJIT_CENTRAL_REPO $NANOJIT_CENTRAL_LOCAL

python $SCRIPTDIR/find-child.py \
    --src=$NANOJIT_CENTRAL_LOCAL \
    --dst=$SRCDIR \
    --start=$NANOJIT_CENTRAL_REV \
    --filemap=$SCRIPTDIR/nanojit-import-filemap \
    >$TMPDIR/import-splicemap

hg convert --config convert.hg.saverev=True \
    --config convert.hg.startrev=$(cut -d ' ' -f 1 $TMPDIR/import-splicemap) \
    --filemap=$SCRIPTDIR/nanojit-import-filemap \
    --splicemap=$TMPDIR/import-splicemap \
    $NANOJIT_CENTRAL_LOCAL \
    $SRCDIR \
    $TMPDIR/import-revmap

(cd $SRCDIR && \
    hg up)

(cd $NANOJIT_CENTRAL_LOCAL && \
    hg log -r tip --template "{node}\n") >$SCRIPTDIR/nanojit-import-rev

(cd $SRCDIR && \
    hg commit --message="Update nanojit-import-rev stamp." $SCRIPTDIR/nanojit-import-rev)

set +x
echo "This repo is now ready to push changes...ensure there is only a single head first"
echo "You may also want to clean-up the tmp directory at " $TMPDIR
