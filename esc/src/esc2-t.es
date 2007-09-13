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
    //print ("parsing ast");
    var top = []
    var parser = initParser(str,top);
    var [ts,nd] = program();
    //print ("gening ast");
    var bytes = cg(nd).getBytes();
    //print ("loading ast");
    Domain.currentDomain.loadBytes(bytes);
}

// decode it

{
    //print ("decoding ast");
    var nd = Decode::program (ast);  // defined by side effect
}

// cogen and write it

{
    //print ("generating abc");
    var bytes = Gen::cg(nd);
    //print ("encoding asm");
    var tx = AbcEncode::abcFile (bytes);
    writeFile (tx,fname+".asm");
    print (fname+".asm, "+tx.length+" chars written");
}