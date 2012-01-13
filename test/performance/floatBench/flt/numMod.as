const NITER:int=5000000; // 20 times less 

function main():void
{
    var a:*=1.2f;
	var b:*=2.4f;
	var c:* = -3.2f;
	var fstart:uint  = getTimer();
    for(var i:int=0;i<NITER;i++){
	    a = b%c;
		c = a%b;
		b = c%a;
	}
	var ftime:uint  = getTimer() - fstart;
	trace("metric time ",ftime);
}

main();

