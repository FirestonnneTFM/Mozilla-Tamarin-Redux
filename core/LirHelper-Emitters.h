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
 *   leon.sha@sun.com
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

#ifdef __avmplus_LirHelper__ // should be included in LIrHelper.h!
#ifdef TODO
#define TODO_backup TODO
#undef TODO
#endif

    class LIREmitter{
    public:
        LIREmitter(LirHelper* lh):_lh(lh) {}// do nothing;
        virtual ~LIREmitter() {}

        virtual LIns* operator()(enum BuiltinType, LIns*,LIns* ) const  { return TODO("operator()(enum,LIns,LIns) NOT IMPLEMENTED"); }
        virtual LIns* operator()(enum BuiltinType, LIns* ) const        { return TODO("operator()(enum,LIns) NOT IMPLEMENTED");      }
        LIns* TODO(const char* msg) const                               { AvmAssertMsg(false,msg); (void)msg;return _lh->InsConstAtom(AtomConstants::undefinedAtom); }
    protected:
          LirHelper* _lh; // used only to give access to all 
    };

    // BasicLIREmitter can emit a generic unary or binary operation
    class BasicLIREmitter:public LIREmitter{
    public:
        BasicLIREmitter(LirHelper* lh, LOpcode op, const CallInfo* call) : LIREmitter(lh),_dblOp(op), _call(call) {}
        virtual LIns* operator()(enum BuiltinType bt, LIns* oper1,LIns* oper2) const;
        virtual LIns* operator()(enum BuiltinType bt,LIns* oper) const ;
    protected:
        LOpcode _dblOp;
        const CallInfo* _call;
    };

    class  ModuloLIREmitter : public LIREmitter {
    public:
        ModuloLIREmitter(LirHelper* lh):LIREmitter(lh) {}
        virtual LIns* operator()(enum BuiltinType bt, LIns* op1,LIns* op2) const;
        virtual LIns* operator()(enum BuiltinType, LIns*) const { return TODO("ModuloEmitter must have two operands"); }
    };

    class IncrementLIREmitter : public LIREmitter 
    {
    public:
        IncrementLIREmitter (LirHelper* lh, bool shouldDecrement=false):LIREmitter(lh),_shouldDecrement(shouldDecrement) {}
        virtual LIns* operator()(enum BuiltinType, LIns* ,LIns* ) const { return TODO("IncrementLIREmitter can't handle two operands"); }
        virtual LIns* operator()(enum BuiltinType bt,LIns* oper) const ;
    protected:
        bool _shouldDecrement;
    };

#ifdef TODO_backup
#define TODO TODO_backup
#undef TODO
#endif
#endif
