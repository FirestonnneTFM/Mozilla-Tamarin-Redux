include 'timetest.as'

function append_equal_plus(loops) {
    var x = '';
    for (var i=0; i<loops; i++) {
        x = x +'abcdefghijklmnopqrstuvwxyz0123456789';
    }
}

timetest(append_equal_plus, 300000);