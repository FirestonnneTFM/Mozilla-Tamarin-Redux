#!/usr/bin/env python
# -*- Mode: Python; indent-tabs-mode: nil -*-
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

# Documentation for native annotations.
#
# Classes can be annotated with 'native' metainformation:
#
#   [native(cls="...", ...)]
#   public class Fnord extends FnordBase { ... }
#
# or
#
#   [native("...")]
#   public class Fnord extends FnordBase { ... }
#
# The latter form is equivalent to the former with a single cls attribute (?).
#
# The named attributes are:
#
#   cls             the C++ name for the class object's class (required)
#   instance        the C++ name for the instance object's class (required)
#   gc              the GC method for both class and instance objects
#   classgc         the GC method for the class object
#   instancegc      the GC method for the instance object
#   methods         ?
#   construct       indicates that the class has a nonstandard construction pipeline:
#
#                   "none": the class cannot be instantiated, nor can subclasses; we will generate a stub
#                       that throws kCantInstantiateError. (Typically used for classes that provide only 
#                       static members and/or static methods.)
#
#                   "check": the class is expected to provide a function of the form
#
#                           static void FASTCALL preCreateInstanceCheck(ClassClosure* cls)
#
#                       which will be called prior to creation of an instance; this function is
#                       allowed to throw an exception to prevent object creation. (Throwing
#                       an exception in the C++ ctor is discouraged, as our current longjmp implementation
#                       of exception handling can result in a half-constructed object, which could cause
#                       issues at object destruction time.)
#
#                   "restricted": subclasses must be defined in the same ABC chunk as the baseclass (otherwise they will 
#                       throw kCantInstantiateError). This is an odd beast, used by Flash for classes 
#                       which can't be subclassed by user code (only by builtin code.)
#
#                   "restricted-check": Like restricted, but with a preCreateInstanceCheck function required as well.
#
#                   "abstract": the class cannot be instantiated, but its subclasses can (ie, an Abstract Base Class);
#                       we will generate a stub that throws kCantInstantiateError when appropriate.
#
#                   "abstract-restricted": is the union of of abstract+restricted: the class can't be instantiated,
#                       and subclasses can only from from the same ABC chunk.
#
#                   * THE FOLLOWING VALUES FOR construct ARE ONLY LEGAL FOR USE IN THE BASE VM BUILTINS * 
#
#                   "override": the Class must provide an override of the ScriptObject::construct() method.
#                       (We will autogenerate a createInstanceProc stub that asserts if called.) 
#
#                   "instance": the Class *and* Instance must provide an override of the ScriptObject::construct() method.
#                       (We will autogenerate a createInstanceProc stub that asserts if called.) 
#
#   instancebase    if the instance inherits from a C++ class that can't be inferred from the AS3 inheritance,
#                   it must be specified here. this is not supported for new code; it's provided for temporary support
#                   of existing code.
#
# The allowable values for "gc", "classgc", and "instancegc" are "exact"
# and "conservative"; the default is "conservative".  If the value is "exact" 
# then tracers are autogenerated based on annotations on the C++ class and 
# on the pointer fields in the C++ class.
#
# For more information about GC see the documentation in utils/exactgc.as.

import optparse, struct, os, sys, StringIO
from optparse import OptionParser
from struct import *
from os import path
from math import floor
from sys import stderr

import sys

parser = OptionParser(usage="usage: %prog [importfile [, importfile]...] file...")
parser.add_option("-n", "--nativemapname", help="no longer supported")
parser.add_option("-v", "--thunkvprof", action="store_true", default=False)
parser.add_option("-e", "--externmethodandclassetables", action="store_true", default=False, help="generate extern decls for method and class tables")
parser.add_option("--native-id-namespace", dest="nativeIDNS", default="avmplus::NativeID", help="Specifies the C++ namespace in which all generated should be in.")
parser.add_option("--root-implementation-namespace", dest="rootImplNS", default="avmplus", help="Specifies the C++ namespace in under which all implementation classes can be found.")
opts, args = parser.parse_args()

if not args:
    parser.print_help()
    exit(2)

if opts.nativemapname:
    raise Error("--nativemapname is no longer supported")

NEED_ARGUMENTS      = 0x01
NEED_ACTIVATION     = 0x02
NEED_REST           = 0x04
HAS_OPTIONAL        = 0x08
IGNORE_REST         = 0x10
NATIVE              = 0x20
HAS_ParamNames      = 0x80

CONSTANT_Utf8               = 0x01
CONSTANT_Int                = 0x03
CONSTANT_UInt               = 0x04
CONSTANT_PrivateNs          = 0x05
CONSTANT_Double             = 0x06
CONSTANT_Qname              = 0x07
CONSTANT_Namespace          = 0x08
CONSTANT_Multiname          = 0x09
CONSTANT_False              = 0x0A
CONSTANT_True               = 0x0B
CONSTANT_Null               = 0x0C
CONSTANT_QnameA             = 0x0D
CONSTANT_MultinameA         = 0x0E
CONSTANT_RTQname            = 0x0F
CONSTANT_RTQnameA           = 0x10
CONSTANT_RTQnameL           = 0x11
CONSTANT_RTQnameLA          = 0x12
CONSTANT_NameL              = 0x13
CONSTANT_NameLA             = 0x14
CONSTANT_NamespaceSet       = 0x15
CONSTANT_PackageNs          = 0x16
CONSTANT_PackageInternalNs  = 0x17
CONSTANT_ProtectedNs        = 0x18
CONSTANT_ExplicitNamespace  = 0x19
CONSTANT_StaticProtectedNs  = 0x1A
CONSTANT_MultinameL         = 0x1B
CONSTANT_MultinameLA        = 0x1C
CONSTANT_TypeName           = 0x1D

TRAIT_Slot          = 0x00
TRAIT_Method        = 0x01
TRAIT_Getter        = 0x02
TRAIT_Setter        = 0x03
TRAIT_Class         = 0x04
TRAIT_Const         = 0x06
TRAIT_mask          = 15

ATTR_final          = 0x10
ATTR_override       = 0x20
ATTR_metadata       = 0x40

CTYPE_VOID          = 0
CTYPE_ATOM          = 1
CTYPE_BOOLEAN       = 2
CTYPE_INT           = 3
CTYPE_UINT          = 4
CTYPE_DOUBLE        = 5
CTYPE_STRING        = 6
CTYPE_NAMESPACE     = 7
CTYPE_OBJECT        = 8

MIN_API_MARK = 0xE000
MAX_API_MARK = 0xF8FF

MPL_HEADER = "/* ***** BEGIN LICENSE BLOCK *****\n" \
            " * Version: MPL 1.1/GPL 2.0/LGPL 2.1\n" \
            " *\n" \
            " * The contents of this file are subject to the Mozilla Public License Version\n" \
            " * 1.1 (the \"License\"); you may not use this file except in compliance with\n" \
            " * the License. You may obtain a copy of the License at\n" \
            " * http://www.mozilla.org/MPL/\n" \
            " *\n" \
            " * Software distributed under the License is distributed on an \"AS IS\" basis,\n" \
            " * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License\n" \
            " * for the specific language governing rights and limitations under the\n" \
            " * License.\n" \
            " *\n" \
            " * The Original Code is [Open Source Virtual Machine].\n" \
            " *\n" \
            " * The Initial Developer of the Original Code is\n" \
            " * Adobe System Incorporated.\n" \
            " * Portions created by the Initial Developer are Copyright (C) 2008\n" \
            " * the Initial Developer. All Rights Reserved.\n" \
            " *\n" \
            " * Contributor(s):\n" \
            " *   Adobe AS3 Team\n" \
            " *\n" \
            " * Alternatively, the contents of this file may be used under the terms of\n" \
            " * either the GNU General Public License Version 2 or later (the \"GPL\"), or\n" \
            " * the GNU Lesser General Public License Version 2.1 or later (the \"LGPL\"),\n" \
            " * in which case the provisions of the GPL or the LGPL are applicable instead\n" \
            " * of those above. If you wish to allow use of your version of this file only\n" \
            " * under the terms of either the GPL or the LGPL, and not to allow others to\n" \
            " * use your version of this file under the terms of the MPL, indicate your\n" \
            " * decision by deleting the provisions above and replace them with the notice\n" \
            " * and other provisions required by the GPL or the LGPL. If you do not delete\n" \
            " * the provisions above, a recipient may use your version of this file under\n" \
            " * the terms of any one of the MPL, the GPL or the LGPL.\n" \
            " *\n" \
            " * ***** END LICENSE BLOCK ***** */"

# Python 2.5 and earlier didn't reliably handle float("nan") and friends uniformly
# across all platforms. This is a workaround that appears to be more reliable.
# if/when we require Python 2.6 or later we can use a less hack-prone approach
kPosInf = 1e300000
kNegInf = -1e300000
kNaN = kPosInf / kPosInf

def is_nan(val):
    strValLower = str(val).lower()
    return strValLower == "nan"

def is_pos_inf(val):
    # [-]1.#INF on Windows in Python 2.5.2!
    strValLower = str(val).lower()
    return strValLower.endswith("inf") and not strValLower.startswith("-")

def is_neg_inf(val):
    # [-]1.#INF on Windows in Python 2.5.2!
    strValLower = str(val).lower()
    return strValLower.endswith("inf") and strValLower.startswith("-")

class Error(Exception):
    nm = ""
    def __init__(self, n):
        self.nm = n
    def __str__(self):
        return self.nm

BASE_CLASS_NAME = "::avmplus::ClassClosure"
BASE_INSTANCE_NAME = "::avmplus::ScriptObject"

