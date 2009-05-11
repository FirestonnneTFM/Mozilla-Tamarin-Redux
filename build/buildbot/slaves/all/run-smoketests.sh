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


##
# Download the shell_release
##
if [ ! -e "$buildsdir/$change-${changeid}/$platform/$shell_release" ]; then
    echo "Download AVMSHELL"
    ../all/util-download.sh $vmbuilds/$branch/$change-${changeid}/$platform/$shell_release $buildsdir/$change-${changeid}/$platform/$shell_release
    ret=$?
    test "$ret" = "0" || {
        echo "Downloading of $shell_release failed"
        rm -f $buildsdir/$change-${changeid}/$platform/$shell_release
        exit 1
    }
    chmod +x $buildsdir/$change-${changeid}/$platform/$shell_release
fi

##
# Download the shell_release_debugger
##
if [ ! -e "$buildsdir/$change-${changeid}/$platform/$shell_release_debugger" ]; then
    echo "Download AVMSHELL"
    ../all/util-download.sh $vmbuilds/$branch/$change-${changeid}/$platform/$shell_release_debugger $buildsdir/$change-${changeid}/$platform/$shell_release_debugger
    ret=$?
    test "$ret" = "0" || {
        echo "Downloading of $shell_release_debugger failed"
        rm -f $buildsdir/$change-${changeid}/$platform/$shell_release_debugger
        exit 1
    }
    chmod +x $buildsdir/$change-${changeid}/$platform/$shell_release_debugger
fi

##
# Download the shell_debug
##
if [ ! -e "$buildsdir/$change-${changeid}/$platform/$shell_debug" ]; then
    echo "Download AVMSHELL"
    ../all/util-download.sh $vmbuilds/$branch/$change-${changeid}/$platform/$shell_debug $buildsdir/$change-${changeid}/$platform/$shell_debug
    ret=$?
    test "$ret" = "0" || {
        echo "Downloading of $shell_debug failed"
        rm -f $buildsdir/$change-${changeid}/$platform/$shell_debug
        exit 1
    }
    chmod +x $buildsdir/$change-${changeid}/$platform/$shell_debug
fi

##
# Download the shell_debug_debugger
##
if [ ! -e "$buildsdir/$change-${changeid}/$platform/$shell_debug_debugger" ]; then
    echo "Download AVMSHELL"
    ../all/util-download.sh $vmbuilds/$branch/$change-${changeid}/$platform/$shell_debug_debugger $buildsdir/$change-${changeid}/$platform/$shell_debug_debugger
    ret=$?
    test "$ret" = "0" || {
        echo "Downloading of $shell_debug_debugger failed"
        rm -f $buildsdir/$change-${changeid}/$platform/$shell_debug_debugger
        exit 1
    }
    chmod +x $buildsdir/$change-${changeid}/$platform/$shell_debug_debugger
fi


##
# Download the latest asc.jar if it does not exist
##
if [ ! -e "$basedir/utils/asc.jar" ]; then
    echo "Download asc.jar"
    ../all/util-download.sh $ascbuilds/asc.jar $basedir/utils/asc.jar
    ret=$?
    test "$ret" = "0" || {
        echo "Downloading of asc.jar failed"
        rm -f $basedir/utils/asc.jar
        exit 1
    }
fi
export ASC=$basedir/utils/asc.jar
export GLOBALABC=$basedir/core/$builtinABC
export SHELLABC=$basedir/shell/$shellABC

echo ""
echo "Missing media will be compiled using the following ASC version:"
echo "`java -jar $basedir/utils/asc.jar`"
echo ""

# set variables for full path to builds
export avmr=$buildsdir/$change-${changeid}/$platform/$shell_release
export avmrd=$buildsdir/$change-${changeid}/$platform/$shell_release_debugger
export avmd=$buildsdir/$change-${changeid}/$platform/$shell_debug
export avmdd=$buildsdir/$change-${changeid}/$platform/$shell_debug_debugger
# cmdline testsuite uses AVM,AVMRD, should change to avmr,avmrd
export AVM=$avmr
export AVMRD=$avmrd

# If available, use windows python (instead of cygwin python)
# Threading only works with windows python, $PYTHONWIN env variable must point to windows install
# $PYTHONWIN must be defined with forward slashes, e.g: c:/Python26/python.exe
if [ -z "$PYTHONWIN" ]
then
    export py=python
else
    export py=$PYTHONWIN
fi

cd $basedir/test
$py ./runsmokes.py --testfile=./runsmokes.txt --time=120
ret=$?

exitcode=0
test "$ret" = "0" ||
   exitcode=1

exit $exitcode


