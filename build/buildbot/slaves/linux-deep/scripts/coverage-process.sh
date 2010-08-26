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
#  Portions created by the Initial Developer are Copyright (C) 2009-2010
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


export COVFILE=$buildsdir/${change}-${changeid}/$platform/avm.cov
test -f $COVFILE && rm -f $COVFILE

cd $buildsdir/${change}-${changeid}/$platform/
files=`ls *.cov`

$bullseyedir/covmerge -c $files

cd ${basedir}
$bullseyedir/covdir -q -m
fnpct=`$bullseyedir/covdir -q -m | grep Total | awk '{print $6}'`
cdpct=`$bullseyedir/covdir -q -m | grep Total | awk '{print $11}'`



echo "message: total function coverage:           $fnpct"
echo "message: total condition/decision coverage: $cdpct"

. ${basedir}/build/buildbot/slaves/all/util-upload-ftp-asteam.sh $COVFILE $ftp_asteam/$branch/${change}-${changeid}/$platform/avm.cov

echo "url: http://10.60.48.47/builds/$branch/${change}-${changeid}/${platform}/avm.cov code coverage data file avm.cov"


# Current known platforms generating coverage data:
platforms="windows mac linux"
covfiles="" # this will get built up by looping over the platforms

# Get the coverage files for all platforms. If all files are not avaible, stop.
# Only continue processing if ALL platforms are complete.
for platform in ${platforms}
do
    covfiles+="$platform/avm.cov "
    if [ ! -e "$buildsdir/${change}-${changeid}/$platform/avm.cov" ]; then
	echo "Downloading $platform/avm.cov"
	${basedir}/build/buildbot/slaves/all/util-download.sh $vmbuilds$branch/${change}-${changeid}/$platform/avm.cov $buildsdir/${change}-${changeid}/$platform/avm.cov
	ret=$?
	test "$ret" = "0" || {
            echo "Downloading of $platform/avm.cov failed"
            rm -f $buildsdir/${change}-${changeid}/$platform/avm.cov
	    echo "Not all coverage files are available so stop processing"
            exit 0
	}
    fi
done

# Merge all coverage files into a single file and upload
mkdir $buildsdir/${change}-${changeid}/coverage
export COVFILE=$buildsdir/${change}-${changeid}/coverage/avm.cov
test -f $COVFILE && rm -f $COVFILE

echo $covfiles
cd $buildsdir/${change}-${changeid}
$bullseyedir/covmerge -c $covfiles

cd ${basedir}
$bullseyedir/covdir -q -m
fnpct=`$bullseyedir/covdir -q -m | grep Total | awk '{print $6}'`
cdpct=`$bullseyedir/covdir -q -m | grep Total | awk '{print $11}'`



echo "message: combined total function coverage:           $fnpct"
echo "message: combined total condition/decision coverage: $cdpct"

. ${basedir}/build/buildbot/slaves/all/util-upload-ftp-asteam.sh $COVFILE $ftp_asteam/$branch/${change}-${changeid}/coverage/avm.cov
echo "url: http://10.60.48.47/builds/$branch/${change}-${changeid}/coverage/avm.cov combined code coverage data file avm.cov"

# Remove current coverage files
ssh ${coverage_host} "cd ${coverage_dir}/latest; rm *.cov"

# Post all of the coverage files to the 'latest' directory
for platform in ${platforms}
do
    echo; echo "Uploading avm-${platform}-${change}.cov ..."
    . ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $buildsdir/${change}-${changeid}/$platform/avm.cov ${scp_coverage}/latest/avm-${platform}-${change}.cov
done
echo; echo "Uploading avm-${change}.cov ..."
. ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $buildsdir/${change}-${changeid}/coverage/avm.cov ${scp_coverage}/latest/avm-${change}.cov


