#!/usr/bin/env python
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
# Portions created by the Initial Developer are Copyright (C) 2007
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

import optparse, struct, os
from optparse import OptionParser
from struct import *
from os import path
from math import floor

parser = OptionParser(usage="usage: %prog [importfile [, importfile]...] file...")
opts, args = parser.parse_args()

if not args:
	parser.print_help()
	exit(2)

NEED_ARGUMENTS		= 0x01
NEED_ACTIVATION		= 0x02
NEED_REST			= 0x04
HAS_OPTIONAL		= 0x08
IGNORE_REST			= 0x10
NATIVE				= 0x20
HAS_ParamNames		= 0x80

CONSTANT_Utf8               = 0x01
CONSTANT_Int	            = 0x03
CONSTANT_UInt               = 0x04
CONSTANT_PrivateNs	        = 0x05
CONSTANT_Double             = 0x06
CONSTANT_Qname              = 0x07
CONSTANT_Namespace	        = 0x08
CONSTANT_Multiname          = 0x09
CONSTANT_False              = 0x0A
CONSTANT_True               = 0x0B
CONSTANT_Null               = 0x0C
CONSTANT_QnameA             = 0x0D
CONSTANT_MultinameA         = 0x0E
CONSTANT_RTQname	        = 0x0F
CONSTANT_RTQnameA	        = 0x10
CONSTANT_RTQnameL	        = 0x11
CONSTANT_RTQnameLA	        = 0x12
CONSTANT_NameL				= 0x13
CONSTANT_NameLA				= 0x14
CONSTANT_NamespaceSet       = 0x15
CONSTANT_PackageNs			= 0x16
CONSTANT_PackageInternalNs  = 0x17
CONSTANT_ProtectedNs		= 0x18
CONSTANT_ExplicitNamespace  = 0x19
CONSTANT_StaticProtectedNs  = 0x1A
CONSTANT_MultinameL         = 0x1B
CONSTANT_MultinameLA        = 0x1C
CONSTANT_TypeName	        = 0x1D

TRAIT_Slot			= 0x00
TRAIT_Method		= 0x01
TRAIT_Getter		= 0x02
TRAIT_Setter		= 0x03
TRAIT_Class			= 0x04
TRAIT_Const			= 0x06
TRAIT_mask			= 15

ATTR_final			= 0x10
ATTR_override       = 0x20
ATTR_metadata       = 0x40

CTYPE_VOID			= 0
CTYPE_ATOM			= 1
CTYPE_BOOLEAN		= 2
CTYPE_INT			= 3
CTYPE_UINT			= 4
CTYPE_DOUBLE		= 5
CTYPE_STRING		= 6
CTYPE_NAMESPACE		= 7
CTYPE_OBJECT		= 8

class Error:
	nm = ""
	def __init__(self, n):
		self.nm = n
	def __str__(self):
		return self.nm

TMAP = {
	CTYPE_OBJECT:		("o", "AvmObject"),
	CTYPE_ATOM:			("a", "AvmBox"),
	CTYPE_VOID:			("v", "void"),
	CTYPE_BOOLEAN:		("b", "AvmBoolArg"),
	CTYPE_INT:			("i", "int32_t"),
	CTYPE_UINT:			("u", "uint32_t"),
	CTYPE_DOUBLE:		("d", "double"),
	CTYPE_STRING:		("s", "AvmString"),
	CTYPE_NAMESPACE:	("n", "AvmNamespace")
};

def uint(i):
	return int(i) & 0xffffffff

def sigchar_from_enum(ct, allowObject):
	if ct == CTYPE_OBJECT and not allowObject:
		ct = CTYPE_ATOM
	return TMAP[ct][0]

def sigchar_from_traits(t, allowObject):
	return sigchar_from_enum(t.ctype, allowObject)

def ctype_from_enum(ct, allowObject):
	if ct == CTYPE_OBJECT and not allowObject:
		ct = CTYPE_ATOM
	return TMAP[ct][1]

def ctype_from_traits(t, allowObject):
	return ctype_from_enum(t.ctype, allowObject)

