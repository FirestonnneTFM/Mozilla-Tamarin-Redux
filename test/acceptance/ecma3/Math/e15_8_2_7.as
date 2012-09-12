/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8.2.7";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.cos(x)";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "Math.cos.length",       1,                      Math.cos.length );
  /*thisError="no error";
    try{
        Math.cos();
    }catch(e:Error){
        thisError=(e.toString()).substring(0,26);
    }finally{//print(thisError);
        array[item++] = new TestCase( SECTION,   "Math.cos()","ArgumentError: Error #1063",thisError);
    }
    array[item++] = new TestCase( SECTION, "Math.cos()",            Number.NaN,             Math.cos() );*/
    array[item++] = new TestCase( SECTION, "Math.cos(void 0)",      Number.NaN,             Math.cos(void 0) );
    array[item++] = new TestCase( SECTION, "Math.cos(false)",       1,                      Math.cos(false) );
    array[item++] = new TestCase( SECTION, "Math.cos(null)",        1,                      Math.cos(null) );

    array[item++] = new TestCase( SECTION, "Math.cos('0')",         1,                      Math.cos('0') );
    array[item++] = new TestCase( SECTION, "Math.cos('Infinity')",  Number.NaN,             Math.cos("Infinity") );
    array[item++] = new TestCase( SECTION, "Math.cos('3.14159265359')",  -1,                 Math.cos('3.14159265359') );

    array[item++] = new TestCase( SECTION, "Math.cos(NaN)",          Number.NaN,             Math.cos(Number.NaN)        );
    array[item++] = new TestCase( SECTION, "Math.cos(0)",            1,                      Math.cos(0)                 );
    array[item++] = new TestCase( SECTION, "Math.cos(-0)",           1,                      Math.cos(-0)                );
    array[item++] = new TestCase( SECTION, "Math.cos(Infinity)",     Number.NaN,             Math.cos(Number.POSITIVE_INFINITY) );
    array[item++] = new TestCase( SECTION, "Math.cos(-Infinity)",    Number.NaN,             Math.cos(Number.NEGATIVE_INFINITY) );
    array[item++] = new TestCase( SECTION, "Math.cos(0.7853981633974)", 0.7071067811865817,    Math.cos(0.7853981633974)   );
    array[item++] = new TestCase( SECTION, "Math.cos(1.570796326795)",   -1.0341155557737347e-13,                  Math.cos(1.570796326795)    );
    array[item++] = new TestCase( SECTION, "Math.cos(2.356194490192)",  -0.7071067811863034,   Math.cos(2.356194490192)    );
    array[item++] = new TestCase( SECTION, "Math.cos(3.14159265359)",   -1,                 Math.cos(3.14159265359)     );
    array[item++] = new TestCase( SECTION, "Math.cos(3.926990816987)",  -0.7071067811867184,   Math.cos(3.926990816987)    );
    array[item++] = new TestCase( SECTION, "Math.cos(4.712388980385)",  3.0979057752227035e-13,                  Math.cos(4.712388980385)    );
    array[item++] = new TestCase( SECTION, "Math.cos(5.497787143782)",  0.70710678118645,    Math.cos(5.497787143782)    );
    array[item++] = new TestCase( SECTION, "Math.cos(Math.PI*2)",       1,                  Math.cos(Math.PI*2)         );
    array[item++] = new TestCase( SECTION, "Math.cos(Math.PI/4)",       Math.SQRT2/2,       Math.cos(Math.PI/4)         );
    array[item++] = new TestCase( SECTION, "Math.cos(Math.PI/2)",       6.123031769111886e-17,                  Math.cos(Math.PI/2)         );
    array[item++] = new TestCase( SECTION, "Math.cos(3*Math.PI/4)",     -0.7071067811865475,      Math.cos(3*Math.PI/4)       );
    array[item++] = new TestCase( SECTION, "Math.cos(Math.PI)",         -1,                 Math.cos(Math.PI)           );
    array[item++] = new TestCase( SECTION, "Math.cos(5*Math.PI/4)",     -0.7071067811865477,      Math.cos(5*Math.PI/4)       );
    array[item++] = new TestCase( SECTION, "Math.cos(3*Math.PI/2)",     -1.836909530733566e-16,                  Math.cos(3*Math.PI/2)       );
    array[item++] = new TestCase( SECTION, "Math.cos(7*Math.PI/4)",     0.7071067811865474,       Math.cos(7*Math.PI/4)       );
    array[item++] = new TestCase( SECTION, "Math.cos(Math.PI*2)",       1,                  Math.cos(2*Math.PI)         );
    array[item++] = new TestCase( SECTION, "Math.cos(-0.7853981633974)",    0.7071067811865817,    Math.cos(-0.7853981633974)  );
    array[item++] = new TestCase( SECTION, "Math.cos(-1.570796326795)", -1.0341155557737347e-13,                  Math.cos(-1.570796326795)   );
    array[item++] = new TestCase( SECTION, "Math.cos(-2.3561944901920)",    -0.7071067811863034,    Math.cos(2.3561944901920)   );
    array[item++] = new TestCase( SECTION, "Math.cos(-3.14159265359)",  -1,                 Math.cos(3.14159265359)     );
    array[item++] = new TestCase( SECTION, "Math.cos(-3.926990816987)", -0.7071067811867184,   Math.cos(3.926990816987)    );
    array[item++] = new TestCase( SECTION, "Math.cos(-4.712388980385)", 3.0979057752227035e-13,                  Math.cos(4.712388980385)    );
    array[item++] = new TestCase( SECTION, "Math.cos(-5.497787143782)", 0.70710678118645,    Math.cos(5.497787143782)    );
    array[item++] = new TestCase( SECTION, "Math.cos(-6.28318530718)",  1,                  Math.cos(6.28318530718)     );
    array[item++] = new TestCase( SECTION, "Math.cos(-Math.PI/4)",      Math.SQRT2/2,       Math.cos(-Math.PI/4)        );
    array[item++] = new TestCase( SECTION, "Math.cos(-Math.PI/2)",      6.123031769111886e-17,                  Math.cos(-Math.PI/2)        );
    array[item++] = new TestCase( SECTION, "Math.cos(-3*Math.PI/4)",        -0.7071067811865475,      Math.cos(-3*Math.PI/4)      );
    array[item++] = new TestCase( SECTION, "Math.cos(-Math.PI)",            -1,                 Math.cos(-Math.PI)          );
    array[item++] = new TestCase( SECTION, "Math.cos(-5*Math.PI/4)",        -0.7071067811865477,      Math.cos(-5*Math.PI/4)      );
    array[item++] = new TestCase( SECTION, "Math.cos(-3*Math.PI/2)",        -1.836909530733566e-16,                  Math.cos(-3*Math.PI/2)      );
    array[item++] = new TestCase( SECTION, "Math.cos(-7*Math.PI/4)",        0.7071067811865474,       Math.cos(-7*Math.PI/4)      );
    array[item++] = new TestCase( SECTION, "Math.cos(-Math.PI*2)",      1,                  Math.cos(-Math.PI*2)        );

    return ( array );
}
