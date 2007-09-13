import avmplus.*;

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
    print ("parsing ast");
    var top = []
    var parser = initParser(str,top);
    var [ts,nd] = program();
    print ("gening ast");
    var bytes = cg(nd).getBytes();
    print ("loading ast");
    Domain.currentDomain.loadBytes(bytes);
}

// decode it

{
    print ("decoding ast");
    var nd = Decode::program (ast);  // defined by side effect
}

{
    use namespace Encode;
    print ("encoding");
    var tx = "public var ast = "+program (nd);
    writeFile (tx,fname+".ast");
    print (fname+".ast, "+tx.length+" chars written");
}

