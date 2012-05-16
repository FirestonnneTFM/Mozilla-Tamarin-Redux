package bar {

public var dummy:Number = 42;

}

package baz {

public var v1:Number = 7;

public var redef:Number = 42;

public function foo():String {
  return "BLAH";
}

}

package baz.bar {

public var v2:Number = 77;

public function foo():String {
  return "BLEH";
}

}

package bam.bar {

public var o = new Object();

}

package {

public function unnamedFoo():String {
  return "UNNAMED";
}

}

function foo():String {
  return "BLOH";
}

var v3:Number = 777;

var bam:Number = 7777;

var bar:Number = 77777;

class baz {
  public static var redef:Number = 0;
}

