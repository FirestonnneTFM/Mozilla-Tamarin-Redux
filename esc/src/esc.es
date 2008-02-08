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
    var total_frontend = 0;
    var total_backend = 0;

    function readFile(fn) {
        import avmplus.*;
        return File.read (fn);
    }

    function boot() {
        use namespace Parse;
        use namespace Gen;

        var esc_env_str = readFile ("esc-env.ast");
        var parser = new Parser(esc_env_str,[], "esc-env.ast");
        var nd = parser.program();
        var bytes = cg(nd).getBytes();
        Domain.currentDomain.loadBytes(bytes); // this defines the variable "esc_env".
    }

    function getTopFixtures() {
        use namespace Ast;

        var nd = Decode::program (esc_env);    // esc_env is defined by side effect in "boot", above
        return nd.head.fixtures;
    }

    function compile(fname) {
        use namespace Parse;

        // reading takes almost no time, so lump it with scan+parse

        var t1 = new Date;
        var input = readFile(fname);
        var parser = new Parser( input, getTopFixtures(), fname );
        var prog = parser.program();

        // dumping takes almost no time, so lump it with cogen

        var t2 = new Date;
        var bytes = Gen::cg(prog);
        var len = dumpABCFile(bytes, fname+".abc");

        var t3 = new Date;

        print (fname);
        print ("  Scan+parse:  " + (t2 - t1) + " ms");
        print ("  Cogen:       " + (t3 - t2) + " ms");

        total_frontend += (t2 - t1);
        total_backend += (t3 - t2);
    }

    var before = new Date();
    boot();
    for ( let i=0, limit=System.argv.length ; i < limit ; i++ )
        compile(System.argv[i]);
    var after = new Date();

    if (System.argv.length > 1) {
        print("");
        print("Total time: " + (after - before));
        print("Front end:  " + total_frontend);
        print("Back end:   " + total_backend);
    }
}
