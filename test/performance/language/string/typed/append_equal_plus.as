include '../timetest.as'

function append_equal_plus(loops:int):void {
    var x:String = '';
    for (var i:int=0; i<loops; i++) {
        x = x +'abcdefghijklmnopqrstuvwxyz0123456789';
    }
}

timetest(append_equal_plus, 300000);