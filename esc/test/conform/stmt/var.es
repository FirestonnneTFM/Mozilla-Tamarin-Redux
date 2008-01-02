// global var
var x = "GLOBAL";
print(x);

// local var, assuming functions are working
function f() {
    var x = "LOCAL";
    print(x);
}

f();
print(x);
