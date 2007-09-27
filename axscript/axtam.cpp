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
 * The Original Code is [ActiveScripting implemented with Tamarin].
 *
 * The Initial Developer of the Original Code is Mozilla Corp.
 * Portions created by the Initial Developer are Copyright (C) 2007
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Mark Hammond.
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

// axtam.cpp : Implementation of DLL Exports and general initialization code.


#include "axtam.h"
#include "resource.h"
#include "mmsystem.h" // timer related functions

#include "Profiler.h"

#include "MSCom.h"
#include "SystemClass.h"
#include "AdaptActiveScriptSite.h"
#include "COMErrorClass.h"

// files cloned from the shell
namespace axtam {
class ByteArrayObject;
class ByteArray;
}
#include "DataIO.h"
#include "ByteArrayGlue.h"
#include "DomainClass.h"

#include <fstream> // while we still load .abc files...


using namespace avmplus::NativeID;

// tamarin initialization, initialization of our extensions, etc
// cloned from tamarin's "shell" utility - hopefully it will become clear
// what all this does at some stage :)
//using namespace avmshell;

namespace axtam
{
	#include "axtoplevel.cpp"

	const int kScriptTimeout = 15;
	const int kScriptGracePeriod = 5;

	HINSTANCE AXTam::hinstance = 0;

	BEGIN_NATIVE_CLASSES(AXTam)
		NATIVE_CLASS(abcclass_axtam_com_MSCom,      MSComClass,        ScriptObject)
		NATIVE_CLASS(abcclass_axtam_System,         SystemClass,       ScriptObject)
		NATIVE_CLASS(abcclass_axtam_com_adaptors_consumer_ScriptSite,
		                                            AdaptActiveScriptSiteClass, ScriptObject)
		NATIVE_CLASS(abcclass_axtam_com_Error,      COMErrorClass,     ScriptObject)
		// clones from the shell
		NATIVE_CLASS(abcclass_avmplus_Domain,          DomainClass,        DomainObject)
		NATIVE_CLASS(abcclass_flash_utils_ByteArray,    ByteArrayClass,     ByteArrayObject)

	END_NATIVE_CLASSES()

	BEGIN_NATIVE_SCRIPTS(AXTam)
		NATIVE_SCRIPT(0, AxtamScript)
	END_NATIVE_SCRIPTS()

	BEGIN_NATIVE_MAP(AxtamScript)
	END_NATIVE_MAP()

	//ConsoleOutputStream *consoleOutputStream;

//	Shell *shell = NULL;
	bool show_error = false;

	void CALLBACK TimeoutProc(UINT /*uTimerID*/,
							  UINT /*uMsg*/,
							  DWORD_PTR dwUser,
							  DWORD_PTR /*dw1*/,
							  DWORD_PTR /*dw2*/)
	{
		AvmCore *core = (AvmCore*)dwUser;
		core->interrupted = true;
	}

	// Get ready for hosting a new script environment.
	HRESULT AXTam::InitNew(IActiveScript *as) {
		this->as = as;
		initBuiltinPool();
		initAXPool();

		#ifdef DEBUGGER
		// Create the debugger
		//debugger = new (gc) DebugCLI(this);

		// Create the profiler
		profiler = new (gc) axtam::Profiler(this);
		#endif

		// init toplevel internally
		toplevel = initAXTamBuiltins();

		return S_OK;
	}

	HRESULT AXTam::Close() {
		as = NULL;
		return S_OK;
	}
	
	void AXTam::initAXPool()
	{
		AbstractFunction *nativeMethods[axtoplevel_abc_method_count];
		NativeClassInfo *nativeClasses[axtoplevel_abc_class_count];
		NativeScriptInfo *nativeScripts[axtoplevel_abc_script_count];

		memset(nativeMethods, 0, sizeof(AbstractFunction*)*axtoplevel_abc_method_count);
		memset(nativeClasses, 0, sizeof(NativeClassInfo*)*axtoplevel_abc_class_count);
		memset(nativeScripts, 0, sizeof(NativeScriptInfo*)*axtoplevel_abc_script_count);

		initNativeTables(classEntries, scriptEntries, 
			nativeMethods, nativeClasses, nativeScripts);

		avmplus::ScriptBuffer code = newScriptBuffer(axtoplevel_abc_length);
		memcpy(code.getBuffer(), axtoplevel_abc_data, axtoplevel_abc_length);
		pool = parseActionBlock(code, 0, NULL, builtinDomain, nativeMethods, nativeClasses, nativeScripts);
		#ifdef AVMPLUS_VERBOSE
		//pool->verbose = true;
		#endif
	}


