// Arguments not implemented at all 2007-12-21

function f(x, y, z) {
    //print("ARGUMENTS DEFINED " + arguments);
    //arguments[0] = 12;
    print("ARGUMENTS SHARING " + x);  // should be 12, not 1
    g();
}

function g() {
    //print("ARGUMENTS ON FN " + f.arguments[0]); // should be 12
    //print("ARGUMENTS CALLEE " + (arguments.callee === f) );
    arguments = 27;
    print("ARGUMENTS IS VARIABLE " + arguments);
}

f(1, 2, 3);

print("DONE");