class Namespace:
	uri = ""
	kind = 0
	srcname = None
	def __init__(self, uri, kind):
		self.uri = uri
		self.kind = kind
	def __str__(self):
		return self.uri
	def isPublic(self):
		return self.kind in [CONSTANT_Namespace, CONSTANT_PackageNs] and self.uri == ""
	def isInternal(self):
		return self.kind in [CONSTANT_PackageInternalNs]
	def isPrivate(self):
		return self.kind in [CONSTANT_PrivateNs]
	def isProtected(self):
		return self.kind in [CONSTANT_ProtectedNs, CONSTANT_StaticProtectedNs]

class QName:
	ns = None
	name = ""
	def __init__(self, ns, name):
		self.ns = ns
		self.name = name
	def __str__(self):
		if str(self.ns) == "":
			return self.name
		if self.ns == None:
			return "*::" + self.name
		return str(self.ns) + "::" + self.name

class Multiname:
	nsset = None
	name = ""
	def __init__(self, nsset, name):
		self.nsset = nsset
		self.name = name
	def __str__(self):
		assert(0)
		return "FOO"

class TypeName:
	name = ""
	types = None
	def __init__(self, name, types):
		self.name = name
		self.types = types
	def __str__(self):
		return str(self.name)

class MetaData:
	name = ""
	attrs = {}
	def __init__(self, name):
		self.name = name
		self.attrs = {}

class MemberInfo:
	id = -1
	kind = -1
	name = ""
	metadata = None

class MethodInfo(MemberInfo):
	flags = 0
	debugName = ""
	paramTypes = None
	paramNames = None
	optional_count = 0
	optionalValues = None
	returnType = None
	local_count = 0
	max_scope = 0
	max_stack = 0
	code_length = 0
	code = None
	activation = None
	anon = False

	def isNative(self):
		return (self.flags & NATIVE) != 0

	def needRest(self):
		return (self.flags & NEED_REST) != 0

	def hasOptional(self):
		return (self.flags & HAS_OPTIONAL) != 0

class SlotInfo(MemberInfo):
	type = ""
	value = ""

BMAP = {
	"Object": CTYPE_ATOM, # yes, items of exactly class "Object" are stored as Atom; subclasses are stored as pointer-to-Object
	"null": CTYPE_ATOM,
	"*": CTYPE_ATOM,
	"void": CTYPE_VOID,
	"int": CTYPE_INT,
	"uint": CTYPE_UINT,
	"Number": CTYPE_DOUBLE,
	"Boolean": CTYPE_BOOLEAN,
	"String": CTYPE_STRING,
	"Namespace": CTYPE_NAMESPACE
};

class Traits:
	name = ""
	init = None
	itraits = None
	base = None
	flags = 0
	protectedNs = 0
	interfaces = None
	names = None
	slots = None
	tmethods = None
	members = None
	class_id = -1
	ctype = CTYPE_OBJECT
	def __init__(self, name):
		self.names = {}
		self.slots = []
		self.tmethods = []
		self.name = name
		if BMAP.has_key(str(name)):
			self.ctype = BMAP[str(name)]
	def __str__(self):
		return str(self.name)

NULL = Traits("*")
UNDEFINED = Traits("void")

class ByteArray:
	data = None
	pos = 0
	def __init__(self, data):
		self.data = data
		self.pos = 0
		
	def readU8(self):
		r = unpack_from("B", self.data, self.pos)[0]
		self.pos += 1
		assert(r >= 0 and r <= 255)
		return r

	def readU16(self):
		r = unpack_from("h", self.data, self.pos)[0]
		self.pos += 2
		assert(r >= 0 and r <= 65535)
		return r

	def readDouble(self):
		r = unpack_from("d", self.data, self.pos)[0]
		self.pos += 8
		return r

	def readBytes(self, lenbytes):
		r = self.data[self.pos:self.pos+lenbytes]
		self.pos += lenbytes
		return r

	def readUTF8(self):
		lenbytes = self.readU30()
		return self.readBytes(lenbytes)

	def readU30(self):
		result = self.readU8()
		if not result & 0x00000080:
			return result
		result = (result & 0x0000007f) | (self.readU8() << 7)
		if not result & 0x00004000:
			return result
		result = (result & 0x00003fff) | (self.readU8() << 14)
		if not result & 0x00200000:
			return result
		result = (result & 0x001fffff) | (self.readU8() << 21)
		if not result & 0x10000000:
			return result
		result = (result & 0x0fffffff) | (self.readU8() << 28)
		return result
		

