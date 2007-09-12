/* -*- mode: java; mode: font-lock; tab-width: 4; insert-tabs-mode: nil; indent-tabs-mode: nil -*- */
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

use namespace Release;
use namespace Ast;
use namespace intrinsic;
public namespace AbcEncode;

{
    use default namespace AbcEncode;
    use namespace Abc;
    use namespace Asm;

    function indent (n:int)
        : string {
        let str = "\n";

        for ( ; n > 0; n-- ) {
            str = str + " ";
        }

        return str;
    }

    function abcFile (nd : ABCFile, nesting : int = 0)
        : string {
        enter ("AbcEncode::abcFile ", nesting);

        var str = indent(nesting) + "{ 'abc_class': 'AbcFile'"
                + indent(nesting) + ", 'minor_version': " + nd.minor_version
                + indent(nesting) + ", 'major_version': " + nd.major_version
                + indent(nesting) + ", 'int_pool': [ " + intPool (nd.constants.int_pool,nesting+", 'int_pool': [ ".length) + " ]"
                + indent(nesting) + ", 'uint_pool': [ " + uintPool (nd.constants.uint_pool,nesting+", 'uint_pool': [ ".length) + " ]"
                + indent(nesting) + ", 'double_pool': [ " + doublePool (nd.constants.double_pool,nesting+", 'double_pool': [ ".length) + " ]"
                + indent(nesting) + ", 'utf8_pool': [ " + utf8Pool (nd.constants.utf8_pool,nesting+", 'utf8_pool': [ ".length) + " ]"
                + indent(nesting) + ", 'namespace_pool': [ " + namespacePool (nd.constants.namespace_pool,nesting+", 'namespace_pool': [ ".length) + " ]"
                + indent(nesting) + ", 'nsset_pool': [ " + namespacesetPool (nd.constants.namespaceset_pool,nesting+", 'nsset_pool': [ ".length) + " ]"
                + indent(nesting) + ", 'name_pool': [ " + namePool (nd.constants.multiname_pool,nesting+", 'name_pool': [ ".length) + " ]"

                + indent(nesting) + ", 'method_infos': [ "   + methodInfos (nd.methods,nesting+", 'method_infos': [ ".length) + " ]"
            /*
                + indent(nesting) + ", 'metadata_infos': [ " + metadataInfo (nd.metadatas,nesting+", 'metadata_infos': [ ".length) + " ]"
                + indent(nesting) + ", 'instance_infos': [ " + instanceInfo (nd.instances,nesting+", 'instance_infos': [ ".length) + " ]"
                + indent(nesting) + ", 'classe_infos': [ "   + classInfo (nd.classes,nesting+", 'class_infos': [ ".length) + " ]"
                + indent(nesting) + ", 'script_infos': [ "   + scriptInfo (nd.scripts,nesting+", 'script_infos': [ ".length) + " ]"
            */
                + indent(nesting) + ", 'method_bodys': [ "   + methodBodys (nd.bodies,nesting+", 'method_bodys': [ ".length) + " ]"
                + " }";

        exit ("AbcEncode::abcFile");
        return str;
    }

    function intPool (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::intPool ", nesting);

        var str = "";

        for (var i = 1, len = nd.length; i < len; ++i) 
        {
            str = str
                + indent (nesting-2)
                + ", "
                + "'" + nd[i] + "'"; //intConst (nd[i], nesting)
        }

        exit ("AbcEncode::intPool");
        return str;
    }

    function uintPool (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::uintPool ", nesting);

        var str = "";   // hole for sub 0

        for (var i = 1, len = nd.length; i < len; ++i) 
        {
            str = str
                + indent (nesting-2)
                + ", "
                + "'" + nd[i] + "'" //intConst (nd[i], nesting)
        }

        exit ("AbcEncode::uintPool");
        return str;
    }

    function doublePool (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::doublePool ", nesting);

        var str = "";

        for (var i = 1, len = nd.length; i < len; ++i) 
        {
            str = str
                + indent (nesting-2)
                + ", "
                + "'" + nd[i] + "'" //intConst (nd[i], nesting)
        }

        exit ("AbcEncode::doublePool");
        return str;
    }

    function utf8Pool (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::utf8Pool ", nesting);

        var str = "";

        for (var i = 1, len = nd.length; i < len; ++i) 
        {
            str = str
                + indent (nesting-2)
                + ", "
                + "'" + nd[i] + "'" //intConst (nd[i], nesting)
        }

        exit ("AbcEncode::utf8Pool");
        return str;
    }

