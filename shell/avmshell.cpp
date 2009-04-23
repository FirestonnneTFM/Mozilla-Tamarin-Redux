/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "avmshell.h"

#if !defined(UNDER_CE) && !defined(AVM_SHELL_NO_PROJECTOR)
#  define AVMSHELL_PROJECTOR_SUPPORT
#endif

#define VMCFG_WORKERTHREADS

#if (defined WIN32 && !defined UNDER_CE) || defined AVMPLUS_UNIX
bool P4Available();
#endif

// [tpr] I removed the override global new stuff, it was apparently added b/c we'd crash when 
// OS would use our new pre-main that was fixed by making the project not export any 
// symbols other than main

namespace avmplus {
	namespace NativeID {
		using namespace avmshell;
		#include "shell_toplevel.cpp"
	}

#ifdef AVMPLUS_JITMAX
	extern int jitmax;
    extern int jitmin;
#endif
}

namespace avmshell
{
	const int kScriptTimeout = 15;
	const int kScriptGracePeriod = 5;

#ifdef AVMPLUS_WIN32
	// An ugly hack
	bool show_error = false;
#endif

	static bool isValidProjectorFile(const char* filename)
	{
		FileInputStream file(filename);
		uint8_t header[8];
		
		if (!file.valid())
			return false;
		
		file.seek(file.length() - 8);
		file.read(header, 8);
		
		// Check the magic number
		if (header[0] != 0x56 || header[1] != 0x34 || header[2] != 0x12 || header[3] != 0xFA)
			return false;
		
		return true;
	}
	
	ShellToplevel::ShellToplevel(AbcEnv* abcEnv) : Toplevel(abcEnv)
	{
		shellClasses = (ClassClosure**) core()->GetGC()->Calloc(avmplus::NativeID::shell_toplevel_abc_class_count, 
																sizeof(ClassClosure*), 
																MMgc::GC::kZero | MMgc::GC::kContainsPointers);
	}
	
	void ShellCore::stackOverflow(MethodEnv *env)
	{
		if (inStackOverflow)
		{
			// Already handling a stack overflow, so do not
			// re-enter handler.
			return;
		}
			
		// Temporarily disable stack overflow checks
		// so that we can construct an exception object.
		// There should be plenty of margin before the
		// actual stack bottom to do this.
		inStackOverflow = true;

		Toplevel* toplevel = env->toplevel();

		Stringp errorMessage = getErrorMessage(kStackOverflowError);
		Atom args[2] = { nullObjectAtom, errorMessage->atom() };
		Atom errorAtom = toplevel->errorClass()->construct(1, args);
		Exception *exception = new (GetGC()) Exception(this, errorAtom);

		// Restore stack overflow checks
		inStackOverflow = false;

		// Throw the stack overflow exception
		throwException(exception);
	}
	
	/* static */
	void ShellCore::interruptTimerCallback(void* data)
	{
		((AvmCore*)data)->interrupted = true;
	}
	
	void ShellCore::interrupt(MethodEnv *env)
	{
		interrupted = false;

		Toplevel* toplevel = env->toplevel();

		if (gracePeriod) {
			// This script has already had its chance; it violated
			// the grace period.
			// Throw an exception it cannot catch.
			Stringp errorMessage = getErrorMessage(kScriptTerminatedError);
			Atom args[2] = { nullObjectAtom, errorMessage->atom() };
			Atom errorAtom = toplevel->errorClass()->construct(1, args);
			Exception *exception = new (GetGC()) Exception(this, errorAtom);
			exception->flags |= Exception::EXIT_EXCEPTION;
			throwException(exception);
		}

		// Give the script an additional grace period to
		// clean up, and throw an exception.
		gracePeriod = true;

		Platform::GetInstance()->setTimer(kScriptGracePeriod, interruptTimerCallback, this);

		toplevel->throwError(kScriptTimeoutError);
	}
	
	void ShellCore::initShellPool()
	{
		shellPool = AVM_INIT_BUILTIN_ABC(shell_toplevel, this);
	}

	Toplevel* ShellCore::initShellBuiltins()
	{
		// Initialize a new Toplevel.  This will also create a new
		// DomainEnv based on the builtinDomain.
		Toplevel* toplevel = initTopLevel();

		// Initialize the shell builtins in the new Toplevel
		handleActionPool(shellPool,
						 toplevel->domainEnv(),
						 toplevel,
						 NULL);

		return toplevel;
	}
	
	Toplevel* ShellCore::createToplevel(AbcEnv* abcEnv)
	{
		return new (GetGC()) ShellToplevel(abcEnv);
	}

#ifdef VMCFG_EVAL

