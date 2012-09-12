/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "11.1.5";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "Object Initialisers";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    MyObject = {}
    array[item++] = new TestCase( SECTION,  "MyObject = {}",    "[object Object]",  MyObject.toString() );

    array[item++] = new TestCase( SECTION,  "MyObject = {}, typeof MyObject","object",typeof MyObject );

    MyNumberObject = {MyNumber:10}

    array[item++] = new TestCase( SECTION,  "MyNumberObject = {MyNumber:10}",10,MyNumberObject.MyNumber );

    MyStringObject = {MyString:"string"}

    array[item++] = new TestCase( SECTION,  "MyStringObject = {MyString:string}","string",MyStringObject.MyString );

    MyBooleanObject = {MyBoolean:true}

    array[item++] = new TestCase( SECTION,  "MyBooleanObject = {MyBoolean:true}",true,MyBooleanObject.MyBoolean );

    function myfunc():String{
        return "Hi!!!"}

    MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}

    array[item++] = new TestCase( SECTION,  "MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}",10,MyObject2.MyNumber );

    

    array[item++] = new TestCase( SECTION,  "MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}","string",MyObject2.MyString );

    

    array[item++] = new TestCase( SECTION,  "MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}",true,MyObject2.MyBoolean );

    array[item++] = new TestCase( SECTION,  "MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}","number",typeof MyObject2.MyNumber );

    

    array[item++] = new TestCase( SECTION,  "MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}","string",typeof MyObject2.MyString );

    

    array[item++] = new TestCase( SECTION,  "MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}","boolean",typeof MyObject2.MyBoolean );

    array[item++] = new TestCase( SECTION,  "MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}",3,MyObject2.myarr.length );
    

   array[item++] = new TestCase( SECTION,  "MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}","object",typeof MyObject2.myarr );

   array[item++] = new TestCase( SECTION,  "MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}","Hi!!!",MyObject2.myfuncvar() );

  array[item++] = new TestCase( SECTION,  "MyObject2 = {MyNumber:10,MyString:'string',MyBoolean:true,myarr:[1,2,3],myfuncvar:myfunc}","function",typeof MyObject2.myfuncvar );
    
    
    MyObject3 = {myvar:this}

    array[item++] = new TestCase( SECTION,  "MyObject3 = {this}","object",typeof MyObject3.myvar);

    array[item++] = new TestCase( SECTION,  "MyObject3 = {this}","[object global]",MyObject3.myvar+"");

   MyObject4 = {myvar:function() {}}

   array[item++] = new TestCase( SECTION,  "MyObject4 = {myvar:function() {}}","function",typeof MyObject4.myvar);

   array[item++] = new TestCase( SECTION,  "MyObject4 = {myvar:function() {}}","function Function() {}",MyObject4.myvar+"");

   array[item++] = new TestCase( SECTION,  "MyObject4 = {myvar:function() {}}","function Function() {}",MyObject4.myvar.toString());

   

   
   return ( array );
}

function MyObject( value ) {
    this.value = function() {return this.value;}
    this.toString = function() {return this.value+'';}
}
