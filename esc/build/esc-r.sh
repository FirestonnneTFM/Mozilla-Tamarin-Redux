echo esc-r $1
cp $1 esc-tmp.es
sml @SMLload=../bin/es4-dump.heap.x86-darwin -e ../src/debug.es ../src/ast.es ../src/ast-encode.es ../src/ast-decode.es ../src/lex-char.es ../src/lex-token.es ../src/lex-scan.es ../src/util.es ../src/parse-util.es ../src/parse-ident.es ../src/parse-lhsexpr.es ../src/parse-assignexpr.es ../src/parse-ptrn.es ../src/parse-type.es ../src/parse-stmt.es ../src/parse-defn.es ../src/parse-prgm.es ../src/util-es4ri.es ../src/bytes-es4ri.es ../src/asm.es ../src/abc.es ../src/emit.es ../src/cogen.es ../src/cogen-stmt.es ../src/cogen-expr.es ../src/esc-r.es

cp esc-tmp.abc $1.abc
rm esc-tmp.es
