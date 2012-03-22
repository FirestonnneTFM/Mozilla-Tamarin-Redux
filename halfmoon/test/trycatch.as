
function trycatch(c) {
	try {
	    if (c)
		  throw c
		print('try')
	} catch (i:int) {
		print('catch ' + i)
	} catch (x) {
		print('catch ' + x)
	}
}
trycatch()
trycatch(1)
