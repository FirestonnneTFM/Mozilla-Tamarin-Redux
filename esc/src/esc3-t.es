import avmplus.*;

// load ast
{
    import flash.utils.*;
    var fname = System.argv[0];
    if (fname==undefined) throw "no file name given";
    var fname = System.argv[0];
    var str = File.read (fname+".ast");
}

// eval ast

{
    use namespace Parse;
    use namespace Gen;
    //print ("parsing");
    var top = [];
    var parser = new Parser(str,top);
    var [ts,nd] = parser.program();
    var bytes = cg(nd).getBytes();
    Domain.currentDomain.loadBytes(bytes);
}

// decode it

{
    //print ("decoding");
    var nd = Decode::program (ast);  // defined by side effect
}

// cogen and write it

{
    //print ("generating");
    var bytes = Gen::cg(nd);
    dumpABCFile(bytes, fname+".abc");
}