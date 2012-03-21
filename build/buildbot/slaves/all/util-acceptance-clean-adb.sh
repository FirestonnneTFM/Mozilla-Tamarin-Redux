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


adb=$basedir/platform/android/adb_proxy.py
echo
echo "+++++++++++++++++++++++++++++++++++++++++"
echo "Ensure that the system is clean and ready"
echo "+++++++++++++++++++++++++++++++++++++++++"
echo

#
# kill any rogue adb processes running on host
#
echo "========================================="
echo "kill any rogue adb processes running on host..."
adbp=`ps -ef | grep adb | grep android_runner | awk '{print $2}'`
for p in $adbp
do
    echo "Found adb process: `ps -ef | grep adb | grep android_runner | grep $p`"
    echo "Found running adb process: $p"
    kill $p
done
echo ""
sleep 2


##
# get list of connected devices
##
echo "Connected devices:"
${adb} devices
devices=`${adb} devices | awk '{ if ( $2  ~ /device/ ) print $1 }'`


#
# for each device look for avmshell processes and kill them
#
echo "========================================="
echo "rebooting devices..."
for device in $devices
do
    echo "Rebooting device - $device"
    ${adb} -s $device reboot
done
sleep 60
echo ""

#
# for each device look for avmshell processes and kill them
#

echo "========================================="
echo "cleaning up any avmshell processes on device..."
for device in $devices
do
    echo "Looking for avmshell processes on device - $device"
    ps=`${adb} -s $device shell ps | grep avmshell | awk '{print $2}'`
    for p in $ps
    do
	echo "found avmshell process: `${adb} -s $device shell ps | grep avmshell | grep $p`"
        echo "killing $p"
        ${adb} -s $device shell kill $p
    done
done
echo ""

#
# remove old abc and shells from the device
#
echo "========================================="
echo "cleanup up /data/local/tamarin directories on device..."
for device in $devices
do
    echo "cleaning up device - $device"
    ${adb} -s $device shell rm -r /data/local/tamarin
    ${adb} -s $device shell mkdir /data/local/tamarin
done
echo ""


echo "cleanup finished"

echo; echo;


