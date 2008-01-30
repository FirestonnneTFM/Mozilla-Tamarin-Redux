/* -*- mode: java; tab-width: 4; insert-tabs-mode: nil; indent-tabs-mode: nil -*- */
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

namespace Abc;
//package abcfile
{
    use default namespace Abc;
    use namespace Asm;
    use namespace Util;
    //import util.*;
    //import assembler.*;
    //import bytestream.*;

    /* ABCFile container & helper class.
     *
     * Every argument to an addWhatever() method is retained by
     * reference.  When getBytes() is finally called, each object is
     * serialized.  The order of serialization is the order they will
     * have in the ABCFile, and the order among items of the same type
     * is the order in which they were added.
     *
     * Performance ought to be good; nothing is serialized more than
     * once and no data are copied except during serialization.
     */

    public class ABCFile
    {
        public const major_version = 46;
        public const minor_version = 16;

        const methods = [];
        const metadatas = [];
        const instances = [];
        const classes = [];
        const scripts = [];
        const bodies = [];
        var constants : ABCConstantPool;

        public function getBytes(): * /* same type as ABCByteStream.getBytes() */ {
            function emitArray(a, len) {
                if (len)
                    bytes.uint30(a.length);
                for ( var i=0 ; i < a.length ; i++ )
                    a[i].serialize(bytes);
            }

            var bytes = new ABCByteStream;

            Util::assert(constants);
            Util::assert(scripts.length != 0);
            Util::assert(methods.length != 0);
            Util::assert(bodies.length != 0);
            Util::assert(classes.length == instances.length);

            // print ("emitting version");
            bytes.uint16(minor_version);
            bytes.uint16(major_version);
            // print ("emitting constants");
            constants.serialize(bytes);
            // print ("emitting methods");
            emitArray(methods,true);
            // print ("emitting metadatas");
            emitArray(metadatas,true);
            // print ("emitting instances");
            emitArray(instances,true);
            // print ("emitting classes");
            emitArray(classes, false);
            // print ("emitting scripts");
            emitArray(scripts,true);
            // print ("emitting bodies");
            emitArray(bodies,true);
            return bytes.getBytes();
        }

        public function addConstants(cpool: ABCConstantPool): void {
            constants = cpool;
        }

        public function addMethod(m: ABCMethodInfo)/*: uint*/ {
            return methods.push(m)-1;
        }

        public function addMetadata(m: ABCMetadataInfo)/*: uint*/ {
            return metadatas.push(m)-1;
        }

        public function addClassAndInstance(cls, inst)/*: uint*/ {
            var x = addClass(cls);
            var y = addInstance(inst);
            Util::assert( x == y );
            return x;
        }

        public function addInstance(i: ABCInstanceInfo)/*: uint*/ {
            return instances.push(i)-1;
        }

        public function addClass(c: ABCClassInfo)/*: uint*/ {
            return classes.push(c)-1;
        }

        public function addScript(s: ABCScriptInfo)/*: uint*/ {
            return scripts.push(s)-1;
        }

        public function addMethodBody(b: ABCMethodBodyInfo)/*: uint*/ {
            return bodies.push(b)-1;
        }
        
    }

    public class ABCConstantPool
    {
        function ABCConstantPool() {
            function hash_number(n) { 
                return n ^ 0;                       // Fairly arbitrary
            }

            function eq_numbers(n1, n2) {
                return n1 == n2;
            }

            function hash_string(s) {
                // See http://www.cse.yorku.ca/~oz/hash.html; this is the djb2 algorithm
                var h = 5381;
                for ( var i=0, limit=s.length ; i < limit ; i++ )
                    h = ((h << 5) +h) + s.charCodeAt(i);
                return h;
            }

            function eq_strings(s1, s2) { 
                return s1 == s2; 
            }

            function hash_namespace(ns) {
                return ns.kind ^ ns.name;          // Fairly arbitrary
            }

            function eq_namespaces(ns1, ns2) {
                return ns1.kind == ns2.kind && ns1.name == ns2.name;
            }

            function hash_multiname(m) {
                return m.kind ^ m.name ^ m.ns;     // Fairly arbitrary
            }

            function eq_multinames(m1, m2) {
                return m1.kind == m2.kind && m1.ns == m2.ns && m1.name == m2.name;
            }

            function hash_namespaceset(nss) {
                var hash = nss.length;
                for ( var i=0, limit=nss.length ; i < limit ; i++ )
                    hash = ((hash << 5) + hash) + nss[i];
                return hash;
            }

            function eq_namespacesets(nss1, nss2) {
                if (nss1.length != nss2.length)
                    return false;
                for ( var i=0, limit=nss1.length ; i < limit ; i++ )
                    if (nss1[i] != nss2[i])
                        return false;
                return true;
            }

            // All pools and counts start at 1.  Counts are
            // initialized in the property definitions.

            multiname_pool.length = 1;

            int_map = new Hashtable(hash_number, eq_numbers, 0);
            uint_map = new Hashtable(hash_number, eq_numbers, 0);
            double_map = new Hashtable(hash_number, eq_numbers, 0);
            utf8_map = new Hashtable(hash_string, eq_strings, 0);
            namespace_map = new Hashtable(hash_namespace, eq_namespaces, 0);
            namespaceset_map = new Hashtable(hash_namespaceset, eq_namespacesets, 0);
            multiname_map = new Hashtable(hash_multiname, eq_multinames, 0);
        }

        public function int32(n:int):uint {
            var probe = int_map.read(n);
            if (probe == 0) {
                probe = int_count++;
                int_bytes.int32(n);
            }
            return probe;
        }

        public function uint32(n:uint):uint {
            var probe = uint_map.read(n);
            if (probe == 0) {
                probe = uint_count++;
                uint_bytes.uint32(n);
            }
            return probe;
        }

        public function float64(n: Number):uint {
            var probe = double_map.read(n);
            if (probe == 0) {
                probe = double_count++;
                double_bytes.float64(n);
            }
            return probe;
        }

        public function stringUtf8(s/*FIXME ES4: string*/)/*:uint*/ {
            if (!(s is String))
                s = s+"";
            var probe = utf8_map.read(s);
            if (probe == 0) {
                probe = utf8_count++;
                utf8_map.write(s, probe);
                utf8_bytes.uint30(s.length);
                utf8_bytes.utf8(s);
            }
            return probe;
        }

        var tmp_namespace = {"kind": 0, "name": 0 };  // avoids allocation when we don't need it

        public function namespace(kind/*:uint*/, name/*:uint*/) {
            tmp_namespace.kind = kind;
            tmp_namespace.name = name;
            var probe = namespace_map.read(tmp_namespace);
            if (probe == 0) {
                probe = namespace_count++;
                namespace_map.write({"kind": tmp_namespace.kind, "name": tmp_namespace.name}, probe);
                namespace_bytes.uint8(tmp_namespace.kind);
                namespace_bytes.uint30(tmp_namespace.name);
            }
            return probe;
        }

        public function namespaceset(namespaces:Array) {
            var probe = namespaceset_map.read(namespaces);
            if (probe == 0) {
                probe = namespaceset_count++;
                namespaceset_map.write(Util::copyArray(namespaces), probe);
                namespaceset_bytes.uint30(namespaces.length);
                for ( var i=0, limit=namespaces.length ; i < limit ; i++ )
                    namespaceset_bytes.uint30(namespaces[i]);
            }
            return probe;
        }

        /* Look up a multiname entry with kind, name, and namespace
         * set.  Allocate an entry for it if it does not exist.  If an
         * entry were allocated, then the negative of the entry index
         * is returned (and the caller should emit data to the
         * multiname_bytes stream), otherwise the entry index is
         * returned.  (If this seems a little contorted, it reduces
         * allocation of closures in the caller.)
         */

        // Temporary structure (avoids allocation of structures that already exist).
        var tmp_multiname = { "kind": 0, "name": 0, "ns": 0 };

        function multinameLookup(kind, name, ns) {
            tmp_multiname.kind = kind;
            tmp_multiname.name = name;
            tmp_multiname.ns = ns;
            var probe = multiname_map.read(tmp_multiname);
            if (probe != 0)
                return probe;

            // Allocate
            probe = multiname_pool.length;
            var entry = {"kind":tmp_multiname.kind, "name":tmp_multiname.name, "ns":tmp_multiname.ns}
            multiname_pool.push(entry);           // need "kind" for later, could optimize here --
            multiname_map.write(entry, probe);    //   but need to save the whole entry anyway
            return -probe;
        }

        public function QName(ns/*: uint*/, name/*: uint*/, is_attr: Boolean /*FIXME ES4: boolean*/) {
            var kind = is_attr ? CONSTANT_QNameA : CONSTANT_QName;
            var idx = multinameLookup( kind, name, ns );
            if (idx < 0) {
                multiname_bytes.uint8(kind);
                multiname_bytes.uint30(ns);
                multiname_bytes.uint30(name);
                idx = -idx;
            }
            return idx;
        }

        public function RTQName(name/*: uint*/, is_attr: Boolean /*FIXME ES4: boolean*/) {
            var kind = is_attr ? CONSTANT_RTQNameA : CONSTANT_RTQName;
            var idx = multinameLookup( kind, name, 0 );
            if (idx < 0) {
                multiname_bytes.uint8(kind);
                multiname_bytes.uint30(name); 
                idx = -idx;
            }
            return idx;
        }

        public function RTQNameL(is_attr: Boolean /*FIXME ES4: boolean*/) {
            var kind = is_attr ? CONSTANT_RTQNameLA : CONSTANT_RTQNameL;
            var idx = multinameLookup( kind, 0, 0 );
            if (idx < 0) {
                multiname_bytes.uint8(kind);
                idx = -idx;
            }
            return idx;
        }

        public function Multiname(nsset/*: uint*/, name/*: uint*/, is_attr: Boolean /*FIXME ES4: boolean*/ ) {
            var kind = is_attr ? CONSTANT_MultinameA : CONSTANT_Multiname;
            var idx = multinameLookup(kind, name, nsset );
            if (idx < 0) {
                multiname_bytes.uint8(kind);
                multiname_bytes.uint30(name);
                multiname_bytes.uint30(nsset); 
                idx = -idx;
            }
            return idx;
        }

        public function MultinameL(nsset/*: uint*/, is_attr: Boolean /*FIXME ES4: boolean*/) {
            var kind = is_attr ? CONSTANT_MultinameLA : CONSTANT_MultinameL;
            var idx = multinameLookup(kind, 0, nsset);
            if (idx < 0) {
                multiname_bytes.uint8(kind);
                multiname_bytes.uint30(nsset);
                idx = -idx;
            }
            return idx;
        }

        public function hasRTNS(index) {
            var kind = multiname_pool[index].kind;
            var result;
            switch (kind) {
            case CONSTANT_RTQName:
            case CONSTANT_RTQNameA:
            case CONSTANT_RTQNameL:
            case CONSTANT_RTQNameLA:
                result = true;
            default:
                result = false;
            }
            return result;
        }

        public function hasRTName(index) {
            var kind = multiname_pool[index].kind;
            var result;
            switch (multiname_pool[index].kind) {
            case CONSTANT_RTQNameL:
            case CONSTANT_RTQNameLA:
            case CONSTANT_MultinameL:
            case CONSTANT_MultinameLA:
                result = true;
            default:
                result = false;
            }
            return result;
        }

        function printPoolStats() {
            print("  Ints: n=" + int_count + ", bytes=" + int_bytes.length);
            print("  Uints: n=" + uint_count + ", bytes=" + uint_bytes.length);
            print("  Doubles: n=" + double_count + ", bytes=" + double_bytes.length);
            print("  Strings: n=" + utf8_count + ", bytes=" + utf8_bytes.length);
            print("  Namespaces: n=" + namespace_count + ", bytes=" + namespace_bytes.length);
            print("  Namespace sets: n=" + namespaceset_count + ", bytes=" + namespaceset_bytes.length);
            print("  Multinames: n=" + multiname_pool.length + ", bytes=" + multiname_bytes.length);
        }

        public function serialize(bs) {
            bs.uint30(int_count);
            bs.byteStream(int_bytes);

            bs.uint30(uint_count);
            bs.byteStream(uint_bytes);

            bs.uint30(double_count);
            bs.byteStream(double_bytes);

            bs.uint30(utf8_count);
            bs.byteStream(utf8_bytes);

            bs.uint30(namespace_count);
            bs.byteStream(namespace_bytes);

            bs.uint30(namespaceset_count);
            bs.byteStream(namespaceset_bytes);

            bs.uint30(multiname_pool.length);
            bs.byteStream(multiname_bytes);

            //printPoolStats();

            return bs;
        }
        /*private*/ var   int_count = 1;
        /*private*/ var   uint_count = 1;
        /*private*/ var   double_count = 1;
        /*private*/ var   utf8_count = 1;
        /*private*/ var   namespace_count = 1;
        /*private*/ var   namespaceset_count = 1;
        /*private*/ const multiname_pool = new Array; // its length is the count

        /*private*/ const int_bytes = new ABCByteStream;
        /*private*/ const uint_bytes = new ABCByteStream;
        /*private*/ const double_bytes = new ABCByteStream;
        /*private*/ const utf8_bytes = new ABCByteStream;
        /*private*/ const namespace_bytes = new ABCByteStream;
        /*private*/ const namespaceset_bytes = new ABCByteStream;
        /*private*/ const multiname_bytes = new ABCByteStream;

        var utf8_map;
        var multiname_map;
        var namespace_map;
        var namespaceset_map;
    }

    public class ABCMethodInfo
    {
        /* \param name         string index
         * \param param_types  array of multiname indices.  May not be null.
         * \param return_type  multiname index.
         * \param flags        bitwise or of NEED_ARGUMENTS, NEED_ACTIVATION, HAS_REST, SET_DXNS
         * \param options      [{val:uint, kind:uint}], if present.
         * \param param_names  array of param_info structures, if present.
         */
        function ABCMethodInfo(name/*:uint*/, param_types:Array, return_type/*:uint*/, flags/*:uint*/,
                               options:Array, param_names:Array) {
            this.name = name;
            this.param_types = param_types;
            this.return_type = return_type;
            this.flags = flags;
            this.options = options;
            this.param_names = param_names;
        }

        public function setFlags(flags) {
            this.flags = flags;
        }

        public function serialize(bs) {
            var i;
            bs.uint30(param_types.length);
            bs.uint30(return_type);
            for ( i=0 ; i < param_types.length ; i++ ) {
                bs.uint30(param_types[i]);
            }
            bs.uint30(name);
            if (options != null) {
                flags = flags | METHOD_HasOptional;
            }
            if (param_names != null) {
                flags = flags | METHOD_HasParamNames;
            }
            bs.uint8(flags);
            if (options != null) {
                bs.uint30(options.length);
                for ( i=0 ; i < options.length ; i++ ) {
                    bs.uint30(options[i].val);
                    bs.uint8(options[i].kind);
                }
            }
            if (param_names != null) {
                Util::assert( param_names.length == param_types.length );
                for ( i=0 ; i < param_names.length ; i++ )
                    bs.uint30(param_names[i]);
            }
        }

        /*private*/ var name, param_types, return_type, flags, options, param_names;
    }

    public class ABCMetadataInfo
    {
        function ABCMetadataInfo( name/*: uint*/, items: Array ) {
            Util::assert( name != 0 );
            this.name = name;
            this.items = items;
        }

        public function serialize(bs) {
            bs.uint30(name);
            bs.uint30(items.length);
            for ( var i=0 ; i < items.length ; i++ ) {
                bs.uint30(items[i].key);
                bs.uint30(items[i].value);
            }
        }

        /*private*/ var name, items;
    }

    public class ABCInstanceInfo
    {
        function ABCInstanceInfo(name, super_name, flags, protectedNS, interfaces) {
            this.name = name;
            this.super_name = super_name;
            this.flags = flags;
            this.protectedNS = protectedNS;
            this.interfaces = interfaces;
            this.traits = [];
        }

        public function setIInit(x) {
            iinit = x;
        }

        public function addTrait(t) {
            return traits.push(t)-1;
        }

        public function serialize(bs) {
            var i;

            Util::assert( iinit != undefined );

            bs.uint30(name);
            bs.uint30(super_name);
            bs.uint8(flags);
            if (flags & CONSTANT_ClassProtectedNs)
                bs.uint30(protectedNS);
            bs.uint30(interfaces.length);
            for ( i=0 ; i < interfaces.length ; i++ ) {
                Util::assert( interfaces[i] != 0 );
                bs.uint30(interfaces[i]);
            }
            bs.uint30(iinit);
            bs.uint30(traits.length);
            for ( i=0 ; i < traits.length ; i++ )
                traits[i].serialize(bs);
        }

        /*private*/ var name, super_name, flags, protectedNS, interfaces, iinit, traits;
    }

    public class ABCTrait
    {
        /* FIXME #101: super not implemented; subclasses must do implementation themselves;
           the constructor must not be defined here (for the sake of AS3).  */
        /*
        function ABCTrait(name, kind) {
            this.name = name;
            this.kind = kind;
        }
        */

    }

    public class ABCSlotTrait /// extends ABCTrait
    {
        function ABCSlotTrait(name, attrs, is_const, slot_id, type_name, vindex, vkind) {
            /*FIXME #101: super not implemented*/
            //super(name, (attrs << 4) | TRAIT_Slot);
            this.name = name;
            this.kind = (attrs << 4) | (is_const ? TRAIT_Const : TRAIT_Slot);
            this.metadata = [];
            //End of fixme
            this.slot_id = slot_id;
            this.type_name = type_name;
            this.vindex = vindex;
            this.vkind = vkind;
        }

        public function inner_serialize(bs) {
            bs.uint30(slot_id);
            bs.uint30(type_name);
            bs.uint30(vindex);
            if (vindex != 0)
                bs.uint8(vkind);
        }

        /*private*/ var slot_id, type_name, vindex, vkind;

        // from ABCTrait

        public function addMetadata(n) {
            return metadata.push(n)-1;
        }

        public function serialize(bs) {
            if (metadata.length > 0)
                kind = kind | ATTR_Metadata;
            bs.uint30(name);
            bs.uint30(kind);
            inner_serialize(bs);
            if (metadata.length > 0) {
                bs.uint30(metadata.length);
                for ( var i=0 ; i < metadata.length ; i++ )
                    bs.uint30(metadata[i]);
            }
        }

        public var name, kind, metadata;


    }

    public class ABCOtherTrait /// extends ABCTrait  // removed for esc
    {
        /* TAG is one of the TRAIT_* values, except TRAIT_Slot */
        function ABCOtherTrait(name, attrs, tag, id, val) {
            /*FIXME #101: super not implemented*/
            //super(name, (attrs << 4) | tag);
            this.name = name;
            this.kind = (attrs << 4) | tag;
            this.metadata = [];
            //End of fixme
            this.id = id;
            this.val = val;
        }

        // esc doesn't support override yet
        public function inner_serialize(bs) {
            bs.uint30(id);
            bs.uint30(val);
        }

        /*private*/ var id, val;

        // from ABCTrait

        public function addMetadata(n) {
            return metadata.push(n)-1;
        }

        public function serialize(bs) {
            if (metadata.length > 0)
                kind = kind | ATTR_Metadata;
            bs.uint30(name);
            bs.uint30(kind);
            inner_serialize(bs);
            if (metadata.length > 0) {
                bs.uint30(metadata.length);
                for ( var i=0 ; i < metadata.length ; i++ )
                    bs.uint30(metadata[i]);
            }
        }

        public var name, kind, metadata;


    }

    public class ABCClassInfo
    {
        public function setCInit(cinit) {
            this.cinit = cinit;
        }

        public function addTrait(t) {
            return traits.push(t)-1;
        }

        public function serialize(bs) {
            Util::assert( cinit != undefined );
            bs.uint30(cinit);
            bs.uint30(traits.length);
            for ( var i=0 ; i < traits.length ; i++ )
                traits[i].serialize(bs);
        }

        /*private*/ var cinit, traits = [];
    }

    public class ABCScriptInfo
    {
        function ABCScriptInfo(init) {
            this.init = init;
        }

        public function setInit(init) {
            this.init = init;
        }

        public function addTrait(t) {
            return traits.push(t)-1;
        }

        public function serialize(bs) {
            Util::assert( init != undefined );
            bs.uint30(init);
            bs.uint30(traits.length);
            for ( var i=0 ; i < traits.length ; i++ )
                traits[i].serialize(bs);
        }

        /*private*/ var init, traits = [];
    }

    public class ABCMethodBodyInfo
    {
        function ABCMethodBodyInfo(method) {
            this.method = method;
        }
        public function setMaxStack(ms) { max_stack = ms }
        public function setLocalCount(lc) { local_count = lc }
        public function setInitScopeDepth(sd) { init_scope_depth = sd }
        public function setMaxScopeDepth(msd) { max_scope_depth = msd }
        public function setCode(insns) { code = insns }

        public function addException(exn) {
            return exceptions.push(exn)-1;
        }

        public function addTrait(t) {
            return traits.push(t)-1;
        }

        public function serialize(bs) {
            Util::assert( max_stack != undefined && local_count != undefined );
            Util::assert( init_scope_depth != undefined && max_scope_depth != undefined );
            Util::assert( code != undefined );

            bs.uint30(method);
            bs.uint30(max_stack);
            bs.uint30(local_count);
            bs.uint30(init_scope_depth);
            bs.uint30(max_scope_depth);
            bs.uint30(code.length);
            code.serialize(bs);
            bs.uint30(exceptions.length);
            for ( var i=0 ; i < exceptions.length ; i++ )
                exceptions[i].serialize(bs);
            bs.uint30(traits.length);
            for ( var i=0 ; i < traits.length ; i++ )
                traits[i].serialize(bs);
        }

        /*private*/ var init_scope_depth = 0, exceptions = [], traits = [];
        /*private*/ var method, max_stack, local_count, max_scope_depth, code;
    }

    public class ABCException
    {
        function ABCException(first_pc, last_pc, target_pc, exc_type, var_name) {
            this.first_pc = first_pc;
            this.last_pc = last_pc;
            this.target_pc = target_pc;
            this.exc_type = exc_type;
            this.var_name = var_name;
        }

        public function serialize(bs) {
            bs.uint30(first_pc);
            bs.uint30(last_pc);
            bs.uint30(target_pc);
            bs.uint30(exc_type);
            bs.uint30(var_name);
        }

        /*private*/ var first_pc, last_pc, target_pc, exc_type, var_name;
    }
    
    // Construct an ABCFile instance from a bytestream representing an abc block.
    function parseAbcFile(b : ABCByteStream) : ABCFile {
        b.position = 0;
        magic = b.readInt();
        
        if (magic != (46<<16|16))
            throw new Error("not an abc file.  magic=" + magic.toString(16));
        
        var abc : ABCFile = new ABCFile();

        abc.constants = parseCpool(b);
        
        var i;
        var n;
        // MethodInfos
        n = b.readU32();
        for(i = 0; i < n; i++)
        {
            abc.addMethod(parseMethodInfo(b));
        }

        // MetaDataInfos
        n = b.readU32();
        for(i = 0; i < n; i++)
        {
            abc.addMetadata(parseMetadata(b));
        }

        // InstanceInfos
        n = b.readU32();
        for(i = 0; i < n; i++)
        {
            abc.addInstance(parseInstanceInfo(b));
        }
        // ClassInfos
        for(i = 0; i < n; i++)
        {
            abc.addClass(parseClassInfo(b));
        }

        // ScriptInfos
        n = b.readU32();
        for(i = 0; i < n; i++)
        {
            abc.addScript(parseScriptInfo(b));
        }

        // MethodBodies
        n = b.readU32();
        for(i = 0; i < n; i++)
        {
            abc.addMethodBody(parseMethodBody(b));
        }


        return abc;            
    }

    function parseCpool(b : ABCByteStream) : ABCConstantPool {
        var i:int;
        var n:int;
        
        var pool : ABCConstantPool = new ABCConstantPool;
        
		// ints
		n = b.readU32();
		for (i=1; i < n; i++)
			pool.int32(b.readU32());
        
		// uints
		n = b.readU32();
		for (i=1; i < n; i++)
			pool.uint32(uint(b.readU32()));
        
		// doubles
		n = b.readU32();
		doubles = [NaN];
		for (i=1; i < n; i++)
			pool.float64(b.readDouble());

        // strings
		n = b.readU32();
		for (i=1; i < n; i++)
			pool.stringUtf8(b.readUTFBytes(b.readU32()));
        
		// namespaces
		n = b.readU32()
		for (i=1; i < n; i++)
        {
            var nskind = b.readByte();
            var uri = b.readU32();
            pool.namespace(nskind, uri);
        }
        
		// namespace sets
		n = b.readU32();
		for (i=1; i < n; i++)
		{
			var count:int = b.readU32();
			var nsset = [];
			for (j=0; j < count; j++)
				nsset[j] = b.readU32();
            pool.namespaceset(nsset);
		}
        
		// multinames
		n = b.readU32()
		for (i=1; i < n; i++)
        {
            var kind = b.readByte();
			switch (kind)
			{
			case CONSTANT_QName:
			case CONSTANT_QNameA:
				pool.QName(b.readU32(), b.readU32(), kind==CONSTANT_QNameA)
				break;
			
			case CONSTANT_RTQName:
			case CONSTANT_RTQNameA:
				pool.RTQName(b.readU32(), kind==CONSTANT_RTQNameA)
				break;
			
			case CONSTANT_RTQNameL:
			case CONSTANT_RTQNameLA:
                pool.RTQNameL(kind==CONSTANT_RTQNameLA);
				names[i] = null
				break;
			
			case CONSTANT_Multiname:
			case CONSTANT_MultinameA:
				var name = b.readU32()
                pool.Multiname(b.readU32(), name, kind==CONSTANT_MultinameA);
				break;

			case CONSTANT_MultinameL:
			case CONSTANT_MultinameLA:
				pool.MultinameL(b.readU32(), kind==CONSTANT_MultinameLA)
				break;
				
			}
        }
        
        return pool;
    }

    function parseMethodInfo(b : ABCByteStream) : ABCMethodInfo {
        
        var paramcount = b.readU32();
        var returntype = b.readU32();
        var params = [];
        for(let i = 0; i < paramcount; ++i)
        {
            params[i] = b.readU32();
        }
        
        var name = b.readU32();
        var flags = b.readByte();
        
        var optionalcount = 0;
        var optionals = null;
        if( flags & METHOD_HasOptional )
        {
            optionalcount = b.readU32();
            optionals = [];
            for(let i = 0; i < optionalcount; ++i )
            {
                optionals[i] = [b.readU32(), b.readByte()];
            }
        }
        
        var paramnames = null;
        if( flags & METHOD_HasParamNames )
        {
            paramnames=[];
            for(let i = 0; i < paramcount; ++i)
                paramnames[i] = b.readU32();
        }    
        
        return new ABCMethodInfo(name, params, returntype, flags, optionals, paramnames);
    }
    
    function parseMetadataInfo(b : ABCByteStream) : ABCMetadataInfo {
        var name = b.readU32();
        var itemcount = b.readU32();
        
        var items = [];
        for( let i = 0; i < itemcount; i++ )
        {
            let key = b.readU32();
            let value = b.readU32();
            items[i] = { key:key, value:value };
        }
        
        return new ABCMetadataInfo(name, items);
        
    }
    
    function parseInstanceInfo(b : ABCByteStream) : ABCInstanceInfo {
        var name = b.readU32();
        var superclass = b.readU32();
        var flags = b.readByte();
        var protectedNS = 0;
        if( flags & 8 ) 
            protectedNS = b.readU32();
        
        var interfacecount = b.readU32();
        var interfaces = [];
        for(let i = 0; i < interfacecount; ++i)
        {
            interfaces[i] = b.readU32();
        }
        var iinit = b.readU32();
        
        var instance_info = new ABCInstanceInfo(name, superclass, flags, protectedNS, interfaces);
        
        instance_info.setIInit(iinit);
        
        parseTraits(instance_info, b);
        
        return instance_info;
    }
    
    function parseClassInfo(b : ABCByteStream) : ABCClassInfo {
        var cinit = b.readU32();

        var class_info = new ABCClassInfo();
        class_info.cinit = cinit;
        
        parseTraits(class_info, b);
        
        return class_info;
    }
    
    function parseScriptInfo(b : ABCByteStream) : ABCScriptInfo {
        
        var script = new ABCScriptInfo(b.readU32());
        parseTraits(script, b);
        return script;
    }
    
    function parseMethodBody(b : ABCByteStream) : ABCMethodBodyInfo {
        var mb:ABCMethodBodyInfo = new ABCMethodBodyInfo(b.readU32());
        
        mb.max_stack = b.readU32();
        mb.local_count = b.readU32();
        mb.init_scope_depth = b.readU32();
        mb.max_scope_depth = b.readU32();
        
        let code_len = b.readU32();
        mb.code = new ABCByteStream;
        for(let i = 0; i < code_len; ++i)
        {
            mb.code.uint8(b.readByte());
        }
        
        var excount = b.readU32();
        for( let i = 0; i < excount; ++i )
        {
            mb.addException(parseException(b));
        }
        
        parseTraits(mb, b);
        
        return mb;
    }
    
    function parseException(b : ABCByteStream) : ABCException {
        var start = b.readU32();
        var end = b.readU32();
        var target = b.readU32();
        var typename = b.readU32();
        var name = b.readU32();
        
        // WTF is wrong with this????
        var ex;
        ex = new ABCException(start, end, target, typename, name);
        return ex;
    }
    
    function parseTraits(target, b : ABCByteStream) {
        var traitcount = b.readU32();
        for(let i =0 ; i < traitcount; ++i)
        {
            target.addTrait(parseTrait(b));
        }
    }

    function parseTrait(b : ABCByteStream) //: ABCTrait should be ABCTrait once inheritance is supported
    {
        var name = b.readU32();
        
        var tag = b.readByte();
        var kind = tag&0x04;
        var attrs = (tag>>4) & 0x04;
        
        var trait;
        
        switch(kind)
        {
            case TRAIT_Slot:
            case TRAIT_Const:
                let slotid = b.readU32();
                let typename = b.readU32();
                let value = b.readU32();
                let kind = null;
                if( value != 0 )
                    kind = b.readByte();
                trait = new ABCSlotTrait(name, attrs, kind==TRAIT_Const, slotid, typename, value, kind);
                break;
            case TRAIT_Method:
            case TRAIT_Setter:
            case TRAIT_Getter:
                let dispid = b.readU32();
                let methinfo = b.readU32();
                trait = new ABCOtherTrait(name, attrs, kind, dispid, methinfo);
                break;
            case TRAIT_Class:
                let slotid = b.readU32();
                let classinfo = b.readU32();
                trait = new ABCOtherTrait(name, attrs, kind, slotid, classinfo);
                break;
        }
        
        if( attrs & ATTR_Metadata )
        {
            let metadatacount = b.readU32();
            for(let i = 0; i < metadatacount; ++i)
            {
                trait.addMetadata(b.readU32());
            }
        }
        
        return trait;
    }
    
}
