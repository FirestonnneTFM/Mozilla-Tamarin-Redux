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
# Portions created by the Initial Developer are Copyright (C) 2005-2006
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

STATIC_LIBRARIES += avmplus
avmplus_BUILD_ALL = 1

avmplus_CXXSRCS := $(avmplus_CXXSRCS) \
  $(curdir)/AbcEnv.cpp \
  $(curdir)/AbcParser.cpp \
  $(curdir)/ActionBlockConstants.cpp \
  $(curdir)/ArrayClass.cpp \
  $(curdir)/ArrayObject.cpp \
  $(curdir)/atom.cpp \
  $(curdir)/AvmCore.cpp \
  $(curdir)/avm.cpp \
  $(curdir)/avmfeatures.cpp \
  $(curdir)/AvmLog.cpp \
  $(curdir)/avmplusDebugger.cpp \
  $(curdir)/avmplusHashtable.cpp \
  $(curdir)/avmplusList.cpp \
  $(curdir)/BigInteger.cpp \
  $(curdir)/BooleanClass.cpp \
  $(curdir)/BuiltinTraits.cpp \
  $(curdir)/ByteArrayGlue.cpp \
  $(curdir)/CdeclThunk.cpp \
  $(curdir)/ClassClass.cpp \
  $(curdir)/ClassClosure.cpp \
  $(curdir)/CodegenLIR.cpp \
  $(curdir)/Coder.cpp \
  $(curdir)/d2a.cpp \
  $(curdir)/DataIO.cpp \
  $(curdir)/DateClass.cpp \
  $(curdir)/DateObject.cpp \
  $(curdir)/DescribeTypeClass.cpp \
  $(curdir)/Domain.cpp \
  $(curdir)/DomainEnv.cpp \
  $(curdir)/DomainMgr.cpp \
  $(curdir)/E4XNode.cpp \
  $(curdir)/ErrorClass.cpp \
  $(curdir)/ErrorConstants.cpp \
  $(curdir)/Exception.cpp \
  $(curdir)/exec.cpp \
  $(curdir)/exec-jit.cpp \
  $(curdir)/exec-osr.cpp \
  $(curdir)/exec-verifyall.cpp \
  $(curdir)/FrameState.cpp \
  $(curdir)/FunctionClass.cpp \
  $(curdir)/IntClass.cpp \
  $(curdir)/Interpreter.cpp \
  $(curdir)/InvokerCompiler.cpp \
  $(curdir)/JSONClass.cpp \
  $(curdir)/LirHelper.cpp \
  $(curdir)/MathClass.cpp \
  $(curdir)/MathUtils.cpp \
  $(curdir)/MethodClosure.cpp \
  $(curdir)/MethodEnv.cpp \
  $(curdir)/MethodInfo.cpp \
  $(curdir)/Multiname.cpp \
  $(curdir)/MultinameHashtable.cpp \
  $(curdir)/Namespace.cpp \
  $(curdir)/NamespaceClass.cpp \
  $(curdir)/NamespaceSet.cpp \
  $(curdir)/NativeFunction.cpp \
  $(curdir)/NumberClass.cpp \
  $(curdir)/ObjectClass.cpp \
  $(curdir)/peephole.cpp \
  $(curdir)/PoolObject.cpp \
  $(curdir)/PrintWriter.cpp \
  $(curdir)/QCache.cpp \
  $(curdir)/RegExpClass.cpp \
  $(curdir)/RegExpObject.cpp \
  $(curdir)/Sampler.cpp \
  $(curdir)/ScopeChain.cpp \
  $(curdir)/ScriptBuffer.cpp \
  $(curdir)/ScriptObject.cpp \
  $(curdir)/StackTrace.cpp \
  $(curdir)/StringBuffer.cpp \
  $(curdir)/StringClass.cpp \
  $(curdir)/StringObject.cpp \
  $(curdir)/Toplevel.cpp \
  $(curdir)/Traits.cpp \
  $(curdir)/TypeDescriber.cpp \
  $(curdir)/UnicodeUtils.cpp \
  $(curdir)/VectorClass.cpp \
  $(curdir)/Verifier.cpp \
  $(curdir)/VTable.cpp \
  $(curdir)/WordcodeEmitter.cpp \
  $(curdir)/WordcodeTranslator.cpp \
  $(curdir)/wopcodes.cpp \
  $(curdir)/XMLClass.cpp \
  $(curdir)/XMLListClass.cpp \
  $(curdir)/XMLListObject.cpp \
  $(curdir)/XMLObject.cpp \
  $(curdir)/XMLParser16.cpp \
  $(curdir)/Date.cpp \
  $(curdir)/AbcData.cpp \
  $(curdir)/AvmPlusScriptableObject.cpp \
  $(curdir)/instr.cpp \
  $(curdir)/ProxyGlue.cpp \
  $(NULL)

#  $(curdir)/avmplus.cpp \

# See manifest.mk in root directory for the dependencies
# on $(topsrcdir)/generated/builtin.h.

# Use of '%' [to force a pattern-rule] instead of '$(curdir)/..' or
# '$(topsrcdir)' [which would then not be a pattern-rule] is crucial
# (ie "deliberate", ie "hack"); see Bug 632086
%/generated/builtin.h %/generated/builtin.cpp: $(topsrcdir)/core/*.as
	cd $(topsrcdir)/core; python builtin.py

# 1. Use of '$(topsrcdir)/generated' is deliberate; we use absolute
#    paths for code being generated outside build dir.
#
# 2. Use of '$(curdir)/AbcData.$(II_SUFFIX)' is also deliberate:
#    preprocessed file as target must be specified via same path that
#    is used in root manifest.mk.
#
# Further discussion at Bug 632086.
$(curdir)/AbcData.$(II_SUFFIX): $(topsrcdir)/generated/builtin.cpp

# Bug 654996: use target-specific variable to disable -Werror in these cases
ifeq ($(TARGET_OS),darwin)
$(curdir)/Interpreter.$(OBJ_SUFFIX): avmplus_CXXFLAGS += -Wno-error
endif
ifeq ($(TARGET_OS),android)
$(curdir)/Interpreter.$(OBJ_SUFFIX): avmplus_CXXFLAGS += -Wno-error
endif
