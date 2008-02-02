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

/* Protocols:
   
   - the 'this' receiver object is passed as the first argument to any call, 
     the value may be null
   - local(0) contains the current 'this' object inside any function body,
     its value is always an object
   - inside class instance methods, the 'this' object is on the scope stack 
     outside the activation object
   - inside constructors, the 'this' object is on the scope stack in the 
     constructor body, also outside the activation object
   - inside other functions, the 'this' object is not on the scope stack
   - inside script top levels the 'this' object is on the scope stack; it
     should be the global object.
   - inside class initializers the 'this' object is on the scope stack; it
     is presumably the class object (but this remains to be verified).
*/

var CTX_shared;

/* A context is a structure with the fields
 *
 *    emitter  -- the unique emitter
 *    script   -- the only script we care about in that emitter
 *    cp       -- the emitter's constant pool
 *    asm      -- the current function's assembler
 *    stk      -- the current function's binding stack (labels, ribs)
 *    target   -- the current trait target
 *
 * All of these are invariant and kept in the prototype except for
 * 'asm', 'stk', and some fields to come.
 *
 * FIXME, there are probably at least two targets: one for LET, another
 * for VAR/CONST/FUNCTION.
 */

class CTX {
    var asm, stk, target;
    var emitter, script, cp, filename;

    function CTX (asm, stk, target) {
        this.asm = asm;
        this.stk = stk;
        this.target = target;

        // tamarin hack
        this.emitter = CTX_shared.emitter;
        this.script = CTX_shared.script;
        this.cp = CTX_shared.cp;
        this.filename = CTX_shared.filename;
    }
}

namespace Gen;
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

    // Emit debug info or not
    var emit_debug = true;

    Gen function internalError(ctx, msg) {
        Util::internalError(ctx.filename, ctx.lineno, msg);
    }

    Gen function syntaxError(ctx, msg) {
        Util::syntaxError(ctx.filename, ctx.lineno, msg);
    }

    /* Returns an ABCFile structure */
    function cg(tree: PROGRAM) {
        var e = new ABCEmitter;
        var s = e.newScript();
        // CTX.prototype = { "emitter": e, "script": s, "cp": e.constants };  // tamarin doesn't like initing prototype here
        CTX_shared = { "emitter": e, "script": s, "cp": e.constants, "filename": tree.file };
        cgProgram(new CTX(s.init.asm, {tag: "script", push_this: true}, s), tree);
        return e.finalize();
    }

    function push(ctx, node) {
        node.link = ctx.stk;
        return new CTX(ctx.asm, node, ctx.target);
    }

    function cgDebugFile(ctx) {
        let {asm:asm, cp:cp} = ctx;
        if( emit_debug && ctx.filename != null )
            asm.I_debugfile(cp.stringUtf8(ctx.filename));
    }

    function cgProgram(ctx, prog) {
        
        cgDebugFile(ctx);
        
        if (prog.head.fixtures != null)
            cgFixtures(ctx, prog.head.fixtures);
        cgBlock(ctx, prog.block);
    }

    function hasTrait(traits, name, kind) {
        for(var i = 0, l =traits.length; i < l; i++) {
            let t = traits[i];
            if(t.name==name && ((t.kind&15)==kind))
                return true;
        }
        return false;
    }
    
    function cgFixtures(ctx, fixtures) {
        let { target:target, asm:asm, emitter:emitter } = ctx;
        let methidx, trait_kind, clsidx;
        for ( let i=0 ; i < fixtures.length ; i++ ) {
            let [fxname, fx] = fixtures[i];
            let name = emitter.fixtureNameToName(fxname);

            if (fx is ValFixture) {
                if( !hasTrait(target.traits, name, TRAIT_Slot) )
                    target.addTrait(new ABCSlotTrait(name, 0, false, 0, emitter.typeFromTypeExpr(fx.type), 0, 0)); 
                    // FIXME when we have more general support for type annos
            }
            else if (fx is MethodFixture) {
                methidx = cgFunc(ctx, fx.func);
                if (target is Method || target is Script) {
                    target.addTrait(new ABCSlotTrait(name, 0, false, 0, 0, 0, 0)); 
                    asm.I_findpropstrict(name);
                    asm.I_newfunction(methidx);
                    asm.I_setproperty(name);
                }
                else {
                    // target.addTrait(new ABCOtherTrait(name, 0, TRAIT_Method, 0, methidx));
                    trait_kind = TRAIT_Method;
                    if (fx.func.name.kind is Get) {
                        trait_kind = TRAIT_Getter;
                    }
                    else if (fx.func.name.kind is Set) {
                        trait_kind = TRAIT_Setter;
                    }
                    target.addTrait(new ABCOtherTrait(name, 0, trait_kind, 0, methidx));
                }
            }
            else if (fx is ClassFixture) {
                clsidx = cgClass(ctx, fx.cls);
                target.addTrait(new ABCOtherTrait(name, 0, TRAIT_Class, 0, clsidx));
            }
            else if (fx is NamespaceFixture) {
                target.addTrait(new ABCSlotTrait(name, 0, true, 0, 
                                                 emitter.qname({ns:new PublicNamespace(""), id:"Namespace"},false), 
                                                 emitter.namespace(fx.ns), CONSTANT_Namespace));
            }
            else if (fx is TypeFixture) {
                //print ("warning: ignoring type fixture");
            }
            else {
                Gen::internalError(ctx, "Unhandled fixture type " + fx);
            }
        }
    }

    function cgBlock(ctx, b) {
        // FIXME -- more here
        cgHead(ctx, b.head);
        let stmts = b.stmts;
        for ( let i=0 ; i < stmts.length ; i++ )
            cgStmt(ctx, stmts[i]);
    }

