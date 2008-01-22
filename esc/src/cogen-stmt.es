/* -*- mode: java; tab-width: 4; insert-tabs-mode: nil; indent-tabs-mode: nil -*- */
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

//package cogen
{
    //import util.*;
    //import abcfile.*;
    //import assembler.*;
    use default namespace public;

    use default namespace Gen;
    use namespace Util;
    use namespace Abc;
    use namespace Asm;
    use namespace Emit;
    use namespace Ast;

    function cgStmt(ctx, s) {
        switch type (s) {
        case (s:EmptyStmt) { }
        case (s:ExprStmt) { cgExprStmt(ctx, s) }
        case (s:ClassBlock) { cgClassBlock(ctx, s) }
        case (s:ForInStmt) { cgForInStmt(ctx, s) }
        case (s:ThrowStmt) { cgThrowStmt(ctx, s) }
        case (s:ReturnStmt) { cgReturnStmt(ctx, s) }
        case (s:BreakStmt) { cgBreakStmt(ctx,s) }
        case (s:ContinueStmt) { cgContinueStmt(ctx,s) }
        case (s:BlockStmt) { cgBlockStmt(ctx,s) }
        case (s:LabeledStmt) { cgLabeledStmt(ctx,s) }
        case (s:LetStmt) { cgLetStmt(ctx,s) }
        case (s:WhileStmt) { cgWhileStmt(ctx, s) }
        case (s:DoWhileStmt) { cgDoWhileStmt(ctx, s) }
        case (s:ForStmt) { cgForStmt(ctx, s) }
        case (s:IfStmt) { cgIfStmt(ctx, s) }
        case (s:WithStmt) { cgWithStmt(ctx, s) }
        case (s:TryStmt) { cgTryStmt(ctx, s) }
        case (s:SwitchStmt) { cgSwitchStmt(ctx, s) }
        case (s:SwitchTypeStmt) { cgSwitchTypeStmt(ctx, s) }
        case (s:DXNStmt) { cgDxnStmt(ctx, s) }
        }
    }

    function cgExprStmt(ctx, s) {
        cgExpr(ctx, s.expr);
        ctx.asm.I_pop();  // FIXME the last expr stmt of the program must save its value
    }

    function cgClassBlock(ctx, s) {
        cgBlock(ctx, s.block);
    }

    function cgBlockStmt(ctx, s) {
        cgBlock(ctx, s.block);
    }

    function cgLabeledStmt(ctx, {label: label, stmt: stmt}) {
        let asm = ctx.asm;
        let L0 = asm.newLabel();
        cgStmt(pushLabel(ctx, label, L0), stmt);
        asm.I_label(L0);
    }

    function cgIfStmt(ctx, s) {
        var {expr:test, then:consequent, elseOpt:alternate} = s;
        let asm = ctx.asm;
        cgExpr(ctx, test);
        let L0 = asm.I_iffalse(undefined);
        cgStmt(ctx, consequent);
        if (alternate != null) {
            let L1 = asm.I_jump(undefined);
            asm.I_label(L0);
            cgStmt(ctx, alternate);
            asm.I_label(L1);
        }
        else
            asm.I_label(L0);
    }

    // Probable AST bug: should be no fixtures here, you can't define
    // vars in the WHILE head.
    function cgWhileStmt(ctx, s) {
        var {stmt: stmt, labels: labels, expr: expr} = s;
        let asm    = ctx.asm;
        let Lbreak = asm.newLabel();
        let Lcont  = asm.I_jump(undefined);
        let Ltop   = asm.I_label(undefined);
        cgStmt(pushBreak(pushContinue(ctx, labels, Lcont), Lbreak), stmt);
        asm.I_label(Lcont);
        cgExpr(ctx, expr);
        asm.I_iftrue(Ltop);
        asm.I_label(Lbreak);
    }

    // Probable AST bug: should be no fixtures here, you can't define
    // vars in the DO-WHILE head.
    function cgDoWhileStmt(ctx, s) {
        var {stmt: stmt, labels: labels, expr: expr} = s;
        let asm    = ctx.asm;
        let Lbreak = asm.newLabel();
        let Lcont  = asm.newLabel();
        let Ltop   = asm.I_label(undefined);
        cgStmt(pushBreak(pushContinue(ctx, labels, Lcont), Lbreak), stmt);
        asm.I_label(Lcont);
        cgExpr(ctx, expr);
        asm.I_iftrue(Ltop);
        asm.I_label(Lbreak);
    }

    function cgForStmt(ctx, s) {
        var {vars:vars,init:init,cond:cond,incr:incr,stmt:stmt,labels:labels} = s;
        // FIXME: fixtures
        // FIXME: code shape?
        let asm = ctx.asm;
        cgHead(ctx, vars);
        let Lbreak = asm.newLabel();
        let Lcont = asm.newLabel();
        if (init != null) {
            cgExpr(ctx, init);
            asm.I_pop();
        }
        let Ltop = asm.I_label(undefined);
        if (cond != null) {
            cgExpr(ctx, cond);
            asm.I_iffalse(Lbreak);
        }
        cgStmt(pushBreak(pushContinue(ctx, labels, Lcont), Lbreak), stmt);
        asm.I_label(Lcont);
        if (incr != null)
        {
            cgExpr(ctx, incr);
            asm.I_pop();
        }
        asm.I_jump(Ltop);
        asm.I_label(Lbreak);
    }

    function cgForInStmt(ctx, s) {
        var {vars:vars,init:init,obj:obj,stmt:stmt,labels:labels} = s;
        // FIXME: fixtures
        // FIXME: code shape?
        let {asm:asm,emitter:emitter} = ctx;
        cgHead(ctx, vars);

        if (!(init is ListExpr))
            throw "cgForInStmt: bogus";

        let name;
        switch type (init.exprs[0]) {
        case (lr: LexicalRef) {
            name = emitter.nameFromIdentExpr(init.exprs[0].ident);
        }
        case (ie: InitExpr) {
            if (ie.inits.length != 1)
                throw "unimplemented cogen in cgForInStmt: too many names" + ie.inits.length;
            let [fxname] = ie.inits[0];
            name = emitter.fixtureNameToName(fxname);
        }
        case(x: *) {
            throw "unimplemented cogen in cgForInStmt for " + init.exprs[0];
        }
        }

        let Lbreak = asm.newLabel();
        let Lcont = asm.newLabel();

        // FIXME: actually wrong to do this.  The effect we're looking for is that the
        // binding is introduced if it does not exist, ie, DEFVAR.
        asm.I_findproperty(name);
        asm.I_pushundefined();
        asm.I_setproperty(name);

        if (init != null) {
            cgExpr(ctx, init);
            asm.I_pop();
        }
        let T_obj = asm.getTemp();
        let T_idx = asm.getTemp();
        cgExpr(ctx, obj);
        asm.I_setlocal(T_obj);
        asm.I_pushbyte(0);
        asm.I_setlocal(T_idx);

        let Ltop = asm.I_label(undefined);

        asm.I_hasnext2(T_obj, T_idx);
        asm.I_iffalse(Lbreak);
        asm.I_getlocal(T_obj);
        asm.I_getlocal(T_idx);
        asm.I_nextname();

        asm.I_findpropstrict(name);
        asm.I_swap();
        asm.I_setproperty(name);

        cgStmt(pushBreak(pushContinue(ctx, labels, Lcont), Lbreak), stmt);
        asm.I_label(Lcont);
        asm.I_jump(Ltop);

        asm.I_label(Lbreak);
        asm.killTemp(T_idx);
        asm.killTemp(T_obj);
    }

    function cgBreakStmt(ctx, s) {
        var ident = s.ident;
        function hit (node) {
            return node.tag == "break" && (ident == null || ident == node.label)
        }
        unstructuredControlFlow(ctx,
                                hit,
                                true,
                                "Internal error: definer should have checked that all referenced labels are defined");
    }

    function cgContinueStmt(ctx, s) {
        var {ident: ident} = s;
        function hit(node) {
            return node.tag == "continue" && (ident == null || memberOf(ident, node.labels))
        }
        unstructuredControlFlow(ctx,
                                hit,
                                true,
                                "Internal error: definer should have checked that all referenced labels are defined");
    }

    function cgThrowStmt(ctx, s) {
        cgExpr(ctx, s.expr);
        ctx.asm.I_throw();
    }

    function cgReturnStmt(ctx, s) {
        let asm = ctx.asm;
        let t = null;
        if (s.expr != null) {
            cgExpr(ctx, s.expr);
            t = asm.getTemp();
            asm.I_setlocal(t);
        }
        function hit(node){
            return node.tag == "function" 
        }
        unstructuredControlFlow(ctx,
                                hit,
                                false,
                                "Internal error: definer should have checked that top-level code does not return");
        if (s.expr == null)
            asm.I_returnvoid();
        else {
            asm.I_getlocal(t);
            asm.killTemp(t);
            asm.I_returnvalue();
        }
    }

    // There are many optimization possibilities for 'switch'.
    // Notably, if the case expressions are all constants (or there
    // are sequences of cases with constant expressions) then binary
    // switching or LOOKUPSWITCH can be used.
    //
    // LOOKUPSWITCH may be used if the case expressions are constant
    // int values or single-character strings (we can extract the
    // character value and switch on that), with a run-time guard on
    // the type of the dispatch value if there is no compile-time type
    // information.
    //
    // For now, we generate LOOKUPSWITCH for "dense" int switches
    // above a certain size -- dense meaning at least one third of the
    // case values in the range of all the defined case values are
    // actually present in the switch, and the size cutoff being four
    // labelled cases or more.  The function analyzeSwitch() performs
    // a simple analysis and determines whether the optimization should
    // kick in or not.
    //
    // FIXME: handle more interesting cases:
    //  - single-character string values
    //  - binary search for switches with all constant-value cases
    //  - mixed sparse-dense switches
    //  - ...

    function cgSwitchStmt(ctx, s) {
        var fastswitch = analyzeSwitch(ctx, s);
        if (!fastswitch)
            cgSwitchStmtSlow(ctx,s);
        else {
            let [low,high,has_default] = fastswitch;
            cgSwitchStmtFast(ctx, s, low, high, has_default);
        }
    }

    function analyzeSwitch(ctx, s) {
        var cases = s.cases;
        var low = Infinity;
        var high = -Infinity;
        var count = 0;
        var has_default = false;
        for ( let i=0, limit=cases.length ; i < limit ; i++ ) {
            let e = cases[i].expr;
            if (e is ListExpr && e.exprs.length == 1) // parser should clean this case up!
                e = e.exprs[0];
            if (e == null)
                has_default = true;
            else if (e is LiteralExpr) {
                let l = e.literal;
                if (!(l is LiteralInt))
                    return false;
                low = Math.min(low, l.intValue);
                high = Math.max(high, l.intValue);
                count++;
            }
            else
                return false;
        }
        if (count < 4)
            return false;
        if (count * 3 < ((high - low) + 1))
            return false;
        return [low,high,has_default];
    }

    function cgSwitchStmtFast(ctx, s, low, high, has_default) {
        print("FAST SWITCH: " + low + " " + high + " " + has_default);

        var {expr:expr, cases:cases} = s;
        let asm = ctx.asm;
        cgExpr(ctx, expr);
        let t = asm.getTemp();
        asm.I_setlocal(t);
        let Ldef = asm.newLabel();
        let Lcases = new Array(high-low+1);
        let Lbreak = asm.newLabel();
        let nctx = pushBreak(ctx, Lbreak);
        let ldef_emitted = false;

        asm.I_getlocal(t);                    // switch value
        asm.I_pushint(ctx.cp.int32(low));     // offset
        asm.I_subtract();                     // bias it
        asm.I_dup();
        asm.I_convert_i();                    // convert to int
        asm.I_dup();
        asm.I_setlocal(t);                    //   and save
        asm.I_equals();                       // if computed value and int value are 
        asm.I_iffalse(Ldef);                  //   not the same then default case

        asm.I_getlocal(t);                    // otherwise dispatch
        Ldefault = asm.I_lookupswitch(undefined, Lcases);

        // Make a prepass to find all the case labels that do not have a
        // case (except maybe the default case).  If Lcases[i] is not
        // handled then Lhandled[i] will be false.

        var Lhandled = new Array(Lcases.length);
        for ( let i=0, limit=cases.length ; i < limit ; i++ ) {
            let c = cases[i];
            let e = c.expr;
            if (e is ListExpr && e.exprs.length == 1) // parser should clean this case up!
                e = e.exprs[0];

            if (e != null) {
                assert(e is LiteralExpr && e.literal is LiteralInt);
                Lhandled[e.literal.intValue - low] = true;
            }
        }

        // Now emit code for all the cases.  If there is a default
        // case then all unhandled labels are emitted there.

        for ( let i=0, limit=cases.length ; i < limit ; i++ ) {
            let c = cases[i];
            let e = c.expr;
            if (e is ListExpr && e.exprs.length == 1) // parser should clean this case up!
                e = e.exprs[0];

            if (e == null) {
                asm.I_label(Ldefault);
                asm.I_label(Ldef);
                ldef_emitted = true;
                for ( let j=0, jlimit=Lhandled.length ; j < jlimit ; j++ )
                    if (!Lhandled[j])
                        asm.I_label(Lcases[j]);
            }
            else {
                assert(e is LiteralExpr && e.literal is LiteralInt);

                // There might be duplicate case selector values, but only the first one counts.
                if (Lcases[e.literal.intValue - low] !== false) {
                    asm.I_label(Lcases[e.literal.intValue - low]);
                    Lcases[e.literal.intValue - low] = false;
                }
            }

            let stmts = c.stmts;
            for ( let j=0 ; j < stmts.length ; j++ )
                cgStmt(nctx, stmts[j] );
        }

        // If there was not a default case then map unhandled case
        // values to this point.

        if (!has_default) {
            for ( let j=0, jlimit=Lhandled.length ; j < jlimit ; j++ )
                if (!Lhandled[j])
                    asm.I_label(Lcases[j]);
        }

        asm.I_label(Lbreak);
        if (!ldef_emitted)
            asm.I_label(Ldef);
        asm.killTemp(t);
    }

    function cgSwitchStmtSlow(ctx,s) {
        var {expr:expr, cases:cases} = s;
        let asm = ctx.asm;
        cgExpr(ctx, expr);
        let t = asm.getTemp();
        asm.I_setlocal(t);
        let Ldefault = null;
        let Lnext = null;
        let Lfall = null;
        let Lbreak = asm.newLabel();
        let nctx = pushBreak(ctx, Lbreak);
        for ( let i=0 ; i < cases.length ; i++ ) {
            let c = cases[i];

            if (c.expr == null) {
                assert (Ldefault==null);
                Ldefault = asm.I_label(undefined);    // label default pos
            }

            if (Lnext !== null) {
                asm.I_label(Lnext);                   // label next pos
                Lnext = null;
            }

            if (c.expr != null) {
                cgExpr(nctx, c.expr);                 // check for match
                asm.I_getlocal(t);
                asm.I_strictequals();
                Lnext = asm.I_iffalse(undefined);     // if no match jump to next label
            }

            if (Lfall !== null) {                     // label fall through pos
                asm.I_label(Lfall);
                Lfall = null;
            }

            let stmts = c.stmts;
            for ( let j=0 ; j < stmts.length ; j++ ) {
                cgStmt(nctx, stmts[j] );
            }

            Lfall = asm.I_jump (undefined);           // fall through
        }
        if (Lnext !== null)
            asm.I_label(Lnext);
        if (Ldefault !== null)
            asm.I_jump(Ldefault);
        if (Lfall !== null)
            asm.I_label(Lfall);
        asm.I_label(Lbreak);
        asm.killTemp(t);
    }

    function cgSwitchTypeStmt(ctx, s) {
        var {expr:expr, type:type, cases:cases} = s;
        let b = new Block(new Ast::Head([],[]), [new ThrowStmt(expr)]);

        let newcases = [];
        let hasDefault = false;
        for( let i = 0; i < cases.length; i++ ) {
            newcases.push(cases[i]);
            let [_,f] = cases[i].param.fixtures[0];
            if (f.type === Ast::anyType)
                hasDefault = true;
        }

        // Add a catch all case so we don't end up throwing whatever the switch type expr was
        if (!hasDefault) {
            newcases.push(new Catch(new Head([ [new PropName({ns:new PublicNamespace(""), id:"x"})
                                               ,new ValFixture(Ast::anyType, false) ] ], [])
                                   ,new Block(new Head([],[]), [])));
        }
        cgTryStmt(ctx, {block:b, catches:newcases, finallyBlock:null} );        
    }
    
    function cgWithStmt(ctx, s) {
        var {expr:expr, stmt:stmt} = s;
        let asm = ctx.asm;
        let scopereg = asm.getTemp();

        cgExpr(ctx, expr);
        asm.I_dup();
        asm.I_setlocal(scopereg);
        asm.I_pushwith();
        cgStmt(pushWith(ctx, scopereg), stmt);
        asm.I_popscope();
        asm.killTemp(scopereg);
    }
    
    function cgTryStmt(ctx, s) {
        if (s.finallyBlock != null)
            cgTryStmtWithFinally(ctx, s);
        else
            cgTryStmtNoFinally(ctx, s);
    }

    // If there's a finally block then:
    //
    // - there is a generated catch around the try-catch complex with a handler that
    //   handles any exception type
    // - the handler in that block must visit the finally code and then re-throw if
    //   the finally code returns normally
    // - code in the try block or the catch block(s) is compiled with a ctx that
    //   records the fact that there is a finally block, so that exits to the outside of 
    //   the try/catch block by means of break/continue (labelled or not) must visit 
    //   the finally block (in inside-out if there are several)
    // - break, continue, and return must look for finally blocks
    //
    // Visiting the finally block may thus be done from various places.  To avoid
    // code bloat it is generated out-of-line.  Visiting is done by setting a register
    // to the "return" address, then jumping to the finally code, which ends with a
    // switch statement that jumps back to all the possible return points.
    //
    // Each finally block gets its own register, it's recorded in the ctx rib.
    //
    // The code for the finally block's "switch" can't be generated until we've seen
    // all the code that can visit it (represented as a list of id/labels in the ctx rib).
    //
    // There is a counter in the ctx, and id's for the switch are generated from it.
    // Its initial value is 0.  lookupswitch can be used.

    function cgTryStmtWithFinally(ctx, s) {
        let {block:block, catches:catches, finallyBlock:finallyBlock} = s;
        let {asm:asm, emitter:emitter, target:target} = ctx;

        let returnreg = asm.getTemp();
        let Lfinally = asm.newLabel();
        let newctx = pushFinally(ctx, Lfinally, returnreg);
        let rib = newctx.stk;

        let myreturn = rib.nextReturn++;
        rib.returnAddresses[myreturn] = null; // aka "Lreturn"; will be initialized below

        let Lend = asm.newLabel();
        let myend = rib.nextReturn++;
        rib.returnAddresses[myend] = Lend;

        let code_start = asm.length;
        cgTryStmtNoFinally(newctx, s);
        let code_end = asm.length;

        // Fallthrough from try-catch: visit the finally block.  This
        // code must not be in the scope of the generated exception
        // handler.

        asm.I_pushint(ctx.cp.int32(myend));
        asm.I_setlocal(returnreg);
        asm.I_jump(Lfinally);                    // control continues at Lend below

        // Generated catch block to handle throws out of try-catch:
        // capture the exception, visit the finally block with return
        // to Lreturn, then re-throw the exception at Lreturn.
        //
        // Use a lightweight exception handler; always store the value
        // in a register.

        let savedExn = asm.getTemp();
        let catch_idx = target.addException(new ABCException(code_start, code_end, asm.length, 0, 0));

        asm.startCatch();           // push 1 item
        asm.I_setlocal(savedExn);   // pop and save it

        restoreScopes(ctx);         // finally block needs correct scopes

        asm.I_pushint(ctx.cp.int32(myreturn));
        asm.I_setlocal(returnreg);
        asm.I_jump(Lfinally);                                    // control continues at Lreturn
        rib.returnAddresses[myreturn] = asm.I_label(undefined);  // "Lreturn" is here
        asm.I_getlocal(savedExn);
        asm.killTemp(savedExn);
        asm.I_throw();

        // Finally block

        asm.I_label(Lfinally);
        cgBlock(ctx, finallyBlock);

        // The return-from-subroutine code at the end of the finally block

        let visitors = newctx.stk;
        let {nextReturn:numvisits, returnAddresses:visitors} = rib;
        let Lcases = new Array(numvisits);
        asm.I_getlocal(returnreg);
        asm.I_convert_i();
        var Ldefault = asm.I_lookupswitch(undefined, Lcases);
        asm.I_label(Ldefault); // Default case is never hit.
        for ( let i=0 ; i < numvisits ; i++ ) {
            asm.I_label(Lcases[i]);
            asm.I_jump(visitors[i]);
        }

        asm.I_label(Lend);
        asm.killTemp(returnreg);
    }

    function cgTryStmtNoFinally(ctx, s) {
        let {block:block, catches:catches} = s;
        let asm = ctx.asm;
        let code_start = asm.length;
        cgBlock(ctx, block);
        let code_end = asm.length;
        
        let Lend = asm.newLabel();
        asm.I_jump(Lend);

        for( let i = 0; i < catches.length; ++i )
            cgCatch(ctx, code_start, code_end, Lend, catches[i]);
        
        asm.I_label(Lend);
    }
    
    function cgCatch(ctx, code_start, code_end, Lend, s ) {
        var {param:param, block:block} = s;
        let {asm:asm, emitter:emitter, target:target} = ctx;
        
        if( param.fixtures.length != 1 )
            throw "Internal Error: catch should have 1 fixture";
        
        let [propname, fix] = param.fixtures[0];
        
        let param_name = emitter.fixtureNameToName(propname);
        let param_type = emitter.realTypeName(fix.type);
        
        let catch_idx = target.addException(new ABCException(code_start, code_end, asm.length, param_type, param_name));

        asm.startCatch();

        let t = asm.getTemp();
        restoreScopes(ctx);
        let catch_ctx = pushCatch(ctx,t);

        asm.I_newcatch(catch_idx);
        asm.I_dup();
        asm.I_setlocal(t);  // Store catch scope in register so it can be restored later
        asm.I_dup();
        asm.I_pushscope();
        
        // Store the exception object in the catch scope.
        asm.I_swap();
        asm.I_setproperty(param_name);

        // catch block body
        cgBlock(catch_ctx, block);
        
        asm.killTemp(t);
        
        asm.I_popscope();
        asm.I_jump(Lend);
    }

}
