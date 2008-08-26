/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2007
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

#include "nanojit.h"

#ifdef AVMPLUS_PORTING_API
#include "portapi_nanojit.h"
#endif

#if defined(AVMPLUS_LINUX) && defined(AVMPLUS_ARM)
#include <asm/unistd.h>
#endif

#ifdef PERFM
#include "../vprof/vprof.h"
#endif /* PERFM */

namespace nanojit
{
	#ifdef FEATURE_NANOJIT


	class DeadCodeFilter: public LirFilter
	{
		const CallInfo *functions;

	    bool ignoreInstruction(LInsp ins)
	    {
            LOpcode op = ins->opcode();
            if (ins->isStore() ||
                op == LIR_def ||
                op == LIR_loop ||
                op == LIR_label ||
                op == LIR_live ||
                isRet(op)) {
                return false;
            }
	        return ins->resv() == 0;
	    }

	public:
		DeadCodeFilter(LirFilter *in, const CallInfo *f) : LirFilter(in), functions(f) {}
		LInsp read() {
			for (;;) {
				LInsp i = in->read();
				if (!i || i->isGuard() || i->isBranch()
					|| i->isCall() && !functions[i->fid()]._cse
					|| !ignoreInstruction(i))
					return i;
			}
		}
	};

#ifdef NJ_VERBOSE
	class VerboseBlockReader: public LirFilter
	{
		Assembler *assm;
		LirNameMap *names;
		avmplus::List<LInsp, avmplus::LIST_NonGCObjects> block;
        bool flushnext;
	public:
		VerboseBlockReader(LirFilter *in, Assembler *a, LirNameMap *n) 
			: LirFilter(in), assm(a), names(n), block(a->_gc), flushnext(false)
        {}

		void flush() {
            flushnext = false;
            if (!block.isEmpty()) {
			    assm->outputf("        %p:", assm->_nIns);
			    assm->output("");
			    for (int j=0,n=block.size(); j < n; j++)
				    assm->outputf("    %s", names->formatIns(block[j]));
			    assm->output("");
			    block.clear();
            }
		}

        void flush_add(LInsp i) {
            flush();
            block.add(i);
        }

		LInsp read() {
			LInsp i = in->read();
			if (!i) {
				flush();
				return i;
			}
            if (i->isGuard() || i->isBranch()) {
				flush_add(i);
				if (i->oprnd1())
					block.add(i->oprnd1());
            }
            else if (isRet(i->opcode())/* || i->isStore()*/) {
                flush_add(i);
            }
			else {
                if (flushnext)
                    flush();
				block.add(i);
                if (i->isop(LIR_label))
                    flushnext = true;
			}
			return i;
		}
	};
#endif
	
	/**
	 * Need the following:
	 *
	 *	- merging paths ( build a graph? ), possibly use external rep to drive codegen
	 */
    Assembler::Assembler(Fragmento* frago)
        : _frago(frago)
        , _gc(frago->core()->gc)
        , _labels(_gc)
        , _patches(_gc)
        , hasLoop(0)
	{
        AvmCore *core = frago->core();
		nInit(core);
		verbose_only( _verbose = !core->quiet_opt() && core->verbose() );
		verbose_only( _outputCache = 0);
		
		internalReset();
		pageReset();
	}

    void Assembler::arReset()
	{
		_activation.highwatermark = 0;
		_activation.lowwatermark = 0;
		_activation.tos = 0;

		for(uint32_t i=0; i<NJ_MAX_STACK_ENTRY; i++)
			_activation.entry[i] = 0;
	}

 	void Assembler::registerResetAll()
	{
		nRegisterResetAll(_allocator);

		// keep a tally of the registers to check that our allocator works correctly
		debug_only(_allocator.count = _allocator.countFree(); )
		debug_only(_allocator.checkCount(); )
		debug_only(_fpuStkDepth = 0; )
	}

	Register Assembler::registerAlloc(RegisterMask allow)
	{
		RegAlloc &regs = _allocator;
//		RegisterMask prefer = livePastCall(_ins) ? saved : scratch;
		RegisterMask prefer = SavedRegs & allow;
		RegisterMask free = regs.free & allow;

		RegisterMask set = prefer;
		if (set == 0) set = allow;

        if (free)
        {
    		// at least one is free
		    set &= free;

		    // ok we have at least 1 free register so let's try to pick 
		    // the best one given the profile of the instruction 
		    if (!set)
		    {
			    // desired register class is not free so pick first of any class
			    set = free;
		    }
		    NanoAssert((set & allow) != 0);
		    Register r = nRegisterAllocFromSet(set);
		    regs.used |= rmask(r);
		    return r;
        }
		counter_increment(steals);

		// nothing free, steal one 
		// LSRA says pick the one with the furthest use
		LIns* vic = findVictim(regs,allow,prefer);
	    Reservation* resv = getresv(vic);

		// restore vic
	    Register r = resv->reg;
        regs.removeActive(r);
        resv->reg = UnknownReg;

		asm_restore(vic, resv, r);
		return r;
	}

	void Assembler::reserveReset()
	{
		_resvTable[0].arIndex = 0;
		int i;
        for(i=1; i<NJ_MAX_STACK_ENTRY; i++) {
			_resvTable[i].arIndex = i-1;
            _resvTable[i].used = 0;
        }
		_resvFree= i-1;
	}

	Reservation* Assembler::reserveAlloc(LInsp i)
	{
		uint32_t item = _resvFree;
        Reservation *r = &_resvTable[item];
		_resvFree = r->arIndex;
		r->reg = UnknownReg;
		r->arIndex = 0;
        r->used = 1;
		if (!item) 
			setError(ResvFull); 

        if (i->isconst() || i->isconstq() || i->isop(LIR_alloc))
            r->cost = 0;
        else if (i == _thisfrag->lirbuf->sp || i == _thisfrag->lirbuf->rp)
            r->cost = 2;
        else
            r->cost = 1;

        i->setresv(item);
		return r;
	}

	void Assembler::reserveFree(LInsp i)
	{
        Reservation *rs = getresv(i);
        NanoAssert(rs == &_resvTable[i->resv()]);
		rs->arIndex = _resvFree;
        rs->used = 0;
		_resvFree = i->resv();
        i->setresv(0);
	}

	void Assembler::internalReset()
	{
		// readies for a brand spanking new code generation pass.
		registerResetAll();
		reserveReset();
		arReset();
	}

	NIns* Assembler::pageAlloc(bool exitPage)
	{
		Page*& list = (exitPage) ? _nativeExitPages : _nativePages;
		Page* page = _frago->pageAlloc();
		if (page)
		{
			page->next = list;
			list = page;
			nMarkExecute(page);
			_stats.pages++;
		}
		else
		{
			// return prior page (to allow overwrites) and mark out of mem 
			page = list;
			setError(OutOMem);
		}
		return &page->code[sizeof(page->code)/sizeof(NIns)]; // just past the end
	}
	
	void Assembler::pageReset()
	{
		pagesFree(_nativePages);		
		pagesFree(_nativeExitPages);
		
		_nIns = 0;
		_nExitIns = 0;
		_stats.pages = 0;

		nativePageReset();
	}
	
	void Assembler::pagesFree(Page*& page)
	{
		while(page)
		{
			Page *next = page->next;  // pull next ptr prior to free
			_frago->pageFree(page);
			page = next;
		}
	}

	#define bytesFromTop(x)		( (size_t)(x) - (size_t)pageTop(x) )
	#define bytesToBottom(x)	( (size_t)pageBottom(x) - (size_t)(x) )
	#define bytesBetween(x,y)	( (size_t)(x) - (size_t)(y) )
	
