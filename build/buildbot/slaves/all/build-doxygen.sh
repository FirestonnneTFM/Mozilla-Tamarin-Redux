#!/bin/bash
# -*-Mode: Shell-script; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
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

# Need to export the change and changeid so that doxygen can see the values
export change=${change}
export changeid=${changeid}

##
# Make sure that docs directory is clean
##
cd $basedir
test -d docs && {
    echo Remove directory $basedir/docs
    rm -rf $basedir/docs
}
mkdir $basedir/docs

# build the doxygen docs
doxygen Doxyfile
res=$?
test "$res" = "0" || {
    echo "doxygen failed, return value $res"
    exit 1
}

# zip up the source to move to tamarin-builds
cd $basedir/docs
zip -r doxygen.zip html/

echo; echo; echo "===> Copy the new doxygen docs to tamarin-builds"
scp doxygen.zip ${scp_doxygen}

echo; echo; echo "===> Remove the old doxygen docs from tamarin-builds"
ssh ${doxygen_host} "cd ${doxygen_dir}; rm -rf html/"

echo; echo; echo "===> Unpack the doxygen.zip"
ssh ${doxygen_host} "cd ${doxygen_dir}; unzip doxygen.zip"

echo; echo; echo "===> Clean up the doxygen.zip file"
ssh ${doxygen_host} "cd ${doxygen_dir}; rm doxygen.zip"

echo; echo; echo "===> Clean up the local repo"
cd $basedir
rm -rf docs/

exit 0
