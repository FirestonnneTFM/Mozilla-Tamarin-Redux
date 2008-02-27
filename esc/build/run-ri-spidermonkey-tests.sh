DIR=../../../com.mozilla.es4.smlnj/tests/spidermonkey

PREFIX=$DIR/ecma/shell.js
SUBDIR=$DIR/ecma/Array
for TEST in $SUBDIR/*.js ; do
  ./main.sh ../test/spidermonkey-prefix.es $PREFIX $TEST
done
