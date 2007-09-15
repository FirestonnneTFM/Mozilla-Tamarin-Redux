{
    import flash.utils.*;
    
    public function writeFile(s:String, filename:String) {
        var b = new ByteArray();
        b.writeUTFBytes(s);
        b.writeFile(filename);
    }
    
    public function readFile(filename:String) {
        var b = ByteArray.readFile(filename);
        return b.readUTFBytes(b.length);
    }

    public function dumpABCFile(abcfile, filename) {
        var bytes = abcfile.getBytes();
        bytes.writeFile(filename);
        return bytes.length;
    }
}