	int32_t Assembler::codeBytes()
	{
		// start and end on same page?
		size_t exit = 0;
		if (samepage(_nExitIns,_stats.codeExitStart-1))
		{
			exit = bytesBetween(_stats.codeExitStart, _nExitIns);
		}
		else if (_nExitIns != _stats.codeExitStart)
		{
			exit = bytesFromTop(_stats.codeExitStart);
			exit += bytesToBottom(_nExitIns);
		}

		size_t main = 0;
		NanoAssert(_nIns != _stats.codeStart);
		if (samepage(_nIns,_stats.codeStart-1))
		{
			main = bytesBetween(_stats.codeStart, _nIns);
		}
		else
		{
			main = bytesFromTop(_stats.codeStart);
			main += bytesToBottom(_nIns);
		}

		return _stats.pages * sizeof(Page) + main + exit;		
	}

	#undef bytesFromTop
	#undef bytesToBottom
	#undef byteBetween
	
	Page* Assembler::handoverPages(bool exitPages)
	{
		Page*& list = (exitPages) ? _nativeExitPages : _nativePages;
		NIns*& ins =  (exitPages) ? _nExitIns : _nIns;
		Page* start = list;
		list = 0;
		ins = 0;
		return start;
	}

	#ifdef _DEBUG
	bool Assembler::onPage(NIns* where, bool exitPages)
	{
		Page* page = (exitPages) ? _nativeExitPages : _nativePages;
		bool on = false;
		while(page)
		{
			if (samepage(where-1,page))
				on = true;
			page = page->next;
		}
		return on;
	}
	
	void Assembler::pageValidate()
	{
		if (error()) return;
		// _nIns and _nExitIns need to be at least on
		// one of these pages
		NanoAssertMsg( onPage(_nIns)&& onPage(_nExitIns,true), "Native instruction pointer overstep paging bounds; check overrideProtect for last instruction");
	}
	#endif

	const CallInfo* Assembler::callInfoFor(uint32_t fid)
	{	
		NanoAssert(fid < CI_Max);
		return &_thisfrag->lirbuf->_functions[fid];
	}

	#ifdef _DEBUG
	
	void Assembler::resourceConsistencyCheck()
	{
		if (error()) return;

#ifdef NANOJIT_IA32
        NanoAssert(_allocator.active[FST0] && _fpuStkDepth == -1 ||
            !_allocator.active[FST0] && _fpuStkDepth == 0);
#endif
		
        AR &ar = _activation;
		// check AR entries
		NanoAssert(ar.highwatermark < NJ_MAX_STACK_ENTRY);
		LIns* ins = 0;
		RegAlloc* regs = &_allocator;
		for(uint32_t i = ar.lowwatermark; i < ar.tos; i++)
		{
			ins = ar.entry[i];
			if ( !ins )
				continue;
			Reservation *r = getresv(ins);
            NanoAssert(r != 0);
			int32_t idx = r - _resvTable;
			NanoAssertMsg(idx, "MUST have a resource for the instruction for it to have a stack location assigned to it");
            if (r->arIndex) {
                if (ins->isop(LIR_alloc)) {
                    int j=i+1;
                    for (int n = i + (ins->size()>>2); j < n; j++) {
                        NanoAssert(ar.entry[j]==ins);
                    }
		        	NanoAssert(r->arIndex == (uint32_t)j-1);
                    i = j-1;
                }
                else if (ins->isQuad()) {
                    NanoAssert(ar.entry[i - stack_direction(1)]==ins);
                    i += 1; // skip high word
                }
                else {
        			NanoAssertMsg(r->arIndex == i, "Stack record index mismatch");
                }
            }
			NanoAssertMsg( r->reg==UnknownReg || regs->isConsistent(r->reg,ins), "Register record mismatch");
		}
	
		registerConsistencyCheck();
				
		// check resv table
		int32_t inuseCount = 0;
		int32_t notInuseCount = 0;
        for(uint32_t i=1; i < sizeof(_resvTable)/sizeof(_resvTable[0]); i++) {
            _resvTable[i].used ? inuseCount++ : notInuseCount++;
        }

		int32_t freeCount = 0;
		uint32_t free = _resvFree;
        while(free) {
			free = _resvTable[free].arIndex;
			freeCount++;
		}
		NanoAssert( ( freeCount==notInuseCount && inuseCount+notInuseCount==(NJ_MAX_STACK_ENTRY-1) ) );
	}

	void Assembler::registerConsistencyCheck()
	{	
		// check registers
		RegAlloc *regs = &_allocator;
		uint32_t managed = regs->managed;
		Register r = FirstReg;
		while(managed)
		{
			if (managed&1)
			{
				if (regs->isFree(r))
				{
					NanoAssert(regs->getActive(r)==0);
				}
				else
				{
					LIns* ins = regs->getActive(r);
					// @todo we should be able to check across RegAlloc's somehow (to include savedGP...)
					Reservation *v = getresv(ins);
					NanoAssert(v != 0);
					int32_t idx = v - _resvTable;
					NanoAssert(idx >= 0 && idx < NJ_MAX_STACK_ENTRY);
					NanoAssertMsg(idx, "MUST have a resource for the instruction for it to have a register assigned to it");
					NanoAssertMsg( regs->getActive(v->reg)==ins, "Register record mismatch");
				}			
			}
			
			// next register in bitfield
			r = nextreg(r);
			managed >>= 1;
		}
	}
	#endif /* _DEBUG */

	void Assembler::findRegFor2(RegisterMask allow, LIns* ia, Reservation* &resva, LIns* ib, Reservation* &resvb)
	{
		if (ia == ib) 
		{
			findRegFor(ia, allow);
			resva = resvb = getresv(ia);
		}
		else
		{
			Register rb = UnknownReg;
			resvb = getresv(ib);
			if (resvb && (rb = resvb->reg) != UnknownReg)
				allow &= ~rmask(rb);
			Register ra = findRegFor(ia, allow);
			resva = getresv(ia);
			NanoAssert(error() || (resva != 0 && ra != UnknownReg));
			if (rb == UnknownReg)
			{
				allow &= ~rmask(ra);
				findRegFor(ib, allow);
				resvb = getresv(ib);
			}
		}
	}

	Register Assembler::findSpecificRegFor(LIns* i, Register w)
	{
		return findRegFor(i, rmask(w));
	}
			
	Register Assembler::findRegFor(LIns* i, RegisterMask allow)
	{
        if (i->isop(LIR_alloc)) {
            // never allocate a reg for this w/out stack space too
            findMemFor(i);
        }

        Reservation* resv = getresv(i);
		Register r;

        if (resv && (r=resv->reg) != UnknownReg && (rmask(r) & allow)) {
			return r;
        }

		RegisterMask prefer = hint(i, allow);
        if (!resv)
			resv = reserveAlloc(i);

        if ((r=resv->reg) == UnknownReg)
		{
            if (resv->cost == 2 && (allow&SavedRegs))
                prefer = allow&SavedRegs;
			r = resv->reg = registerAlloc(prefer);
			_allocator.addActive(r, i);
			return r;
		}
		else 
		{
			// r not allowed
			resv->reg = UnknownReg;
			_allocator.retire(r);
            if (resv->cost == 2 && (allow&SavedRegs))
                prefer = allow&SavedRegs;
			Register s = resv->reg = registerAlloc(prefer);
			_allocator.addActive(s, i);
            if (rmask(r) & GpRegs) {
    			MR(r, s);
            } 
            else {
				asm_nongp_copy(r, s);
			}
			return s;
		}
	}

