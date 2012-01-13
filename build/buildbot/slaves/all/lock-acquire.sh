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
#  Portions created by the Initial Developer are Copyright (C) 2009
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

test "$lockfile" = "" && {
  echo "must set lockfile env variable"
  exit 1
}
test "$sleeptime" = "" && {
  echo "must set sleeptime env variable"
  exit 1
}
echo "Attempting to acquire lock."
while true
do
    echo Will check for lock in $sleeptime seconds.
    sleep $sleeptime

    # Check to see if we actually own the lock and it is stale
    test -f $lockfile && {
        lock_owner=`head -1 $lockfile | cut -d: -f1`
        test $lock_owner == $slavename && {
            echo There is a stale lockfile, removing stale lock.
            rm -f $lockfile
        }
    }
    test -f $lockfile || {
        echo Lock has been acquired
        echo $slavename: `date` > $lockfile
        break;
    }

    echo [`date +%H:%M:%S`] Lock in use by: `cat $lockfile`
done

exit 0