	Toplevel* AXTam::initAXTamBuiltins()
	{
		// Initialize a new Toplevel.  This will also create a new
		// DomainEnv based on the builtinDomain.
		Toplevel* toplevel = initTopLevel();

		// load up the compiler (this list comes from esc/build/esc.sh)
		// This is hacked in under the assumption we will come up with a
		// better strategy.
		static const wchar_t *abcs[] = {
			L"debug.es.abc",           L"ast.es.abc",          L"ast-decode.es.abc",
			L"util.es.abc",            L"lex-char.es.abc",
			L"lex-token.es.abc",       L"lex-scan.es.abc",     L"parse.es.abc",
			L"util-tamarin.es.abc",    L"bytes-tamarin.es.abc",L"util-tamarin.es.abc",
			L"asm.es.abc",             L"abc.es.abc",          L"emit.es.abc",
			L"cogen.es.abc",           L"cogen-stmt.es.abc",   L"cogen-expr.es.abc",
			NULL
		};
		// first of these directories with abcs[0] wins...
		static const wchar_t *candidates[] = {
			L"..\\..\\..\\esc\\bin\\", // for running directly from the source tree
			L"",
			NULL
		};
		wchar_t fqname[MAX_PATH+100] = {L'\0'}; // space for candidate path too...
		rsize_t fqsize = sizeof(fqname)/sizeof(fqname[0]);

		wchar_t *fqtail; // point into fqname where the tail starts.
		GetModuleFileNameW(axtam::AXTam::hinstance, fqname, fqsize);
		fqtail = wcsrchr(fqname, L'\\');
		if (fqtail)
			fqtail += 1;
		else // unlikely, but...
			fqtail = fqname;
		rsize_t tailsize = fqsize - (fqtail-fqname);
		const wchar_t **candidate;
		for (candidate=candidates;*candidate;candidate++) {
			wcscpy_s(fqtail, tailsize, *candidate);
			wcscat_s(fqtail, tailsize, abcs[0]);
			if (0xFFFFFFFF != GetFileAttributesW(fqname)) {
				// yay - found the path they live in - load-em up.
				const wchar_t **abc;
				for (abc=abcs;*abc;abc++) {
					wcscpy_s(fqtail, tailsize, *candidate);
					wcscat_s(fqtail, tailsize, *abc);
					Stringp fname = new (GetGC()) String((wchar *)fqname, wcslen(fqname));
					// XXX - this will be wrong for non-ascii names!
					std::fstream file((char *)fname->toUTF8String()->c_str(), std::ios_base::in | std::ios_base::binary | std::ios_base::ate);
					std::ifstream::pos_type size(file.tellg());
					ScriptBuffer code = newScriptBuffer(size);
					file.seekg(0);
					file.read((char *)code.getBuffer(), size);
					axtam::CodeContext* codeContext = new (GetGC()) axtam::CodeContext(toplevel->domainEnv());
					// parse new bytecode
					handleActionBlock(code, 0, toplevel->domainEnv(), toplevel, NULL, NULL, NULL, codeContext);
				}
			}
			break; // all done
		}

		// Initialize the parser in our Toplevel
		handleActionPool(pool,
						 toplevel->domainEnv(),
						 toplevel,
						 NULL);
		return toplevel;
	}

	void AXTam::dumpException(Exception *exception)
	{
		#ifdef DEBUGGER
		if (!(exception->flags & Exception::SEEN_BY_DEBUGGER))
		{
			ATLTRACE2((wchar_t *)this->string(exception->atom)->c_str());
			ATLTRACE2("\n");
		}
		if (exception->getStackTrace()) {
			ATLTRACE2((const wchar_t *)exception->getStackTrace()->format(this)->c_str());
			ATLTRACE2("\n");
		}
		#else
			ATLTRACE2((wchar_t *)this->string(exception->atom)->c_str());
			ATLTRACE2("\n");
		#endif
	}

	AXTam::AXTam(MMgc::GC *gc) : AvmCore(gc), pool(NULL), mscomClass(NULL), toplevel(NULL)
	{
//		systemClass = NULL;
		
		gracePeriod = false;
		inStackOverflow = false;

//		computeStackBase();

		OutputStream *outputStream = new (gc) OutputStream();
		setConsoleStream(outputStream);
	}

	void AXTam::interrupt(MethodEnv *env)
	{
		interrupted = false;

		Toplevel *toplevel = env->vtable->toplevel;

		if (gracePeriod) {
			// This script has already had its chance; it violated
			// the grace period.
			// Throw an exception it cannot catch.
			Stringp errorMessage = getErrorMessage(kScriptTerminatedError);
			Atom args[2] = { nullObjectAtom, errorMessage->atom() };
			Atom errorAtom = toplevel->errorClass()->construct(1, args);
			Exception *exception = new (GetGC()) Exception(errorAtom
													  #ifdef DEBUGGER
													  ,this
													  #endif
													  );
			exception->flags |= Exception::EXIT_EXCEPTION;
			throwException(exception);
		}

		// Give the script an additional grace period to
		// clean up, and throw an exception.
		gracePeriod = true;

		#ifdef WIN32
		timeSetEvent(kScriptGracePeriod*1000,
					 kScriptGracePeriod*1000,
					 (LPTIMECALLBACK)TimeoutProc,
					 (DWORD_PTR)this,
					 TIME_ONESHOT);
		#else
		#ifndef AVMPLUS_ARM // TODO AVMPLUS_ARM
		alarm(kScriptGracePeriod);
		#endif
		#endif

		toplevel->throwError(kScriptTimeoutError);
	}

	void AXTam::stackOverflow(MethodEnv *env)
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

		Toplevel *toplevel = env->vtable->toplevel;

		Stringp errorMessage = getErrorMessage(kStackOverflowError);
		Atom args[2] = { nullObjectAtom, errorMessage->atom() };
		Atom errorAtom = toplevel->errorClass()->construct(1, args);
		Exception *exception = new (GetGC()) Exception(errorAtom
		#ifdef DEBUGGER
		                                               ,this
		#endif
		);

		// Restore stack overflow checks
		inStackOverflow = false;

		// Throw the stack overflow exception
		throwException(exception);
	}

	void AXTam::throwCOMError(HRESULT hr){
		// hrm - not sure this is working ok...
		AvmAssert(0);
		comErrorClass()->throwError(hr);
		AvmAssert(0); // not reached
	}

} /* end of namespace AXTam */


// DLL initialization, COM registration and other fun stuff.
class CAXTamarinModule : public CAtlDllModuleT< CAXTamarinModule >
{
public :
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SCREAMINGMONKEY, "{FA7B55ED-3B6E-4043-A196-070BE246A194}")
};

CAXTamarinModule _AtlModule;


#ifdef _MANAGED
#pragma managed(push, off)
#endif

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	axtam::AXTam::hinstance = hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved); 
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer(FALSE);
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer(FALSE);
	return hr;
}

