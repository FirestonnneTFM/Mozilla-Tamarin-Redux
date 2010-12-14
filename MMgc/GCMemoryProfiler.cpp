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

#include "MMgc.h"

namespace MMgc
{

#ifdef MMGC_MEMORY_PROFILER
    // increase this to get more info
    const int kNumTypes = 10;
    const int kNumTracesPerType = 5;

    // include total and swept memory totals in memory profiling dumps as opposed to just "live"
    const bool showTotal = false;
    const bool showSwept = false;

    bool simpleDump;

    class StackTrace : public GCAllocObject
    {
    public:
        StackTrace(uintptr_t *trace)
        {
            VMPI_memset(this, 0, sizeof(StackTrace));
            VMPI_memcpy(ips, trace, kMaxStackTrace * sizeof(uintptr_t));
        }
        uintptr_t ips[kMaxStackTrace];
        size_t size;
        size_t totalSize;
        size_t sweepSize;
        const char *package;
        const char *category;
        const char *name;
        uint32_t count;
        uint32_t totalCount;
        uint32_t sweepCount;
        StackTrace *master;
        uint8_t skip;
    };

    struct AllocInfo : public GCAllocObject
    {
        StackTrace* allocTrace;

        // memory optimization:  askSize is N/A after the object is deleted,
        // and deleteTrace is only used to report writing to deleted memory,
        union {
            size_t askSize;
            StackTrace* deleteTrace;
        };
    };

    GCThreadLocal<const char*> memtag;
    GCThreadLocal<const void*> memtype;

    MemoryProfiler::MemoryProfiler() :
        stackTraceMap(128),
        stringsTable(4),
        nameTable(128),
        allocInfoTable(128)
    {
        VMPI_setupPCResolution();
        simpleDump = !VMPI_hasSymbols();
        VMPI_lockInit(&lock);
    }

    MemoryProfiler::~MemoryProfiler()
    {
        GCStackTraceHashtable_VMPI::Iterator traceIter(&stackTraceMap);
        const void *obj;
        while((obj = traceIter.nextKey()) != NULL)
        {
            StackTrace *trace = (StackTrace*)traceIter.value();
            delete trace;
        }
        GCHashtable_VMPI::Iterator nameIter(&nameTable);
        while((obj = nameIter.nextKey()) != NULL)
        {
            VMPI_free((void*)nameIter.value());
        }

        GCHashtable_VMPI::Iterator allocIter(&allocInfoTable);
        while((obj = allocIter.nextKey()) != NULL)
        {
            delete (AllocInfo*)allocIter.value();
        }
        VMPI_desetupPCResolution();
        VMPI_lockDestroy(&lock);
    }

    const char *MemoryProfiler::GetAllocationNameFromTrace(StackTrace *trace)
    {
        if(trace->name)
            return trace->name;

        char *name=NULL;

        int i=0;
        uintptr_t ip;
        while((ip = trace->ips[i++]) != 0) {
            // everytime we lookup an ip cache the result
            name = (char*)nameTable.get(ip);
            if(!name) {
                name = (char*)VMPI_alloc(256);
                if(VMPI_getFunctionNameFromPC(ip, name, 256) == false)
                {
                    VMPI_snprintf(name, 256, "0x%llx", (unsigned long long)ip);
                }
                nameTable.put((const void*)ip, name);
            }
            // keep going until we hit mutator code
            if(VMPI_strstr(name, "::Alloc") != NULL ||
                VMPI_strstr(name, "::LargeAlloc") != NULL ||
                VMPI_strstr(name, "::Calloc") != NULL ||
                VMPI_strstr(name, "operator new") != NULL)
            {
                trace->skip++;
                continue;
            }
            break;
        }
        trace->name = name;
        return name;
    }

    StackTrace *MemoryProfiler::GetAllocationTrace(const void *obj)
    {
        MMGC_LOCK(lock);
        return GetAllocationTraceLocked(obj);
    }

    StackTrace *MemoryProfiler::GetAllocationTraceLocked(const void *obj)
    {
        AllocInfo* info = (AllocInfo*)allocInfoTable.get(obj);
        //GCAssert(info != NULL);
        return info ? info->allocTrace : NULL;
    }

