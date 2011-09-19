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

revision=$1
shell=$2
args=$3

test "$shell" = "" && shell=$shell_release_debugger
test "$args" = "" && args="--quiet"

if [ "$shell" = "avmshell_sd" -o "$shell" = "avmshell_sd_64" ]
then
    knownerrors=knownerrors-debug.txt
else
    knownerrors=knownerrors.txt
fi

# calculate the revision number to test
. ../all/util-calculate-change.sh $revision

# download build
download_shell $shell

# set the release debugger shell
export AVMRD=$buildsdir/$change-${changeid}/$platform/$shell

test "$BRIGHTSPOT" = "" && {
    echo "BRIGHTSPOT must be set to the url of brightspot"
    exit 1
}

# download the avmglue.abc, requiring for running swfs in vm
echo "Download avmglue.abc"
../all/util-download.sh $BRIGHTSPOT/avmglue.abc $basedir/test/brightspot/avmglue.abc
echo "Download runtests.py"
../all/util-download.sh $BRIGHTSPOT/runtests.py $basedir/test/brightspot/runtests.py
echo "Download knownerrors.txt"
../all/util-download.sh $BRIGHTSPOT/$knownerrors $basedir/test/brightspot/knownerrors.txt

cd $basedir/test/brightspot
chmod +x ./runtests.py

# run the testsuite
$PYTHON_RUNTESTS ./runtests.py $args

