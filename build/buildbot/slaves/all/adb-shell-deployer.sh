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

filename=$2
test "$filename" = "" && {
    filename=$shell_release
}

adb=$basedir/platform/android/adb_proxy.py
# Determine the number of devices attached to the machine and their ids
adboutput=`${adb} devices`
deviceids=''
devicecount=0
IFS=$'\n'
for i in ${adboutput}; do
    if echo $i | grep -q 'device$'; then
	deviceids="${deviceids} `echo $i | awk '{print $1}'`"
	let devicecount=devicecount+1
    fi
done
unset IFS

echo ""
echo "Found ${devicecount} devices"
echo""
echo "Installing $filename"

for device in ${deviceids};do

    # Copy the shell and runner script to the device
    ${adb} -s ${device} push $filename /data/app/avmshell 2> /dev/null
    ${adb} -s ${device} shell 'chmod 777 /data/app/avmshell' 2> /dev/null
    ${adb} -s ${device} push ${basedir}/platform/android/android_runner.sh /data/app 2> /dev/null
    ${adb} -s ${device} shell 'chmod 777 /data/app/android_runner.sh' 2> /dev/null

    # Make sure that the version running on the device is the expected revision
    adb -s ${device} shell 'cd /data/app; ./avmshell' > /tmp/stdout${device}
    # Verify that the shell was successfully deployed
    # Remove CR from the stdout as they really mess up shell commands on mac, 
    # causing really weird output, characters getting moved around 
    deploy_rev=`tr -d '\r' < /tmp/stdout${device} | grep "avmplus shell" | awk '{print $6}'`
    if [ "$change" != "${deploy_rev%:*}" ] || [ "$changeid" != "${deploy_rev#*:}" ]; 
    then
	echo $0 FAILED!!!
	echo "requested build $change:$changeid is not what is deployed ${deploy_rev%:*}:${deploy_rev#*:}"
	exit 1
    fi
    echo "device ${device} setup with ${filename}"
done

exit
