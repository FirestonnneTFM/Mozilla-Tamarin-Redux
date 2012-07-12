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
# Set any variables that my be needed higher up the chain
##
export shell_extension=.exe

##
# Bring in the BRANCH environment variables
##
. ../all/environment.sh

export platform=windows

export shell_release=$shell_release_rt
export shell_debug=$shell_debug_rt
export shell_release_debugger=$shell_release_debugger_rt
export shell_debug_debugger=$shell_debug_debugger_rt


if [ "$VS_HOME" == "" ]
then
    VS_HOME="C:\Program Files (x86)\Microsoft Visual Studio 11.0"
fi
VS_HOME_PATH=`cygpath -a "$VS_HOME"`
echo VS_HOME: $VS_HOME
echo VS_HOME_PATH: $VS_HOME_PATH

if [ "$WINDOWS_SDK" == "" ]
then
    WINDOWS_SDK="C:\Program Files (x86)\Windows Kits\8.0"
fi

export PATH="$PATH_PREPEND:$VS_HOME_PATH/Common7/IDE:$VS_HOME_PATH/VC/bin/x86_arm:$VS_HOME_PATH\Common7\Tools:$VS_HOME_PATH/VC/VCPackages:$PATH"

export INCLUDE="$VS_HOME\VC\atlmfc\include;$VS_HOME\VC\include;$WINDOWS_SDK\Include\um;$WINDOWS_SDK\Include\shared;"

export LIB="$VS_HOME\VC\atlmfc\lib\arm;$VS_HOME\VC\lib\arm;$WINDOWS_SDK\Lib\win8\um\arm"
export LIBPATH="$LIB;"
