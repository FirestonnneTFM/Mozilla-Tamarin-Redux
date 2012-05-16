package {
import flash.system.Promise;

public function insert(q:Promise) {
    q.async.enqueue(44);
}

}