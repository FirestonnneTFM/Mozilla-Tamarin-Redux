/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.10.6.3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "RegExp.prototype.test(string)"
    writeHeaderToLog( SECTION + TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var string = "mystring"

    array[item++] = new TestCase( SECTION,
                                "01 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                RegExp.prototype.test(string) );

    var regexp = new RegExp("a|ab");
    var string = 'abc'

    array[item++] = new TestCase( SECTION,
                                "02 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (regexp.test(string)) );

    var regexp = new RegExp("d|ef");
    var string = 'abc'

    array[item++] = new TestCase( SECTION,
                                "03 ( RegExp.prototype.test(" + string + "))",
                                false ,
                                (regexp.test(string)) );


    var pattern = /((a)|(ab))((c)|(bc))/;
    var string = 'abc';

    array[item++] = new TestCase( SECTION,
                                "04 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );

     var pattern = /a[a-z]{2,4}/;
    var string = 'abcdefghi';

    array[item++] = new TestCase( SECTION,
                                "05 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );

    var pattern = /a[a-z]{2,4}?/;
    var string = 'abcdefghi';

    array[item++] = new TestCase( SECTION,
                                "06 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );

    var pattern = /(aa|aabaac|ba|b|c)*/;
    var string = 'aabaac';

    array[item++] = new TestCase( SECTION,
                                "07 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );

    var pattern = /^(a+)\1*,\1+$/;
    var string = 'aaaaaaaaaa,aaaaaaaaaaaaaaa';

    array[item++] = new TestCase( SECTION,
                                "08 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );

    var pattern = /(z)((a+)?(b+)?(c))*/;
    var string = 'zaacbbbcac';

    array[item++] = new TestCase( SECTION,
                                "09 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );

     var pattern = /(a*)*/;
    var string = 'b';

    array[item++] = new TestCase( SECTION,
                                "10 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );

     var pattern = /(a*)b\1+/;
    var string = 'baaaac';

    array[item++] = new TestCase( SECTION,
                                "11 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );

    var pattern = /(?=(a+))/;
    var string = 'baaabac';

    array[item++] = new TestCase( SECTION,
                                "12 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );

     var pattern = /(?=(a+))a*b\1/;
    var string = 'baaabac';

    array[item++] = new TestCase( SECTION,
                                "13 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );





    var pattern = /(.*?)a(?!(a+)b\2c)\2(.*)/;
    var string = 'baaabac';

    array[item++] = new TestCase( SECTION,
                                "14 ( RegExp.prototype.test(" + string + "))",
                                true ,
                                (pattern.test(string)) );






    return ( array );
}
