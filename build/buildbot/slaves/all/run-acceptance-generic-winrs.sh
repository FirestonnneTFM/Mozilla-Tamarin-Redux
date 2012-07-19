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
#  Portions created by the Initial Developer are Copyright (C) 2012
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
# If we are running a sandbox build and the user specifies the build with the revision hash
# make sure that we stick with using the revision hash downstream as that is where we are
# going to find the necessary files on asteam, the ftp directory will have been created with the
# hash so that is how we must access it from the winrs client.
if [ "$changeid" == "$1" ]; then
   change=$changeid
fi

showhelp ()
{
    echo ""
    echo "usage: run-acceptance-generic-winrs.sh <change> <filename> <vmargs> <config> <scriptargs>"
    echo "  <change>     build number of shell to test"
    echo "  <filename>   name of the shell, do not include file extenstion"
    echo "  <vmargs>     vmargs to be passed or empty quoted string"
    echo "  <config>     custom config string to be passed to runtests.py"
    echo "               or an empty string"
    echo "  <deployargs> (optional) configuration arguments, 'skipdeploy' to not deploy the shell"
    echo "               and tests to the device"
    echo "  <scriptargs> (optional) additional runtests.py args to be passed, can be"
    echo "               args and test/directories to run, value is appended to call"
    exit 1
}

if [ "$#" -lt 4 ]
then
    echo "not enough args passed"
    showhelp
fi

filename=$2
vmargs=$3
config=$4
deploy=$5
# assign the remaining positional params to scriptargs
shift 5
scriptargs=$*


export shell=$filename$shell_extension

export AVM="$basedir/build/buildbot/slaves/all/winrs-shell.sh"
echo AVM=$AVM
test -f $AVM || {
    echo "ERROR: $AVM not found"
    exit 1
}
export AVM="bash $AVM"

echo ""
echo "Missing media will be compiled using the following ASC version:"
echo "`java -jar $ASC`"
echo ""

if [ "$deploy" == "deploy" ]
then

    echo "running deploy on shell ${shell}"
    ../all/winrs-shell-deployer.sh ${change} ${shell} ${clean}
    res=$?
    test "$res" = "0" || {
        echo "message: setup failed"
        exit 1
    }

else
     echo "skipping deploy"
fi

echo ""
echo "*******************************************************************************"
echo AVM=$AVM
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

cd $basedir/test/acceptance

scriptargs="--passthreadid --threads=$threads $scriptargs"

echo "message: $PYTHON_RUNTESTS ./runtests.py --vmargs=\"${vmargs}\" --config=${config} --notimecheck ${scriptargs}"
$PYTHON_RUNTESTS ./runtests.py  --vmargs="${vmargs}" --config=${config} --notimecheck ${scriptargs}


exit 0