class Abc:
	data = None
	major = 0
	minor = 0
	ints = None
	uints = None
	doubles = None
	strings = None
	namespaces = None
	nssets = None
	names = None
	defaults = None
	methods = None
	instances = None
	metadata = None
	classes = None
	scripts = None
	scriptName = ""
	publicNs = Namespace("", CONSTANT_Namespace)
	anyNs = Namespace("*", CONSTANT_Namespace)
	magic = 0
		
	def __init__(self, data, scriptName):
		self.scriptName = scriptName
		self.data = ByteArray(data)

		if self.data.readU16() != 16 or self.data.readU16() != 46:
			raise Error("Bad Abc Version")

		self.parseCpool()
		
		self.defaults = [ (None, 0) ] * 32
		self.defaults[CONSTANT_Utf8] = (self.strings, CTYPE_STRING)
		self.defaults[CONSTANT_Int] = (self.ints, CTYPE_INT)
		self.defaults[CONSTANT_UInt] = (self.uints, CTYPE_UINT)
		self.defaults[CONSTANT_Double] = (self.doubles, CTYPE_DOUBLE)
		self.defaults[CONSTANT_False] = ({ CONSTANT_False: False }, CTYPE_BOOLEAN)
		self.defaults[CONSTANT_True] = ({ CONSTANT_True: True }, CTYPE_BOOLEAN)
		self.defaults[CONSTANT_Namespace] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_PrivateNs] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_PackageNs] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_PackageInternalNs] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_ProtectedNs] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_StaticProtectedNs] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_ExplicitNamespace] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_Null] = ({ CONSTANT_Null: None }, CTYPE_ATOM)	
		
		self.parseMethodInfos()
		self.parseMetadataInfos()
		self.parseInstanceInfos()
		self.parseClassInfos()
		self.parseScriptInfos()
		self.parseMethodBodies()

	def default_ctype_and_value(self,d):
		kind, index = d
		deftable = self.defaults[kind]
		if deftable[0] != None:
			val = str(deftable[0][index])
			ct = deftable[1]
		else:
			assert(kind == 0 and index == 0)
			val = "kAvmThunkUndefined"
			ct = CTYPE_ATOM # yes, not void
		rawval = val
		if ct == CTYPE_DOUBLE:
			# Python apparently doesn't have isNaN, isInf
			if str(val) == "inf":
				val = "kAvmThunkInfinity"
			elif str(val) == "-inf":
				val = "kAvmThunkNegInfinity"
			elif str(val) == "nan":
				val = "kAvmThunkNaN"
			elif float(val) >= -2147483648.0 and float(val) <= 2147483647.0 and float(val) == floor(float(val)):
				ct = CTYPE_INT
				val = "%.0f" % float(val)
			elif float(val) >= 0.0 and float(val) <= 4294967295.0 and float(val) == floor(float(val)):
				ct = CTYPE_UINT
				val = "%.0fU" % float(val)
		elif ct == CTYPE_STRING:
			for i in range(0, len(self.strings)):
				if (self.strings[i] == str(val)):
					val = "AvmThunkConstant_AvmString("+str(i)+")/* \""+self.strings[i]+"\" */";
					break
		elif ct == CTYPE_BOOLEAN:
			assert(str(val) == "False" or str(val) == "True")
			if str(val) == "False":
				val = "false"
			else:
				val = "true"
		if str(val) == "None":
			val = "kAvmThunkNull"
		return ct,val,rawval
	
	def parseCpool(self):
		
		n = self.data.readU30()
		self.ints = [0] * n
		for i in range(1, n):
			ii = self.data.readU30()
			if float(ii) > 2147483647.0:
				ii = int(ii - 4294967296.0)
			assert(int(ii) >= -2147483648 and int(ii) <= 2147483647)
			self.ints[i] = int(ii)
			
		n = self.data.readU30()
		self.uints = [0] * n
		for i in range(1, n):
			self.uints[i] = uint(self.data.readU30())
			
		n = self.data.readU30()
		self.doubles = [ float("nan") ] * n
		for i in range(1, n):
			self.doubles[i] = self.data.readDouble()

		n = self.data.readU30()
		self.strings = [""] * n
		for i in range(1, n):
			self.strings[i] = self.data.readUTF8()

		n = self.data.readU30()
		self.namespaces = [self.publicNs] * n
		for i in range(1, n):
			nskind = self.data.readU8()
			if nskind in [CONSTANT_Namespace, 
							CONSTANT_PackageNs, 
							CONSTANT_PackageInternalNs,
							CONSTANT_ProtectedNs,
							CONSTANT_ExplicitNamespace,
							CONSTANT_StaticProtectedNs]:
				self.namespaces[i] = Namespace(self.strings[self.data.readU30()], nskind)

			elif nskind in [CONSTANT_PrivateNs]:
				self.data.readU30() # skip
				self.namespaces[i] = Namespace("private", CONSTANT_PrivateNs)

		n = self.data.readU30()
		self.nssets = [ None ] * n
		for i in range(1, n):
			count = self.data.readU30()
			self.nssets[i] = []
			for j in range(0, count):
				self.nssets[i].append(self.namespaces[self.data.readU30()])

		n = self.data.readU30()
		self.names = [ None ] * n
		self.namespaces[0] = self.anyNs
		self.strings[0] = "*"
		for i in range(1, n):
			namekind = self.data.readU8()
			if namekind in [CONSTANT_Qname, CONSTANT_QnameA]:
				self.names[i] = QName(self.namespaces[self.data.readU30()], self.strings[self.data.readU30()])

			elif namekind in [CONSTANT_RTQname, CONSTANT_RTQnameA]:
				self.names[i] = QName(self.anyNs, self.strings[self.data.readU30()])

			elif namekind in [CONSTANT_RTQnameL, CONSTANT_RTQnameLA]:
				self.names[i] = None

			elif namekind in [CONSTANT_NameL, CONSTANT_NameLA]:
				self.names[i] = QName(Namespace(""), None)

			elif namekind in [CONSTANT_Multiname, CONSTANT_MultinameA]:
				name = self.strings[self.data.readU30()]
				nsset = self.nssets[self.data.readU30()]
				self.names[i] = Multiname(nsset, name)

			elif namekind in [CONSTANT_MultinameL, CONSTANT_MultinameLA]:
				nsset = self.nssets[self.data.readU30()]
				self.names[i] = Multiname(nsset, None)

			elif namekind in [CONSTANT_TypeName]:
				name = self.names[self.data.readU30()];
				count = self.data.readU30();
				types = []
				for j in range(0, count):
					types.append(self.names[self.data.readU30()]);
				self.names[i] = TypeName(name, types);
			else:
				raise Error("Bad Kind")

		self.namespaces[0] = self.publicNs
		self.strings[0] = "*"

	def parseMethodInfos(self):
		self.names[0] = QName(self.publicNs,"*")
		method_count = self.data.readU30()
		self.methods = [ None ] * method_count
		for i in range(0, method_count):
			m = MethodInfo()
			self.methods[i] = m
			param_count = self.data.readU30()
			m.returnType = self.names[self.data.readU30()]
			m.paramTypes = [ None ] * param_count
			m.optional_count = 0
			for j in range(0, param_count):
				m.paramTypes[j] = self.names[self.data.readU30()]
				m.paramNames = ""
			m.debugName = self.strings[self.data.readU30()]
			m.flags = self.data.readU8()
			if m.hasOptional():
				m.optional_count = self.data.readU30();
				m.optionalValues = [ (-1, -1) ] * param_count
				for k in range(param_count-m.optional_count, param_count):
					index = self.data.readU30()
					kind = self.data.readU8()
					m.optionalValues[k] = (kind, index)
			if (m.flags & HAS_ParamNames) != 0:
				for j in range(0, param_count):
					m.paramNames[j] = self.strings[self.data.readU30()]

	def parseMetadataInfos(self):
		count = self.data.readU30()
		self.metadata = [ None ] * count
		for i in range (0, count):
			mname = self.strings[self.data.readU30()]
			m = MetaData(mname)
			self.metadata[i] = m
			values_count = self.data.readU30()
			names = [ None ] * values_count
			for q in range(0, values_count):
				names[q] = self.strings[self.data.readU30()]
			for q in range(0, values_count):
				m.attrs[names[q]] = self.strings[self.data.readU30()] 

	def parseInstanceInfos(self):
		count = self.data.readU30()
		self.instances = [ None ] * count
		for i in range (0, count):
			tname = self.names[self.data.readU30()]
			t = Traits(tname)
			self.instances[i] = t
			t.base = self.names[self.data.readU30()]
			t.flags = self.data.readU8()
			if (t.flags & 8) != 0:
				t.protectedNs = self.namespaces[self.data.readU30()]
			interface_count = self.data.readU30()
			t.interfaces = [None] * interface_count
			for j in range(0, interface_count):
				t.interfaces[j] = self.names[self.data.readU30()]
			methid = self.data.readU30()
			t.init = self.methods[methid]
			t.init.name = t.name
			t.init.kind = TRAIT_Method
			t.init.id = methid
			self.parseTraits(t)
	
	def parseTraits(self, t):
		namecount = self.data.readU30()
		t.members = [ None ] * namecount
		for i in range(0, namecount):
			name = self.names[self.data.readU30()]
			tag = self.data.readU8()
			kind = tag & 0xf
			member = None
			if kind in [TRAIT_Slot, TRAIT_Const, TRAIT_Class]:
				member = SlotInfo()
				member.id = self.data.readU30()
				while len(t.slots) <= member.id:
					t.slots.append(None)
				t.slots[member.id] = member
				if kind in [TRAIT_Slot, TRAIT_Const]:
					member.type = self.names[self.data.readU30()]
					index = self.data.readU30()
					if index:
						deftable = self.defaults[self.data.readU8()]
						member.value = deftable[0][index]
						if deftable[1] == CTYPE_NAMESPACE:
							assert(isinstance(member.value, Namespace))
							member.value.srcname = name.name
				else:
					member.value = self.classes[self.data.readU30()]
			elif kind in [TRAIT_Method, TRAIT_Getter, TRAIT_Setter]:
				self.data.readU30()	# disp_id, ignored
				methid = self.data.readU30()
				member = self.methods[methid]
				t.tmethods.append(member)
				member.id = methid
			member.kind = kind
			member.name = name
			t.members[i] = member
			t.names[str(name)] = member
			
			if (tag & ATTR_metadata) != 0:
				mdCount = self.data.readU30()
				member.metadata = [ None ] * mdCount
				for j in range(0, mdCount):
					member.metadata[j] = self.metadata[self.data.readU30()]

	def parseClassInfos(self):
		count = len(self.instances)
		self.classes = [ None ] * count
		for i in range(0, count):
			itraits = self.instances[i]
			tname = str(itraits.name) + "$"
			t = Traits(tname)
			self.classes[i] = t
			t.init = self.methods[self.data.readU30()]
			t.base = "Class"
			t.itraits = itraits
			t.init.name = str(t.itraits.name) + "$cinit"
			t.init.kind = TRAIT_Method
			self.parseTraits(t)

	def parseScriptInfos(self):
		count = self.data.readU30()
		self.scripts = [ None ] * count
		for i in range(0, count):
			tname = self.scriptName + "_script_" + str(i)
			t = Traits(tname)
			self.scripts[i] = t
			t.init = self.methods[self.data.readU30()]
			t.base = self.names[0]
			t.itraits = None
			t.init.name = t.name + "$init"
			t.init.kind = TRAIT_Method	    
			self.parseTraits(t)

	def parseMethodBodies(self):
		count = self.data.readU30()
		for i in range(0, count):
			m = self.methods[self.data.readU30()]
			m.max_stack = self.data.readU30()
			m.local_count = self.data.readU30()
			initScopeDepth = self.data.readU30()
			maxScopeDepth = self.data.readU30()
			m.max_scope = maxScopeDepth - initScopeDepth
			code_length = self.data.readU30()
			m.code = self.data.readBytes(code_length)
			ex_count = self.data.readU30()
			for j in range(0, ex_count):
				frm = self.data.readU30()
				to = self.data.readU30()
				target = self.data.readU30()
				type = self.names[self.data.readU30()]
				name = self.names[self.data.readU30()];
			m.activation = Traits(None)
			self.parseTraits(m.activation)


