public namespace Debug;
public namespace Release;

Debug function trace (s) {
    print (s);
}

var nesting = 0;

function arrows (c)
    : string {
    let str = "";
    for ( var n = nesting; n > 0; n = n - 1 ) {
        str = str + c;
    }
    return nesting + " " + str+" ";
}

Debug function enter (s,a="") {
    nesting = nesting + 1;
    print (arrows(">"), s, a);
}

Debug function exit (s,a="") {
    print (arrows("<"), s, a);
    nesting = nesting - 1;
}

Release function enter (s,a="") { nesting = nesting + 1 }
Release function exit (s,a="") { nesting = nesting - 1 }
Release function trace (s) { }
