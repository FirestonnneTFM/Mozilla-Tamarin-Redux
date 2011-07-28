// Test forward goto in the same block.
// This should print "PASSED".

var v = 0;

function test(n)
{
	if (n == 0) goto L1;
	v++;
	if (n == 1) goto L1;
	v++;
L1: return;
}

test(2);
print(v == 2 ? "PASSED" : "FAILED");
