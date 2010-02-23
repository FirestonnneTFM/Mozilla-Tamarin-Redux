# -*- gdb-script -*-
# To use this file type from the gdb prompt:
# source utils/as3.gdbinit
# or include in your .gdbinit
#
# Note that the gdb scripting language is rather limited.
# In case of undefined symbols, try running the gdb 'where' command before aswhere.
#
# Typical use case:
# (gdb) run
# ^C
# (gdb) where
# (gdb) aswhere
# (gdb) asframe 4    # select 4th AS3 frame from the top
# (gdb) aslocal      # print locals
# (gdb) aslocal 2    # print 2nd local as a C++ value
# $42 = ....
# (gdb) print *$42   # dereference  $42, assuming it's a pointer

define aswhere
print avmshell::DebugCLI::bt()
end


set var $_asframe_selected=-1

define asframe 
  if ($argc == 0)
    print  $_asframe_selected 
  else
    set var $_asframe_selected=$arg0
  end
  if ($_asframe_selected >= 0)
    print avmshell::DebugCLI::printFrame($_asframe_selected)
  end
end

# not pretty, but there's no switch
define aslocal
  if $argc == 0
    print avmshell::DebugCLI::locals($_asframe_selected)
  else
    set var $_last_type=avmshell::DebugCLI::autoAtomKindAt($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_LOCAL) 
    if ($_last_type == 0)
      print "unknown"
    end
    if ($_last_type == 1)
      print avmshell::DebugCLI::autoVarAsObject($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_LOCAL) 
    end
    if ($_last_type == 2)
      print avmshell::DebugCLI::autoVarAsString($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_LOCAL) 
    end
    if ($_last_type == 3)
      print "namespace (unfinished)"
    end
    if ($_last_type == 4)
      print "undefined"
    end
    if ($_last_type == 5)
      print avmshell::DebugCLI::autoVarAsBoolean($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_LOCAL) 
    end
    if ($_last_type == 6)
      print avmshell::DebugCLI::autoVarAsInteger($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_LOCAL) 
    end
    if ($_last_type == 7)
      print avmshell::DebugCLI::autoVarAsDouble($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_LOCAL) 
    end
  end
end

define asarg
  if $argc == 0
    print avmshell::DebugCLI::arguments($_asframe_selected)
  else
    set var $_last_type=avmshell::DebugCLI::autoAtomKindAt($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_ARGUMENT) 
    if ($_last_type == 0)
      print "unknown"
    end
    if ($_last_type == 1)
      print avmshell::DebugCLI::autoVarAsObject($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_ARGUMENT) 
    end
    if ($_last_type == 2)
      print avmshell::DebugCLI::autoVarAsString($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_ARGUMENT) 
    end
    if ($_last_type == 3)
      print "namespace (unfinished)"
    end
    if ($_last_type == 4)
      print "undefined"
    end
    if ($_last_type == 5)
      print avmshell::DebugCLI::autoVarAsBoolean($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_ARGUMENT) 
    end
    if ($_last_type == 6)
      print avmshell::DebugCLI::autoVarAsInteger($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_ARGUMENT) 
    end
    if ($_last_type == 7)
      print avmshell::DebugCLI::autoVarAsDouble($_asframe_selected, $arg0, avmshell::DebugCLI::AUTO_ARGUMENT) 
    end
  end
end





