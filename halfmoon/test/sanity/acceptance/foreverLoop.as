package {
	function loop(x) {
		for (;;) {
			x += x;
		}
	}

	function properLoop(x) {
		for (var i = 0; i < x; i++) {
			i += i;
		}
	}

	loop(5);
}
