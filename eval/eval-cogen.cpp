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
 * Portions created by the Initial Developer are Copyright (C) 2008
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

#include "avmplus.h"

#ifdef VMCFG_EVAL

#include "eval.h"

namespace avmplus
{
    namespace RTC
    {
        using namespace ActionBlockConstants;

        VarScopeCtx * Ctx::findVarScope()
        {
            Ctx* ctx = this;
            while (ctx->tag != CTX_Function && ctx->tag != CTX_ClassMethod && ctx->tag != CTX_Program)
                ctx = ctx->next;
            return (VarScopeCtx*)ctx;
        }
        
        const Cogen::BinopMapping Cogen::binopMapping[] = {
        {0, 0},                 // unused
        {0, OP_astypelate},     // OPR_as
        {0, OP_add},            // OPR_plus,
        {0, 0},                 // OPR_assign,
        {0, 0},                 // OPR_init,
        {0, 0},                 // OPR_comma,
        {0, OP_subtract},       // OPR_minus,
        {0, OP_multiply},       // OPR_multiply,
        {0, OP_divide},         // OPR_divide,
        {0, OP_modulo},         // OPR_remainder,
        {0, OP_lshift},         // OPR_leftShift,
        {0, OP_rshift},         // OPR_rightShift,
        {0, OP_urshift},        // OPR_rightShiftUnsigned,
        {0, OP_instanceof},     // OPR_instanceof
        {0, OP_in},             // OPR_in
        {0, OP_istypelate},     // OPR_is
        {0, OP_bitand},         // OPR_bitwiseAnd,
        {0, OP_bitor},          // OPR_bitwiseOr,
        {0, OP_bitxor},         // OPR_bitwiseXor,
        {0, 0},                 // OPR_logicalAnd,
        {0, 0},                 // OPR_logicalOr,
        {0, OP_lessthan},       // OPR_less,
        {0, OP_lessequals},     // OPR_lessOrEqual,
        {0, OP_greaterthan},    // OPR_greater,
        {0, OP_greaterequals},  // OPR_greaterOrEqual,
        {0, OP_equals},         // OPR_equal,
        {1, OP_equals},         // OPR_notEqual,
        {0, OP_strictequals},   // OPR_strictEqual,
        {1, OP_strictequals},   // OPR_strictNotEqual,
        {0, OP_coerce},         // OPR_to
        };

        Cogen::Cogen(Compiler *compiler, ABCFile* abc, ABCTraitsTable* traits, ABCMethodBodyInfo* body, uint32_t first_temp) 
            : compiler(compiler)
            , abc(abc)
            , allocator(compiler->allocator)
            , code(compiler->allocator)
            , labels(compiler->allocator)
            , traits(traits)
            , body(body)
            , last_linenum(0)
            , label_counter(0)
            , temp_counter(first_temp)
            , sets_dxns(false)
            , need_activation(false)
            , stack_depth(0)
            , max_stack_depth(0)
            , scope_depth(0)
        {
        }

        uint8_t* Cogen::serializeCodeBytes(uint8_t* b) const
        {
            code.serialize(b);
            fixupBackpatches(b);
            return b + code.size();
        }

        /* Stack height tracking is "simplest possible": we assume that even for
         * unconditional branches the stack height in the taken branch and in the
         * untaken (impossible) branch are the same; this means that anyone jumping
         * to a label following a jump must be careful to match the stack height.
         * This does not seem to be an issue in practice; the verifier keeps us
         * honest; and we don't need to track the expected stack height at every
         * label.  Also, we're not interested in the actual stack height everywhere,
         * just a conservative approximation to it.
         */
        void Cogen::stackMovement(AbcOpcode opcode)
        {
            stack_depth = stack_depth + opcodeInfo[opcode].stack;
            AvmAssert((int32_t)stack_depth >= 0);
            if (stack_depth > max_stack_depth)
                max_stack_depth = stack_depth;
        }

