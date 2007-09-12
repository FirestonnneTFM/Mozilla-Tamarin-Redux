### STEP1: compile esc3 .es to .ast using esc1-r

#./esc1-r.sh ../src/debug.es
#./esc1-r.sh ../src/util.es
#./esc1-r.sh ../src/util-ramarin.es
#./esc1-r.sh ../src/lex-char.es
#./esc1-r.sh ../src/lex-roken.es
#./esc1-r.sh ../src/lex-scan.es
#./esc1-r.sh ../src/ast.es
#./esc1-r.sh ../src/ast-decode.es
#./esc1-r.sh ../src/ast-encode.es
#./esc1-r.sh ../src/parse-util.es
#./esc1-r.sh ../src/parse-ident.es
#./esc1-r.sh ../src/parse-lhsexpr.es
#./esc1-r.sh ../src/parse-assignexpr.es
#./esc1-r.sh ../src/parse-ptrn.es
#./esc1-r.sh ../src/parse-rype.es
#./esc1-r.sh ../src/parse-stmt.es
#./esc1-r.sh ../src/parse-defn.es
#./esc1-r.sh ../src/parse-prgm.es
#./esc1-r.sh ../src/bytes-tamarin.es
#./esc1-r.sh ../src/asm.es
#./esc1-r.sh ../src/abc.es
#./esc1-r.sh ../src/abc-encode.es
#./esc1-r.sh ../src/emit.es
#./esc1-r.sh ../src/cogen.es
#./esc1-r.sh ../src/cogen-stmt.es
#./esc1-r.sh ../src/cogen-expr.es
./esc1-r.sh ../src/esc1-t.es
#./esc1-r.sh ../src/esc2-t.es
#./esc1-r.sh ../src/esc3-t.es
#./esc1-r.sh ../src/esc-t.es
#./esc1-r.sh ../src/main.es

### STEP 2: compile .ast to .abc using esc3-r and copy to ../bin

#./esc3-r.sh ../src/debug.es
#./esc3-r.sh ../src/util.es
#./esc3-r.sh ../src/util-tamarin.es
#./esc3-r.sh ../src/lex-char.es
#./esc3-r.sh ../src/lex-token.es
#./esc3-r.sh ../src/lex-scan.es
#./esc3-r.sh ../src/ast.es
#./esc3-r.sh ../src/ast-decode.es
#./esc3-r.sh ../src/ast-encode.es
#./esc3-r.sh ../src/parse-util.es
#./esc3-r.sh ../src/parse-ident.es
#./esc3-r.sh ../src/parse-lhsexpr.es
#./esc3-r.sh ../src/parse-assignexpr.es
#./esc3-r.sh ../src/parse-ptrn.es
#./esc3-r.sh ../src/parse-type.es
#./esc3-r.sh ../src/parse-stmt.es
#./esc3-r.sh ../src/parse-defn.es
#./esc3-r.sh ../src/parse-prgm.es
#./esc3-r.sh ../src/bytes-tamarin.es
#./esc3-r.sh ../src/asm.es
#./esc3-r.sh ../src/abc.es
#./esc3-r.sh ../src/abc-encode.es
#./esc3-r.sh ../src/emit.es
#./esc3-r.sh ../src/cogen.es
#./esc3-r.sh ../src/cogen-stmt.es
#./esc3-r.sh ../src/cogen-expr.es
./esc3-r.sh ../src/esc1-t.es
#./esc3-r.sh ../src/esc2-t.es
#./esc3-r.sh ../src/esc3-t.es
#./esc3-r.sh ../src/esc-t.es
#./esc3-r.sh ../src/main.es

cp ../src/debug.es.abc ../bin
cp ../src/util.es.abc ../bin
cp ../src/util-tamarin.es.abc ../bin
cp ../src/lex-char.es.abc ../bin
cp ../src/lex-token.es.abc ../bin
cp ../src/lex-scan.es.abc ../bin
cp ../src/ast.es.abc ../bin
cp ../src/ast-decode.es.abc ../bin
cp ../src/ast-encode.es.abc ../bin
cp ../src/parse-util.es.abc ../bin
cp ../src/parse-ident.es.abc ../bin
cp ../src/parse-lhsexpr.es.abc ../bin
cp ../src/parse-assignexpr.es.abc ../bin
cp ../src/parse-ptrn.es.abc ../bin
cp ../src/parse-type.es.abc ../bin
cp ../src/parse-stmt.es.abc ../bin
cp ../src/parse-defn.es.abc ../bin
cp ../src/parse-prgm.es.abc ../bin
cp ../src/bytes-tamarin.es.abc ../bin
cp ../src/asm.es.abc ../bin
cp ../src/abc.es.abc ../bin
cp ../src/emit.es.abc ../bin
cp ../src/cogen.es.abc ../bin
cp ../src/cogen-stmt.es.abc ../bin
cp ../src/cogen-expr.es.abc ../bin
cp ../src/esc1-t.es.abc ../bin
cp ../src/esc2-t.es.abc ../bin
cp ../src/esc3-t.es.abc ../bin
cp ../src/esc-t.es.abc ../bin
cp ../src/main.es.abc ../bin

