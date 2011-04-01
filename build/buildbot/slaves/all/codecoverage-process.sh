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


##
# Calculate the change number and change id
##
. ../all/util-calculate-change.sh $1

errors=""
covdatadir=$buildsdir/${change}-${changeid}/$platform
for file in $covdatadir/*.cov
do
    export COVFILE=$file
    echo
    echo "coverage file: $COVFILE"
    cd ${basedir}
    $bullseyedir/covdir -q -m $coverage_exclude_regions
    fnpct=`$bullseyedir/covdir -q -m $coverage_exclude_regions | grep Total | awk '{print $6}'`
    cdpct=`$bullseyedir/covdir -q -m $coverage_exclude_regions | grep Total | awk '{print $11}'`

    echo "message: total function coverage:           $fnpct"
    echo "message: total condition/decision coverage: $cdpct"

    # download current historical files
    basename=`basename $file | awk -F. '{print $1}'`
    ${basedir}/build/buildbot/slaves/all/util-download.sh $http_coverage/${basename}-recentfn.csv $covdatadir/${basename}-recentfn.csv
    ${basedir}/build/buildbot/slaves/all/util-download.sh $http_coverage/${basename}-recentbc.csv $covdatadir/${basename}-recentbc.csv
    ${basedir}/build/buildbot/slaves/all/util-download.sh $http_coverage/${basename}-milestonefn.baseline.csv $covdatadir/${basename}-milestonefn.csv
    ${basedir}/build/buildbot/slaves/all/util-download.sh $http_coverage/${basename}-milestonebc.baseline.csv $covdatadir/${basename}-milestonebc.csv
    ${basedir}/build/buildbot/slaves/all/util-download.sh $http_coverage/${basename}-milestone-missingfn.csv $covdatadir/${basename}-milestone-missingfn.csv

    # parse code coverage data and generate csv reports
    ${basedir}/build/buildbot/slaves/all/util-parse-codecoverage.py --covfile=$file --build=$change
    result=$?
    if [ "$result" != "0" ]
    then
        echo "message: error ${basedir}/build/buildbot/slaves/all/util-parse-codecoverage.py failed"
        errors="$file FAILED $errors"
    else
        echo "uploading csv data"
        ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $covdatadir/${basename}-info.csv ${scp_coverage}/${basename}-info.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $covdatadir/${basename}-summaryfn.csv ${scp_coverage}/${basename}-summaryfn.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $covdatadir/${basename}-summarybc.csv ${scp_coverage}/${basename}-summarybc.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $covdatadir/${basename}-recentfn.csv ${scp_coverage}/${basename}-recentfn.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $covdatadir/${basename}-recentbc.csv ${scp_coverage}/${basename}-recentbc.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $covdatadir/${basename}-milestonefn.csv ${scp_coverage}/${basename}-milestonefn.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $covdatadir/${basename}-milestonebc.csv ${scp_coverage}/${basename}-milestonebc.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $covdatadir/${basename}-missingfn.csv ${scp_coverage}/${basename}-missingfn.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-scp-mozilla.sh $covdatadir/${basename}-missingfn-diffs.csv ${scp_coverage}/${basename}-missingfn-diffs.csv
    
        ${basedir}/build/buildbot/slaves/all/util-upload-ftp-asteam.sh $covdatadir/${basename}-missingfn-diffs.csv $ftp_asteam/$branch/$change-${changeid}/coverage/${basename}-missingfn-diffs.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-ftp-asteam.sh $covdatadir/${basename}-missingfn.csv $ftp_asteam/$branch/$change-${changeid}/coverage/${basename}-missingfn.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-ftp-asteam.sh $covdatadir/${basename}-summaryfn.csv $ftp_asteam/$branch/$change-${changeid}/coverage/${basename}-summaryfn.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-ftp-asteam.sh $covdatadir/${basename}-summarybc.csv $ftp_asteam/$branch/$change-${changeid}/coverage/${basename}-summarybc.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-ftp-asteam.sh $covdatadir/${basename}-recentfn.csv $ftp_asteam/$branch/$change-${changeid}/coverage/${basename}-recentfn.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-ftp-asteam.sh $covdatadir/${basename}-recentbc.csv $ftp_asteam/$branch/$change-${changeid}/coverage/${basename}-recentbc.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-ftp-asteam.sh $covdatadir/${basename}-milestonefn.csv $ftp_asteam/$branch/$change-${changeid}/coverage/${basename}-milestonefn.csv
        ${basedir}/build/buildbot/slaves/all/util-upload-ftp-asteam.sh $covdatadir/${basename}-milestonebc.csv $ftp_asteam/$branch/$change-${changeid}/coverage/${basename}-milestonebc.csv
    fi
done

if [ "$errors" != "" ]
then
    echo "message: code coverage processing failed"
    exit 1
else
    echo "message: finished code coverage processing"
    exit 0
fi
