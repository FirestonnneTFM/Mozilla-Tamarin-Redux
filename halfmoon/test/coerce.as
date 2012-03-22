class A {}
function docast1(x):A {
	var a:A = x
	return a
}
docast1(new A())

function docast2(x:A):A {
	var a:A = x
	return a
}
docast2(new A())
