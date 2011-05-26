const NITER:int=100000000;

function main():void
{
    var a:float=1.2f;
	var b:float=2.4f;
	var c:float = -3.2f;
	var fstart:uint  = getTimer();
    for(var i:int=0;i<NITER;i++){
	    a = b+c;
		c = a+b;
		b = c+a;
	}
	var ftime:uint  = getTimer() - fstart;
	trace("metric time ",ftime);
}

main();