    function namespacePool (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::namespacePool ", nesting);

        var str = "";

        for (var i = 1, len = nd.length; i < len; ++i) 
        {
            str = str
                + indent (nesting-2)
                + ", "
                + namespaceConst (nd[i], nesting)
        }

        exit ("AbcEncode::namespacePool");
        return str;
    }

    function namespaceConst (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::namespaceConst ", nesting);
        var str = "{ 'kind': " + namespaceKind (nd.kind,nesting+"{ 'kind': ".length)
                + indent(nesting) + ", 'utf8': '" + nd.name + "'"
                + " }";

        exit ("AbcEncode::abcFile");
        return str;
    }

    function namespaceKind (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::namespaceKind ", nesting);
        var str = "";

        switch (nd) {
        case CONSTANT_Namespace:
            str = "'AnonymousNamespace'";
            break;
        case CONSTANT_PackageNamespace:
            str = "'PackageNamespace'";
            break;
        default:
            str = "Other";
            break;
        }

        exit ("AbcEncode::namespaceKind");
        return str;
    }

    function namespacesetPool (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::namespacesetPool ", nesting);

        var str = "";

        for (var i = 1, len = nd.length; i < len; ++i) 
        {
            str = str
                + indent (nesting-2)
                + ", "
                + "[ " + namespacesetConst (nd[i], nesting+"[ ".length)
                + " ]"
        }

        exit ("AbcEncode::namespacesetPool");
        return str;
    }

    function namespacesetConst (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::namespacesetConst ", nesting);

        var str = "'" + nd[0] + "'";

        for (var i = 1, len = nd.length; i < len; ++i) 
        {
            str = str
                + indent (nesting-2)
                + ", "
                + "'" + nd[i] + "'"
        }

        exit ("AbcEncode::namespacesetConst");
        return str;
    }

    function namePool (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::namePool ", nesting);

        var str = "";

        for (var i = 1, len = nd.length; i < len; ++i)
        {
            str = str
                + indent (nesting-2)
                + ", "
                + nameConst (nd[i], nesting)
        }

        exit ("AbcEncode::namePool");
        return str;
    }

    function nameConst (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::nameConst ", nesting);

        var str = "";

        switch (nd.kind) {
        case CONSTANT_QName:
            str = "{ 'kind': 'QName'"
                + indent(nesting)
                + ", 'ns': '" + nd.ns + "'"
                + indent(nesting) 
                + ", 'utf8': '" + nd.name + "'"
                + " }";
            break;
        case CONSTANT_RTQName:
            str = "{ 'kind': 'RTQName'"
                + indent(nesting) 
                + ", 'utf8': '" + nd.name + "'"
                + " }";
            break;
        case CONSTANT_RTQNameL:
            str = "{ 'kind': 'RTQName'"
                + " }";
            break;
        case CONSTANT_Multiname:
            str = "{ 'kind': 'Multiname'"
                + indent(nesting) 
                + ", 'utf8': '" + nd.name + "'"
                + indent(nesting) 
                + ", 'nsset': '" + nd.ns + "'"
                + " }";
            break;
        case CONSTANT_MultinameL:
            str = "{ 'kind': 'MultinameL'"
                + indent(nesting) 
                + ", 'nss': '" + nd.ns + "'"
                + " }";
            break;
        case CONSTANT_QNameA:
        case CONSTANT_RTQNameA:
        case CONSTANT_RTQNameLA:
        case CONSTANT_MultinameA:
        case CONSTANT_MultinameLA:
        default:
            str = "Unsupported Name constant";
            break;
        }

        exit ("AbcEncode::nameConst");
        return str;
    }

    function methodInfos (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::methodInfos ", nesting);

        var str = "";

        for (var i = 0, len = nd.length; i < len; ++i)
        {
            str = str
                + methodInfo (nd[i], nesting)
                + indent (nesting-2)
                + ", "
        }

        exit ("AbcEncode::methodInfos");
        return str;
    }

    function methodInfo (nd, nesting: int = 0)
        : string {
        enter ("AbcEncode::methodInfo");

        var str =
            "{ 'ret_type': "
          + indent(nesting) + ", 'param_types': [" + "" + "]"
          + indent(nesting) + ", 'name': "
          + indent(nesting) + ", 'flags': "
          + indent(nesting) + ", 'optional_count': "
          + indent(nesting) + ", 'value_kind': [ " + "" + " ]"
          + indent(nesting) + ", 'param_names': [ " + "" + " ]"
          + " }";

        exit ("AbcEncode:methodInfo ",str);
        return str;
    }