    StackTrace *MemoryProfiler::GetDeletionTrace(const void *obj)
    {
        MMGC_LOCK(lock);
        AllocInfo* info = (AllocInfo*)allocInfoTable.get(obj);
        GCAssert(info != NULL);
        return info ? info->deleteTrace : NULL;
    }

    const char * MemoryProfiler::GetAllocationName(const void *obj)
    {
        MMGC_LOCK(lock);
        AllocInfo *info = (AllocInfo*)allocInfoTable.get(obj);
        if(info)
            return GetAllocationNameFromTrace(info->allocTrace);
        return NULL;
    }

    const char *MemoryProfiler::GetAllocationCategory(StackTrace *trace)
    {
        if(trace->master)
            trace = trace->master;
        if(trace->category)
            return trace->category;
        const char *cat = GetAllocationNameFromTrace(trace);
        trace->category = cat;
        return cat;
    }

    void ChangeSize(StackTrace *trace, bool add, size_t delta)
    {
        if (add) {
            trace->size += delta;
            trace->count++;
            trace->totalSize += delta;
            trace->totalCount++;
        }
        else {
            trace->size -= delta;
            trace->count--;
        }
        GCAssert(trace->count != 0 || trace->size == 0);
    }

    void MemoryProfiler::RecordAllocation(const void *item, size_t askSize, size_t gotSize)
    {
        GCAssert(gotSize != 0);
        MMGC_LOCK(lock);
        (void)askSize;

        StackTrace *trace = GetStackTraceLocked();

        ChangeSize(trace, true, gotSize);

        AllocInfo* info = (AllocInfo*) allocInfoTable.get(item);
        if(!info)
        {
            info = new AllocInfo;
            allocInfoTable.put(item, info);
        }

        info->askSize = askSize;
        info->allocTrace = trace;

        if(memtype)
        {
            trace->master = GetAllocationTraceLocked(memtype);
            memtype = NULL;
        }

        if(memtag)
        {
            trace->category = memtag;
            memtag = NULL;
        }
    }

    void MemoryProfiler::RecordDeallocation(const void *item, size_t size)
    {
        MMGC_LOCK(lock);
        // This should be a remove, but calling remove a lot has performance issues
        // When we fix the perf issues with GCHashtable::remove, we should change this back to a remove.
        AllocInfo* info = (AllocInfo*) allocInfoTable.get(item);

        GCAssert(info != NULL);

        ChangeSize(info->allocTrace, false, size);
        // FIXME: how to know this is a sweep?

        // store deletion trace
        info->deleteTrace = GetStackTraceLocked();

#if 0
        if(poison == uint8_t(GCHeap::GCSweptPoison)) {
            trace->sweepSize += size;
            trace->sweepCount++;
        }
#endif
    }

    StackTrace *MemoryProfiler::GetStackTrace()
    {
        MMGC_LOCK(lock);
        return GetStackTraceLocked();
    }

    StackTrace *MemoryProfiler::GetStackTraceLocked()
    {
        uintptr_t trace[kMaxStackTrace];
        VMPI_memset(trace, 0, sizeof(trace));

        VMPI_captureStackTrace(trace, kMaxStackTrace, 3);
        StackTrace *st = (StackTrace*)stackTraceMap.get(trace);
        if(!st) {
            st = new StackTrace(trace);
            stackTraceMap.put(st, st);
        }
        return st;
    }

    size_t MemoryProfiler::GetAskSize(const void* item)
    {
        MMGC_LOCK(lock);
        AllocInfo* info = (AllocInfo*) allocInfoTable.get(item);
        //failing this assert means that either FinalizeHook() was called before GetAsk()
        //or this item is being double deleted
        GCAssert(info != NULL);
        return info ? info->askSize : 0;
    }

    class PackageGroup : public GCAllocObject
    {
    public:
        PackageGroup(const char *name) : name(name), size(0), count(0), categories(16) {}
        const char *name;
        size_t size;
        uint32_t count;
        // Note: it's important to use the VMPI variant of GCHashtable for this.
        GCHashtable_VMPI categories; // key == category name, value == CategoryGroup*
    };

    // data structure to gather allocations by type with the top 5 traces
    class CategoryGroup : public GCAllocObject
    {
    public:
        CategoryGroup(const char *name) : name(name), size(0), count(0)
        {
            VMPI_memset(traces, 0, sizeof(traces));
        }
        const char *name;
        size_t size;
        uint32_t count;
        // biggest kNumTracesPerType traces
        StackTrace *traces[kNumTracesPerType ? kNumTracesPerType : 1];
    };

