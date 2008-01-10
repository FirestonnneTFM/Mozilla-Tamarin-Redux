var x = 10;
var o = { x: 20 }

while (true)
  with (o) {
    print("HERE");
    break;
  }

print("BREAK-WITH " + x);
print("DONE");
