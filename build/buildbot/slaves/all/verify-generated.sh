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

echo basedir=$basedir

## This function is called by verify_builtinabc.sh and verify_tracers.sh
function verify_generated_files () {

    export LC_ALL=C
    
    ##
    # Backup the generated files
    ##
    cd $basedir/generated
    for file in $FILES
    do
        # The python scripts that build the files are expecting a specific list of files so fail here if one is missing.    
        if [ ! -e "$file" ]; then       
            echo "Expected file $file does not exist."; echo
            endSilent
            export LC_ALL=
            exit 1
        else
            mv $file $file".orig"
        fi
    done

    ##
    # Build the files
    ##
    echo "building $FILES"
    cd $basedir/"$BUILDER_DIR"
    python ./$BUILDER
    ret=$?
    test "$ret" = "0" || {
        echo "$BUILDER failed"
        cd $basedir/generated
        for file in $FILES
        do
            if [ ! -e "$file" ]; then
                echo "Expected file $file.orig does not exist."; echo
            else
                mv $file".orig" $file
            fi
        done
        endSilent
        export LC_ALL=
        exit 1        
    }
    
    ##
    # Diff the files
    ##
    cd $basedir
    for file in $FILES
    do    
        test -f $basedir/build/buildbot/slaves/scripts/$file".diff" && {
            rm $basedir/build/buildbot/slaves/scripts/$file".diff"
        }
        
        tr -d '\r' < generated/$file > generated/difftemp
        tr -d '\r' < generated/$file.orig > generated/difftemp.orig
        
        diff generated/difftemp generated/difftemp.orig
        diff generated/difftemp generated/difftemp.orig > $basedir/build/buildbot/slaves/scripts/$file.diff
        
        rm generated/difftemp
        rm generated/difftemp.orig
        
        # If the diff file is > 0 bytes fire a warning
        if [ -s $basedir/build/buildbot/slaves/scripts/$file.diff ]; then
            echo "buildbot_status: WARNINGS"
        fi
    done
    
    # Revert files
    # The files are being touched below to deal with this issue on solaris:
    # http://hg.mozilla.org/tamarin-redux/rev/67a99bdafb0c
    cd $basedir/generated
    for file in $FILES
    do
        mv $file".orig" $file
        # don't touch abc files
        if [ ${file/*./} != "abc" ]; then
            touch $file
        fi
    done
    
    export LC_ALL=
}

