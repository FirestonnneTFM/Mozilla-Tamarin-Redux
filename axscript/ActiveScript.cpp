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
#include "axtam.h"
#include "mscom.h"
#include "ActiveScriptError.h"

using namespace axtam;

static MMgc::FixedMalloc* fm = NULL;

class ATL_NO_VTABLE CActiveScript :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CActiveScript, &CLSID_ActiveScript>,
	public IActiveScript, // is this correct?
	public IActiveScriptParseProcedure2,
	public IActiveScriptParse,
	public IObjectSafety
{
public:
	CActiveScript();
	virtual ~CActiveScript() {;}

	// Our AvmCore instance.
	AXTam *core;

	// we hold a pointer to a script object for delegation, but can't subclass
	// as the MMgc did not allocate our mem.
	MMgc::GCRoot *root; 

	DECLARE_REGISTRY_RESOURCEID(IDR_ACTIVESCRIPT)

	BEGIN_COM_MAP(CActiveScript)
		COM_INTERFACE_ENTRY(IActiveScript)
		COM_INTERFACE_ENTRY(IActiveScriptParseProcedure2)
		COM_INTERFACE_ENTRY(IActiveScriptParse)
		COM_INTERFACE_ENTRY(IObjectSafety)
	END_COM_MAP()

	BEGIN_CATEGORY_MAP(CActiveScript)
		IMPLEMENTED_CATEGORY(AXT_CATID_ActiveScript)
		IMPLEMENTED_CATEGORY(AXT_CATID_ActiveScriptParse)
	END_CATEGORY_MAP()

	// IActiveScript
    STDMETHOD(SetScriptSite)( 
        /* [in] */ IActiveScriptSite *pass);
    
    STDMETHOD(GetScriptSite)( 
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ void **ppvObject);
    
    STDMETHOD(SetScriptState)( 
        /* [in] */ SCRIPTSTATE ss);

    STDMETHOD(GetScriptState)( 
        /* [out] */ SCRIPTSTATE *pssState);

    STDMETHOD(Close)(void);

    STDMETHOD(AddNamedItem)( 
        /* [in] */ LPCOLESTR pstrName,
        /* [in] */ DWORD dwFlags);

    STDMETHOD(AddTypeLib)( 
        /* [in] */ REFGUID rguidTypeLib,
        /* [in] */ DWORD dwMajor,
        /* [in] */ DWORD dwMinor,
        /* [in] */ DWORD dwFlags);

    STDMETHOD(GetScriptDispatch)( 
        /* [in] */ LPCOLESTR pstrItemName,
        /* [out] */ IDispatch **ppdisp);

    STDMETHOD(GetCurrentScriptThreadID)( 
        /* [out] */ SCRIPTTHREADID *pstidThread);

    STDMETHOD(GetScriptThreadID)( 
        /* [in] */ DWORD dwWin32ThreadId,
        /* [out] */ SCRIPTTHREADID *pstidThread);
    
    STDMETHOD(GetScriptThreadState)( 
        /* [in] */ SCRIPTTHREADID stidThread,
        /* [out] */ SCRIPTTHREADSTATE *pstsState);

    STDMETHOD(InterruptScriptThread)( 
        /* [in] */ SCRIPTTHREADID stidThread,
        /* [in] */ const EXCEPINFO *pexcepinfo,
        /* [in] */ DWORD dwFlags);

    STDMETHOD(Clone)( 
        /* [out] */ IActiveScript **ppscript);

	// IActiveScriptParseProcedure2
	STDMETHOD(ParseProcedureText)( 
            /* [in] */ LPCOLESTR pstrCode,
            /* [in] */ LPCOLESTR pstrFormalParams,
            /* [in] */ LPCOLESTR pstrProcedureName,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [in] */ IUnknown *punkContext,
            /* [in] */ LPCOLESTR pstrDelimiter,
            /* [in] */ DWORD dwSourceContextCookie,
            /* [in] */ ULONG ulStartingLineNumber,
            /* [in] */ DWORD dwFlags,
            /* [out] */ IDispatch **ppdisp);


	// IActiveScriptParse
	STDMETHOD(InitNew)(void);

	STDMETHOD(AddScriptlet)( 
            /* [in] */ LPCOLESTR pstrDefaultName,
            /* [in] */ LPCOLESTR pstrCode,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [in] */ LPCOLESTR pstrSubItemName,
            /* [in] */ LPCOLESTR pstrEventName,
            /* [in] */ LPCOLESTR pstrDelimiter,
            /* [in] */ DWORD dwSourceContextCookie,
            /* [in] */ ULONG ulStartingLineNumber,
            /* [in] */ DWORD dwFlags,
            /* [out] */ BSTR *pbstrName,
            /* [out] */ EXCEPINFO *pexcepinfo);
        
	STDMETHOD(ParseScriptText)( 
            /* [in] */ LPCOLESTR pstrCode,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [in] */ IUnknown *punkContext,
            /* [in] */ LPCOLESTR pstrDelimiter,
            /* [in] */ DWORD dwSourceContextCookie,
            /* [in] */ ULONG ulStartingLineNumber,
            /* [in] */ DWORD dwFlags,
            /* [out] */ VARIANT *pvarResult,
            /* [out] */ EXCEPINFO *pexcepinfo);

	// IObjectSafety
    STDMETHOD(GetInterfaceSafetyOptions)( 
            /* [in] */ REFIID riid,
            /* [out] */ DWORD *pdwSupportedOptions,
            /* [out] */ DWORD *pdwEnabledOptions);

	STDMETHOD(SetInterfaceSafetyOptions)( 
            /* [in] */ REFIID riid,
            /* [in] */ DWORD dwOptionSetMask,
            /* [in] */ DWORD dwEnabledOptions);
protected:
	HRESULT callEngine(Atom *ret, const char *name, ...);
	CComPtr<IActiveScriptSite> m_site;
	SCRIPTSTATE scriptState;
	DWORD safetyOptions;
};

