/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

 

import MultipleCatchBlocks2.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Testing try block with multiple catch blocks";  // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


var z = new MyErrors2();
thisError = "no error";
thisError1 = "no error";
thisError2 = "no error";
thisError3 = "no error";
thisError4 = "no error";
thisError5 = "no error";
thisError6 = "no error";
thisError7 = "no error";
try {
    z.MyArgumentError();
    }catch(e:ReferenceError){
          thisError=(e.toString()).substr(0,26);//print(thisError);
    }catch(e1:TypeError){
          thisError1=(e1.toString()).substr(0,26);//print(thisError1);
    }catch(e2:ArgumentError){
          thisError2=(e2.toString()).substr(0,26);//print(thisError2);
    }catch(e3:URIError){
          thisError3=(e3.toString()).substr(0,26);//print(thisError3);
    }catch(e4:UninitializedError){
          thisError4=(e4.toString()).substr(0,26);//print(thisError4);
    }catch(e5:EvalError){
          thisError5=(e5.toString()).substr(0,26);//print(thisError5);
    }catch(e6:RangeError){
          thisError6=(e6.toString()).substr(0,26);//print(thisError6);
    }catch(e7:Error){
          thisError7=(e7.toString()).substr(0,26);//print(thisError7);
    }finally{
AddTestCase( "Testing catch block with Reference Error", "no error" ,thisError);
AddTestCase( "Testing catch block with Type Error", "no error" ,thisError1);
AddTestCase( "Testing catch block with Argument Error", "ArgumentError: Error #1063",thisError2);
AddTestCase( "Testing catch block with URIError", "no error" ,thisError3);
AddTestCase( "Testing catch block with Eval Error", "no error" ,thisError5);
AddTestCase( "Testing catch block with Range Error", "no error" ,thisError6);
AddTestCase( "Testing catch block with Error", "no error" ,thisError7);
            }

test();       // leave this alone.  this executes the test cases and
              // displays results.
