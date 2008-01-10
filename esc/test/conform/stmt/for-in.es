// FOR-IN stmt

var x = new Object;
for ( i in x )
    print("WRONG " + i);
print("DONE 0");

var y = { foo: 10, bar: 20 }
for ( i in y )
    print("LOOP 1");

for ( var w in y )
    print("LOOP 2");

var z = 10;
var obj = {}
for ( z in obj )
    print("WRONG");
print("SHOULD BE 10: " + z );

print("DONE");