	int Assembler::findMemFor(LIns *i)
	{
		Reservation* resv = getresv(i);
		if (!resv)
			resv = reserveAlloc(i);
		if (!resv->arIndex)
			resv->arIndex = arReserve(i);
		return disp(resv);
	}

	Register Assembler::prepResultReg(LIns *i, RegisterMask allow)
	{
		Reservation* resv = getresv(i);
		const bool pop = !resv || resv->reg == UnknownReg;
		Register rr = findRegFor(i, allow);
		freeRsrcOf(i, pop);
		return rr;
	}

	void Assembler::freeRsrcOf(LIns *i, bool pop)
	{
		Reservation* resv = getresv(i);
		int index = resv->arIndex;
		Register rr = resv->reg;

		if (rr != UnknownReg)
		{
			asm_spilli(i, resv, pop);
			_allocator.retire(rr);	// free any register associated with entry
		}
		if (index)
            arFree(index);			// free any stack stack space associated with entry
		reserveFree(i);		// clear fields of entry and add it to free list
	}

	void Assembler::evict(Register r)
	{
		registerAlloc(rmask(r));
		_allocator.addFree(r);
	}

	void Assembler::asm_cmp(LIns *cond)
	{
        LOpcode condop = cond->opcode();
        
        // LIR_ov and LIR_cs recycle the flags set by arithmetic ops
        if ((condop == LIR_ov) || (condop == LIR_cs))
            return;
        
        LInsp lhs = cond->oprnd1();
		LInsp rhs = cond->oprnd2();
		Reservation *rA, *rB;

		NanoAssert((!lhs->isQuad() && !rhs->isQuad()) || (lhs->isQuad() && rhs->isQuad()));

		// Not supported yet.
#if !defined NANOJIT_64BIT
		NanoAssert(!lhs->isQuad() && !rhs->isQuad());
#endif

		// ready to issue the compare
		if (rhs->isconst())
		{
			int c = rhs->constval();
			Register r = findRegFor(lhs, GpRegs);
			if (c == 0 && cond->isop(LIR_eq)) {
				if (rhs->isQuad()) {
#if defined NANOJIT_64BIT
					TESTQ(r, r);
#endif
				} else {
					TEST(r,r);
				}
			// No 64-bit immediates so fall-back to below
			} else if (!rhs->isQuad()) {
				CMPi(r, c);
			}
		}
		else
		{
			findRegFor2(GpRegs, lhs, rA, rhs, rB);
			Register ra = rA->reg;
			Register rb = rB->reg;
			if (rhs->isQuad()) {
#if defined NANOJIT_64BIT
				CMPQ(ra, rb);
#endif
			} else {
				CMP(ra, rb);
			}
		}
	}

    void Assembler::patch(GuardRecord *lr)
    {
        Fragment *frag = lr->target;
		NanoAssert(frag->fragEntry != 0);
		NIns* was = asm_adjustBranch((NIns*)lr->jmp, frag->fragEntry);
		if (!lr->origTarget) lr->origTarget = was;
		verbose_only(verbose_outputf("patching jump at %p to target %p (was %p)\n",
			lr->jmp, frag->fragEntry, was);)
    }

    void Assembler::unpatch(GuardRecord *lr)
    {
		NIns* was = asm_adjustBranch((NIns*)lr->jmp, (NIns*)lr->origTarget);
		(void)was;
		verbose_only(verbose_outputf("unpatching jump at %p to original target %p (was %p)\n",
			lr->jmp, lr->origTarget, was);)
    }

    NIns* Assembler::asm_exit(LInsp guard)
    {
		SideExit *exit = guard->exit();
		NIns* at = 0;
		if (!_branchStateMap->get(exit))
		{
			at = asm_leave_trace(guard);
		}
		else
		{
			RegAlloc* captured = _branchStateMap->get(exit);
			intersectRegisterState(*captured);
			verbose_only(
				verbose_outputf("        merging trunk with %s",
					_frago->labels->format(exit->target));
				verbose_outputf("        %p:",_nIns);
			)			
			at = exit->target->fragEntry;
			NanoAssert(at != 0);
			_branchStateMap->remove(exit);
		}
		return at;
	}
	
	NIns* Assembler::asm_leave_trace(LInsp guard)
	{
        verbose_only(bool priorVerbose = _verbose; )
		verbose_only( _verbose = verbose_enabled() && _frago->core()->config.verbose_exits; )
        verbose_only( int32_t nativeSave = _stats.native );
		verbose_only(verbose_outputf("--------------------------------------- end exit block SID %d", guard->exit()->sid);)

		RegAlloc capture = _allocator;

        // this point is unreachable.  so free all the registers.
		// if an instruction has a stack entry we will leave it alone,
		// otherwise we free it entirely.  intersectRegisterState will restore.
		releaseRegisters();
		
		swapptrs();
		_inExit = true;
		
		//verbose_only( verbose_outputf("         LIR_xend swapptrs, _nIns is now %08X(%08X), _nExitIns is now %08X(%08X)",_nIns, *_nIns,_nExitIns,*_nExitIns) );
		debug_only( _sv_fpuStkDepth = _fpuStkDepth; _fpuStkDepth = 0; )

		nFragExit(guard);

		// if/when we patch this exit to jump over to another fragment,
		// that fragment will need its parameters set up just like ours.
        LInsp stateins = _thisfrag->lirbuf->state;
		Register state = findSpecificRegFor(stateins, Register(stateins->imm8()));
		asm_bailout(guard, state);

		intersectRegisterState(capture);

		// this can be useful for breaking whenever an exit is taken
		//INT3();
		//NOP();

		// we are done producing the exit logic for the guard so demark where our exit block code begins
		NIns* jmpTarget = _nIns;	 // target in exit path for our mainline conditional jump 

		// swap back pointers, effectively storing the last location used in the exit path
		swapptrs();
		_inExit = false;
		
		//verbose_only( verbose_outputf("         LIR_xt/xf swapptrs, _nIns is now %08X(%08X), _nExitIns is now %08X(%08X)",_nIns, *_nIns,_nExitIns,*_nExitIns) );
		verbose_only( verbose_outputf("        %p:",jmpTarget);)
		verbose_only( verbose_outputf("--------------------------------------- exit block (LIR_xt|LIR_xf)") );

#ifdef NANOJIT_IA32
		NanoAssertMsgf(_fpuStkDepth == _sv_fpuStkDepth, ("LIR_xtf, _fpuStkDepth=%d, expect %d\n",_fpuStkDepth, _sv_fpuStkDepth));
		debug_only( _fpuStkDepth = _sv_fpuStkDepth; _sv_fpuStkDepth = 9999; )
#endif

        verbose_only( _verbose = priorVerbose; )
        verbose_only(_stats.exitnative += (_stats.native-nativeSave));

        return jmpTarget;
    }
	
	void Assembler::beginAssembly(RegAllocMap* branchStateMap)
	{
		_activation.lowwatermark = 1;
		_activation.tos = _activation.lowwatermark;
		_activation.highwatermark = _activation.tos;
		
		counter_reset(native);
		counter_reset(exitnative);
		counter_reset(steals);
		counter_reset(spills);
		counter_reset(remats);

		setError(None);

		// native code gen buffer setup
		nativePageSetup();
		
	#ifdef AVMPLUS_PORTING_API
		_endJit1Addr = _nIns;
		_endJit2Addr = _nExitIns;
	#endif

		// make sure we got memory at least one page
		if (error()) return;
			
#ifdef PERFM
		_stats.pages = 0;
		_stats.codeStart = _nIns;
		_stats.codeExitStart = _nExitIns;		
#endif /* PERFM */

        _epilogue = genEpilogue(SavedRegs);
		_branchStateMap = branchStateMap;
        _labels.clear();
		
		verbose_only( verbose_outputf("        %p:",_nIns) );
		verbose_only( verbose_output("        epilogue:") );
	}
	
