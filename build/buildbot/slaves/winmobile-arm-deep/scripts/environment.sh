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
# Set any variables that my be needed higher up the chain
##
export shell_extension=.exe

##
# Bring in the BRANCH environment variables
##
. ../all/environment.sh

export platform=winmobile
export basedir=c:/buildbot/$branch/$platform-arm-deep/$branch
export buildsdir=c:/buildbot/$branch/$platform-arm-deep/builds
export EMULATORDIR=c:/buildbot/$branch/$platform-arm-deep/emulator

export shell_release_arm=avmshell_arm$shell_extension
export shell_release_wordcode_arm=avmshell_wordcode_arm$shell_extension
export shell_release_thumb=avmshell_thumb$shell_extension
export shell_debug_arm=avmshell_arm_d$shell_extension
export shell_debug_thumb=avmshell_thumb_d$shell_extension

export EMULATOR="c:/Program Files/Microsoft Device Emulator/1.0/DeviceEmulator.exe"
export EMULATORIMAGE="c:/Program Files/Windows Mobile 6 SDK/PocketPC/DeviceemulationV650/0409/PPC_USA_GSM_VR.BIN"
