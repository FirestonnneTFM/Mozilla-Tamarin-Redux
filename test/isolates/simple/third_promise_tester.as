import flash.system.Promise;

function printWrapped(wrappedPromise:Promise) {

  var s:String = wrappedPromise.local::receive();
  print("WRAPPED VALUE: "+s);

}
