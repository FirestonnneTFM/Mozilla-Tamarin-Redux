# For GNU make.
#
# Recompile the compiler using the compiler in ../bin.
#
# Fall back on the script in comp-es.sh if this makefile gives you trouble.
# Please update comp-es.sh if you change TARGETS below.

ESC=./esc.sh

DIR=../src
TARGETS=$(DIR)/debug.es.abc $(DIR)/util.es.abc $(DIR)/util-tamarin.es.abc $(DIR)/lex-char.es.abc $(DIR)/lex-token.es.abc \
	$(DIR)/lex-scan.es.abc $(DIR)/ast.es.abc $(DIR)/ast-decode.es.abc $(DIR)/ast-encode.es.abc $(DIR)/parse.es.abc \
	$(DIR)/bytes-tamarin.es.abc $(DIR)/asm.es.abc $(DIR)/abc.es.abc $(DIR)/abc-encode.es.abc $(DIR)/abc-decode.es.abc \
	$(DIR)/emit.es.abc $(DIR)/cogen.es.abc $(DIR)/cogen-stmt.es.abc $(DIR)/cogen-expr.es.abc $(DIR)/esc1-t.es.abc \
	$(DIR)/esc2-t.es.abc $(DIR)/esc3-t.es.abc $(DIR)/esc.es.abc $(DIR)/main.es.abc

default: $(TARGETS)
	cp $(TARGETS) ../bin

all:	clean
	$(MAKE)

clean:
	rm -f $(TARGETS)

$(TARGETS): %.es.abc: %.es
	$(ESC) $<
