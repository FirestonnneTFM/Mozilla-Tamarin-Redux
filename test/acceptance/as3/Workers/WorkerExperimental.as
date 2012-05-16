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
 * Portions created by the Initial Developer are Copyright (C) 2011
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

    import flash.system.*
    import avmplus.*

    if (Worker.current.isPrimordial) {
        var SECTION = "concurrency";
        var VERSION = "AS3";
        var TITLE   = "Test Worker experimental, not in spec functions.";
        startTest();
        writeHeaderToLog( SECTION + " "+ TITLE);

// pr is temporary
        Worker.pr("called Worker.pr()");

        var w:Worker=WorkerDomain.current.createWorkerFromPrimordial();
        var events=[]
        
        function listener(e) {
            eventMap=["empty","NEW","STARTING","RUNNING","FINISHING","STOPPED","FAILED","ABORTED","EXCEPTION"];
            events.push(""+e.target+" "+eventMap[e.previousState]+" to "+eventMap[e.currentState]);
        }
        w.addEventListener(WorkerEvent.WORKER_STATE, listener);
        var p1:Promise=w.start();
        var p2:Promise=p1.async.echo("hello");
        print(p2.receive());
        w.stop();
        Worker.handleLifecycleEvents();
        
        AddTestCase("Listener received all events",4,events.length);
        if (events.length>0) {
            AddTestCase("Listener 1st Event","[object Worker] NEW to STARTING",events[0]);
        }
        if (events.length>1) {
            AddTestCase("Listener 2nd Event","[object Worker] STARTING to RUNNING",events[1]);
        }
        if (events.length>2) {
            AddTestCase("Listener 3rd Event","[object Worker] RUNNING to FINISHING",events[2]);
        }
        if (events.length>3) {
            AddTestCase("Listener 4th Event","[object Worker] FINISHING to STOPPED",events[3]);
        }
        test();
    } else {
        public function echo(o:Object):Object {
            return o;
        }
    }
}