	void Assembler::assemble(Fragment* frag,  NInsList& loopJumps)
	{
		if (error()) return;	
		AvmCore *core = _frago->core();
		GC *gc = core->gc;
        _thisfrag = frag;

		// set up backwards pipeline: assembler -> StackFilter -> LirReader
		LirReader bufreader(frag->lastIns);
		StackFilter storefilter1(&bufreader, gc, frag->lirbuf, frag->lirbuf->sp);
		StackFilter storefilter2(&storefilter1, gc, frag->lirbuf, frag->lirbuf->rp);
		DeadCodeFilter deadfilter(&storefilter2, frag->lirbuf->_functions);
		LirFilter* rdr = &deadfilter;
		verbose_only(
			VerboseBlockReader vbr(rdr, this, frag->lirbuf->names);
			if (verbose_enabled())
				rdr = &vbr;
		)

		verbose_only(_thisfrag->compileNbr++; )
		verbose_only(_frago->_stats.compiles++; )
		verbose_only(_frago->_stats.totalCompiles++; )
		_latestGuard = 0;
		_inExit = false;		
		gen(rdr, loopJumps);
		frag->fragEntry = _nIns;
		frag->outbound = core->config.tree_opt? _latestGuard : 0;
		//fprintf(stderr, "assemble frag %X entry %X\n", (int)frag, (int)frag->fragEntry);

		// patch all branches
		while(!_patches.isEmpty())
		{
			NIns* where = _patches.lastKey();
			LInsp targ = _patches.removeLast();
            LabelState *label = _labels.get(targ);
			NIns* ntarg = label->addr;
            if (ntarg) {
				nPatchBranch(where,ntarg);
			}
            else {
				_err = UnknownBranch;
				break;
			}
		}
	}

	void Assembler::endAssembly(Fragment* frag, NInsList& loopJumps)
	{
		while(!loopJumps.isEmpty())
		{
			NIns* loopJump = (NIns*)loopJumps.removeLast();
			nPatchBranch(loopJump, _nIns);
		}

		NIns* patchEntry = 0;
		if (!error())
		{
			patchEntry = genPrologue(SavedRegs);
			verbose_only( verbose_outputf("        %p:",_nIns); )
			verbose_only( verbose_output("        prologue"); )
		}
		
		// something bad happened?
		if (!error())
		{
			// check for resource leaks 
			debug_only( 
				for(uint32_t i=_activation.lowwatermark;i<_activation.highwatermark; i++) {
					NanoAssertMsgf(_activation.entry[i] == 0, ("frame entry %d wasn't freed\n",-4*i)); 
				}
			)

            frag->fragEntry = patchEntry;
			NIns* code = _nIns;
#ifdef PERFM
			_nvprof("code", codeBytes());  // requires that all pages are released between begin/endAssembly()otherwise we double count
#endif
			// let the fragment manage the pages if we're using trees and there are branches
			Page* manage = (_frago->core()->config.tree_opt) ? handoverPages() : 0;
			frag->setCode(code, manage); // root of tree should manage all pages
			//fprintf(stderr, "endAssembly frag %X entry %X\n", (int)frag, (int)frag->fragEntry);
		}
		
		NanoAssertMsgf(error() || _fpuStkDepth == 0, ("_fpuStkDepth %d\n",_fpuStkDepth));

		internalReset();  // clear the reservation tables and regalloc
		NanoAssert(_branchStateMap->isEmpty());
		_branchStateMap = 0;
		
		#if defined(UNDER_CE)
		// If we've modified the code, we need to flush so we don't end up trying 
		// to execute junk
		FlushInstructionCache(GetCurrentProcess(), NULL, NULL);
		#elif defined(AVMPLUS_LINUX) && defined(AVMPLUS_ARM)
			// N A S T Y - obviously have to fix this
		// determine our page range

		Page *page=0, *first=0, *last=0;
		for (int i=2;i!=0;i--) {
			page = first = last = (i==2 ? _nativePages : _nativeExitPages);
			while (page)
			{
				if (page<first)
					first = page;
				if (page>last)
					last = page;
				page = page->next;
			}
	
			register unsigned long _beg __asm("a1") = (unsigned long)(first);
			register unsigned long _end __asm("a2") = (unsigned long)(last+NJ_PAGE_SIZE);
			register unsigned long _flg __asm("a3") = 0;
			register unsigned long _swi __asm("r7") = 0xF0002;
			__asm __volatile ("swi 0 	@ sys_cacheflush" : "=r" (_beg) : "0" (_beg), "r" (_end), "r" (_flg), "r" (_swi));
		}
		#endif
	#ifdef AVMPLUS_PORTING_API
		NanoJIT_PortAPI_FlushInstructionCache(_nIns, _endJit1Addr);
		NanoJIT_PortAPI_FlushInstructionCache(_nExitIns, _endJit2Addr);
	#endif
	}
	
	void Assembler::copyRegisters(RegAlloc* copyTo)
	{
		*copyTo = _allocator;
	}

	void Assembler::releaseRegisters()
	{
		for (Register r = FirstReg; r <= LastReg; r = nextreg(r))
		{
			LIns *i = _allocator.getActive(r);
			if (i)
			{
				// clear reg allocation, preserve stack allocation.
				Reservation* resv = getresv(i);
				NanoAssert(resv != 0);
				_allocator.retire(r);
				if (r == resv->reg)
					resv->reg = UnknownReg;

				if (!resv->arIndex && resv->reg == UnknownReg)
				{
					reserveFree(i);
				}
			}
		}
	}
	
