// Test backward goto in the same block.
// This should print "PASSED".

var v = 0;

function test(n) {
L1: if (n == 0) return;
	v++;
	n--;
	goto L1;
}

test(10);
print(v == 10 ? "PASSED" : "FAILED");
