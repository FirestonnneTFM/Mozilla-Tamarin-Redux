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
 * Portions created by the Initial Developer are Copyright (C) 2012
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

package {
    import avmplus.*
    import flash.system.*

    var SECTION = "concurrency";
    var VERSION = "AS3";
    var TITLE = "Test Safepoints";

    startTest();

/*
 * The safepoint tests System.runInSafepoint.  When the addLine function
 * is run without safepoints the file io will write over each other and 
 * lines will be skipped.  With safepoints each write to the file will 
 * happen without interference from other workers. 
 */

    public function addLine() {
//        addLine1();  // run without safepoint writes to the file will collide
        System.runInSafepoint(addLine1);  // with with safepoint writes will not collide
    }
    public function addLine1(s:String="aa") {
        var output:String="";
        for (var i:uint=0;i<10;i++) {
            output+=s;
        }
        contents="";
        if (File.exists("test.txt")) {
            contents=File.read("test.txt");
        }
        contents+=output+'\n';
        File.write("test.txt",contents);
    }

    if (Worker.current.isPrimordial) {
        // set the test file empty before starting
        File.write('test.txt','');

        var nworkers=2;
        var workers:Array=new Array();
        var ipromises:Array=new Array();
        var rpromises:Array=new Array();
        for (var i0:uint=0;i0<nworkers;i0++) {
            workers[i0]=WorkerDomain.current.createWorkerFromPrimordial();
            ipromises[i0]=workers[i0].start();
        }
        for (var i1:uint=0;i1<nworkers;i1++) {
            for (var j:uint=0;j<10;j++) {
                rpromises[i1]=ipromises[i1].async.addLine();
            }
        }
        for (var i2:uint=0;i2<nworkers;i2++) {
            rpromises[i2].receive();
            workers[i2].stop();
        }
        contents=File.read('test.txt');
        lines=contents.split('\n');
        
        // the extra line is from the initial state
        AddTestCase("verify all writes from addLine were correctly written to the file",lines.length,nworkers*10+1);
        test();
    }
}
