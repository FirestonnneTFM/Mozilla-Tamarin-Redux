/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
//-----------------------------------------------------------------------------
var SECTION = "15.9.5.4";
var VERSION = "ECMA_3";
var TITLE   = "Date.prototype.toTimeString()";

var status = '';
var actual = '';
var expect = '';
var givenDate;
var year = '';
var regexp = '';
var reducedDateString = '';
var hopeThisIsTimeString = '';
var cnEmptyString = '';
var cnERR ='OOPS! FATAL ERROR: no regexp match in extractTimeString()';



startTest();

writeHeaderToLog( SECTION + " "+ TITLE);
var testcases = getTestCases();
test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    // first, a couple of generic tests -

    status = "typeof (now.toTimeString())";
    actual =   typeof (now.toTimeString());
    expect = "string";
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = "Date.prototype.toTimeString.length";
    actual =  Date.prototype.toTimeString.length;
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
       
       status = '('  +  givenDate  +  ').toTimeString()';
       actual = givenDate.toTimeString();
       expect = extractTimeString(givenDate);
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
 * Thus, use a regexp of the form /date.toDateString()(.*)$/
 * to capture the TimeString into the first backreference -
 */
function extractTimeString(date)
{
  year = date.getFullYear();
  // strip the year off date.toDateString().
  // the pattern for regexp:   /(.*)year$/
  regexp = new RegExp('(.*)' +   year  +  '$');
  reducedDateString = (date.toDateString()).match(regexp)[1];
  
  // now extract the middle of date.toString()
  // the pattern for regexp:  /reducedDateString(.*)year$/
  regexp=new RegExp( reducedDateString  +  '(.*)'  +  year  +  '$');
  hopeThisIsTimeString = (date.toString()).match(regexp)[1];
  // trim any trailing spaces -
  return trimR(hopeThisIsTimeString);
  
}




function trimL(s)
{
  if (!s) {return cnEmptyString;};
  for (var i = 0; i!=s.length; i++) {if (s.charAt(i) != ' ') {break;}}
  return s.substring(i);
}


function trimR(s)
{
  if (!s) {return cnEmptyString;};
  for (var i = (s.length - 1); i!=-1; i--) {if (s.charAt(i) != ' ') {break;}}
  return s.substring(0, i+1);
}

