const NITER:int=100000000;

function main():void
{
    var a:*=1.2;
	var b:*=2.4;
	var c:* = -3.2;
	var fstart:uint  = getTimer();
    for(var i:int=0;i<NITER;i++){
	    a = b/c;
		c = a/b;
		b = c/a;
	}
	var ftime:uint  = getTimer() - fstart;
	trace("metric time ",ftime);
}

main();

