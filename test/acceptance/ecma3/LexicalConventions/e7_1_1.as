/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "7.1-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "White Space";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;

    // whitespace between var reserved word and identifier
    array[item++] = new TestCase( SECTION, "Testing white space","var MYVAR1=10",'var'+' '+'MYVAR1'+'='+'10');

    // No-breakspace between var reserved word and identifier
    //array[item++] = new TestCase( SECTION,  "Testing No break space","var-·MYVAR1=10" ,'var'+'\u00A0'+'MYVAR1=10;MYVAR1');


    // tab between var  reserved word and identifier
	var		MYVAR1=10;
    array[item++] = new TestCase( SECTION,  'var'+'\t'+'MYVAR1=10;MYVAR1',   10, MYVAR1 );

	// newline between var reserved word and identifier
	var
MYVAR2=10;
    array[item++] = new TestCase( SECTION,  'var'+'\n'+'MYVAR2=10;MYVAR2',   10, MYVAR2 );
   
    //backspace between var reserved word and   Result should be vaMYVAR2=10;MYVAR2 = 10     //PASSED!
    array[item++] = new TestCase( SECTION,  'var'+'\b'+'MYVAR2=10;MYVAR2',   10, MYVAR2 );

    //vertical tabspace between var reserved word and identifier
    array[item++] = new TestCase( SECTION,  'var'+'\v'+'MYVAR2=10;MYVAR2',   10, MYVAR2 );

    //form feed between var reserved word and identifier
    array[item++] = new TestCase( SECTION,  'var'+'\f'+'MYVAR2=10;MYVAR2',   10, MYVAR2 );
    
    //carriage return between var reserved word and identifier
    array[item++] = new TestCase( SECTION,  'var'+'\r'+'MYVAR2=10;MYVAR2',   10, MYVAR2 );

    //double quotes between var reserved word and identifier
    array[item++] = new TestCase( SECTION,  'var'+'\"'+'MYVAR2=10;MYVAR2',   10, MYVAR2 );

    //single quote between var reserved word and identifier
    array[item++] = new TestCase( SECTION,  'var'+'\''+'MYVAR2=10;MYVAR2',   10, MYVAR2 );

    //backslash between var reserved word and identifier
    array[item++] = new TestCase( SECTION,  'var'+'\\'+'MYVAR2=10;MYVAR2',   10, MYVAR2 );

    
   
    return ( array );
}
