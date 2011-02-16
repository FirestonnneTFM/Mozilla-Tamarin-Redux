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




##
# Calculate the change number and change id
##
. ../all/util-calculate-change.sh $1

# silence output if silent=true (function defined in environment.sh)
logfile=builtinabc.log
beginSilent

echo basedir=$basedir
##
# Download the latest asc.jar if it does not exist
##
download_asc

echo ""
echo "Building builtin.abc file using the following ASC version:"
echo "`java -jar $ASC`"
echo ""



##
# Backup the generated files
##
cd $basedir/generated
mv builtin.abc builtin.abc.orig
mv builtin.cpp builtin.cpp.orig
mv builtin.h builtin.h.orig
mv shell_toplevel.abc shell_toplevel.abc.orig
mv shell_toplevel.cpp shell_toplevel.cpp.orig
mv shell_toplevel.h shell_toplevel.h.orig

##
# Build the builtin.abc
##
echo "building builtin.abc"
cd $basedir/core
python ./builtin.py
ret=$?
test "$ret" = "0" || {
    echo "builtin.py failed"
    cd $basedir/generated
    mv builtin.abc.orig builtin.abc
    mv builtin.cpp.orig builtin.cpp
    mv builtin.h.orig builtin.h
    endSilent
    exit 1
}

cd $basedir

##
# Diff the builtin.cpp and builtin.h files
##

test -f $basedir/build/buildbot/slaves/scripts/builtin.diff && {
    rm $basedir/build/buildbot/slaves/scripts/builtin.diff
}
diff generated/builtin.cpp generated/builtin.cpp.orig
diff generated/builtin.cpp generated/builtin.cpp.orig > $basedir/build/buildbot/slaves/scripts/builtin.diff
cd $basedir/build/buildbot/slaves/scripts
../all/util-builtin-verify.py $basedir/build/buildbot/slaves/scripts/builtin.diff

cd $basedir
test -f $basedir/build/buildbot/slaves/scripts/builtin.diff && {
    rm $basedir/build/buildbot/slaves/scripts/builtin.diff
}
diff generated/builtin.h generated/builtin.h.orig
diff generated/builtin.h generated/builtin.h.orig > $basedir/build/buildbot/slaves/scripts/builtin.diff
cd $basedir/build/buildbot/slaves/scripts
../all/util-builtin-verify.py $basedir/build/buildbot/slaves/scripts/builtin.diff

cd $basedir/generated
# revert files
mv builtin.abc.orig builtin.abc
mv builtin.cpp.orig builtin.cpp
mv builtin.h.orig builtin.h

##
# Build the shell_toplevel.abc
##

echo "building shell_toplevel.abc"
cd $basedir/shell
python ./shell_toplevel.py
ret=$?
test "$ret" = "0" || {
    echo "shell_toplevel failed"
    cd $basedir/generated
    mv shell_toplevel.abc.orig shell_toplevel.abc
    mv shell_toplevel.cpp.orig shell_toplevel.cpp
    mv shell_toplevel.h.orig shell_toplevel.h
    endSilent
    exit 1
}

cd $basedir

##
# Diff the shell_toplevel.cpp and shell_toplevel.h files
##
test -f $basedir/build/buildbot/slaves/scripts/shell_toplevel.cpp.diff && {
    rm $basedir/build/buildbot/slaves/scripts/shell_toplevel.cpp.diff
}
diff generated/shell_toplevel.cpp generated/shell_toplevel.cpp.orig
diff generated/shell_toplevel.cpp generated/shell_toplevel.cpp.orig > $basedir/build/buildbot/slaves/scripts/shell_toplevel.cpp.diff

cd $basedir
test -f $basedir/build/buildbot/slaves/scripts/shell_toplevel.h.diff && {
    rm $basedir/build/buildbot/slaves/scripts/shell_toplevel.h.diff
}
diff generated/shell_toplevel.h generated/shell_toplevel.h.orig
diff generated/shell_toplevel.h generated/shell_toplevel.h.orig > $basedir/build/buildbot/slaves/scripts/shell_toplevel.h.diff

cd $basedir/generated
# revert files
mv shell_toplevel.abc.orig shell_toplevel.abc
mv shell_toplevel.cpp.orig shell_toplevel.cpp
mv shell_toplevel.h.orig shell_toplevel.h

endSilent

cd $basedir/build/buildbot/slaves/scripts
../all/util-builtin-verify.py $basedir/build/buildbot/slaves/scripts/shell_toplevel.cpp.diff
../all/util-builtin-verify.py $basedir/build/buildbot/slaves/scripts/shell_toplevel.h.diff

exit 0

