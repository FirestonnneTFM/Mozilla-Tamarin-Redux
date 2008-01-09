try {
    print("THROW");
    throw "Foo";
    print("WRONG");
}
catch (e) {
    print("CATCH");
}
print("DONE 1");

function f() {
    print("THROW");
    throw "Foo";
    print("WRONG");
}
try {
    f();
}
catch (e) {
    print("CATCH");
}
finally {
    print("FINALLY");
}
print("DONE 2");

try {
    try {
        f();
    }
    finally {
        print("FINALLY");
    }
}
catch (e) {
    print("CATCH");
}
print("DONE 3");
