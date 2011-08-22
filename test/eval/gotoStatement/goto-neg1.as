// Duplicate label

function f()
{
L1: print("x");
L1: print("y");
	goto L1;
}
f();
