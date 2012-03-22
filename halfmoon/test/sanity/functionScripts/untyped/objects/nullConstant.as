package {
var a = [
	function f1() { return print(null.p) },
	function f2() { return print(undefined.p) },
	function f3() { return print(null[0]) },
	function f4() { return print(undefined[0]) },
]
for each (var f in a) { try { f() } catch (e) { print('pass') }}
}
