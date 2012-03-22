/* -*- Mode: actionscript; -*- */

package {

print(caller(42))

function loop(n) {
	for (var i=0; i < n; i++)
		print(i)
}

function caller(n) {
	loop(n)
	return n
}

}
   
