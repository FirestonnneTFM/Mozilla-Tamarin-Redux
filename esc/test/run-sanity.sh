function run {
echo compiling $1
../build/esc1-t.sh sanity/tests/$1
../build/esc-t.sh sanity/tests/$1
/work/tamarin/bin/shell -log sanity/tests/$1.abc
}

rm sanity/log/*

run arrayliteral.es
run cls.es
run continue.es
run expr.es
run fib.es
run for.es
run hello.es
run if.es
run numbers.es
run objectliteral.es
run prime.es
run print.es
run switch.es
run switchType.es
run test.es
run token.es
run try.es
run vars.es
run while.es

mv sanity/tests/*.es.ast sanity/log
mv sanity/tests/*.es.log sanity/log
rm sanity/tests/*.es.abc

diff sanity/regress sanity/log