OBJECT_ENTRY_AUTO(CLSID_ActiveScript, CActiveScript)

// Constructor
CActiveScript::CActiveScript() : 
	root(NULL), 
	safetyOptions(0), 
	scriptState(SCRIPTSTATE_UNINITIALIZED)
{
		// move this to DLL init?
	if (!fm) {
		MMgc::GCHeap::Init();
		MMgc::FixedMalloc::Init();

		fm = MMgc::FixedMalloc::GetInstance();
	}

	MMgc::GCHeap* heap = MMgc::GCHeap::GetGCHeap();

	// XXX - memory exceptions?
	MMgc::GC *gc = new MMgc::GC(heap); // XXX - delete this pointer??
	core = new AXTam(gc);

	// hrmph - this doesn't look correct...
	// XXX - surely I must delete this root?
	root = new MMgc::GCRoot(gc, this, sizeof(*this));
}

HRESULT CActiveScript::callEngine(Atom *ppret, const char *name, ...)
{
	AvmAssert(ppret == NULL || *ppret == undefinedAtom); // please init this out param
	static const int maxAtoms = 64;
	Atom args[maxAtoms];

	if (!core) {
		ATLTRACE2("callEngine('%s') - early exit due to null core%s\n", name);
		return E_FAIL;
	}

	ATLTRACE2("Calling engine::%s\n", name);
	TRY(core, kCatchAction_ReportAsError) {

		// Get the object named 'engine' - XXX - cache this?
		Multiname multiname(core->publicNamespace, core->constantString("engine"));
		ScriptEnv *se = (ScriptEnv *)core->toplevel->domainEnv()->getScriptInit(&multiname);
		Atom a = core->toplevel->getproperty(se->global->atom(), &multiname, core->toplevel->toVTable(se->global->atom()));
		Multiname multiname_ani(core->publicNamespace, core->constantString(name));
		Atom ani = core->toplevel->getproperty(a, &multiname_ani, core->toplevel->toVTable(a));
		// prepare the args
		va_list s;
		va_start (s, name); 
		int argc = 1;
		args[0] = a;
		Atom arg = va_arg (s, Atom);
		while (arg != (Atom)-1) {
			args[argc] = arg;
			argc++;
			arg = va_arg (s, Atom);
			AvmAssert(argc<maxAtoms);
		}
		// Now call the method.
		Atom ret = AvmCore::atomToScriptObject(ani)->call(argc-1, args);
		if (ppret)
			*ppret = ret;
	} CATCH(Exception * exception) {
		// dump the exception for diagnostic purposes
		core->dumpException(exception);
		// report the exception to the site.
		// XXX - later, we will want to move this error handling into
		// AS, leaving the C++ code to only deal with 'internal' errors
		// in the engine itself.  For now though, report all errors to 
		// the site
		// We may not have a site if we are calling InitNew, or after we
		// have closed...
		if (m_site) {
			CGCRootComObject<CActiveScriptError> *err;
			ATLTRY(err = new CGCRootComObject<CActiveScriptError>(core));
			if (err) {
				err->exception = exception;
				// XXX - must get passed dwSourceContextCookie, if available
				//err->dwSourceContextCookie = dwSourceContextCookie;
				CComQIPtr<IActiveScriptError, &IID_IActiveScriptError> ase(err);
				m_site->OnScriptError(ase);
			}
		}

		return E_FAIL;
	}
	END_CATCH
	END_TRY
	return S_OK;
}

