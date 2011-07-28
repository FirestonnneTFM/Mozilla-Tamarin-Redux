// Missing label - not in scope, in substatement

function f()
{
    if (true) { L1: print("x"); }
	goto L1;
}
f();