    const char *MemoryProfiler::Intern(const char *name, size_t len)
    {
        char tmp[100];
        // input doesn't have to be zero terminated, so zero terminate in buff
        char *buff = len < 100 ? tmp : (char*)VMPI_alloc(len+1);
        if (buff == NULL)
        {
            // Well, we try
            len = 99;
            buff = tmp;
        }
        VMPI_strncpy(buff, name, len);
        buff[len]='\0';
        char *iname = (char*)stringsTable.get(buff);
        if(iname)
        {
            if (buff != tmp)
                VMPI_free(buff);
            return iname;
        }
        if (buff == tmp)
        {
            iname = (char*)VMPI_alloc(len+1);
            if (iname == NULL)
                GCHeap::GetGCHeap()->Abort();
            VMPI_strcpy(iname, buff);
        }
        else
        {
            iname = buff;
            buff = tmp;
        }
        stringsTable.put(iname, iname);
        if (buff != tmp)
            VMPI_free(buff);
        return iname;
    }

    // TODO duplicate code in here and in GetAllocationName
    const char *MemoryProfiler::GetPackage(StackTrace *trace)
    {
        if(trace->package)
            return trace->package;
        const char *name = GetAllocationNameFromTrace(trace);
        const char *colons = name ? VMPI_strstr(name, "::") : NULL;
        const char *package="global";
        if(colons) {
            colons += 2;
            // two sets of colons indicates a namespace
            const char *colons2 = VMPI_strstr(colons, "::");
            if(colons2)
                package = Intern(name, colons-name);
        }
        trace->package = package;
        return package;
    }

#define PERCENT(all, some) (((double)some*100.0)/(double)all)

