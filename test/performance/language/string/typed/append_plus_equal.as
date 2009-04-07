include '../timetest.as'

function append_plus_equal(loops:int):void {
    var x:String = '';
    for (var i:int=0; i<loops; i++) {
        x += 'abcdefghijklmnopqrstuvwxyz0123456789';
    }
}

timetest(append_plus_equal, 300000);