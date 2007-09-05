{
    import avmplus.*;
    import flash.utils.*;
    use namespace Parse;

    var fname = System.argv[0];
    var str = File.read (fname);

    var topFixtures = [];
    var parser = initParser(str,topFixtures);
    var [ts,nd] = program();

    dumpABCFile(Gen::cg(nd), fname+".abc");
}