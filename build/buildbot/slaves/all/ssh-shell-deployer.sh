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

##
# Calculate the change number and change id
##
. ../all/util-calculate-change.sh $1

filename=$2
if [[ "$filename" = "" ]]; then
    filename=$shell_release
fi


# If running under Jenkins, acceptance media comes from upstream job via the
# "copy artifact" plugin and should not be downloaded via ftp
if [ "$JENKINS_HOME" = "" ]; then
    ## download the desired version of the acceptance-tests-abcs.zip locally
    echo "Download acceptance-tests-abcs.zip"
    if [ ! -f ${buildsdir}/${change}-${changeid}/acceptance-tests-abcs.zip ]
    then
        $basedir/build/buildbot/slaves/all/util-download.sh $ftp_asteam/builds/$branch/$change-${changeid}/acceptance-tests-abcs.zip ${buildsdir}/${change}-${changeid}/acceptance-tests-abcs.zip
        res=$?
        if [ ! -f "${buildsdir}/${change}-${changeid}/acceptance-tests-abcs.zip" ]
        then
            echo "ERROR: download acceptance-tests-abcs.zip failed"
            exit 1
        fi
    fi

    export acceptance_zip=${buildsdir}/${change}-${changeid}/acceptance-tests-abcs.zip
else
    export acceptance_zip=${basedir}/test/acceptance/acceptance-tests-abcs.zip
fi # end Jenkins check



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

    # copy the ssh-shell-runner.sh to the client
    echo "Installing ssh-shell-runner.sh on $SSH_SHELL_REMOTE_HOST to $SSH_SHELL_REMOTE_DIR"
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "${SSH_SETUP}mkdir -p $SSH_SHELL_REMOTE_DIR;cd $SSH_SHELL_REMOTE_DIR;rm ssh-shell-runner.sh"
    scp ../all/ssh-shell-runner.sh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST:$SSH_SHELL_REMOTE_DIR/ssh-shell-runner.sh
    # confirm the copy succeeded
    if [[ "$?" -ne "0" ]]; then 
        echo "Error copying ssh-shell-runner.sh."
        # If there was an error copying the script abort
        exit 1
    fi
    # set executable bit for ssh-shell-runner.sh
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;chmod 777 ssh-shell-runner.sh"

    echo""
    echo "Installing $filename on $SSH_SHELL_REMOTE_HOST to $SSH_SHELL_REMOTE_DIR"
   
    exename=`basename $filename`
    # check if the shell already exists on the client
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "${SSH_SETUP}test -f $SSH_SHELL_REMOTE_BASEDIR/builds/${change}-${changeid}/$exename"
    if [ "$?" != "0" ]
    then
        # upload the shell to the client builds directory
        ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "${SSH_SETUP}mkdir -p $SSH_SHELL_REMOTE_BASEDIR/builds/${change}-${changeid}"
        scp $filename $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST:$SSH_SHELL_REMOTE_BASEDIR/builds/${change}-${changeid}/$exename
    fi

    # copy the shell from the device build directory to the client directory
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;${SSH_SETUP}rm avmshell;${SSH_SETUP}cp $SSH_SHELL_REMOTE_BASEDIR/builds/${change}-${changeid}/$exename ./avmshell;chmod 777 ./avmshell"

    # verify the deployed shell version if correct
    ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;./avmshell" > /tmp/stdout
    deploy_rev=`cat /tmp/stdout | grep "avmplus shell" | awk '{print $NF}'`
    if [ "$change" != "${deploy_rev%:*}" ] || [ "$changeid" != "${deploy_rev#*:}" ];
    then
        # Could be possible that we are running from the hg mirror repo and using a binary that has a p4 changelist revision
        # The last line in the description is going to be "CL@12345"
        # so grab the last line and peel off the perforce changelist
        cl=`hg log -r $change --template {desc} | tail -n 1 | awk -F@  '{print $2}'`
        echo "found changelist in description: ${cl}"
        if [ "${cl}" != "${deploy_rev%:*}" ]; then
            echo $0 FAILED!!!
            echo requested build "$change:$changeid" is not what is deployed "${deploy_rev%:*}:${deploy_rev#*:}"
            exit 1
        fi
    fi

    # check if the base acceptance-tests-abcs.zip is correct version
    baseversion=`ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "${SSH_SETUP}cat $SSH_SHELL_REMOTE_BASEDIR/acceptance-tests-abcs.txt"`
    if [ "$baseversion" != "${change}-${changeid}" ]
    then
        # if the version does not match upload the correct version
        scp ${acceptance_zip} $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST:$SSH_SHELL_REMOTE_BASEDIR/acceptance-tests-abcs.zip
        if [[ "$?" -ne "0" ]]; then 
            echo "Error copying acceptance-tests-abcs.zip."
            exit 1
        fi
        ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "echo ${change}-${changeid} > $SSH_SHELL_REMOTE_BASEDIR/acceptance-tests-abcs.txt"
    fi
        
    # check if the client acceptance-tests-abc.zip is the correct version
    version=`ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "${SSH_SETUP}cat $SSH_SHELL_REMOTE_DIR/acceptance-tests-abcs.txt"`
    if [ "$version" != "${change}-${changeid}" ]
    then
        # if the version does not match copy from the base version
        echo "unzipping acceptance-tests-abcs.zip..."
        ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "cd $SSH_SHELL_REMOTE_DIR;${SSH_SETUP}unzip -o -q $SSH_SHELL_REMOTE_BASEDIR/acceptance-tests-abcs.zip"
        if [[ "$?" -ne "0" ]]; then 
            echo "Error unzipping acceptance-tests-abcs.zip."
            exit 1
        fi
        ssh $SSH_SHELL_REMOTE_USER@$SSH_SHELL_REMOTE_HOST "echo ${change}-${changeid} > $SSH_SHELL_REMOTE_DIR/acceptance-tests-abcs.txt"
    fi

    # increment the counter, check if we are finished looping
    count=$[count+1]
    if [ "$count" = "$threadcount" ]
    then
        break
    fi
done

exit $exitcode