    function methodBodys (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::methodBodys ", nesting);

        var str = "";

        for (var i = 0, len = nd.length; i < len; ++i)
        {
            str = str
                + methodBody (nd[i], nesting)
                + indent (nesting-2)
                + ", "
        }

        exit ("AbcEncode::methodBodys");
        return str;
    }

    function methodBody (nd, nesting: int = 0)
        : string {
        enter ("AbcEncode::methodBody");

        var str =
            "{ 'method_info': "
          + indent(nesting) + ", 'max_stack': "
          + indent(nesting) + ", 'max_regs': "
          + indent(nesting) + ", 'scope_depth': "
          + indent(nesting) + ", 'max_scope': "
          + indent(nesting) + ", 'code': [ " + code (nd.code, nesting+", 'code': [ ".length) + " ]"
          + indent(nesting) + ", 'exceptions': [ " + "" + " ]"
          + indent(nesting) + ", 'fixtures': [ " + "" + " ]"
          + " }";

        exit ("AbcEncode:methodBody ",str);
        return str;
    }

    function code (nd, nesting : int = 0)
        : string {
        enter ("AbcEncode::code ", nesting);

        var str = "";
        var bytes = nd.code.getArrayOfBytes ();

        for (var ip = 0, len = bytes.length; ip < len; ip=ip+width)
        {
            var [bs,width] = instruction (ip);
            str = str
                + bs
                + indent (nesting-2)
                + ", "
        }

        exit ("AbcEncode::code");
        return str;

        function instruction (ip)
            : [int,string] {
            enter ("AbcEncode::instruction ",ip);
            
            var str = "";
            var n = bytes[ip];
            var width = opcodes [n][1]
            switch (width) {
            case 0:
                str = "invalid opcode " + opcodes[n][0];
                width = 1;
                break;
            default:
                str = opcodes[n][0] + operands ();
                break;
            }

            exit ("AbcEncode::code");
            return [str,width];

            function operands () {
                var str = "";

                // do variable length int operands if all are variable length
                // FIXME this is all a little too cute for my taste

                if (width < 0) { 
                    var w = width; 
                    width = 1;
                }
                for (var i=1; w<0; w=w+2, i=i+1 ) {
                    let n;
                    if (bytes[ip+i] < 0x7F) n = 1;
                    else if (bytes[ip+i] < 0x4000) n = 2;
                    else if (bytes[ip+i] < 0x20000) n = 3;
                    else if (bytes[ip+i] < 0x1000000) n = 4;
                    else n = 5;
                    width = width + n;
                    i = i + n;
                }

                for (let n=1; n<width; ++n) { // 0 is the opcode
                    str = str + " " + (bytes[ip+n]<16 ? "0"+ bytes[ip+n].toString (16) : bytes[ip+n].toString (16));
                }
                return str;
            }
        }
    }

    // negative widths mean variable length. -2 for each variable length operand. zero width
    // means no implemented or deprecated and should never be used.

