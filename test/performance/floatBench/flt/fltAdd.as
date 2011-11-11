const NITER:int=100000000;

function main():void
{
    var a:float = 1.2f;
	var b:float = 7.2f;
	var c:float = -7.2f;
	var fstart:uint  = getTimer();
    for(var i:int=0;i < NITER; ++i){
	    a = b + c;
		c = a + b + c;
		b = c + a;
	}
	var ftime:uint  = getTimer() - fstart;
	if(a == 0f && b == 0f && c == 0f)
	    trace("metric time ",ftime);
	else
	    trace("FAIL: results invalid, metric irrelevant")
}

main();

