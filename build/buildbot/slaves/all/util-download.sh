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

maxtries=5
x=1

while [ $x -le $maxtries ]
do
    
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
    # Check that the source file is the same size that wget indicated
    ##
    
    # use nawk if present (due to solaris awk not being compatible)
    AWK=awk
    test `which nawk` && {
        AWK=nawk
    }
    
    # awk command breakdown - need to account for variation in wget output on diff platforms:
    # /(saved|written to stdout).*\[/ = find the line with "saved [" or "written to stdout ["
    # match(...) = using the line above regexp match a "[" followed by digits followed by either "]" or "/"
    # match defines RSTART = index of where the pattern starts; RLENGTH = length of pattern match
    # if ... print = if there's a match, print the pattern minus the surrounding chars
    expectedFilesize=`$AWK  '/(saved|written to stdout) \[/ {match($0,/\[([0-9]+)(\]|\/)/); if (RSTART) print substr($0, RSTART+1, RLENGTH-2)}' download.log`
    if [ "$expectedFilesize" = "" ]; then
        expectedFilesize=-1
    fi

    if [ `uname -o` = "Cygwin" ]
    then
        # on windows, the ls columns are not quoted
        # and the "group" may contain a space;
        # use "du -sb" to return size in bytes
        filesize=`du -sb $dest | awk '{print $1}'`
    else
        # osx du command doesn't have a bytes option
        filesize=`ls -l $dest | awk '{print $5}'`
    fi
    
    echo "Downloaded file is $filesize bytes"
    if [ "$filesize" -eq "$expectedFilesize" ]; then
        echo "Download successful"
        exit 0
    else
        echo "Download appears to have failed"
        rm $dest
        if [ $x -lt $maxtries ]; then
            x=$(( $x + 1 ))
            echo "Attempting download again.  Attempt $x of $maxtries."
            sleep 5
        else 
            echo "Download failed after $maxtries tries.  Aborting Download."
            exit 1
        fi
    fi
done

exit 0