// Implementation methods.
STDMETHODIMP CActiveScript::SetScriptSite( 
            /* [in] */ IActiveScriptSite *pass)
{
	if (!pass)
		return E_POINTER;
	m_site = pass;
	return S_OK;
}

STDMETHODIMP CActiveScript::GetScriptSite( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject)
{
	if (!m_site) {
		ATLTRACE2("GetScriptSite with no site!");
		return E_FAIL;
	}
	return m_site.p->QueryInterface(riid, ppvObject);
}

STDMETHODIMP CActiveScript::SetScriptState( 
            /* [in] */ SCRIPTSTATE ss)
{
	ATLTRACE2("CActiveScript::SetScriptState(0x%x)\n", ss);
	scriptState = ss;
	return S_OK;
}

STDMETHODIMP CActiveScript::GetScriptState( 
            /* [out] */ SCRIPTSTATE *pssState)
{
	if (!pssState)
		return E_POINTER;
	ATLTRACE2("CActiveScript::GetScriptState (is 0x%x)\n", scriptState);
	*pssState = scriptState;
	return S_OK;
}

STDMETHODIMP CActiveScript::Close(void)
{
	ATLTRACE2("CActiveScript::Close()\n");
	if (!core)
		return S_OK;
	return core->Close();
}

STDMETHODIMP CActiveScript::AddNamedItem( 
            /* [in] */ LPCOLESTR pstrName,
            /* [in] */ DWORD dwFlags)
{
	ATLTRACE2("CActiveScript::AddNamedItem(\"%S\", 0x%x)\n", pstrName, dwFlags);

	CComPtr<IUnknown> punk;

	return callEngine(NULL, "AddNamedItem", core->toAtom(pstrName), core->toAtom(dwFlags), (Atom)-1);
}

STDMETHODIMP CActiveScript::AddTypeLib( 
            /* [in] */ REFGUID rguidTypeLib,
            /* [in] */ DWORD dwMajor,
            /* [in] */ DWORD dwMinor,
            /* [in] */ DWORD dwFlags)
{
	ATLTRACENOTIMPL(_T("CActiveScript::AddTypeLib"));
}

STDMETHODIMP CActiveScript::GetScriptDispatch( 
            /* [in] */ LPCOLESTR pstrItemName,
            /* [out] */ IDispatch **ppdisp)
{
	ATLTRACENOTIMPL(_T("CActiveScript::GetScriptDispatch"));
}

STDMETHODIMP CActiveScript::GetCurrentScriptThreadID( 
            /* [out] */ SCRIPTTHREADID *pstidThread)
{
	ATLTRACENOTIMPL(_T("CActiveScript::GetCurrentScriptThreadID"));
}

STDMETHODIMP CActiveScript::GetScriptThreadID( 
            /* [in] */ DWORD dwWin32ThreadId,
            /* [out] */ SCRIPTTHREADID *pstidThread)
{
	ATLTRACENOTIMPL(_T("CActiveScript::GetScriptThreadID"));
}

STDMETHODIMP CActiveScript::GetScriptThreadState( 
            /* [in] */ SCRIPTTHREADID stidThread,
            /* [out] */ SCRIPTTHREADSTATE *pstsState)
{
	ATLTRACENOTIMPL(_T("CActiveScript::GetScriptThreadState"));
}

STDMETHODIMP CActiveScript::InterruptScriptThread( 
            /* [in] */ SCRIPTTHREADID stidThread,
            /* [in] */ const EXCEPINFO *pexcepinfo,
            /* [in] */ DWORD dwFlags)
{
	ATLTRACENOTIMPL(_T("CActiveScript::InterruptScriptThread"));
}

STDMETHODIMP CActiveScript::Clone( 
            /* [out] */ IActiveScript **ppscript)
{
	ATLTRACENOTIMPL(_T("CActiveScript::Clone"));
}

	// IActiveScriptParseProcedure2
