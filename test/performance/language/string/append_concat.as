include 'timetest.as'

function append_concat(loops) {
    var x = '';
    for (var i=0; i<loops; i++) {
        x = x.concat('abcdefghijklmnopqrstuvwxyz0123456789');
    }
}

timetest(append_concat, 300000);

