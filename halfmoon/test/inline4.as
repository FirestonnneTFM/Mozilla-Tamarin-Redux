/* -*- Mode: actionscript; -*- */

package {

public class vec {
	var x:int;
	var y:int;
	function vec(x:uint,y:uint) {
		this.x=x;
		this.y=y;
	}
	public function sum():int {
		return this.x+this.y;
	}
}

function caller(p1: int): int {
	print(new vec(p1, 1).sum())
}
caller(2)

}
