package {
function test_switch(x) {
	switch (x) {
	case 1:	return print(1)
	case 2: return print(2)
	case 3: return print(3)
	default: return print('default')
	}
}
test_switch(2)
}
