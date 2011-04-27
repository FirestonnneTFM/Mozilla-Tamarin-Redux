/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2010
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

// JSON according to the ECMAScript 5 specification.
// Based on ECMA-262-5 and Errata as of 31 July 2010 (no JSON errata at that time).
//
// Deliberate deviations from the specification
//  - There are additional type checks on JSON.parse and JSON.stringify - that fits AS3 better.
//  - Property enumeration order is indeterminate in AS3, so there is no attempt to extract
//    keys in any particular order when enumerating properties during filtering.
//
// Compiling it
//  - This code must be compilable with -strict.
//  - The code ought to work even if compiled with -AS3 because public:: qualifiers are
//    used where they matter.

package
{

    include "api-versions.as"

    [API(CONFIG::SWF_13)]
    [native(cls="JSONClass", classgc="exact", methods="auto", construct="none")]
    public final class JSON
    {
        private static const as3ns:Namespace = AS3;

        private native
        static function parseCore(text:String):Object;

        // specialized stringify procedure
        private native
        static function stringifySpecializedToString(value:Object,
                                                     replacerArray:Array,
                                                     replacerFunction:Function,
                                                     gap:String):String;

        public static function parse(text:String,
                                     reviver:Function = null):Object
        {
            if (text === null || text === undefined) {
                Error.throwError( SyntaxError, 1132 /*kJSONInvalidParseInput*/ );
            }

            // at this point, we should be assured that text is String.
            var unfiltered: Object = parseCore(text);

            if (reviver === null)
                return unfiltered;
            return (new Walker(reviver)).walk({ "": unfiltered }, "");
        }

        public static function stringify(value:Object,
                                         replacer=null,
                                         space=null):String
        {
            // We deliberately deviate from ECMA-262 and throw on
            // invalid replacer parameter.
            if (!(replacer === null || replacer is Function || replacer is Array))
                Error.throwError( TypeError, 1131 /*kJSONInvalidReplacer*/ );

            // We follow ECMA-262 and silently ignore invalid space parameter.
            if (!(space === null || space is String || space is Number))
                space = null;

            var gap = "";

            if (space is String)
                gap = space.length > 10 ? space.AS3::substring(0,10) : space;
            else if (space is Number)
                gap = "          ".AS3::substring(0,Math.min(10,Math.floor(space)));

            if (replacer === null) {
                return stringifySpecializedToString(value, null, null, gap);
            } else if (replacer is Array) {
                return stringifySpecializedToString(value, replacer, null, gap);
            } else { // replacer is Function
                return stringifySpecializedToString(value, null, replacer, gap);
            }
        }
    }

    internal final class Walker
    {
        function Walker(reviver:Function) {
            this.reviver = reviver;
        }

        function walk(holder:Object, name:String):* {
            var val:Object = holder[name];
            if (val is Array) {
                var v:Array = val as Array;
                for (var i:uint=0, limit:uint=v.length; i < limit; i++) {
                    var newElement:* = walk(v, String(i));
                    if (newElement === undefined)
                        delete v[i];
                    else
                        v[i] = newElement;
                }
            }
            else if (val !== null && !(val is Boolean) && !(val is Number) && !(val is String)) {

                //
                // See earlier note about unsafe for-in enumeration in AS3.

                for (var p:String in val) {
                    if (!val.AS3::hasOwnProperty(p))
                        break;
                    var newElement:* = walk(val, p);
                    if (newElement === undefined)
                        delete val[p];
                    else
                        val[p] = newElement;
                }
            }
            return reviver.AS3::call(holder, name, val);
        }

        var reviver:Function;
    }
}
