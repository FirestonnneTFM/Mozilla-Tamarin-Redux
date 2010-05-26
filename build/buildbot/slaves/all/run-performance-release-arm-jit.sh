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

##
# Run any slave specific code PRE performance
##
. ./run-performance-pre.sh

##
# Download the AVMSHELL if it does not exist
##
if [ ! -e "$buildsdir/$change-${changeid}/$platform/$shell_release" ]; then
    echo "Download AVMSHELL"
    ../all/util-download.sh $vmbuilds/$branch/$change-${changeid}/$platform/$shell_release $buildsdir/$change-${changeid}/$platform/$shell_release
    ret=$?
    test "$ret" = "0" || {
        echo "Downloading of $shell_release failed"
        rm -f $buildsdir/$change-${changeid}/$platform/$shell_release
        exit 1
    }
    chmod +x $buildsdir/$change-${changeid}/$platform/$shell_release
fi


##
# Download the latest asc.jar if it does not exist
##
if [ ! -e "$basedir/utils/asc.jar" ]; then
    echo "Download asc.jar"
    ../all/util-download.sh $ascbuilds/asc.jar $basedir/utils/asc.jar
    ret=$?
    test "$ret" = "0" || {
        echo "Downloading of asc.jar failed"
        rm -f $basedir/utils/asc.jar
        exit 1
    }
fi

##
# Install the AVMSHELL on the device
##
echo "Setting up the device with build #$change"
../all/avmshell-arm-setup.sh $change:$changeid


echo ""
echo "Building ABC files using the following ASC version:"
echo "`java -jar $basedir/utils/asc.jar`"
echo ""




export AVM=$basedir/build/buildbot/slaves/all/tools/ceremoteshell.exe
export ASC=$basedir/utils/asc.jar
export BUILTINABC=$basedir/core/$builtinABC
export SHELLABC=$basedir/shell/$shellABC



cd $basedir/test/performance
find ./ -name "*.abc" -exec rm {} \;

measurememory="false"
result="0"
resultmessage=""

# If a second parameter (after revision is given) then only run those tests
if [ $2 ]
then
    echo ""
    echo "===========   Custom Run: $2   ==========="
    # determine what iter to apply based on testname
    if [[ $2 == jsbench* ]] ; then
        vmargs=""
        iter=3
    elif [[ $2 == sunspider* ]] ; then
        vmargs=""
        iter=10
    elif [[ $2 == v8* ]] ; then
        vmargs=""
        iter=10
    else
        vmargs=""
        iter=3
    fi
    echo "python ./runtests.py -r $branch -k -f -i $iter --vmargs='$vmargs' $2"
    python ./runtests.py -r $branch -k -f -i $iter --vmargs="$vmargs" $2
    test "$?" = "0" || { 
        result="1"; 
        resultmessage="$2 time test run failed. " 
    }
    test "$measurememory" = "true" && {
        python ./runtests.py --memory -r $branch -k -f -i 1 $2
        test "$?" = "0" || { 
            result="1"; 
            resultmessage="$resultmessage \n$2 memory test run failed. " 
        }
    }