        void Cogen::stackMovement(AbcOpcode opcode, bool hasRTNS, bool hasRTName, uint32_t pops)
        {
            stack_depth = stack_depth + opcodeInfo[opcode].stack - hasRTNS - hasRTName - pops;
            AvmAssert((int32_t)stack_depth >= 0);
            if (stack_depth > max_stack_depth)
                max_stack_depth = stack_depth;
        }
        
        void Cogen::emitOp(AbcOpcode opcode)
        {
            code.emitU8((uint8_t)opcode);
            stackMovement(opcode);
        }
        
        void Cogen::emitOpU30(AbcOpcode opcode, uint32_t u30)
        {
            code.emitU8((uint8_t)opcode);
            code.emitU30(u30);
            stackMovement(opcode);
        }

        void Cogen::emitOpU30Special(AbcOpcode opcode, uint32_t u30, uint32_t pops)
        {
            code.emitU8((uint8_t)opcode);
            code.emitU30(u30);
            stackMovement(opcode, false, false, pops);
        }
        
        void Cogen::emitOpU30U30(AbcOpcode opcode, uint32_t u30_1, uint32_t u30_2)
        {
            code.emitU8((uint8_t)opcode);
            code.emitU30(u30_1);
            code.emitU30(u30_2);
            stackMovement(opcode);
        }
        
        void Cogen::emitOpU8(AbcOpcode opcode, uint8_t b)
        {
            code.emitU8((uint8_t)opcode);
            code.emitU8(b);
            stackMovement(opcode);
        }

        void Cogen::emitOpS8(AbcOpcode opcode, int8_t b)
        {
            code.emitU8((uint8_t)opcode);
            code.emitS8(b);
            stackMovement(opcode);
        }
        
        void Cogen::I_getlocal(uint32_t index) {
            if (index < 4)
                emitOp((AbcOpcode)(OP_getlocal0 + index));
            else
                emitOpU30(OP_getlocal, index);
        }

        void Cogen::I_setlocal(uint32_t index) {
            if (index < 4)
                emitOp((AbcOpcode)(OP_setlocal0 + index));
            else
                emitOpU30(OP_setlocal, index);
        }

        void Cogen::I_debugfile(uint32_t index)
        {
            if (compiler->debugging)
                emitOpU30(OP_debugfile, index);
        }
        
        void Cogen::I_debugline(uint32_t linenum)
        {
            if (compiler->debugging && linenum > last_linenum)
            {
                last_linenum = linenum;
                emitOpU30(OP_debugline, linenum);
            }
        }

        void Cogen::callMN(AbcOpcode opcode, uint32_t index, uint32_t nargs) {
            code.emitU8((uint8_t)opcode);
            code.emitU30(index);
            code.emitU30(nargs);
            stackMovement(opcode, abc->hasRTNS(index), abc->hasRTName(index), nargs);
        }
        
        void Cogen::propU30(AbcOpcode opcode, uint32_t index) 
        {
            code.emitU8((uint8_t)opcode);
            code.emitU30(index);
            stackMovement(opcode, abc->hasRTNS(index), abc->hasRTName(index), 0);
        }
        
        Label* Cogen::newLabel()
        {
            Label* l = ALLOC(Label, ());
            labels.addAtEnd(l);
            return l;
        }
        
        void Cogen::emitJump(AbcOpcode opcode, Label* label)
        {
            // OPTIMIZEME: don't need to register backpatches for branches to known labels.
            code.emitU8((uint8_t)opcode);
            code.emitS24(3);
            stackMovement(opcode);
            label->backpatches = ALLOC(Seq<uint32_t>, (code.size() - 3, label->backpatches));
        }
        
        void Cogen::I_label(Label* label)
        {
            AvmAssert(label->address == ~0U);
            label->address = code.size();
            code.emitU8((uint8_t)OP_label);
        }
        
