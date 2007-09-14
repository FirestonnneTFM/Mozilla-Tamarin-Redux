#./esc.sh ../src/debug.es
#./esc.sh ../src/util.es
#./esc.sh ../src/util-tamarin.es
#./esc.sh ../src/lex-char.es
#./esc-t.sh ../src/lex-token.es
#./esc-t.sh ../src/lex-scan.es
#./esc.sh ../src/ast.es
#./esc-t.sh ../src/ast-decode.es
#./esc.sh ../src/ast-encode.es
#./esc-t.sh ../src/parse.es
#./esc.sh ../src/bytes-tamarin.es
#./esc.sh ../src/asm.es
#./esc.sh ../src/abc.es
#./esc.sh ../src/abc-encode.es
#./esc.sh ../src/emit.es
#./esc.sh ../src/cogen.es
#./esc.sh ../src/cogen-stmt.es
#./esc.sh ../src/cogen-expr.es
#./esc.sh ../src/esc1-t.es
#./esc.sh ../src/esc2-t.es
#./esc.sh ../src/esc3-t.es
./esc-t.sh ../src/esc.es
#./esc.sh ../src/main.es

cp ../src/*.es.abc ../bin
