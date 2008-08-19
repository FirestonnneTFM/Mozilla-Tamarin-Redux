var SECTION="";
var VERSION = "ECMA_1";

startTest();

writeHeaderToLog( " Vector.slice()");
var v1=new Vector.<String>();
AddTestCase(
		"slice no args on empty vector",
		"",
		v1.slice().toString());
test();