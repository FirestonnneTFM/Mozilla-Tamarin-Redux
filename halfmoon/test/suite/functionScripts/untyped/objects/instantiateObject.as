function someObject(a, b, c) {
    this.a = a;
    this.b = b;
    this.c = c;
}

function createObject() {
    var x = new someObject(10, 20, 30);
    print(x.b);
}

createObject();
