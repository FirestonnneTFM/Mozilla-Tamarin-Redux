var x = 10;
var o = { x: 20 }
while (true)
  with (o)
    break;
print("BREAK-WITH " + x);
print("DONE");
