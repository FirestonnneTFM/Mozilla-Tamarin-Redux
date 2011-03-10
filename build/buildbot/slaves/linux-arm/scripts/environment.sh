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
# Set any variables that my be needed higher up the chain
##
export shell_extension=

##
# Bring in the BRANCH environment variables
##
. ../all/environment.sh

export platform=linux

export shell_release=avmshell_neon_arm
export shell_release_debugger=avmshell_neon_arm
export shell_debug=avmshell_neon_arm_d
export shell_debug_debugger=avmshell_neon_arm_d
export shell_selftest=avmshell_neon_arm

export PYTHON_RUNTESTS=python3

export threads=6

export SSH_SHELL_REMOTE_HOST0=asteam-beagle-xM1
export SSH_SHELL_REMOTE_USER0=build
export SSH_SHELL_REMOTE_BASEDIR0=/home/build
export SSH_SHELL_REMOTE_DIR0=/home/build/app1

export SSH_SHELL_REMOTE_HOST1=asteam-beagle-xM1
export SSH_SHELL_REMOTE_USER1=build
export SSH_SHELL_REMOTE_BASEDIR1=/home/build
export SSH_SHELL_REMOTE_DIR1=/home/build/app2

export SSH_SHELL_REMOTE_HOST2=asteam-beagle-xM2
export SSH_SHELL_REMOTE_USER2=build
export SSH_SHELL_REMOTE_BASEDIR2=/home/build
export SSH_SHELL_REMOTE_DIR2=/home/build/app1

export SSH_SHELL_REMOTE_HOST3=asteam-beagle-xM2
export SSH_SHELL_REMOTE_USER3=build
export SSH_SHELL_REMOTE_BASEDIR3=/home/build
export SSH_SHELL_REMOTE_DIR3=/home/build/app2

export SSH_SHELL_REMOTE_HOST4=asteam-beagle-xM3
export SSH_SHELL_REMOTE_USER4=build
export SSH_SHELL_REMOTE_BASEDIR4=/home/build
export SSH_SHELL_REMOTE_DIR4=/home/build/app1

export SSH_SHELL_REMOTE_HOST5=asteam-beagle-xM3
export SSH_SHELL_REMOTE_USER5=build
export SSH_SHELL_REMOTE_BASEDIR5=/home/build
export SSH_SHELL_REMOTE_DIR5=/home/build/app2