    var opcodes = [ ["OP_0x00", 0]
                  , ["bkpt", 1]
                  , ["nop", 1]
                  , ["throw", 1]
                  , ["getsuper", 1-2]
                  , ["setsuper", 1-2]
                  , ["dxns", 1-2]
                  , ["dxnslate", 1]
                  , ["kill", 1-2]
                  , ["label", 1]
                  , ["OP_0x0A", 0]
                  , ["OP_0x0B", 0]
                  , ["ifnlt", 1+3]
                  , ["ifnle", 1+3]
                  , ["ifngt", 1+3]
                  , ["ifnge", 1+3]
                  , ["jump", 1+3]
                  , ["iftrue", 1+3]
                  , ["iffalse", 1+3]
                  , ["ifeq", 1+3]
                  , ["ifne", 1+3]
                  , ["iflt", 1+3]
                  , ["ifle", 1+3]
                  , ["ifgt", 1+3]
                  , ["ifge", 1+3]
                  , ["ifstricteq", 1+3]
                  , ["ifstrictne", 1+3]
                  , ["lookupswitch", 1+3+2+0]
                  , ["pushwith", 1]
                  , ["popscope", 1]
                  , ["nextname", 1]
                  , ["hasnext", 1]
                  , ["pushnull", 1]
                  , ["pushundefined", 1]
                  , ["OP_0x22", 0]
                  , ["nextvalue", 1]
                  , ["pushbyte", 1+1]
                  , ["pushshort", 1-2]
                  , ["pushtrue", 1]
                  , ["pushfalse", 1]
                  , ["pushnan", 1]
                  , ["pop", 1]
                  , ["dup", 1]
                  , ["swap", 1]
                  , ["pushstring", 1-2]
                  , ["pushint", 1-2]
                  , ["pushuint", 1-2]
                  , ["pushdouble", 1-2]
                  , ["pushscope", 1]
                  , ["pushnamespace", 1-2]
                  , ["hasnext2", 1]
                  , ["OP_0x33", 0]
                  , ["OP_0x34", 0]
                  , ["OP_0x35", 0]
                  , ["OP_0x36", 0]
                  , ["OP_0x37", 0]
                  , ["OP_0x38", 0]
                  , ["OP_0x39", 0]
                  , ["OP_0x3A", 0]
                  , ["OP_0x3B", 0]
                  , ["OP_0x3C", 0]
                  , ["OP_0x3D", 0]
                  , ["OP_0x3E", 0]
                  , ["OP_0x3F", 0]
                  , ["newfunction", 1-2]
                  , ["call", 1-2]
                  , ["construct", 1-2]
                  , ["callmethod", 1-2-2]
                  , ["callstatic", 1-2-2]
                  , ["callsuper", 1-2-2]
                  , ["callproperty", 1-2-2]
                  , ["returnvoid", 1]
                  , ["returnvalue", 1]
                  , ["constructsuper", 1-2]
                  , ["constructprop", 1-2-2]
                  , ["callsuperid", 0]
                  , ["callproplex", 1-2-2]
                  , ["callinterface", 0]
                  , ["callsupervoid", 1-2-2]
                  , ["callpropvoid", 1-2-2]
                  , ["OP_0x50", 0]
                  , ["OP_0x51", 0]
                  , ["OP_0x52", 0]
                  , ["OP_0x53", 0]
                  , ["OP_0x54", 0]
                  , ["newobject", 1-2]
                  , ["newarray", 1-2]
                  , ["newactivation", 1]
                  , ["newclass", 1-2]
                  , ["getdescendants", 1-2]
                  , ["newcatch", 1-2]
                  , ["OP_0x5B", 0]
                  , ["OP_0x5C", 0]
                  , ["findpropstrict", 1-2]  // width depends on size of index
                  , ["findproperty", 1-2]
                  , ["finddef", 1-2]
                  , ["getlex", 1-2]
                  , ["setproperty", 1-2]
                  , ["getlocal", 1-2]
                  , ["setlocal", 1-2]
                  , ["getglobalscope", 1]
                  , ["getscopeobject", 1-2]
                  , ["getproperty", 1-2]
                  , ["OP_0x67", 0]
                  , ["initproperty", 1-2]
                  , ["OP_0x69", 0]
                  , ["deleteproperty", 1-2]
                  , ["OP_0x6B", 0]
                  , ["getslot", 1-2]
                  , ["setslot", 1-2]
                  , ["getglobalslot", 0]
                  , ["setglobalslot", 0]
                  , ["convert_s", 1]
                  , ["esc_xelem", 1]
                  , ["esc_xattr", 1]
                  , ["convert_i", 1]
                  , ["convert_u", 1]
                  , ["convert_d", 1]
                  , ["convert_b", 1]
                  , ["convert_o", 1]
                  , ["checkfilter", 1]
                  , ["OP_0x79", 0]
                  , ["OP_0x7A", 0]
                  , ["OP_0x7B", 0]
                  , ["OP_0x7C", 0]
                  , ["OP_0x7D", 0]
                  , ["OP_0x7E", 0]
                  , ["OP_0x7F", 0]
                  , ["coerce", 1-2]
                  , ["coerce_b", 0]
                  , ["coerce_a", 1]
                  , ["coerce_i", 0]
                  , ["coerce_d", 0]
                  , ["coerce_s", 1]
                  , ["astype", 1-2]
                  , ["astypelate", 1]
                  , ["coerce_u", 0]
                  , ["coerce_o", 1]
                  , ["OP_0x8A", 0]
                  , ["OP_0x8B", 0]
                  , ["OP_0x8C", 0]
                  , ["OP_0x8D", 0]
                  , ["OP_0x8E", 0]
                  , ["OP_0x8F", 0]
                  , ["negate", 1]
                  , ["increment", 1]
                  , ["inclocal", 1-2]
                  , ["decrement", 1]
                  , ["declocal", 1-2]
                  , ["typeof", 1]
                  , ["not", 1]
                  , ["bitnot", 1]
                  , ["OP_0x98", 0]
                  , ["OP_0x99", 0]
                  , ["concat", 0]
                  , ["add_d", 0]
                  , ["OP_0x9C", 0]
                  , ["OP_0x9D", 0]
                  , ["OP_0x9E", 0]
                  , ["OP_0x9F", 0]
                  , ["add", 1]
                  , ["subtract", 1]
                  , ["multiply", 1]
                  , ["divide", 1]
                  , ["modulo", 1]
                  , ["lshift", 1]
                  , ["rshift", 1]
                  , ["urshift", 1]
                  , ["bitand", 1]
                  , ["bitor", 1]
                  , ["bitxor", 1]
                  , ["equals", 1]
                  , ["strictequals", 1]
                  , ["lessthan", 1]
                  , ["lessequals", 1]
                  , ["greaterthan", 1]
                  , ["greaterequals", 1]
                  , ["instanceof", 1]
                  , ["istype", 1-2]
                  , ["istypelate", 1]
                  , ["in", 1]
                  , ["OP_0xB5", 0]
                  , ["OP_0xB6", 0]
                  , ["OP_0xB7", 0]
                  , ["OP_0xB8", 0]
                  , ["OP_0xB9", 0]
                  , ["OP_0xBA", 0]
                  , ["OP_0xBB", 0]
                  , ["OP_0xBC", 0]
                  , ["OP_0xBD", 0]
                  , ["OP_0xBE", 0]
                  , ["OP_0xBF", 0]
                  , ["increment_i", 1]
                  , ["decrement_i", 1]
                  , ["inclocal_i", 1-2]
                  , ["declocal_i", 1-2]
                  , ["negate_i", 1]
                  , ["add_i", 1]
                  , ["subtract_i", 1]
                  , ["multiply_i", 1]
                  , ["OP_0xC8", 0]
                  , ["OP_0xC9", 0]
                  , ["OP_0xCA", 0]
                  , ["OP_0xCB", 0]
                  , ["OP_0xCC", 0]
                  , ["OP_0xCD", 0]
                  , ["OP_0xCE", 0]
                  , ["OP_0xCF", 0]
                  , ["getlocal0", 1]
                  , ["getlocal1", 1]
                  , ["getlocal2", 1]
                  , ["getlocal3", 1]
                  , ["setlocal0", 1]
                  , ["setlocal1", 1]
                  , ["setlocal2", 1]
                  , ["setlocal3", 1]
                  , ["OP_0xD8", 0]
                  , ["OP_0xD9", 0]
                  , ["OP_0xDA", 0]
                  , ["OP_0xDB", 0]
                  , ["OP_0xDC", 0]
                  , ["OP_0xDD", 0]
                  , ["OP_0xDE", 0]
                  , ["OP_0xDF", 0]
                  , ["OP_0xE0", 0]
                  , ["OP_0xE1", 0]
                  , ["OP_0xE2", 0]
                  , ["OP_0xE3", 0]
                  , ["OP_0xE4", 0]
                  , ["OP_0xE5", 0]
                  , ["OP_0xE6", 0]
                  , ["OP_0xE7", 0]
                  , ["OP_0xE8", 0]
                  , ["OP_0xE9", 0]
                  , ["OP_0xEA", 0]
                  , ["OP_0xEB", 0]
                  , ["OP_0xEC", 0]
                  , ["OP_0xED", 0]
                  , ["abs_jump", 0]
                  , ["debug", 1-2-2-2-2]  // this isn't quite right, some operands are unsigned bytes
                  , ["debugline", 1-2]
                  , ["debugfile", 1-2]
                  , ["bkptline", 1-2]
                  , ["timestamp", 1]
                  , ["OP_0xF4", 0]
                  , ["verifypass", 0]
                  , ["alloc", 0]
                  , ["mark", 0]
                  , ["wb", 0]
                  , ["prologue", 0]
                  , ["sendenter", 0]
                  , ["doubletoatom", 0]
                  , ["sweep", 0]
                  , ["codegenop", 0]
                  , ["verifyop", 0]
                  , ["decode", 0]
                  , ];
}
