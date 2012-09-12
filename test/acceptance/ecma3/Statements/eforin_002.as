/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "forin-002";
    var VERSION = "ECMA_2";
    var TITLE   = "The for...in  statement";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    function MyObject( value ) {
        this.value = value;
    this.valueOf = function(){return this.value;}
        this.toString = function(){return this.value + '';}
        this.toNumber = function(){return this.value + 0;}
        this.toBoolean = function(){return Boolean( this.value );}
    }

    var resultArray = new Array( "value", "valueOf", "toString", "toNumber", "toBoolean" );

    //ForIn_1(this);
    //ForIn_2(this);

    ForIn_1(new MyObject(true));
    ForIn_2(new MyObject(true));
    //ForIn_2(new MyObject(new Boolean(true)));

    //ForIn_2(3);

    function ForIn_1( object) {
        var tcValue = item+0;
        var tcValueOf = item+1;
        var tcString = item+2;
        var tcNumber = item+3;
        var tcBoolean = item+4;

        var index = 0;
        with ( object ) {
            for ( property in object ) {
                switch( property ){
                    case "value":
                        array[tcValue] = new TestCase(
                            SECTION,
                            "for...in loop in a with loop.  ("+object+")["+property +"] == "+
                             property,
                            true,
                            property == resultArray[0] );
                        item++;
                        break;

                    case "valueOf":
                        array[tcValueOf] = new TestCase(
                            SECTION,
                            "for...in loop in a with loop.  ("+object+")["+property +"] == "+
                             property,
                            true,
                            property == resultArray[1] );
                        item++;
                        break;

                    case "toString":
                        array[tcString] = new TestCase(
                            SECTION,
                            "for...in loop in a with loop.  ("+object+")["+property +"] == "+
                             property,
                            true,
                            property == resultArray[2] );
                        item++;
                        break;

                    case "toNumber":
                        array[tcNumber] = new TestCase(
                            SECTION,
                            "for...in loop in a with loop.  ("+object+")["+property +"] == "+
                             property,
                            true,
                            property == resultArray[3] );
                        item++;
                        break;

                    case "toBoolean":
                        array[tcBoolean] = new TestCase(
                            SECTION,
                            "for...in loop in a with loop.  ("+object+")["+property +"] == "+
                             property,
                            true,
                            property == resultArray[4] );
                        item++;
                        break;


                }
            }
        }
    }

    function ForIn_2(object) {
        var tcValue = item+0;
        var tcValueOf = item+1;
        var tcString = item+2;
        var tcNumber = item+3;
        var tcBoolean = item+4;

        var index = 0
        for ( property in object ) {
            with ( object ) {
                switch( property ){
                    case "value":
                        array[tcValue] = new TestCase(
                            SECTION,
                            "with loop in a for...in loop.  ("+object+")["+property +"] == "+
                                property,
                            true,
                            property == resultArray[0] );
                        item++;
                        break;

                    case "valueOf":
                        array[tcValueOf] = new TestCase(
                            SECTION,
                            "with loop in a for...in loop.  ("+object+")["+property +"] == "+
                                property,
                            true,
                            property == resultArray[1] );
                        item++;
                        break;

                    case "toString":
                        array[tcString] = new TestCase(
                            SECTION,
                            "with loop in a for...in loop.  ("+object+")["+property +"] == "+
                                property,
                            true,
                            property == resultArray[2] );
                        item++;
                        break;

                    case "toNumber":
                        array[tcNumber] = new TestCase(
                            SECTION,
                            "with loop in a for...in loop.  ("+object+")["+property +"] == "+
                                property,
                            true,
                            property == resultArray[3] );
                        item++;
                        break;

                    case "toBoolean":
                        array[tcBoolean] = new TestCase(
                            SECTION,
                            "with loop in a for...in loop.  ("+object+")["+property +"] == "+
                                property,
                            true,
                            property == resultArray[4] );
                        item++;
                        break;
                }

            }
        }
    }
    return array;
}
