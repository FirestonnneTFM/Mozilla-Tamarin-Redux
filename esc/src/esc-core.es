/* -*- mode: java; tab-width: 4; insert-tabs-mode: nil; indent-tabs-mode: nil;  -*- */
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

{
    use default namespace ESC;

    var booted = false;

    function readFile(fn) {
        import avmplus.*;
        return File.read (fn);
    }

    function loadBytes(bytes) {
        import avmplus.*;
        Domain.currentDomain.loadBytes(bytes);
    }

    function commandLineArguments() {
        import avmplus.*;
        return System.argv;
    }
	
    function getTopFixtures() {
        use namespace Ast;

        var nd = Decode::program (esc_env);    // esc_env is defined in esc-env.es (within ESC namespace)
        return nd.head.fixtures;
    }

    function compile(consume, produce, context) {
        use namespace Parse;

        var t1 = new Date;

        var input = consume()
        var parser = new Parser( input, getTopFixtures(), context );
        var prog = parser.program();

        var t2 = new Date;

        produce( Gen::cg(prog) );

        var t3 = new Date;

        return [t2-t1, t3-t2];
    }

    function compileFile(fname)
        compile( function () { return ESC::readFile(fname) },
                 function (abc) { return dumpABCFile(abc, fname + ".abc") },
                 fname );

    
    function compileAndLoadFile(fname)
        compile( function () { return ESC::readFile(fname) },
                 function (abc) { return ESC::loadBytes(abc.getBytes()) },
                 fname );

    function compileAndLoadString(input, context)
        compile( function () { return input },
                 function (abc) { return ESC::loadBytes(abc.getBytes()) },
                 context );
}
