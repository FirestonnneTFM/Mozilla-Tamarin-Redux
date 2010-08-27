/* -*- tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

// This file is to be included in its clients

// method flags
const NEED_ARGUMENTS:int = 		0x01
const NEED_ACTIVATION:int = 	0x02
const NEED_REST:int = 			0x04
const HAS_OPTIONAL:int = 		0x08
const IGNORE_REST:int = 		0x10
const NATIVE:int =				0x20
const HAS_ParamNames:int =      0x80

const CONSTANT_Utf8					:int = 0x01
const CONSTANT_Int					:int = 0x03
const CONSTANT_UInt					:int = 0x04
const CONSTANT_PrivateNs			:int = 0x05 // non-shared namespace
const CONSTANT_Double				:int = 0x06
const CONSTANT_Qname				:int = 0x07 // o.ns::name, ct ns, ct name
const CONSTANT_Namespace			:int = 0x08
const CONSTANT_Multiname			:int = 0x09 // o.name, ct nsset, ct name
const CONSTANT_False				:int = 0x0A
const CONSTANT_True					:int = 0x0B
const CONSTANT_Null					:int = 0x0C
const CONSTANT_QnameA				:int = 0x0D // o.@ns::name, ct ns, ct attr-name
const CONSTANT_MultinameA			:int = 0x0E // o.@name, ct attr-name
const CONSTANT_RTQname				:int = 0x0F // o.ns::name, rt ns, ct name
const CONSTANT_RTQnameA				:int = 0x10 // o.@ns::name, rt ns, ct attr-name
const CONSTANT_RTQnameL				:int = 0x11 // o.ns::[name], rt ns, rt name
const CONSTANT_RTQnameLA			:int = 0x12 // o.@ns::[name], rt ns, rt attr-name
const CONSTANT_NameL				:int = 0x13	// o.[], ns=public implied, rt name
const CONSTANT_NameLA				:int = 0x14 // o.@[], ns=public implied, rt attr-name
const CONSTANT_NamespaceSet			:int = 0x15
const CONSTANT_PackageNs			:int = 0x16
const CONSTANT_PackageInternalNs	:int = 0x17
const CONSTANT_ProtectedNs			:int = 0x18
const CONSTANT_StaticProtectedNs	:int = 0x19
const CONSTANT_StaticProtectedNs2	:int = 0x1a
const CONSTANT_MultinameL           :int = 0x1B
const CONSTANT_MultinameLA          :int = 0x1C
const CONSTANT_TypeName             :int = 0x1D

const constantKinds:Array = [ "0", "utf8", "2",
"int", "uint", "private", "double", "qname", "namespace",
"multiname", "false", "true", "null", "@qname", "@multiname", "rtqname",
"@rtqname", "[qname]", "@[qname]", "[name]", "@[name]", "nsset", "packagens",
"packageinternalns", "protectedns", "staticprotectedns", "staticprotectedns2",
"multiname", "multiname2", "typename"
]

const TRAIT_Slot		:int = 0x00
const TRAIT_Method		:int = 0x01
const TRAIT_Getter		:int = 0x02
const TRAIT_Setter		:int = 0x03
const TRAIT_Class		:int = 0x04
const TRAIT_Function	:int = 0x05
const TRAIT_Const		:int = 0x06

const traitKinds:Array = [
"var", "function", "function get", "function set", "class", "function", "const"
]

include "opcodes-table.as"

const ATTR_final			:int = 0x01; // 1=final, 0=virtual
const ATTR_override         :int = 0x02; // 1=override, 0=new
const ATTR_metadata         :int = 0x04; // 1=has metadata, 0=no metadata
const ATTR_public           :int = 0x08; // 1=add public namespace
	
const CLASS_FLAG_sealed		:int = 0x01;
const CLASS_FLAG_final		:int = 0x02;
const CLASS_FLAG_interface	:int = 0x04;
