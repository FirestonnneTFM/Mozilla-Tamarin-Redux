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

export platform=android

export shell_release=avmshell
export shell_debug=avmshell_d
export ssh_proc_names="avmshell avmshell_d"

# Override the default MAKE_OPTIONS env variable on the machine
export MAKE_OPTIONS="-j2"

# Override this, default is avmshell* and since this slave runs on a machine
# with other slaves, the process cleaner /can/ find avmshell processes, 
# BUT they will NEVER belong to this slave since the shell is run on a device
# not on the host machine. Reset this to something that will never be found/killed
export proc_names="fake_never_find_me"

export PYTHON_RUNTESTS=python3
export threads=10

export SSH_SHELL_REMOTE_HOST0=asteam-pandroid1
export SSH_SHELL_REMOTE_USER0=root
export SSH_SHELL_REMOTE_BASEDIR0=/data/local
export SSH_SHELL_REMOTE_DIR0=/data/local/app1

export SSH_SHELL_REMOTE_HOST1=asteam-pandroid1
export SSH_SHELL_REMOTE_USER1=root
export SSH_SHELL_REMOTE_BASEDIR1=/data/local
export SSH_SHELL_REMOTE_DIR1=/data/local/app1

export SSH_SHELL_REMOTE_HOST2=asteam-pandroid2
export SSH_SHELL_REMOTE_USER2=root
export SSH_SHELL_REMOTE_BASEDIR2=/data/local
export SSH_SHELL_REMOTE_DIR2=/data/local/app1

export SSH_SHELL_REMOTE_HOST3=asteam-pandroid2
export SSH_SHELL_REMOTE_USER3=root
export SSH_SHELL_REMOTE_BASEDIR3=/data/local
export SSH_SHELL_REMOTE_DIR3=/data/local/app2

export SSH_SHELL_REMOTE_HOST4=asteam-pandroid3
export SSH_SHELL_REMOTE_USER4=root
export SSH_SHELL_REMOTE_BASEDIR4=/data/local
export SSH_SHELL_REMOTE_DIR4=/data/local/app1

export SSH_SHELL_REMOTE_HOST5=asteam-pandroid3
export SSH_SHELL_REMOTE_USER5=root
export SSH_SHELL_REMOTE_BASEDIR5=/data/local
export SSH_SHELL_REMOTE_DIR5=/data/local/app2

export SSH_SHELL_REMOTE_HOST6=asteam-pandroid4
export SSH_SHELL_REMOTE_USER6=root
export SSH_SHELL_REMOTE_BASEDIR6=/data/local
export SSH_SHELL_REMOTE_DIR6=/data/local/app1

export SSH_SHELL_REMOTE_HOST7=asteam-pandroid4
export SSH_SHELL_REMOTE_USER7=root
export SSH_SHELL_REMOTE_BASEDIR7=/data/local
export SSH_SHELL_REMOTE_DIR7=/data/local/app2

export SSH_SHELL_REMOTE_HOST8=asteam-pandroid5
export SSH_SHELL_REMOTE_USER8=root
export SSH_SHELL_REMOTE_BASEDIR8=/data/local
export SSH_SHELL_REMOTE_DIR8=/data/local/app1

export SSH_SHELL_REMOTE_HOST9=asteam-pandroid5
export SSH_SHELL_REMOTE_USER9=root
export SSH_SHELL_REMOTE_BASEDIR9=/data/local
export SSH_SHELL_REMOTE_DIR9=/data/local/app2

export SSH_SETUP=/bin/