	// FIXME, this is currently hokey for several reasons:
	//
	//  - Does not try to determine whether input is Latin1, UTF8, or indeed, already UTF16,
	//    but assumes UTF8, which can be dangerous.  Falls back to latin1 if the utf8 conversion
	//    fails, this seems ill-defined in the string layer though so it's just one more hack.
	//
	//  - Does not create an UTF16 string.  The string layer is actually broken on this count,
	//    because requesting an empty UTF16 string returns a constant that is a Latin1 string,
	//    and appending to it won't force the representation to UTF16 unless the data require
	//    that to happen.  See <URL:https://bugzilla.mozilla.org/show_bug.cgi?id=473995>.
	//
	//  - May incur copying because the terminating NUL is not accounted for in the original
	//    creation

	String* ShellCore::decodeBytesAsUTF16String(uint8_t* bytes, uint32_t nbytes, bool terminate)
	{
		String* s = newStringUTF8((const char*)bytes, nbytes);
		if (s == NULL)
			s = newStringLatin1((const char*)bytes, nbytes);
		if (terminate)
			s = s->appendLatin1("\0", 1);
		return s;
	}

	String* ShellCore::readFileForEval(String* referencingFile, String* filename)
	{
		// FIXME, filename sanitazion is more complicated than this
		if (referencingFile != NULL && filename->charAt(0) != '/' && filename->charAt(0) != '\\') {
			// find the last slash if any, truncate the string there, append the
			// new filename
			int32_t x = referencingFile->lastIndexOf(newStringLatin1("/"));
			if (x != -1)
				filename = referencingFile->substring(0,x+1)->append(filename);
		}
		filename = filename->appendLatin1("\0", 1);
		
		// FIXME, not obvious that UTF8 is correct for all operating systems (far from it!)
		StUTF8String fn(filename);
		FileInputStream f(fn.c_str());
		if (!f.valid() || (uint64_t) f.length() >= UINT32_T_MAX)
			return NULL;

		uint32_t nbytes = (uint32_t) f.available();
		uint8_t* bytes = new uint8_t[nbytes];
		f.read(bytes, nbytes);
		String* str = decodeBytesAsUTF16String(bytes, nbytes, true);
		delete [] bytes;
		return str;
	}
	
	// input is always NUL-terminated
	void ShellCore::evaluateAtToplevel(String* input, bool record_time)
	{
		minstack = Platform::GetInstance()->getStackBase();
		
		ShellCodeContext* codeContext = new (GetGC()) ShellCodeContext();
		codeContext->m_domainEnv = shell_domainEnv;

		TRY(this, kCatchAction_ReportAsError) 
		{
			// Always Latin-1 here
			input = input->appendLatin1("\0", 1);
			double then = 0, now = 0;
			if (record_time) 
				then = VMPI_getDate();
			Atom result = handleActionSource(input, NULL, shell_domainEnv, shell_toplevel, NULL, codeContext);
			if (record_time) 
				now = VMPI_getDate();
			if (result != undefinedAtom)
				console << string(result) << "\n";
			if (record_time)
				console << "Elapsed time: " << (now - then)/1000 << "s\n";
		}
		CATCH(Exception *exception)
		{
#ifdef DEBUGGER
			if (!(exception->flags & Exception::SEEN_BY_DEBUGGER))
			{
				console << string(exception->atom) << "\n";
			}
			if (exception->getStackTrace()) {
				console << exception->getStackTrace()->format(this) << '\n';
			}
#else
			console << string(exception->atom) << "\n";
#endif
		}
		END_CATCH
		END_TRY
	}
	
#endif // VMCFG_EVAL
	
	ShellCore::ShellCore(MMgc::GC* gc) : AvmCore(gc)
	{
		systemClass = NULL;
		
		gracePeriod = false;
		inStackOverflow = false;

		allowDebugger = -1;	// aka "not yet set" 

		consoleOutputStream = new (gc) ConsoleOutputStream();
	
		setConsoleStream(consoleOutputStream);
	}

#ifdef AVMSHELL_PROJECTOR_SUPPORT
	
	// Run a known projector file
	void ShellCore::executeProjector(char *executablePath, int& exitCode)
	{
		AvmAssert(isValidProjectorFile(executablePath));
		
		uint8_t header[8];
		
		FileInputStream file(executablePath);
		
		file.seek(file.length() - 8);
		file.read(header, 8);
		
		int abcLength = (header[4]     |
						 header[5]<<8  |
						 header[6]<<16 |
						 header[7]<<24);
		
		ScriptBuffer code = newScriptBuffer(abcLength);
		file.seek(file.length() - 8 - abcLength);
		file.read(code.getBuffer(), abcLength);
		
		exitCode = handleArbitraryExecutableContent(code, executablePath);
	}
	
#endif // AVMSHELL_PROJECTOR_SUPPORT

