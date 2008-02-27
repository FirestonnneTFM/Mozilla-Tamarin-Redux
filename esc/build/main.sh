# Interactive/non-interactive interpreter with eval.
#
# If file name arguments are present then they are compiled, 
# loaded, and executed before the shell exits.  Otherwise 
# the shell enters a repl.

DIR=../bin

$DIR/shell \
    $DIR/debug.es.abc \
    $DIR/util.es.abc \
    $DIR/bytes-tamarin.es.abc \
    $DIR/util-tamarin.es.abc \
    $DIR/lex-char.es.abc \
    $DIR/lex-token.es.abc \
    $DIR/lex-scan.es.abc \
    $DIR/ast.es.abc \
    $DIR/ast-decode.es.abc \
    $DIR/parse.es.abc \
    $DIR/asm.es.abc \
    $DIR/abc.es.abc \
    $DIR/emit.es.abc \
    $DIR/cogen.es.abc \
    $DIR/cogen-stmt.es.abc \
    $DIR/cogen-expr.es.abc \
    $DIR/esc-core.es.abc \
    $DIR/eval-support.es.abc \
    $DIR/main.es.abc \
    -- $@
