// Canonical API: call START first, then PASS or FAIL for each test, then END.

package 
{
    var PASSED = " PASSED!";
    var FAILED = " FAILED! expected: ";
    var summary = "";

    public function START(_summary)
    {
	summary = _summary;
	print("Testing: " + summary);
    }

    public function PASS(name)
    {
	print(name + PASSED);
    }

    public function FAIL(name, expected, actual)
    {
	print(name + FAILED + expected + ", actual: " + actual);
    }

    public function END()
    {
	print("Finished testing " + summary);
    }

    // Useful helpers

    public function COMPARE_STRICTEQ(name, expected, actual)
    {
	if (expected !== actual)
	    FAIL(name, expected, actual);
	else
	    PASS(name);
    }

	/**
	 *  Compare to a specified precision.
	 */
	public function COMPARE_NUMBEREQ(name, expected, actual, fractionDigits=-1)
    {
        if (fractionDigits >= 0) {
            if (expected.toFixed(fractionDigits) !== actual.toFixed(fractionDigits))
                FAIL(name, expected, actual);
            else
                PASS(name);
        } else {
            COMPARE_STRICTEQ(name, expected, actual)
        }
    }
	
}