        // The location to be patched must contain a signed adjustment that will be
        // added to the offset value.  For regular jump instructions this should be '3',
        // because the jump is relative to the end of the instruction - 3 bytes after
        // the address of the offset field.  For lookupswitch it is a value that depends
        // on the location within the lookupswitch instruction of the offset word,
        // because the jump is relative to the start of the instruction.
        
        void Cogen::fixupBackpatches(uint8_t* b) const
        {
            for ( Seq<Label*>* labels = this->labels.get() ; labels != NULL ; labels = labels->tl ) {
                uint32_t addr = labels->hd->address;
                bool backward = false;
                AvmAssert(addr != ~0U);
                for ( Seq<uint32_t>* backpatches = labels->hd->backpatches ; backpatches != NULL ; backpatches = backpatches->tl ) {
                    uint32_t loc = backpatches->hd;
                    int32_t adjustment = readS24(b + loc);
                    int32_t offset = (int32_t)(addr - (loc + adjustment));
                    backward = backward || offset < 0;
                    emitS24(b + loc, offset);
                }
                if (!backward) {
                    // Work around verifier bug: if a branch to this label is never a backward
                    // branch then replace OP_label with OP_nop.  The verifier always assumes
                    // that OP_label is the target of a backward branch.
                    b[addr] = OP_nop;
                }
            }
        }
        
        uint32_t Cogen::emitException(uint32_t from, uint32_t to, uint32_t target, uint32_t type, uint32_t name_index)
        {
            return body->exceptions.addAtEnd(ALLOC(ABCExceptionInfo, (from, to, target, type, name_index)));
        }
        
        uint32_t Cogen::emitTypeName(Compiler* compiler, QualifiedName* t)
        {
            ABCFile* abc = &compiler->abc; 
            if (t == NULL)
                return 0;
            uint32_t ns = compiler->NS_public;
            if (t->qualifier != NULL) {
                AvmAssert(t->qualifier->tag() == TAG_simpleName);
                ns = abc->addNamespace(CONSTANT_Namespace, abc->addString(((SimpleName*)t->qualifier)->name));
            }
            AvmAssert(t->name->tag() == TAG_simpleName);
            return abc->addQName(ns, abc->addString(((SimpleName*)t->name)->name));
        }
    
        void Cogen::I_lookupswitch(Label* default_label, Label** case_labels, uint32_t ncases) 
        {
            AvmAssert( ncases > 0 );
            AvmAssert( default_label != NULL );
            // AvmAssert( forall c in case_labels c != NULL );

            uint32_t here = code.size();
            code.emitU8((uint8_t)OP_lookupswitch);
            code.emitS24((int32_t)(here - code.size()));
            default_label->backpatches = ALLOC(Seq<uint32_t>, (code.size() - 3, default_label->backpatches));
            code.emitU30(ncases - 1);
            for ( uint32_t i=0 ; i < ncases ; i++ ) {
                Label* label = case_labels[i];
                code.emitS24((int32_t)(here - code.size()));
                label->backpatches = ALLOC(Seq<uint32_t>, (code.size() - 3, label->backpatches));
            }
            stackMovement(OP_lookupswitch);
        }

