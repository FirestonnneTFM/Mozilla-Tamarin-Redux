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

winrs=$basedir/build/buildbot/slaves/all/winrs-proxy.py

##
# Calculate the change number and change id
##
. ../all/util-calculate-change.sh $1

filename=$2
if [[ "$filename" = "" ]]; then
    filename=$shell_release
fi

clean=$3

# keep a list of already deployed hosts
already_deployed=""

# loop through each ssh client: for count=1 to threadcount, count contains the current client
while true
do
    # set WINRS_SHELL_REMOTE_* to the current winrs client
    eval WINRS_SHELL_REMOTE_USER=\${WINRS_SHELL_REMOTE_USER$count}
    eval WINRS_SHELL_REMOTE_PASSWD=\${WINRS_SHELL_REMOTE_PASSWD$count}
    eval WINRS_SHELL_REMOTE_HOST=\${WINRS_SHELL_REMOTE_HOST$count}
    eval WINRS_SHELL_REMOTE_BASEDIR=\${WINRS_SHELL_REMOTE_BASEDIR$count}

    if [ "$WINRS_SHELL_REMOTE_USER" = "" ] ||
       [ "$WINRS_SHELL_REMOTE_PASSWD" = "" ] ||
       [ "$WINRS_SHELL_REMOTE_HOST" = "" ] ||
       [ "$WINRS_SHELL_REMOTE_BASEDIR" = "" ];
    then
        echo "missing environment variable: "
        echo "WINRS_SHELL_REMOTE_USER${count}" = "$WINRS_SHELL_REMOTE_USER"
        echo "WINRS_SHELL_REMOTE_PASSWD${count}" = "<intentionally blank>"
        echo "WINRS_SHELL_REMOTE_HOST${count}" = "$WINRS_SHELL_REMOTE_HOST"
        echo "WINRS_SHELL_REMOTE_BASEDIR${count}" = "$WINRS_SHELL_REMOTE_BASEDIR"
        exit 1
    fi

# check if already deployed on the host
    echo "$already_deployed" | grep "$WINRS_SHELL_REMOTE_HOST" > /dev/null
    res=$?
    if [ "$res" == "0" ]
    then
        break     # skip deploying since the host already is setup        
    else
        already_deployed="$WINRS_SHELL_REMOTE_HOST $already_deployed"  # add host to deploy list
    fi

    echo ""
    echo "===================================================="
    echo "setting up client $count"
    echo "WINRS_SHELL_REMOTE_USER" = "$WINRS_SHELL_REMOTE_USER"
    echo "WINRS_SHELL_REMOTE_PASSWD" = "<intentionally blank>"
    echo "WINRS_SHELL_REMOTE_HOST" = "$WINRS_SHELL_REMOTE_HOST"
    echo "WINRS_SHELL_REMOTE_BASEDIR" = "$WINRS_SHELL_REMOTE_BASEDIR"

    if [[ -n "$clean" ]]; then
        echo ""
        echo "Clean up the remote directory"
        ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "rmdir /s /q ${WINRS_SHELL_REMOTE_BASEDIR}"
        ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "mkdir ${WINRS_SHELL_REMOTE_BASEDIR}"
    fi

    echo""
    echo "Installing $filename on $WINRS_SHELL_REMOTE_HOST to $WINRS_SHELL_REMOTE_BASEDIR"
    # Setup the ftp script to get the acceptance media
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo open ${ftp_host} \> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo user \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo ftp \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo ftp \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo lcd ${WINRS_SHELL_REMOTE_BASEDIR} \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo cd ${branch}/${change}/windows \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo get ${filename} avmshell.exe \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo get winrs-shell-runner.bat \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo close \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo quit \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"

    echo ""
    echo "Get the ${filename} from ftp server"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "ftp -n -s:${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"

    echo ""
    echo "verify the deployed shell version if correct"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "${WINRS_SHELL_REMOTE_BASEDIR}\\\\winrs-shell-runner.bat" > /tmp/stdout
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

    # Setup the ftp script to get the acceptance media
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo open ${ftp_host} \> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo user \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo ftp \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo ftp \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo lcd ${WINRS_SHELL_REMOTE_BASEDIR} \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo cd ${branch}/${change} \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo get acceptance-tests-abcs.zip \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo close \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "echo quit \>\> ${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"

    echo ""
    echo "Get the acceptance media from ftp server"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "ftp -n -s:${WINRS_SHELL_REMOTE_BASEDIR}\\\\ftp_script"

    echo "unzipping acceptance-tests-abcs.zip..."
    echo ""
    echo "Unzip the acceptance media"
    ${winrs} -r:${WINRS_SHELL_REMOTE_HOST} -u:${WINRS_SHELL_REMOTE_USER} -p:${WINRS_SHELL_REMOTE_PASSWD} "cscript c:\\\\tamarin-tools\\\\unzip.vbs ${WINRS_SHELL_REMOTE_BASEDIR}\\\\acceptance-tests-abcs.zip ${WINRS_SHELL_REMOTE_BASEDIR}"

    # increment the counter, check if we are finished looping
    count=$[count+1]
    if [ "$count" = "$threadcount" ]
    then
        break
    fi
done

exit $exitcode
