package {
import flash.system.Promise;

public function retrieve(q:Promise) {

    var res:Promise = q.async.dequeue();
    print("RETRIEVED (44?): "+res.receive());
}

}