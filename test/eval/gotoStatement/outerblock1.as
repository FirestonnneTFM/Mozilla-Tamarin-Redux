// Test forward goto out of a block.
// This should print "PASSED".

var v = 0;

function test(n)
{
	for (;;) {
		if (n == 0) goto L1;
		v++;
		n--;
	}
	print("DEAD CODE, SHOULD NOT RUN");
L1: return;
}

test(10);
print(v == 10 ? "PASSED" : "FAILED");
