/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "LexicalConventions/regexp-literals-001.js";
    var VERSION = "ECMA_2";
    var TITLE   = "Regular Expression Literals";

    startTest();

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
        
    // Regular Expression Literals may not be empty; // should be regarded
    // as a comment, not a RegExp literal.

    s = //;

    "passed";

    array[item++] = new TestCase(SECTION,
        "// should be a comment, not a regular expression literal",
        "passed",
        String(s));

    array[item++] = new TestCase(SECTION,
        "// typeof object should be type of object declared on following line",
        "passed",
        (typeof s) == "string" ? "passed" : "failed" );
    
    array[item++] = new TestCase(SECTION,
        "// should not return an object of the type RegExp",
        "passed",
        (typeof s == "object") ? "failed" : "passed" );

    

    var regexp1:RegExp = /a*b/;
    var regexp2:RegExp = /a*b/;

    array[item++] = new TestCase(SECTION,
        "Two regular expression literals should never compare as === to each other even if the two literals contents are the same",
        "failed",
        (regexp1 === regexp2) ? "passed" : "failed" );

    var regexp3:RegExp = new RegExp();

    

    array[item++] = new TestCase(SECTION,
        "creating RegExp object using new keyword",
        "true",
        ((regexp3 instanceof RegExp).toString()));

    var regexp4:RegExp = RegExp();

    array[item++] = new TestCase(SECTION,
        "creating RegExp object using new keyword",
        "true",
        ((regexp4 instanceof RegExp).toString()));
        
    return array;
}
