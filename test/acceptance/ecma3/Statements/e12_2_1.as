/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "12.2-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The variable statement";

    writeHeaderToLog( SECTION +" "+ TITLE);

    var testcases = getTestCases();
    
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var x = 3;
    function f() { var a = x; x = 23; return a; }

    array[item++] = new TestCase(    "SECTION",
                                    "var x = 3; function f() { var a = x; var x = 23; return a; }; f()",3,f() );

    array[item++] = new TestCase(    "SECTION",
                                    "var x created with global scope with property attribute {DontDelete}",false,delete x);

    array[item++] = new TestCase(    "SECTION",
                                    "var x created with global scope with property attribute {DontDelete}",23,x);
  
    function g(){
        var y = 20;
    }
    var thisError="no error";
    try{
        y++;
   
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++] = new TestCase(    "SECTION",
                                    "var y created with function scope","ReferenceError: Error #1065",referenceError(thisError));
    }

    function h(){
        var i;
        return i;
    }
 
    array[item++] = new TestCase(    "SECTION",
                                    "undefined variables created with function scope",undefined,h());

    function MyFunction(){
        var myvar1:int=10,myvar2:int=20,myvar3:int;
        myvar3=myvar1+myvar2;
        return myvar3;
    }
 
    array[item++] = new TestCase(    "SECTION",
                                    "variables created with function scope and assigned with values",30,MyFunction());

   
    var l,m,n;

    array[item++] = new TestCase(    "SECTION",
                                    "undefined variables",undefined,l);

    array[item++] = new TestCase(    "SECTION",
                                    "undefined variables",undefined,m);

    array[item++] = new TestCase(    "SECTION",
                                    "undefined variables",undefined,n);
    var t;var u;var v;

    array[item++] = new TestCase(    "SECTION",
                                    "undefined variables",undefined,t);

    array[item++] = new TestCase(    "SECTION",
                                    "undefined variables",undefined,u);

    array[item++] = new TestCase(    "SECTION",
                                    "undefined variables",undefined,v);

    v=u;

    array[item++] = new TestCase(    "SECTION",
                                    "undefined variables",undefined,v);
    v=x;

    array[item++] = new TestCase(    "SECTION",
                                    "variable assigned with value when the variable statement is executed",23,v);

    var d:Number=100,b:Array=new Array(1,2,3),k:Boolean=true,gg:String="string";

    array[item++] = new TestCase(    "SECTION",
                                    "variable assigned with value when the variable statement is executed",100,d);

    array[item++] = new TestCase(    "SECTION",
                                    "variable assigned with value when the variable statement is executed","1,2,3",b+"");

    array[item++] = new TestCase(    "SECTION",
                                    "variable assigned with value when the variable statement is executed",true,k);
   
    array[item++] = new TestCase(    "SECTION",
                                    "variable assigned with value when the variable statement is executed","string",gg);
    return array;
}
