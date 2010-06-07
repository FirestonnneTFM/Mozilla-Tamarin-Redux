#!/bin/bash
#  ***** BEGIN LICENSE BLOCK *****
#  Version: MPL 1.1/GPL 2.0/LGPL 2.1
# 
#  The contents of this file are subject to the Mozilla Public License Version
#  1.1 (the "License"); you may not use this file except in compliance with
#  the License. You may obtain a copy of the License at
#  http://www.mozilla.org/MPL/
# 
#  Software distributed under the License is distributed on an "AS IS" basis,
#  WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
#  for the specific language governing rights and limitations under the
#  License.
# 
#  The Original Code is [Open Source Virtual Machine.].
# 
#  The Initial Developer of the Original Code is
#  Adobe System Incorporated.
#  Portions created by the Initial Developer are Copyright (C) 2009
#  the Initial Developer. All Rights Reserved.
# 
#  Contributor(s):
#    Adobe AS3 Team
# 
#  Alternatively, the contents of this file may be used under the terms of
#  either the GNU General Public License Version 2 or later (the "GPL"), or
#  the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
#  in which case the provisions of the GPL or the LGPL are applicable instead
#  of those above. If you wish to allow use of your version of this file only
#  under the terms of either the GPL or the LGPL, and not to allow others to
#  use your version of this file under the terms of the MPL, indicate your
#  decision by deleting the provisions above and replace them with the notice
#  and other provisions required by the GPL or the LGPL. If you do not delete
#  the provisions above, a recipient may use your version of this file under
#  the terms of any one of the MPL, the GPL or the LGPL.
# 
#  ***** END LICENSE BLOCK ****
(set -o igncr) 2>/dev/null && set -o igncr; # comment is needed


source=$1
test "$source" = "" && {
    echo "usage: util-download.sh <source> <dest>"
    exit 1
}

dest=$2
test "$dest" = "" && {
    echo "usage: util-download.sh <source> <dest>"
    exit 1
}

##
# Make sure the destination directory exists
##
dest_dir=`dirname $dest`
mkdir -p $dest_dir

##
# Download the requested file
##

echo "Downloading $source to $dest"

test -f download.log && {
   rm -f download.log
}

# wget "-O -" tells wget to print download to stdout.  This is then piped to our
# $dest file.  The reason for using this and not doing a "-O $dest" is if there
# is an error midstream, wget will retry the download and APPEND to $dest (which
# already is a partially downloaded file) resulting in a corrupt download

wget -o download.log --progress=dot:mega -O - $source > $dest
cat download.log
response=`cat download.log | grep ERROR`
if [ ! -z "${response}" ]; then
        echo "Did not find $source, exit run"
        exit 1
fi

##
# Check that the source file has some size
##
filesize=`ls -l $dest | awk '{print $5}'`
echo "Downloaded file is $filesize bytes"
test "$filesize" = "0" && {
    echo "Download appears to have failed"
    exit 1
}


exit 0
