package {
function rest_test(...rest) {
	for (var i = 0; i < rest.length; i++)
		print(rest[i])
}
rest_test(1,2)
}
