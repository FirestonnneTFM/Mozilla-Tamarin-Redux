/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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

namespace avmshell
{
    SystemClass::SystemClass(avmplus::VTable *cvtable)
        : avmplus::ClassClosure(cvtable)
    {
        ShellCore* core = (ShellCore*)this->core();
        if (core->systemClass == NULL) {
            core->systemClass = this;
        }

        createVanillaPrototype();

        // initialTime: support for getTimer
        // todo note this is currently routed to the performance counter
        // for benchmark purposes.
        #ifdef PERFORMANCE_GETTIMER
        initialTime = VMPI_getPerformanceCounter();
        #else
        initialTime = VMPI_getTime();
        #endif // PERFORMANCE_GETTIMER

    }

    SystemClass::~SystemClass()
    {
        initialTime = 0;
    }

    void SystemClass::exit(int status)
    {
        Platform::GetInstance()->exit(status);
    }

    int SystemClass::exec(avmplus::Stringp command)
    {
        if (!command) {
            toplevel()->throwArgumentError(kNullArgumentError, "command");
        }
        #ifdef UNDER_CE
        AvmAssert(0);
        return 0;
        #else
        avmplus::StUTF8String commandUTF8(command);
        return system(commandUTF8.c_str());
        #endif
    }

    avmplus::Stringp SystemClass::getAvmplusVersion()
    {
        return core()->newConstantStringLatin1(AVMPLUS_VERSION_USER " " AVMPLUS_BUILD_CODE);
    }

    avmplus::Stringp SystemClass::getFeatures()
    {
        return core()->newConstantStringLatin1(avmfeatures);
    }

    avmplus::Stringp SystemClass::getRunmode()
    {
        ShellCore* core = (ShellCore*)this->core();
        if (core->config.runmode == avmplus::RM_mixed)
            return core->newConstantStringLatin1("mixed");
        if (core->config.runmode == avmplus::RM_jit_all)
        {
            if (core->config.jitordie)
                return core->newConstantStringLatin1("jitordie");
            return core->newConstantStringLatin1("jit");
        }
        if (core->config.runmode == avmplus::RM_interp_all)
            return core->newConstantStringLatin1("interp");
        return core->newConstantStringLatin1("unknown");
    }

    void SystemClass::write(avmplus::Stringp s)
    {
        if (!s)
            toplevel()->throwArgumentError(kNullArgumentError, "string");
        core()->console << s;
    }

    void SystemClass::trace(avmplus::ArrayObject* a)
    {
        if (!a)
            toplevel()->throwArgumentError(kNullArgumentError, "array");
        avmplus::AvmCore* core = this->core();
        avmplus::PrintWriter& console = core->console;
        for (int i=0, n = a->getLength(); i < n; i++)
        {
            if (i > 0)
                console << ' ';
            avmplus::StringIndexer s(core->string(a->getUintProperty(i)));
            for (int j = 0; j < s->length(); j++)
            {
                wchar c = s[j];
                // '\r' gets converted into '\n'
                // '\n' is left alone
                // '\r\n' is left alone
                if (c == '\r')
                {
                    if (((j+1) < s->length()) && s[j+1] == '\n')
                    {
                        console << '\r';
                        j++;
                    }

                    console << '\n';
                }
                else
                {
                    console << c;
                }
            }
        }
        console << '\n';
    }

    void SystemClass::debugger()
    {
        #ifdef DEBUGGER
        if (core()->debugger())
            core()->debugger()->enterDebugger();
        #endif
    }

    bool SystemClass::isDebugger()
    {
        #ifdef DEBUGGER
        return core()->debugger() != NULL;
        #else
        return false;
        #endif
    }

    unsigned SystemClass::getTimer()
    {
#ifdef PERFORMANCE_GETTIMER
        double time = ((double) (VMPI_getPerformanceCounter() - initialTime) * 1000.0 /
                       (double)VMPI_getPerformanceFrequency());
        return (uint32_t)time;
#else
        return (uint32_t)(VMPI_getTime() - initialTime);
#endif /* PERFORMANCE_GETTIMER */

    }

    int SystemClass::user_argc;
    char **SystemClass::user_argv;

    avmplus::ArrayObject * SystemClass::getArgv()
    {
        // get VTable for avmplus.System
        avmplus::Toplevel *toplevel = this->toplevel();
        avmplus::AvmCore *core = this->core();

        avmplus::ArrayObject *array = toplevel->arrayClass()->newArray();
        for(int i=0; i<user_argc;i++)
            array->setUintProperty(i, core->newStringUTF8(user_argv[i])->atom());

        return array;
    }

    avmplus::Stringp SystemClass::readLine()
    {
        avmplus::AvmCore* core = this->core();
        avmplus::Stringp s = core->kEmptyString;
        wchar wc[64];
        int i=0;
        for (int c = getchar(); c != '\n' && c != EOF; c = getchar())
        {
            wc[i++] = (wchar)c;
            if (i == 63) {
                wc[i] = 0;
                s = s->append16(wc);
                i = 0;
            }
        }
        if (i > 0) {
            wc[i] = 0;
            s = s->append16(wc);
        }
        return s;
    }

    double SystemClass::get_totalMemory()
    {
        MMgc::GCHeap* gcheap = MMgc::GCHeap::GetGCHeap();
        return double(gcheap->GetTotalHeapSize() * MMgc::GCHeap::kBlockSize);
    }

    double SystemClass::get_freeMemory()
    {
        MMgc::GCHeap* gcheap = MMgc::GCHeap::GetGCHeap();
        return double(gcheap->GetFreeHeapSize() * MMgc::GCHeap::kBlockSize);
    }

    double SystemClass::get_privateMemory()
    {
        return double(VMPI_getPrivateResidentPageCount() * VMPI_getVMPageSize());
    }

    int32_t SystemClass::get_swfVersion()
    {
        ShellCore* core = (ShellCore*)this->core();
        avmplus::BugCompatibility::Version v = core->getDefaultBugCompatibilityVersion();
        AvmAssert(v >= 0 && v < avmplus::BugCompatibility::VersionCount);
        return avmplus::BugCompatibility::kNames[v];
    }

    int32_t SystemClass::get_apiVersion()
    {
        ShellCore* core = (ShellCore*)this->core();
        return core->defaultAPIVersion;
    }

    void SystemClass::forceFullCollection()
    {
        core()->GetGC()->Collect();
    }

    void SystemClass::queueCollection()
    {
        core()->GetGC()->QueueCollection();
    }

    bool SystemClass::isGlobal(avmplus::Atom o)
    {
        return avmplus::AvmCore::isObject(o) ? avmplus::AvmCore::atomToScriptObject(o)->isGlobalObject() : false;
    }

    void SystemClass::disposeXML(avmplus::XMLObject *xmlObject)
    {
        if(xmlObject)
            xmlObject->dispose();
    }

    void SystemClass::pauseForGCIfCollectionImminent(double imminence)
    {
        if( avmplus::MathUtils::isNaN(imminence) )
            imminence = 0.75;
        core()->GetGC()->Collect(imminence);
    }
    
    /*static*/ void FASTCALL CheckBaseClass::preCreateInstanceCheck(avmplus::ClassClosure* cls)
    {
        avmplus::Multiname qname(cls->traits()->ns(), cls->traits()->name());
        // Deliberately throw a weird, non-sequitur error here so that we
        // can distinguish this from construct="none" in the acceptance tests.
        cls->toplevel()->argumentErrorClass()->throwError(kNotImplementedError, cls->core()->toErrorString(&qname));
    }
}
