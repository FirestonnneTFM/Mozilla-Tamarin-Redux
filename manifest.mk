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
# The Original Code is [Open Source Virtual Machine].
#
# The Initial Developer of the Original Code is
# Adobe System Incorporated.
# Portions created by the Initial Developer are Copyright (C) 2010
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
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

STATIC_LIBRARIES += aot
aot_BUILD_ALL = 1
aot_CXXSRCS := \
  $(curdir)/AOTCompiler.cpp \
  $(curdir)/AOTStubs.cpp \
  $(NULL)

numstubs = 30
stubcpps := $(curdir)/AOTStubs-0000.cpp \
	$(curdir)/AOTStubs-0001.cpp \
	$(curdir)/AOTStubs-0002.cpp \
	$(curdir)/AOTStubs-0003.cpp \
	$(curdir)/AOTStubs-0004.cpp \
	$(curdir)/AOTStubs-0005.cpp \
	$(curdir)/AOTStubs-0006.cpp \
	$(curdir)/AOTStubs-0007.cpp \
	$(curdir)/AOTStubs-0008.cpp \
	$(curdir)/AOTStubs-0009.cpp \
	$(curdir)/AOTStubs-0010.cpp \
	$(curdir)/AOTStubs-0011.cpp \
	$(curdir)/AOTStubs-0012.cpp \
	$(curdir)/AOTStubs-0013.cpp \
	$(curdir)/AOTStubs-0014.cpp \
	$(curdir)/AOTStubs-0015.cpp \
	$(curdir)/AOTStubs-0016.cpp \
	$(curdir)/AOTStubs-0017.cpp \
	$(curdir)/AOTStubs-0018.cpp \
	$(curdir)/AOTStubs-0019.cpp \
	$(curdir)/AOTStubs-0020.cpp \
	$(curdir)/AOTStubs-0021.cpp \
	$(curdir)/AOTStubs-0022.cpp \
	$(curdir)/AOTStubs-0023.cpp \
	$(curdir)/AOTStubs-0024.cpp \
	$(curdir)/AOTStubs-0025.cpp \
	$(curdir)/AOTStubs-0026.cpp \
	$(curdir)/AOTStubs-0027.cpp \
	$(curdir)/AOTStubs-0028.cpp \
	$(curdir)/AOTStubs-0029.cpp \
	$(curdir)/AOTStubs-0030.cpp \
	$(NULL)

STATIC_LIBRARIES += aotstubs
aotstubs_BUILD_ALL = 1
aotstubs_CXXSRCS := $(stubcpps)
aotstubs_EXTRA_CXXFLAGS := -Wno-sign-compare

$(curdir)/dummy.cpp: $(topsrcdir)/aot/aotstubs.py $(topsrcdir)/aot/aotstubs.pickle
	@echo "Generating AOT stubs..."
	@mkdir -p aot
	@cd aot && python $(topsrcdir)/aot/AOTStubs.py --numstubs $(numstubs) --picklefile $(topsrcdir)/aot/aotstubs.pickle
	@touch $(curdir)/aot/dummy.cpp

$(stubcpps): $(curdir)/dummy.cpp