        void FunctionDefn::cogenGuts(Compiler* compiler, Ctx* ctx, ABCMethodInfo** info, ABCMethodBodyInfo** body)
        {
            Allocator* allocator = compiler->allocator;
            ABCFile* abc = &compiler->abc;
            ABCTraitsTable* traits;
            Str* name = this->name;
            if (name == NULL)
                name = compiler->SYM_anonymous;
            
            SeqBuilder<uint32_t> param_types(allocator);
            SeqBuilder<DefaultValue*> default_values(allocator);
            uint32_t numdefaults = 0;
            for ( Seq<FunctionParam*>* params = this->params ; params != NULL ; params = params->tl ) {
                param_types.addAtEnd(Cogen::emitTypeName(compiler, params->hd->type_name));
                if (params->hd->default_value != NULL) {
                    Expr* dv = params->hd->default_value;
                    uint32_t cv = 0;
                    uint32_t ct = 0;
                    switch (dv->tag()) {
                        case TAG_literalString:
                            ct = CONSTANT_Utf8;
                            cv = abc->addString(((LiteralString*)dv)->value);
                            break;
                        case TAG_literalUInt:
                            ct = CONSTANT_UInt;
                            cv = abc->addUInt(((LiteralUInt*)dv)->value);
                            break;
                        case TAG_literalInt:
                            ct = CONSTANT_Int;
                            cv = abc->addInt(((LiteralInt*)dv)->value);
                            break;
                        case TAG_literalDouble:
                        case TAG_literalBoolean:
                            ct = CONSTANT_Double;
                            cv = abc->addDouble(((LiteralDouble*)dv)->value);
                            if (((LiteralBoolean*)dv)->value)
                                ct = CONSTANT_True;
                            else
                                ct = CONSTANT_False;
                            break;
                        case TAG_literalNull:
                            ct = CONSTANT_Null;
                            break;
                        default:
                            // EXTENDME: we can sort-of support arbitrary default values here if we want to.
                            //
                            // AS3 does not support default value other than the six cases above.  Doing better
                            // would be nice.
                            //
                            // We can use one of the obscure namespace default values as a placeholder, then 
                            // generate code to test for that value and compute the correct default value.  
                            // But the signature of the function won't be right; the type of the argument 
                            // must be '*'.  May be close enough, as long as we assign a provided argument 
                            // value to a typed slot and get a type check on entry.
                            compiler->syntaxError(params->hd->default_value->pos, SYNTAXERR_IMPOSSIBLE_DEFAULT);
                    }
                    numdefaults++;
                    default_values.addAtEnd(ALLOC(DefaultValue, (ct, cv)));
                }
            }
            *info = ALLOC(ABCMethodInfo, (compiler, abc->addString(name), numparams, param_types.get(), numdefaults, default_values.get(), Cogen::emitTypeName(compiler, return_type_name)));
            traits = ALLOC(ABCTraitsTable, (compiler));
            *body = ALLOC(ABCMethodBodyInfo, (compiler, *info, traits, 1 + numparams + (uses_arguments || (rest_param != NULL))));

            cogen(&(*body)->cogen, ctx);
        
            uint32_t flags = 0;
            AvmAssert( !(uses_arguments && (rest_param != NULL)) );
            if (uses_arguments)
                flags |= abcMethod_NEED_ARGUMENTS;
            if (rest_param != NULL)
                flags |= abcMethod_NEED_REST;
            if (uses_dxns)
                flags |= abcMethod_SETS_DXNS;
            (*info)->setFlags((uint8_t)((*body)->getFlags() | flags));
        }

