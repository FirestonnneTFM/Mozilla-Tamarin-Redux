/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2009
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

/* Usage:
 *
 *    avmshell apivergen.abc -- ... api-versions.xml
 *
 * All arguments except the last are ignored.
 */
package apivergen 
{
    import avmplus.*;

    var DO_NOT_EDIT =
        "/* DO NOT EDIT THIS FILE!  It was generated by utils/apivergen.abc. */\n\n";

    var LICENSE_BLOCK = 
        "/* ***** BEGIN LICENSE BLOCK *****\n"   +
        " * Version: MPL 1.1/GPL 2.0/LGPL 2.1\n" +
        " *\n" +
        " * The contents of this file are subject to the Mozilla Public License Version\n" +
        " * 1.1 (the \"License+\"); you may not use this file except in compliance with\n" +
        " * the License. You may obtain a copy of the License at\n" +
        " * http://www.mozilla.org/MPL/\n" +
        " *\n" +
        " * Software distributed under the License is distributed on an \"AS IS\" basis,\n" +
        " * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License\n" +
        " * for the specific language governing rights and limitations under the\n" +
        " * License.\n" +
        " *\n" +
        " * The Original Code is [Open Source Virtual Machine].\n" +
        " *\n" +
        " * The Initial Developer of the Original Code is\n" +
        " * Adobe System Incorporated.\n" +
        " * Portions created by the Initial Developer are Copyright (C) 2008\n" +
        " * the Initial Developer. All Rights Reserved.\n" +
        " *\n" +
        " * Contributor(s):\n" +
        " *   Adobe AS3 Team\n" +
        " *\n" +
        " * Alternatively, the contents of this file may be used under the terms of\n" +
        " * either the GNU General Public License Version 2 or later (the \"GPL+\"), or\n" +
        " * the GNU Lesser General Public License Version 2.1 or later (the \"LGPL\"),\n" +
        " * in which case the provisions of the GPL or the LGPL are applicable instead\n" +
        " * of those above. If you wish to allow use of your version of this file only\n" +
        " * under the terms of either the GPL or the LGPL, and not to allow others to\n" +
        " * use your version of this file under the terms of the MPL, indicate your\n" +
        " * decision by deleting the provisions above and replace them with the notice\n" +
        " * and other provisions required by the GPL or the LGPL. If you do not delete\n" +
        " * the provisions above, a recipient may use your version of this file under\n" +
        " * the terms of any one of the MPL, the GPL or the LGPL.\n" +
        " *\n" +
        " * ***** END LICENSE BLOCK ***** */\n" +
        "\n";

    /**
     * find the coordinates of a value in an n-dim matrix
     *
     * v = value to look for
     * m = array of array of ... of value
     * dim = dimensionality of m
     */

    function find(v, m, dim)
    {
        if (dim == 0)
            return m == v ? [] : null;
        for ( var i=0 ; i < m.length ; i++ ) {
            var probe = find(v, m[i], dim-1);
            if (probe) {
                probe.unshift(i);
                return probe;
            }
        }
        return null;
    }

    /**
     * emit the values in positions outside of a given position
     * in an n-dim matrix
     *
     * m = array of array of ... of value
     * coord = array of int
     * dim = dimensionality of m; length of coord
     * f = function to call on each value
     */

    function gen(m, coord, dim, f): void
    {
        if (dim == 0) {
            f(m);
            return;
        }
        for (var i=coord[coord.length-dim] ; i < m.length ; i++)
            gen(m[i], coord, dim-1, f);
    }
    
    function process (fname) {
        var api = new XML (File.read (fname));
        var versions = api.versions;
        var uris = api.uris;
        var releases = versions..release;
        var products = releases[releases.length()-1]..product;
        var profiles = products[products.length()-1]..profile;
        var release_ids = [];
        var product_ids = [];
        var profile_ids = [];
        for each (var v in releases) {
            release_ids.push(v.@id);
        }

        for each (var v in products) {
            product_ids.push(v.@id);
        }

        for each (var v in profiles) {
            profile_ids.push(v.@id);
        }

        var default_version = -1; // default

        // build the compatiblity matrix (emitting a comment on which
        // versions are which)

        var frag = {};
        var out = DO_NOT_EDIT + LICENSE_BLOCK;
        var d1 = [];
        var min_version = Number.MAX_VALUE;
        var max_version = 0;
        var maximalNonSys = 0;
        var config_names = [];
        out += "/*\n";
        for each (var release_id in release_ids) {
            var d2 = [];
            d1.push(d2);
            var release = versions.release.(@id == release_id);
            default_version = release.version==void 0 ? default_version : release.version.@id;
            for each (var product_id in product_ids) {
                var d3 = [];
                d2.push(d3);
                product = release.product.(@id == product_id);
                var default_version = product.version==void 0 ? default_version : product.version.@id;
                for each (var profile_id in profile_ids) {
                    var profile = product.profile.(@id == profile_id);
                    var version = profile.version==void 0 ? default_version : profile.version.@id;
                    if(version >= 0) {
                        out += "["+release_id+","+product_id+","+profile_id+"]="+version+":"+profile.version.@alias+"\n";
                        if (!String(profile.version.@alias).match(/_SYS$/))
                            maximalNonSys = Math.max(maximalNonSys, parseInt(String(version)));
                        config_names.push({name: String(profile.version.@alias), value: version});
                    }
                    d3.push(version);
                    if (version > max_version) {
                        max_version = version;
                    }
                    if (version >=0 && version < min_version) {
                        min_version = version;
                    }
                }
            }
        }
        out += "*/\n\n";
        frag.documentation = out;
        out = "";
        frag.maximalNonSys = String(maximalNonSys) + ";\n";
        frag.config_names = config_names;

        // emit the array of versions_count array
        var version_count;
        out += "[] = {";
        for (var v = min_version; v <= max_version; ++v) {
            version_count = 0;
            gen(d1,find(v,d1,3),3, function (x) { if(x>=0) version_count += 1 });
            out += version_count + ", ";
        }
        out += "};\n\n";
        frag.versions_count = out;
        out = "";

        // emit the versions matrix
        frag.versions = "["+(Number(max_version)-Number(min_version)+1)+"]";
        out += "{\n";
        for (var v = min_version; v <= max_version; ++v) {
            out += "  {";
            gen(d1,find(v,d1,3),3, function (x) { if(x>=0) out += x + ", " });
            out += "},\n";
        }
        out += "};\n";
        frag.versions_initializer = out;

        frag.uris_count = "" + uris.uri.length() + ";\n";
        out = "{\n";
        for each (var v in uris.uri) {
            out += "  \"" + v.@id + "\",\n";
        }
        out += "};\n";
        frag.uris = out;
        frag.min_version_num = min_version + ";\n";
        frag.max_version_num = max_version + ";\n";

        out = "{";
        for (var v = min_version; v <= max_version; ++v) {
            var api = 0;
            gen(d1,find(v,d1,3),3, function (x) { if(x>=0) api |= 0x1 << x-min_version });
            out += "0x" + api.toString(16) + ", ";
        }
        out += "};\n";
        frag.api_compat_initializer = out;

        return frag;
    }

    /*
      emit c code
    */

    function emitc(frag) {
        var out = frag.documentation;
        out += "static const uint32_t _min_version_num = " + frag.min_version_num;
        out += "static const uint32_t _max_version_num = " + frag.max_version_num;
        out += "static const uint32_t _versions_count" + frag.versions_count;
        out += "static const uint32_t _versions []" + frag.versions;
        out += " = " + frag.versions_initializer;
        out += "static const uint32_t _uris_count = " + frag.uris_count;
        out += "static const char* _uris [] = " + frag.uris;
        out += "static const int32_t _api_compat [] = " + frag.api_compat_initializer;
        out += "static const uint32_t _max_nonsys_version_num = " + frag.maximalNonSys;
        return out;
    }

    /*
      emit java
    */

    function emitj(frag) {
        var out = frag.documentation;
        out += "package macromedia.asc.util;\n";
        out += "public class APIVersions {\n";
        out += "public static int min_version_num = " + frag.min_version_num;
        out += "public static int max_version_num = " + frag.max_version_num;
        out += "public static int versions [][]";
        out += " = " + frag.versions_initializer;
        out += "public static String uris [] = " + frag.uris;
        out += "public static int api_compat [] = " + frag.api_compat_initializer;
        out += "};\n";
        return out;
    }

    /*
      emit actionscript
    */
    function emitas(frag) {
        var out = DO_NOT_EDIT + LICENSE_BLOCK;
        var c = frag.config_names;
        for ( var i=0 ; i < c.length ; i++ )
            out += "CONFIG const " + c[i].name + " = " + c[i].value + ";\n";
        return out;
    }

    /*
      get file name from the command-line and go. ignore all but the last 
      argument, which is treated as the file name
    */

    var argv = System.argv;
    var fname = argv[argv.length-1];
    var frags = process(fname);
    File.write("api-versions.h", emitc(frags));
    File.write("api-versions.java", emitj(frags));
    File.write("api-versions.as", emitas(frags));
}
