function timetest(func:Function, iterationsDesktop:Number=1, iterationsMobile:Number=1) {
    if (iterationsMobile == null)
        iterationsMobile = iterationsDesktop;

    var start:Number;
    var totaltime:Number;
    
    if (CONFIG::desktop) {
        start = new Date();
        func(iterationsDesktop);
        totaltime = new Date() - start;
    } else {
        start = getTimer();
        func(iterationsMobile);
        totaltime = getTimer() - start;
    }
    print('metric time '+totaltime);
}