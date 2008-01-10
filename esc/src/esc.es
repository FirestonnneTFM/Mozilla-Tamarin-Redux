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
    //print ("decoding esc_env ",esc_env.ast_class);
    var nd = Decode::program (esc_env);  // defined by side effect
    var topFixtures = nd.head.fixtures;
}

{
    use namespace Parse;
    //print ("parsing");
    var t1 = new Date;
    var parser = new Parser(str,topFixtures);
    var [ts,nd] = parser.program();
    var t2 = new Date;
    //print (fname+" parse "+(t2-t1)+" ms");
}

{
    //print ("gening");
    nd.Ast::file = fname;
    var bytes = Gen::cg(nd);
    var t3 = new Date;
    //print (fname+" cogen "+(t3-t2)+" ms");
    //print ("writing");
    var len = dumpABCFile(bytes, fname+".abc");
    print (fname+", "+(t3-t1)+" ms, "+len+" bytes written");
}