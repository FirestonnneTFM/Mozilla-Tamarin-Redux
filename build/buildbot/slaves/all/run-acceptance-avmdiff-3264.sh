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


# If running under Jenkins, avm and asc come from upstream jobs via the
# "copy artifact" plugin and should not be downloaded via ftp
if [ "$JENKINS_HOME" = "" ]; then
    ##
    # Download the AVMSHELL if it does not exist
    ##
    download_shell $shell_release_32
    download_shell $shell_release_64

    ##
    # Download the latest asc.jar if it does not exist
    ##
    download_asc

    ## HACK, use the release and debug variables for the 32 and 64 bit shells
    export shell_release=$buildsdir/$change-${changeid}/$platform/$shell_release_32
    export shell_debug=$buildsdir/$change-${changeid}/$platform/$shell_release_64

else
    ## HACK, use the release and debug variables for the 32 and 64 bit shells
    export shell_release=$WS/objdir/shell/$shell_release_32
    export shell_debug=$WS/objdir/shell/$shell_release_64
fi

echo ""
echo "Missing media will be compiled using the following ASC version:"
echo "`java -jar $ASC`"
echo ""





##
# Ensure that the system is clean and ready
##
cd $basedir/build/buildbot/slaves/scripts
../all/util-acceptance-clean.sh


cd $basedir/test/acceptance

avmdiff=$basedir/utils/avmdiff.py
avmdiffcfg=$basedir/build/buildbot/slaves/all/avmdiff_32-64.cfg
if [ "$OSTYPE" == "cygwin" ]; then
    avmdiff=`cygpath -w $basedir/utils/avmdiff.py`
fi
export AVM="$PYTHON_RUNTESTS $avmdiff --buildfile=${avmdiffcfg}"
echo "`$AVM`"
echo; echo "AVM built with the following options:"
echo "`$AVM -Dversion`"


echo "message: $PYTHON_RUNTESTS ./runtests.py --config=${platform}-3264-diff   --notimecheck"
$PYTHON_RUNTESTS ./runtests.py --config=${platform}-3264-diff --notimecheck

##
# Ensure that the system is torn down and clean
##
cd $basedir/build/buildbot/slaves/scripts
../all/util-acceptance-teardown.sh

exit 0