	bool ShellCore::setup(int argc, char** argv, ShellSettings& settings)
	{
#if defined FEATURE_NANOJIT && (defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64))
	#ifdef AVMPLUS_SSE2_ALWAYS
		config.sse2 = true;
	#else
		if (!P4Available())
			config.sse2 = false;
	#endif
#endif
		
		config.interrupts = settings.interrupts;
#ifdef AVMPLUS_VERIFYALL
		config.verifyall = settings.verifyall;
#endif
#if defined FEATURE_NANOJIT
		config.cseopt = settings.cseopt;
	#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		config.sse2 = settings.sse2;
	#endif
#endif
#ifdef AVMPLUS_VERBOSE
#  ifdef FEATURE_NANOJIT
		config.bbgraph = settings.bbgraph;
#  endif
		config.verbose = settings.do_verbose;
#endif
		config.runmode = settings.runmode;
		
#ifdef DEBUGGER
	#if VMCFG_METHOD_NAMES
		// debugger in avmshell always enables methodnames. 
		if (allowDebugger)
			config.methodNames = true;
	#endif
#endif
			
#ifdef AVMPLUS_VERBOSE
	#if VMCFG_METHOD_NAMES
		// verbose requires methodnames (in avmshell, anyway), before calling initBuiltinPool.
		if (settings.do_verbose)
			config.methodNames = true;
	#endif
#endif

#ifdef DEBUGGER
		langID = settings.langID;
#endif

		GetGC()->greedy = settings.greedy;
		GetGC()->nogc = settings.nogc;
		GetGC()->incremental = settings.incremental;
		
		TRY(this, kCatchAction_ReportAsError)
		{
			minstack = Platform::GetInstance()->getStackBase();
			
			allowDebugger = !settings.nodebugger;
			
			setCacheSizes(settings.cacheSizes);

			initBuiltinPool();
			initShellPool();
			
			// init toplevel internally
			shell_toplevel = initShellBuiltins();
			
			// Create a new Domain for the user code
			shell_domain = new (GetGC()) Domain(this, builtinDomain);
			
			// Return a new DomainEnv for the user code
			shell_domainEnv = new (GetGC()) DomainEnv(this, shell_domain, shell_toplevel->domainEnv());
			
			SystemClass::user_argc = argc-settings.endFilenamePos-1; 
			SystemClass::user_argv = &argv[settings.endFilenamePos+1];

			return true;
		}
		CATCH(Exception *exception)
		{
#ifdef DEBUGGER
			if (!(exception->flags & Exception::SEEN_BY_DEBUGGER))
				console << string(exception->atom) << "\n";
			
			if (exception->getStackTrace())
				console << exception->getStackTrace()->format(this) << '\n';
#else
			// [ed] always show error, even in release mode,
			// see bug #121382
			console << string(exception->atom) << "\n";
#endif /* DEBUGGER */
			return false;
		}
		END_CATCH
		END_TRY
	}
	
	int ShellCore::execute(const char* filename, ShellSettings& settings)
	{
		if (config.interrupts)
			Platform::GetInstance()->setTimer(kScriptTimeout, interruptTimerCallback, this);
		
#ifdef AVMPLUS_VERBOSE
		if (config.verbose)
			console << "run " << filename << "\n";
#endif
		
		FileInputStream f(filename);
		bool isValid = f.valid() && ((uint64_t)f.length() < UINT32_T_MAX); //currently we cannot read files > 4GB
		if (!isValid) {
			console << "cannot open file: " << filename << "\n";
			return(1);
		}
		
		// parse new bytecode
		ScriptBuffer code = newScriptBuffer((size_t)f.available());
		f.read(code.getBuffer(), (size_t)f.available());
		
#ifdef DEBUGGER
		if (settings.enter_debugger_on_launch)
		{
			// Activate the debug CLI and stop at
			// start of program
			debugCLI()->activate();
			debugCLI()->stepInto();
		}
#else
		(void)settings.enter_debugger_on_launch;
#endif
		
		return handleArbitraryExecutableContent(code, filename);
	}

