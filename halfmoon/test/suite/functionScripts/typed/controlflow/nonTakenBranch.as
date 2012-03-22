package {
function escCtrlChars(str:String):String {  // escape control chars which might cause problems handling ciphertext
  var s:String = "";
  for ( var i:int=0 ; i < str.length ; i++ ) {
    var c:String = str.charAt(i);
    if (c == "\0")  
        s += "!"; 
  }
  return s;
}



function test():String {
	var ct:String = '';
	return escCtrlChars(ct);
}

function makeHot() {
	for (var i = 0; i < 1000; i++) {
		test();
	}
}

	makeHot();
}
