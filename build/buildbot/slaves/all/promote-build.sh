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


# This script takes the given revision and promotes it to the "latest" directory
# on asteam and also copies the files to the mozilla ftp site

# script is designed to only run on asteam

# $change contains the revision id we want to promote, $changeid is the hash
pushd $buildsdir

# verify the build exists
if [[ -d "$change-$changeid" ]]; then
    echo "$change-$changeid" >> greenBuilds.txt
    rm -r latest
    cp -R $change-$changeid latest
    echo "$change" > latest/revision.txt
    
    # promote the build on mozilla server
    # setup directory and delete older revs
    ssh stage.mozilla.org "~/setupbuilds.sh $branch $change-$changeid"
    scp -r $change-$changeid $scp_mozilla/$branch/
else
    echo "Revision to promote: $change-$changeid NOT FOUND in builds/tamarin-redux"
    exit 1
fi