	int ShellCore::handleArbitraryExecutableContent(ScriptBuffer& code, const char * filename)
	{
		minstack = Platform::GetInstance()->getStackBase();
		
		TRY(this, kCatchAction_ReportAsError)
		{
			ShellCodeContext* codeContext = new (GetGC()) ShellCodeContext();
			codeContext->m_domainEnv = shell_domainEnv;
			
			if (AbcParser::canParse(code) == 0) {
				handleActionBlock(code, 0, shell_domainEnv, shell_toplevel, NULL, codeContext);
			}
			else if (isSwf(code)) {
				handleSwf(filename, code, shell_domainEnv, shell_toplevel, codeContext);
			}
			else {
#ifdef VMCFG_EVAL
				// FIXME: I'm assuming code is UTF8 - OK for now, but easy to go wrong; it could be 8-bit ASCII
				String* code_string = decodeBytesAsUTF16String(code.getBuffer(), (uint32_t)code.getSize(), true);
				String* filename_string = decodeBytesAsUTF16String((uint8_t*)filename, (uint32_t)VMPI_strlen(filename));
				ScriptBuffer empty;		// With luck: allow the
				code = empty;			//    buffer to be garbage collected
				handleActionSource(code_string, filename_string, shell_domainEnv, shell_toplevel, NULL, codeContext);
#else
				console << "unknown input format in file: " << filename << "\n";
				return(1);
#endif // VMCFG_EVAL
			}
		}
		CATCH(Exception *exception)
		{
#ifdef DEBUGGER
			if (!(exception->flags & Exception::SEEN_BY_DEBUGGER))
			{
				console << string(exception->atom) << "\n";
			}
			if (exception->getStackTrace()) {
				console << exception->getStackTrace()->format(this) << '\n';
			}
#else
			// [ed] always show error, even in release mode,
			// see bug #121382
			console << string(exception->atom) << "\n";
#endif /* DEBUGGER */
			
			return 1;
		}
		END_CATCH
		END_TRY
		
		return 0;
	}

	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// Driver code - Shell

	// Try not to have conditional fields in this, just leave the defaults to "off".
	// Client code can discriminate, and the command line parser will discriminate too.
	//
	// FIXME: A naming disaster.  Clean up.
	
	ShellSettings::ShellSettings()
		: filenamesPos(-1)
		, endFilenamePos(-1)
		, nodebugger(false)
		, do_repl(false)
		, do_log(false)
		, do_verbose(false)
		, enter_debugger_on_launch(false)
		, do_selftest(false)
		, st_component(NULL)
		, st_category(NULL)
		, st_name(NULL)
		, numthreads(1)
		, numworkers(1)
		, interrupts(AvmCore::interrupts_default)
		, verifyall(AvmCore::verifyall_default)
		, sse2(AvmCore::sse2_default)
		, greedy(false)
		, nogc(false)
		, incremental(true)
		, langID(-1)
		, bbgraph(AvmCore::bbgraph_default)
		, cseopt(AvmCore::cseopt_default)
		, runmode(AvmCore::runmode_default)
		, do_projector(false)
	{
	}
	
	/* static */
	int Shell::run(int argc, char *argv[]) 
	{
		MMgc::GCHeapConfig conf;
		//conf.verbose = true;
		MMgc::GCHeap::Init(conf);

		// Note that output from the command line parser will not go to the log file.

		ShellSettings settings;
		parseCommandLine(argc, argv, settings);
		
		if (settings.do_log)
		{
			if (settings.filenamesPos < settings.endFilenamePos)
				initializeLogging(argv[settings.filenamesPos]);
			else
				initializeLogging("AVMLOG");
		}

		AvmAssert( settings.numworkers == 1 && settings.numthreads == 1 );

		int exitCode = 0;
		{
			MMGC_ENTER;
			if(MMGC_ENTER_STATUS != 0) {
				// allowing control to flow below to Destroy results in tons of leak asserts
				return OUT_OF_MEMORY;
			}
			
			{
				MMgc::GC *gc = new MMgc::GC(MMgc::GCHeap::GetGCHeap());
				MMGC_GCENTER(gc);

				ShellCore* shell = new ShellCore(gc);

				if (!shell->setup(argc, argv, settings))
					Platform::GetInstance()->exit(1);
				
#ifdef AVMPLUS_SELFTEST
				if (settings.do_selftest) {
					// need minstack
					::selftests(shell, settings.st_component, settings.st_category, settings.st_name);
					goto finish;
				}
#endif
				
#ifdef AVMSHELL_PROJECTOR_SUPPORT
				if (settings.do_projector)
					shell->executeProjector(argv[0], exitCode);
#endif
				
				// execute each abc file
				for (int i=settings.filenamesPos; i < settings.endFilenamePos; i++) {
					exitCode = shell->execute(argv[i], settings);
					if (exitCode != 0) {
						// do something?
					}
				}
				
#ifdef VMCFG_EVAL
				if (settings.do_repl)
					repl(shell);
#endif
				
#ifdef AVMPLUS_WITH_JNI
				// This surely does not belong here?
				if (Java::startup_options) delete Java::startup_options;
#endif /* AVMPLUS_WITH_JNI */

#ifdef AVMPLUS_SELFTEST
			finish:
#endif
				delete shell;
				delete gc;
			}  // MMGC_GCENTER
		}  // MMGC_ENTER

		MMgc::GCHeap::Destroy();
	 	return exitCode;
	}
	
#ifdef VMCFG_EVAL

