var x, y;

x = 10;  y = ++x;  print("PREFIX ++ " + x + " " + y);
x = 10;  y = x++;  print("POSTFIX ++ " + x + " " + y);

x = 10;  y = --x;  print("PREFIX -- " + x + " " + y);
x = 10;  y = x--;  print("POSTFIX -- " + x + " " + y);

x = { foo: 10 }
delete x.foo;
print( "DELPROP " + ("foo" in x) );

print( "DELVAR " + (delete x) );

function f() { print("VOID called") }
print( "VOID " + (void f()) );

/* Verifier fails
print( "TYPEOF " + (typeof "foo"));
print( "TYPEOF " + (typeof null));
print( "TYPEOF " + (typeof zappa));
*/

print( "UNOP + " + (+ "") );
print( "UNOP - " + (- 10) );
print( "UNOP ~ " + (~ 10) );
print( "UNOP ! " + (! true) );
print( "DONE" );
