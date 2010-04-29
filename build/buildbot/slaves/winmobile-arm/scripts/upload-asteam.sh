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



# Release_ARM
. ../all/util-upload-ftp-asteam.sh $buildsdir/$change-${changeid}/$platform/$shell_release_arm $ftp_asteam/$branch/$change-${changeid}/$platform/$shell_release_arm

# Release-wordcode_ARM
. ../all/util-upload-ftp-asteam.sh $buildsdir/$change-${changeid}/$platform/$shell_release_wordcode_arm $ftp_asteam/$branch/$change-${changeid}/$platform/$shell_release_wordcode_arm

# Release-FPU_ARM
. ../all/util-upload-ftp-asteam.sh $buildsdir/$change-${changeid}/$platform/$shell_release_fpu_arm $ftp_asteam/$branch/$change-${changeid}/$platform/$shell_release_fpu_arm

# Debug_ARM
. ../all/util-upload-ftp-asteam.sh $buildsdir/$change-${changeid}/$platform/$shell_debug_arm $ftp_asteam/$branch/$change-${changeid}/$platform/$shell_debug_arm

# Debug-FPU_ARM
. ../all/util-upload-ftp-asteam.sh $buildsdir/$change-${changeid}/$platform/$shell_debug_fpu_arm $ftp_asteam/$branch/$change-${changeid}/$platform/$shell_debug_fpu_arm


# bring in the win64 environment this will reset the shell names so that the x64 shells are uploaded
. ../windows64/scripts/environment.sh
# Release
. ../all/util-upload-ftp-asteam.sh $buildsdir/$change-${changeid}/$platform/$shell_release $ftp_asteam/$branch/$change-${changeid}/$platform/$shell_release

# Release-wordcode
. ../all/util-upload-ftp-asteam.sh $buildsdir/$change-${changeid}/$platform/$shell_release_wordcode $ftp_asteam/$branch/$change-${changeid}/$platform/$shell_release_wordcode

# Release_Debugger
. ../all/util-upload-ftp-asteam.sh $buildsdir/$change-${changeid}/$platform/$shell_release_debugger $ftp_asteam/$branch/$change-${changeid}/$platform/$shell_release_debugger

# Debug
. ../all/util-upload-ftp-asteam.sh $buildsdir/$change-${changeid}/$platform/$shell_debug $ftp_asteam/$branch/$change-${changeid}/$platform/$shell_debug

#Debug_Debugger
. ../all/util-upload-ftp-asteam.sh $buildsdir/$change-${changeid}/$platform/$shell_debug_debugger $ftp_asteam/$branch/$change-${changeid}/$platform/$shell_debug_debugger
