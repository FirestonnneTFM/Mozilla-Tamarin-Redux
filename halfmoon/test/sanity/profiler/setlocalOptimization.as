package {

	function returnVal() {
		return 10;
	}

	function safepoint(x) {
		var y = x + 10;
		y += returnVal();
		var z = y - 10;
		print(z);
	}

	for (var i = 0; i < 20; i++) {
		safepoint(i);

	}
}
