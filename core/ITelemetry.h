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
 *   Adobe Engineering
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

#ifndef TELEMETRY_H_INCLUDED
#define TELEMETRY_H_INCLUDED

#ifndef VMCFG_TELEMETRY

#define TELEMETRY_BOOLEAN(t, x, v)
#define TELEMETRY_INT32(t, x, v)
#define TELEMETRY_UINT32(t, x, v)
#define TELEMETRY_UINT64(t, x, v)
#define TELEMETRY_INT64(t, x, v)
#define TELEMETRY_DOUBLE(t, x, v)
#define TELEMETRY_STRING(t, x, v)

#define TELEMETRY_BYTES(t, x, v,l)
#define TELEMETRY_TIME(t, x)

#define TELEMETRY_METHOD(t, x)
#define TELEMETRY_METHOD_NO_THRESHOLD(t, x)
#define TELEMETRY_METHOD_VAR(t, x, v)

#else
    // For all the macros, first argument is always ITelemetry*.
    // Second argument is metric name (reverse DNS notation is the recommended notation to avoid
    //      name conflicts and for native metrics (i.e. not from ActionScript) the metric name should
    //      start with '.' -- for example, a metric in VM could be ".vm.core.internString").
    // Third argument, if applicable, is the value of metric of any supported type (for TELEMETRY_VALUE,
    //      expected type of arguments is any type allowed by WriteValue function in ITelemetry class or union
    //      of all other macros with same number of arguments; for other macros, the type may
    //      be of the type indicated by the name of the macro).
    //  For example,
    //   char* internedString = "abc";
    //   TELEMETRY_STRING(GetTelemetry(), ".vm.core.internString", internedString); // Assuming GetTelemetry returns ITelemetry*.
    //

// Macros for all primitive types
#define TELEMETRY_BOOLEAN(t, x, v) \
    do { if (t && t->IsActive()) { \
        t->WriteValue(x, (bool)v);    \
    } } while(0)

#define TELEMETRY_INT32(t, x, v)  \
    do { if (t && t->IsActive()) { \
        t->WriteValue(x, (int32_t)v); \
    } } while(0)

#define TELEMETRY_UINT32(t, x, v) \
    do { if (t && t->IsActive()) { \
        t->WriteValue(x, (uint32_t)v); \
    } } while(0)

#define TELEMETRY_UINT64(t, x, v) \
    do { if (t && t->IsActive()) { \
        t->WriteValue(x, (uint64_t)v); \
    } } while(0)

#define TELEMETRY_INT64(t, x, v) \
    do { if (t && t->IsActive()) { \
        t->WriteValue(x, (int64_t)v); \
    } } while(0)

#define TELEMETRY_DOUBLE(t, x, v)  \
    do { if (t && t->IsActive()) { \
        t->WriteValue( x, (double)v); \
    } } while(0)

#define TELEMETRY_STRING(t, x, v)  \
    do { if (t && t->IsActive()) { \
        t->WriteValue( x, (const char*)v); \
    } } while(0)



// Use this for writing byte array.
// v - pointer to any block of memory; const uint8_t*
// l - length of bytes; uint32_t
#define TELEMETRY_BYTES(t, x, v, l) \
    do { if (t && t->IsActive()) { \
        t->WriteValue(x, v, l); \
    } } while(0)

// Use for writing time metrics.
// A microsecond timestamp (corresponding to the time of the call) would be written as a time metric
#define TELEMETRY_TIME(t, x)  \
    do { if (t && t->IsActive()) { \
        t->WriteTime(x); \
    } } while(0)


// Put this at the beginning of a block of code and it will transmit the starting timestamp and duration
// from this until the block exits (this goes out of scope).
#define TELEMETRY_METHOD(t, x) \
    telemetry::TelemetryMethod _tm(t, x, false)

#define TELEMETRY_METHOD_NO_THRESHOLD(t, x) \
    telemetry::TelemetryMethod _tm(t, x, true)

// Use this, if multiple TELEMETRY_METHOD macros need to be used per block (specify variable name as the
// last argument).
#define TELEMETRY_METHOD_VAR(t, x, v) \
    telemetry::TelemetryMethod v(t, x)

namespace telemetry
{
    typedef const char * telemetryId;

    // It is recommended to use the above macros -- they are sufficient for most use cases.
    class ITelemetry
    {
    public:
        ITelemetry() : m_active (false) {}
        virtual ~ITelemetry() {}
        bool IsActive() {   return m_active;    } // Check whether Telemetry is ON.
        virtual uint64_t GetElapsedTime() = 0;    // Get a microsecond timestamp since Telemetry start up.

        virtual void WriteValue(telemetryId id, bool value) = 0;    // Writes a boolean metric.
        virtual void WriteValue(telemetryId id, uint32_t value) = 0;
        virtual void WriteValue(telemetryId id, int32_t value) = 0;
        virtual void WriteValue(telemetryId id, double value) = 0;
        virtual void WriteValue(telemetryId id, const char* value) = 0;
        virtual void WriteValue(telemetryId id, uint64_t value) = 0;
        virtual void WriteValue(telemetryId id, int64_t value) = 0;
        virtual void WriteValue(telemetryId id, const uint8_t *value, uint32_t len) = 0; // Writes bytearray.
        virtual void WriteSpan(telemetryId id, uint64_t start, bool force, bool fromAS = false) = 0;
        virtual void WriteTime(telemetryId) = 0;    // Writes a time metric with microsecond timestamp.
    protected:
        void SetActive(bool isActive)   { m_active = isActive; }
    private:
        bool m_active;
    };


    // Used for measuring the duration of a method or any block of code.
    // Declare this on the stack and when the block exits, the destructor will log the time delta.
    class TelemetryMethod
    {
    public:
        TelemetryMethod(ITelemetry* telem, telemetryId id, bool force=false)
        {
            Init(telem, id, force);
        }

        ~TelemetryMethod()
        {
            if (m_telemetry && m_telemetry->IsActive()) {
                m_telemetry->WriteSpan(m_id, m_start, m_force);
            }
        }

        void Init(ITelemetry* telem, telemetryId id, bool force)
        {
            m_id = id;
            m_telemetry = telem;
            m_force = force;
            if (m_telemetry && m_telemetry->IsActive()) {
                m_start = (uint64_t)m_telemetry->GetElapsedTime();
            } else {
                m_start = 0;
            }
        }

    private:
        bool m_force;
        telemetryId m_id;
        uint64_t m_start;
        ITelemetry *m_telemetry;
    };


} // namespace telemetry


#endif // VMCFG_TELEMETRY

#endif // TELEMETRY_H_INCLUDED

