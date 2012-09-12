/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

   var SECTION = "15.9.5.3";
   var VERSION = "ECMA_3";
   var TITLE   = "Date.prototype.toDateString()";
   
   var status = '';
   var actual = '';
   var expect = '';


   startTest();
   writeHeaderToLog( SECTION + " "+ TITLE);


//-----------------------------------------------------------------------------------------------------
   var testcases = getTestCases();
//-----------------------------------------------------------------------------------------------------

    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

   // first, some generic tests -

   status = "typeof (now.toDateString())";
   actual =   typeof (now.toDateString());
   expect = "string";
   array[item++] = new TestCase(SECTION, status, expect, actual);

   status = "Date.prototype.toDateString.length";
   actual =  Date.prototype.toDateString.length;
   expect =  0;
   array[item++] = new TestCase(SECTION, status, expect, actual);

   /* Date.parse is accurate to the second;  valueOf() to the millisecond.
        Here we expect them to coincide, as we expect a time of exactly midnight -  */
   status = "(Date.parse(now.toDateString()) - (midnight(now)).valueOf()) == 0";
   actual =   (Date.parse(now.toDateString()) - (midnight(now)).valueOf()) == 0;
   expect = true;
   array[item++] = new TestCase(SECTION, status, expect, actual);



   // 1970
   addDateTestCase(0);
   addDateTestCase(TZ_ADJUST);

   
   // 1900
   addDateTestCase(TIME_1900);
   addDateTestCase(TIME_1900 - TZ_ADJUST);

   
   // 2000
   addDateTestCase(TIME_2000);
   addDateTestCase(TIME_2000 - TZ_ADJUST);

    
   // 29 Feb 2000
   //var UTC_29_FEB_2000=946684800000+31*86400000+28*86400000;
   addDateTestCase(UTC_29_FEB_2000);

   addDateTestCase(UTC_29_FEB_2000 - 1000);
   addDateTestCase(UTC_29_FEB_2000 - TZ_ADJUST);
 

   // 2005
   //var    msPerDay =86400000;
   //var    TIME_2000    = 946684800000;
   //UTC_1_JAN_2005 = TIME_2000 + TimeInYear(2000) + TimeInYear(2001) +
       //TimeInYear(2002) + TimeInYear(2003) + TimeInYear(2004);
   /*function DaysInYear( y ) {
    if ( y % 4 != 0 ) {
        return 365;
    }
    if ( (y % 4 == 0) && (y % 100 != 0) ) {
        return 366;
    }
    if ( (y % 100 == 0) &&  (y % 400 != 0) ) {
        return 365;
    }
    if ( (y % 400 == 0) ){
        return 366;
    } else {
        return "ERROR: DaysInYear(" + y + ") case not covered";
    }
}
   function TimeInYear( y ) {
    return ( DaysInYear(y) * msPerDay );
   }*/
    addDateTestCase(UTC_1_JAN_2005);
    addDateTestCase(UTC_1_JAN_2005 - 1000);
    addDateTestCase(UTC_1_JAN_2005 - TZ_ADJUST);
   
    function addTestCase()
    {
      array[item++] = new TestCase( SECTION, status, expect, actual);
    }
    
    
    function addDateTestCase(date_given_in_milliseconds)
    {
      var givenDate = new Date(date_given_in_milliseconds);
    
      status = 'Date.parse(   +   givenDate   +   ).toDateString())';
      actual =  Date.parse(givenDate.toDateString());
      expect = Date.parse(midnight(givenDate));
      addTestCase();
    }
    return array;
}

function midnight(givenDate)
{
  // midnight on the given date -
  return new Date(givenDate.getFullYear(), givenDate.getMonth(), givenDate.getDate());
}