### STEP 3: compile .es to .abc using esc1-t.sh and esc3-t.sh

#./esc1-t.sh ../src/debug.es
#./esc1-t.sh ../src/util.es
#./esc1-t.sh ../src/util-tamarin.es
#./esc1-t.sh ../src/lex-char.es
#./esc1-t.sh ../src/lex-token.es
#./esc1-t.sh ../src/lex-scan.es
#./esc1-t.sh ../src/ast.es
#./esc1-t.sh ../src/ast-decode.es
#./esc1-t.sh ../src/ast-encode.es
#./esc1-t.sh ../src/parse-util.es
#./esc1-t.sh ../src/parse-ident.es
#./esc1-t.sh ../src/parse-lhsexpr.es
#./esc1-t.sh ../src/parse-assignexpr.es
#./esc1-t.sh ../src/parse-ptrn.es
#./esc1-t.sh ../src/parse-type.es
#./esc1-t.sh ../src/parse-stmt.es
#./esc1-t.sh ../src/parse-defn.es
#./esc1-t.sh ../src/parse-prgm.es
#./esc1-t.sh ../src/bytes-tamarin.es
#./esc1-t.sh ../src/asm.es
#./esc1-t.sh ../src/abc.es
#./esc1-t.sh ../src/emit.es
#./esc1-t.sh ../src/cogen.es
#./esc1-t.sh ../src/cogen-stmt.es
#./esc1-t.sh ../src/cogen-expr.es
#./esc1-t.sh ../src/esc1-t.es
#./esc1-t.sh ../src/esc2-t.es
#./esc1-t.sh ../src/esc3-t.es
#./esc1-t.sh ../src/esc-t.es
#./esc1-t.sh ../src/main.es

### translate .ast to .asm, is good for debugging

#./esc2-t.sh ../src/debug.es
#./esc2-t.sh ../src/util.es
#./esc2-t.sh ../src/util-tamarin.es
#./esc2-t.sh ../src/lex-char.es
#./esc2-t.sh ../src/lex-token.es
#./esc2-t.sh ../src/lex-scan.es
#./esc2-t.sh ../src/ast.es
#./esc2-t.sh ../src/ast-decode.es
#./esc2-t.sh ../src/ast-encode.es
#./esc2-t.sh ../src/parse-util.es
#./esc2-t.sh ../src/parse-ident.es
#./esc2-t.sh ../src/parse-lhsexpr.es
#./esc2-t.sh ../src/parse-assignexpr.es
#./esc2-t.sh ../src/parse-ptrn.es
#./esc2-t.sh ../src/parse-type.es
#./esc2-t.sh ../src/parse-stmt.es
#./esc2-t.sh ../src/parse-defn.es
#./esc2-t.sh ../src/parse-prgm.es
#./esc2-t.sh ../src/bytes-tamarin.es
#./esc2-t.sh ../src/asm.es
#./esc2-t.sh ../src/abc.es
#./esc2-t.sh ../src/emit.es
#./esc2-t.sh ../src/cogen.es
#./esc2-t.sh ../src/cogen-stmt.es
#./esc2-t.sh ../src/cogen-expr.es
#./esc2-t.sh ../src/esc1-t.es
#./esc2-t.sh ../src/esc2-t.es
#./esc2-t.sh ../src/esc3-t.es
#./esc2-t.sh ../src/esc-t.es
#./esc2-t.sh ../src/main.es

#./esc3-t.sh ../src/debug.es
#./esc3-t.sh ../src/util.es
#./esc3-t.sh ../src/util-tamarin.es
#./esc3-t.sh ../src/lex-char.es
#./esc3-t.sh ../src/lex-token.es
#./esc3-t.sh ../src/lex-scan.es
#./esc3-t.sh ../src/ast.es
#./esc3-t.sh ../src/ast-decode.es
#./esc3-t.sh ../src/ast-encode.es
#./esc3-t.sh ../src/parse-util.es
#./esc3-t.sh ../src/parse-ident.es
#./esc3-t.sh ../src/parse-lhsexpr.es
#./esc3-t.sh ../src/parse-assignexpr.es
#./esc3-t.sh ../src/parse-ptrn.es
#./esc3-t.sh ../src/parse-type.es
#./esc3-t.sh ../src/parse-stmt.es
#./esc3-t.sh ../src/parse-defn.es
#./esc3-t.sh ../src/parse-prgm.es
#./esc3-t.sh ../src/bytes-tamarin.es
#./esc3-t.sh ../src/asm.es
#./esc3-t.sh ../src/abc.es
#./esc3-t.sh ../src/emit.es
#./esc3-t.sh ../src/cogen.es
#./esc3-t.sh ../src/cogen-stmt.es
#./esc3-t.sh ../src/cogen-expr.es
#./esc3-t.sh ../src/esc1-t.es
#./esc3-t.sh ../src/esc2-t.es
#./esc3-t.sh ../src/esc3-t.es
#./esc3-t.sh ../src/esc-t.es
#./esc3-t.sh ../src/main.es