	/* static */
	void Shell::repl(ShellCore* shellCore)
	{
		const int kMaxCommandLine = 1024;
		char commandLine[kMaxCommandLine];
		String* input;

		AvmLog("avmplus interactive shell\n"
			   "Type '?' for help\n\n");
		
		for (;;)
		{
			bool record_time = false;
			AvmLog("> ");
			
			if(Platform::GetInstance()->getUserInput(commandLine, kMaxCommandLine) == NULL)
				return;
			
			commandLine[kMaxCommandLine-1] = 0;
			if (VMPI_strncmp(commandLine, "?", 1) == 0) {
				AvmLog("Text entered at the prompt is compiled and evaluated unless\n"
					   "it is one of these commands:\n\n"
					   "  ?             print help\n"
					   "  .input        collect lines until a line that reads '.end',\n"
					   "                then eval the collected lines\n"
					   "  .load file    load the file (source or compiled)\n"
					   "  .quit         leave the repl\n"
					   "  .time expr    evaluate expr and report the time it took.\n\n");
				continue;
			}
			
			if (VMPI_strncmp(commandLine, ".load", 5) == 0) {
				const char* s = commandLine+5;
				while (*s == ' ' || *s == '\t')
					s++;
				// wrong, handles only source code
				//readFileForEval(NULL, newStringLatin1(s));
				// FIXME: implement .load
				// Small amount of generalization of the code currently in the main loop should
				// take care of it.
				AvmLog("The .load command is not implemented\n");
				continue;
			}
			
			if (VMPI_strncmp(commandLine, ".input", 6) == 0) {
				input = shellCore->newStringLatin1("");
				for (;;) {
					if(Platform::GetInstance()->getUserInput(commandLine, kMaxCommandLine) == NULL)
						return;
					commandLine[kMaxCommandLine-1] = 0;
					if (VMPI_strncmp(commandLine, ".end", 4) == 0)
						break;
					input->appendLatin1(commandLine);
				}
				goto compute;
			}
			
			if (VMPI_strncmp(commandLine, ".quit", 5) == 0) {
				return;
			}
			
			if (VMPI_strncmp(commandLine, ".time", 5) == 0) {
				record_time = true;
				input = shellCore->newStringLatin1(commandLine+5);
				goto compute;
			}
			
			input = shellCore->newStringLatin1(commandLine);

		compute:
			shellCore->evaluateAtToplevel(input, record_time);
		}
	}

#endif // VMCFG_EVAL
	
	// open logfile based on a filename
	/* static */
	void Shell::initializeLogging(const char* basename)
	{
		const char* lastDot = VMPI_strrchr(basename, '.');
		if(lastDot)
		{
			//filename could contain '/' or '\' as their separator, look for both
			const char* lastPathSep1 = VMPI_strrchr(basename, '/');
			const char* lastPathSep2 = VMPI_strrchr(basename, '\\');
			if(lastPathSep1 < lastPathSep2) //determine the right-most 
				lastPathSep1 = lastPathSep2;
				
				//if dot is before the separator, the filename does not have an extension
				if(lastDot < lastPathSep1)
					lastDot = NULL;
		}
		
		//if no extension then take the entire filename or 
		size_t logFilenameLen = (lastDot == NULL) ? VMPI_strlen(basename) : (lastDot - basename); 
		
		char* logFilename = new char[logFilenameLen + 5];  // 5 bytes for ".log" + null char
		VMPI_strncpy(logFilename,basename,logFilenameLen);
		VMPI_strcpy(logFilename+logFilenameLen,".log");
		
		Platform::GetInstance()->initializeLogging(logFilename);
		
		delete [] logFilename;
	}