/*
    function cgDefn(ctx, d) {
        let { asm:asm, emitter:emitter } = ctx;
        switch type (d) {
        case (fd:FunctionDefn) {
            assert( fd.func.name.kind is Ordinary );
            let name = emitter.nameFromIdent(fd.func.name.ident);
            //asm.I_findpropstrict(name); // name is fixture, thus always defined
            //asm.I_newfunction(cgFunc(ctx, fd.func));
            //asm.I_initproperty(name);
        }
        case (vd: VariableDefn) {
            // nothing to do, right?
        }
        case (x:*) { 
            Gen::internalError(ctx, "Unimplemented defn " +d); 
        }
        }
    }
*/

    function extractNamedFixtures(fixtures)
    {
        let named = [];
        let fix_length = fixtures ? fixtures.length : 0;
        for(let i = 0; i < fix_length; ++i)
        {
            let [name,fixture] = fixtures[i];
            switch type (name) {
                case (pn:PropName) {
                    named.push([name,fixture]);
                }
                case (tn:TempName) {
                    // do nothing
                }
            }
        }
        return named;
    }
    
    function extractUnNamedFixtures(fixtures)
    {
        let named = [];
        let fix_length = fixtures ? fixtures.length : 0;
        for(let i = 0; i < fix_length; ++i)
        {
            let [name,fixture] = fixtures[i];
            switch type (name) {
                case (pn:PropName) {
                    // do nothing
                }
                case (tn:TempName) {
                    named.push([name,fixture]);
                }
            }
       }
       return named;
   }

    function cgClass(ctx, c) {
        
        let {asm:asm, emitter:emitter, script:script} = ctx;
        
        let classname = emitter.qname(c.name,false);
        let basename = c.baseName != null ? emitter.qname(c.baseName,false) : 0;
        
        let cls = script.newClass(classname, basename);
        
        
        let c_ctx = new CTX(asm, {tag:"class"}, cls);

        // static fixtures
        cgFixtures(c_ctx, c.classHead.fixtures);

        // cinit - init static fixtures
        let cinit = cls.getCInit();
        let cinit_ctx = new CTX(cinit.asm, {tag:"function", functype:"cinit"}, cinit);
        cgDebugFile(cinit_ctx);
        cgHead(cinit_ctx, {fixtures:[], exprs:c.classHead.exprs});
        
      
        let inst = cls.getInstance();
        
        // Context for the instance
        let i_ctx = new CTX(asm, {tag:"instance"}, inst);
        
        // do instance slots
        cgFixtures(i_ctx, c.instanceHead.fixtures);  // FIXME instanceHead and instanceInits should be unified
        
        inst.setIInit(cgCtor(i_ctx, c.constructor, {fixtures:[],exprs:c.instanceHead.exprs}));
        
        var clsidx = cls.finalize();
        var Object_name = emitter.qname({ns:new PublicNamespace(""), id:"Object"},false);

        asm.I_findpropstrict(Object_name);
        asm.I_getproperty(Object_name);
        asm.I_dup();
        asm.I_pushscope();
        asm.I_newclass(clsidx);
        asm.I_popscope();
        asm.I_getglobalscope();
        asm.I_swap();
        asm.I_initproperty(classname);

        return clsidx;
    }
    
    /*  
     *  Generate code for a ctor.
     */
    function cgCtor(ctx, c, instanceInits) {
        let formals_type = extractFormalTypes(ctx, c.func);
        let method = new Method(ctx.script.e, formals_type, "$construct", false, c.func.attr.uses_arguments);
        let asm = method.asm;

        let defaults = extractDefaultValues(ctx, c.func);
        if( defaults.length > 0 )
        {
            method.setDefaults(defaults);
        }
        
        let t = asm.getTemp();
        // FIXME: record that scopes must be restored here!
        let ctor_ctx = new CTX(asm, {tag:"function", functype:"iinit", scope_reg:t}, method);
       
        cgDebugFile(ctor_ctx);
        asm.I_getlocal(0);
        asm.I_dup();
        // Should this be instanceInits.inits only?
        asm.I_pushscope();  // This isn't quite right...
        for( let i = 0; i < instanceInits.length; i++ ) {
            cgExpr(ctor_ctx, instanceInits[i]);
            asm.I_pop();
        }
        cgHead(ctor_ctx, instanceInits);
        asm.I_popscope();
        //cgHead(ctor_ctx, instanceInits.inits, true);

        // Push 'this' onto scope stack
        //asm.I_getlocal(0);
        //asm.I_pushscope();
        // Create the activation object, and initialize params
        asm.I_newactivation();
        asm.I_dup();
        asm.I_setlocal(t);
        asm.I_dup();
        asm.I_pushwith();

        setupArguments(ctor_ctx, c.func);

        cgHead(ctor_ctx, c.func.params);

        for ( let i=0 ; i < c.settings.length ; i++ ) {
            cgExpr(ctor_ctx, c.settings[i]);
            asm.I_pop();
        }

        // Eval super args, and call super ctor
        asm.I_getlocal(0);
        let nargs = c.superArgs.length;
        for ( let i=0 ; i < nargs ; i++ )
            cgExpr(ctx, c.superArgs[i]);
        asm.I_constructsuper(nargs);
        
        asm.I_popscope();
        asm.I_getlocal(0);
        asm.I_pushscope();  //'this'
        asm.I_pushscope();  //'activation'
        
        cgHead(ctor_ctx, c.func.vars);

        cgBlock(ctor_ctx, c.func.block);
        
        asm.I_kill(t);
        return method.finalize();
    }

    function extractFormalTypes(ctx, f:Func) {
        var {emitter:emitter, script:script} = ctx;
        function extractType([name,fixture])
            emitter.fixtureTypeToType(fixture);
        
        let named_fixtures = extractUnNamedFixtures(f.params.fixtures);
        
        return map(extractType, named_fixtures);
    }
        
    function extractDefaultValues(ctx, f:Func) {
        var {emitter:emitter, script:script} = ctx;
        function extractDefaults(expr)
            emitter.defaultExpr(expr);

        return map(extractDefaults, f.defaults);
    }
    
    /* Create a method trait in the ABCFile
     * Generate code for the function
     * Return the function index
     */
    function cgFunc(ctx0, f:FUNC) {
        var {emitter:emitter,script:script, cp:cp} = ctx0;
        let fntype = ctx0.stk != null && (ctx0.stk.tag == "instance" || ctx0.stk.tag == "class")? "method" : "vanilla";  // brittle as hell
        let formals_type = extractFormalTypes({emitter:emitter, script:script}, f);
        let method = script.newFunction(formals_type, fntype != "vanilla", f.attr.uses_arguments);
        let asm = method.asm;

        let name = f.name ? f.name.ident : "";
        method.name = cp.stringUtf8(name);
        
        let defaults = extractDefaultValues({emitter:emitter, script:script}, f);
        if( defaults.length > 0 )
        {
            method.setDefaults(defaults);
        }
        
        /* Create a new rib and populate it with the values of all the
         * formals.  Add slot traits for all the formals so that the
         * rib have all the necessary names.  Later code generation
         * will add properties for all local (hoisted) VAR, CONST, and
         * FUNCTION bindings, and they will be added to the rib too,
         * but not initialized here.  (That may have to change, for
         * FUNCTION bindings at least.)
         *
         * FIXME: if a local VAR shadows a formal, there's more
         * elaborate behavior here, and the compiler must perform some
         * analysis and avoid the shadowed formal here.
         */
        let t = asm.getTemp();

        let fnctx = new CTX(asm, {tag: "function", 
                                  functype:fntype, 
                                  scope_reg:t, 
                                  has_scope:true, 
                                  push_this: (fntype != "vanilla")}, 
                            method);
        cgDebugFile(fnctx);

        asm.I_newactivation();
        asm.I_dup();
        asm.I_setlocal(t);
        asm.I_pushscope();

        setupArguments(fnctx, f);

        cgHead(fnctx, f.params);
        cgHead(fnctx, f.vars);

        /* Generate code for the body.  If there is no return statement in the
         * code then the default behavior of the emitter is to add a returnvoid
         * at the end, so there's nothing to worry about here.
         */
        cgBlock(fnctx, f.block);
        asm.killTemp(t);
        return method.finalize();
    }

    function setupArguments(ctx, f) {
        if (f.attr.uses_arguments) {
            // Create a fixture for "arguments", cgFixture ignores it if it's defined already.
            //
            // FIXME: what if the existing fixture is typed and won't admit the arguments object?
            // The rule for ES4 should probably be that if there is a typed "arguments" defined,
            // then no assignment will be generated here.
            //
            // Then initialize it.  It must be done first according to E262-3.

            cgFixtures(ctx, [[new PropName({ns: Ast::noNS, id: "arguments"}), 
                              new ValFixture(Ast::anyType, false)]]);
            cgExpr(ctx, new Ast::SetExpr(Ast::assignOp, 
                                         new Ast::LexicalRef(new Ast::Identifier("arguments",[[Ast::noNS]])), 
                                         new Ast::GetParam(f.numparams)));
            ctx.asm.I_pop();
        }
    }
    
    function cgHead(ctx, head) {
        let {asm:asm, emitter:emitter, target:target} = ctx;
        
        function extractName([name,fixture])
            ctx.emitter.fixtureNameToName(name); //FIXME: shouldn't need ctx.
        
        function extractType([name,fixture])
            ctx.emitter.fixtureTypeToType(fixture); //FIXME: shouldn't need ctx.
        
        let named_fixtures = extractNamedFixtures(head.fixtures);
/*
        let formals = map(extractName, named_fixtures);
        let formals_type = map(extractType, named_fixtures);
        for ( let i=0 ; i < formals.length ; i++ ) {
            if(!hasTrait(target.traits, formals[i], TRAIT_Slot) )
                target.addTrait(new ABCSlotTrait(formals[i], 0, false, 0, formals_type[i]));
        }
*/
        cgFixtures(ctx, named_fixtures);
        for ( let i=0 ; i < head.exprs.length ; i++ ) {
            cgExpr(ctx, head.exprs[i]);
            asm.I_pop();
        }
    }

    function cgInits(ctx, inits, baseOnStk){
        let {asm:asm, emitter:emitter} = ctx;

        let t = -1;
        let inits_length = inits?inits.length:0;
        for( let i=0; i < inits_length; ++i ) {
            let [name, init] = inits[i];

            let name_index = emitter.fixtureNameToName(name);

            if( baseOnStk ) {
                if(i < inits_length-1)
                    asm.I_dup();
            }
            else
                asm.I_findproperty(name_index);
            
            cgExpr(ctx, init);
            asm.I_setproperty(name_index);
        }
        if( inits_length == 0 && baseOnStk )
        {
            asm.I_pop();
        }
  }
    

    // Handles scopes and finally handlers and returns a label, if appropriate, to
    // branch to.  "tag" is one of "function", "break", "continue"

    function unstructuredControlFlow(ctx, hit, jump, msg) {
        var {stk:stk, asm:asm} = ctx;
        while (stk != null) {
            if (hit(stk)) {
                if (jump)
                    asm.I_jump(stk.target);
                return;
            }
            else {
                if(stk.has_scope) {
                    asm.I_popscope();
                }
                if (stk.tag == "finally") {
                    /* The verifier can't deal with all these combinations, it appears to
                       be a limitation of how it does control flow analysis.  So throw
                       a SyntaxError here until the verifier can be fixed.
                    let myreturn = stk.nextReturn++;
                    asm.I_pushint(ctx.cp.int32(myreturn));
                    asm.I_setlocal(stk.returnreg);
                    asm.I_jump(stk.label);
                    stk.returnAddresses[myreturn] = asm.I_label(undefined);
                    */
                    Gen::internalError(ctx, "Limitation: Can't generate code for break/continue/return past 'finally' block.");
                }
            }
            stk = stk.link;
        }
        Gen::syntaxError(ctx, msg);
    }

    function restoreScopes(ctx) {
        var {stk:stk, asm:asm} = ctx;
        loop(stk);

        function loop(stk) {
            if (stk == null)
                return;
            if (stk.tag != "function")
                loop(stk.link);
            if (stk.push_this) {
                // function, script -- probably others
                asm.I_getlocal(0);
                asm.I_pushscope();
            }
            if (stk.has_scope) {
                asm.I_getlocal(stk.scope_reg);
                if (stk.tag == "with")
                    asm.I_pushwith();
                else
                    asm.I_pushscope();
            }
        }
    }

    // The following return extended contexts
    function pushBreak(ctx, target)
        pushLabel(ctx, null, target);

    function pushLabel(ctx, label, target)
        push(ctx, { tag:"break", label:label, target:target, has_scope:false });

    function pushContinue(ctx, labels, target)
        push(ctx, { tag:"continue", labels:labels, target:target, has_scope:false });

    function pushFunction(ctx /*more*/) {
        // FIXME
    }

    function pushWith(ctx, scope_reg)
        push(ctx, { tag:"with", has_scope:true, scope_reg:scope_reg });

    function pushLet(ctx /*more*/) {
    }

    function pushCatch(ctx, scope_reg )
        push(ctx, {tag:"catch", has_scope:true, scope_reg:scope_reg});

    function pushFinally(ctx, label, returnreg)
        push(ctx, {tag:"finally", label:label, returnreg:returnreg, returnAddresses:new Array(), nextReturn:0});
}
