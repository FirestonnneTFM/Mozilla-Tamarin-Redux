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

abcdis_asfiles := $(abcdis_asfiles)\
  -in $(curdir)/abcdis/Utils.as\
  -in $(curdir)/abcdis/IPrinter.as\
  -in $(curdir)/abcdis/ByteArrayPrinter.as\
  -in $(curdir)/abcdis/TablePrinter.as\
  -in $(curdir)/abcdis/IndentingPrinter.as\
  -in $(curdir)/abcdis/abc/AbcAS3Traversal.as\
  -in $(curdir)/abcdis/abc/AbcAPIWriter.as\
  -in $(curdir)/abcdis/abc/AbcAsmWriter.as\
  -in $(curdir)/abcdis/abc/AbcDumpWriter.as\
  -in $(curdir)/abcdis/abc/AbcFormatWriter.as\
  -in $(curdir)/abcdis/abc/ABCReader.as\
  -in $(curdir)/abcdis/abc/AVMType.as\
  -in $(curdir)/abcdis/abc/BasicBlock.as\
  -in $(curdir)/abcdis/abc/Constants.as\
  -in $(curdir)/abcdis/abc/DOTWriter.as\
  -in $(curdir)/abcdis/abc/FrameState.as\
  -in $(curdir)/abcdis/abc/Instruction.as\
  -in $(curdir)/abcdis/abc/IReader.as\
  -in $(curdir)/abcdis/abc/MethodReference.as\
  -in $(curdir)/abcdis/abc/Reader.as\
  -in $(curdir)/abcdis/abc/Types/ABCFile.as\
  -in $(curdir)/abcdis/abc/Types/ABCObject.as\
  -in $(curdir)/abcdis/abc/Types/ClassInfo.as\
  -in $(curdir)/abcdis/abc/Types/ConstantMultiname.as\
  -in $(curdir)/abcdis/abc/Types/ConstantNamespace.as\
  -in $(curdir)/abcdis/abc/Types/ConstantNamespaceSet.as\
  -in $(curdir)/abcdis/abc/Types/Exception.as\
  -in $(curdir)/abcdis/abc/Types/InstanceInfo.as\
  -in $(curdir)/abcdis/abc/Types/MetadataInfo.as\
  -in $(curdir)/abcdis/abc/Types/MethodBody.as\
  -in $(curdir)/abcdis/abc/Types/MethodInfo.as\
  -in $(curdir)/abcdis/abc/Types/Pool.as\
  -in $(curdir)/abcdis/abc/Types/ScriptInfo.as\
  -in $(curdir)/abcdis/abc/Types/Trait.as\
  -in $(curdir)/abcdis/abc/Types/Traits.as\
  -in $(curdir)/abcdis/abc/Types/ValueKind.as\
  -in $(curdir)/abcdis/abc/Verifier.as\
  -in $(curdir)/abcdis/abc/XMLWriter.as\
  -in $(curdir)/abcdis/SWF/Constants.as\
  -in $(curdir)/abcdis/SWF/Rect.as\
  -in $(curdir)/abcdis/SWF/SWF.as\
  -in $(curdir)/abcdis/SWF/SWFReader.as\
  -in $(curdir)/abcdis/SWF/Tag.as\
  -in $(curdir)/abcdis/SWC/SWCReader.as\
  -in $(curdir)/abcdis/zip/ZipFile.as\
  -in $(curdir)/abcdis/ABCDump.as\
  $(NULL)

asc=java -jar $(ASC) -strict -d -md -AS3 -import ../generated/builtin.abc -import ../generated/shell_toplevel.abc 

utils:
	$(asc) $(abcdis_asfiles) $(curdir)/abcdis.as
	$(asc) $(abcdis_asfiles) $(curdir)/abcdisclassic.as