else
# standard performance run
    echo ""
    echo "===========   JSBench   ==========="
    python ./runtests.py --config=jsbench --vmversion=${change} -r $branch -k -f -i 3 --vmargs="-Ojit"
    test "$?" = "0" || { 
        result="1"; 
        resultmessage="jsbench time test run failed. " 
    }
    test "$measurememory" = "true" && {
        python ./runtests.py --config=jsbench --memory -r $branch -k -f -i 1
        test "$?" = "0" || { 
           result="1"; 
            resultmessage="$resultmessage \njsbench memory test run failed. " 
        }
    }
    echo ""
    echo "===========   Misc   ==========="
    python ./runtests.py --config=misc-mobile-Ojit --vmversion=${change} -r $branch -k -f -i 3 --vmargs="-Ojit"
    test "$?" = "0" || { 
        result="1"; 
        resultmessage="$resultmessage \nmisc time test run failed. " 
    }
    test "$measurememory" = "true" && {
        python ./runtests.py --config=misc --memory -r $branch -k -f -i 3
        test "$?" = "0" || { 
            result="1"; 
            resultmessage="$resultmessage \nmisc memory test run failed. " 
        }
    }
    echo ""
    echo "===========   SunSpider   ==========="
    python ./runtests.py --config=sunspider-mobile-Ojit --vmversion=${change} -r $branch -k -f -i 10 --vmargs="-Ojit"
    test "$?" = "0" || { 
        result="1"; 
        resultmessage="$resultmessage \nsunspider time test run failed. " 
    }
    test "$measurememory" = "true" && {
        python ./runtests.py --config=sunspider --memory -r $branch -k -f -i 3
        test "$?" = "0" || { 
            result="1"; 
            resultmessage="$resultmessage \nsunspider memory test run failed. " 
        }
    }
    
    echo ""
    echo "===========   V8   ==========="
    python ./runtests.py --config=v8 --vmversion=${change} -r $branch -k -f -i 3 --larger --vmargs="-Ojit"
    test "$?" = "0" || { 
        result="1"; 
        resultmessage="$resultmessage \nv8 time test run failed. " 
    }
    test "$measurememory" = "true" && {
        python ./runtests.py --config=v8 --memory -r $branch -k -f -i 3
        test "$?" = "0" || { 
            result="1"; 
            resultmessage="$resultmessage \nv8 memory test run failed. " 
        }
    }
        
    echo ""
    echo "===========   MMGC   ==========="
    python ./runtests.py --config=mmgc -r $branch -k -f -i 3 --vmargs="-Ojit"
    test "$?" = "0" || { 
        result="1"; 
        resultmessage="$resultmessage \nmmgc time test run failed. " 
    }
    test "$measurememory" = "true" && {
        python ./runtests.py --config=mmgc --memory -r $branch -k -f -i 1
        test "$?" = "0" || { 
            result="1"; 
            resultmessage="$resultmessage \nmmgc memory test run failed. " 
        }
    }
fi # second parameter

export memory_url="http://tamarin-builds.mozilla.org/report/index.cfm?hostip=${hostip}&config1=${configDefault}&config2=${configDefault}&configbaseline=${baselineConfigMemory}&baselineBuild=${baselineBuildMemory}&topBuild=${change}&product1=${branch}&product2=${branch}&productBaseline=${baselineBranchMemory}&raw=false&ratio=false&verbose=false&group=Desktop&metricsChecked=memory"
export time_url="http://tamarin-builds.mozilla.org/report/index.cfm?hostip=${hostip}&config1=${configDefault}&config2=${configDefault}&configbaseline=${baselineConfigTime}&baselineBuild=${baselineBuildTime}&topBuild=${change}&product1=${branch}&product2=${branch}&productBaseline=${baselineBranchTime}&raw=false&ratio=true&verbose=false&group=Desktop&metricsChecked=time"

echo ""
echo ""
echo "url: ${time_url} time report"
if [ "$branch" != "tamarin-tracing" ]
then
    echo "url: ${memory_url} memory report"
fi

test -f results.log && rm results.log
wget -O results.log -q ${time_url}
retry="0"
perfchg=""
while true
 do
  test -f results.log && {
    sleep 10
    perfchg=`cat results.log | grep -m1 "perfchange_ratio_time:" | awk -F"perfchange_ratio_time:" '{print $2}' | awk '{print $1}'`
    break
  }
  retry=`echo $retry | awk '{ print $1+1 }'`
  test "$retry" = "20" && break
  sleep 1
done
echo "perfchange: ${perfchg}%"


##
# Run any slave specific code POST performance
##
cd $basedir/build/buildbot/slaves/scripts/
. ./run-performance-post.sh

test "$result" = "0" && resultmessage="performance tests passed"
echo -e "message: $resultmessage"
exit $result