	void Assembler::gen(LirFilter* reader,  NInsList& loopJumps)
	{
		// trace must start with LIR_x or LIR_loop
		//NanoAssert(reader->pos()->isop(LIR_x) || reader->pos()->isop(LIR_loop));
		 
		for (LInsp ins = reader->read(); ins != 0 && !error(); ins = reader->read())
		{
			LOpcode op = ins->opcode();			
			switch(op)
			{
				default:
					NanoAssertMsg(false, "unsupported LIR instruction");
					break;

                case LIR_live: {
                    findMemFor(ins->oprnd1());
                    break;
                }

                case LIR_ret:  {
                    LIns *val = ins->oprnd1();
                    findSpecificRegFor(val, retRegs[0]);
                    if (_nIns != _epilogue) {
                        JMP(_epilogue);
                    }
                    MR(SP,FP);
                    break;
                }

                case LIR_fret: {
                    LIns *val = ins->oprnd1();
                    findSpecificRegFor(val, FST0);
                    fpu_pop();
                    if (_nIns != _epilogue) {
                        JMP(_epilogue);
                    }
                    MR(SP,FP);
                    if (sse2)
                        evict(FST0);
                    break;
                }

                // allocate some stack space.  the value of this instruction
                // is the address of the stack space.
                case LIR_alloc: {
                    Reservation *resv = getresv(ins);
                    NanoAssert(resv->arIndex != 0);
                    Register r = resv->reg;
                    if (r != UnknownReg) {
    			        _allocator.retire(r);
                        resv->reg = UnknownReg;
                        asm_restore(ins, resv, r);
                    }
                    freeRsrcOf(ins, 0);
                    break;
                }

				case LIR_var:
				{
					Reservation* r = getresv(ins);
					NanoAssert(r->reg == UnknownReg); // don't directly access LIR_var, LIR_use it first
					arFree(r->arIndex);	// free any stack stack space associated with entry
					reserveFree(ins);	// clear fields of entry and add it to free list
					break;
				}					
				case LIR_use:
				{
					LInsp to = ins->oprnd1();
					int d = findMemFor(to); // var's mem							
					Reservation* r = getresv(ins);
					if (r->reg == UnknownReg)
					{
						// was spilled so we need to ld/st
						NanoAssert(r->arIndex);  // must be on the stack ; otherwise this is dead code!
						Register rr = findRegFor(ins, GpRegs);
						evict(rr);      // store to spill'd location						
						asm_load(d,rr); // load from var 
						NanoAssertMsg(0,"Call me if you hit this untested path [rickr]");
					}
					else
					{
						// should be in a reg so we just need a load
						asm_load(d,r->reg);
						_allocator.retire(r->reg);
						r->reg = UnknownReg;
					}

					arFree(r->arIndex);	// free any stack stack space associated with entry
					reserveFree(ins);	// clear fields of entry and add it to free list
					break;
				}					
			
			
				case LIR_def:
				{
					NanoAssert(!getresv(ins));  // like store no one should ref this.
					LInsp to = ins->oprnd1();
					LInsp val = ins->oprnd2();
					int d = findMemFor(to); // var's mem
					Register valreg = findRegFor(val, GpRegs);					
					asm_spill(valreg, d);
					break;
				}					
				case LIR_short:
				case LIR_int:
				{
					Register rr = prepResultReg(ins, GpRegs);
					int32_t val;
					if (op == LIR_int)
						val = ins->imm32();
					else
						val = ins->imm16();
					if (val == 0)
						XOR(rr,rr);
					else
						LDi(rr, val);
					break;
				}
				case LIR_quad:
				{
					asm_quad(ins);
					break;
				}
				case LIR_callh:
				{
					// return result of quad-call in register
					prepResultReg(ins, rmask(retRegs[1]));
                    // if hi half was used, we must use the call to ensure it happens
                    findRegFor(ins->oprnd1(), rmask(retRegs[0]));
					break;
				}
				case LIR_param:
				{
                    uint32_t a = ins->imm8();
                    AbiKind abi = _thisfrag->lirbuf->abi;
                    uint32_t abi_regcount = abi == ABI_FASTCALL ? 2 : abi == ABI_THISCALL ? 1 : 0;
                    if (a < abi_regcount) {
					    Register w = argRegs[a];
                        NanoAssert(w != UnknownReg);
					    // incoming arg in register
					    prepResultReg(ins, rmask(w));
                    } else {
                        // incoming arg is on stack, and EAX points nearby (see genPrologue)
						evict(EAX);
                        Register r = prepResultReg(ins, GpRegs & ~rmask(EAX));
                        int d = (a - abi_regcount) * sizeof(intptr_t) + 8;
                        LD(r, d, EAX); 
                    }
					break;
				}
				case LIR_qlo:
                {
					LIns *q = ins->oprnd1();

					if (!asm_qlo(ins, q))
					{
    					Register rr = prepResultReg(ins, GpRegs);
				        int d = findMemFor(q);
				        LD(rr, d, FP);
                    }
					break;
                }
				case LIR_qhi:
				{
					Register rr = prepResultReg(ins, GpRegs);
					LIns *q = ins->oprnd1();
					int d = findMemFor(q);
				    LD(rr, d+4, FP);
					break;
				}

				case LIR_cmov:
				{
					LIns* condval = ins->oprnd1();
					NanoAssert(condval->isCmp());

					LIns* values = ins->oprnd2();

					NanoAssert(values->opcode() == LIR_2);
					LIns* iftrue = values->oprnd1();
					LIns* iffalse = values->oprnd2();
					NanoAssert(!iftrue->isQuad() && !iffalse->isQuad());
					
					const Register rr = prepResultReg(ins, GpRegs);

					// this code assumes that neither LD nor MR nor MRcc set any of the condition flags.
					// (This is true on Intel, is it true on all architectures?)
					const Register iffalsereg = findRegFor(iffalse, GpRegs & ~rmask(rr));
					switch (condval->opcode())
					{
						// note that these are all opposites...
						case LIR_eq:	MRNE(rr, iffalsereg);	break;
                        case LIR_ov:    MRNO(rr, iffalsereg);   break;
                        case LIR_cs:    MRNC(rr, iffalsereg);   break;
						case LIR_lt:	MRGE(rr, iffalsereg);	break;
						case LIR_le:	MRG(rr, iffalsereg);	break;
						case LIR_gt:	MRLE(rr, iffalsereg);	break;
						case LIR_ge:	MRL(rr, iffalsereg);	break;
						case LIR_ult:	MRAE(rr, iffalsereg);	break;
						case LIR_ule:	MRA(rr, iffalsereg);	break;
						case LIR_ugt:	MRBE(rr, iffalsereg);	break;
						case LIR_uge:	MRB(rr, iffalsereg);	break;
						debug_only( default: NanoAssert(0); break; )
					}
					/*const Register iftruereg =*/ findSpecificRegFor(iftrue, rr);
					asm_cmp(condval);
					break;
				}

				case LIR_ld:
				case LIR_ldc:
				case LIR_ldcb:
				{
					LIns* base = ins->oprnd1();
					LIns* disp = ins->oprnd2();
					Register rr = prepResultReg(ins, GpRegs);
					Register ra;
					int d = disp->constval();
                    if (base->isop(LIR_alloc)) {
                        ra = FP;
                        d += findMemFor(base);
                    } else {
                        ra = findRegFor(base, GpRegs);
                    }
					if (op == LIR_ldcb)
						LD8Z(rr, d, ra);
					else
						LD(rr, d, ra); 
					break;
				}

				case LIR_ldq:
				{
					asm_load64(ins);
					break;
				}

				case LIR_neg:
				case LIR_not:
				{
					Register rr = prepResultReg(ins, GpRegs);

					LIns* lhs = ins->oprnd1();
					Reservation *rA = getresv(lhs);
					// if this is last use of lhs in reg, we can re-use result reg
					Register ra;
					if (rA == 0 || (ra=rA->reg) == UnknownReg)
						ra = findSpecificRegFor(lhs, rr);
					// else, rA already has a register assigned.

					if (op == LIR_not)
						NOT(rr); 
					else
						NEG(rr); 

					if ( rr != ra ) 
						MR(rr,ra); 
					break;
				}
				
				case LIR_qjoin:
				{
                    asm_qjoin(ins);
					break;
				}

				case LIR_add:
				case LIR_sub:
				case LIR_mul:
				case LIR_and:
				case LIR_or:
				case LIR_xor:
				case LIR_lsh:
				case LIR_rsh:
				case LIR_ush:
				{
                    LInsp lhs = ins->oprnd1();
                    LInsp rhs = ins->oprnd2();

					Register rb = UnknownReg;
					RegisterMask allow = GpRegs;
					if (lhs != rhs && (op == LIR_mul || !rhs->isconst()))
					{
#ifdef NANOJIT_IA32
						if (op == LIR_lsh || op == LIR_rsh || op == LIR_ush)
							rb = findSpecificRegFor(rhs, ECX);
						else
#endif
							rb = findRegFor(rhs, allow);
						allow &= ~rmask(rb);
					}

					Register rr = prepResultReg(ins, allow);
					Reservation* rA = getresv(lhs);
					Register ra;
					// if this is last use of lhs in reg, we can re-use result reg
					if (rA == 0 || (ra = rA->reg) == UnknownReg)
						ra = findSpecificRegFor(lhs, rr);
					// else, rA already has a register assigned.

					if (!rhs->isconst() || op == LIR_mul)
					{
						if (lhs == rhs)
							rb = ra;

						if (op == LIR_add)
							ADD(rr, rb);
						else if (op == LIR_sub)
							SUB(rr, rb);
						else if (op == LIR_mul)
							MUL(rr, rb);
						else if (op == LIR_and)
							AND(rr, rb);
						else if (op == LIR_or)
							OR(rr, rb);
						else if (op == LIR_xor)
							XOR(rr, rb);
						else if (op == LIR_lsh)
							SHL(rr, rb);
						else if (op == LIR_rsh)
							SAR(rr, rb);
						else if (op == LIR_ush)
							SHR(rr, rb);
						else
							NanoAssertMsg(0, "Unsupported");
					}
					else
					{
						int c = rhs->constval();
						if (op == LIR_add) {
#ifdef NANOJIT_IA32_TODO
							if (ra != rr) {
								LEA(rr, c, ra);
								ra = rr; // suppress mov
							} else
#endif
							{
								ADDi(rr, c); 
							}
						} else if (op == LIR_sub) {
#ifdef NANOJIT_IA32
							if (ra != rr) {
								LEA(rr, -c, ra);
								ra = rr;
							} else
#endif
							{
								SUBi(rr, c); 
							}
						} else if (op == LIR_and)
							ANDi(rr, c);
						else if (op == LIR_or)
							ORi(rr, c);
						else if (op == LIR_xor)
							XORi(rr, c);
						else if (op == LIR_lsh)
							SHLi(rr, c);
						else if (op == LIR_rsh)
							SARi(rr, c);
						else if (op == LIR_ush)
							SHRi(rr, c);
						else
							NanoAssertMsg(0, "Unsupported");
					}

					if ( rr != ra ) 
						MR(rr,ra);
					break;
				}
#ifndef NJ_SOFTFLOAT
				case LIR_fneg:
				{
					asm_fneg(ins);
					break;
				}
				case LIR_fadd:
				case LIR_fsub:
				case LIR_fmul:
				case LIR_fdiv:
				{
					asm_fop(ins);
                    break;
				}
				case LIR_i2f:
				{
					asm_i2f(ins);
					break;
				}
				case LIR_u2f:
				{
					asm_u2f(ins);
					break;
				}
#endif // NJ_SOFTFLOAT
				case LIR_st:
				case LIR_sti:
				{
                    asm_store32(ins->oprnd1(), ins->immdisp(), ins->oprnd2());
                    break;
				}
				case LIR_stq:
				case LIR_stqi:
				{
					LIns* value = ins->oprnd1();
					LIns* base = ins->oprnd2();
					int dr = ins->immdisp();
					if (value->isop(LIR_qjoin)) 
					{
						// this is correct for little-endian only
						asm_store32(value->oprnd1(), dr, base);
						asm_store32(value->oprnd2(), dr+4, base);
					}
					else 
					{
						asm_store64(value, dr, base);
					}
                    break;
				}

				case LIR_j:
				{
					LInsp to = ins->oprnd2();
                    LabelState *label = _labels.get(to);
                    // the jump is always taken so whatever register state we
                    // have from downstream code, is irrelevant to code before
                    // this jump.  so clear it out.  we will pick up register
                    // state from the jump target, if we have seen that label.
                    releaseRegisters();
                    if (label && label->addr) {
                        // forward jump - pick up register state from target.
                        unionRegisterState(label->regs);
                        JMP(label->addr);
                    }
                    else {
                        // backwards jump
                        hasLoop = true;
                        if (!label) {
                            // save empty register state at loop header
                            _labels.add(to, 0, _allocator);
                        }
                        else {
                            intersectRegisterState(label->regs);
                        }
                        JMP(0);
    					_patches.put(_nIns, to);
                        verbose_only(
                            verbose_outputf("        Loop %s -> %s", 
                                lirNames[ins->opcode()], 
                                _thisfrag->lirbuf->names->formatRef(to));
                        )
                    }
					break;
				}

				case LIR_jt:
				case LIR_jf:
				{
					LInsp to = ins->getTarget();
					LIns* cond = ins->oprnd1();
                    LabelState *label = _labels.get(to);
                    if (label && label->addr) {
                        // forward jump to known label.  need to merge with label's register state.
                        unionRegisterState(label->regs);
    					asm_branch(op == LIR_jf, cond, label->addr);
                    }
                    else {
                        // back edge.
                        hasLoop = true;
                        if (!label) {
                            // evict all registers, most conservative approach.
                            evictRegs(~_allocator.free);
                            _labels.add(to, 0, _allocator);
                        } 
                        else {
                            // evict all registers, most conservative approach.
                            intersectRegisterState(label->regs);
                        }
                        NIns *branch = asm_branch(op == LIR_jf, cond, 0);
			            _patches.put(branch,to);
                        verbose_only(
                            verbose_outputf("Loop %s -> %s", 
                                lirNames[ins->opcode()], 
                                _thisfrag->lirbuf->names->formatRef(to));
                        )
                    }
					break;
				}					
				case LIR_label:
				{
                    LabelState *label = _labels.get(ins);
                    if (!label) {
                        // label seen first, normal target of forward jump, save addr & allocator
    					_labels.add(ins, _nIns, _allocator);
                    }
                    else {
                        // we're at the top of a loop
                        hasLoop = true;
                        NanoAssert(label->addr == 0 && label->regs.isValid());
                        //evictRegs(~_allocator.free);
                        intersectRegisterState(label->regs);
                        label->addr = _nIns;
                        verbose_only(
                            verbose_outputf("Loop label %s", _thisfrag->lirbuf->names->formatRef(ins));
                        )
                    }
					break;
				}

                case LIR_xt:
				case LIR_xf:
				{
					// we only support cmp with guard right now, also assume it is 'close' and only emit the branch
                    NIns* exit = asm_exit(ins); // does intersectRegisterState()
					LIns* cond = ins->oprnd1();
					asm_branch(op == LIR_xf, cond, exit);
					break;
				}
				case LIR_x:
				{
		            verbose_only(verbose_output(""));
					// generate the side exit branch on the main trace.
                    NIns *exit = asm_exit(ins);
					JMP( exit ); 
					break;
				}
				case LIR_loop:
				{
					JMP_long_placeholder(); // jump to SOT	
					verbose_only( if (_verbose && _outputCache) { _outputCache->removeLast(); outputf("         jmp   SOT"); } );
					
					loopJumps.add(_nIns);

                    #ifdef NJ_VERBOSE
                    // branching from this frag to ourself.
                    if (_frago->core()->config.show_stats)
					#if defined NANOJIT_AMD64
                        LDQi(argRegs[1], intptr_t((Fragment*)_thisfrag));
					#else
                        LDi(argRegs[1], int((Fragment*)_thisfrag));
                    #endif
                    #endif

					// restore first parameter, the only one we use
                    LInsp state = _thisfrag->lirbuf->state;
                    Register a0 = Register(state->imm8());
					findSpecificRegFor(state, a0); 
					break;
				}
#ifndef NJ_SOFTFLOAT
				case LIR_feq:
				case LIR_fle:
				case LIR_flt:
				case LIR_fgt:
				case LIR_fge:
				{
					// only want certain regs 
					Register r = prepResultReg(ins, AllowableFlagRegs);
					// SETcc only sets low 8 bits, so extend 
					MOVZX8(r,r);
					SETNP(r);
					asm_fcmp(ins);
					break;
				}
#endif
				case LIR_eq:
                case LIR_ov:
                case LIR_cs:
				case LIR_le:
				case LIR_lt:
				case LIR_gt:
				case LIR_ge:
				case LIR_ult:
				case LIR_ule:
				case LIR_ugt:
				case LIR_uge:
				{
					// only want certain regs 
					Register r = prepResultReg(ins, AllowableFlagRegs);
					// SETcc only sets low 8 bits, so extend 
					MOVZX8(r,r);
					if (op == LIR_eq)
						SETE(r);
                    else if (op == LIR_ov)
                        SETO(r);
                    else if (op == LIR_cs)
                        SETC(r);
					else if (op == LIR_lt)
						SETL(r);
					else if (op == LIR_le)
						SETLE(r);
					else if (op == LIR_gt)
						SETG(r);
					else if (op == LIR_ge)
						SETGE(r);
					else if (op == LIR_ult)
						SETB(r);
					else if (op == LIR_ule)
						SETBE(r);
					else if (op == LIR_ugt)
						SETA(r);
					else // if (op == LIR_uge)
						SETAE(r);
					asm_cmp(ins);
					break;
				}

#ifndef NJ_SOFTFLOAT
				case LIR_fcall:
				case LIR_fcalli:
#endif
				case LIR_call:
				case LIR_calli:
				{
                    Register rr = UnknownReg;
#ifndef NJ_SOFTFLOAT
                    if ((op&LIR64))
                    {
                        // fcall or fcalli
						Reservation* rR = getresv(ins);
						rr = asm_prep_fcall(rR, ins);
                    }
                    else
#endif
                    {
                        rr = retRegs[0];
						prepResultReg(ins, rmask(rr));
                    }

					// do this after we've handled the call result, so we dont
					// force the call result to be spilled unnecessarily.
					evictRegs(~SavedRegs);

					asm_call(ins);
				}
			}

			// check that all is well (don't check in exit paths since its more complicated)
			debug_only( pageValidate(); )
			debug_only( resourceConsistencyCheck();  )
		}
	}

