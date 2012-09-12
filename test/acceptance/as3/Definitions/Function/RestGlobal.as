/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

function myRest( ... rest ):int{
    return rest.length;
}

AddTestCase ("myRest( ... rest) called with zero Args", 0, myRest() );
AddTestCase ("myRest( ... rest) called with one Arg", 1, myRest(1) );
AddTestCase ("myRest( ... rest) called with multiple Args", 4, myRest(1,2,3,4) );
AddTestCase ("myRest( ... rest) called with multiple different Args", 4, myRest(1,"2",false,Number.NaN) );

anon_myRest = function ( ... rest):int {
    return rest.length;
}

AddTestCase ("anon_myRest( ... rest) called with zero Args", 0, anon_myRest() );
AddTestCase ("anon_myRest( ... rest) called with one Arg", 1, anon_myRest(1) );
AddTestCase ("anon_myRest( ... rest) called with multiple Args", 4, anon_myRest(1,2,3,4) );
AddTestCase ("anon_myRest( ... rest) called with multiple different Args", 4, anon_myRest(1,"2",false,Number.NaN) );

function foo(){}
var resArray:Array = [foo, new Array().toString(),-1,2,"3",true,undefined,null,Number.NaN];
function myRest2( a:Array, ... cust):Boolean {
    if( cust.length > 0 ){
        for( var i:int = 0; i < cust.length; i++ ){
            AddTestCase( "myRest2( a:Array, ... cust)", resArray[i], cust[i] );
        }
        return true;
    } else {
        return false;
    }
}

if( !myRest2( new Array(),foo, new Array().toString(),-1,2,"3",true,undefined,null,Number.NaN )){
    AddTestCase("ERROR", 0, 1);
}


test();
