package {
	function loop(x) {
		var sum = 0;
		sum += x;
		print(sum);
	}

	for (var i = 0; i < 30; i++) {
		if (i > 25) {
			loop(i + 0.5);
		} else {
			loop(i);
		}
	}
}