	NIns* Assembler::asm_branch(bool branchOnFalse, LInsp cond, NIns* targ)
	{
		NIns* at = 0;
		LOpcode condop = cond->opcode();
		NanoAssert(cond->isCond());
#ifndef NJ_SOFTFLOAT
		if (condop >= LIR_feq && condop <= LIR_fge)
		{
			if (branchOnFalse)
				JP(targ);
			else
				JNP(targ);
			at = _nIns;
			asm_fcmp(cond);
			return at;
		}
#endif
		// produce the branch
		if (branchOnFalse)
		{
			if (condop == LIR_eq)
				JNE(targ);
			else if (condop == LIR_ov)
				JNO(targ);
			else if (condop == LIR_cs)
				JNC(targ);
			else if (condop == LIR_lt)
				JNL(targ);
			else if (condop == LIR_le)
				JNLE(targ);
			else if (condop == LIR_gt)
				JNG(targ);
			else if (condop == LIR_ge)
				JNGE(targ);
			else if (condop == LIR_ult)
				JNB(targ);
			else if (condop == LIR_ule)
				JNBE(targ);
			else if (condop == LIR_ugt)
				JNA(targ);
			else //if (condop == LIR_uge)
				JNAE(targ);
		}
		else // op == LIR_xt
		{
			if (condop == LIR_eq)
				JE(targ);
			else if (condop == LIR_ov)
				JO(targ);
			else if (condop == LIR_cs)
				JC(targ);
			else if (condop == LIR_lt)
				JL(targ);
			else if (condop == LIR_le)
				JLE(targ);
			else if (condop == LIR_gt)
				JG(targ);
			else if (condop == LIR_ge)
				JGE(targ);
			else if (condop == LIR_ult)
				JB(targ);
			else if (condop == LIR_ule)
				JBE(targ);
			else if (condop == LIR_ugt)
				JA(targ);
			else //if (condop == LIR_uge)
				JAE(targ);
		}
		at = _nIns;
		asm_cmp(cond);
		return at;
	}