    void MemoryProfiler::DumpFatties()
    {
        if( simpleDump )
        {
            DumpSimple();
            return;
        }

        MMGC_LOCK(lock);

        // Note: it's important to use the VMPI variant of GCHashtable for this.
        GCHashtable_VMPI packageTable(128);

        size_t residentSize=0;
        size_t residentCount=0;
        size_t packageCount=0;

        // rip through all allocation sites and sort into package and categories
        GCStackTraceHashtable_VMPI::Iterator iter(&stackTraceMap);
        const void *obj;
        while((obj = iter.nextKey()) != NULL)
        {
            StackTrace *trace = (StackTrace*)iter.value();
            size_t size;

            if(showSwept) {
                size = trace->sweepSize;
            } else if(showTotal) {
                size = trace->totalSize;
            } else {
                size = trace->size;
            }

            if(size == 0)
                continue;

            residentSize += size;

            uint32_t count = trace->master != NULL ? 0 : trace->count;
            residentCount += trace->count;

            const char *pack = GetPackage(trace);
            PackageGroup *pg = (PackageGroup*) packageTable.get((void*)pack);
            if(!pg) {
                pg = new PackageGroup(pack);
                packageTable.add(pack, pg);
                packageCount++;
            }
            pg->size += size;
            pg->count += count;

            const char *cat = GetAllocationCategory(trace);
            CategoryGroup *tg = (CategoryGroup *) pg->categories.get((void*)cat);
            if(!tg)  {
                tg = new CategoryGroup(cat);
                pg->categories.add((void*)cat, tg);
            }
            tg->size += size;
            tg->count += count;

            // insertion sort StackTrace
            for(int j=0; j < kNumTracesPerType; j++) {
                if(tg->traces[j] == trace)
                    break;
              if(!tg->traces[j] || tg->traces[j]->size < size) {
                    if(j != kNumTracesPerType-1) {
                        VMPI_memmove(&tg->traces[j+1], &tg->traces[j], (kNumTracesPerType-j-1)*sizeof(void*));
                    }
                    tg->traces[j] = trace;
                    break;
                }
            }
        }

        // reporting time....
        PackageGroup **packages = (PackageGroup**)VMPI_alloc(packageCount*sizeof(PackageGroup*));
        if (packages == NULL)
            return;
        VMPI_memset(packages, 0, packageCount*sizeof(PackageGroup*));

        GCHashtable_VMPI::Iterator pack_iter(&packageTable);
        const char *package;
        while((package = (const char*)pack_iter.nextKey()) != NULL)
        {
            PackageGroup* pg = (PackageGroup*)pack_iter.value();
            for(unsigned j=0; j<packageCount; j++) {
                if(packages[j] == NULL || packages[j]->size < pg->size) {
                    if(j != packageCount-1) {
                        VMPI_memmove(&packages[j+1], &packages[j], (packageCount-j-1)*sizeof(PackageGroup*));
                    }
                    packages[j]=pg;
                    break;
                }
            }
        }

        GCLog("\n\nMemory allocation report for %llu allocations, totaling %llu kb (%llu ave) across %llu packages\n", 
              (unsigned long long)residentCount, 
              (unsigned long long)(residentSize>>10),
              (unsigned long long)(residentSize / residentCount),
              (unsigned long long)packageCount);

        for(unsigned i=0; i<packageCount; i++)
        {
            PackageGroup* pg = packages[i];

            int numTypes = pg->categories.count();

            if(numTypes == 0)
                continue;

            // sort CategoryGroup's into this array
            CategoryGroup **residentFatties = (CategoryGroup**) VMPI_alloc(numTypes * sizeof(CategoryGroup *));
            if (residentFatties == NULL)
                return;
            VMPI_memset(residentFatties, 0, numTypes * sizeof(CategoryGroup *));
            GCHashtable_VMPI::Iterator iter(&pg->categories);
            const char *name;
            while((name = (const char*)iter.nextKey()) != NULL)
            {
                CategoryGroup *tg = (CategoryGroup*)iter.value();
                // TODO refactor insertion sort into sub routine
                for(int j=0; j<numTypes; j++) {
                    if(!residentFatties[j]) {
                        residentFatties[j] = tg;
                        break;
                    }
                    if(residentFatties[j]->size < tg->size) {
                        if(j != numTypes-1) {
                            VMPI_memmove(&residentFatties[j+1], &residentFatties[j], (numTypes-j-1) * sizeof(CategoryGroup *));
                        }
                        residentFatties[j] = tg;
                        break;
                    }
                }
            }

            GCLog("%s - %3.1f%% - %llu kb %u items, avg %llu b\n", 
                  pg->name,
                  PERCENT(residentSize, pg->size),
                  (unsigned long long)(pg->size>>10), 
                  (unsigned)pg->count,
                  (unsigned long long)(pg->count ? pg->size/pg->count : 0));

            // result capping
            if(numTypes > kNumTypes)
                numTypes = kNumTypes;

            for(int i=0; i < numTypes; i++)
            {
                CategoryGroup *tg = residentFatties[i];
                if(!tg)
                    break;
                GCLog("\t%s - %3.1f%% - %llu kb %u items, avg %llu b\n",
                      tg->name,
                      PERCENT(residentSize, tg->size),
                      (unsigned long long)(tg->size>>10),
                      (unsigned)tg->count,
                      (unsigned long long)(tg->count ? tg->size/tg->count : 0));
                for(int j=0; j < kNumTracesPerType; j++) {
                    StackTrace *trace = tg->traces[j];
                    if(trace) {
                        size_t size = trace->size;
                        uint32_t count = trace->count;
                        if(showSwept) {
                            size = trace->sweepSize;
                            count = trace->sweepCount;
                        } else if(showTotal) {
                            size = trace->totalSize;
                            count = trace->totalCount;
                        }
                        GCLog("\t\t %3.1f%% - %llu kb - %u items - ", 
                              PERCENT(tg->size, size),
                              (unsigned long long)(size>>10),
                              (unsigned)count);
                        PrintStackTrace(trace);
                    }
                }
            }

            VMPI_free(residentFatties);
        }

        GCHashtable_VMPI::Iterator pi(&packageTable);
        while(pi.nextKey() != NULL)
        {
            PackageGroup* pg = (PackageGroup*)pi.value();
            GCHashtable_VMPI::Iterator iter(&pg->categories);
            while(iter.nextKey() != NULL)
                delete (CategoryGroup*)iter.value();
            delete pg;
        }

        VMPI_free(packages);
    }

