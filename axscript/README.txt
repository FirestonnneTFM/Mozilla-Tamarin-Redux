This is the readme for axtam - Active Scripting implemented using Tamarin.
--------------------------------------------------------------------------

This is still very early - not much works yet!  See the 'axscript/test'
directory, where things will generally be more up-to-date than this README 
is; currently tested are IE and WSH.

Building
---------

* Build the standard tamarim 'avmplus' project.  This will create the core
  tamarin static libraries used by axtam.

* Load vc8/axtam.dsp into Microsoft Visual Studio 2005 - there is no support 
  for earlier versions.  Select the same configuration you used for avmplus.

* Build it - a custom build step will also register the engine.  Only debug 
  builds work - release builds fail in strange ways.

After this, engines named 'application/ecmascript;version=4' and 
'application/javascript;version=2' are available - they are currently 
identical.  Note that no file extension is currently registered for this 
engine, so the engine name will need to be explicitly specified.

Test it
--------

See README.txt in the test directory.
