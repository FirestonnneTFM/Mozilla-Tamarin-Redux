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

showhelp ()
{
    echo ""
    echo "usage: compile-generic.sh <change> <config> <filename> <upload>"
    echo "       <change>       changeset that is going to be built"
    echo "       <config>       config options passed to configure.py"
    echo "       <filename>     name of the shell, do not include file extension"
    echo "       <upload>       (true|false) upload shell to server"
    echo "       <features>     +<feature> -<feature>, will ensure specified"
    echo "                      features are either enabled(+) or disabled(-)"
    exit 1
}

config=$2
test "$config" = "" && {
    showhelp
}
test "$CONFIGURE_ARGS" != "" && {
    echo "CONFIGURE_ARGS=$CONFIGURE_ARGS, appending to config"
    config="$config $CONFIGURE_ARGS"
}

filename=$3
test "$filename" = "" && {
    showhelp
}

upload=$4
test "$upload" = "true" || {
    upload=false
}

# Features to confirm being enabled or disabled
features=$5

# silence output if silent=true (function defined in environment.sh)
logfile=build-$platform-$filename.log
beginSilent

##
# Update the version string
##

. ../all/util-update-version.sh


##
# Make sure that there are no left over directories from previous compile
##
cd $basedir
test -d objdir && {
    echo Remove directory $basedir/objdir
    rm -rf $basedir/objdir
}

mkdir objdir

cd objdir

echo ""
echo "*******************************************************************************"
echo "configure.py call:"
echo "../configure.py $config"
python ../configure.py $config
echo ""
echo "*******************************************************************************"

echo ""
echo "*******************************************************************************"
echo "Makefile:"
echo ""
cat Makefile
echo ""
echo "*******************************************************************************"
topsrcdir=`grep topsrcdir= Makefile | awk -F"=" '{print $2}'`
CXX=`grep CXX= Makefile | awk -F"=" '{print $2}'| sed 's/(/{/' | sed 's/)/}/' | sed 's/-nologo//'`
echo compiler version: 
if [ `uname` == "SunOS" ]; then
    eval ${CXX} -V
else
    eval ${CXX} --version
fi
echo ""
echo "*******************************************************************************"
echo ""


make $MAKE_OPTIONS clean

echo ""
echo "*******************************************************************************"
echo ""
echo "make $MAKE_OPTIONS"
echo ""
make $MAKE_OPTIONS
res=$?

test "$res" = "0" || {
    echo "build failed return value $res"
}
test -f shell/$shell || {
    echo "avmshell is missing, build failed"
    cd $basedir/core
    mv avmplusVersion.h.orig avmplusVersion.h
    endSilent
    exit 1
}

mkdir -p $buildsdir/${change}-${changeid}/$platform
chmod 777 $buildsdir/${change}-${changeid}/$platform
cp shell/$shell $buildsdir/${change}-${changeid}/$platform/$filename$shell_extension
chmod 777 $buildsdir/${change}-${changeid}/$platform/$filename$shell_extension


# Check to see if it is possible to run the generated shell, we could be cross compiling
# Look for the version string since calling the shell without an ABC will have a non-zero exitcode
$buildsdir/${change}-${changeid}/$platform/$filename$shell_extension | grep ${change}:${changeid} &> /dev/null
res=$?
if [ "$res" == "0" ]; then
    echo ""
    echo "*******************************************************************************"
    echo "shell compiled with these features:"
    avmfeatures=`$buildsdir/${change}-${changeid}/$platform/$filename$shell_extension -Dversion | grep AVM | sed 's/\;/ /g' | sed 's/features //g'`
    for i in ${avmfeatures}; do
	echo $i
    done
    echo ""
    failbuild=0
    for i in ${features}; do
	feature_ok=0
	if [[ $i == +* ]]; then
	    echo "Make sure that ${i:1} is enabled"
	    for feat in ${avmfeatures}; do
		if [ "$feat" == "${i:1}" ]; then
		    feature_ok=1
		    break		
		fi
            done
	    if [ $feature_ok != 1 ]; then
		echo "---> FAIL"
		failbuild=1
	    else
		echo "---> PASS"
	    fi
	fi
	if [[ $i == -* ]]; then
	    feature_ok=1
	    echo "Make sure that ${i:1} is NOT enabled"
	    for feat in ${avmfeatures}; do
		if [ "$feat" == "${i:1}" ]; then
		    feature_ok=0
		    break		
		fi
            done
	    if [ $feature_ok == 0 ]; then
		echo "---> FAIL"
		failbuild=1
	    else
		echo "---> PASS"
	    fi
	fi
	echo ""
    done
    if [ $failbuild == 1 ]; then
	echo "message: feature check FAILED"
	cd $basedir/core
	mv avmplusVersion.h.orig avmplusVersion.h
	# Remove the binary since we have determined that it is NOT valid
	rm $buildsdir/${change}-${changeid}/$platform/$filename$shell_extension
	endSilent
	exit 1
    fi
    echo "*******************************************************************************"
fi # end feature check

cd $basedir/core
mv avmplusVersion.h.orig avmplusVersion.h



# Post the build shell to ASTEAM
if ${upload}; then
    cd $basedir/build/buildbot/slaves/scripts/
    ../all/util-upload-ftp-asteam.sh $buildsdir/${change}-${changeid}/$platform/$filename$shell_extension $ftp_asteam/$branch/${change}-${changeid}/$platform/$filename$shell_extension
    ret=$?
    if [ "$ret" != "0" ]; then
	echo "Uploading of $platform/$filename$shell_extension failed"
	exit 1
    fi
fi

echo "build succeeded"
rm -rf $basedir/objdir

endSilent

exit 0

