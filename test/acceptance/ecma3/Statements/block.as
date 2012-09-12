/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = '12.1';
    var VERSION = 'no version';
    startTest();
    var TITLE = 'Statement:block';

    writeHeaderToLog('Executing script: block.as');
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
    
    var t;
    Block:
    {
            var x = 3;
            var y= 5;
            t = x + y;
    
    }
    
    array[item++] = new TestCase( SECTION, "Block:{t}", 8, t);

    {
        var k = 100;
        var l = 50;
        thisError ="no error";
        try{
           t=k/l;
           t= n+10;
        }catch(e:ReferenceError){
            thisError=e.toString();
        }
        k=k+50;
            

    }

    array[item++] = new TestCase( SECTION, "Block in which exception is thrown", "ReferenceError: Error #1065", referenceError(thisError));

    array[item++] = new TestCase( SECTION, "Block in which exception is thrown",2, t);
    array[item++] = new TestCase( SECTION, "Block in which exception is thrown",150, k);
       
    return array;
}