    void MemoryProfiler::DumpSimple()
    {
        MMGC_LOCK(lock);

        // rip through all allocation sites and dump them all without any sorting
        // useful on WinMo or other platforms where we don't have symbol names
        // at runtime, and just need to dump the raw addresses (which makes sorting impossible)
        GCStackTraceHashtable_VMPI::Iterator iter(&stackTraceMap);
        const void *obj;
        size_t num_traces = 0;
        // Get a stack trace with VMPI_captureStackTrace as the top address - this will be used to calculate the
        // base address to translate the addresses into relative addresses later
        uintptr_t trace[kMaxStackTrace];
        VMPI_memset(trace, 0, sizeof(trace));

        VMPI_captureStackTrace(trace, kMaxStackTrace, 1);

        GCLog("ReferenceAddress VMPI_captureStackTrace 0x%llx \n", (unsigned long long)trace[0]);

        while((obj = iter.nextKey()) != NULL)
        {
            ++num_traces;
            StackTrace *trace = (StackTrace*)iter.value();
            size_t size;
            uint64_t count;

            if(showSwept) {
                size = trace->sweepSize;
                count = trace->sweepCount;
            } else if(showTotal) {
                size = trace->totalSize;
                count = trace->totalCount;
            } else {
                size = trace->size;
                count = trace->count;
            }

            if(size == 0)
                continue;

            GCLog("%llu b - %u items - ", (unsigned long long)size, (unsigned)count);
            PrintStackTrace(trace);
        }
        GCLog("%llu traces", (unsigned long long)num_traces);
    }

    void MemoryProfiler::DumpSimpleByTotal(uint32_t limit, MemoryProfiler::SortMode sort)
    {
        struct Item {
            uint64_t value;
            StackTrace* trace;
        };

        {
            uint32_t num_traces = 0;
            GCStackTraceHashtable_VMPI::Iterator iter(&stackTraceMap);
            const void *obj;
            while((obj = iter.nextKey()) != NULL)
                num_traces++;
            
            if (limit == 0 || limit > num_traces)
                limit = num_traces;
        }

        // This array is sorted in decreasing order by 'value'
        Item* traces = (Item*)VMPI_alloc(sizeof(Item) * limit);
        
        if (traces == NULL) {
            GCAssert(!"Could not allocate array to hold stacktrace pointers");
            return;
        }

        for ( uint32_t i=0 ; i < limit ; i++ )
        {
            traces[i].value = 0;
            traces[i].trace = NULL;
        }
        
        {
            GCStackTraceHashtable_VMPI::Iterator iter(&stackTraceMap);
            const void *obj;
            while((obj = iter.nextKey()) != NULL)
            {
                StackTrace *trace = (StackTrace*)iter.value();

                if (trace->totalSize == 0)
                    continue;

                Item it;
                it.value = sort == BY_VOLUME ? trace->totalSize : trace->totalCount;
                it.trace = trace;

                // OPTIMIZEME: This works OK for short arrays, less well for longer.
                uint32_t i=0;
                while (i < limit && it.value <= traces[i].value)
                    i++;
                if (i < limit) {
                    for ( uint32_t j=limit-1 ; j > i ; j-- )
                        traces[j] = traces[j-1];
                    traces[i] = it;
                }
            }
        }
        
        for ( uint32_t i=0 ; i < limit && traces[i].value > 0 ; i++ ) {
            GCLog("%llu b - %u items - ", (unsigned long long)traces[i].trace->totalSize, (unsigned)traces[i].trace->totalCount);
            PrintStackTrace(traces[i].trace);
        }
    }

    void MemoryProfiler::DumpAllocationProfile()
    {
        // No particular reason this has to be AVMSHELL_BUILD only, but that's
        // what we've tested so far.  Environment variables are not kosher in
        // all settings.
        //
        // Note you may want to inspect the implementation of VMPI_setupPCResolution
        // to make sure symbol resolution is available and enabled, otherwise
        // the profiles won't make a lot of sense.
#ifdef AVMSHELL_BUILD
        // Ad-hoc configuration.  If MMGC_PROFILE_CONFIG is present we try to 
        // interpret it.  Its presence means we want allocation site profiling,
        // not leak profiling.  The string additionally can be empty, but if not
        // empty it has this form:
        //   n,sort
        // where:
        //   - n=0 means "unlimited" and otherwise "number of traces we want",
        //     the default is 40
        //   - sort="volume" means we sort by allocation volume, "count" means
        //     we sort by allocation count, the default is "volume".
        const char *x = VMPI_getenv("MMGC_PROFILE_CONFIG");
        if (x != NULL && VMPI_strlen(x) < 100)
        {
            char buf[100];
            unsigned limit;
            int len;
            MemoryProfiler::SortMode s;
            if (VMPI_sscanf(x, "%u,%s%n", &limit, buf, &len) == 2 && unsigned(len) == VMPI_strlen(x)) {
                if (VMPI_strcmp(buf, "count") == 0)
                    s = MemoryProfiler::BY_COUNT;
                else 
                    s = MemoryProfiler::BY_VOLUME;
            }
            else if (VMPI_sscanf(x, "%u%n", &limit, &len) == 1 && unsigned(len) == VMPI_strlen(x)) {
                s = MemoryProfiler::BY_VOLUME;
            }
            else {
                limit=40;
                s = MemoryProfiler::BY_VOLUME;
            }
            DumpSimpleByTotal(limit, s);
        }
#endif
    }

