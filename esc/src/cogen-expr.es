/* -*- mode: java; tab-width: 4; insert-tabs-mode: nil; indent-tabs-mode: nil;  -*- */
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

/* FIXME: handling 'super'.
 *
 * super.m(...)
 *   calls the super class's "m" with "this" as the receiver:
 *   'callsuper' instruction
 *
 * super(...)
 *   calls the super class's constructor on the arguments:
 *   'constructsuper' instruction
 *   only legal in a constructor, the parser annotates the Ctor structure with the args,
 *   don't need to handle this as an expression
 *
 * super.x
 *   picks up the 'x' member from the super class:
 *   'getsuper' instruction
 *
 * super(o).m()
 *   calls the super class's "m" with "o" as the receiver (o must be of a reasonable type):
 *   'callsuper' instruction
 */

//package cogen
{
    //import util.*;
    //import abcfile.*;
    //import assembler.*;
    //import emitter.*;
    use default namespace Gen;

    use namespace Util;
    use namespace Abc;
    use namespace Asm;
    use namespace Emit;
    use namespace Ast;

    function cgExpr(ctx, e) {
        if( e.pos != null ) {
            cgDebugInfo(ctx, e.pos);
        }
        switch type (e) {
        case (e:TernaryExpr) { cgTernaryExpr(ctx, e) }
        case (e:BinaryExpr) { cgBinaryExpr(ctx, e) }
        case (e:BinaryTypeExpr) { cgBinaryTypeExpr(ctx, e) }
        case (e:UnaryExpr) { cgUnaryExpr(ctx, e) }
        case (e:TypeExpr) { cgTypeExpr(ctx, e) }
        case (e:ThisExpr) { cgThisExpr(ctx, e) }
        case (e:YieldExpr) { cgYieldExpr(ctx, e) }
        case (e:SuperExpr) { 
            Gen::syntaxError(ctx, "SuperExpr can't appear here");
        }
        case (e:LiteralExpr) { cgLiteralExpr(ctx, e) }
        case (e:CallExpr) { cgCallExpr(ctx, e) }
        case (e:ApplyTypeExpr) { cgApplyTypeExpr(ctx, e) }
        case (e:LetExpr) { cgLetExpr(ctx, e) }
        case (e:NewExpr) { cgNewExpr(ctx, e) }
        case (e:ObjectRef) { cgObjectRef(ctx, e) }
        case (e:LexicalRef) { cgLexicalRef(ctx, e) }
        case (e:SetExpr) { cgSetExpr(ctx, e) }
        case (e:ListExpr) { cgListExpr(ctx, e) }
        case (e:InitExpr) { cgInitExpr(ctx, e) }
        case (e:SliceExpr) { cgSliceExpr(ctx, e) }
        case (e:GetTemp) { cgGetTempExpr(ctx, e) }
        case (e:GetParam) { cgGetParamExpr(ctx, e) }
        case (e:EvalScopeInitExpr) { cgEvalScopeInitExpr(ctx,e) }
        case (e:*) { 
            Gen::internalError(ctx, "Unimplemented expression type " + e);
        }
        }
    }

    var lastline = -1;
    function cgDebugInfo(ctx, p) {
        //do debugging stuff
        if( p && emit_debug) {
            let asm = ctx.asm;
            if( p.line >= 0  && p.line != lastline) {
                asm.I_debugline(p.line);
                lastline = p.line;
            }
        }
    }
    
    function cgTernaryExpr(ctx, { e1: test, e2: consequent, e3: alternate }) {
        let asm = ctx.asm;
        cgExpr(ctx, test);
        let L0 = asm.I_iffalse(undefined);
        cgExpr(ctx, consequent);
        asm.I_coerce_a();
        let L1 = asm.I_jump(undefined);
        asm.I_label(L0);
        cgExpr(ctx, alternate);
        asm.I_coerce_a();
        asm.I_label(L1);
    }

    function cgBinaryExpr(ctx, e) {
        let asm = ctx.asm;
        if (e.op is LogicalAnd) {
            cgExpr(ctx, e.e1);
            asm.I_coerce_a();  // wrong, should coerce to LUB of lhs and rhs
            asm.I_dup();
            asm.I_convert_b();
            let L0 = asm.I_iffalse(undefined);
            asm.I_pop();
            cgExpr(ctx, e.e2);
            asm.I_coerce_a();  // wrong, should coerce to LUB of lhs and rhs
            asm.I_label(L0);
        }
        else if (e.op is LogicalOr) {
            cgExpr(ctx, e.e1);
            asm.I_coerce_a();  // wrong, should coerce to LUB of lhs and rhs
            asm.I_dup();
            asm.I_convert_b();
            let L0 = asm.I_iftrue(undefined);
            asm.I_pop();
            cgExpr(ctx, e.e2);
            asm.I_coerce_a();  // wrong, should coerce to LUB of lhs and rhs
            asm.I_label(L0);
        }
        else {
            cgExpr(ctx, e.e1);
            cgExpr(ctx, e.e2);
            switch type (e.op) {
            case (e:Plus) { asm.I_add() }
            case (e:Minus) { asm.I_subtract() }
            case (e:Times) { asm.I_multiply() }
            case (e:Divide) { asm.I_divide() }
            case (e:Remainder) { asm.I_modulo() }
            case (e:LeftShift) { asm.I_lshift() }
            case (e:RightShift) { asm.I_rshift() }
            case (e:RightShiftUnsigned) { asm.I_urshift() }
            case (e:BitwiseAnd) { asm.I_bitand() }
            case (e:BitwiseOr) { asm.I_bitor() }
            case (e:BitwiseXor) { asm.I_bitxor() }
            case (e:InstanceOf) { asm.I_instanceof() }
            case (e:In) { asm.I_in() }
            case (e:Equal) { asm.I_equals() }
            case (e:NotEqual) { asm.I_equals(); asm.I_not() }
            case (e:StrictEqual) { asm.I_strictequals() }
            case (e:StrictNotEqual) { asm.I_strictequals(); asm.I_not() }
            case (e:Less) { asm.I_lessthan() }
            case (e:LessOrEqual) { asm.I_lessequals() }
            case (e:Greater) { asm.I_greaterthan() }
            case (e:GreaterOrEqual) { asm.I_greaterequals() }
            case (e:*) { 
                Gen::internalError(ctx, "Unimplemented binary operator " + e);
            }
            }
        }
    }

    var id_TypeError = new Ast::Identifier("TypeError",[[Ast::noNS]]);

    function cgBinaryTypeExpr(ctx, e) {
        let asm = ctx.asm;
        switch type (e.op) {
        case (op:CastOp) {
            // ES4 'cast'.
            //
            // OPTIMIZEME.  This would benefit from an "OP_coercelate"
            // opcode for brevity and less control flow but the code
            // below should be correct as far as the language and
            // verifier are concerned.
            //
            // OPTIMIZEME.  Early-bind the right hand side if possible
            // and use simpler code here (probably just a single
            // OP_coerce instruction if that does not invoke any user
            // defined converters).
            cgExpr(ctx, e.e1);
            asm.I_dup();
            cgTypeExprHelper(ctx, e.e2);
            asm.I_istypelate();
            let L0 = asm.I_iftrue(undefined);
            asm.I_pop();
            // FIXME: should lookup directly in global obj or be unforgeable name.
            asm.I_findproperty(cgIdentExpr(ctx, id_TypeError));
            asm.I_pushstring(ctx.cp.stringUtf8("Cast failed."));
            asm.I_constructprop(cgIdentExpr(ctx, id_TypeError), 1);
            asm.I_throw();
            asm.I_label(L0);
            asm.I_coerce_a();
        }
        case (op:IsOp) { 
            // ES4 'is'.
            //
            // OPTIMIZEME.  Early-bind the right hand side if possible
            // and use simpler code here (probably just a single
            // OP_istype instruction).
            cgExpr(ctx, e.e1);
            cgTypeExprHelper(ctx, e.e2);
            asm.I_istypelate();
        }
        case (op:*) { 
            Gen::internalError(ctx, "Unimplemented binary type operator " + op);
        }
        }
    }

    function cgTypeExpr(ctx, e) {
        cgTypeExprHelper(ctx, e.ex);
    }

    function cgTypeExprHelper(ctx, ty) {
        let {asm:asm, emitter:emitter} = ctx;
        switch type (ty) {
        case (ty:TypeName) {
            //let name = cgIdentExpr(ctx, ty.ident);
            asm.I_findpropstrict(cgIdentExpr(ctx, ty.ident));
            asm.I_getproperty(cgIdentExpr(ctx, ty.ident));
        }
        case (ty:*) {
            /* FIXME */
            Gen::internalError(ctx, "Unimplemented type expression type " + ty);
        }
        }
    }

    function cgUnaryExpr(ctx, e) {
        var {asm:asm, emitter:emitter} = ctx;

        switch type (e.op) {
        case (op:Delete) {
            switch type (e.e1) {
            case (lr:LexicalRef) {
                //let name = cgIdentExpr(ctx, lr.ident);
                asm.I_findproperty(cgIdentExpr(ctx, lr.ident));
                asm.I_deleteproperty(cgIdentExpr(ctx, lr.ident));
            }
            case (or:ObjectRef) {
                //let name = cgIdentExpr(ctx, or.ident);
                cgExpr(ctx, or.base);
                asm.I_deleteproperty(cgIdentExpr(ctx, or.ident));
            }
            case (e1:*) {
                cgExpr(ctx, e1);
                asm.I_pop();
                asm.I_pushtrue();
            }
            }
        }
        case (op:Void) {
            cgExpr(ctx, e.e1);
            asm.I_pop();
            asm.I_pushundefined();
        }
        case (op:Typeof) {
            if (e.e1 is LexicalRef) {
                asm.I_findproperty(cgIdentExpr(ctx, e.e1.ident));
                asm.I_getproperty(cgIdentExpr(ctx, e.e1.ident));
            }
            else 
                cgExpr(ctx, e.e1);
            asm.I_typeof();
        }
        case (op:PreIncr) { incdec(true, true) }
        case (op:PreDecr) { incdec(true, false) }
        case (op:PostIncr) { incdec(false, true) }
        case (op:PostDecr) { incdec(false, false) }
        case (op:UnaryPlus) {
            cgExpr(ctx, e.e1);
            asm.I_convert_d();
        }
        case (op:UnaryMinus) {
            cgExpr(ctx, e.e1);
            asm.I_negate();
        }
        case (op:BitwiseNot) {
            cgExpr(ctx, e.e1);
            asm.I_bitnot();
        }
        case (op:LogicalNot) {
            cgExpr(ctx, e.e1);
            asm.I_not();
        }
        case (op:*) {
            Gen::internalError(ctx, "Unimplemented unary operation " + op);
        }
        }

        function incdec(pre, inc) {
            switch type (e.e1) {
            case (lr:LexicalRef) {
                //name = cgIdentExpr(ctx, lr.ident);
                asm.I_findpropstrict(cgIdentExpr(ctx, lr.ident));
            }
            case (or:ObjectRef) {
                //name = cgIdentExpr(ctx, or.ident);
                cgExpr(ctx, or.base);
            }
            case (x:*) { 
                Gen::syntaxError(ctx, "Expression is not an lvalue");
            }
            }
            asm.I_dup();
            asm.I_getproperty(cgIdentExpr(ctx, e.e1.ident));
            let t = asm.getTemp();
            if (pre) {
                if (inc)
                    asm.I_increment();
                else
                    asm.I_decrement();
                asm.I_dup();
                asm.I_setlocal(t);
            }
            else {
                // Postfix ops return value after conversion to number.
                asm.I_convert_d();
                asm.I_dup();
                asm.I_setlocal(t);
                if (inc)
                    asm.I_increment();
                else
                    asm.I_decrement();
            }
            asm.I_setproperty(cgIdentExpr(ctx, e.e1.ident));
            asm.I_getlocal(t);
            asm.killTemp(t);
        }
    }

    function cgThisExpr(ctx, e) {
        ctx.asm.I_getlocal(0);
    }

    function cgYieldExpr(ctx, e) {
        // FIXME
        Gen::internalError(ctx, "Unimplemented 'yield' expression");
    }

    function cgCallExpr(ctx, e) {
        let {asm:asm, emitter:emitter} = ctx;
        let nargs = e.args.length;
        let evalTmp = 0;
        let isEval = false;

        switch type (e.expr) {
        case (or:ObjectRef) {
            cgExpr(ctx, or.base);
        }
        case (lr:LexicalRef) {
            asm.I_findpropstrict(cgIdentExpr(ctx, lr.ident));
            if (lr.ident is Identifier && lr.ident.ident === "eval") {
                isEval = true;
                evalTmp = asm.getTemp();   // save the
                asm.I_dup();               //   object
                asm.I_setlocal(evalTmp);   //     for later
            }
        }
        case (x:*) {
            cgExpr(ctx, e.expr);
            asm.I_pushnull();
        }
        }

        for ( let i=0 ; i < nargs ; i++ )
            cgExpr(ctx, e.args[i]);

        var L_skipcall;

        if (isEval) {
            // Code performs 'eval', cleans the stack, and jumps to L0
            // if the eval operator kicks in, otherwise falls through
            // to the regular call code below.
            L_skipcall = cgEvalPrefix(ctx, evalTmp, nargs);
        }

        switch type (e.expr) {
        case (or:ObjectRef) {
            asm.I_callproperty(cgIdentExpr(ctx, or.ident), nargs);
        }
        case (lr:LexicalRef) {
            // This is not right if the function is bound by "with".  In that
            // case, I_callproperty would be more right.  That's the outlier, though.
            asm.I_callproplex(cgIdentExpr(ctx, lr.ident), nargs);
        }
        case (x:*) {
            asm.I_call(nargs);
        }
        }

        if (isEval) {
            asm.I_label(L_skipcall);
            asm.killTemp(evalTmp);
        }
    }

    // First check that 'eval' really gets us the global eval binding.
    //
    // Assuming it really is the eval operator:
    //
    // Since the form of the call is eval(...) we know there are no
    // late-bound name components on the evaluation stack, just the
    // receiver object (which is the global object).  Clean up the
    // stack by consing up an array of all the arguments.
    //
    // Call ESC::eval() on the argument array, a descriptor of the
    // scopes (a string), and an array of scopes, outermost-first.
    // The descriptor and the scope array have the same length.  A
    // letter in the descriptor is "s" if the object is a regular
    // scope object (to be pushed by "pushscope") and "w" if it is is
    // a "with" object (to be pushed by "pushwith").
    //
    // ESC::evalCompiler() returns the result of the evaluation.

    function cgEvalPrefix(ctx, evalTmp, nargs) {
        var asm = ctx.asm;
        var nons = [[new Ast::ReservedNamespace(Ast::noNS)]];
        var id_ESC = new Ast::Identifier("ESC", nons); // Needs to be open namespaces??
        var id_evaluateInScopeArray = new Ast::QualifiedIdentifier(new Ast::LexicalRef(id_ESC), "evaluateInScopeArray");

        // Check it: Is this *really* the eval operator?

        var L_normalcall = undefined;

        /* FIXME: The following sanity tests only work when getglobalscope returns the object 
           that actually holds the global variables.  Bugzilla 417342.

        // The container must be === to the global object
        asm.I_getlocal(evalTmp);
        asm.I_getglobalscope();
        asm.I_ifstrictne(L_normalcall);

        // Property must be === to the predefined eval function, stored in the constant ESC::eval
        asm.I_getlocal(evalTmp);
        asm.I_getproperty(cgIdentExpr(ctx, lr.ident));
        asm.I_getglobalscope();
        asm.i_getproperty(cgIdentExpr(ctx, new Ast::QualifiedIdentifier(id_ESC,
                                                                        new Ast::Identifier("eval", [[Ast::NoNS]]))));
        asm.I_ifstrictne(L_normalcall);
        */

        asm.I_newarray(nargs);             // collapse the arguments
        asm.I_setlocal(evalTmp);           // save it...
        asm.I_pop();                       // get rid of the object
        asm.I_findpropstrict(cgIdentExpr(ctx, id_evaluateInScopeArray));
        asm.I_getlocal(evalTmp);           // argument array

        // pushScopes() generates code that leaves an array of scope
        // objects on the stack, followed by the scope descriptor
        // string.

        let numscopes = pushScopes(ctx);

        asm.I_callproplex(cgIdentExpr(ctx, id_evaluateInScopeArray), 3);

        L_skipcall = asm.I_jump(undefined);

        if (L_normalcall != undefined)
            asm.I_label(L_normalcall);

        return L_skipcall;

        function pushScopes(ctx) {

            let scopedesc = "";

            function rec(stk, inner) {
                let level;

                // Do not capture the global scope
                if (stk.tag == "script")
                    return 1;

                if (stk.tag == "function") {
                    level = rec(stk.link, false);
                    if (inner)
                        level = 0;
                }
                else
                    level = rec(stk.link, inner);

                // FIXME: There may be two scope objects per ctx rib,
                // because push_this may be true too.
                push = false;
                switch (stk.tag) {
                case "function":
                case "catch":
                    scopedesc = "s" + scopedesc;
                    push = true;
                    break;
                case "with":
                    scopedesc = "w" + scopedesc;
                    push = true;
                    break;
                case "class":
                case "instance":
                case "break":
                case "continue":
                case "finally":
                    break;
                case "let":
                default:
                    Gen::internalError(ctx, "Unknown context tag: " + stk.tag);
                }

                if (push) {
                    if (inner)
                        asm.I_getscopeobject(level);
                    else
                        asm.I_getouterscope(level);
                }
                return level + 1;
            }

            rec(ctx.stk, true);

            let numscopes = scopedesc.length;

            ctx.asm.I_newarray(numscopes);
            ctx.asm.I_pushstring(ctx.cp.stringUtf8(scopedesc));

            return numscopes;
        }
    }

    function cgEvalScopeInitExpr(ctx, e) {
        let asm = ctx.asm;
        asm.I_getlocal(1);
        asm.I_getproperty(cgIdentExpr(ctx, new Ast::Identifier(String(e.index), [[Ast::noNS]])));
        if (e.how == "w")
            asm.I_pushwith();
        else
            asm.I_pushscope();
        asm.I_pushundefined();
    }

    function cgApplyTypeExpr(ctx, e) {
        // FIXME
        Gen::internalError(ctx, "Unimplemented type application expression");
    }

    function cgLetExpr(ctx, e) {
        cgHead(ctx, e.head);
        cgExpr(ctx, e.expr);
    }

    function cgNewExpr(ctx, e) {
        cgExpr(ctx, e.expr);
        for ( let i=0 ; i < e.args.length ; i++ )
            cgExpr(ctx, e.args[i]);
        ctx.asm.I_construct(e.args.length);
    }

    function cgObjectRef(ctx, e) {
        cgExpr(ctx, e.base);
        ctx.asm.I_getproperty(cgIdentExpr(ctx, e.ident));
    }

    function cgLexicalRef(ctx, e) {
        let asm = ctx.asm;
        //let name = cgIdentExpr(ctx, e.ident);
        asm.I_findpropstrict(cgIdentExpr(ctx, e.ident));
        asm.I_getproperty(cgIdentExpr(ctx, e.ident));
    }

    function cgSetExpr(ctx, e) {
        let {asm:asm, emitter:emitter} = ctx;
        let name = null;

        // The switch leaves an object on the stack and sets "name"
        switch type (e.le) {
        case (lhs:ObjectRef) {
            cgExpr(ctx, lhs.base);
            name = lhs.ident;
        }
        case (lhs:LexicalRef) {
            //name = cgIdentExpr(ctx, lhs.ident);
            name = lhs.ident;
            if (e.op is Assign)
                asm.I_findproperty(cgIdentExpr(ctx, lhs.ident));
            else
                asm.I_findpropstrict(cgIdentExpr(ctx, lhs.ident));
        }
        case (lhs:*) { 
            Gen::syntaxError(ctx, "Illegal lvalue");
        }
        }

        if (e.op is AssignLogicalAnd) {
            asm.I_dup();
            asm.I_getproperty(cgIdentExpr(ctx, name));
            let L0 = asm.I_iffalse(undefined);
            asm.I_pop();
            cgExpr(ctx, e.re);
            asm.I_label(L0);
            asm.I_setproperty(cgIdentExpr(ctx, name));  // Always store it; the effect is observable
        }
        else if (e.op is AssignLogicalOr) {
            asm.I_dup();
            asm.I_getproperty(cgIdentExpr(ctx, name));
            let L0 = asm.I_iftrue(undefined);
            asm.I_pop();
            cgExpr(ctx, e.re);
            asm.I_label(L0);
            asm.I_setproperty(cgIdentExpr(ctx, name));  // Always store it; the effect is observable
        }
        else {
            let t = asm.getTemp();
            if (e.op is Assign) {
                let use_once_name = cgIdentExpr(ctx, name);
                cgExpr(ctx, e.re);
                asm.I_dup();
                asm.I_setlocal(t);
                asm.I_setproperty(use_once_name);
            }
            else {
                let propname = null;
                let subtmp = null;     // stores indexing expression value
                let subname = null;    // multiname to store under
                asm.I_dup();           // object expr
                if (name is ExpressionIdentifier) {
                    subtmp = asm.getTemp();
                    cgExpr(ctx, name.expr);
                    asm.I_dup();
                    asm.I_setlocal(subtmp);
                    subname = emitter.multinameL(name,false);
                    asm.I_getproperty(subname);
                }
                else {
                    asm.I_getproperty(cgIdentExpr(ctx, name));
                    propname = cgIdentExpr(ctx, name);
                }
                cgExpr(ctx, e.re);
                switch type (e.op) {
                case (op:AssignPlus) { asm.I_add() }
                case (op:AssignMinus) { asm.I_subtract() }
                case (op:AssignTimes) { asm.I_multiply() }
                case (op:AssignDivide) { asm.I_divide() }
                case (op:AssignRemainder) { asm.I_modulo() }
                case (op:AssignLeftShift) { asm.I_lshift() }
                case (op:AssignRightShift) { asm.I_rshift() }
                case (op:AssignRightShiftUnsigned) { asm.I_urshift() }
                case (op:AssignBitwiseAnd) { asm.I_bitand() }
                case (op:AssignBitwiseOr) { asm.I_bitor() }
                case (op:AssignBitwiseXor) { asm.I_bitxor() }
                case (op:*) { 
                    Gen::internalError(ctx, "ASSIGNOP not supported " + op);
                }
                }
                asm.I_dup();
                asm.I_setlocal(t);
                if (name is ExpressionIdentifier) {
                    asm.I_getlocal(subtmp);
                    asm.I_swap();
                    asm.I_setproperty(subname);
                    asm.killTemp(subtmp);
                }
                else
                    asm.I_setproperty(propname);
            }
            asm.I_getlocal(t);
            asm.killTemp(t);
        }
    }

    function cgListExpr(ctx, e) {
        let asm = ctx.asm;
        for ( let i=0, limit=e.exprs.length ; i < limit ; i++ ) {
            cgExpr(ctx, e.exprs[i]);
            if (i < limit-1)
                asm.I_pop();
        }
    }

    function cgInitExpr(ctx, e) {
        let asm = ctx.asm;
        let baseOnStk = false;
//        cgHead(ctx, e.head);
        switch type (e.target) {
        case (i:InstanceInit ) {
            // Load this on the stack
            asm.I_getlocal(0);
            baseOnStk = true;
        }
        }
        cgInits(ctx, e.inits, baseOnStk);
        asm.I_pushundefined(); // exprs need to leave something on the stack
        // FIXME: should this be the value of the last init?
    }

    function cgLiteralExpr(ctx, e) {

        function cgArrayInitializer(ctx, {exprs:exprs}) {
            let asm = ctx.asm;
            let i = 0;

            // Use newarray to construct the dense prefix
            for ( ; i < exprs.length ; i++ ) {
                let e = exprs[i];
                if (e is Ast::LiteralExpr && e.literal is Ast::LiteralUndefined)
                    break;
                cgExpr(ctx, e);
            }
            asm.I_newarray(i);

            // Then init the other defined slots one by one
            if (i < exprs.length) {
                let last_was_undefined = false;
                for ( ; i < exprs.length ; i++ ) {
                    let e = exprs[i];
                    if (!(e is Ast::LiteralExpr && e.literal is Ast::LiteralUndefined)) {
                        asm.I_dup();
                        cgExpr(ctx, e);
                        asm.I_setproperty(cgIdentExpr(ctx, new Ast::Identifier(String(i), [[Ast::noNS]])));
                        last_was_undefined = false;
                    }
                    else
                        last_was_undefined = true;
                }
                if (last_was_undefined) {
                    asm.I_dup();
                    asm.I_pushint(ctx.cp.int32(exprs.length));
                    asm.I_setproperty(cgIdentExpr(ctx, new Ast::Identifier("length", [[Ast::noNS]])));
                }
            }
        }

        function cgObjectInitializer(ctx, {fields:fields}) {
            let {asm:asm, emitter:emitter} = ctx;
            asm.I_findpropstrict(ctx.emitter.Object_name);
            asm.I_constructprop(ctx.emitter.Object_name, 0);
            let t = asm.getTemp();
            asm.I_setlocal(t);
            for ( let i=0 ; i < fields.length ; i++ ) {
                //cgLiteralField(fields[i]);
                let f = fields[i];
                asm.I_getlocal(t);
                cgExpr(ctx, f.expr);
                asm.I_setproperty(cgIdentExpr(ctx, f.ident));
            }
            //asm.I_newobject(fields.length);
            asm.I_getlocal(t);
            asm.killTemp(t);
        }

        function cgRegExpLiteral({asm:asm, cp:cp}, {src:src}) {
            // src is "/.../flags"
            //
            // Note, ES4 semantics: recreate RE object every time.
            // FIXME: re-compiles the RE every time.
            let p = src.lastIndexOf('/');
            // FIXME: We don't want findpropstrict because it can be used to spoof RegExp.
            // But getglobalscope produces an object that does not have "RegExp" bound.
            asm.I_findpropstrict(ctx.emitter.RegExp_name);
            asm.I_pushstring(cp.stringUtf8(src.substring(1,p)));
            asm.I_pushstring(cp.stringUtf8(src.substring(p+1)));
            asm.I_constructprop(ctx.emitter.RegExp_name, 2);
        }

        let {asm:asm, emitter:emitter} = ctx;
        switch type (e.literal) {
        case (e:LiteralNull) { asm.I_pushnull() }
        case (e:LiteralUndefined) { asm.I_pushundefined() }
        case (e:LiteralInt) { 
            let val = e.intValue;
            if (val >= -128 && val < 128)
                asm.I_pushbyte(val & 0xFF);  // pushbyte sign-extends
            else
                asm.I_pushint(ctx.cp.int32(val));
        }
        case (e:LiteralUInt) { 
            asm.I_pushuint(ctx.cp.uint32(e.uintValue));
        }
        case (e:LiteralDouble) { 
            let val = e.doubleValue;
            if (isNaN(val))
                asm.I_pushnan();
            else
                asm.I_pushdouble(ctx.cp.float64(val));
        }
        case (e:LiteralDecimal) { 
            // FIXME: proper decimal support when the AVM can handle it!
            asm.I_pushdouble(ctx.cp.float64(parseFloat(e.decimalValue)));
        }
        case (e:LiteralString) {
            asm.I_pushstring(ctx.cp.stringUtf8(e.strValue));
        }
        case (e:LiteralBoolean) {
            if (e.booleanValue)
                asm.I_pushtrue();
            else
                asm.I_pushfalse();
        }
        case (e:LiteralFunction) { 
            if (e.func.name != null) {
                // FIXME: correct for ES3 but not for ES4
                let t = asm.getTemp();
                asm.I_newobject(0);
                asm.I_dup();
                asm.I_setlocal(t);
                asm.I_pushwith();
                asm.I_newfunction(cgFunc(ctx, e.func));
                asm.I_dup();
                asm.I_getlocal(t);
                asm.I_swap();
                asm.I_setproperty(emitter.nameFromIdent(e.func.name.ident));
                asm.killTemp(t);
            }
            else
                asm.I_newfunction(cgFunc(ctx, e.func));
        }
        case (e:LiteralArray) { cgArrayInitializer(ctx, e) }
        case (e:LiteralObject) { cgObjectInitializer(ctx, e) }
        case (e:LiteralRegExp) { cgRegExpLiteral(ctx, e) }
            // case (e:LiteralNamespace) { cgNamespaceLiteral(ctx, e) }
        case (e:*) { 
            Gen::internalError(ctx, "Unimplemented LiteralExpr " + e);
        }
        }
    }

    function cgSliceExpr(ctx, e) {
        // FIXME
        Gen::internalError(ctx, "Unimplemented slice expression");
    }

    function cgGetTempExpr(ctx, e) {
        // FIXME
        let{asm:asm, emitter:emitter} = ctx;
        var qn = emitter.qname ({ns:Ast::noNS,id:"$t"+e.n},false);
        asm.I_findpropstrict(qn);
        asm.I_getproperty(qn);
    }

    function cgGetParamExpr(ctx, e) {
        let asm = ctx.asm;
        asm.I_getlocal(e.n + 1);  //account for 'this'
    }
    
    function cgIdentExpr(ctx, e) {
        let{asm:asm, emitter:emitter} = ctx;
        switch type(e) {
            case (id:Identifier) {
                return emitter.multiname(id,false);
            }
            case (ei:ExpressionIdentifier) {
                cgExpr(ctx, ei.expr);
                return emitter.multinameL(ei,false);
            }
            case (qi:QualifiedIdentifier) {
                switch type(qi.qual) {
                    case( lr:LexicalRef ) {
                        // Hack to deal with namespaces for now...
                        // later we will have to implement a namespace lookup to resolve qualified typenames
                        return emitter.qname({ns:new PublicNamespace(lr.ident.ident), id:qi.ident},false)
                    }
                    case( e:* ) {
                        /// cgExpr(ctx, qi.qual);
                        /// return emitter.rtqname(qi);
                        Gen::internalError(ctx, "Unsupported form of qualified identifier " + qi.ident);
                    }
                }
            }
            case (x:*) { 
                Gen::internalError(ctx, "Unimplemented cgIdentExpr " + e);
            }
        }
    }
}
