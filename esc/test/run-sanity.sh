function run {
echo compiling $1
../build/esc1-t.sh ../test/sanity/tests/$1
../build/esc3-t.sh ../test/sanity/tests/$1
../bin/shell -log ../test/sanity/tests/$1.abc
}

rm sanity/log/*
rm sanity/tests/*.es.abc

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
run try.es
run vars.es
run while.es

mv sanity/tests/*.es.ast sanity/log
mv sanity/tests/*.es.log sanity/log

diff -s sanity/regress sanity/log
