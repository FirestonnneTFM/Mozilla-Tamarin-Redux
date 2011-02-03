#!/usr/bin/env python
# -*- Mode: Python; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
# vi: set ts=4 sw=4 expandtab:

# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is [Open Source Virtual Machine.].
#
# The Initial Developer of the Original Code is
# Adobe System Incorporated.
# Portions created by the Initial Developer are Copyright (C) 2004-2006
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#   Adobe AS3 Team
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****

import os
import shutil
import sys
import filecmp

avm = os.environ.get('AVM')
if avm == None:
    print "ERROR: AVM environment variable must point to avm executable"
    exit(1)

classpath = os.environ.get('ASC')
if classpath == None:
    print "ERROR: ASC environment variable must point to asc.jar"
    exit(1)

asfile = "../utils/exactgc.as"
abcfile = "../utils/exactgc.abc"

if not os.path.exists(abcfile) or os.path.getmtime(abcfile) < os.path.getmtime(asfile):
    print("Compiling exactgc script...")
    os.system("java -jar " + classpath + " -AS3 -import ../generated/builtin.abc -import ../generated/shell_toplevel.abc -debug " + asfile)

# This is a mess, since DomainClass.{cpp,h} is in the avmplus namespace but the
# files reside with avmshell files.
print("Generating gcTrace methods...")
os.system(avm+" "+abcfile+" -- -ns avmshell -b avmshell-as3-gc.h -n avmshell-cpp-gc.h -i avmshell-gc-interlock.h shell_toplevel.as DebugCLI.h ShellCore.h SystemClass.h")
os.system(avm+" "+abcfile+" -- -b extensions-as3-gc.h -n extensions-cpp-gc.h -i extensions-gc-interlock.h DomainClass.h Domain.as ../extensions/*.h ../extensions/*.as")

# copy changed headers stuff to generated dir
for src in ['avmshell-as3-gc.h','avmshell-cpp-gc.h','avmshell-gc-interlock.h','extensions-as3-gc.h','extensions-cpp-gc.h','extensions-gc-interlock.h']:
    target = "../generated/"+src
    if not os.path.exists(target) or not filecmp.cmp(target,src):
        shutil.move(src,target)
    else:
        os.remove(src)

print("Done.")
