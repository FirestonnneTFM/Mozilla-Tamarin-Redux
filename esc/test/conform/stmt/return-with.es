// Sanity: returing out of "with" does what it's supposed to do
var x = 20;
var obj = { x: 10 }
function f() {
    with (obj)
        return x;
}
print("SHOULD BE 10: " + f());
print("SHOULD BE 20: " + x);
print("DONE");