	/* static */
	void Shell::parseCommandLine(int argc, char* argv[], ShellSettings& settings)
	{
		bool print_version = false;
		
		// options filenames -- args
		
		for (int i=1; i < argc ; i++) {
			const char * const arg = argv[i];
			
			if (arg[0] == '-') 
			{
				if (arg[1] == '-' && arg[2] == 0) {
					if (settings.filenamesPos == -1)
						settings.filenamesPos = i;
					settings.endFilenamePos = i;
					break;
				}
				
				if (arg[1] == 'D') {
					if (!VMPI_strcmp(arg+2, "timeout")) {
						settings.interrupts = true;
					}
					else if (!VMPI_strcmp(arg+2, "version")) {
						print_version = true;
					}
					else if (!VMPI_strcmp(arg+2, "nodebugger")) {
						// allow this option even in non-DEBUGGER builds to make test scripts simpler
						settings.nodebugger = true;
					}
#ifdef AVMPLUS_IA32
					else if (!VMPI_strcmp(arg+2, "nosse")) {
#if defined FEATURE_NANOJIT
						settings.sse2 = false;
#endif
					}
#endif /* AVMPLUS_IA32 */
#ifdef AVMPLUS_VERIFYALL
					else if (!VMPI_strcmp(arg+2, "verifyall")) {
						settings.verifyall = true;
					}
#endif /* AVMPLUS_VERIFYALL */
#ifdef _DEBUG
					else if (!VMPI_strcmp(arg+2, "greedy")) {
						settings.greedy = true;
					}
#endif /* _DEBUG */
#ifdef DEBUGGER
					else if (!VMPI_strcmp(arg+2, "nogc")) {
						settings.nogc = true;
					}
					else if (!VMPI_strcmp(arg+2, "noincgc")) {
						settings.incremental = false;
					}
					else if (!VMPI_strcmp(arg+2, "astrace")) {
						avmplus::Debugger::astrace_console = (avmplus::Debugger::TraceLevel) VMPI_strtol(argv[++i], 0, 10);
					}
					else if (!VMPI_strcmp(arg+2, "language")) {
						settings.langID=-1;
						for (int j=0;j<kLanguages;j++) {
							if (!VMPI_strcmp(argv[i+1],languageNames[j].str)) {
								settings.langID=j;
								break;
							}
						}
						if (settings.langID==-1) {
							settings.langID = VMPI_atoi(argv[i+1]);
						}
						i++;
					}
#endif /* DEBUGGER */
#ifdef AVMPLUS_SELFTEST
					else if (!VMPI_strncmp(arg+2, "selftest", 8)) {
						settings.do_selftest = true;
						if (arg[10] == '=') {
							VMPI_strncpy(settings.st_mem, arg+11, sizeof(settings.st_mem));
							settings.st_mem[sizeof(settings.st_mem)-1] = 0;
							char *p = settings.st_mem;
							settings.st_component = p;
							while (*p && *p != ',')
								p++;
							if (*p == ',')
								*p++ = 0;
							settings.st_category = p;
							while (*p && *p != ',')
								p++;
							if (*p == ',')
								*p++ = 0;
							settings.st_name = p;
							if (*settings.st_component == 0)
								settings.st_component = NULL;
							if (*settings.st_category == 0)
								settings.st_category = NULL;
							if (*settings.st_name == 0)
								settings.st_name = NULL;
						}
					}
#endif /* AVMPLUS_SELFTEST */
#ifdef AVMPLUS_VERBOSE
					else if (!VMPI_strcmp(arg+2, "verbose")) {
						settings.do_verbose = true;
					}
					else if (!VMPI_strcmp(arg+2, "verbose_init")) {
						settings.do_verbose = true;
					}
#endif /* AVMPLUS_VERBOSE */
#if defined FEATURE_NANOJIT && defined AVMPLUS_VERBOSE
					else if (!VMPI_strcmp(arg+2, "bbgraph")) {
						settings.bbgraph = true;  // generate basic block graph (only valid with JIT)
                    }
#endif /* FEATURE_NANOJIT && AVMPLUS_VERBOSE */
#ifdef FEATURE_NANOJIT
					else if (!VMPI_strcmp(arg+2, "nocse")) {
						settings.cseopt = false;
					}
#endif /* FEATURE_NANOJIT */
					else if (!VMPI_strcmp(arg+2, "interp")) {
						settings.runmode = RM_interp_all;
					}
					else {
						usage();
					}
				} 
				else if (!VMPI_strcmp(arg, "-cache_bindings")) {
					settings.cacheSizes.bindings = (uint16_t)VMPI_strtol(argv[++i], 0, 10);
				}
				else if (!VMPI_strcmp(arg, "-cache_metadata")) {
					settings.cacheSizes.metadata = (uint16_t)VMPI_strtol(argv[++i], 0, 10);
				}
				else if (!VMPI_strcmp(arg, "-cache_methods")) {
					settings.cacheSizes.methods = (uint16_t)VMPI_strtol(argv[++i], 0, 10);
				}
#ifdef FEATURE_NANOJIT
				else if (!VMPI_strcmp(arg, "-Ojit")) {
					settings.runmode = RM_jit_all;
				} 
#endif /* FEATURE_NANOJIT */
#ifdef AVMPLUS_JITMAX
				else if (!VMPI_strcmp(arg, "-jitmax")) {
					char* val = argv[++i];
					char* dash = VMPI_strchr(val,'-');
					if (dash) {
						if (dash==&val[0]) 
							jitmax = VMPI_atoi(&val[1]); // -n form
						else {
							int32_t hl = VMPI_strlen(dash);
							dash[0] = '\0'; // hammer argv ;)  - go boom?
							jitmin = VMPI_atoi(val); 
							if (hl>1)
								jitmax = VMPI_atoi(&dash[1]); 
						}
					} else {                                            
						jitmax = VMPI_atoi(val);
					}
				}
#endif /* AVMPLUS_JITMAX */
				else if (!VMPI_strcmp(arg, "-memstats")) {
					MMgc::GCHeap::GetGCHeap()->Config().gcstats = true;
					MMgc::GCHeap::GetGCHeap()->Config().autoGCStats = true;
				}
				else if (!VMPI_strcmp(arg, "-memlimit")) {
					MMgc::GCHeap::GetGCHeap()->SetHeapLimit(VMPI_strtol(argv[++i], 0, 10));
				}
				else if (!VMPI_strcmp(arg, "-log")) {
					settings.do_log = true;
				} 
#ifdef VMCFG_EVAL
				else if (!VMPI_strcmp(arg, "-repl")) {
					settings.do_repl = true;
				}
#endif /* VMCFG_EVAL */
#ifdef VMCFG_WORKERTHREADS
				else if (!VMPI_strcmp(arg, "-workers")) {
					const char *val = argv[++i];
					int nchar;
					if (val == NULL)
						val = "";
					if (sscanf(val, "%d,%d%n", &settings.numthreads, &settings.numworkers, &nchar) != 2 || 
						settings.numthreads < 1 || 
						settings.numworkers < settings.numthreads || 
						size_t(nchar) != VMPI_strlen(val))
						usage();
				}
#endif // VMCFG_WORKERTHREADS
#ifdef AVMPLUS_WIN32
				else if (!VMPI_strcmp(arg, "-error")) {
					show_error = true;
#ifndef UNDER_CE
					SetErrorMode(0);  // set to default
#endif
				}
#endif // AVMPLUS_WIN32
#ifdef AVMPLUS_WITH_JNI
				else if (!VMPI_strcmp(arg, "-jargs")) {
					// all the following args until the semi colon is for java.
					//@todo fix up this hard limit
					bool first = true;
					Java::startup_options = new char[256];
					VMPI_memset(Java::startup_options, 0, 256);
					
					for(i++; i<argc; i++)
					{
						if (*argv[i] == ';')
							break;
						if (!first) VMPI_strcat(Java::startup_options, " ");
						VMPI_strcat(Java::startup_options, argv[i]);
						first = false;
					}
					AvmAssert(VMPI_strlen(Java::startup_options) < 256);
				}
#endif /* AVMPLUS_WITH_JNI */
#ifdef DEBUGGER
				else if (!VMPI_strcmp(arg, "-d")) {
					settings.enter_debugger_on_launch = true;
				}
#endif /* DEBUGGER */
				else {
					// Unrecognized command line option
					AvmLog("Unrecognized option %s\n", arg);
					usage();
				}
			}
			else {
				if (settings.filenamesPos == -1)
					settings.filenamesPos = i;
			}
		}
		
		if (settings.filenamesPos == -1)
			settings.filenamesPos = argc;
		
		if (settings.endFilenamePos == -1)
			settings.endFilenamePos = argc;
		
		AvmAssert(settings.filenamesPos != -1 && settings.endFilenamePos != -1 && settings.filenamesPos <= settings.endFilenamePos);

		if (print_version)
		{
			AvmLog("shell " AVMPLUS_VERSION_USER " build " AVMPLUS_BUILD_CODE "\n");
			AvmLog("features %s\n", avmfeatures);
			Platform::GetInstance()->exit(1);
		}
		
		// Vetting the options
		
		if (isValidProjectorFile(argv[0])) {
			if (settings.do_selftest || settings.do_repl || settings.filenamesPos < settings.endFilenamePos) {
				AvmLog("Projector files can't be used with -repl, -Dselftest, or program file arguments.\n");
				usage();
			}
			if (settings.numthreads > 1 || settings.numworkers > 1) {
				AvmLog("A projector requires exactly one worker on one thread.\n");
				usage();
			}
			settings.do_projector = 1;
			return;
		}

		if (settings.filenamesPos == settings.endFilenamePos) {
			// no files, so we need something more
			if (!settings.do_selftest && !settings.do_repl) {
				AvmLog("You must provide input files, -repl, or -Dselftest, or the executable must be a projector file.\n");
				usage();
			}
		}

#ifdef VMCFG_EVAL
		if (settings.do_repl)
		{
			if (settings.numthreads > 1 || settings.numworkers > 1) {
				AvmLog("The REPL requires exactly one worker on one thread.\n");
				usage();
			}
		}
#endif
		
#ifdef AVMPLUS_SELFTEST
		if (settings.do_selftest)
		{
			// Presumably we'd want to use the selftest harness to test multiple workers eventually.
			if (settings.numthreads > 1 || settings.numworkers > 1 || settings.filenamesPos < settings.endFilenamePos) {
				AvmLog("The selftest harness requires exactly one worker on one thread, and no input files.\n");
				usage();
			}
		}
#endif
	}
	
