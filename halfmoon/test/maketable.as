{

// extracted from esc/src/util.es.  Compile with
// esc:  avm esc.swf -- maketable.as

function makeTable(size) {
	var tbl = new Array(size);
	for ( var i=0; i < size; i = i + 1)
		tbl[i] = null;
	return tbl;
}
print(makeTable(3))

}
