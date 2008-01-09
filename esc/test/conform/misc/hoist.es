// hoisting

print("FUNCTION 1 " + fn());    // fn defn should be hoisted from below and should be defined
print("HOISTED 1 " + hoisted);  // should be hoisted from below, should be undefined here
print("LOOPVAR 1 " + loopvar);  // should be hoisted out of the loop, so this should be undefined

var hoisted = 0;

function fn() { return 10 }

for ( var loopvar = hoisted ; loopvar < 0 ; loopvar++ )
    ;

print("HOISTED 2 " + hoisted);
print("LOOPVAR 2 " + loopvar);

print("DONE");