TMAP = {
    # map ctype -> in-arg-type, ret-arg-type, base-type
    CTYPE_OBJECT:       (BASE_INSTANCE_NAME+"*", BASE_INSTANCE_NAME+"*", BASE_INSTANCE_NAME),
    CTYPE_ATOM:         ("avmplus::Atom", "avmplus::Atom", "#error"),
    CTYPE_VOID:         ("void", "void", "#error"),
    CTYPE_BOOLEAN:      ("avmplus::bool32", "bool", "#error"),
    CTYPE_INT:          ("int32_t", "int32_t", "#error"),
    CTYPE_UINT:         ("uint32_t", "uint32_t", "#error"),
    CTYPE_DOUBLE:       ("double", "double", "#error"),
    CTYPE_STRING:       ("avmplus::String*", "avmplus::String*", "avmplus::String"),
    CTYPE_NAMESPACE:    ("avmplus::Namespace*", "avmplus::Namespace*", "avmplus::Namespace")
};

def uint(i):
    return int(i) & 0xffffffff

def ctype_from_enum(ct, allowObject):
    if ct == CTYPE_OBJECT and not allowObject:
        ct = CTYPE_ATOM
    return TMAP[ct][0]

def c_rettype_from_enum(ct, allowObject):
    if ct == CTYPE_OBJECT and not allowObject:
        ct = CTYPE_ATOM
    return TMAP[ct][1]

def ctype_from_traits(t, allowObject):
    return ctype_from_enum(t.ctype, allowObject)

def c_rettype_from_traits(t, allowObject):
    return c_rettype_from_enum(t.ctype, allowObject)

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


def parseCPPClassName(className):
    prependRootNS = (len(opts.rootImplNS) > 0)
    if (className.startswith('::')):
        prependRootNS = False
    fullyQualifiedName = (opts.rootImplNS + '::' + className) if prependRootNS else className
    fullyQualifiedNameComponents = fullyQualifiedName.split('::')
    if (len(fullyQualifiedNameComponents) < 2):
        fullyQualifiedNameComponents = (u'', fullyQualifiedNameComponents)
    return ('::'.join(filter(lambda ns: len(ns) > 0, fullyQualifiedNameComponents[:-1])), fullyQualifiedNameComponents[-1])
    
def fullyQualifiedCPPClassName(className):
    r = parseCPPClassName(className)
    return "%s::%s" % (r[0], r[1])


def ns_prefix(ns, iscls):
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

def stripVersion(uri):
    if len(uri) > 0:
        uri16 = uri.decode('utf8')
        cc = ord(uri16[-1])
        if cc >= MIN_API_MARK and cc <= MAX_API_MARK:
            return cc-MIN_API_MARK, uri16[0:len(uri16)-1].encode('utf8')
    return -1,uri

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
    def stripVersion(self):
        api, strippeduri = stripVersion(self.uri)
        # it's important to return 'self' (and not an identical clone)
        # if we are unversioned, otherwise native methods with custom namespaces
        # may be emitted incorrectly
        if api < 0:
            return self
        newself = Namespace(strippeduri, self.kind)
        newself.srcname = self.srcname
        return newself

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
        nsStrings = map(lambda ns: u'"' + ns.decode("utf8") + u'"', self.nsset)
        stringForNSSet = u'[' + u', '.join(nsStrings) + u']'
        return stringForNSSet + u'::' + unicode(self.name.decode("utf8"))

class TypeName:
    name = ""
    types = None
    def __init__(self, name, types):
        self.name = name
        self.types = types
    def __str__(self):
        # @todo horrible special-casing, improve someday
        s = str(self.name)
        t = str(self.types[0])
        if t == "int":
            s += "$int"
        elif t == "uint":
            s += "$uint"
        elif t == "Number":
            s += "$double"
        else:
            s += "$object"
        return s

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
    native_id_name = None
    native_method_name = None
    final = False
    override = False
    receiver = None
    unbox_this = -1 # -1 == undetermined, 0 = no, 1 = yes

    def isNative(self):
        return (self.flags & NATIVE) != 0

    def needRest(self):
        return (self.flags & NEED_REST) != 0

    def hasOptional(self):
        return (self.flags & HAS_OPTIONAL) != 0

    def assign_names(self, traits, prefix):
        self.receiver = traits

        if not self.isNative():
            return

        if self == traits.init:
            raise Error("ctors cannot be native")

        assert(isinstance(self.name, QName))
        self.native_id_name = prefix + ns_prefix(self.name.ns, False) + self.name.name
        self.native_method_name = self.name.name

        if self.kind == TRAIT_Getter:
            self.native_id_name += "_get"
            self.native_method_name = "get_" + self.native_method_name
        elif self.kind == TRAIT_Setter:
            self.native_id_name += "_set"
            self.native_method_name = "set_" + self.native_method_name

        if self.name.ns.srcname != None:
            self.native_method_name = str(self.name.ns.srcname) + "_" + self.native_method_name

        # if we are an override, prepend the classname to the C method name.
        # (native method implementations must not be virtual, and some compilers
        # will be unhappy if a subclass overrides a method with the same name and signature
        # without it being virtual.) Note that we really only need to do this if the ancestor
        # implementation is native, rather than pure AS3, but we currently do it regardless.
        if self.override:
            self.native_method_name = traits.name.name + "_" + self.native_method_name

        self.native_method_name = to_cname(self.native_method_name)

class SlotInfo(MemberInfo):
    type = ""
    value = ""
    fileOffset = -1

