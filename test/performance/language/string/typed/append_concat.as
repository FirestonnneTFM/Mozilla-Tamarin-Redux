include '../timetest.as'

function append_concat(loops:int):void {
    var x:String = '';
    for (var i:int=0; i<loops; i++) {
        x = x.concat('abcdefghijklmnopqrstuvwxyz0123456789');
    }
}

timetest(append_concat, 300000);