STDMETHODIMP CActiveScript::ParseProcedureText( 
            /* [in] */ LPCOLESTR pstrCode,
            /* [in] */ LPCOLESTR pstrFormalParams,
            /* [in] */ LPCOLESTR pstrProcedureName,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [in] */ IUnknown *punkContext,
            /* [in] */ LPCOLESTR pstrDelimiter,
            /* [in] */ DWORD dwSourceContextCookie,
            /* [in] */ ULONG ulStartingLineNumber,
            /* [in] */ DWORD dwFlags,
            /* [out] */ IDispatch **ppdisp)
{
	ATLTRACENOTIMPL(_T("CActiveScript::ParseProcedureText"));
}

// IActiveScriptParse implementation
STDMETHODIMP CActiveScript::InitNew(void)
{
	HRESULT hr;
	if (!core) {
		ATLTRACE2("CActiveScript Engine failing to initialize - no core!");
		return E_OUTOFMEMORY;
	}
	TRY(core, kCatchAction_ReportAsError) {
		hr = core->InitNew(this);
		if (FAILED(hr))
			return hr;
		return callEngine(NULL, "InitNew", (Atom)-1);
	}
	CATCH(Exception * exception) {
		// ack - error setting up our environment.
		core->dumpException(exception);
		return E_FAIL;

	}
	END_CATCH
	END_TRY

}

STDMETHODIMP CActiveScript::AddScriptlet( 
            /* [in] */ LPCOLESTR pstrDefaultName,
            /* [in] */ LPCOLESTR pstrCode,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [in] */ LPCOLESTR pstrSubItemName,
            /* [in] */ LPCOLESTR pstrEventName,
            /* [in] */ LPCOLESTR pstrDelimiter,
            /* [in] */ DWORD dwSourceContextCookie,
            /* [in] */ ULONG ulStartingLineNumber,
            /* [in] */ DWORD dwFlags,
            /* [out] */ BSTR *pbstrName,
            /* [out] */ EXCEPINFO *pexcepinfo)
{
	ATLTRACENOTIMPL(_T("CActiveScript::AddScriptlet"));
}

STDMETHODIMP CActiveScript::ParseScriptText( 
            /* [in] */ LPCOLESTR pstrCode,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [in] */ IUnknown *punkContext,
            /* [in] */ LPCOLESTR pstrDelimiter,
            /* [in] */ DWORD dwSourceContextCookie,
            /* [in] */ ULONG ulStartingLineNumber,
            /* [in] */ DWORD dwFlags,
            /* [out] */ VARIANT *pvarResult,
            /* [out] */ EXCEPINFO *pexcepinfo)
{
	return callEngine(NULL, "ParseScriptText",
	                  core->toAtom(pstrCode),
	                  core->toAtom(pstrItemName),
	                  undefinedAtom, // XXX - punkContext,
	                  core->toAtom(pstrDelimiter),
	                  core->toAtom(dwSourceContextCookie),
	                  core->toAtom(ulStartingLineNumber),
	                  core->toAtom(dwFlags),
	                  (Atom)-1);
}

// IObjectSafety
STDMETHODIMP CActiveScript::GetInterfaceSafetyOptions( 
            /* [in] */ REFIID riid,
            /* [out] */ DWORD *pdwSupportedOptions,
            /* [out] */ DWORD *pdwEnabledOptions)
{
	// XXX - we must look at this in detail!
	ATLTRACE2("CActiveScript::GetInterfaceSafetyOptions\n");
	if (!pdwSupportedOptions || !pdwEnabledOptions)
		return E_POINTER;
	*pdwSupportedOptions = (DWORD)-1;//INTERFACESAFE_FOR_UNTRUSTED_DATA | INTERFACESAFE_FOR_UNTRUSTED_CALLER;
	*pdwEnabledOptions = safetyOptions;
	return S_OK;
}

STDMETHODIMP CActiveScript::SetInterfaceSafetyOptions( 
            /* [in] */ REFIID riid,
            /* [in] */ DWORD dwOptionSetMask,
            /* [in] */ DWORD dwEnabledOptions)
{
	ATLTRACE2("CActiveScript::SetInterfaceSafetyOptions(...,0x%x, 0x%x)\n", dwOptionSetMask, dwEnabledOptions);
	// XXX - check interfaces
	safetyOptions &= ~dwOptionSetMask;
	safetyOptions |= dwEnabledOptions;
	return S_OK;
}
