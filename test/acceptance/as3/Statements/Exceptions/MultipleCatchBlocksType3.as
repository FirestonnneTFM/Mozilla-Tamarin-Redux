/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Testing try block with multiple catch blocks, the third catch block catching the type error";  // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


thisError = "no error";
       
try {
     throw new TypeError();
    } catch(e:ReferenceError){
       thisError="This is Reference Error";
    }catch(e1:ArgumentError){
       thisError="This is Argument Error";
    }catch(e2:TypeError){
       thisError="This is Type Error";
    }catch(e3:URIError){
       thisError="This is URI Error"
    }catch(e4:EvalError){
       thisError="This is Eval Error";
    }catch(e5:RangeError){
       thisError="This is Range Error";
    }catch(e6:SecurityError){
       thisError="This is Security Error!!!";
    }catch(e7:Error){
      thisError = "This is an error";
    }finally{
       AddTestCase( "Testing try block with throw statement", "This is Type Error"        ,thisError);
     }


test();       // leave this alone.  this executes the test cases and
              // displays results.