class NativeInfo:
    class_name = None
    class_gc_exact = None
    instance_name = None
    instancebase_name = None
    instance_gc_exact = None
    gen_method_map = False
    method_map_name = None
    constSetters = False
    construct = None
    createInstanceProcName = None

    def fill_in_nativeinfo(self, attrs, is_vm_builtin):
        for k in attrs.keys():
            v = attrs[k]
            if (k == "script"):
                raise Error("native scripts are no longer supported; please use a native class instead and wrap with AS3 code as necessary.")

            elif (k == "cls"):
                self.set_class(v)
            elif (k == "instance"):
                self.set_instance(v)
            elif (k == "instancebase"):
                self.set_instancebase(v)
            elif (k == "gc"):
                self.set_classGC(v)
                self.set_instanceGC(v)
            elif (k == "classgc"):
                self.set_classGC(v)
            elif (k == "instancegc"):
                self.set_instanceGC(v)
            elif (k == "methods"):
                self.gen_method_map = True
                if v != "auto":
                    self.method_map_name = v
            elif (k == "constsetters"):
                if (v == "true"):
                    self.constSetters = True
                elif (v != "false"):
                    raise Error(u'native metadata specified illegal value, "%s" for constsetters field.  Value must be "true" or "false".' % unicode(v))
            elif (k == "construct"):
                self.set_construct(v, is_vm_builtin)
            else:
                raise Error("unknown attribute native(%s)" % k)
        if (self.class_name == None) and (self.instance_name == None):
            raise Error("native metadata must specify (cls,instance)")
  
    def set_class(self, name):
        if self.class_name != None:
            raise Error("native(cls) may not be specified multiple times for the same class: %s %s" % (self.class_name, name))
        self.class_name = name

    def set_instance(self, name):
        if self.instance_name != None:
            raise Error("native(instance) may not be specified multiple times for the same class: %s %s" % (self.instance_name, name))
        if name == "ScriptObject" or name == BASE_INSTANCE_NAME:
            raise Error("native(instance='ScriptObject') is no longer supported:")
        self.instance_name = name

    def set_instancebase(self, name):
        if self.instancebase_name != None:
            raise Error("native(instancebase) may not be specified multiple times for the same class: %s %s" % (self.instancebase_name, name))
        self.instancebase_name = name

    def set_construct(self, value, is_vm_builtin):
        if self.construct != None:
            raise Error("native(construct) may not be specified multiple times for the same class")
        if value in ["override", "instance"]:
            if not is_vm_builtin:
                raise Error('construct=%s may only be specified for the VM builtins' % value)
            self.construct = value
        elif value in ["none", "abstract", "abstract-restricted", "restricted", "check", "restricted-check"]:
            self.construct = value
        else:
            raise Error('native metadata specified illegal value, "%s" for construct field.' % value)
   
    def set_classGC(self, gc):
        if self.class_gc_exact != None:
            raise Error("native(classgc) may not be specified multiple times for the same class: %s %s" % (self.class_name, gc))
        if gc == "exact":
            self.class_gc_exact = True
        elif gc == "conservative":
            True
        else:
            raise Error("native(classgc) can only be specified as 'exact' or 'conservative': %s %s" % (self.class_name, gc))

    def set_instanceGC(self, gc):
        if self.instance_gc_exact != None:
            raise Error("native(instancegc) may not be specified multiple times for the same class: %s %s" % (self.instance_name, gc))
        if gc == "exact":
            self.instance_gc_exact = True
        elif gc == "conservative":
            True
        else:
            raise Error("native(instancegc) can only be specified as 'exact' or 'conservative': %s %s" % (self.instance_name, gc))

    def validate(self, t):
        if self.gen_method_map and self.class_name == None and self.instance_name == None:
            raise Error("cannot specify native(methods) without native(cls)")

        no_native_instance_specified = (self.construct == None and self.instance_name == None)
        
        # if either is specified, make sure both are
        if self.class_name != None or self.instance_name != None:
            if self.class_name == None:
                self.class_name = BASE_CLASS_NAME
            if self.instance_name == None:
                self.instance_name = BASE_INSTANCE_NAME

        if self.construct != None:
            t.construct = self.construct
            if t.construct in ["override", "instance"]:
                t.has_construct_method_override = True
            if t.construct in ["abstract-restricted", "restricted", "restricted-check"]:
                t.is_restricted_inheritance = True
            if t.construct in ["abstract", "abstract-restricted"]:
                t.is_abstract_base = True
            if t.construct in ["check", "restricted-check"]:
                t.has_pre_create_check = True
            if self.construct == "instance":
                t.itraits.construct = "override"
                t.itraits.has_construct_method_override = True

        if str(t.name) == "Object$" or no_native_instance_specified:
            # "Object" is special-cased.
            self.createInstanceProcName = "ClassClosure::createScriptObjectProc"

        elif t.construct in ["none", "abstract", "abstract-restricted"]:
            self.createInstanceProcName = "ClassClosure::cantInstantiateCreateInstanceProc"

        elif t.construct in ["override", "instance"] or t.itraits.ctype != CTYPE_OBJECT:
            self.createInstanceProcName = "ClassClosure::impossibleCreateInstanceProc"

        elif self.class_name != None:
            self.createInstanceProcName = "%s::createInstanceProc" % fullyQualifiedCPPClassName(self.class_name)
            t.has_custom_createInstanceProc = True


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
    qname = None
    init = None
    itraits = None
    base = None
    flags = 0
    protectedNs = 0
    is_sealed = False
    is_final = False
    is_interface = False
    interfaces = None
    names = None
    slots = None
    tmethods = None
    members = None
    class_id = -1
    ctype = CTYPE_OBJECT
    metadata = None
    ni = None
    niname = None
    nextSlotId = 0
    construct = None
    # some values for "construct" imply an override to the ScriptObject::construct method,
    # some don't. this simplifies things.
    has_construct_method_override = False
    has_custom_createInstanceProc = False
    is_restricted_inheritance = False
    is_abstract_base = False
    has_pre_create_check = False
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
        r = unpack_from("<h", self.data, self.pos)[0]
        self.pos += 2
        assert(r >= 0 and r <= 65535)
        return r

    def readDouble(self):
        r = unpack_from("<d", self.data, self.pos)[0]
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
    versioned_uris = {}
    is_vm_builtin = False

    magic = 0

    qnameToName = {}
    nameToQName = {}

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

        for i in range(0, len(self.classes)):
            c = self.classes[i]
            assert(isinstance(c.name, QName))
            prefix = ns_prefix(c.name.ns, True) + to_cname(c.name.name)
            c.class_id = i
            c.ni = self.find_class_nativeinfo(c)
            c.niname = c.ni.class_name
            self.assign_names(c, prefix)
            if c.itraits:
                c.itraits.ni = c.ni
                c.itraits.niname = c.ni.instance_name
                self.assign_names(c.itraits, prefix)

        for i in range(0, len(self.scripts)):
            script = self.scripts[i]
            if script != None:
                for j in range(0, len(script.tmethods)):
                    m = script.tmethods[j]
                    if m.metadata != None:
                        for md in m.metadata:
                            if md.name == "native":
                                if md.attrs.has_key("script"):
                                    raise Error("native(script) is no longer supported; please use a native(\"function-name\") instead: " + str(m.name))
                                if len(md.attrs) != 1 or not md.attrs.has_key(""):
                                    raise Error("native(\"function-name\") is the only form supported here" + str(m.name))
                                if not m.isNative():
                                    raise Error("native(\"function-name\") can only be used on native functions" + str(m.name))
                                m.receiver = None
                                m.native_method_name = md.attrs[""]     # override
                                m.native_id_name = "native_script_function_" + ns_prefix(m.name.ns, False) + m.name.name
                                #m.native_id_name = "native_script_function_" + to_cname(m.native_method_name)
                                m.gen_method_map = True


    def assign_names(self, traits, prefix):
        if traits.init != None:
            traits.init.assign_names(traits, prefix)
        for j in range(0, len(traits.tmethods)):
            traits.tmethods[j].assign_names(traits, prefix)

    def default_ctype_and_value(self,d):
        kind, index = d
        deftable = self.defaults[kind]
        if deftable[0] != None:
            val = str(deftable[0][index])
            ct = deftable[1]
        else:
            assert(kind == 0 and index == 0)
            val = "undefinedAtom"
            ct = CTYPE_ATOM # yes, not void
        rawval = val
        if ct == CTYPE_DOUBLE:
            # Python apparently doesn't have isNaN, isInf
            if is_nan(val):
                val = "MathUtils::kNaN"
            elif is_neg_inf(val):
                val = "MathUtils::kNegInfinity"
            elif is_pos_inf(val):
                val = "MathUtils::kInfinity"
            elif float(val) >= -2147483648.0 and float(val) <= 2147483647.0 and float(val) == floor(float(val)):
                ct = CTYPE_INT
                val = "%.0f" % float(val)
            elif float(val) >= 0.0 and float(val) <= 4294967295.0 and float(val) == floor(float(val)):
                ct = CTYPE_UINT
                val = "%.0fU" % float(val)
        elif ct == CTYPE_STRING:
            for i in range(0, len(self.strings)):
                if (self.strings[i] == str(val)):
                    val = "AvmThunkGetConstantString(%d)/* \"%s\" */" % (i, self.strings[i])
                    break
        elif ct == CTYPE_BOOLEAN:
            assert(str(val) == "False" or str(val) == "True")
            if str(val) == "False":
                val = "false"
            else:
                val = "true"
        if str(val) == "None":
            val = "nullObjectAtom"
        return ct,val,rawval

    def parseCpool(self):

        n = self.data.readU30()
        self.ints = [0] * max(1,n)
        for i in range(1, n):
            ii = self.data.readU30()
            if float(ii) > 2147483647.0:
                ii = int(ii - 4294967296.0)
            assert(int(ii) >= -2147483648 and int(ii) <= 2147483647)
            self.ints[i] = int(ii)

        n = self.data.readU30()
        self.uints = [0] * max(1,n)
        for i in range(1, n):
            self.uints[i] = uint(self.data.readU30())

        n = self.data.readU30()
        self.doubles = [ kNaN ] * max(1,n)
        for i in range(1, n):
            self.doubles[i] = self.data.readDouble()

        n = self.data.readU30()
        self.strings = [""] * max(1,n)
        for i in range(1, n):
            self.strings[i] = self.data.readUTF8()

        n = self.data.readU30()
        self.namespaces = [self.anyNs] * max(1,n)
        for i in range(1, n):
            nskind = self.data.readU8()
            if nskind in [CONSTANT_Namespace,
                            CONSTANT_PackageNs,
                            CONSTANT_PackageInternalNs,
                            CONSTANT_ProtectedNs,
                            CONSTANT_ExplicitNamespace,
                            CONSTANT_StaticProtectedNs]:
                uri = self.strings[self.data.readU30()]
                self.namespaces[i] = Namespace(uri, nskind)
                # if it's public, and the final char has the magic "version mark",
                # it's a versioned namespace uri
                if nskind in [CONSTANT_Namespace, CONSTANT_PackageNs]:
                    api, strippeduri = stripVersion(uri)
                    if api >= 0:
                        if not strippeduri in self.versioned_uris:
                            self.versioned_uris[strippeduri] = []
                        if not api in self.versioned_uris[strippeduri]:
                            self.versioned_uris[strippeduri].append(api)

            elif nskind in [CONSTANT_PrivateNs]:
                self.data.readU30() # skip
                self.namespaces[i] = Namespace("private", CONSTANT_PrivateNs)

        n = self.data.readU30()
        self.nssets = [ None ] * max(1,n)
        for i in range(1, n):
            count = self.data.readU30()
            self.nssets[i] = []
            for j in range(0, count):
                self.nssets[i].append(self.namespaces[self.data.readU30()])

        n = self.data.readU30()
        self.names = [ None ] * max(1,n)
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
            m.paramNames = [ "" ] * param_count
            m.optional_count = 0
            for j in range(0, param_count):
                m.paramTypes[j] = self.names[self.data.readU30()]
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
        instancesDict = {}
        for i in range (0, count):
            tname = self.names[self.data.readU30()]
            t = Traits(tname)
            self.instances[i] = t
            instancesDict[id(tname)] = t
            t.base = self.names[self.data.readU30()]
            t.flags = self.data.readU8()
            if (t.flags & 1) != 0:
                t.is_sealed = True
            if (t.flags & 2) != 0:
                t.is_final = True
            if (t.flags & 4) != 0:
                t.is_interface = True
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
            self.parseTraits(t, instancesDict.get(id(t.base), None))

    @staticmethod
    def __qname(name):
        if isinstance(name, QName):
            return name
        if len(name.nsset) == 0:
            return QName(Namespace("", CONSTANT_Namespace), name.name)
        return QName(name.nsset[0].stripVersion(), name.name)

    def qname(self, name):
        if (not self.nameToQName.has_key(id(name))):
            try:
                result = self.__qname(name)
            except:
                print dir(name)
                raise
            self.qnameToName[id(result)] = name
            self.nameToQName[id(name)] = result
            return result
        return self.nameToQName[id(name)]

    def parseTraits(self, t, baseTraits=None):
        lastBaseTraitsSlotId = 0 if baseTraits is None else baseTraits.nextSlotId
        namecount = self.data.readU30()
        t.members = [ None ] * namecount
        for i in range(0, namecount):
            name_index = self.data.readU30()
            name = self.names[name_index]
            name = self.qname(name)
            bindingOffset = self.data.pos
            tag = self.data.readU8()
            kind = tag & 0xf
            member = None
            if kind in [TRAIT_Slot, TRAIT_Const, TRAIT_Class]:
                member = SlotInfo()
                member.fileOffset = bindingOffset
                memberId = self.data.readU30()
                member.id = (memberId - 1) if memberId != 0 else (len(t.slots) + lastBaseTraitsSlotId)
                memberIndex = member.id - lastBaseTraitsSlotId
                while len(t.slots) <= memberIndex:
                    t.slots.append(None)
                t.slots[member.id - lastBaseTraitsSlotId] = member
                t.nextSlotId = max(t.nextSlotId, member.id + 1)
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
                    member.value.qname = name
            elif kind in [TRAIT_Method, TRAIT_Getter, TRAIT_Setter]:
                self.data.readU30() # disp_id, ignored
                methid = self.data.readU30()
                member = self.methods[methid]
                t.tmethods.append(member)
                member.id = methid
                member.final = (tag & ATTR_final) != 0
                member.override = (tag & ATTR_override) != 0
            member.kind = kind
            member.name = name
            t.members[i] = member
            t.names[str(name)] = member

            if (tag & ATTR_metadata) != 0:
                mdCount = self.data.readU30()
                member.metadata = [ None ] * mdCount
                for j in range(0, mdCount):
                    member.metadata[j] = self.metadata[self.data.readU30()]
                # stash class metadata in the ctraits and itraits too, makes it much easier later
                if kind == TRAIT_Class:
                    member.value.metadata = member.metadata
                    member.value.itraits.metadata = member.metadata

    def find_nativeinfo(self, m, ni):
        if m != None:
            for md in m:
                if md.name == "native":
                    ni.fill_in_nativeinfo(md.attrs, self.is_vm_builtin)

    def find_class_nativeinfo(self, t):
        ni = NativeInfo()
        self.find_nativeinfo(t.metadata, ni)
        if ni.instance_name != None and t.itraits.is_interface:
            raise Error("interfaces may not specify native(instance)")
        ni.validate(t)
        return ni

    def parseClassInfos(self):
        count = len(self.instances)
        self.classes = [ None ] * count
        for i in range(0, count):
            itraits = self.instances[i]
            tname = QName(itraits.name.ns, (str(itraits.name.name) + "$"))
            if str(tname) == "Object$":
                self.is_vm_builtin = True
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
    do_indent = True

    def __init__(self, file):
        self.f = file

    def dent(self):
        if self.do_indent:
            for i in range(0, self.indent):
                self.f.write("    ")
            self.do_indent = False

    def prnt(self, s):
        self.dent();
        self.f.write(s)

    def println(self, s):
        if s != "":
            self.dent();
            self.f.write(s)
        self.f.write("\n")
        self.do_indent = True


