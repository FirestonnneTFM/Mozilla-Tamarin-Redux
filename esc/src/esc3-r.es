{
    use namespace Util;

    print ("reading")
    load ("esc-tmp.ast");  // read and eval 
    print ("decoding");
    var nd = Decode::program (ast);
    dumpABCFile(Gen::cg(nd), "esc-tmp.abc");
}