    void SetMemTag(const char *s)
    {
        if(GCHeap::GetGCHeap()->GetProfiler() != NULL)
        {
            if(memtag == NULL)
                memtag = s;
        }
    }

    void SetMemType(const void *s)
    {
        if(GCHeap::GetGCHeap()->GetProfiler() != NULL)
        {
            GCAssertMsg(s == NULL || GCHeap::GetGCHeap()->GetProfiler()->GetAllocationTrace(s) != NULL, "Unknown allocation");
            if(memtype != NULL || s == NULL) {
                memtype = s;
            }
        }
    }

    void DumpStackTraceHelper(uintptr_t *trace)
    {
        char out[2048];         // This should be at least 3 times as large as 'buff', below
        char *tp = out;
        *tp++ = '\n';
        for(int i=0; trace[i] != 0; i++) {
            char buff[256];     // 'out', above, should be at least 3 times as large as this
            if( !simpleDump )
            {
                *tp++ = '\t';
                *tp++ = '\t';
                *tp++ = '\t';
            }

            bool found_name;
            if((found_name = VMPI_getFunctionNameFromPC(trace[i], buff, sizeof(buff))) == false)
            {
                VMPI_snprintf(buff, sizeof(buff), "0x%llx", (unsigned long long)trace[i]);
            }
            VMPI_strcpy(tp, buff);
            tp += VMPI_strlen(buff);

            uint32_t lineNum;
            if(VMPI_getFileAndLineInfoFromPC(trace[i], buff, sizeof(buff), &lineNum))
            {
                // Don't bother with file, linenumber, and address if we're just printing the address anyways
                if (found_name)
                {
                    size_t x = VMPI_strlen(buff);
                    VMPI_snprintf(buff+x, sizeof(buff)-x, ":%u", (unsigned)lineNum);

                    *tp++ = '(';
                    VMPI_strcpy(tp, buff);
                    tp += VMPI_strlen(buff);
                    *tp++ = ')';
                    tp += VMPI_sprintf(tp, " - 0x%llx", (unsigned long long) trace[i]);
                }
            }
            *tp++ = '\n';

            if(tp - out > 200) {
                *tp = '\0';
                GCLog(out);
                tp = out;
            }
        }
        *tp = '\0';

        GCLog(out);
    }

    void PrintStackTrace(StackTrace *trace)
    {
        DumpStackTraceHelper(&trace->ips[trace->skip]);
    }

    void PrintAllocStackTrace(const void *item)
    {
        if(GCHeap::GetGCHeap()->GetProfiler()) {
            StackTrace *trace = GCHeap::GetGCHeap()->GetProfiler()->GetAllocationTrace(item);
            GCAssertMsg(trace != NULL, "Trace was null");
            PrintStackTrace(trace);
        }
    }

    void PrintDeleteStackTrace(const void *item)
    {
        if(GCHeap::GetGCHeap()->GetProfiler()) {
            StackTrace *trace = GCHeap::GetGCHeap()->GetProfiler()->GetDeletionTrace(item);
            GCAssertMsg(trace != NULL, "Trace was null");
            PrintStackTrace(trace);
        }
    }

    const char* GetAllocationName(const void *obj)
    {
        if(GCHeap::GetGCHeap()->GetProfiler())
            return GCHeap::GetGCHeap()->GetProfiler()->GetAllocationName(obj);
        return NULL;
    }

    struct ObjectPopulationProfiler::PopulationNode : public GCAllocObject
    {
        PopulationNode(StackTrace* trace) : trace(trace), numobjects(0), numbytes(0), next(NULL) {}
        