def outputBasicSlotDecl(output, slotDict):
    output.println(u'%(type)s m_%(name)s;' % slotDict)

def outputWBRCSlotDecl(output, slotDict):
    output.println(u'DRCWB(%(type)s) m_%(name)s;' % slotDict)

def outputWBAtomSlotDecl(output, slotDict):
    output.println(u'ATOM_WB m_%(name)s;' % slotDict)

CTYPE_TO_SLOT_DECL = {
    ctype_from_enum(CTYPE_OBJECT, True) : outputWBRCSlotDecl,
    ctype_from_enum(CTYPE_ATOM, False) : outputWBAtomSlotDecl,
    ctype_from_enum(CTYPE_VOID, True) : lambda output, slotDict: None,
    ctype_from_enum(CTYPE_BOOLEAN, True) : outputBasicSlotDecl,
    ctype_from_enum(CTYPE_INT, True) : outputBasicSlotDecl,
    ctype_from_enum(CTYPE_UINT, True) : outputBasicSlotDecl,
    ctype_from_enum(CTYPE_DOUBLE, True) : outputBasicSlotDecl,
    ctype_from_enum(CTYPE_STRING, True) : outputWBRCSlotDecl,
    ctype_from_enum(CTYPE_NAMESPACE, True) : outputWBRCSlotDecl
}

def outputBasicGetMethodDecl(output, slotDict):
    output.println(u'REALLY_INLINE %(type)s get_%(name)s() const { return m_%(name)s; }' % slotDict)

CTYPE_TO_GET_METHOD_DECL = {
    ctype_from_enum(CTYPE_OBJECT, True) : outputBasicGetMethodDecl,
    ctype_from_enum(CTYPE_ATOM, False) : outputBasicGetMethodDecl,
    ctype_from_enum(CTYPE_VOID, True) : lambda output, slotDict: None,
    ctype_from_enum(CTYPE_BOOLEAN, True) : outputBasicGetMethodDecl,
    ctype_from_enum(CTYPE_INT, True) : outputBasicGetMethodDecl,
    ctype_from_enum(CTYPE_UINT, True) : outputBasicGetMethodDecl,
    ctype_from_enum(CTYPE_DOUBLE, True) : outputBasicGetMethodDecl,
    ctype_from_enum(CTYPE_STRING, True) : outputBasicGetMethodDecl,
    ctype_from_enum(CTYPE_NAMESPACE, True) : outputBasicGetMethodDecl
}

def outputBasicSetMethodDecl(output, slotDict):
    output.println(u'REALLY_INLINE void set_%(name)s(%(type)s newVal) { m_%(name)s = newVal; }' % slotDict)

CTYPE_TO_SET_METHOD_DECL = {
    ctype_from_enum(CTYPE_OBJECT, True) : outputBasicSetMethodDecl,
    ctype_from_enum(CTYPE_ATOM, False) : outputBasicSetMethodDecl,
    ctype_from_enum(CTYPE_VOID, True) : lambda output, slotDict: None,
    ctype_from_enum(CTYPE_BOOLEAN, True) : outputBasicSetMethodDecl,
    ctype_from_enum(CTYPE_INT, True) : outputBasicSetMethodDecl,
    ctype_from_enum(CTYPE_UINT, True) : outputBasicSetMethodDecl,
    ctype_from_enum(CTYPE_DOUBLE, True) : outputBasicSetMethodDecl,
    ctype_from_enum(CTYPE_STRING, True) : outputBasicSetMethodDecl,
    ctype_from_enum(CTYPE_NAMESPACE, True) : outputBasicSetMethodDecl
}

def outputBasicSetMethodMacroThunk(output, slotDict):
    output.println(u'REALLY_INLINE void set_%(name)s(%(type)s newVal) { %(instance)s.set_%(name)s(newVal); } \\' % slotDict)

CTYPE_TO_SET_METHOD_MACRO_THUNK = {
    ctype_from_enum(CTYPE_OBJECT, True) : outputBasicSetMethodMacroThunk,
    ctype_from_enum(CTYPE_ATOM, False) : outputBasicSetMethodMacroThunk,
    ctype_from_enum(CTYPE_VOID, True) : lambda output, slotDict: None,
    ctype_from_enum(CTYPE_BOOLEAN, True) : outputBasicSetMethodMacroThunk,
    ctype_from_enum(CTYPE_INT, True) : outputBasicSetMethodMacroThunk,
    ctype_from_enum(CTYPE_UINT, True) : outputBasicSetMethodMacroThunk,
    ctype_from_enum(CTYPE_DOUBLE, True) : outputBasicSetMethodMacroThunk,
    ctype_from_enum(CTYPE_STRING, True) : outputBasicSetMethodMacroThunk,
    ctype_from_enum(CTYPE_NAMESPACE, True) : outputBasicSetMethodMacroThunk
}

NON_POINTER_4_BYTE_SLOT_BUCKET = 0
POINTER_SLOT_BUCKET = 1
NON_POINTER_8_BYTE_SLOT_BUCKET = 2

CTYPE_TO_SLOT_SORT_BUCKET = {
    # following types are 4 bytes
    ctype_from_enum(CTYPE_INT, True) : NON_POINTER_4_BYTE_SLOT_BUCKET,
    ctype_from_enum(CTYPE_UINT, True) : NON_POINTER_4_BYTE_SLOT_BUCKET,
    ctype_from_enum(CTYPE_BOOLEAN, True) : NON_POINTER_4_BYTE_SLOT_BUCKET,
    # following types are pointer size ( either 4 or 8 bytes )
    ctype_from_enum(CTYPE_OBJECT, True) : POINTER_SLOT_BUCKET,
    ctype_from_enum(CTYPE_ATOM, False) : POINTER_SLOT_BUCKET,
    ctype_from_enum(CTYPE_STRING, True) : POINTER_SLOT_BUCKET,
    ctype_from_enum(CTYPE_NAMESPACE, True) : POINTER_SLOT_BUCKET,
    # doubles are 8 bytes
    ctype_from_enum(CTYPE_DOUBLE, True) : NON_POINTER_8_BYTE_SLOT_BUCKET,
    # slots should never be of type void
    ctype_from_enum(CTYPE_VOID, True) : -1
}

CTYPE_TO_NEED_FORWARD_DECL = {
    ctype_from_enum(CTYPE_INT, True) : False,
    ctype_from_enum(CTYPE_UINT, True) : False,
    ctype_from_enum(CTYPE_BOOLEAN, True) : False,
    ctype_from_enum(CTYPE_OBJECT, True) : True,
    ctype_from_enum(CTYPE_ATOM, False) : False,
    ctype_from_enum(CTYPE_STRING, True) : True,
    ctype_from_enum(CTYPE_NAMESPACE, True) : True,
    ctype_from_enum(CTYPE_DOUBLE, True) : False,
    ctype_from_enum(CTYPE_VOID, True) : False
}

GLUECLASSES_WITHOUT_SLOTS = frozenset((
    'bool',
    'double',
    'int32_t',
    'Namespace',
    'String',
    'uint32_t'))


