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

    import flash.concurrent.Mutex;
    import flash.concurrent.Condition;    

    var SECTION = "Workers";
    var VERSION = "as3";
    var TITLE   = "Condition and Mutex API";
    startTest();
    writeHeaderToLog(SECTION+" "+TITLE);

    var mutex=null;
    mutex=new Mutex();
    AddTestCase("create Mutex object, assert is not null",true,mutex!=null);
    var exception:String="";
    try {
        mutex.lock();
        mutex.unlock();
        mutex.lock();
        mutex.unlock();
        mutex.lock();
        mutex.lock();
        mutex.unlock();
        mutex.unlock();
    } catch(e) {
        exception=e.toString();
    }
    AddTestCase("locking and unlocking Mutex did not throw any exceptions","",exception);
    var trylock:Boolean=mutex.tryLock();
    AddTestCase("tryLock succeeded",trylock,true);
    mutex.unlock();

    exception="";
    var i:uint=0;
    try {
        for (i=0;i<1025;i++) {
            mutex.lock();
        }
    } catch (e) {
        exception=e.toString();
    }
    AddTestCase("Mutex lock throws does not throw exception when 1025 mutex locks happen","",exception);

    mutex=new Mutex();
    mutex.lock();
    var condition:Condition;

    exception="";
    try {
        condition=new Condition(null);
    } catch (e) {
        exception=e.toString();
    }
    AddTestCase("Condition with no mutex throws ArgumentError","ArgumentError: Error #2007",exception.substring(0,"ArgumentError: Error #2007".length));

    mutex=new Mutex();
    condition=new Condition(mutex);
    AddTestCase("Condition has getter mutex",mutex,condition.mutex);
    condition.mutex.lock();
    var notifyRes=condition.notify();
    var notifyAllRes=condition.notifyAll();
    AddTestCase("Condition notify and notifyAll returns immediately on same worker",true,notifyRes==null && notifyAllRes==null);
    var waitRes:Boolean;
    waitRes=condition.wait(1);
    AddTestCase("Condition wait times out when notify and notifyAll were called previously",false,waitRes);

    mutex=new Mutex();
    condition=new Condition(mutex);
    mutex.lock();
    waitRes=condition.wait(1);
    AddTestCase("Condition wait times out with no notify",false,waitRes);

    exception="";
    mutex=new Mutex();
    condition=new Condition(mutex);

    try {
        condition.notify();
    } catch (e) {
        exception=e.toString();
    }
    AddTestCase("Condition.notify() without owning the lock to the mutex throws an exception","Error: Error #1516",exception.substring(0,"Error: Error #1516".length));

    try {
        condition.notifyAll();
    } catch (e) {
        exception=e.toString();
    }
    AddTestCase("Condition.notifyAll() without owning the lock to the mutex throws an exception","Error: Error #1517",exception.substring(0,"Error: Error #1517".length));

    try {
        condition.wait();
    } catch (e) {
        exception=e.toString();
    }
    AddTestCase("Condition.wait() without owning the lock to the mutex throws an exception","Error: Error #1518",exception.substring(0,"Error: Error #1518".length));

    test();
 }