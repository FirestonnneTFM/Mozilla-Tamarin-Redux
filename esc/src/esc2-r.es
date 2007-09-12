{
    use namespace Util;

    print ("reading")
    load ("esc-tmp.ast");  // read and eval 
    print ("decoding");
    var ast = Decode::program (ast);
    var abc = Gen::cg(ast);
    var asm = AbcEncode::abcFile (abc);
    writeFile (asm,"esc-tmp.asm");
    print (asm.length+" chars written");
}