class IndentingPrintWriter:
	f = None
	indent = 0

	def __init__(self, file):
		self.f = file

	def prnt(self, s):
		self.f.write(s)

	def println(self, s):
		for i in range(0, self.indent):
			self.f.write("    ")
		self.f.write(s)
		self.f.write("\n")

def to_cname(nm):
	nm = str(nm)
	nm = nm.replace("+", "_");
	nm = nm.replace("-", "_");
	nm = nm.replace("?", "_");
	nm = nm.replace("!", "_");
	nm = nm.replace("<", "_");
	nm = nm.replace(">", "_");
	nm = nm.replace("=", "_");
	nm = nm.replace("(", "_");
	nm = nm.replace(")", "_");
	nm = nm.replace("\"", "_");
	nm = nm.replace("'", "_");
	nm = nm.replace("*", "_");
	nm = nm.replace(" ", "_");
	nm = nm.replace(".", "_");
	nm = nm.replace("$", "_");
	nm = nm.replace("::", "_");
	nm = nm.replace(":", "_");
	nm = nm.replace("/", "_");
	return nm

class AbcThunkGen:
	abc = None
	abcs = []
	out_h = None
	out_c = None
	native_methods = {}
	unique_thunks = {}
	lookup_traits = None

	def addAbc(self, a):
		self.abcs.append(a)
		self.lookup_traits = None

	def emit(self, abc, name, out_h, out_c):
		self.abc = abc;
		self.out_h = out_h;
		self.out_c = out_c;
		self.native_methods = {}
		self.unique_thunks = {}
		self.lookup_traits = None

		for i in range(0, len(abc.classes)):
			abc.classes[i].class_id = i

		out_h.println("/* machine generated file -- do not edit */");
		out_c.println("/* machine generated file -- do not edit */");

		out_h.println("#define AVMTHUNK_VERSION 2");
		
		out_h.println("const uint32_t "+name+"_abc_class_count = "+str(len(abc.classes))+";");
		out_h.println("const uint32_t "+name+"_abc_script_count = "+str(len(abc.scripts))+";");
		out_h.println("const uint32_t "+name+"_abc_method_count = "+str(len(abc.methods))+";");
		out_h.println("const uint32_t "+name+"_abc_length = "+str(len(abc.data.data))+";");
		out_h.println("extern const uint8_t "+name+"_abc_data["+str(len(abc.data.data))+"];");

		for i in range(0, len(abc.scripts)):
			script = abc.scripts[i]
			if script == None:
				continue
			# not enough info in the ABC to recover the original name (eg abcpackage_Foo_as) 
			# so output identifiers based on the native script functions found
			for j in range(0, len(script.tmethods)):
				m = script.tmethods[j]
				if (m != None) and m.isNative():
					out_h.println("const uint32_t abcscript_"+ to_cname(m.name) + " = " + str(i) + ";") # yes, i, not j
			self.emitSourceTraits("", script)

		out_c.println("// "+str(len(self.unique_thunks.keys()))+" unique thunks");

		for sig in self.unique_thunks:
			users = self.unique_thunks[sig]
			receiver = None;
			m = None;
			for native_name in users:
				out_c.println("// "+native_name);
				receiver = users[native_name][0];
				m = users[native_name][1];
			thunkname = name+"_"+sig;
			# emit both with and without-cookie versions, since we can't tell at this point which
			# might be used for a particular method. rely on linker to strip the unused ones.
			self.emitThunk(thunkname, receiver, m, False);
			self.emitThunk(thunkname, receiver, m, True);
			for native_name in users:
				receiver = users[native_name][0];
				m = users[native_name][1];
				assert(m.id >= 0)
				out_h.println("  const uint32_t "+native_name+" = "+str(m.id)+";");
				# use #define here (rather than constants) to avoid the linker including them and thus preventing dead-stripping
				# (sad but true, happens in some environments)
				out_h.println("  #define "+native_name+"_thunk  "+thunkname+"_thunk")
				out_h.println("  #define "+native_name+"_thunkc "+thunkname+"_thunkc")

		# cpp file - abc data, thunks
		#print "Emit ABC Data..." 
		n = len(abc.data.data)
		out_c.println("const uint8_t "+name+"_abc_data["+str(n)+"] = {");
		for i in range(0, n):
			x = ord(abc.data.data[i]) & 255;
			out_c.prnt("%3d" % x)
			if i+1 < n: 
				out_c.prnt(", ")
			if i%16 == 15:
				out_c.println("");
		out_c.println("};");

	def argTraits(self, receiver, m):
		argtraits = [ receiver ]
		for i in range(0, len(m.paramTypes)):
			argtraits.append(self.lookupTraits(m.paramTypes[i]))
		return argtraits

	def emitThunk(self, name, receiver, m, cookie):
		ret = ctype_from_traits(self.lookupTraits(m.returnType), False);
		
		cstr = ""
		if cookie:
			cstr = "c"
		decl = "AvmThunkRetType_"+ret+" AVMTHUNK_CALLTYPE "+name+"_thunk"+cstr+"(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)"

		self.out_h.println("extern "+decl+";");

		self.out_c.println(decl);
		self.out_c.println("{");
		self.out_c.indent += 1;

		param_count = len(m.paramTypes);
		optional_count = m.optional_count;

		argtraits = self.argTraits(receiver, m)

		argszprev = "0"
		for i in range(0, len(argtraits)):
			cts = ctype_from_traits(argtraits[i], True);
			if i == 0:
				self.out_c.println("const uint32_t argoff0 = 0;");
			else:
				self.out_c.println("const uint32_t argoff"+str(i)+" = argoff"+str(i-1)+" + "+argszprev+";");
			argszprev = "AvmThunkArgSize_"+cts;
	
		if m.needRest():
			self.out_c.println("const uint32_t argoffV = argoff"+str(len(argtraits)-1)+" + "+argszprev+";");
		
		args = []

		for i in range(0, len(argtraits)):
			cts = ctype_from_traits(argtraits[i], True)
			val = "AvmThunkUnbox_"+cts+"(argv[argoff" + str(i) + "])";
			# argtraits includes receiver at 0, optionalValues does not
			if i > param_count - optional_count:
				dct,defval,defvalraw = self.abc.default_ctype_and_value(m.optionalValues[i-1]);
				dts = ctype_from_enum(dct, True)
				if dts != cts:
					defval = "AvmThunkCoerce_"+dts+"_"+cts+"("+defval+")";
				val = "(argc < "+str(i)+" ? "+defval+" : "+val+")";
			args.append((val, cts))
			if i == 0 and cookie:
				args.append(("AVMTHUNK_GET_COOKIE(env)", "int32_t"))

		if m.needRest():
			args.append(("(argc <= "+str(param_count)+" ? NULL : argv + argoffV)", "const AvmBox*"))
			args.append(("(argc <= "+str(param_count)+" ? 0 : argc - "+str(param_count)+")", "uint32_t"))

		if not m.hasOptional() and not m.needRest():
			self.out_c.println("(void)argc;");

		self.out_c.println("AVMTHUNK_DEBUG_ENTER(env)");
		
		call = "";
		if ret != "void":
			call += "const "+ret+" ret = ";		
		call += "AVMTHUNK_CALL_FUNCTION_"+str(len(args)-1)+"(AVMTHUNK_GET_HANDLER(env), "+ret;
		self.out_c.println(call)
		self.out_c.indent += 1
		for i in range(0, len(args)):
			self.out_c.println(", " + args[i][1] + ", " + args[i][0]);
		self.out_c.indent -= 1
		self.out_c.println(");")

		self.out_c.println("AVMTHUNK_DEBUG_EXIT(env)")

		self.out_c.println("return AvmToRetType_"+ret+"(ret);")
		self.out_c.indent -= 1
		self.out_c.println("}")

	def lookupTraits(self, name):
		name = str(name)
		if self.lookup_traits == None:
			self.lookup_traits = {}
			self.lookup_traits["*"] = NULL
			self.lookup_traits["void"] = UNDEFINED
			for a in self.abcs:
				for t in a.scripts:
					if self.lookup_traits.has_key(str(t)):
						raise Error("duplicate name found: " + name)
					self.lookup_traits[str(t)] = t
				for t in a.classes:
					if self.lookup_traits.has_key(str(t)):
						raise Error("duplicate name found: " + name)
					self.lookup_traits[str(t)] = t
				for t in a.instances:
					if self.lookup_traits.has_key(str(t)):
						raise Error("duplicate name found: " + name)
					self.lookup_traits[str(t)] = t
		if not self.lookup_traits.has_key(name):
			raise Error("name not found: " + name)
		return self.lookup_traits[name]
		
	def thunkSig(self, receiver, m):
		sig = sigchar_from_traits(self.lookupTraits(m.returnType), False)+"2";
		if m.returnType.name == "Number":
			sig += "d"
		else:
			sig += "a"
		sig += "_";
		argtraits = self.argTraits(receiver, m)
		for i in range(0, len(argtraits)):
			sig += sigchar_from_traits(argtraits[i], True)
		if m.hasOptional():
			param_count = len(m.paramTypes)
			for i in range(param_count - m.optional_count, param_count):
				dct,defval,defvalraw = self.abc.default_ctype_and_value(m.optionalValues[i]);
				sig += "_opt" + sigchar_from_enum(dct, True) + to_cname(defval)
		if m.needRest():
			sig += "_rest"
		return sig;

	def gatherThunk(self, native_name, receiver, m):
		self.native_methods[m.id] = native_name		
		sig = self.thunkSig(receiver, m)
		if not self.unique_thunks.has_key(sig):
			self.unique_thunks[sig] = {}
		self.unique_thunks[sig][native_name] = (receiver, m)

	def ns_prefix(self, ns, iscls):
		if not ns.isPublic() and not ns.isInternal():
			if ns.isPrivate() and not iscls:
				return "private_";
			if ns.isProtected():
				return "protected_";
			if ns.srcname != None:
				return to_cname(str(ns.srcname)) + "_"
		p = to_cname(ns.uri);
		if len(p) > 0:
			p += "_"
		return p

	def propLabel(self, b):
		assert(isinstance(b.name,QName))
		return self.ns_prefix(b.name.ns, False) + to_cname(b.name.name)

	def emitSourceClass(self, b):
		assert(isinstance(b.name,QName))
		label = self.ns_prefix(b.name.ns, True) + to_cname(b.name.name)
		c = b.value
		self.out_h.println("const int abcclass_"+ label + " = " + str(c.class_id) + ";");
		self.emitSourceTraits(label+"_", c)
		self.emitSourceTraits(label+"_", c.itraits)

	def emitSourceMethod(self, prefix, receiver, m):
		if m != None and m.isNative():
			native_name = prefix + self.propLabel(m)
			if m.kind == TRAIT_Getter:
				native_name += "_get"
			elif m.kind == TRAIT_Setter:
				native_name += "_set"		
			self.gatherThunk(native_name, receiver, m)

	def emitSourceTraits(self, prefix, s):
		if s.init != None and s.init.isNative():
			native_name = prefix + to_cname(s.name.name) # not self.propLabel(s)
			self.gatherThunk(native_name, s, s.init)
		for i in range(0, len(s.members)):
			if s.members[i].kind in [TRAIT_Method,TRAIT_Getter,TRAIT_Setter]:
				self.emitSourceMethod(prefix, s, s.members[i])
			elif s.members[i].kind in [TRAIT_Class]:
				self.emitSourceClass(s.members[i]);
	
ngen = AbcThunkGen();
abcGenFor = None
abcGenName = ""
for file in args:
	try:
		f = open(file,"r")
		data = f.read()
	finally:
		f.close()

	abcScriptName = os.path.splitext(os.path.split(file)[1])[0]
	#print "read %s" % abcScriptName
	abcGenFor = Abc(data, abcScriptName)
	ngen.addAbc(abcGenFor)
	abcGenName = os.path.splitext(file)[0]

if abcGenFor:
	try:
		hf = open(abcGenName+".h2","w")
		hc = open(abcGenName+".cpp2","w")
		h = IndentingPrintWriter(hf)
		c = IndentingPrintWriter(hc)
		ngen.emit(abcGenFor, abcScriptName, h, c);
	finally:
		hf.close()
		hc.close()



		