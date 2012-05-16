import flash.system.*;
import avmplus.*;

if (Worker.current.isPrimordial()) {

  var numWorkers=0;
  if (System.argv.length>0) {
      try {
          numWorkers=int(System.argv[0]);
      } catch (e) {
          print("error parsing number of workers, must be a number, value '"+System.argv[0]+"'");
      System.exit(1);
      }
      if (numWorkers>30) {
          print("error number of workers must be <= 30");
      System.exit(1);
      }
  }
  var size=3;
  if (CONFIG::desktop) {
        size=0;
  }
  if (System.argv.length>1) {
      try {
          size=int(System.argv[1]);
      } catch (e) {
          print("error: size must be a number, invalid size '"+System.argv[1]+"'");
          System.exit(1);
      }
  }

  var size:int;
    // Declare class data.

  var array_rows:int;

  var TestArray:Vector.<Vector.<Number>>; // Array of arrays.
  
  var datasizes:Vector.<int> = new Vector.<int>(4,true);
  datasizes[0] = 10000;
  datasizes[1] = 100000;
  datasizes[2] = 1000000;
  datasizes[3] = 125;

  if (CONFIG::desktop) {
      var start = new Date();
      JGFrun(size);
      var elapsed = new Date() - start;
  }
  else { // mobile
      var start = getTimer();
      JGFrun(size);
      var elapsed = getTimer() - start;
  }
  if (JGFvalidate())
    print("metric time "+elapsed);
  else
    print("validation failed");

}
  
  function JGFsetsize(sizel:int):void {
    size = sizel;
  }

  function JGFinitialise():void {
    array_rows = datasizes[size];
    if ( array_rows % (numWorkers+1) > 0 ) {
        print("error: size must be divisible by number of workers+1, but "+array_rows+" is not divisible by "+(numWorkers+1));
    System.exit(1);
    }
    //    print("using size "+array_rows);
    //    print("using workers "+numWorkers);
//    buildTestData();
  }

  function JGFkernel():void {
    Do();
  }

  function JGFvalidate():Boolean {
    var ref:Vector.<Vector.<Number>> = new Vector.<Vector.<Number>>(4,true);
    for(var i:int=0;i<4;i++)
    {
      ref[i] = new Vector.<Number>(2,true);
      
    }
    
    ref[0][0] = 2.8729524964837996;
    ref[0][1] = 0.0;
    ref[1][0] = 1.1161046676147888;
    ref[1][1] = -1.8819691893398025;
    ref[2][0] = 0.34429060398168704;
    ref[2][1] = -1.1645642623320958;
    ref[3][0] = 0.15238898702519288;
    ref[3][1] = -0.8143461113044298;
    /*
     * // for 200 points double ref[][] = {{2.8377707562588803, 0.0},
     * {1.0457844730995536, -1.8791032618587762}, {0.27410022422635033,
     * -1.158835123403027}, {0.08241482176581083, -0.8057591902785817}};
     */
    for (var i:int = 0; i < 4; i++) {
      for (var j:int = 0; j < 2; j++) {
        var error:Number = Math.abs(TestArray[j][i] - ref[i][j]);
        if (error > 1.0e-12) {
          print("Validation failed for coefficient " + j + "," + i);
          print("Computed value = " + TestArray[j][i]);
          print("Reference value = " + ref[i][j]);
          return false
        }
        
    //        print( TestArray[j][i] );
      }
    }
    return true;
  }

  function JGFtidyup():void {
    freeTestData();
  }

  function JGFrun(sizel:int):void {
    JGFsetsize(sizel);
    JGFinitialise();
    JGFkernel();
    JGFvalidate();
    //JGFtidyup();
  }
  
    /*
   * buildTestData
   * 
   */

  // Instantiate array(s) to hold fourier coefficients.
  function buildTestData():void {
    // Allocate appropriate length for the double array of doubles.

    TestArray = new Vector.<Vector.<Number>>(2,true); //double[2][array_rows];
    for(var i=0;i<2;i++)
    {
      TestArray[i] = new Vector.<Number>(array_rows);
    }
  }

  /*
   * Do
   * 
   * This consists of calculating the first n pairs of fourier coefficients of
   * the function (x+1)^x on the interval 0,2. n is given by array_rows, the
   * array size. NOTE: The # of integration steps is fixed at 1000.
   */

  function Do():void {
    var workers:Array=new Array();
    var promises1:Array=new Array();
    var promises2:Array=new Array();

    var splitsize:int=array_rows/(numWorkers+1);

    for (var i:int=0;i<numWorkers;i++) {
        workers[i]=WorkerDomain.current.createWorkerFromPrimordial();
        promises1[i]=workers[i].start();
        promises2[i]=promises1[i].Divide(splitsize+splitsize*i,splitsize+splitsize*(i+1));
    }
    TestArray=Divide(0,splitsize);
    for (var i=0;i<numWorkers;i++) {
    TestArray=TestArray.concat(promises2[i].local::receive());
    }
    for (var i=0;i<numWorkers;i++) {
        workers[i].stop();
    }
  }
  function Divide(start:int,end:int):Vector.<Vector.<Number>> {
      var omega:Number = 3.1415926535897932;
      var res:Vector.<Vector.<Number>>=new Vector.<Vector.<Number>>(2,true);
      res[0]=new Vector.<Number>(end-start);
      res[1]=new Vector.<Number>(end-start);
      if (start==0) {
          res[0][0]=2.0;
      res[0][0]=TrapezoidIntegrate(0.0,2.0,1000,0.0,0)/2.0;
      res[1][0]=0.0;
      for (var i:int=1;i<end-start;i++) {
              res[0][i]=TrapezoidIntegrate(0.0,2.0,1000,omega*i,1);
             res[1][i]=TrapezoidIntegrate(0.0,2.0,1000,omega*i,2);
          }
      } else {
          for (var i:int=0;i<end-start;i++) {
              res[0][i]=TrapezoidIntegrate(0.0,2.0,1000,omega*i,1);
              res[1][i]=TrapezoidIntegrate(0.0,2.0,1000,omega*i,2);
          }
      }
      return res;
  }


  /*
   * TrapezoidIntegrate
   * 
   * Perform a simple trapezoid integration on the function (x+1)**x. x0,x1
   * set the lower and upper bounds of the integration. nsteps indicates # of
   * trapezoidal sections. omegan is the fundamental frequency times the
   * series member #. select = 0 for the A[0] term, 1 for cosine terms, and 2
   * for sine terms. Returns the value.
   */

  function TrapezoidIntegrate( x0:Number, // Lower bound.
       x1:Number, // Upper bound.
       nsteps:int, // # of steps.
       omegan:Number, // omega * n.
       select:int):Number // Term type.
  {
    var x:Number; // Independent variable.
    var dx:Number; // Step size.
    var rvalue:Number; // Return value.

    // Initialize independent variable.

    x = x0;

    // Calculate stepsize.

    dx = (x1 - x0) / nsteps;

    // Initialize the return value.

    rvalue = thefunction(x0, omegan, select) / 2.0;

    // Compute the other terms of the integral.

    if (nsteps != 1) {
      --nsteps; // Already done 1 step.
      while (--nsteps > 0) {
        x += dx;
        rvalue += thefunction(x, omegan, select);
      }
    }

    // Finish computation.

    rvalue = (rvalue + thefunction(x1, omegan, select) / 2.0) * dx;
    return (rvalue);
  }

  /*
   * thefunction
   * 
   * This routine selects the function to be used in the Trapezoid
   * integration. x is the independent variable, omegan is omega * n, and
   * select chooses which of the sine/cosine functions are used. Note the
   * special case for select=0.
   */

  function thefunction( x:Number, // Independent variable.
       omegan:Number, // Omega * term.
       select:int):Number // Choose type.
  {
    // Use select to pick which function we call.
    switch (select) {
      case 0:
        return (Math.pow(x + 1.0, x));

      case 1:
        return (Math.pow(x + 1.0, x) * Math.cos(omegan * x));

      case 2:
        return (Math.pow(x + 1.0, x) * Math.sin(omegan * x));
    }

    // We should never reach this point, but the following
    // keeps compilers from issuing a warning message.

    return (0.0);
  }
  
