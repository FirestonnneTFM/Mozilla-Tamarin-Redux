import avmplus.*;

// load asm
{
    import flash.utils.*;
    var fname = System.argv[0];
    if (fname==undefined) throw "no file name given";
    var fname = System.argv[0];
    var str = "var asm = " + File.read (fname+".asm");
    //print(str);
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
    var bytes = AbcDecode::abcFile (asm);  // defined by side effect
}

// cogen and write it

{
    
    var len = dumpABCFile(bytes, fname+".abc");
    print (fname+", "/*+(t3-t1)+" ms, "*/+len+" bytes written");
}