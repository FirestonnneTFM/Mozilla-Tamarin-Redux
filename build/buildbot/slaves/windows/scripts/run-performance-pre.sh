#!/bin/sh
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

# allow to run script from tamarin-redux outside buildbot
test "$basedir" = "" && 
    basedir="."

# downloads kernel files for fc64 canary testcase
kerneldir=$basedir/other-licenses/test/performance/canaries/fc64util/kernel

# create dir if does not exist
test -d "$kerneldir" || 
    mkdir -p $kerneldir

# only download new kernel files if they don't exist
test -f $kerneldir/basic.901226-01.bin || {
    echo "downloading $kerneldir/basic.901226-01.bin"
    wget --quiet --output-file=$kerneldir/basic.901226-01.bin http://www.zimmers.net/anonftp/pub/cbm/firmware/computers/c64/basic.901226-01.bin
}

test -f $kerneldir/characters.901225-01.bin || {
    echo "downloading $kerneldir/characters.901225-01.bin"
    wget --quiet --output-file=$kerneldir/characters.901225-01.bin http://www.zimmers.net/anonftp/pub/cbm/firmware/computers/c64/characters.901225-01.bin
}

test -f $kerneldir/kernal.901227-03.bin || {
    echo "downloading $kerneldir/kernal.901227-03.bin"
    wget --quiet --output-file=$kerneldir/kernal.901227-03.bin http://www.zimmers.net/anonftp/pub/cbm/firmware/computers/c64/kernal.901227-03.bin
}
