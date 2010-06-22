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


showhelp ()
{
    echo ""
    echo "usage: run-selftest-generic.sh <change> <filename>"
    echo "  <change>     build number of shell to test"
    echo "  <filename>   name of the shell, do not include file extenstion"
    exit 1
}

if [ "$#" -lt 2 ]
then
    echo "not enough args passed"
    showhelp
fi

filename=$2

export shell=$filename$shell_extension


##
# Download the AVMSHELL if it does not exist
##
if [ ! -e "$buildsdir/$change-${changeid}/$platform/$shell" ]; then
    echo "Download AVMSHELL: ${shell}"
    ../all/util-download.sh $vmbuilds/$branch/$change-${changeid}/$platform/$shell $buildsdir/$change-${changeid}/$platform/$shell
    ret=$?
    test "$ret" = "0" || {
        echo "Downloading of $shell failed"
        rm -f $buildsdir/$change-${changeid}/$platform/$shell
        exit 1
    }
    chmod +x $buildsdir/$change-${changeid}/$platform/$shell
fi



##
# Ensure that the system is clean and ready
##
cd $basedir/build/buildbot/slaves/scripts
../all/util-acceptance-clean.sh

AVM=$buildsdir/$change-${changeid}/$platform/$shell

$AVM -Dselftest > selftest.out 2>&1
ret=$?

cat selftest.out

passes=`grep pass selftest.out | wc -l`
fails=`grep fail selftest.out | wc -l`

# a non-zero exit code indicates an avm crash, therefore increment the failures by 1
if [ "$ret" -ne "0" ]; then
    let fails=fails+1
fi

echo "passes            : $passes"
echo "failures          : $fails"

rm selftest.out

##
# Ensure that the system is torn down and clean
##
cd $basedir/build/buildbot/slaves/scripts
../all/util-acceptance-teardown.sh

exit $ret
 