	// Does not return

	/*static*/
	void Shell::usage()
	{
		AvmLog("avmplus shell " AVMPLUS_VERSION_USER " build " AVMPLUS_BUILD_CODE "\n\n");
		AvmLog("usage: avmplus\n");
#ifdef DEBUGGER
		AvmLog("          [-d]          enter debugger on start\n");
#endif
		AvmLog("          [-memstats]   generate statistics on memory usage\n");
		AvmLog("          [-memlimit d] limit the heap size to d pages\n");
		AvmLog("          [-cache_bindings N]   size of bindings cache (0 = unlimited)\n");
		AvmLog("          [-cache_metadata N]   size of metadata cache (0 = unlimited)\n");
		AvmLog("          [-cache_methods  N]   size of method cache (0 = unlimited)\n");
#ifdef _DEBUG
		AvmLog("          [-Dgreedy]    collect before every allocation\n");
#endif
#ifdef DEBUGGER
		AvmLog("          [-Dnogc]      don't collect\n");
		AvmLog("          [-Dnoincgc]   don't use incremental collection\n");
		AvmLog("          [-Dastrace N] display AS execution information, where N is [1..4]\n");
		AvmLog("          [-Dlanguage l] localize runtime errors, languages are:\n");
		AvmLog("                        en,de,es,fr,it,ja,ko,zh-CN,zh-TW\n");
#endif
		AvmLog("          [-Dinterp]    do not generate machine code, interpret instead\n");
#ifdef AVMPLUS_VERBOSE
		AvmLog("          [-Dverbose]   trace every instruction (verbose!)\n");
		AvmLog("          [-Dverbose_init] trace the builtins too\n");
		AvmLog("          [-Dbbgraph]   output JIT basic block graphs for use with Graphviz\n");
#endif
#ifdef FEATURE_NANOJIT
		AvmLog("          [-Ojit]       use jit always, never interp\n");
		AvmLog("          [-Dnocse]     disable CSE optimization \n");
	#ifdef AVMPLUS_IA32
        AvmLog("          [-Dnosse]     use FPU stack instead of SSE2 instructions\n");
	#endif
#endif
#ifdef AVMPLUS_JITMAX
        AvmLog("          [-jitmax N-M] jit the Nth to Mth methods only; N- and -M are also valid.\n");
#endif
#ifdef AVMPLUS_VERIFYALL
	    AvmLog("          [-Dverifyall] verify greedily instead of lazily\n");
#endif
#ifdef AVMPLUS_SELFTEST
		AvmLog("          [-Dselftest[=component,category,test]]  run selftests\n");
#endif
		AvmLog("          [-Dtimeout]   enforce maximum 15 seconds execution\n");
		AvmLog("          [-Dversion]   print the version and the list of compiled-in features and then exit\n");
#ifdef AVMPLUS_WIN32
		AvmLog("          [-error]      crash opens debug dialog, instead of dumping\n");
#endif
#ifdef VMCFG_EVAL
		AvmLog("          [-repl]       read-eval-print mode\n");
#endif
#ifdef VMCFG_WORKERTHREADS
		AvmLog("          [-workers W,T]  Spawn W worker VMs on T threads where W >= T and T >= 1.\n");
		AvmLog("                          The files provided are handed off to the workers in the order given,\n");
		AvmLog("                          as workers become available, and these workers are scheduled onto threads\n");
		AvmLog("                          in a deterministic order that prevents them from having affinity to a thread.\n");
		AvmLog("                          To test this functionality you want many more files than workers and many more\n");
		AvmLog("                          workers than threads, and at least two threads.\n");
#endif
		AvmLog("          [-log]\n");
		AvmLog("          [-jargs ... ;] args passed to Java runtime\n");
		AvmLog("          [filename.{abc,swf} ...\n");
		AvmLog("          [-- application argument ...]\n");
		Platform::GetInstance()->exit(1);
	}
}

