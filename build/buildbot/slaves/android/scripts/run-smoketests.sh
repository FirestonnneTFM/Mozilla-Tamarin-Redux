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
#  Portions created by the Initial Developer are Copyright (C) 2010
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
# Download the AVMSHELL if it does not exist
##
if [ ! -e "$buildsdir/$change-${changeid}/$platform/$shell_release" ]; then
    echo "Download AVMSHELL: ${$shell_release}"
    ../all/util-download.sh $vmbuilds/$branch/$change-${changeid}/$platform/$shell_release $buildsdir/$change-${changeid}/$platform/$shell_release
    ret=$?
    test "$ret" = "0" || {
        echo "Downloading of $shell failed"
        rm -f $buildsdir/$change-${changeid}/$platform/$shell_release
        exit 1
    }
    chmod +x $buildsdir/$change-${changeid}/$platform/$shell_release
fi

##
# Ensure that the system is clean and ready
##
# Clean up the adb_failures log file, this file tracks any adb calls that timeout
if [ -e "/tmp/adb_failures" ]; then
    echo ""
    echo "message: adb call failures"
    cat /tmp/adb_failures
    rm /tmp/adb_failures
fi
cd $basedir/build/buildbot/slaves/scripts
../all/util-acceptance-clean-adb.sh

echo "setup $branch/${change}-${changeid}"
../all/adb-shell-deployer.sh ${change} ${buildsdir}/${change}-${changeid}/${platform}/$shell_release
res=$?
test "$res" = "0" || {
    echo "message: setup failed"
    exit 1
}

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
export BUILTINABC=$basedir/core/$builtinABC
export SHELLABC=$basedir/shell/$shellABC
# If available, use windows python (instead of cygwin python)
# Threading only works with windows python, $PYTHONWIN env variable must point to windows install
# $PYTHONWIN must be defined with forward slashes, e.g: c:/Python26/python.exe
if [ -z "$PYTHONWIN" ]
then
    export py=python
else
    export py=$PYTHONWIN
fi

export AVM=$basedir/platform/android/android_shell.py
export avmr=$AVM
export avmrd=$AVM
export avmd=$AVM
export avmdd=$AVM

# silence output if silent=true (function defined in environment.sh)
logfile=smokes-android.log
beginSilent

echo ""
echo "*******************************************************************************"
echo AVM="$AVM"
echo "`$AVM`"
echo ""
echo "shell compiled with these features:"
features=`$AVM -Dversion | grep AVM | sed 's/\;/ /g' | sed 's/features //g'`
for i in ${features}; do
    echo feature: $i
done
echo ""
echo "*******************************************************************************"
echo ""

cd $basedir/test
$py ./runsmokes.py --testfile=./runsmokes-arm-android.txt --time=120
ret=$?

exitcode=0
test "$ret" = "0" ||
   exitcode=1

endSilent

test "$silent" = "true" && {
    # display smoke results to stdout so that buildbot parses the results
    grep "^ *passes" $logfile
    grep "^ *failures" $logfile
}

##
# Ensure that the system is torn down and clean
##
cd $basedir/build/buildbot/slaves/scripts
../all/util-acceptance-teardown.sh

# Clean up the adb_failures log file, this file tracks any adb calls that timeout
if [ -e "/tmp/adb_failures" ]; then
    echo ""
    echo "message: adb call failures"
    cat /tmp/adb_failures
    rm /tmp/adb_failures
fi

exit $exitcode