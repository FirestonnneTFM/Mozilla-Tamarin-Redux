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
 *   Mark Hammond
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

#include <stdlib.h>

namespace axtam
{
	MSCom::MSCom(VTable* vtable, ScriptObject* prototype, IDispatch *pDisp)
		: ScriptObject(vtable, prototype)
	{
		disp = pDisp; // must have an IDispatch
		AvmAssert(disp != 0);
		dispex = pDisp; // dispex is optional
	}

	Atom MSCom::callProperty(avmplus::Multiname *name, int argc, avmplus::Atom *argv)
	{
		// Not sure how to best handle this re 'builtin' names, such as toString()
		// XXX - need a map of DISPIDs to speed things up, and/or optimizations
		// using the typelib.
		DISPID id;
		AXTam *axcore = (AXTam *)core();
		OLECHAR *olename = (OLECHAR *)name->getName()->c_str();
		HRESULT hr = disp->GetIDsOfNames(IID_NULL, &olename, 1, 0, &id);
		if (hr == DISP_E_UNKNOWNNAME) {
			// not a name this object has - see if its builtin.
			return ScriptObject::callProperty(name, argc, argv);
		}
		if (FAILED(hr))
			axcore->throwCOMError(hr);
		// Now create args for the call.
		EXCEPINFO ei;
		CComVariant *pArgs = new CComVariant[argc];
		//memset(pArgs, 0, sizeof(VARIANT) * argc);
		// Take care to not early exit without cleaning up variants
		int i;
		for (i=0;i<argc;i++) {
			//VariantInit(pArgs+i);
			axcore->atomToVARIANT(argv[i+1], pArgs+i);
		}
		DISPPARAMS params = {pArgs, NULL, argc, 0};
		CComVariant ret;
		hr = disp->Invoke(id, IID_NULL, 0, DISPATCH_METHOD, &params, &ret, &ei, NULL);
		//for (i=0;i<argc;i++)
		//	VariantClear(pArg+i);
		delete [] pArgs;
		if (FAILED(hr))
			axcore->throwCOMError(hr, &ei);
		return axcore->toAtom(ret);
	}

	Atom MSCom::getAtomProperty(Atom name) const {
		AXTam *axcore = (AXTam *)core();
		if (!axcore->isString(name))
			axcore->toplevel->throwTypeError(kCheckTypeFailedError);
		DISPID id;

		OLECHAR *olename = (OLECHAR *)axcore->atomToString(name)->c_str();
		HRESULT hr = disp->GetIDsOfNames(IID_NULL, &olename, 1, 0, &id);
		if (hr == DISP_E_UNKNOWNNAME) {
			// not a name this object has - see if its builtin.
			return ScriptObject::getAtomProperty(name);
		}
		if (FAILED(hr))
			axcore->throwCOMError(hr);
		EXCEPINFO ei;
		DISPPARAMS params = {NULL, NULL, 0, 0};
		CComVariant ret;
		hr = disp->Invoke(id, IID_NULL, 0, DISPATCH_PROPERTYGET, &params, &ret, &ei, NULL);
		if (FAILED(hr))
			axcore->throwCOMError(hr, &ei);
		return axcore->toAtom(ret);
	}


	BEGIN_NATIVE_MAP(MSComClass)
	END_NATIVE_MAP()

	MSComClass::MSComClass(VTable *cvtable)
		: ClassClosure(cvtable)
    {
		AXTam* core = (AXTam*)this->core();
//		if (core->systemClass == NULL) {
//			core->systemClass = this;
//		}
		// should only be initialized once!
		AvmAssert(!core->mscomClass);
		core->mscomClass = this;

		createVanillaPrototype();
	}

	MSComClass::~MSComClass()
	{
	}

	// Function called as constructor ... not supported from user code
	MSCom* MSComClass::create(IDispatch* p)
	{
		VTable* ivtable = this->ivtable();
		MSCom *o = new (core()->GetGC(), ivtable->getExtraSize()) MSCom(ivtable, prototype, p);
		return o;
	}

}
