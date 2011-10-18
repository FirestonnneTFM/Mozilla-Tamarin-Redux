// Missing label - not in scope, in top-level group

function f()
{
    { L1: print("x"); }
	goto L1;
}
f();