    void Assembler::asm_arg(ArgSize sz, LInsp p, Register r)
    {
        if (sz == ARGSIZE_Q) 
        {
			// ref arg - use lea
			if (r != UnknownReg)
			{
				// arg in specific reg
				int da = findMemFor(p);
				LEA(r, da, FP);
			}
			else
			{
				NanoAssert(0); // not supported
			}
		}
        else if (sz == ARGSIZE_LO)
		{
			if (r != UnknownReg)
			{
				// arg goes in specific register
				if (p->isconst())
					LDi(r, p->constval());
				else
					findSpecificRegFor(p, r);
			}
			else
			{
				asm_pusharg(p);
			}
		}
        else
		{
            NanoAssert(sz == ARGSIZE_F);
			asm_farg(p);
		}
    }

	void Assembler::arFree(uint32_t idx)
	{
        AR &ar = _activation;
        LIns *i = ar.entry[idx];
        NanoAssert(i != 0);
        do {
            ar.entry[idx] = 0;
            idx--;
        } while (ar.entry[idx] == i);
	}

#ifdef NJ_VERBOSE
	void Assembler::printActivationState()
	{
		bool verbose_activation = false;
		if (!verbose_activation)
			return;
			
#ifdef NANOJIT_ARM
		verbose_only(
			if (_verbose) {
				char* s = &outline[0];
				memset(s, ' ', 51);  s[51] = '\0';
				s += strlen(s);
				sprintf(s, " SP ");
				s += strlen(s);
				for(uint32_t i=_activation.lowwatermark; i<_activation.tos;i++) {
					LInsp ins = _activation.entry[i];
					if (ins && ins !=_activation.entry[i+1]) {
						sprintf(s, "%d(%s) ", 4*i, _thisfrag->lirbuf->names->formatRef(ins));
						s += strlen(s);
					}
				}
				output(&outline[0]);
			}
		)
#else
		verbose_only(
			char* s = &outline[0];
			if (_verbose) {
				memset(s, ' ', 51);  s[51] = '\0';
				s += strlen(s);
				sprintf(s, " ebp ");
				s += strlen(s);

				for(uint32_t i=_activation.lowwatermark; i<_activation.tos;i++) {
					LInsp ins = _activation.entry[i];
					if (ins /* && _activation.entry[i]!=_activation.entry[i+1]*/) {
						sprintf(s, "%d(%s) ", -4*i,_thisfrag->lirbuf->names->formatRef(ins));
						s += strlen(s);
					}
				}
				output(&outline[0]);
			}
		)
#endif
	}
#endif

    bool canfit(int32_t size, int32_t loc, AR &ar) {
        for (int i=0; i < size; i++) {
            if (ar.entry[loc+stack_direction(i)])
                return false;
        }
        return true;
    }
	
	uint32_t Assembler::arReserve(LIns* l)
	{
		NanoAssert(!l->isTramp());

		//verbose_only(printActivationState());
        int32_t size = l->isop(LIR_alloc) ? (l->size()>>2) : l->isQuad() ? 2 : sizeof(intptr_t)>>2;
        AR &ar = _activation;
		const int32_t tos = ar.tos;
		int32_t start = ar.lowwatermark;
		int32_t i = 0;
		NanoAssert(start>0);
		if (tos+size >= NJ_MAX_STACK_ENTRY)
		{	
			setError(StackFull);
			return start;
		}

        if (size == 1) {
            // easy most common case -- find a hole, or make the frame bigger
            for (i=start; i < NJ_MAX_STACK_ENTRY; i++) {
                if (ar.entry[i] == 0) {
                    // found a hole
                    ar.entry[i] = l;
                    return i;
                }
            }
            ar.tos++;
            ar.highwatermark++;
            return i;
        }
        else if (size == 2) {
			if ( (start&1)==1 ) start++;  // even 8 boundary
			for (i=start; i < NJ_MAX_STACK_ENTRY; i+=2) {
				if ( (ar.entry[i+stack_direction(1)] == 0) && (i==tos || (ar.entry[i] == 0)) )
					break;   //  for fp we need 2 adjacent aligned slots
			}
            NanoAssert(_activation.entry[i] == 0);
            NanoAssert(_activation.entry[i+stack_direction(1)] == 0);
            ar.entry[i] = l;
            ar.entry[i+stack_direction(1)] = l;
		}
        else {
            // alloc larger block on 8byte boundary.
            if (start < size) start = size;
            if ((start&1)==1) start++;
            for (i=start; i < NJ_MAX_STACK_ENTRY; i+=2) {
                if (canfit(size, i, ar))
                    break;
            }
		    // place the entry in the table and mark the instruction with it
            for (int32_t j=0; j < size; j++) {
                NanoAssert(_activation.entry[i+stack_direction(j)] == 0);
                _activation.entry[i+stack_direction(j)] = l;
            }
		}
        if (i >= (int32_t)ar.tos) {
            ar.tos = ar.highwatermark = i+1;
        }
        return i;
	}

