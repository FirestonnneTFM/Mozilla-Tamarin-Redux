import avmplus.System;
import flash.system.Promise;


function executeCallback(promise:Promise) {
    promise.async::callback("callback from deep callee");
}

function remoteEcho(s:String) {
    return s;
}

function throwRemoteException() {
    throw "exception on deep callee thrown";
}

function resolveEmpty(emptyPromise:Promise) {
  emptyPromise.resolve("EMPTY PROMISE RESOLVED");
}

