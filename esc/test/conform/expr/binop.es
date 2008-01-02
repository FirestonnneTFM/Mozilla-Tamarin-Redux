function plus(a,b) { return a+b }
function minus(a,b) { return a-b }
function times(a,b) { return a*b }
function divide(a,b) { return a/b }
function mod(a,b) { return a%b }
function shl(a,b) { return a<<b }
function shr(a,b) { return a>>b }
//function shru(a,b) { return a>>>b }
function and(a,b) { return a&b }
function or(a,b) { return a|b }
function xor(a,b) { return a^b }
function lt(a,b) { return a<b }
function le(a,b) { return a<=b }
function gt(a,b) { return a>b }
function ge(a,b) { return a>=b }
function eq(a,b) { return a===b }
function neq(a,b) { return a!==b }
function eqv(a,b) { return a==b }
function neqv(a,b) { return a!=b }
function _in(a,b) { return a in b }
function _instanceof(a,b) { return a instanceof b }
function _true(x) { print(x + " TRUE"); return true }
function _false(x) { print(x + " FALSE"); return false }

print("PLUS " + plus(1,2));
print("PLUS " + plus("a","b"));
print("MINUS " + minus(1,2));
print("TIMES " + times(3,5));
print("DIVIDE " + divide(15,2));
print("MOD " + mod(8,3));
print("SHL " + shl(1,3));
print("SHR " + shr(-1,3));
//print("SHRU " + shru(-1,3));
print("AND " + and(10,2));
print("OR " + or(10,18));
print("XOR " + xor(15,8));
print("LT " + lt(1,2));
print("LE " + le(1,2));
print("GT " + gt(1,2));
print("GE " + ge(1,2));
print("EQ " + eq(1,1));
print("NEQ " + neq(1,1));
print("EQV " + eqv(1,1));
print("NEQV " + neqv(1,1));
print("IN " + _in("propertyIsEnumerable",Object));
print("INSTANCEOF " + _instanceof(new Object, Object));
_true("&&") && _false("&&");
_false("&&") && _true("&&");
_true("||") || _false("||");
_false("||") || _true("||");

var x;
x = 10;
print("ASSIGN " + x );

/* None of these are implemented

x = 10; x += 5; print("+= " + x);
x = 10; x -= 5; print("-= " + x);
x = 10; x *= 5; print("*= " + x);
x = 10; x /= 5; print("/= " + x);
x = 10; x %= 5; print("%= " + x);
x = 10; x <<= 2; print("<<= " + x);
x = -1; x >>= 2; print(">>= " + x);
x = -1; x >>>= 2; print(">>>= " + x);
x = 10; x &= 3; print("&= " + x);
x = 10; x |= 3; print("|= " + x);
x = 10; x ^= 7; print("^= " + x);
*/

print("COMMA " + ( "WRONG", "RIGHT" ));

print("DONE");