        StackTrace* trace;
        size_t numobjects;
        uint64_t numbytes;
        PopulationNode* next;
    };
    
    ObjectPopulationProfiler::ObjectPopulationProfiler(GC* gc, const char* profileName)
        : gc(gc)
        , heap(gc->GetGCHeap())
        , profileName(profileName)
        , list(NULL)
        , length(0)
    {
    }

    ObjectPopulationProfiler::~ObjectPopulationProfiler()
    {
        while (list != NULL)
        {
            PopulationNode* pn = list;
            list = list->next;
            delete pn;
        }
    }

    void ObjectPopulationProfiler::accountForObject(const void* obj)
    {
        StackTrace* trace = heap->GetProfiler()->GetAllocationTrace(obj);
        if (trace != NULL)
        {
            size_t size = GC::Size(obj);
            PopulationNode* l = list;
            while (l != NULL)
            {
                int i;
                for ( i=0; i < kMaxStackTrace && l->trace->ips[i] == trace->ips[i] ; i++ )
                    ;
                if (i == kMaxStackTrace)
                    break;
                l = l->next;
            }
            
            if (l == NULL)
            {
                PopulationNode* pn = new PopulationNode(trace);
                length++;
                pn->next = list;
                list = pn;
                l = pn;
            }
            
            l->numobjects++;
            l->numbytes += size;
        }
    }

    static uint32_t log2(uint32_t n)
    {
        uint32_t result = 0;
        while (n > 1) {
            result += 1;
            n >>= 1;
        }
        return result;
    }

    void ObjectPopulationProfiler::accountForRoot(size_t size)
    {
        roots.numobjects++;
        roots.numbytes += size;
        uint32_t slot = log2(uint32_t(size));
        rootHistogram[slot].numobjects++;
        rootHistogram[slot].numbytes += size;
    }

    void ObjectPopulationProfiler::accountForStack(size_t size)
    {
        stacks.numobjects++;
        stacks.numbytes += size;
        uint32_t slot = log2(uint32_t(size));
        stackHistogram[slot].numobjects++;
        stackHistogram[slot].numbytes += size;
    }
    
    // Sort by byte volume, then dump the top entries
    
    void ObjectPopulationProfiler::dumpTopBacktraces(int howmany, DumpMode mode)
    {
        MMgc::GC::AllocaAutoPtr _popnode;
        PopulationNode** xs = (PopulationNode**)VMPI_alloca_gc(gc, _popnode, howmany*sizeof(PopulationNode*));
        int live = 0;
        
        for ( PopulationNode* l = list ; l != NULL ; l = l->next )
        {
            bool inserted = false;
            for ( int i=0 ; i < live && !inserted ; i++ )
            {
                bool insert = false;
                if (mode == BY_VOLUME)
                    insert = l->numbytes > xs[i]->numbytes;
                else if (mode == BY_COUNT)
                    insert = l->numobjects > xs[i]->numobjects || (l->numobjects == xs[i]->numobjects && l->numbytes > xs[i]->numbytes);
                if (insert)
                {
                    for ( int j=howmany-1 ; j > i ; j-- )
                        xs[j] = xs[j-1];
                    xs[i] = l;
                    inserted = true;
                }
            }
            if (!inserted && live < howmany)
            {
                xs[live] = l;
                inserted = true;
            }
            if (inserted && live < howmany)
                live++;
        }

        GCLog("Object population profile: %s\n", profileName);
        GCLog("Nodes: %u\n", (unsigned)length);
        GCLog("Roots:  %llu bytes scanned  - %u objs scanned\n", (unsigned long long)roots.numbytes, (unsigned)roots.numobjects);
        for ( size_t i=0 ; i < ARRAY_SIZE(rootHistogram) ; i++ )
        {
            if (rootHistogram[i].numobjects > 0)
                GCLog("  Class %d-%d:  %llu bytes scanned  - %u objs scanned\n", 
                      (1 << i),
                      (1 << (i+1))-1,
                      (unsigned long long)rootHistogram[i].numbytes, (unsigned)rootHistogram[i].numobjects);
        }
        GCLog("Stacks: %llu bytes scanned  - %u objs scanned\n", (unsigned long long)stacks.numbytes, (unsigned)stacks.numobjects);
        for ( size_t i=0 ; i < ARRAY_SIZE(stackHistogram) ; i++ )
        {
            if (stackHistogram[i].numobjects > 0)
                GCLog("  Class %d-%d:  %llu bytes scanned  - %u objs scanned\n", 
                      (1 << i),
                      (1 << (i+1))-1,
                      (unsigned long long)stackHistogram[i].numbytes, (unsigned)stackHistogram[i].numobjects);
        }
        GCLog("Objects:\n");
        for ( int i=0 ; i < live ; i++ )
        {
            GCLog("  %llu bytes scanned - %u objs scanned", (unsigned long long)xs[i]->numbytes, (unsigned)xs[i]->numobjects);
            PrintStackTrace(xs[i]->trace);
            GCLog("\n");
        }
    }
    
#else