	void Assembler::evictRegs(RegisterMask regs)
	{
		// generate code to restore callee saved registers 
		// @todo speed this up
		for (Register r = FirstReg; r <= LastReg; r = nextreg(r))
		{
			if ((rmask(r) & regs) && _allocator.getActive(r))
            {
				evict(r);
            }
		}
	}
	
	/**
	 * Merge the current state of the registers with a previously stored version
     * current == saved    skip
     * current & saved     evict current, keep saved
     * current & !saved    evict current  (unionRegisterState would keep)
     * !current & saved    keep saved
	 */
	void Assembler::intersectRegisterState(RegAlloc& saved)
	{
		// evictions and pops first
		RegisterMask skip = 0;
		for (Register r=FirstReg; r <= LastReg; r = nextreg(r))
		{
			LIns * curins = _allocator.getActive(r);
			LIns * savedins = saved.getActive(r);
			if (curins == savedins)
			{
				verbose_only( if (curins) verbose_outputf("        skip %s", regNames[r]); )
				skip |= rmask(r);
			}
			else 
			{
				if (curins)
					evict(r);
				
    			#ifdef NANOJIT_IA32
				if (savedins && (rmask(r) & x87Regs))
					FSTP(r);
				#endif
			}
		}
        assignSaved(saved, skip);
	}

	/**
	 * Merge the current state of the registers with a previously stored version.
     * 
     * current == saved    skip
     * current & saved     evict current, keep saved
     * current & !saved    keep current (intersectRegisterState would evict)
     * !current & saved    keep saved
	 */
	void Assembler::unionRegisterState(RegAlloc& saved)
	{
		// evictions and pops first
		RegisterMask skip = 0;
		for (Register r=FirstReg; r <= LastReg; r = nextreg(r))
		{
			LIns * curins = _allocator.getActive(r);
			LIns * savedins = saved.getActive(r);
			if (curins == savedins)
			{
				verbose_only( if (curins) verbose_outputf("        skip %s", regNames[r]); )
				skip |= rmask(r);
			}
			else 
			{
				if (curins && savedins)
					evict(r);
				
    			#ifdef NANOJIT_IA32
				if (savedins && (rmask(r) & x87Regs))
					FSTP(r);
				#endif
			}
		}
        assignSaved(saved, skip);
    }

    void Assembler::assignSaved(RegAlloc &saved, RegisterMask skip)
    {
		// now reassign mainline registers
		for (Register r=FirstReg; r <= LastReg; r = nextreg(r))
		{
			LIns *i = saved.getActive(r);
			if (i && !(skip&rmask(r)))
				findSpecificRegFor(i, r);
		}
		debug_only(saved.used = 0);  // marker that we are no longer in exit path
	}
	
	/**																 
	 * Guard records are laid out in the exit block buffer (_nInsExit),
	 * intersperced with the code.   Preceding the record are the native
	 * instructions associated with the record (i.e. the exit code).
	 * 
	 * The layout is as follows:
	 * 
	 * [ native code ] [ GuardRecord1 ]
	 * ...
	 * [ native code ] [ GuardRecordN ]
	 * 
	 * The guard record 'code' field should be used to locate 
	 * the start of the native code associated with the
	 * exit block. N.B the code may lie in a different page 
	 * than the guard record  
	 * 
	 * The last guard record is used for the unconditional jump
	 * at the end of the trace. 
	 * 
	 * NOTE:  It is also not guaranteed that the native code 
	 *        is contained on a single page.
	 */
	GuardRecord* Assembler::placeGuardRecord(LInsp guard)
	{
		// we align the guards to 4Byte boundary
		size_t size = GuardRecordSize(guard);
		SideExit *exit = guard->exit();
		NIns* ptr = (NIns*)alignTo(_nIns-size, 4);
		underrunProtect( (intptr_t)_nIns-(intptr_t)ptr );  // either got us a new page or there is enough space for us
		GuardRecord* rec = (GuardRecord*) alignTo(_nIns-size,4);
		rec->outgoing = _latestGuard;
		_latestGuard = rec;
		_nIns = (NIns*)rec;
		rec->next = 0;
		rec->origTarget = 0;		
		rec->target = exit->target;
		rec->from = _thisfrag;
		initGuardRecord(guard,rec);
		if (exit->target) 
			exit->target->addLink(rec);
		return rec;
	}

	#ifdef NJ_VERBOSE
		char Assembler::outline[8192];

		void Assembler::outputf(const char* format, ...)
		{
			va_list args;
			va_start(args, format);
			outline[0] = '\0';
			vsprintf(outline, format, args);
			output(outline);
		}

		void Assembler::output(const char* s)
		{
			if (_outputCache)
			{
				char* str = (char*)_gc->Alloc(strlen(s)+1);
				strcpy(str, s);
				_outputCache->add(str);
			}
			else
			{
				_frago->core()->console << s << "\n";
			}
		}

		void Assembler::output_asm(const char* s)
		{
			if (!verbose_enabled())
				return;
			if (*s != '^')
				output(s);
		}

		char* Assembler::outputAlign(char *s, int col) 
		{
			int len = strlen(s);
			int add = ((col-len)>0) ? col-len : 1;
			memset(&s[len], ' ', add);
			s[col] = '\0';
			return &s[col];
		}
	#endif // verbose

	#endif /* FEATURE_NANOJIT */

#if defined(FEATURE_NANOJIT) || defined(NJ_VERBOSE)
	uint32_t CallInfo::_count_args(uint32_t mask) const
	{
		uint32_t argc = 0;
		uint32_t argt = _argtypes;
		for (uint32_t i = 0; i < MAXARGS; ++i) {
			argt >>= 2;
			argc += (argt & mask) != 0;
		}
		return argc;
	}

    uint32_t CallInfo::get_sizes(ArgSize* sizes) const
    {
		uint32_t argt = _argtypes;
		uint32_t argc = 0;
		for (uint32_t i = 0; i < MAXARGS; i++) {
			argt >>= 2;
			ArgSize a = ArgSize(argt&3);
#ifdef NJ_SOFTFLOAT
			if (a == ARGSIZE_F) {
                sizes[argc++] = ARGSIZE_LO;
                sizes[argc++] = ARGSIZE_LO;
                continue;
            }
#endif
            if (a != ARGSIZE_NONE) {
                sizes[argc++] = a;
            }
		}
        if (isIndirect()) {
            // add one more arg for indirect call address
            argc++;
        }
        return argc;
    }
#endif

    void LabelStateMap::add(LIns *label, NIns *addr, RegAlloc &regs) {
        LabelState *st = new (gc) LabelState(addr, regs);
        labels.put(label, st);
    }

    LabelState* LabelStateMap::get(LIns *label) {
        return labels.get(label);
    }
}
