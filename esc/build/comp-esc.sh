### STEP1: compile esc3 .es to .ast

./esc1-r.sh ../src/debug.es
./esc1-r.sh ../src/util.es
./esc1-r.sh ../src/util-tamarin.es
./esc1-r.sh ../src/lex-char.es
./esc1-r.sh ../src/lex-token.es
./esc1-r.sh ../src/lex-scan.es
./esc1-r.sh ../src/ast.es
./esc1-r.sh ../src/ast-decode.es
./esc1-r.sh ../src/ast-encode.es
./esc1-r.sh ../src/parse-util.es
./esc1-r.sh ../src/parse-ident.es
./esc1-r.sh ../src/parse-lhsexpr.es
./esc1-r.sh ../src/parse-assignexpr.es
./esc1-r.sh ../src/parse-ptrn.es
./esc1-r.sh ../src/parse-type.es
./esc1-r.sh ../src/parse-stmt.es
./esc1-r.sh ../src/parse-defn.es
./esc1-r.sh ../src/parse-prgm.es
./esc1-r.sh ../src/bytes.es
./esc1-r.sh ../src/asm.es
./esc1-r.sh ../src/abc.es
./esc1-r.sh ../src/emit.es
./esc1-r.sh ../src/cogen.es
./esc1-r.sh ../src/cogen-stmt.es
./esc1-r.sh ../src/cogen-expr.es
./esc1-r.sh ../src/esc1-t.es
./esc1-r.sh ../src/esc2-t.es
./esc1-r.sh ../src/esc3-t.es
./esc1-r.sh ../src/main.es

### STEP2: compile esc3 .ast to .ast.abc

### STEP 3: compile .ast to .abc using esc3-r

./esc3-r.sh ../src/debug.es
./esc3-r.sh ../src/util.es
./esc3-r.sh ../src/util-tamarin.es
./esc3-r.sh ../src/lex-char.es
./esc3-r.sh ../src/lex-token.es
./esc3-r.sh ../src/lex-scan.es
./esc3-r.sh ../src/ast.es
./esc3-r.sh ../src/ast-decode.es
./esc3-r.sh ../src/ast-encode.es
./esc3-r.sh ../src/parse-util.es
./esc3-r.sh ../src/parse-ident.es
./esc3-r.sh ../src/parse-lhsexpr.es
./esc3-r.sh ../src/parse-assignexpr.es
./esc3-r.sh ../src/parse-ptrn.es
./esc3-r.sh ../src/parse-type.es
./esc3-r.sh ../src/parse-stmt.es
./esc3-r.sh ../src/parse-defn.es
./esc3-r.sh ../src/parse-prgm.es
./esc3-r.sh ../src/bytes.es
./esc3-r.sh ../src/asm.es
./esc3-r.sh ../src/abc.es
./esc3-r.sh ../src/emit.es
./esc3-r.sh ../src/cogen.es
./esc3-r.sh ../src/cogen-stmt.es
./esc3-r.sh ../src/cogen-expr.es
./esc3-r.sh ../src/esc1-t.es
./esc3-r.sh ../src/esc2-t.es
./esc3-r.sh ../src/esc3-t.es
./esc3-r.sh ../src/main.es

### STEP 4: compile .ast.abc to .abc using esc3-t

