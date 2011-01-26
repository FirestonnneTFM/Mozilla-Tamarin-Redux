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

. ./environment.sh
. ../all/util-calculate-change.sh $1

##
# Download the AVMSHELL if it does not exist
##
download_shell $shell_release
download_shell $shell_release_debugger
download_shell $shell_debug
download_shell $shell_debug_debugger

##
# Download the latest asc.jar if it does not exist
##
download_asc

echo ASC=$ASC
export AVM=$buildsdir/$change-${changeid}/$platform/$shell_release
export AVMRD=$buildsdir/$change-${changeid}/$platform/$shell_release_debugger


echo AVM=$AVM
echo AVMRD=$AVMRD
echo BUILTINABC=$BUILTINABC
echo SHELLABC=$SHELLABC


##
# Ensure that the system is clean and ready
##
cd $basedir/build/buildbot/slaves/scripts
../all/util-acceptance-clean.sh

cd $basedir/test/cmdline
echo "starting cmdline testsuite..."

# If available, use windows python (instead of cygwin python)
# Threading only works with windows python, $PYTHONWIN env variable must point to windows install
# $PYTHONWIN must be defined with forward slashes, e.g: c:/Python26/python.exe
if [ -z "$PYTHONWIN" ]
then
    py=python
else
    py=$PYTHONWIN
fi
$py ./runtests.py > cmdline.txt 2>&1
ret_release=$?


# run the tests again, this time using debug and debug-debugger shells
# note that we use the release env vars set to the debug players
export AVM=$buildsdir/$change-${changeid}/$platform/$shell_debug
export AVMRD=$buildsdir/$change-${changeid}/$platform/$shell_debug_debugger

if [ -z "$PYTHONWIN" ]
then
    py=python
else
    py=$PYTHONWIN
fi
# Note that we append to cmdline.txt as we have results from the run above in it
$py ./runtests.py >> cmdline.txt 2>&1
ret_debug=$?

# Boolean OR the two returns to get a combined exitcode (ret) value
ret=$(( $ret_release || $ret_debug ))
echo "ret=$ret"

cat cmdline.txt

pass=`cat cmdline.txt | grep PASSED | wc -l | awk '{print $1}'`
fails=`cat cmdline.txt | grep FAILED | wc -l | awk '{print $1}'`
exfails=`cat cmdline.txt | grep "EXPECTED FAIL" | wc -l | awk '{print $1}'`
unpass=`cat cmdline.txt | grep "UNEXPECTED" | wc -l | awk '{print $1}'`
skips=`cat cmdline.txt | grep "SKIP" | wc -l | awk '{print $1}'`

echo "Summary results:"
echo "passes            : $pass"
echo "failures          : $fails"
test "$exfails" = "0" || {
echo "expected failures : $exfails"
}
test "$unpass" = "0" || {
echo "unexpected passes : $unpass"
}
test "$skips" = "0" || {
echo "tests skipped     : $skips"
}

rm cmdline.txt

##
# Ensure that the system is torn down and clean
##
cd $basedir/build/buildbot/slaves/scripts
../all/util-acceptance-teardown.sh

exit $ret
