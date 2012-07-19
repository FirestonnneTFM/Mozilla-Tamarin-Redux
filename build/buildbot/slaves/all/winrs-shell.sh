#!/bin/bash
# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is [Open Source Virtual Machine.].
#
# The Initial Developer of the Original Code is
# Adobe System Incorporated.
# Portions created by the Initial Developer are Copyright (C) 2012
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#   Adobe AS3 Team
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK ***** */
# acts as a proxy to remotely run abc files via a winrs call to the remote machine
# usage: ./winrs_shell.sh <vmargs> file.abc
# assumes the shell is deployed to $WINRS_SHELL_REMOTE_DIR/avmshell
#
(set -o igncr) 2>/dev/null && set -o igncr; # comment is needed

if [ "$THREADID" == "" ]
then
   id="0"
else
   id=$THREADID
fi

eval WINRS_SHELL_REMOTE_USER=\${WINRS_SHELL_REMOTE_USER$id}
eval WINRS_SHELL_REMOTE_PASSWD=\${WINRS_SHELL_REMOTE_PASSWD$id}
eval WINRS_SHELL_REMOTE_HOST=\${WINRS_SHELL_REMOTE_HOST$id}
eval WINRS_SHELL_REMOTE_BASEDIR=\${WINRS_SHELL_REMOTE_BASEDIR$id}

if [ "$WINRS_SHELL_REMOTE_USER" = "" ] ||
   [ "$WINRS_SHELL_REMOTE_PASSWD" = "" ] ||
   [ "$WINRS_SHELL_REMOTE_HOST" = "" ] ||
   [ "$WINRS_SHELL_REMOTE_BASEDIR" = "" ];
then
    echo "missing environment variable: "
    echo "WINRS_SHELL_REMOTE_USER" = "$WINRS_SHELL_REMOTE_USER"
    echo "WINRS_SHELL_REMOTE_PASSWD${count}" = "<intentionally blank>"
    echo "WINRS_SHELL_REMOTE_HOST" = "$WINRS_SHELL_REMOTE_HOST"
    echo "WINRS_SHELL_REMOTE_BASEDIR" = "$WINRS_SHELL_REMOTE_BASEDIR"
    exit 1
fi


MAX_RETRIES=5
filelist=""
flatfilelist=""
expectedExitCode=0
if [ "$WINRS_EXE" == "" ]
then
    winrs=winrs.exe
else
    winrs=$WINRS_EXE
fi
function try_command () {
    count=1
    while [ $count -le $MAX_RETRIES ]
    do
        # run the passed in command - not that "$@" (quoted) is used since that
        # is the only form that will work with quoted arguments containing spaces
        # see http://www.tldp.org/LDP/abs/html/internalvariables.html#APPREF2
        # for details
        "$@" 2> ./stderr$id
        ec=$?
        if [ "$ec" -eq "$expectedExitCode" ]; then
            # command executed with expected exit code
            # Put captured stderr back into stderr so that it is handled properly by the test runner
            if [ -s ./stderr$id ]; then
                echo "`cat ./stderr$id`" >&2
                rm -f ./stderr$id
            fi
            return 0
        else
            echo "Command Failed: $*"
            echo "Exit Code: $ec"
            echo "Expected Exit Code: $expectedExitCode"
            echo "Try $count of $MAX_RETRIES"
            sleep 3
        fi
        ((count++))
    done
    # command failed SSH_RETRIES times, report failure and exit
    echo "Reached max tries, exiting with exit code $ec ..."
    # Put captured stderr back into stderr so that it is handled properly by the test runner
    if [ -s ./stderr$id ]; then
        echo "`cat ./stderr$id`" >&2
        rm -f ./stderr$id
    fi
    exit $ec
}


if [ "$1" = "" ]
then
    # running the shell with no args prints the help and exits with exitcode 1
    expectedExitCode=0
    try_command ${winrs} -r:$WINRS_SHELL_REMOTE_HOST -u:$WINRS_SHELL_REMOTE_USER -p:$WINRS_SHELL_REMOTE_PASSWD "$WINRS_SHELL_REMOTE_BASEDIR\\\\avmshell"
else
    # assumes all .abc files are on the device in the WINRS_SHELL_REMOTE_BASEDIR
    # workaround for not returning exit code, run a shell script and print exit code to stdout
    try_command ${winrs} -r:$WINRS_SHELL_REMOTE_HOST -u:$WINRS_SHELL_REMOTE_USER -p:$WINRS_SHELL_REMOTE_PASSWD "$WINRS_SHELL_REMOTE_BASEDIR\\\\winrs-shell-runner.bat $*" > ./stdout$id
    ret=`cat ./stdout$id | grep "EXITCODE=" | awk -F= '{printf("%d",$2)}'`
    # remove the EXITCODE from the stdout before returning it so that exact output matching will be fine
    cat ./stdout$id | sed 's/^EXITCODE=[0-9][0-9]*$//g' > ./stdout_clean$id
    cat ./stdout_clean$id
    rm -f ./stdout$id ./stdout_clean$id
    exit $ret
fi
