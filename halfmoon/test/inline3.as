/* -*- Mode: actionscript; -*- */

package {

print(caller(10))

function loop(n) {
	for (var i=0; i < n; i++)
		print(i)
}

function caller(n) {
	for (var i=0; i < 2; i++)
		loop(n)
	return n
}

}
   
