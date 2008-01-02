/* -*- mode: fundamental -*- */
// Various kinds of semicolon insertion

var x = 10
print("VAR")

x = x*2
print("EXPR 1 " + x)

x = 2
* 3
print("EXPR 2 " + x)

while (true)
    break
print("BREAK")

while (false)
    continue
print("CONTINUE")

function f() {
   return
   "not this value"
}
print("RETURN " + f()) // should be undefined

print("DONE")
