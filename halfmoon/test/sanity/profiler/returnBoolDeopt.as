function checker1(value,index,obj):Boolean {
  if (value==0) {
	print(index + " false " + value);
    return false;
	}

  print(index + " true " + value);
  return true;
}

for (var i = 0; i < 15; i++) {
		var v1 = Vector.<uint>([31415, uint.MAX_VALUE, 0, 999999]);
		v1.every(checker1);
}
