# -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- #
# vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) #
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

# threadcount is the number of child threads
# count is used to loop over the threads
if [ "$threads" == "" ]
then
   threadcount="1"
else
   threadcount=$threads
fi
count="0"

# keep track of any failures
exitcode=0


# loop through each ssh client: for count=1 to threadcount, count contains the current client
while true
do
    # set SSH_SHELL_REMOTE_* to the current ssh client
    eval SSH_SHELL_REMOTE_USER=\${SSH_SHELL_REMOTE_USER$count}
    eval SSH_SHELL_REMOTE_HOST=\${SSH_SHELL_REMOTE_HOST$count}
    eval SSH_SHELL_REMOTE_BASEDIR=\${SSH_SHELL_REMOTE_BASEDIR$count}
    eval SSH_SHELL_REMOTE_DIR=\${SSH_SHELL_REMOTE_DIR$count}

    if [ "$SSH_SHELL_REMOTE_USER" = "" ] ||
       [ "$SSH_SHELL_REMOTE_HOST" = "" ] ||
       [ "$SSH_SHELL_REMOTE_BASEDIR" = "" ] ||
       [ "$SSH_SHELL_REMOTE_DIR" = "" ];
    then
        echo "missing environment variable: "
        echo "SSH_SHELL_REMOTE_USER${count}" = "$SSH_SHELL_REMOTE_USER"
        echo "SSH_SHELL_REMOTE_HOST${count}" = "$SSH_SHELL_REMOTE_HOST"
        echo "SSH_SHELL_REMOTE_BASEDIR${count}" = "$SSH_SHELL_REMOTE_BASEDIR"
        echo "SSH_SHELL_REMOTE_DIR${count}" = "$SSH_SHELL_REMOTE_DIR"
        exit 1
    fi

    echo "setting up client $count"
    echo "SSH_SHELL_REMOTE_USER" = "$SSH_SHELL_REMOTE_USER"
    echo "SSH_SHELL_REMOTE_HOST" = "$SSH_SHELL_REMOTE_HOST"
    echo "SSH_SHELL_REMOTE_BASEDIR" = "$SSH_SHELL_REMOTE_BASEDIR"
    echo "SSH_SHELL_REMOTE_DIR" = "$SSH_SHELL_REMOTE_DIR"

    # Create the builds directory, this is not used BUT IS NECESSARY for the
    # utils-acceptance-clean-ssh.sh script since it tries to clean the dir
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "${SSH_SETUP}mkdir -p $SSH_SHELL_REMOTE_BASEDIR/builds"

    # copy the aot-shell-runner.sh to the client
    echo "Installing aot-shell-runner.sh on $SSH_SHELL_REMOTE_HOST to $SSH_SHELL_REMOTE_DIR"
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "${SSH_SETUP}mkdir -p $SSH_SHELL_REMOTE_DIR;cd $SSH_SHELL_REMOTE_DIR;rm aot-shell-runner.sh"
    scp ../all/aot-shell-runner.sh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST:$SSH_SHELL_REMOTE_DIR/aot-shell-runner.sh
    # confirm the copy succeeded
    if [[ "$?" -ne "0" ]]; then
        echo "Error copying aot-shell-runner.sh."
        # If there was an error copying the script abort
        exit 1
    fi
    # set executable bit for aot-shell-runner.sh
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;chmod 777 aot-shell-runner.sh"

    # increment the counter, check if we are finished looping
    count=$[count+1]
    if [ "$count" = "$threadcount" ]
    then
        break
    fi
done

exit $exitcode
