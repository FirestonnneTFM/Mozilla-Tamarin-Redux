ANTLR_HOME=../../other-licenses/ANTLR
ANTLR_RUNTIME=$ANTLR_HOME/antlr-runtime-3.0.1.jar

# Classpath set for Cygwin systems
java -ea -classpath lib/abcasm.jar\;$ASC\;$ANTLR_RUNTIME adobe.abcasm.Main $*

# 'NIX systems use this classpath
#java -ea -classpath lib/abcasm.jar:$ASC:$ANTLR_RUNTIME adobe.abcasm.Main $*

# -jar option doesn't work, since
# the ASC jar isn't on a relative path
#java -ea  -jar lib/abcasm.jar $*
