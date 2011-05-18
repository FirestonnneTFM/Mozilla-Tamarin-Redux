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

##
# Bring in the environment variables
##
. ./environment.sh

##
# Calculate the change number and change id
##
. ../all/util-calculate-change.sh $1

function verify_generated_files () {

    ##
    # Backup the generated files
    ##
    cd $basedir/generated
    for file in $FILES
    do
        # The python scripts that build the files are expecting a specific list of files so fail here if one is missing.    
        if [ ! -e "$file" ]; then       
            echo "Expected file $file does not exist."; echo
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
        diff generated/$file generated/$file.orig
        diff generated/$file generated/$file.orig > $basedir/build/buildbot/slaves/scripts/$file.diff
        
        # If the diff file is > 0 bytes fire a warning
        if [ -s $basedir/build/buildbot/slaves/scripts/$file.diff ]; then
            echo "buildbot status: WARNINGS Diff found between generated/$file.orig and generated/$file. See $basedir/build/buildbot/slaves/scripts/$file.diff"
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
}

# silence output if silent=true (function defined in environment.sh)
logfile=builtinabc.log
beginSilent

echo basedir=$basedir

##
# Download the latest asc.jar if it does not exist
##
download_asc

echo ""
echo "Building builtin.abc and shell_toplevel.abc using the following ASC version:"
echo "`java -jar $ASC`"
echo ""

FILES="builtin.abc builtin.cpp builtin.h"
BUILDER="builtin.py"
BUILDER_DIR="core"
verify_generated_files $FILES $BUILDER $BUILDER_DIR

FILES="shell_toplevel.abc shell_toplevel.cpp shell_toplevel.h"
BUILDER="shell_toplevel.py"
BUILDER_DIR="shell"
verify_generated_files $FILES $BUILDER $BUILDER_DIR

# exactgc.py, called by builtin-tracers.py and shell_toplevel-tracers.py below, builds against the avmshell
# so check that we're not cross-compiling and the shell will run on the build platform.
# Set AVM
    if [ "$AVM" == "" ]; then
        export AVM=$buildsdir/$change-${changeid}/$platform/$shell_release
    fi
echo "Cross-compile check: Running avmshell at $AVM"    
$AVM | grep ${change}:${changeid} &> /dev/null
res=$?
if [ "$res" != "0" ]; then
    echo ""
    echo "Cross-compile check failed - cannot build exactgc tracers on $platform platform"
    echo ""
    exit 0
else
    echo ""
    echo "Building exactgc tracer files"
    echo ""
    
    FILES="avmplus-tracers.h avmplus-tracers.hh"
    BUILDER="builtin-tracers.py"
    BUILDER_DIR="core"
    verify_generated_files $FILES $BUILDER $BUILDER_DIR
    
    FILES="avmshell-tracers.h avmshell-tracers.hh extensions-tracers.h extensions-tracers.hh"
    BUILDER="shell_toplevel-tracers.py"
    BUILDER_DIR="shell"
    verify_generated_files $FILES $BUILDER $BUILDER_DIR
fi

endSilent

exit 0

