#!/usr/bin/env python
# -*- Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5)
#
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
# Portions created by the Initial Developer are Copyright (C) 2011
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
# ***** END LICENSE BLOCK ***** */
#

# the script outputs a list of exclude patterns

# the exclude pattern to print
exclude_pattern=""

# document each exclude with a reason

# exclude the self tests, they are not part of the source code
exclude_pattern+="!extensions/ST_*.cpp !extensions/Selftest*.cpp "

# exclude generated code
exclude_pattern+="!generated/shell_toplevel.h !generated/shell_toplevel.cpp !generated/shell_toplevel*.hh "

# exclude Memory Profiler not part of flash player shipping code
exclude_pattern+="!MMgc/GCMemoryProfiler.h !MMgc/GCMemoryProfiler.cpp "

# exclude other-licenses, zlib and pcre, they are external packages
exclude_pattern+="!other-licenses/ !pcre/ "

# exclude the shell code, it is not part of the flash player shipping code
exclude_pattern+="!shell/ "

# exclude debugging utilities
exclude_pattern+="!vmbase/AvmAssert.cpp !VMPI/MacDebugUtils.cpp !VMPI/SpyUtils*.cpp !VMPI/*DebugUtils.cpp "

# exclude Sampler
exclude_pattern+="!extensions/SamplerScript.h "

# exclude vprof and eval tools, not part of flash player shipping code
exclude_pattern+="!vprof/ !eval/ "

# exclude gtest
exclude_pattern+="!gtest/ "

# The following functions in MathClass and MathUtils have been excluded
# from the coverage calculation as there are currently not reachable
# (not called from any other source):
# https://bugzilla.mozilla.org/show_bug.cgi?id=592728
exclude_pattern+="'!avmplus::MathClass::max2(double,double)' "
exclude_pattern+="'!avmplus::MathClass::min2(double,double)' "
exclude_pattern+="'!avmplus::MathUtils::equals(double,double)' "
exclude_pattern+="'!avmplus::MathUtils::infinity()' "
exclude_pattern+="'!avmplus::MathUtils::max(double,double)' "
exclude_pattern+="'!avmplus::MathUtils::min(double,double)' "
exclude_pattern+="'!avmplus::MathUtils::nan()' "
exclude_pattern+="'!avmplus::MathUtils::neg_infinity()' "
exclude_pattern+="'!avmplus::MathUtils::nextDigit(double*)' "
exclude_pattern+="'!avmplus::MathUtils::powerOfTen(int32_t,double)' "
exclude_pattern+="'!avmplus::MathUtils::roundInt(double)' "

# print exclude pattern
print(exclude_pattern)