class AbcThunkGen:
    abc = None
    abcs = []
    out_h = None
    out_c = None
    all_thunks = []
    lookup_traits = None

    def addAbc(self, a):
        self.abcs.append(a)
        self.lookup_traits = None

    def class_native_name(self, c):
        return ns_prefix(c.qname.ns, True) + to_cname(c.qname.name)

    def class_id_name(self, c):
        return "abcclass_" + self.class_native_name(c)

    @staticmethod
    def __parseCPPNamespaceStr(nsStr):
        return nsStr.split(u'::')

    def emitAOT(self, name, ctypeObject):
        self.out_c.println(u'#ifdef VMCFG_AOT')
        
        traits = filter(lambda t: (t.niname is not None) and (t.niname != "double") and ((t.ctype == ctypeObject) or (t.niname == BASE_INSTANCE_NAME) or (t.niname == BASE_CLASS_NAME)), self.abc.classes + self.abc.instances)
        glueClasses = sorted(set(map(lambda t: t.niname, traits)))
        
        self.out_c.println(u'extern "C" const struct {')
        self.out_c.indent += 1
        
        i = 0
        for i in range(0, len(glueClasses)):
            self.out_c.println(u'const char* const n_%(count)u; %(glueClass)s* const m_%(count)u;' % { 'count' : i, 'glueClass': glueClasses[i]})
        
        self.out_c.indent -= 1
        self.out_c.println(u'} aotABCTypes_%s = {' % name)
        self.out_c.indent += 1
        
        i = 0
        for i in range(0, len(glueClasses)):
            self.out_c.println(u'"%(glueClass)s", 0,' % { 'count' : i, 'glueClass': glueClasses[i]})
        
        self.out_c.indent -= 1
        self.out_c.println(u'};')
        
        self.out_c.println(u'#endif')

    def emit(self, abc, name, out_h, out_c):
        self.abc = abc;
        self.out_h = out_h;
        self.out_c = out_c;
        self.all_thunks = []
        self.lookup_traits = None

        for i in range(0, len(abc.scripts)):
            script = abc.scripts[i]
            if script != None:
                self.processTraits(script)

        out_h.println(MPL_HEADER);
        out_c.println(MPL_HEADER);

        out_h.println('')
        out_h.println("/* machine generated file -- do not edit */");
        out_h.println('')
        out_c.println('')
        out_c.println("/* machine generated file -- do not edit */");
        out_c.println('')

        out_h.println("#define AVMTHUNK_VERSION 5");
        out_h.println('')

        self.forwardDeclareGlueClasses(out_h)

        nativeIDNamespaces = self.__parseCPPNamespaceStr(opts.nativeIDNS)
        #turn list of namespaces [foo, bar, baz] into "namespace foo { namespace bar { namespace baz{"
        out_h.println(' '.join(map(lambda ns: u'namespace %s {' % ns, nativeIDNamespaces)))
        out_h.println('')
        out_c.println(' '.join(map(lambda ns: u'namespace %s {' % ns, nativeIDNamespaces)))
        out_c.println('')

        out_h.println('extern const uint32_t '+name+"_abc_class_count;")
        out_h.println('extern const uint32_t '+name+"_abc_script_count;")
        out_h.println('extern const uint32_t '+name+"_abc_method_count;")
        out_h.println('extern const uint32_t '+name+"_abc_length;")
        out_h.println('extern const uint8_t '+name+"_abc_data[];");
        out_h.println('extern const char* const '+name+"_versioned_uris[];");

        out_c.println("const uint32_t "+name+"_abc_class_count = "+str(len(abc.classes))+";");
        out_c.println("const uint32_t "+name+"_abc_script_count = "+str(len(abc.scripts))+";");
        out_c.println("const uint32_t "+name+"_abc_method_count = "+str(len(abc.methods))+";");
        out_c.println("const uint32_t "+name+"_abc_length = "+str(len(abc.data.data))+";");

        out_h.println("AVMTHUNK_DECLARE_NATIVE_INITIALIZER(%s)" % (name));

        out_h.println('')
        out_h.println("/* classes */");
        for i in range(0, len(abc.classes)):
            c = abc.classes[i]
            self.out_h.println("const uint32_t " + self.class_id_name(c) + " = " + str(c.class_id) + ";");

        out_h.println('')
        out_h.println("/* methods */");
        for i in range(0, len(abc.methods)):
            m = abc.methods[i]
            if m.native_id_name != None:
                assert(m.id == i)
                if m.isNative():
                    out_h.println("const uint32_t "+m.native_id_name+" = "+str(m.id)+";");
                else:
                    # not sure if we want to expose method id's for non-native methods; emit as comments for now
                    out_h.println("/* const uint32_t "+m.native_id_name+" = "+str(m.id)+"; */");
        out_h.println('')

        out_c.println("");
        out_c.println("/* thunks (%d total) */" % len(self.all_thunks));
        if opts.thunkvprof:
            out_c.println("#define DOPROF")
            out_c.println('#include "../vprof/vprof.h"')

        for receiver,m in self.all_thunks:
            thunkname = m.native_id_name;
            self.emitThunkProto(thunkname, receiver, m);
            self.emitThunkBody(thunkname, receiver, m);

        out_c.println("")
        self.printStructAsserts(out_c, abc)
        out_c.println("")

        for i in range(0, len(abc.classes)):
            c = abc.classes[i]
            if c.ni.gen_method_map:
                basename = self.__baseNINameForNIName(c.ni.class_name)
                if c.ni.class_gc_exact:
                    out_c.println("AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(%s, %s, %s, SlotOffsetsAndAsserts::do%sAsserts)" % (basename, c.ni.class_name, c.ni.createInstanceProcName, basename))
                else:
                    out_c.println("AVMTHUNK_NATIVE_CLASS_GLUE(%s, %s, %s, SlotOffsetsAndAsserts::do%sAsserts)" % (basename, c.ni.class_name, c.ni.createInstanceProcName, basename))

        out_c.println("");
        out_c.println("AVMTHUNK_BEGIN_NATIVE_TABLES(%s)" % self.abc.scriptName)
        out_c.indent += 1

        out_c.println("");
        out_c.println("AVMTHUNK_BEGIN_NATIVE_METHODS(%s)" % self.abc.scriptName)
        out_c.indent += 1
        for i in range(0, len(abc.methods)):
            m = abc.methods[i]
            if m.isNative() and (m.receiver == None or m.receiver.ni.gen_method_map):
                assert(m.native_method_name != None)
                assert(m.native_id_name != None)
                if m.receiver == None:
                    self.out_c.println("AVMTHUNK_NATIVE_FUNCTION(%s, %s)" % (m.native_id_name, m.native_method_name))
                else:
                    # special-case the two oddballs of the group: String and Namespace
                    # don't descend from ScriptObject and so need a little extra love.
                    if str(m.receiver.name) == "String":
                        nmout = "AVMTHUNK_NATIVE_METHOD_STRING"
                    elif str(m.receiver.name) == "Namespace":
                        nmout = "AVMTHUNK_NATIVE_METHOD_NAMESPACE"
                    else:
                        nmout = "AVMTHUNK_NATIVE_METHOD"
                    method_map_name = m.receiver.niname
                    if m.receiver.ni.method_map_name != None and m.receiver.itraits == None:
                        method_map_name = m.receiver.ni.method_map_name
                    self.out_c.println("%s(%s, %s::%s)" % (nmout, m.native_id_name, method_map_name, m.native_method_name))
        out_c.indent -= 1
        out_c.println("AVMTHUNK_END_NATIVE_METHODS()")

        out_c.println("");
        out_c.println("AVMTHUNK_BEGIN_NATIVE_CLASSES(%s)" % self.abc.scriptName)
        out_c.indent += 1
        for i in range(0, len(abc.classes)):
            c = abc.classes[i]
            if c.ni.class_name != None or c.ni.instance_name != None:
                if c.ni.gen_method_map:
                    offsetOfSlotsClass = "SlotOffsetsAndAsserts::s_slotsOffset%s" % self.__baseNINameForNIName(c.ni.class_name)
                    offsetOfSlotsInstance = "SlotOffsetsAndAsserts::s_slotsOffset%s" % self.__baseNINameForNIName(c.ni.instance_name)
                    out_c.println("AVMTHUNK_NATIVE_CLASS(%s, %s, %s, %s, %s, %s, %s, %s, %s)" %\
                        (self.class_id_name(c),\
                        self.__baseNINameForNIName(c.ni.class_name),\
                        c.ni.class_name,\
                        offsetOfSlotsClass,\
                        c.ni.instance_name,\
                        offsetOfSlotsInstance,\
                        str(c.has_construct_method_override).lower(),
                        str(c.is_restricted_inheritance).lower(),
                        str(c.is_abstract_base).lower()))
                else:
                    out_c.println("NATIVE_CLASS(%s, %s, %s)" % (self.class_id_name(c), c.ni.class_name, c.ni.instance_name))
        out_c.indent -= 1
        out_c.println("AVMTHUNK_END_NATIVE_CLASSES()")

        out_c.println("");
        out_c.indent -= 1
        out_c.println("AVMTHUNK_END_NATIVE_TABLES()")

        out_c.println("");
        out_c.println("AVMTHUNK_DEFINE_NATIVE_INITIALIZER(%s)" % (name));

        if opts.externmethodandclassetables:
            out_c.println("");
            out_c.println('extern const NativeClassInfo* '+name+"_classEntriesExtern = "+name+"_classEntries;");
            out_c.println('extern const NativeMethodInfo* '+name+"_methodEntriesExtern = "+name+"_methodEntries;");

        out_c.println("");
        out_c.println("/* abc */");
        n = len(abc.data.data)
        out_c.println("const uint8_t "+name+"_abc_data["+str(n)+"] = {");
        for i in range(0, n):
            x = ord(abc.data.data[i]) & 255;
            out_c.prnt("%4d" % x)
            if i+1 < n:
                out_c.prnt(",")
            if i%16 == 15:
                out_c.println("");
        out_c.println("};");
        out_c.println('')

        out_c.println("");
        out_c.println("/* versioned_uris */");
        out_c.println("const char* const "+name+"_versioned_uris[] = {");
        out_c.indent += 1
        # don't really need to sort 'em, but helps keep output stable
        sorted_keys = sorted(abc.versioned_uris.keys())
        for i in sorted_keys:
            # The empty URI (aka "public") is always versioned 
            # (and special-cased by the versioning code in AvmCore)
            # so don't bother emitting it.
            if len(i) > 0:
                out_c.println('"%s", // %s' % (i, str(sorted(abc.versioned_uris[i]))))
        out_c.println('NULL')
        out_c.indent -= 1
        out_c.println("};");
        out_c.println('')

        c_stubs = StringIO.StringIO("")
        out_c_stubs = IndentingPrintWriter(c_stubs)
        self.printStructInfoForClasses(out_h, out_c, out_c_stubs)

        self.emitAOT(name, CTYPE_OBJECT)

        out_h.println(' '.join(('}',) * len(nativeIDNamespaces)))
        out_c.println(' '.join(('}',) * len(nativeIDNamespaces)))

        # emit stubs after closing open namespaces!
        out_c.prnt(c_stubs.getvalue())
        c_stubs.close()

    def forwardDeclareGlueClasses(self, out_h):
        # find all the native glue classes and write forward declarations for them
        cppNamespaceToGlueClasses = {}
        traitsSet = set()
        for i in range(0, len(self.abc.classes)):
            c = self.abc.classes[i]
            if c.ni.class_name != None:
                traitsSet.add(c)
            if (c.ni.instance_name != None):
                traitsSet.add(c.itraits)

        for t in frozenset(traitsSet):
            filteredSlots = filter(lambda s: s is not None, t.slots)
            for s in filteredSlots:
                slotTraits = self.lookupTraits(s.type)
                traitsSet.add(slotTraits)

        glueClassToTraits = {}
        for t in sorted(traitsSet):
            if ((t.niname is not None) and (CTYPE_TO_NEED_FORWARD_DECL[ctype_from_traits(t, True)])):
                (classNS, glueClassName) = parseCPPClassName(t.niname)
                # special hack because the meta data for the class Math says its instance data is of type double
                if (CTYPE_TO_NEED_FORWARD_DECL.get(glueClassName, True)):
                    cppNamespaceToGlueClasses.setdefault(classNS, set()).add(glueClassName)
                    key = classNS + u'::' + glueClassName
                    if not key in glueClassToTraits:
                        glueClassToTraits[key] = []
                    glueClassToTraits[key].append(t)
        for (nsStr, glueClasses) in sorted(cppNamespaceToGlueClasses.iteritems()):
            # turn list of namespaces [foo, bar, baz] into "namespace foo { namespace bar { namespace baz{"
            nsList = self.__parseCPPNamespaceStr(nsStr)
            out_h.println(' '.join(map(lambda ns: u'namespace %s {' % ns, nsList)))
            out_h.indent += 1
            
            # this can emit the same class multiple times; that's by design,
            # for clarity & stability of output
            for glueClass in sorted(glueClasses):
                traitsList = glueClassToTraits[nsStr + u'::' + glueClass]
                for traits in sorted(traitsList):
                    out_h.println('class %s; // %s' % (glueClass, traits))
            out_h.indent -= 1
            out_h.println(' '.join(('}',) * len(nsList)))
            out_h.println('')

    @staticmethod
    def cmpSlots(slotA, slotB, slotsTypeInfo):
        if (slotA is slotB):
            return 0;

        # slotA or slotB could be None, which means they are an anonymous slot.
        # Anonymous slots should be at the end of the pointer slots.
        slotBBucket = CTYPE_TO_SLOT_SORT_BUCKET[slotsTypeInfo[id(slotB)][0]] if (slotB is not None) else POINTER_SLOT_BUCKET
        if (slotA is None):
            if (slotBBucket <= POINTER_SLOT_BUCKET):
                return 1
            else:
                return -1

        assert slotA is not None
        slotABucket = CTYPE_TO_SLOT_SORT_BUCKET[slotsTypeInfo[id(slotA)][0]]
        if (slotB is None):
            if (slotBBucket <= POINTER_SLOT_BUCKET):
                return -1
            else:
                return 1

        assert slotB is not None
        slotBucketCmp = cmp(slotABucket, slotBBucket)
        if (slotBucketCmp != 0):
            return slotBucketCmp
        return cmp(slotA.fileOffset, slotB.fileOffset)

    @staticmethod
    def slotsStructNameForTraits(t, isClassTraits):
        return to_cname(t.niname) + u'Slots'

    @staticmethod
    def __baseNINameForNIName(niname):
        return parseCPPClassName(niname)[1]

    @staticmethod
    def slotsInstanceNameForTraits(t, isClassTraits):
        return u'm_slots_' + AbcThunkGen.__baseNINameForNIName(t.niname)

    @staticmethod
    def needsInstanceSlotsStruct(c):
        return (c.ni.instance_name is not None) and (c.ni.instance_name != BASE_INSTANCE_NAME)

    @staticmethod
    def hashSlots(c):
        return False

    def printStructInfoForClasses(self, out_h, out_c, out_c_stubs):
        out_h.println(u'class SlotOffsetsAndAsserts;')

        visitedGlueClasses = set()

        for i in range(0, len(self.abc.classes)):
            c = self.abc.classes[i]
            if (c.ni.class_name is not None):
                self.printStructInfoForTraits(out_h, out_c, out_c_stubs, c, visitedGlueClasses, True)
                if (self.needsInstanceSlotsStruct(c)):
                    self.printStructInfoForTraits(out_h, out_c, out_c_stubs, c.itraits, visitedGlueClasses, False)
            else:
                assert not self.needsInstanceSlotsStruct(c)

    def printStructInfoForTraits(self, out_h, out_c, out_c_stubs, t, visitedGlueClasses, isClassTraits):
        if (t.base is not None):
            baseTraits = self.lookupTraits(t.base)
            if (((isClassTraits) and (baseTraits.ni.class_name is None)) or ((not isClassTraits) and (baseTraits.ni.instance_name is None))):
                glueClassName = t.ni.class_name if isClassTraits else t.ni.instance_name
                raise Error(u'Native class %s(%s) extends %s which is not a native class' % (unicode(t.name), glueClassName, unicode(t.base)))

        if (t.niname in visitedGlueClasses):
            if (len(t.slots) > 0):
                raise Error(u'C++ glue classes for AS3 classes that have slots may only be referenced by meta data for one AS3 class: %s(%s)' % (unicode(t.name), t.niname))
            else:
                return

        visitedGlueClasses.add(t.niname)
        if (t.niname in GLUECLASSES_WITHOUT_SLOTS):
            return

        memberVars = []
        structName = self.slotsStructNameForTraits(t, isClassTraits)
        slotsInstanceName = self.slotsInstanceNameForTraits(t, isClassTraits)
        out_h.println(u'// %s' % str(t.name))
        out_h.println(u'//-----------------------------------------------------------')
        out_h.println(u'class %(struct)s' % {u'struct' : structName})
        out_h.println(u'{')
        out_h.indent += 1
        out_h.println(u'friend class SlotOffsetsAndAsserts;')
        out_h.indent -= 1
        out_h.println(u'public:')
        out_h.indent += 1

        filteredSlots = filter(lambda s: s is not None, t.slots)

        slotsTypeInfo = {}
        for slot in filteredSlots:
            slotTraits = self.lookupTraits(slot.type)
            slotCType = ctype_from_traits(slotTraits, True)
            slotNIType = (slotTraits.niname + u'*') if ((slotTraits.niname is not None) and (slotCType == ctype_from_enum(CTYPE_OBJECT, True))) else slotCType
            slotsTypeInfo[id(slot)] = (slotCType, slotNIType)

        sortedSlots = sorted(t.slots, lambda x,y: self.cmpSlots(x, y, slotsTypeInfo))

        for slot in sortedSlots:
            if (slot is not None):
                assert slot.kind in (TRAIT_Slot, TRAIT_Const)
                (slotCType, slotNIType) = slotsTypeInfo[id(slot)]
                slotDict = { u'struct' : structName, u'native' : t.niname, u'instance' : slotsInstanceName, u'type' : slotNIType, u'name' : to_cname(slot.name) }
                CTYPE_TO_GET_METHOD_DECL[slotCType](out_h, slotDict)
                if ((slot.kind == TRAIT_Slot) or (t.ni.constSetters)):
                    CTYPE_TO_SET_METHOD_DECL[slotCType](out_h, slotDict)
        out_h.indent -= 1
        out_h.println(u'private:')
        out_h.indent += 1

        anonCount = 0
        for slot in sortedSlots:
            if (slot is not None):
                assert slot.kind in (TRAIT_Slot, TRAIT_Const)
                (slotCType, slotNIType) = slotsTypeInfo[id(slot)]
                slotDict = { u'struct' : structName, u'native' : t.niname, u'instance' : slotsInstanceName, u'type' : slotNIType, u'name' : to_cname(slot.name) }
                CTYPE_TO_SLOT_DECL[slotCType](out_h, slotDict)
            else:
                out_h.println(u'Atom __anonymous_slot_%u;' % (anonCount,))
                anonCount = anonCount + 1
        baseTraits = self.lookupTraits(t.base)

        if (isClassTraits and t.ni.class_gc_exact) or (not isClassTraits and t.ni.instance_gc_exact):
            numTracedSlots = 0
            for slot in sortedSlots:
                if (slot is not None):
                    slotTraits = self.lookupTraits(slot.type)
                    if slotTraits.ctype == CTYPE_ATOM:
                        numTracedSlots += 1
                    elif (slotTraits.ctype == CTYPE_STRING) or (slotTraits.ctype == CTYPE_NAMESPACE) or (slotTraits.ctype == CTYPE_OBJECT):
                        numTracedSlots += 1
                else:
                    numTracedSlots += 1
            if numTracedSlots > 0:
                out_h.indent -= 1
                out_h.println(u'public:');
                out_h.indent += 1
                out_h.println(u'REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)')
                out_h.println(u'{')
                out_h.indent += 1
                anonCount = 0
                for slot in sortedSlots:
                    if (slot is not None):
                        slotTraits = self.lookupTraits(slot.type)
                        if slotTraits.ctype == CTYPE_ATOM:
                            out_h.println(u'gc->TraceAtom(&m_%s);' % to_cname(slot.name))
                        elif (slotTraits.ctype == CTYPE_STRING) or (slotTraits.ctype == CTYPE_NAMESPACE) or (slotTraits.ctype == CTYPE_OBJECT):
                            out_h.println(u'gc->TraceLocation(&m_%s);' % to_cname(slot.name))
                    else:
                        out_h.println(u'gc->TraceAtom(&__anonymous_slot_%u);' % (anonCount,))
                        anonCount = anonCount + 1
                out_h.indent -= 1
                out_h.println(u'}')
            else:
                out_h.indent -= 1
                out_h.println(u'#define GC_TRIVIAL_TRACER_' + self.__baseNINameForNIName(t.niname))
                out_h.indent += 1

        out_h.indent -= 1
        out_h.println(u'};')
        out_h.println(u'#define DECLARE_SLOTS_' + self.__baseNINameForNIName(t.niname) + u' \\')
        out_h.indent += 1
        selfname = fullyQualifiedCPPClassName(t.niname)
        basename = fullyQualifiedCPPClassName(baseTraits.niname)
        if not isClassTraits and t.ni.instancebase_name != None:
            basename = fullyQualifiedCPPClassName(t.ni.instancebase_name)
        if t.has_construct_method_override:
            # emit the construct declaration to ensure that construct is defined for this class
            out_h.println("public: \\")
            out_h.indent += 1
            out_h.println("virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \\")
            out_h.indent -= 1
        else:
            # emit a (debug-only) stub to ensure that construct is NOT defined for this class
            out_h.println("public: \\")
            out_h.indent += 1
            out_h.println("AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\\")
            out_h.indent -= 1
            # put in out_c_stubs so we aren't wrapped in avmplus::NativeID:: namespaces
            out_c_stubs.println("AvmThunk_DEBUG_ONLY( avmplus::Atom %s::construct(int argc, avmplus::Atom* argv) { return %s::construct(argc, argv); } )" % (selfname,basename))

        if isClassTraits and t.has_custom_createInstanceProc: 
            out_h.println("public: \\") 
            out_h.indent += 1
            if t.has_pre_create_check: 
                out_h.println("static void FASTCALL preCreateInstanceCheck(avmplus::ClassClosure*); \\");
            out_h.println("static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \\")
            out_h.indent -= 1
            out_c_stubs.println("/*static*/ avmplus::ScriptObject* FASTCALL %s::createInstanceProc(avmplus::ClassClosure* cls)" % (selfname));
            out_c_stubs.println("{");
            out_c_stubs.indent += 1
            instancename = fullyQualifiedCPPClassName(t.ni.instance_name)
            if t.has_pre_create_check: 
                out_c_stubs.println("%s::preCreateInstanceCheck(cls);" % (selfname));
            if t.ni.instance_gc_exact: 
                out_c_stubs.println("return %s::create(cls->gc(), cls->ivtable(), cls->prototypePtr());" % (instancename));
            else:
                out_c_stubs.println("return new(cls->gc(), cls->getExtraSize()) %s(cls->ivtable(), cls->prototypePtr());" % (instancename));
            out_c_stubs.indent -= 1
            out_c_stubs.println("}");
            
        # createInstance() is no longer supported; emit a (debug-only) stub to generate compile errors for any dangling usages
        out_h.println("private: \\")
        out_h.indent += 1
        out_h.println("AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )\\")
        out_h.indent -= 1

        out_h.println(u'private: \\')
        out_h.indent += 1
        out_h.println(u'friend class %s::SlotOffsetsAndAsserts; \\' % opts.nativeIDNS)
        out_h.indent -= 1
        if (len(t.slots) > 0):
            out_h.println(u'protected: \\')
            out_h.indent += 1
            for slot in sortedSlots:
                assert slot.kind in (TRAIT_Slot, TRAIT_Const)
                (slotCType, slotNIType) = slotsTypeInfo[id(slot)]
                slotDict = { u'struct' : structName, u'native' : t.niname, u'instance' : slotsInstanceName, u'type' : slotNIType, u'name' : to_cname(slot.name) }
                out_h.println(u'REALLY_INLINE %(type)s get_%(name)s() const { return %(instance)s.get_%(name)s(); } \\' % slotDict);
                if ((slot.kind == TRAIT_Slot) or (t.ni.constSetters)):
                    CTYPE_TO_SET_METHOD_MACRO_THUNK[slotCType](out_h, slotDict)
            out_h.indent -= 1
            out_h.println(u'private: \\')
            out_h.indent += 1
            out_h.println(u'%(nativeIDNS)s::%(struct)s %(instance)s' % { u'nativeIDNS' : opts.nativeIDNS, u'struct' : structName, u'instance' : slotsInstanceName} )
            out_h.indent -= 1
        else:
            out_h.indent += 1
            out_h.println(u'typedef %s::%s EmptySlotsStruct_%s' % (opts.nativeIDNS, structName, self.__baseNINameForNIName(t.niname)))
            out_h.indent -= 1
        out_h.indent -= 1
        out_h.println(u'//-----------------------------------------------------------')
        out_h.println(u'')

    def printStructAsserts(self, out_c, abc):
        namesDict = {}
        for i in range(1, len(abc.names)):
            if (not isinstance(abc.names[i], TypeName)):
                namesDict[id(abc.qname(abc.names[i]))] = i

        out_c.println(u'class SlotOffsetsAndAsserts')
        out_c.println(u'{')
        out_c.println(u'private:')
        out_c.indent += 1
        out_c.println(u'static uint32_t getSlotOffset(Traits* t, int nameId);')
        out_c.indent -= 1
        out_c.println(u'public:')
        out_c.indent += 1
        out_c.println(u'// This exists solely to silence a warning (generally GCC 4.4+):')
        out_c.println(u'// "all member functions in class SlotOffsetsAndAsserts are private"')
        out_c.println(u'static inline void do_nothing();')
        visitedNativeClasses = set()
        for i in range(0, len(abc.classes)):
            c = abc.classes[i]
            if (c.ni.gen_method_map):
                if (c.ni.class_name not in visitedNativeClasses):
                    visitedNativeClasses.add(c.ni.class_name)
                    if (len(c.slots) > 0):
                        out_c.println(u'static const uint16_t s_slotsOffset%(nativeClassBaseName)s = offsetof(%(nativeClass)s, %(slotsInstance)s);' %
                            { u'nativeClass' : c.ni.class_name
                            , u'nativeClassBaseName' : self.__baseNINameForNIName(c.ni.class_name)
                            , u'slotsInstance' : self.slotsInstanceNameForTraits(c, True) } )
                    else:
                        out_c.println(u'static const uint16_t s_slotsOffset%s = 0;' % self.__baseNINameForNIName(c.ni.class_name))
                if (c.ni.instance_name not in visitedNativeClasses):
                    visitedNativeClasses.add(c.ni.instance_name)
                    if (len(c.itraits.slots) > 0):
                        out_c.println(u'static const uint16_t s_slotsOffset%(nativeClassBaseName)s = offsetof(%(nativeClass)s, %(slotsInstance)s);' %
                            { u'nativeClass' : c.ni.instance_name
                            , u'nativeClassBaseName' : self.__baseNINameForNIName(c.ni.instance_name)
                            , u'slotsInstance' : self.slotsInstanceNameForTraits(c.itraits, False) } )
                    else:
                        out_c.println(u'static const uint16_t s_slotsOffset%s = 0;' % self.__baseNINameForNIName(c.ni.instance_name))
                out_c.println(u'#ifdef DEBUG')
                out_c.println(u'static void do%sAsserts(Traits* cTraits, Traits* iTraits);' % self.__baseNINameForNIName(c.ni.class_name))
                out_c.println(u'#endif');

        out_c.indent -= 1
        out_c.println(u'};')
        out_c.println(u'#ifdef DEBUG');
        for i in range(0, len(abc.classes)):
            c = abc.classes[i]
            if (c.ni.class_name is not None):
                out_c.println(u'REALLY_INLINE void SlotOffsetsAndAsserts::do%sAsserts(Traits* cTraits, Traits* iTraits)' % self.__baseNINameForNIName(c.ni.class_name))
                out_c.println(u'{')
                out_c.indent += 1
                out_c.println(u'(void)cTraits; (void)iTraits;')
                noSlotsStaticAssertStr = u'// MMGC_STATIC_ASSERT(sizeof(%(nativeClass)s::EmptySlotsStruct_%(nativeClassBaseName)s) >= 0);'
                assert (c.ni.class_name is not None)
                if (len(c.slots) > 0):
                    self.printStructAssertsForTraits(namesDict, out_c, c, True, u'cTraits')
                elif (c.ni.class_name not in GLUECLASSES_WITHOUT_SLOTS):
                    out_c.println(noSlotsStaticAssertStr % { u'nativeClass' : c.ni.class_name, u'nativeClassBaseName' : self.__baseNINameForNIName(c.ni.class_name) })
                if (self.needsInstanceSlotsStruct(c)):
                    if (len(c.itraits.slots) > 0):
                        self.printStructAssertsForTraits(namesDict, out_c, c.itraits, False, u'iTraits')
                    elif (c.ni.instance_name not in GLUECLASSES_WITHOUT_SLOTS):
                        out_c.println(noSlotsStaticAssertStr % { u'nativeClass' : c.ni.instance_name, u'nativeClassBaseName' : self.__baseNINameForNIName(c.ni.instance_name) })

                out_c.indent -= 1
                out_c.println(u'}')
        out_c.println(u'#endif // DEBUG')

    def printStructAssertsForTraits(self, namesDict, out_c, t, isClassTraits, traitsVarName):
        if (len(t.slots) == 0):
            return
        filteredSlots = filter(lambda s: s is not None, t.slots)
        structName = self.slotsStructNameForTraits(t, isClassTraits)
        slotsInstanceName = self.slotsInstanceNameForTraits(t, isClassTraits)
        formatDict = {
                u'nativeClass' : t.niname
            ,   u'nativeClassBaseName' : self.__baseNINameForNIName(t.niname)
            ,   u'slotsInstance' : slotsInstanceName
            ,   u'structName' : structName
        }
        out_c.println(u'MMGC_STATIC_ASSERT(offsetof(%(nativeClass)s, %(slotsInstance)s) == s_slotsOffset%(nativeClassBaseName)s);' % formatDict)
        out_c.println(u'MMGC_STATIC_ASSERT(offsetof(%(nativeClass)s, %(slotsInstance)s) <= 0xFFFF);' % formatDict)
        out_c.println(u'MMGC_STATIC_ASSERT(sizeof(%(nativeClass)s) <= 0xFFFF);' % formatDict)
        for slot in filteredSlots:
            formatDict = {
                    u'traits' : traitsVarName
                ,   u'nameId' : namesDict[id(slot.name)]
                ,   u'nativeClass' : t.niname
                ,   u'slotsInstance' : slotsInstanceName
                ,   u'structName' : structName
                ,   u'slotName' : to_cname(slot.name)
            }
            out_c.println(u'AvmAssert(getSlotOffset(%(traits)s, %(nameId)u) == (offsetof(%(nativeClass)s, %(slotsInstance)s) + offsetof(%(structName)s, m_%(slotName)s)));' % formatDict)


    def argTraits(self, receiver, m):
        argtraits = [ receiver ]
        for i in range(0, len(m.paramTypes)):
            argtraits.append(self.lookupTraits(m.paramTypes[i]))
        return argtraits

    def thunkDecl(self, name, m):
        ret_traits = self.lookupTraits(m.returnType)
        ret_ctype = ret_traits.ctype
        if m.kind == TRAIT_Setter:
            ret_ctype = CTYPE_VOID

        # for return types of thunks, everything but double maps to Atom
        if ret_ctype != CTYPE_DOUBLE:
            thunk_ret_typedef = TMAP[CTYPE_ATOM][1]
        else:
            thunk_ret_typedef = TMAP[ret_ctype][1]

        ret_typedef = TMAP[ret_ctype][1]
        if ret_ctype == CTYPE_OBJECT and ret_traits.niname != None:
            ret_typedef = ret_traits.niname + "*"

        decl = "%s %s_thunk(MethodEnv* env, uint32_t argc, Atom* argv)" % (thunk_ret_typedef, name)

        return decl,ret_ctype,ret_typedef

    def emitThunkProto(self, name, receiver, m):
        decl,ret_ctype,ret_typedef = self.thunkDecl(name, m)
        self.out_h.println('extern '+decl+";");

    def findNativeBase(self, t):
        if t.niname != None:
            return t.niname
        if t.base != None:
            return self.findNativeBase(self.lookupTraits(t.base))
        return None

    def emitThunkBody(self, name, receiver, m):
        decl,ret_ctype,ret_typedef = self.thunkDecl(name, m)

        unbox_receiver = self.calc_unbox_this(m)

        self.out_c.println(decl);
        self.out_c.println("{");
        self.out_c.indent += 1;

        if opts.thunkvprof:
            self.out_c.println('_nvprof("%s", 1);' % name)

        param_count = len(m.paramTypes);
        optional_count = m.optional_count;

        argtraits = self.argTraits(receiver, m)

        argszprev = "0"
        self.out_c.println("enum {");
        self.out_c.indent += 1;
        for i in range(0, len(argtraits)):
            cts = ctype_from_traits(argtraits[i], True);
            if i == 0:
                self.out_c.println("argoff0 = 0");
            else:
                self.out_c.println(", argoff%d = argoff%d + %s" % (i, i-1, argszprev));
            argszprev = "AvmThunkArgSize_%s" % (to_cname(cts));
        self.out_c.indent -= 1;
        self.out_c.println("};");

        if m.needRest():
            self.out_c.println("const uint32_t argoffV = argoff"+str(len(argtraits)-1)+" + "+argszprev+";");

        args = []

        arg0_ctype = argtraits[0].ctype
        arg0_typedef = TMAP[arg0_ctype][0]
        arg0_basetype = TMAP[arg0_ctype][2]
        assert(argtraits[0].ctype in [CTYPE_OBJECT,CTYPE_STRING,CTYPE_NAMESPACE])
        if unbox_receiver:
            val = "AvmThunkUnbox_AvmAtomReceiver("+arg0_typedef+", argv[argoff0])";
        else:
            val = "AvmThunkUnbox_AvmReceiver("+arg0_typedef+", argv[argoff0])";
        if argtraits[0].niname != None:
            val = "(%s*)%s" % (argtraits[0].niname, val)
        args.append((val, arg0_typedef))

        for i in range(1, len(argtraits)):
            arg_ctype = argtraits[i].ctype
            arg_typedef = TMAP[arg_ctype][0]
            val = "AvmThunkUnbox_%s(argv[argoff%d])" % (to_cname(arg_typedef), i)
            if arg_ctype == CTYPE_OBJECT:
                unboxname = self.findNativeBase(argtraits[i])
                if unboxname != None:
                    val = "(%s*)%s" % (unboxname, val)
            # argtraits includes receiver at 0, optionalValues does not
            if i > param_count - optional_count:
                dct,defval,defvalraw = self.abc.default_ctype_and_value(m.optionalValues[i-1]);
                dts = ctype_from_enum(dct, True)
                if dts != arg_typedef:
                    defval = "AvmThunkCoerce_%s_%s(%s)" % (to_cname(dts), to_cname(arg_typedef), defval)
                val = "(argc < "+str(i)+" ? "+defval+" : "+val+")";
                if arg_ctype == CTYPE_OBJECT:
                    coercename = self.findNativeBase(argtraits[i])
                    if coercename != None:
                        val = "(%s*)%s" % (coercename, val)
            args.append((val, arg_typedef))

        if m.needRest():
            args.append(("(argc <= "+str(param_count)+" ? NULL : argv + argoffV)", "Atom*"))
            args.append(("(argc <= "+str(param_count)+" ? 0 : argc - "+str(param_count)+")", "uint32_t"))

        if not m.hasOptional() and not m.needRest():
            self.out_c.println("(void)argc;");

        self.out_c.println("(void)env;") # avoid "unreferenced formal parameter" in non-debugger builds
        if m.receiver == None:
            recname = BASE_INSTANCE_NAME
        else:
            recname = m.receiver.niname
        self.out_c.println("%s* const obj = %s;" % (recname, args[0][0]))

        if ret_ctype != CTYPE_VOID:
            self.out_c.prnt("%s const ret = " % (ret_typedef))

        if m.receiver == None:
            self.out_c.prnt("%s(obj" % m.native_method_name)
            need_comma = True
        else:
            native_method_name = m.native_method_name
            if m.receiver.ni.method_map_name != None and m.receiver.itraits == None:
                native_method_name = m.receiver.ni.method_map_name + "::" + m.native_method_name
            self.out_c.prnt("obj->%s(" % native_method_name)
            need_comma = False

        if len(args) > 1:
            self.out_c.println("")
            self.out_c.indent += 1
            for i in range(1, len(args)):
                if need_comma:
                    self.out_c.prnt(", ")
                self.out_c.println("%s" % args[i][0]);
                need_comma = True
            self.out_c.indent -= 1
        self.out_c.println(");")

        if ret_ctype == CTYPE_DOUBLE:
            self.out_c.println("return ret;")
        elif ret_ctype != CTYPE_VOID:
            self.out_c.println("return (Atom) ret;")
        else:
            self.out_c.println("return undefinedAtom;")
        self.out_c.indent -= 1
        self.out_c.println("}")

    # inefficient, but doesn't really matter
    def find_override_base(self, mi):
        if mi.override and mi.receiver.base != None:
            bt = self.lookupTraits(mi.receiver.base)
            for j in range(0, len(bt.tmethods)):
                bmi = bt.tmethods[j]
                if bmi.name.name == mi.name.name and bmi.name.ns == mi.name.ns and bmi != mi:
                    #print "OVER", str(mi.name), str(mi.receiver)
                    #print "BASE", str(bmi.name), str(bmi.receiver)
                    return bt,bmi
        return None,None

    def calc_unbox_this(self, mi):
        if mi.unbox_this < 0:
            bt,bmi = self.find_override_base(mi)
            if bmi == None:
                mi.unbox_this = 0 # no need to unbox
            elif bmi.unbox_this > 0:
                mi.unbox_this = 1 # unbox_this is sticky, down the inheritance tree
            elif len(bmi.paramTypes) > 0:
                param0 = self.lookupTraits(bmi.paramTypes[0])
                if mi.receiver.ctype in [CTYPE_OBJECT,CTYPE_STRING,CTYPE_NAMESPACE] and param0.ctype == CTYPE_ATOM:
                    mi.unbox_this = 1 # unbox_this is sticky, down the inheritance tree
        return mi.unbox_this > 0

    def lookupTraits(self, name):
        name = str(name)
        if self.lookup_traits == None:
            self.lookup_traits = {}
            self.lookup_traits["*"] = NULL
            self.lookup_traits["void"] = UNDEFINED
            for a in self.abcs:
                for t in a.scripts:
                    if self.lookup_traits.has_key(str(t)):
                        raise Error("duplicate name found: " + str(t))
                    self.lookup_traits[str(t)] = t
                for t in a.classes:
                    if self.lookup_traits.has_key(str(t)):
                        raise Error("duplicate name found: " + str(t))
                    self.lookup_traits[str(t)] = t
                for t in a.instances:
                    if self.lookup_traits.has_key(str(t)):
                        raise Error("duplicate name found: " + str(t))
                    self.lookup_traits[str(t)] = t
        if not self.lookup_traits.has_key(name):
            raise Error("name not found: " + name)
        return self.lookup_traits[name]

    def gatherThunk(self, receiver, m):
        if m.native_id_name == None:
            raise Error("name not specified for native method " + str(m.name))
        self.all_thunks.append((receiver, m))

    def processClass(self, b):
        c = b.value
        self.processTraits(c)
        self.processTraits(c.itraits)

    def processMethod(self, receiver, m):
        if m.isNative():
            self.gatherThunk(receiver, m)

    def processTraits(self, s):
        if s.init != None:
            if s.init.isNative():
                raise Error("native constructors are not allowed: " + str(s))
            self.processMethod(s, s.init)
        for i in range(0, len(s.members)):
            if s.members[i].kind in [TRAIT_Method,TRAIT_Getter,TRAIT_Setter]:
                self.processMethod(s, s.members[i])
            elif s.members[i].kind in [TRAIT_Class]:
                self.processClass(s.members[i]);

ngen = AbcThunkGen();
abcGenFor = None
abcGenName = ""
for file in args:
    try:
        f = open(file,"rb")
        data = f.read()
    finally:
        f.close()

    abcScriptName = os.path.splitext(os.path.split(file)[1])[0]
    #print "read %s" % abcScriptName
    abcGenFor = Abc(data, abcScriptName)
    ngen.addAbc(abcGenFor)
    abcGenName = os.path.splitext(file)[0]

if abcGenFor:
    hf = None
    hc = None
    try:
        hf = open(abcGenName+".h","w")
        hc = open(abcGenName+".cpp","w")
        h = IndentingPrintWriter(hf)
        c = IndentingPrintWriter(hc)
        ngen.emit(abcGenFor, abcScriptName, h, c);
    except Exception, e:
        sys.stderr.write("ERROR: "+str(e)+"\n")
        exit(1)
    finally:
        if hf != None:
            hf.close()
        if hc != None:
            hc.close()
