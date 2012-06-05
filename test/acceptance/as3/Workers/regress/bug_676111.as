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

import flash.system.Worker;
import flash.system.WorkerDomain;
import flash.system.Promise;
import flash.net.registerClassAlias;

registerClassAlias('com.adobe.flash.xmllist', XMLList);


if (Worker.current.isPrimordial) {

    var SECTION = "concurrency";
    var VERSION = "AS3";
    var TITLE   = "Regression test for bug 677111";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var w:Worker = WorkerDomain.current.createWorkerFromPrimordial();
    var promise:Promise = w.start();
    
    function getEchoedObject(obj) {
        var echo_object_promise:Promise = promise.async.echoObject(obj);
        var result;
        try {
            result = echo_object_promise.receive();
        } catch (exception) {
            result = exception.toString();
        }
        return result;
    }

   
    var books:XML = <books>
                    <book publisher="Addison-Wesley" name="Design Patterns" />
                    <book publisher="Addison-Wesley" name="The Pragmatic Programmer" />
                    <book publisher="Addison-Wesley" name="Test Driven Development" />
                    <book publisher="Addison-Wesley" name="Refactoring to Patterns" />
                    <book publisher="O'Reilly Media" name="The Cathedral & the Bazaar" />
                    <book publisher="O'Reilly Media" name="Unit Test Frameworks" />
                </books>;
                
    var xmllist:XMLList = books.book.(@publisher == "Addison-Wesley");
    print("sanity check: simple echo(1)=1 actual:"+getEchoedObject(1));
    print("pass xmllist, should not assert in debug player");
    var echoed = getEchoedObject(xmllist);

    AddTestCase("XMLList data is echoed from worker",echoed,xmllist);
    AddTestCase("XMLList data returned is type XMLList",true,echoed is XMLList);
    
    test();
    w.terminate();
   
    
} else {
    // worker
    public function echoObject(o) {
        return o;
    }
}

}