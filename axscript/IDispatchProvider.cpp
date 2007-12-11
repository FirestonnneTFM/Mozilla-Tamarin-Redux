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
#include "IDispatchProvider.h"

using namespace axtam;

// IDispatch

STDMETHODIMP IDispatchProvider::GetTypeInfoCount(UINT* pctinfo)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::GetTypeInfoCount"));
}
STDMETHODIMP IDispatchProvider::GetTypeInfo(UINT itinfo, LCID lcid, ITypeInfo** pptinfo)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::GetTypeInfo"));
}
STDMETHODIMP IDispatchProvider::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
                LCID lcid, DISPID* rgdispid)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::GetIDsOfNames"));
}

STDMETHODIMP IDispatchProvider::Invoke(DISPID dispidMember, REFIID riid,
				LCID lcid, WORD wFlags, DISPPARAMS* pdispparams, VARIANT* pvarResult,
				EXCEPINFO* pexcepinfo, UINT* puArgErr)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::Invoke"));
}

STDMETHODIMP IDispatchProvider::GetDispID(
			/* [in] */ BSTR bstrName,
			/* [in] */ DWORD grfdex,
			/* [out] */ DISPID *pid)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::GetDispID"));
}

STDMETHODIMP IDispatchProvider::InvokeEx(
			/* [in] */ DISPID id,
			/* [in] */ LCID lcid,
			/* [in] */ WORD wFlags,
			/* [in] */ DISPPARAMS *pdp,
			/* [out] */ VARIANT *pvarRes,
			/* [out] */ EXCEPINFO *pei,
			/* [unique][in] */ IServiceProvider *pspCaller)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::InvokeEx"));
}

STDMETHODIMP IDispatchProvider::DeleteMemberByName(
			/* [in] */ BSTR bstrName,
			/* [in] */ DWORD grfdex)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::DeleteMemberByName"));
}

STDMETHODIMP IDispatchProvider::DeleteMemberByDispID(
			/* [in] */ DISPID id)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::DeleteMemberByDispID"));
}

STDMETHODIMP IDispatchProvider::GetMemberProperties(
			/* [in] */ DISPID id,
			/* [in] */ DWORD grfdexFetch,
			/* [out] */ DWORD *pgrfdex)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::GetMemberProperties"));
}

STDMETHODIMP IDispatchProvider::GetMemberName(
			/* [in] */ DISPID id,
			/* [out] */ BSTR *pbstrName)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::GetMemberName"));
}

STDMETHODIMP IDispatchProvider::GetNextDispID(
			/* [in] */ DWORD grfdex,
			/* [in] */ DISPID id,
			/* [out] */ DISPID *pid)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::GetNextDispID"));
}


STDMETHODIMP IDispatchProvider::GetNameSpaceParent(
			/* [out] */ IUnknown **ppunk)
{
	ATLTRACENOTIMPL(_T("IDispatchProvider::GetNameSpaceParent"));
}
