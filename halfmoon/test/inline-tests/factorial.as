
package inlinetest {

	class FactorialTester {

		final function factorial(n):Number {

			if (n < 2) {
				return 1;
			}
			return n*factorial(n-1);
		}
	}

	f = new FactorialTester();

	trace(f.factorial(3)); //Outputs 6
} //package
