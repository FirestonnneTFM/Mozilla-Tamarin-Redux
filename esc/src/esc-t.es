{
    import avmplus.*;
    import flash.utils.*;
    use namespace Parse;

    var fname = System.argv[0];
    var str = File.read (fname);

    var topFixtures = [];
    var parser = initParser(str,topFixtures);
    var [ts,nd] = program();
    var ob = Gen::cg(nd);

    
}