
package {
	function loop(x) {
		var sum = 0;
		for (var i = 0; i < x; i++) {
			sum += i;
			print(i);
			sum += i;
		}

		return sum;
	}

	for (var i = 0; i < 20; i++) {
		loop(i);
	}
}
