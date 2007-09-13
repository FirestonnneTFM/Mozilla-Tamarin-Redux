{
    import avmplus.*;
    var fname = System.argv[0];
    var str = File.read (fname);
    //print ("compiling ", fname);
}

{
    import avmplus.*;
    use namespace Parse;
    use namespace Gen;
    var esc_env_str = File.read ("esc-env.ast");
    var parser = new Parser(esc_env_str,[]);
    var [ts,nd] = parser.program();
    var bytes = cg(nd).getBytes();
    Domain.currentDomain.loadBytes(bytes);
}

// decode it

{
    use namespace Ast;
    //print ("decoding esc_env");
    var nd = Decode::program (esc_env);  // defined by side effect
    var topFixtures = nd.head.fixtures;
}

{
    use namespace Parse;
    //print ("parsing");
    var parser = new Parser(str,topFixtures);
    var [ts,nd] = parser.program();
}

{
    use namespace Encode;
    //print ("encoding");
    var tx = "public var ast = "+program (nd);
    writeFile (tx,fname+".ast");
    print (fname+".ast, "+tx.length+" chars written");
}
