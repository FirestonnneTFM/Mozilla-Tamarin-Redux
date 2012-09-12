/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "11.8.7";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The in operator";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
  
    var Array_One = new Array(0,1,2,3);

    

    array[item++] = new TestCase(   SECTION,
                                    "0 in Array_One",
                                    true,
                                    0 in Array_One);

    array[item++] = new TestCase(   SECTION,
                                    "1 in Array_One",
                                    true,
                                    1 in Array_One);

    array[item++] = new TestCase(   SECTION,
                                    "2 in Array_One",
                                    true,
                                    2 in Array_One);

    array[item++] = new TestCase(   SECTION,
                                    "3 in Array_One",
                                    true,
                                    3 in Array_One);



    array[item++] = new TestCase(   SECTION,
                                    "4 in Array_One",
                                    false,
                                    4 in Array_One);

    var Array_Two = new Array('z','y','x','w');

     array[item++] = new TestCase(   SECTION,
                                    "0 in Array_Two",
                                    true,
                                    0 in Array_Two);

    array[item++] = new TestCase(   SECTION,
                                    "1 in Array_Two",
                                    true,
                                    1 in Array_Two);

    array[item++] = new TestCase(   SECTION,
                                    "2 in Array_Two",
                                    true,
                                    2 in Array_Two);

    array[item++] = new TestCase(   SECTION,
                                    "3 in Array_Two",
                                    true,
                                    3 in Array_Two);



    array[item++] = new TestCase(   SECTION,
                                    "4 in Array_Two",
                                    false,
                                    4 in Array_Two);

    array[item++] = new TestCase(   SECTION,
                                    "a in Array_Two",
                                    false,
                                    'a' in Array_Two);

    array[item++] = new TestCase(   SECTION,
                                    "length in Array_Two",
                                    true,
                                    "length" in Array_Two);

    var myobj = {obj1:"string1",obj2:"string2"}

    array[item++] = new TestCase(   SECTION,
                                    "obj1 in myobj",
                                    true,
                                    "obj1" in myobj);

    array[item++] = new TestCase(   SECTION,
                                    "obj2 in myobj",
                                    true,
                                    "obj2" in myobj);

    function myfunc():String{
        return "Hi!!!"}

    MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}

    array[item++] = new TestCase(   SECTION,
                                    "MyNumber in MyObject2",
                                    true,
                                    "MyNumber" in MyObject2);

     array[item++] = new TestCase(   SECTION,
                                    "MyString in MyObject2",
                                    true,
                                    "MyString" in MyObject2);

     array[item++] = new TestCase(   SECTION,
                                    "MyBoolean in MyObject2",
                                    true,
                                    "MyBoolean" in MyObject2);



     array[item++] = new TestCase(   SECTION,
                                    "myarr in MyObject2",
                                    true,
                                    "myarr" in MyObject2);

     array[item++] = new TestCase(   SECTION,
                                    "myfuncvar in MyObject2",
                                    true,
                                    "myfuncvar" in MyObject2);


     var mystring1 = new String("string1");

     array[item++] = new TestCase(   SECTION,
                                    "length in mystring1",
                                    true,
                                    "length" in mystring1);

     var mystring2 = "string2";

      
      array[item++] = new TestCase(   SECTION,
                                    "length in mystring2",
                                    true,
                                    "length" in mystring2);

     MyObject3 = {MyNumber1:10,MyString1:'string',MyBoolean1:true,myarr1:[1,2,3],myfuncvar1:myfunc}

     delete MyObject3.MyNumber1;


    array[item++] = new TestCase(   SECTION,
                                    "MyNumber1 in MyObject3",
                                    false,
                                    "MyNumber1" in MyObject3);
    

     delete MyObject3.myfuncvar1;

    array[item++] = new TestCase(   SECTION,
                                    "myfuncvar1 in MyObject3",
                                    false,
                                    "myfuncvar1" in MyObject3);

    MyObject3.MyNumber1 = undefined;

    array[item++] = new TestCase(   SECTION,
                                    "MyNumber1 in MyObject3",
                                    true,
                                    "MyNumber1" in MyObject3);

    myarr3 = [0,1,2,3];

    delete myarr3[3];

    array[item++] = new TestCase(   SECTION,
                                    "3 in myarr3",
                                    false,
                                    3 in myarr3);

    myarr3[3] = undefined;

    array[item++] = new TestCase(   SECTION,
                                    "3 in myarr3",
                                    true,
                                    3 in myarr3);



    array[item++] = new TestCase(   SECTION,
                                    "PI in Math",
                                    true,
                                    "PI" in Math);

    array[item++] = new TestCase(   SECTION,
                                    "myproperty in Math",
                                    false,
                                    "myproperty" in Math);

    array[item++] = new TestCase(   SECTION,
                                    "myproperty in Object",
                                    false,
                                    "myproperty" in Object)


    

    
  
    return ( array );
}

