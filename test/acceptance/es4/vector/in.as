/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/**
   File Name:    in.es
   Description:  test 'in' keyword.
   		 the exception is a current issue with properties defined in the prototype.
   Author:       dschaffe@adobe.com 27-Aug-2007
   *
   */

var SECTION = " ";
var VERSION = "AS3";
startTest();
writeHeaderToLog( SECTION + " Vector in statement");

var v1:Vector.<*>=new Vector.<*>();
var v2:Vector.<int>=Vector.<int>(["zero","one","two","three","four","five"]);
AddTestCase(    "in value valid index",
		true,
		(0 in v2));
AddTestCase(    "in value for empty vector",
		false,
		(0 in v1));

AddTestCase(    "in value valid index does not exist",
		false,
		(6 in v1));

AddTestCase(    "in value valid index in string form",
		true,
		("2" in v2));

err1="no exception";
try {
AddTestCase(    "in value is push function index ",
		true,
		("push" in v1));
AddTestCase(    "in value is concat function index ",
		true,
		("concat" in v1));
AddTestCase(    "in value negative number index ",
		false,
		(-2 in v1));
AddTestCase(    "in value decimal index",
		false,
		(1.1 in v1));
AddTestCase(    "in value decimal in string index",
		false,
		("1.1" in v1));
AddTestCase(    "in value valid string",
		false,
		("string" in v1));
} catch(e) {
  err1=e.toString();
  AddTestCase(    "in throws exception for invalid vector indexes",
                  "no exception",
                  err1);
}

test();

