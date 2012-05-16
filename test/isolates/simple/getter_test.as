import flash.system.*
if (Worker.current.isPrimordial()) {
    var w:Worker=WorkerDomain.current.createWorkerFromPrimordial();
    var p:Promise=w.start();
    var p1:Promise=p.value;
    print(p1.local::receive());
    var p2:Promise=p.Clazz.svalue;
    print(p2.local::receive());
    var p3:Promise=p.o.ivalue;
    print(p3.local::receive());
    w.stop();
} else {
    function get value() {
        return 10;
    }

    class Clazz {
	public static function get svalue() {
	    return 42;
	}

	public function get ivalue() {
	    return 7;
	}
    };

    var o = new Clazz();
}