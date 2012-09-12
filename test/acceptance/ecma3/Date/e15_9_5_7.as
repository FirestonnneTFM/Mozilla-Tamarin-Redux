/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
//-----------------------------------------------------------------------------
var SECTION = "15.9.5.7";
var VERSION = "ECMA_3";
var TITLE   = "Date.prototype.toLocaleTimeString()";

var status = '';
var actual = '';
var expect = '';
var givenDate;
var year = '';
var regexp = '';
var TimeString = '';
var reducedDateString = '';
var hopeThisIsLocaleTimeString = '';
var cnERR ='OOPS! FATAL ERROR: no regexp match in extractLocaleTimeString()';


startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


//-----------------------------------------------------------------------------------------------------
   var testcases = getTestCases();
//-----------------------------------------------------------------------------------------------------
test();


function getTestCases() {
    var array = new Array();
    var item = 0;
    // first, a couple generic tests -

    status = "typeof (now.toLocaleTimeString())";
    actual =   typeof (now.toLocaleTimeString());
    expect = "string";
    array[item++] = new TestCase(SECTION, status, expect, actual);
    

    status = "Date.prototype.toLocaleTimeString.length";
    actual =  Date.prototype.toLocaleTimeString.length;
    expect =  0;
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
    addDateTestCase(UTC_29_FEB_2000);
    addDateTestCase(UTC_29_FEB_2000 - 1000);
    addDateTestCase(UTC_29_FEB_2000 - TZ_ADJUST);


    // Now
    addDateTestCase( TIME_NOW);
    addDateTestCase( TIME_NOW - TZ_ADJUST);


    // 2005
    addDateTestCase(UTC_1_JAN_2005);
    addDateTestCase(UTC_1_JAN_2005 - 1000);
    addDateTestCase(UTC_1_JAN_2005 - TZ_ADJUST);

    
    
    function addTestCase()
    {
      array[item++] = new TestCase( SECTION, status, expect, actual);
    }


    function addDateTestCase(date_given_in_milliseconds)
    {
       givenDate = new Date(date_given_in_milliseconds);
       
       status = '().toLocaleTimeString()';
       
       
       actual = cnERR;
       expect = extractLocaleTimeString(givenDate);
       
       addTestCase();
    }
    return array;
}

/*
 * As of 2002-01-07, the format for JavaScript dates changed.
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=118266 (SpiderMonkey)
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=118636 (Rhino)
 *
 * WAS: Mon Jan 07 13:40:34 GMT-0800 (Pacific Standard Time) 2002
 * NOW: Mon Jan 07 2002 13:40:34 GMT-0800 (Pacific Standard Time)
 *
 * So first, use a regexp of the form /date.toDateString()(.*)$/
 * to capture the TimeString into the first backreference.
 *
 * Then remove the GMT string from TimeString (see introduction above)
 */
function extractLocaleTimeString(date)
{
  regexp = new RegExp(date.toDateString() + '(.*)' + '$');
  try
  {
    TimeString = date.toString().match(regexp)[1];
  }
  catch(e)
  {
    return cnERR;
  }

  /*
   * Now remove the GMT part of the TimeString.
   * Guard against dates with two "GMT"s, like:
   * Jan 01 00:00:00 GMT+0000 (GMT Standard Time)
   */
  regexp= /([^G]*)GMT.*/;
  try
  {
    hopeThisIsLocaleTimeString = TimeString.match(regexp)[1];
  }
  catch(e)
  {
    return TimeString;
  }

  // trim any leading or trailing spaces -
  return trimL(trimR(hopeThisIsLocaleTimeString));
}


function trimL(s)
{
  if (!s) {return cnEmptyString;};
  for (var i = 0; i!=s.length; i++) {if (s[i] != ' ') {break;}}
  return s.substring(i);
}


function trimR(s)
{
  for (var i = (s.length - 1); i!=-1; i--) {if (s[i] != ' ') {break;}}
  return s.substring(0, i+1);
}
