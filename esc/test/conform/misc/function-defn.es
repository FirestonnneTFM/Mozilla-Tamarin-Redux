print("OUTER");  // before the defn to make sure the defn is allowed

function f(x) {
    print("NESTED");  // before the defn to make sure the nested defn is OK

    function g() {
        return x;
    }

    return g; // testing that it's closed over
}
var v1 = f(10);
print("CLOSURE 1 " + v1());
var v2 = f(20);
print("CLOSURE 2 " + v2());
print("CLOSURE 1 " + v1());  // should be 10 again
print("DONE");
