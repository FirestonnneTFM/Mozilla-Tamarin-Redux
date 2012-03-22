package {
	function testbool(b) {
		if (b) { print("true"); }
		else { print("false"); }
	}

	for (var i = 0; i < 20; i++) {
		testbool(true);
	}
}
