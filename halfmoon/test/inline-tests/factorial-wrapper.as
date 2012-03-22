
package inlinetest {

	class FactorialWrapperTester {

		final function factorialWrapper(n):Number {
			return factorial(n);
			}

		//factorial is not trivially recursive.
		//it calls factorialWrapper, which calls factorial.
		//
		final function factorial(n):Number {

			if (n < 2) {
				return 1;
			}
			return n*factorialWrapper(n-1);
		}
	}
	var f:FactorialWrapperTester = new FactorialWrapperTester();
	trace(f.factorialWrapper(3)); //Outputs 6
} //package