    void PrintAllocStackTrace(const void *) {}
    void PrintDeleteStackTrace(const void *) {}
    const char* GetAllocationName(const void *) { return NULL; }

#endif //MMGC_MEMORY_PROFILER
    
#ifdef MMGC_MEMORY_INFO

// end user servicable parts

    size_t DebugSize()
    {
    #ifdef MMGC_64BIT
        // Our writeback pointer is 8 bytes so we need to round up to the next 8 byte
        // size.  (only 5 DWORDS are used)
        return 6 * sizeof(int32_t);
    #else
        return 4 * sizeof(int32_t);
    #endif
    }

    /*
     * allocate the memory such that we can detect underwrites, overwrites and remember
     * the allocation stack in case of a leak.   Memory is laid out like so:
     *
     * first four bytes == size
     * second four bytes == stack trace index
     * size data bytes
     * 4 bytes == GCHeap::GCEndOfObjectPoison
     * last 4/8 bytes - writeback pointer
     *
     * Its important that the stack trace index is not stored in the first 4 bytes,
     * it enables the leak detection to work see ~FixedAlloc.  Underwrite detection isn't
     * perfect, an assert will be fired if the stack table index is invalid (greater than
     * the table size or to an unused table entry) or if the size gets mangled and the
     * end tag isn't at mem+size.
    */
    void DebugDecorate(const void *item, size_t size)
    {
        item = GetRealPointer(item);

        int32_t *mem = (int32_t*)item;
        // set up the memory
        *mem++ = (int32_t)size;
        *mem++ = 0;
        mem += (size>>2);
        *mem++ = int32_t(GCHeap::GCEndOfObjectPoison);
        *mem = 0;
    #ifdef MMGC_64BIT
        *(mem+1) = 0;
        *(mem+2) = 0;
    #endif
    }

    void DebugFreeHelper(const void *item, int poison, size_t wholeSize, bool actualFree)
    {
        uint32_t *ip = (uint32_t*) item;
        if (actualFree) {
            uint32_t size = *ip;
            uint32_t *endMarker = ip + 2 + (size>>2);

            // this can be called twice on some memory in inc gc
            if(size == 0)
                return;

            if (*endMarker != uint32_t(GCHeap::GCEndOfObjectPoison))
            {
                // if you get here, you have a buffer overrun.  The stack trace about to
                // be printed tells you where the block was allocated from.  To find the
                // overrun, put a memory breakpoint on the location endMarker is pointing to.
                GCDebugMsg(false, "Memory overwrite detected\n");
                PrintAllocStackTrace(item);
                GCAssert(false);
            }
        }

        // clean up
        *ip = 0;
        ip += 2;

        // size is the non-Debug size, so add 4 to get last 4 bytes, don't
        // touch write back pointer space
        VMPI_memset(ip, poison, wholeSize+4);
    }

    void *DebugFree(const void *item, int poison, size_t size, bool actualFree)
    {
        item = GetRealPointer(item);
        DebugFreeHelper(item, poison, size, actualFree);
        return (void*)item;
    }

    void ReportDeletedMemoryWrite(const void* item)
    {
        GCDebugMsg(false, "Object 0x%llx was written to after it was deleted, allocation trace:", (unsigned long long)(uintptr_t)item);
        PrintAllocStackTrace(GetUserPointer(item));
        GCDebugMsg(false, "Deletion trace:");
        PrintDeleteStackTrace(GetUserPointer(item));
        GCDebugMsg(true, "Deleted item write violation!");
    }

#endif // defined MMGC_MEMORY_INFO

} // namespace MMgc