        void CodeBlock::cogen(Cogen* cogen, Ctx* ctx)
        {
            Compiler* compiler = cogen->compiler;
            ABCFile* abc = cogen->abc;
            uint32_t activation = 0;    // 0 means "unallocated"
            FunctionDefn* fn = NULL;
            
            if (tag == CODE_Function)
                fn = (FunctionDefn*)this;
                
            cogen->I_debugfile(cogen->emitString(compiler->str_filename));
            
            if (tag == CODE_Program) {
                cogen->I_getlocal(0);
                cogen->I_pushscope();
            }

            if (fn && (fn->bindings != NULL || fn->uses_arguments)) {
                activation = cogen->getTemp();
                cogen->I_newactivation();
                cogen->I_dup();
                cogen->I_setlocal(activation);
                cogen->I_pushscope();
            }
            
            for ( Seq<Binding*>* bindings = this->bindings ; bindings != NULL ; bindings = bindings->tl ) {
                Binding* b = bindings->hd;
                uint32_t id = abc->addQName(compiler->NS_public, cogen->emitString(b->name));
                uint32_t type_id = cogen->emitTypeName(compiler, b->type_name);
                switch (bindings->hd->kind) {
                    case TAG_namespaceBinding:  // FIXME: namespace bindings should be const, but the VM does not allow TAG_constBinding
                    case TAG_varBinding:
                        cogen->emitSlotTrait(id, type_id);
                        break;
                    case TAG_constBinding:
                        cogen->emitConstTrait(id, type_id);
                        break;
                    default:
                        compiler->internalError(0, "Unknown binding tag");
                }
            }

            for ( Seq<NamespaceDefn*>* namespaces = this->namespaces ; namespaces != NULL ; namespaces = namespaces->tl ) {
                uint32_t id = abc->addQName(compiler->NS_public, cogen->emitString(namespaces->hd->name));
                uint32_t ns = 0;
                Expr* value = namespaces->hd->value;
                if (value == NULL)
                    ns = abc->addNamespace(CONSTANT_Namespace, cogen->emitString(compiler->intern(compiler->namespace_counter++)));
                else if (value->tag() == TAG_literalString)
                    ns = abc->addNamespace(CONSTANT_ExplicitNamespace, cogen->emitString(((LiteralString*)value)->value));
                AvmAssert(activation != 0);
                cogen->I_getlocal(activation);
                if (ns != 0)
                    cogen->I_pushnamespace(ns);
                else {
                    // FIXME: semantic check for namespaces.
                    // Check that the name on the RHS is actually a ns
                    // Code is the same as for 'use default namespace'
                    // If we can't tell (name may be shadowed?) then 
                    // emit code that checks at run-time.  If we can tell,
                    // then don't emit code for looking it up at run-time
                    // here, but just reference the definition of the other
                    // binding?  (That's an optimization.)
                    //value->cogen(cogen);
                    compiler->internalError(0, "Namespace should have been resolved before code generation");
                }
                cogen->I_initproperty(id);
            }
            
            if (fn) {
                uint32_t i=1;
                Seq<FunctionParam*>* params=fn->params;
                for ( ; params != NULL ; params = params->tl, i++ ) {
                    uint32_t id = abc->addQName(compiler->NS_public, cogen->emitString(params->hd->name));
                    AvmAssert(activation != 0);
                    cogen->I_getlocal(activation);
                    cogen->I_getlocal(i);
                    cogen->I_setproperty(id);
                }
                if (fn->uses_arguments || fn->rest_param) {
                    AvmAssert(activation != 0);
                    cogen->I_getlocal(activation);
                    cogen->I_getlocal(i);
                    if (fn->uses_arguments)
                        cogen->I_setproperty(abc->addQName(compiler->NS_public, cogen->emitString(compiler->SYM_arguments)));
                    else
                        cogen->I_setproperty(abc->addQName(compiler->NS_public, cogen->emitString(fn->rest_param->name)));
                }
            }
            
            for ( Seq<FunctionDefn*>* functions = this->functions ; functions != NULL ; functions = functions->tl ) {
                FunctionDefn* func = functions->hd;
                ABCMethodInfo* fn_info;
                ABCMethodBodyInfo* fn_body;
                func->cogenGuts(compiler, ctx, &fn_info, &fn_body);
                uint32_t fname = abc->addQName(compiler->NS_public, cogen->emitString(func->name));
                cogen->I_getlocal(activation);
                cogen->I_newfunction(fn_info->index);
                cogen->I_setproperty(fname);
            }
            
            cogenBody(cogen, ctx, activation);
        }

        uint32_t Cogen::buildNssetWithPublic(Seq<Namespace*>* ns)
        {
            SeqBuilder<uint32_t> s(allocator);
            s.addAtEnd(compiler->NS_public);
            while (ns != NULL) {
                if (ns->hd->tag() != TAG_commonNamespace)
                    compiler->internalError(0, "Namespace should have been resolved before now.");
                CommonNamespace* cns = (CommonNamespace*)ns->hd;
                s.addAtEnd(abc->addNamespace(CONSTANT_Namespace, abc->addString(cns->name)));
                ns = ns->tl;
            }
            return abc->addNsset(s.get());
        }
    }
}

#endif // VMCFG_EVAL
