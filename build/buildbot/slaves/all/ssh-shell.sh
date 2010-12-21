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
# Portions created by the Initial Developer are Copyright (C) 2010
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
# acts as a proxy to remotely run abc files via a ssh call to the remote machine
# usage: ./ssh_shell.sh <vmargs> file.abc
# assumes the shell is deployed to $SSH_SHELL_REMOTE_DIR/avmshell
#

if [ "$SSH_SHELL_REMOTE_USER" = "" ] ||
   [ "$SSH_SHELL_REMOTE_HOST" = "" ] ||
   [ "$SSH_SHELL_REMOTE_DIR" = "" ];
then
    echo "missing environment variable: "
    echo "SSH_SHELL_REMOTE_USER" = "$SSH_SHELL_REMOTE_USER"
    echo "SSH_SHELL_REMOTE_HOST" = "$SSH_SHELL_REMOTE_HOST"
    echo "SSH_SHELL_REMOTE_DIR" = "$SSH_SHELL_REMOTE_DIR"
    exit 1
fi



MAX_RETRIES=5
filelist=""
flatfilelist=""
expectedExitCode=0

function try_command () {
    count=1
    while [ $count -le $MAX_RETRIES ]
    do
        # run the passed in command - not that "$@" (quoted) is used since that
        # is the only form that will work with quoted arguments containing spaces
        # see http://www.tldp.org/LDP/abs/html/internalvariables.html#APPREF2
        # for details
        "$@"
        ec=$?
        if [ "$ec" -eq "$expectedExitCode" ]; then
            # command ran with no errors
            return 0
        else
            echo "Command Failed: $*"
            echo "Exit Code: $ec"
            echo "Try $count of $MAX_RETRIES"
            sleep 3
        fi
        ((count++))
    done
    # command failed SSH_RETRIES times, report failure and exit
    echo "Reached max tries, exiting with exit code $ec ..."
    exit $ec
}


if [ "$1" = "" ]
then
    # running the shell with no args prints the help and exits with exitcode 1
    expectedExitCode=1
    try_command ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;./avmshell"
else
    # Note that testfiles are copied to the SSH_SHELL_REMOTE_DIR directly and
    # run one at a time.  No dir structure is preserved when copying the files.
    args=""
    for a in $*
    do
        # look for an .abc file
        echo "$a" | grep ".*\.abc" > /dev/null
        res=$?
        if [ "$res" = "0" ]
        then
            file=$a
            flatfile=`basename $a`
            # check to see if flatfile is already in filelist
            echo "$filelist" | grep "$flatfile" > /dev/null
            res=$?
            if [ "$res" = "1" ]; then
                # flatfile is not in filelist; add it
                filelist="$filelist $flatfile"
                # copy file to device
                try_command scp $file $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST:$SSH_SHELL_REMOTE_DIR/$flatfile > /dev/null
            fi
            # even if flatfile is already in filelist, add to args
            args="$args $flatfile"      
        else
            args="$args $a"
        fi
    done
    # workaround for not returning exit code, run a shell script and print exit code to stdout
    try_command ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;./ssh-shell-runner.sh $args" > ./stdout
    ret=`cat ./stdout | grep "EXITCODE=" | awk -F= '{printf("%d",$2)}'`
    # clean up copied over files
    for a in $filelist
    do
        try_command ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;rm $a"
    done
    # remove the EXITCODE from the stdout before returning it so that exact output matching will be fine
    cat ./stdout | sed 's/^EXITCODE=[0-9][0-9]*$//g' > ./stdout_clean
    cat ./stdout_clean
    rm -f ./stdout ./stdout_clean
    exit $ret
fi
