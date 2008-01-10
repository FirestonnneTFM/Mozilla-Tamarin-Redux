var x = 10;
var o = { x: 20 }

var n = 2;
while (n-- > 0) {
  with (o) {
    print("HERE " + n);
    continue;
  }
  print("WRONG");
}

print("CONTINUE-WITH " + x);
print("DONE");
