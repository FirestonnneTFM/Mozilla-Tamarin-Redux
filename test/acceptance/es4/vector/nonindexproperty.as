/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/**
   File Name:    nonindexproperty.es
   Description:  Vector properties not uint will throw a runtime error.
   		 the exception is a current issue with properties defined in the prototype.
   Author:       dschaffe@adobe.com 27-Aug-2007
   *
   */

var SECTION = " ";
var VERSION = "AS3";
startTest();
writeHeaderToLog( SECTION + " Vector non-index properties");

Vector.<*>.prototype[3.14]="three";
var v1:Vector.<*>=new Vector.<*>();
v1[0]="zero";
v1["1"]="one";
v1[2.0]="two";
v1["3.0"]="three";

AddTestCase(    "standard 0 uint index",
		"zero",
		v1[0]);
AddTestCase(    "uint 1 as string index",
		"one",
		v1[1]);
AddTestCase(    "number 3.0 as string index",
		"two",
		v1[2]);
AddTestCase(    "number 2.0 index",
		"three",
		v1["3.0"]);
err1="exception not thrown";
try {
  v1[5.1]="five";
} catch(e) {
  err1=e.toString();
}
AddTestCase(    "index 5.1 throws exception because non-uint property",
		"ReferenceError: Error #1056",
		parseError(err1,"ReferenceError: Error #1056".length));
err2="exception not thrown";
try {
 v1[-6]="six";
} catch(e) {
  err2=e.toString();
}
AddTestCase(    "index -6 throws exception because non-uint property",
		"ReferenceError: Error #1056",
		parseError(err2,"ReferenceError: Error #1056".length));
err3="exception not thrown";
try {
 v1["foo"]="seven";
} catch(e) {
  err3=e.toString();
}
AddTestCase(    "index 'foo' throws exception because non-uint property",
		"ReferenceError: Error #1056",
		parseError(err3,"ReferenceError: Error #1056".length));

err4="exception not thrown";
try {
 v1["3.14"]=="seven";
} catch(e) {
  err4=e.toString();
}
AddTestCase(    "when Vector.<*>.prototype[3.14] is set throws exception because non-uint property",
		"ReferenceError: Error #1069",
		parseError(err4,"ReferenceError: Error #1056".length));

test();

