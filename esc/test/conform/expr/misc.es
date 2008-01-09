// this

var global = this;

function f1() {
    print("THIS GLOBAL " + (this === global));
}
f1();

var x = {}
function f2() {
    function f3() {
        print("THIS GLOBAL " + (this === global));
    }
    print("THIS X " + (this === x));
    f3();
}
x.f2 = f2;
x.f2();

// literals
print("INT " + 37);
print("DOUBLE " + 3.14159)
print("HEX " + 0xDEADBEEF);
print("STRING HELLO");
print("XESCAPE \x48\x45\x4C\x4C\x4F");
print("UESCAPE \u0048\u0045\u004C\u004C\u004F");
print("BOOL " + true);
print("BOOL " + false);
print("NULL " + null);
var y = [1,2,3];
print("ARRAY " + y);
print("ARRAY length " + y.length);
for ( i=0 ; i < 3 ; i++ )
    print("ARRAY ELEMENT " + y[i]);
var z = { x: 1, y: 2, z: 3 }
print("OBJECT " + z);
print("OBJECT x " + z.x);
print("OBJECT y " + z.y);
print("OBJECT z " + z.z);
/*
var w = /abc/g;
print("REGEXP " + w);
print("REGEXP source " + w.source);
print("REGEXP global " + w.global);
print("REGEXP multiline " + w.multiline);
print("REGEXP ignorecase " + w.ignorecase);
*/

// Functions

/*var fn = function f(n) { print("NAMED " + n); if (n > 0) f(n-1) }
fn(2);
var fn2 = function(n) { print("UNNAMED " + n); if (n > 0) fn2(n-1) }
fn2(2);
*/

// Property reference

print( "PAREN " + ( 10 ) );
print( "FIELD " + { x: 10 }.x );
print( "FIELD " + { x: 20 }["x"] );

// Call

function g(a,b,c) { return a+b+c }

print( "FN " + g(1,2,3) );

// constructor

var x = new Number;
print( "NEW cls default " + x );
var y = new Number(37);
print( "NEW cls param " + y );

function MyType(t) {
    this.t = t;
}

/* Crashes with TypeError

var z = new MyType;
print( "NEW fn default " + z.t );
var zz = new MyType(10);
print( "NEW fn param " + zz.t );

*/

// conditional

print( "?: " + (true ? "RIGHT" : "WRONG") );

print("DONE");
