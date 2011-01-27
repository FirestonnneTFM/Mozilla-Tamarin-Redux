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

if [ "$threads" == "" ]
then
   threadcount="1"
else
   threadcount=$threads
fi

count="0"

exitcode=0
##
# Calculate the change number and change id
##
. ../all/util-calculate-change.sh $1

filename=$2
if [[ "$filename" = "" ]]; then
    filename=$shell_release
fi

while true
do
    # use indirect reference to set SSH_SHELL_REMOTE_USERn where n=$count
    eval SSH_SHELL_REMOTE_USER=\${SSH_SHELL_REMOTE_USER$count}
    eval SSH_SHELL_REMOTE_HOST=\${SSH_SHELL_REMOTE_HOST$count}
    eval SSH_SHELL_REMOTE_DIR=\${SSH_SHELL_REMOTE_DIR$count}
    
    if [ "$SSH_SHELL_REMOTE_USER" = "" ] ||
       [ "$SSH_SHELL_REMOTE_HOST" = "" ] ||
       [ "$SSH_SHELL_REMOTE_DIR" = "" ];
    then
        echo "missing environment variable: "
        echo "SSH_SHELL_REMOTE_USER${count}" = "$SSH_SHELL_REMOTE_USER"
        echo "SSH_SHELL_REMOTE_HOST${count}" = "$SSH_SHELL_REMOTE_HOST"
        echo "SSH_SHELL_REMOTE_DIR${count}" = "$SSH_SHELL_REMOTE_DIR"
        exit 1
    fi

    echo "setting up client $count"
    echo "SSH_SHELL_REMOTE_USER" = "$SSH_SHELL_REMOTE_USER"
    echo "SSH_SHELL_REMOTE_HOST" = "$SSH_SHELL_REMOTE_HOST"
    echo "SSH_SHELL_REMOTE_DIR" = "$SSH_SHELL_REMOTE_DIR"

    # Deploy ssh-shell-runner.sh
    echo "Installing ssh-shell-runner.sh on $SSH_SHELL_REMOTE_HOST to $SSH_SHELL_REMOTE_DIR"
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;rm ssh-shell-runner.sh"
    scp ../all/ssh-shell-runner.sh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST:$SSH_SHELL_REMOTE_DIR/ssh-shell-runner.sh
    # make sure file copied over
    if [[ "$?" -ne "0" ]]; then 
        echo "Error copying ssh-shell-runner.sh."
        # If there was an error copying the script abort
        exit 1
    fi
    # set executable bit for ssh-shell-runner.sh
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;chmod +x ssh-shell-runner.sh"

    echo""
    echo "Installing $filename on $SSH_SHELL_REMOTE_HOST to $SSH_SHELL_REMOTE_DIR"

    # Clean up previous avmshell if it exists
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;rm avmshell"

    # Upload the shell, filename will ALWAYS be avmshell on the remote system
    scp $filename $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST:$SSH_SHELL_REMOTE_DIR/avmshell

    # Make sure that the version running on the remote system is the expected revision
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;chmod +x avmshell;./avmshell" > /tmp/stdout

    # Verify that the shell was successfully deployed
    deploy_rev=`cat /tmp/stdout | grep "avmplus shell" | awk '{print $6}'`
    if [ "$change" != "${deploy_rev%:*}" ] || [ "$changeid" != "${deploy_rev#*:}" ]; 
    then
        echo $0 FAILED!!!
        echo requested build "$change:$changeid" is not what is deployed "${deploy_rev%:*}:${deploy_rev#*:}"
        exitcode=1
    fi
    count=$[count+1]
    test "$count" == "$threadcount" && {
        break
    }
done

exit $exitcode
