package {
function swaptest(c,x,y) {
  while (c--) { var t = x; x = y; y = t; }
  print(x, y)
}
swaptest(2,0,1)
swaptest(1,0,1)
swaptest(0,0,1)
}
