{
    import avmplus.*;
    var fname = System.argv[0];
    var str = File.read (fname);
    print ("compiling ", fname);
}
var topFixtures = [];
{
    use namespace Parse;
    print ("parsing");
    var parser = initParser(str,topFixtures);
    var [ts,nd] = program();
}
{
    use namespace Encode;
    print ("encoding");
    var tx = "public var ast = "+program (nd);
    print ("writing");
    writeFile (tx,fname+".ast");
    print (tx.length+" chars written");
}
