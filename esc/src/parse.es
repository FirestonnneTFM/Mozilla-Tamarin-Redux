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

use namespace Release;
use namespace intrinsic;

{
    use default namespace Parse;
    use namespace Lex;

    type PATTERNS = [PATTERN];
    type PATTERN =
          ( ObjectPattern
          , ArrayPattern
          , SimplePattern
          , IdentifierPattern );

    type FIELD_PATTERNS = [FIELD_PATTERN];
    type FIELD_PATTERN = FieldPattern;

    class FieldPattern {
        use default namespace public;
        const ident: Ast::IDENT_EXPR;
        const ptrn: PATTERN;
        function FieldPattern (ident,ptrn)
            : ident = ident
            , ptrn = ptrn { }
    }

    class ObjectPattern {
        const ptrns //: FIELD_PATTERNS;
        function ObjectPattern (ptrns)
            : ptrns = ptrns { }
    }

    class ArrayPattern { 
        const ptrns //: PATTERNS;
        function ArrayPattern (ptrns)
            : ptrns = ptrns { }
    }

    class SimplePattern
    {
        const expr : Ast::EXPR;
        function SimplePattern (expr)
            : expr = expr { }
    }

    class IdentifierPattern
    {
        const ident : Ast::IDENT;
        function IdentifierPattern (ident)
            : ident = ident { }
    }

    type ALPHA = (NoColon, AllowColon);
    class NoColon {}
    class AllowColon {}
    const noColon = new NoColon;
    const allowColon = new AllowColon;

    type BETA = (NoIn, AllowIn);
    class NoIn {}
    class AllowIn {}
    const noIn = new NoIn;
    const allowIn = new AllowIn;

    type GAMMA = (NoExpr, AllowExpr);
    class NoExpr {}
    class AllowExpr {}
    const noExpr = new NoExpr;
    const allowExpr = new AllowExpr;

    type TAU = (GlobalBlk, ClassBlk, InterfaceBlk, LocalBlk);
    class GlobalBlk {}
    class ClassBlk {}
    class InterfaceBlk {}
    class LocalBlk {}
    const globalBlk = new GlobalBlk;
    const classBlk = new ClassBlk;
    const interfaceBlk = new InterfaceBlk;
    const localBlk = new LocalBlk;

    /*
    const AbbrevIfElse = 0;
    const AbbrevDoWhile = AbbrevIfElse + 1;
    const AbbrevFunction = AbbrevDoWhile + 1;
    const Abbrev = AbbrevFunction + 1;
    const Full = Abbrev + 1;
    */

    type OMEGA = (FullStmt, AbbrevStmt);
    class FullStmt {}
    class AbbrevStmt {}
    const fullStmt = new FullStmt;
    const abbrevStmt = new AbbrevStmt;

    type ENV = [Ast::FIXTURES];

    type PRAGMAS = Pragmas;
    class Pragmas 
    {
        use default namespace public;
        var openNamespaces //: [[Ast::NAMESPACE]];
        var defaultNamespace: Ast::NAMESPACE;
        function Pragmas (pragmas) 
        {
            if (pragmas==null)
            {
                this.openNamespaces = [[]];
                this.defaultNamespace = Ast::noNS;  // same as new Ast::PublicNamespace ("");
            }
            else
            {
                this.openNamespaces = Util::copyArray (pragmas.openNamespaces);
                this.defaultNamespace = pragmas.defaultNamespace;
            }

            if (this.openNamespaces[this.openNamespaces.length-1].length !== 0) { 
                this.openNamespaces.push ([]);  // otherwise reuse the last one pushed
            }
        }
    }

    type PRAGMA_ENV = [Ast::PRAGMAS];

    Parse function syntaxError(ctx, msg) {
        var filename = "";
        var position = 0;
        if (ctx is Context)
            ctx = ctx.parser;
        if (ctx is Parser) {
            filename = ctx.scan.filename;
            let p = ctx.position();
            if (p != null)
                position = p.line;
        }
        Util::syntaxError(filename, position, msg);
    }

    Parse function internalError(ctx, msg) {
        var filename = "";
        var position = 0;
        if (ctx is Context)
            ctx = ctx.parser;
        if (ctx is Parser) {
            filename = ctx.scan.filename;
            let p = ctx.position();
            if (p != null)
                position = p.line;
        }
        Util::internalError(filename, position, msg);
    }

    class Context
    {
        use default namespace public;
        var env: ENV;
        var varHeads  //: [Ast::HEAD];
        var letHeads  //: [Ast::HEAD];
        var ctor: Ast::CTOR;
        var pragmas: PRAGMAS
        var pragmaEnv: PRAGMA_ENV; // push one PRAGMAS for each scope
        var top_function/*: Ast::FuncAttr*/;
        var parser;

        function Context (topFixtures, parser)
            : env = [topFixtures]
            , varHeads = []
            , letHeads = [] 
            , ctor = null
            , pragmas = null
            , pragmaEnv = []
            , parser = parser
        {
            //print ("topFixtures.length=",topFixtures.length);
            //            print ("env[0].length=",env[0].length);
            top_function = new Ast::FuncAttr(null);  // global context
        }

        function enterVarBlock () 
        {
            use namespace Ast;
            let varHead = new Ast::Head ([],[]);
            this.varHeads.push(varHead);
            this.env.push (varHead.fixtures);
            this.pragmas = new Pragmas (this.pragmas);
            this.pragmaEnv.push (this.pragmas);
        }

        function exitVarBlock () 
        {
            let varHead = this.varHeads.pop ();
            this.env.pop ();
            this.pragmaEnv.pop ();
            if (this.pragmaEnv.length === 0) {
                this.pragmas = null;
            }
            else {
                this.pragmas = this.pragmaEnv[this.pragmaEnv.length-1];
            }
            return varHead;
        }

        function enterFunction() {
            use namespace Ast; // language bug, needs fixing
            var node = new FuncAttr(top_function);
            top_function.children.push(node);
            top_function = node;
            return node;
        }

        function topFunction() {
            return top_function;
        }

        function exitFunction() {
            use namespace Ast; // language bug, needs fixing
            var top = top_function;
            top_function = top_function.parent;
            return top;
        }

        function hasFixture (fxtrs,fb) {
            use namespace Ast;
            let [fn,f1] = fb;
            switch type (fn) {
            case (fn: Ast::PropName) {
                if (hasName (fxtrs,fn.name.id,fn.name.ns)) {
                    //print("hasName ",ns,"::",id);
                    let f2 = getFixture (fxtrs,id,ns);
                    if (f1 is Ast::ValFixture && f2 is Ast::ValFixture) {
                        if (f1.Ast::type==Ast::anyType) return true;
                        else if (f2.Ast::type==Ast::anyType) return true;
                        // other positive cases here
                    }
                    Parse::syntaxError(this, "Incompatible fixture redefinition "+fn.id);
                }
            }
            case (fn: Ast::TempName) {
                return false;  // for now
            }
            }
        }

        function addVarFixtures (fxtrs, isStatic=false) 
        {
            use namespace Ast;
            let varHead = this.varHeads[this.varHeads.length-(isStatic?2:1)];
            for (let n = 0, len = fxtrs.length; n < len; ++n)  // until array conact works
            {
                let fb = fxtrs[n];
                /// if (!hasFixture (varHead.Ast::fixtures,fb)) {
                    varHead.fixtures.push (fxtrs[n]);
                /// }
            }
        }

        function addVarInits (inits, isStatic=false) 
        {
            use namespace Ast;
            let varHead = this.varHeads[this.varHeads.length-(isStatic?2:1)];
            for (let n = 0, len = inits.length; n < len; ++n)  // until array conact works
                varHead.exprs.push (inits[n]);
        }

        function enterLetBlock () 
        {
            use namespace Ast;
            let letHead = new Ast::Head ([],[]);
            this.letHeads.push(letHead);
            this.env.push (letHead.fixtures);
            this.pragmas = new Pragmas (this.pragmas);
            this.pragmaEnv.push (this.pragmas);
        }

        function exitLetBlock () 
        {
            let letHead = this.letHeads.pop ();
            this.env.pop ();
            this.pragmaEnv.pop ();
            this.pragmas = this.pragmaEnv[this.pragmaEnv.length-1];
            return letHead;
        }

        function addLetFixtures (fxtrs) 
        {
            use namespace Ast;
            let letHead = this.letHeads[this.letHeads.length-1];
            for (let n = 0, len = fxtrs.length; n < len; ++n)  // until array conact works
                letHead.fixtures.push (fxtrs[n]);
        }

        function addLetInits (inits) 
        {
            use namespace Ast;
            let letHead = this.letHeads[this.letHeads.length-1];
            for (let n = 0, len = inits.length; n < len; ++n)  // until array conact works
                letHead.exprs.push (inits[n]);
        }

        function openNamespace (nd: Ast::IDENT_EXPR) {
            let ns = evalIdentExprToNamespace (nd);
            //print("this.pragmas=",this.pragmas);
            let opennss = this.pragmas.openNamespaces;
            //print ("opennss=",opennss);
            //print ("opennss.length=",opennss.length);
            //print ("adding ns ",ns);
            opennss[opennss.length-1].push (ns);
        }

        function defaultNamespace (nd: Ast::IDENT_EXPR) {
            let ns = evalIdentExprToNamespace (nd);
            this.pragmas.defaultNamespace = ns;
        }

        function hasName (fxtrs,id,ns) 
        {
            use namespace Ast;

            if (fxtrs.length==0)
                return false;

            let pn = fxtrs[0][0];
            //print ("pn",pn," is PropName",pn is PropName);
            //print ("pn.name",pn.name);
            //print ("pn..id=",pn.name.id," id=",id);
            //print ("pn..ns=",pn.name.ns.hash()," ns=",ns.hash());
            if (pn.name.id==id && pn.name.ns.hash()==ns.hash())  // FIXME: need ns compare
            {
                return true;
            }
            else 
            {
                return hasName (fxtrs.slice (1,fxtrs.length),id,ns);
            }
        }

        function getFixture (fxtrs,id,ns) 
        {
            use namespace Ast;

            if (fxtrs.length===0) 
                Parse::syntaxError(this, "Name not found " + ns + "::" + id);

            let pn = fxtrs[0][0];
            if (pn.name.id==id && pn.name.ns.toString()==ns.toString()) 
            {
                return fxtrs[0];
            }
            else 
            {
                return getFixture (fxtrs.slice (1,fxtrs.length),id,ns);
            }
        }

        /*

        two dimensional search

        repeat for each shadowed name
            each name in each head
                dup is error

        for each namespace set
            find all names in the inner most head

        */

        function findFixtureWithNames (id,nss, it: Ast::INIT_TARGET?) {
            let env = this.env;

            switch (it) {
            case Ast::instanceInit:
                var start = env.length-2;
                var stop = start;
                break;
            case null:
                var start = env.length-1;
                var stop = 0;
                break;
            default:
                Parse::internalError(this, "findFixtureWithName: unimplemented target " + it);
            }

            //print ("env.length=",env.length);
            for (var i=start; i>=stop; --i)   // for each head
            {
                let ns = null;
                let fxtrs = env[i];
                //print ("nss.length=",nss.length);
                for (var j=nss.length-1; j>=0; --j) {
                    //print ("nss[",j,"]=",nss[j]);
                    if (hasName (fxtrs,id,nss[j])) {
                        if (ns !== null)
                            Parse::syntaxError(this, "Ambiguous reference to " + id);
                        ns = nss[j];
                    }
                }
                if (ns!==null) {
                    return getFixture (fxtrs,id,ns);
                }
            }

            return null;
        }

        function findFixtureWithIdentifier (id: Ast::IDENT, it: Ast::INIT_TARGET?)
        {
            //print ("this.pragmas=",this.pragmas);
            let nsss = this.pragmas.openNamespaces;
            //print ("nsss.length=",nsss.length);
            for (var i=nsss.length-1; i>=0; --i) 
            {
                //print ("nsss[",i,"]=",nsss[i]);
                let fx = findFixtureWithNames (id,nsss[i],it);
                if (fx !== null) 
                {
                    return fx;
                }
            }
            Parse::syntaxError(this, "Fixture not found: " + id);
        }

        function evalIdentExprToNamespace (nd: Ast::IDENT_EXPR)
            : Ast::NAMESPACE
        {
            use namespace Ast;

            var fxtr = null;
            var val = null;

            switch type (nd) {
            case (nd: Identifier) {
                var fxtr = findFixtureWithIdentifier (nd.ident,null);
                switch type (fxtr[1]) {
                case (fxtr:NamespaceFixture) {
                    var val = fxtr.ns;
                    return fxtr.ns;
                }
                case (fxtr:*) {
                    Parse::internalError(this, "Fixture with unknown value " + fxtr);
                }
                }
            }
            case (nd: ReservedNamespace) {
                var val = nd.ns;
                return val;
            }
            case (nd: *) {
                Parse::internalError(this, "evalIdentExprToNamespace: case not implemented " + nd);
            }
            }
            return val;
        }

        function resolveIdentExpr (nd: Ast::IDENT_EXPR, it: Ast::INIT_TARGET)
            : Ast::FIXTURE_NAME
        {
            switch type (nd) {
            case (nd: Ast::Identifier) {
                var fxtr = findFixtureWithIdentifier (nd.Ast::ident, it);
            }
            case (nd: *) {
                Parse::internalError(this, "resolveIdentExpr: case not implemented " + nd);
            }
            }
            return fxtr[0];
        }
    }

    class Parser
    {
        var scan    : Scanner;
        var cx      : Context;
        var filename: String;

        function Parser(src,topFixtures,filename="") {
            this.cx = new Context (topFixtures, this);
            this.scan = new Scanner (src,filename);
            this.filename = filename;
        }

        var defaultNamespace: Ast::NAMESPACE;
        var currentPackageName: string;
        var currentClassName: string;

        // Token queue abstractions
        // BEGIN

        // Token queue
        //
        // T0 is the current token, L0 its line number
        // T1 is the next token, L1 its line number
        // LP is the line number of the previous token
        //
        // The line number of a token is the 1-based line number of
        // the last character of the token.
        //
        // Invariants:
        //   T0 is NONE only before start() and when the stream is exhausted.
        //   T1 is NONE whenever it's invalid
        //   L1 is invalid iff T1 is invalid
        //   LP, L0, and L1 are 0 if there is "no information"
        //   The scanner never returns Eol
        //
        // Every token passes through this interface so we try to save time
        // when possible.
        //
        // Current optimizations:
        //   * avoid function calls
        //     - scan.start() is shallow
        //     - Token::tokenKind and Token::tokenText have been in-lined
        //   * avoid allocations
        //     - Communicate with lexer via multiple variables rather than 
        //       using multiple return values
        //
        // Future optimizations (maybe):
        //   - With static typing to "uint" it may be possible to avoid write 
        //     barriers on assignments to T0, T1, LP, L0, and L1
        //   - With tokenStore typed as Vector.<uint> it may be possible to
        //     avoid range checks and checks for holes
        //
        // What we need the compiler to do:
        //   - Early binding to instance vars and methods is important
        //   - We would probably benefit from the compiler inlining hd
        //     everywhere; we can declare it "final" or just make Parser
        //     itself "final"

        var T0=Token::NONE, T1=Token::NONE, LP=0, L0=0, L1=0;
        const tokenStore = Token::tokenStore;

        function start() {
            T0 = scan.start();
            L0 = scan.lnCoord;
        }

        function div() {
            Util::assert( T0 === Token::BREAK && T1 === Token::NONE );
            T0 = scan.div();
            L0 = scan.lnCoord;
            return hd();
        }

        function hd ()
            tokenStore[T0].Token::kind;

        function lexeme ()
            tokenStore[T0].Token::text;

        function hd2 () {
            if (T1 === Token::NONE) {
                T1 = scan.start();
                L1 = scan.lnCoord;
            }
            return tokenStore[T1].Token::kind;
        }

        function lexeme2 () {
            hd2 ();
            return tokenStore[T1].Token::text;
        }

        function next () {
            LP = L0;
            T0 = T1;
            L0 = L1;
            T1 = Token::NONE;
            if (T0 === Token::NONE) {
                T0 = scan.start();
                L0 = scan.lnCoord;
            }
        }

        function replace (t) {
            T0 = t;
        }

        function newline ()
            LP < L0;

        function position () {
            if (L0 != 0)
                return { line: L0 };
            return null;
        }

        function tokenText(t)
            tokenStore[t].Token::text;

        // Token queue abstractions
        // END

        // If the current token is not tc then throw an error.
        // Otherwise consume the token.

        function eat (tc) {
            let tk = hd ();
            if (tk !== tc)
                Parse::syntaxError(this, "Expecting " + tokenText(tc) + " found " + tokenText(tk));
            next ();
        }

        function makeIdentifier(id, nss) : Ast::Identifier {
            var ident = new Ast::Identifier(id, nss);
            if (id === "arguments") 
                cx.topFunction().uses_arguments = true;
            else if (id === "eval")
                cx.topFunction().uses_eval = true;
            return ident;
        }

        /*

        Notation

        []             list
        (fl,el)        head
        fl             fixture list
        el             expr list
        il             init list
        sl             stmt list
        it             init target = VAR, LET (default=LET)
        ie             init expr
        se             set expr

        initexpr       init it (fl,el) il
        letexpr        let (fl,el) el
        block          (fl,el) sl

      

        Bindings

        var x = y      [x], init VAR () [x=y]
        var [x] = y    [x], init VAR ([t0],[init t0=y]) [x=t0[0]]

        let (x=y) ...  let ([x], init x=y) ...
        let x=y             [x], init x=y]

        Assignments

        x = y          [],  set x=y
        [x] = y        [],  let ([t0],[init t0=y]) [set x=t0[0]]

        Blocks

        { }            () {}
        {stmt}         () {stmt}
        {let x}        ([x],[x=undef]) {}       is undef the right val?
        let (x) {}     ([x],[x=undef]) {}       what about reping uninit?

        Mixture

        { var x = y; let z = y }  =>
            ([x],[]) { blkstmt ([z],[]) { init VAR () x=y; init LET () z=y } }


        assignment, create a let for each aggregate, a temp for
        each level of nesting

        x = y              set x=y
        [x] = y            let (t0=y) set x=t0[0]
        [[x]] = y          let (t0=y) let (t1=t0[0]) set x=t1[0]
        [[x],[x]] = y      let (t0=y) let (t1=t0[0]) set x=t1[0]
                                    , let (t1=t0[1]) set x=t1[0]
        
        initialization, create an init rather than a set for the
        leaf nodes

        var x = v            let (t0=v) init () [x=t0]
        var [x] = v          let (t0=v) init () [x=t0[0]]
        var [x,[y,z]] = v    let (t0=v) init () [x=t0[0]]
                                      , let (t1=t0[1]) init () [y=t1[0], z=t1[1]]
        var [x,[y,[z]]] = v  let (t0=v) init () [x=t0[0]]
                                      , let (t1=t0[1]) init () [y=t1[0]
                                                     , let (t2=t1[0]) init () [z=t2[0]]

        for initialization, we need to know the namespace and the target 
        so we make INITS to go into the InitExpr inside the LetExpr

        let x = y          init x=y

        flattening.

        var [x,[y,z]] = v  let (t0=v) init () [x=t0[0]]
                                    , let (t1=t0[1]) init () [y=t1[0], z=t1[0]]

                           t0=v
                           x=t0[0]
                           t1=t0[1]
                           y=t1[0]
                           z=t1[1]
        head = {[t0,x,t1,y,z],

        flattening doesn't work because it mixes named and temporary
        fixtures

        lets and params have the same problem. both allow destructuring
        patterns that can expand into a nested expression.

        let ([x,[y,z]]=v) ...

        top heads only have named fixtures. sub heads only have temporaries.
        temporaries are always immediately initialized. a head is a list of
        fixtures and a list of expressions. the expressions get evaluated
        in the scope outside the head.

        settings is a sub head. it has temporary fixtures and init exprs that
        target instance variables

        */

        function desugarAssignmentPattern (p: PATTERN, t: Ast::TYPE_EXPR, e: Ast::EXPR, op: Ast::ASSIGNOP)
            : [Ast::FIXTURES, Ast::EXPR]
            desugarPattern (p,t,e,null,null,null,op);

        function desugarBindingPattern (p: PATTERN, t: Ast::TYPE_EXPR, e: Ast::EXPR,
                                        ns: Ast::NAMESPACE?, it: Ast::INIT_TARGET?, ro: boolean?)
            : [Ast::FIXTURES, Ast::EXPR]
            desugarPattern (p,t,e,ns,it,ro,null);

        function desugarPattern (p: PATTERN, t: Ast::TYPE_EXPR, e: Ast::EXPR,
                                 ns: Ast::NAMESPACE?, it: Ast::INIT_TARGET?, ro: boolean?, op: Ast::ASSIGNOP?)
            : [Ast::FIXTURES, Ast::EXPR]
        {
            return desugarSubPattern (p,t,e,0);

            function identExprFromExpr (e: Ast::EXPR) 
                : Ast::IDENT_EXPR {
                switch type (e) {
                case (e: Ast::LexicalRef) {
                    var ie = e.Ast::ident;
                }
                case (e: *) {
                    Parse::syntaxError(this, "Invalid initializer left-hand-side " + e);
                }
                }
                return ie;
            }

            function desugarSubPattern (p: PATTERN, t: Ast::TYPE_EXPR, e: Ast::EXPR, n: int) 
                : [Ast::FIXTURES, Ast::EXPR]
            {
                switch type (p) : PATTERN {
                case (p:IdentifierPattern) {
                    let nm = new Ast::PropName ({ns:ns,id:p.ident});
                    let fx = new Ast::ValFixture (t,ro);
                    var fxtrs = [[nm,fx]];
                    if (e !== null) {
                        var inits = [[nm,e]];
                    }
                    else {
                        var inits = [];
                    }
                    var expr = new Ast::InitExpr (it, new Ast::Head ([],[]), inits);
                }
                case (p:SimplePattern) {
                    if (e === null) 
                        Parse::syntaxError(this, "Simple pattern without initializer");
                    var fxtrs = [];
                    if (it != null) { // we have an init target so must be an init
                        var ie = identExprFromExpr (p.expr);
                        var nm = cx.resolveIdentExpr (ie,it);
                        var expr = new Ast::InitExpr (it, new Ast::Head ([],[]), [[nm,e]]);
                    }
                    else {
                        var expr = new Ast::SetExpr (op,p.expr,e);
                    }
                }
                //case (p: (ArrayPattern, ObjectPattern)) {
                case (p: *) {
                    let tn = new Ast::TempName (n);
                    var fxtrs = [];
                    let exprs = [];
                    let ptrns = p.ptrns;
                    for (let i=0; i<ptrns.length; ++i) {
                        let sub = ptrns[i];
                        /// switch type (sub) {
                        /// case (sub: FieldPattern) {
                        if (sub is FieldPattern) {
                            var typ = new Ast::FieldTypeRef (t,sub.ident);
                            var exp = new Ast::ObjectRef (new Ast::GetTemp (n), sub.ident);
                            var ptn = sub.ptrn;
                        }
                        /// case (pat: *) {
                        else {
                            var typ = new Ast::ElementTypeRef (t,i);
                            var exp = new Ast::ObjectRef (new Ast::GetTemp (n), makeIdentifier (i,[[Ast::noNS]]));
                                      // FIXME what is the ns of a temp and how do we refer it
                            var ptn = sub;
                        }
                        /// }

                        let [fx,ex] = desugarSubPattern (ptn,typ,exp,n+1);
                        for (let j=0; j<fx.length; ++j) fxtrs.push(fx[j]);
                        exprs.push(ex);
                    }
                    let head = new Ast::Head ([[tn,new Ast::ValFixture (Ast::anyType,false)]],
                                              [new Ast::InitExpr (Ast::letInit,new Ast::Head([],[]),[[tn,e]])]);
                    var expr = new Ast::LetExpr (head, new Ast::ListExpr (exprs));
                }
                }
                return [fxtrs,expr];
            }
        }

        // Parse rountines

        /*

        Identifier
            Identifier
            call
            debugger
            dynamic
            each
            final
            get
            goto
            include
            namespace
            native
            override
            prototype
            set
            static
            type
            xml

        */

        // The performance of this is probably OK because Token::Identifier is the first case,
        // and will be the one hit almost always.  But if the code generator starts getting
        // smart and generates a binary lookup tree here then it might be better to separate
        // that test out.  That won't be a problem on tamarin-central, but tamarin-tracing may
        // discover that the tokens are all const-bound and so do something about it.
        //
        // (Another matter is that the code perhaps ought to be auto-generated by the same 
        // code that generates the keyword lookup code in the lexer.  I'm not sure.)

        public function identifier () : Ast::IDENT {
            var str = "";   // fixme: evaluator isn't happy if this is inside of the switch

            switch (hd ()) {
            case Token::Identifier:
            case Token::Call:
            case Token::Cast:
            case Token::Const:
            case Token::Decimal:
            case Token::Double:
            case Token::Dynamic:
            case Token::Each:
            case Token::Eval:
            case Token::Final:
            case Token::Get:
            case Token::Has:
            case Token::Implements:
            case Token::Import:
            case Token::Int:
            case Token::Interface:
            case Token::Internal:
            case Token::Intrinsic:
            case Token::Is:
            case Token::Let:
            case Token::Namespace:
            case Token::Native:
            case Token::Number:
            case Token::Override:
            case Token::Package:
            case Token::Precision:
            case Token::Private:
            case Token::Protected:
            case Token::Prototype:
            case Token::Public:
            case Token::Rounding:
            case Token::Standard:
            case Token::Strict:
            case Token::Set:
            case Token::Static:
            case Token::To:
            case Token::Type:
            case Token::UInt:
            case Token::Undefined:
            case Token::Use:
            case Token::Xml:
            case Token::Yield:
                var str = lexeme ();
                next ();
                break;
            default:
                Parse::syntaxError(this, "Expecting identifier, found " + lexeme () );
            }
            return str;
        }

        function isReserved (tk: int) {
            switch (tk) {
            case Token::Break:
                break;
            // FIXME more of these
            default:
                return false;
                break;
            }
            return true;
        }

        // Commented out because reservedOrOrdinaryIdentifier() is never called.
        /*
        function reservedOrOrdinaryIdentifier () : Ast::IDENT {
            var name;

            if (isReserved (hd ())) 
            {
                name = lexeme();
                next();
            }
            else 
                name = identifier();

            return name;
        }
        */

        /*
            Qualifier
                *
                ReservedNamespace
                Identifier
        */

        function qualifier() : (Ast::IDENT, Ast::NAMESPACE) {
            var qual;

            switch (hd()) {
            case Token::Internal:
            case Token::Intrinsic:
            case Token::Private:
            case Token::Protected:
            case Token::Public:
                qual = reservedNamespace();
                break;
            case Token::Mult:
                qual = lexeme ();
                next ();
                break;
            default:
                qual = identifier ();
                break;
            }

            return qual;
        }

        /*
            ReservedNamespace
                internal
                intrinsic
                private
                protected
                public
        */

        function reservedNamespace () : Ast::NAMESPACE {
            var ns = null;

            switch (hd ()) {
            case Token::Internal:
                ns = new Ast::InternalNamespace (currentPackageName);
                break;
            case Token::Public:
                ns = new Ast::PublicNamespace (currentPackageName);
                break;
            case Token::Intrinsic:
                ns = new Ast::IntrinsicNamespace;
                break;
            case Token::Private:
                ns = new Ast::PrivateNamespace (currentClassName);
                break;
            case Token::Protected:
                ns = new Ast::ProtectedNamespace (currentClassName);
                break;
            }
            if (ns != null)
                next();

            return ns;
        }

        /*
          QualifiedNameIdentifier
              *
              Identifier
              ReservedIdentifier
              String
              Number
              Brackets
        */

        function qualifiedNameIdentifier (qual: Ast::EXPR) : Ast::IDENT_EXPR {
            var id = null;

            switch (hd()) {
            case Token::Mult:
                id = "*";
                next();
                break;
            case Token::StringLiteral:
            case Token::DecimalLiteral:
                id = lexeme ();
                next();
                break;
            case Token::LeftBracket:
                id = brackets ();
                break;
            default:
                id = identifier ();
                break;
            }

            return new Ast::QualifiedIdentifier (qual,id);
        }

        /*
          SimpleQualifiedName
              Identifier
              Qualifier  ::  QualifiedNameIdentifier
        */

        function simpleQualifiedName () : Ast::IDENT_EXPR {
            var qual = qualifier ();
            var name = null;

            switch (hd ()) {
            case Token::DoubleColon:
                switch type (qual) {
                case (id:String) {
                    qual = new Ast::LexicalRef (makeIdentifier (qual,cx.pragmas.openNamespaces))
                }
                case (ns:*) {
                    qual = new Ast::LiteralExpr (new Ast::LiteralNamespace (qual), position());
                }
                }
                next();
                name = qualifiedNameIdentifier (qual);
                break;

            default:
                switch type (qual) {
                case (id:String) {
                    name = makeIdentifier (qual,cx.pragmas.openNamespaces);
                }
                case (ns:*) {
                    name = new Ast::ReservedNamespace (qual);
                }
                }
                break;
            }

            return name;
        }

        /*
            ExpressionQualifiedName
                ParenListExpression :: QualifiedName
        */

        /*
            NonAttributeQualifiedIdentifier
                SimpleQualifiedName
                ExpressionQualifiedName
        */

        function nonAttributeQualifiedName () : Ast::IDENT_EXPR {
            var name = null;

            switch (hd ()) {
            case Token::LeftParen:
                name = expressionQualifiedIdentifier ();
                break;
            default:
                name = simpleQualifiedName ();
                break;
            }

            return name;
        }

        /*
            AttributeQualifiedIdentifier
                @ Brackets
                @ NonAttributeQualifiedIdentifier
        */

        /*
            QualifiedName
                AttributeName
                NonAttributeQualifiedName
        */

        function qualifiedName () : Ast::IDENT_EXPR {
            var name = null;

            switch (hd ()) {
            case Token::LeftParen:
                name = expressionQualifiedIdentifier ();
                break;
            default:
                name = simpleQualifiedName ();
            }

            return nd1;
        }

        /*
            PropertyName
                NonAttributeQualifiedName
                NonAttributeQualifiedName  .<  TypeExpressionList  >
                (  TypeExpression  )  .<  TypeExpressionList  >

            e.g.
                A.<B.<C.<t>,D.<u>>>
        */

        function propertyName () : Ast::IDENT_EXPR {
            var name = null;

            switch (hd ()) {
/*  FIXME: this is a grammar bug
            case Token::LeftParen:
                var [ts1,nd1] = typeExpression (tl (ts));
                ts1 = eat (ts1,Token::RightParen);
                break;
*/
            default:
                name = nonAttributeQualifiedName ();
            }

            if (hd () === Token::LeftDotAngle) {
                eat (Token::LeftDotAngle);
                name = typeExpressionList ();
                switch (hd ()) {
                case Token::UnsignedRightShift:
                    // downgrade >>> to >> to eat one >
                    replace (Token::RightShift);
                    break;
                case Token::RightShift:
                    // downgrade >> to > to eat one >
                    replace (Token::GreaterThan);
                    break;
                default:
                    eat (Token::GreaterThan);
                    break;
                }
            }

            return name;
        }

        /*
            PrimaryName
                Path  .  PropertyName
                PropertyName
        */

        function primaryName () : Ast::IDENT_EXPR {
            var name = null;

            if (hd() === Token::Identifier && hd2() === Token::Dot) {
                let tx = lexeme ();
                next();
                next();
                var nd1 = path ([tx]);
                var nd2 = propertyName ();
                name = new Ast::UnresolvedPath (nd1,nd2);
            }
            else
                name = propertyName ();

            return name;
        }

        /*
            Path
                Identifier
                Path  .  Identifier
        */

        function path (nd /*: [Ast::IDENT]*/ ) /* FIXME: verifier bug */ : [Ast::IDENT] {
            var newpath = null;

            if (hd() === Token::Identifier && hd2() === Token::Dot) {
                nd.push( lexeme() );
                next();
                next();
                newpath = path (nd);
            }
            else
                newpath = nd;

            return newpath;
        }

        function parenExpression () : Ast::EXPR {
            eat (Token::LeftParen);
            var expr = assignmentExpression (allowIn);
            eat (Token::RightParen);

            return expr;
        }

        function parenListExpression () : Ast::EXPR {
            eat (Token::LeftParen);
            var expr = listExpression (allowIn);
            eat (Token::RightParen);

            return expr;
        }

        /*

        ObjectLiteral(noColon)
            {  FieldList  }

        ObjectLiteral(allowColon)
            {  FieldList  }
            {  FieldList  }  :  TypeExpression

        */

        function objectLiteral (/*, alpha: ALPHA*/) : Ast::TYPE_EXPR {
            var alpha: ALPHA = allowColon;    // FIXME need to get this from caller
            var pos = position();             // Record source location of initial left brace
            eat (Token::LeftBrace);
            var fields = fieldList ();
            eat (Token::RightBrace);

            switch (alpha) {
            case allowColon:
                switch (hd ()) {
                case Token::Colon:
                    next();
                    var texpr = typeExpression ();
                    break;
                default:
                    var texpr = new Ast::ObjectType ([]); // FIXME I mean {*}
                    break;
                }
                break;
            default:
                var texpr = new Ast::ObjectType ([]); // FIXME I mean {*}
                break;
            }

            return new Ast::LiteralExpr (new Ast::LiteralObject (fields,texpr), pos);
        }

        /*

        FieldList
            empty
            LiteralField
            LiteralField  ,  LiteralFieldList

        */

        function fieldList () /* : [Ast::FIELD_TYPE] */ {
            var fields = [];

            if (hd () !== Token::RightBrace) {
                var field = literalField ();
                fields.push (field);
                while (hd () === Token::Comma) {
                    next();
                    var field = literalField ();
                    fields.push (field);
                }
            }

            return fields;
        }

        /*

          LiteralField
              FieldKind  FieldName  :  AssignmentExpressionallowColon, allowIn
              get  FieldName  FunctionSignature  FunctionExpressionBodyallowColon, allowIn
              set  FieldName  FunctionSignature  FunctionExpressionBodyallowColon, allowIn

        */

        function literalField () : Ast::FIELD_TYPE {
            var tag;

            switch (hd ()) {
            case Token::Const:
                next();
                tag = constTag;
                break;
            default:
                tag = Ast::varTag;
                break;
            }

            var fn = fieldName ();
            eat (Token::Colon);

            var expr;

            switch (hd ()) {
            case Token::LeftBrace:   // short cut to avoid recursion
                expr = objectLiteral ();
                break;
            case Token::LeftBracket:
                expr = arrayLiteral ();
                break;
            default:
                expr = assignmentExpression (allowIn);
                break;
            }

            return new Ast::LiteralField (tag,fn,expr);
        }

        /*

        FieldName
            NonAttributeQualifiedName
            StringLiteral
            NumberLiteral
            ReservedIdentifier

        */

        function fieldName () : Ast::IDENT_EXPR {
            var name;

            switch (hd ()) {
            case Token::StringLiteral:
                name = makeIdentifier (lexeme(), cx.pragmas.openNamespaces);
                next();
                break;
            case Token::DecimalLiteral:
            case Token::DecimalIntegerLiteral:
            case Token::HexIntegerLiteral:
                Parse::internalError(this, "Unsupported fieldName " + hd());
                break;
            default:
                if (isReserved (hd ())) {
                    name = makeIdentifier (lexeme(), cx.pragmas.openNamespaces);
                    next();
                    // NOTE we use openNamespaces here to indicate that the name is 
                    //      unqualified. the generator should use the expando namespace,
                    //      which is probably Public "".
                }
                else
                    name = nonAttributeQualifiedName ();
                break;
            }

            return name;
        }

        /*

        ArrayLiteral(noColon)
            [  Elements  ]
        
        ArrayLiteral(allowColon)
            [  Elements  ]
            [  Elements  ]  :  TypeExpression
        
        Elements
            ElementList
            ElementComprehension

        */

        function arrayLiteral () : Ast::EXPR {
            var pos = position();   // Record source location of initial left bracket
            eat (Token::LeftBracket);
            var elts = elementList ();
            eat (Token::RightBracket);

            return new Ast::LiteralExpr (new Ast::LiteralArray (elts, new Ast::ArrayType ([])), 
                                         pos);
        }

        /*

        ElementList
            empty
            LiteralElement
            ,  ElementList
             LiteralElement  ,  ElementList

        LiteralElement
            AssignmentExpression(allowColon,allowIn)

        */

        function elementList () : Ast::EXPR {
            var elts = [];
            var elt;

            if (hd () !== Token::RightBracket) 
            {
                switch (hd ()) {
                case Token::Comma:
                    let pos = position();
                    next();
                    elt = new Ast::LiteralExpr (new Ast::LiteralUndefined, pos);
                    break;
                default:
                    switch (hd ()) {
                    case Token::LeftBrace:
                        elt = objectLiteral ();
                        break;
                    case Token::LeftBracket:
                        elt = arrayLiteral ();
                        break;
                    default:
                        elt = assignmentExpression (allowIn);
                        break;
                    }
                    break;
                }
                elts.push (elt);
                while (hd () === Token::Comma) {
                    eat (Token::Comma);
                    switch (hd ()) {
                    case Token::Comma:
                        elt = new Ast::LiteralExpr (new Ast::LiteralUndefined, position());
                        break;
                    case Token::RightBracket:
                        continue;  // we're done
                    default:
                        switch (hd ()) {
                        case Token::LeftBrace:
                            elt = objectLiteral ();
                            break;
                        case Token::LeftBracket:
                            elt = arrayLiteral ();
                            break;
                        default:
                            elt = assignmentExpression (allowIn);
                            break;
                        }
                        break;
                    }
                    elts.push (elt);
                }
            }

            return elts;
        }

        /*

        PrimaryExpression
            null
            true
            false
            NumberLiteral
            StringLiteral
            this
            RegularExpression
            XMLInitialiser
            ParenListExpression
            ArrayLiteral
            ObjectLiteral
            FunctionExpressionb
            AttributeIdentifier
            PrimaryIdentifier
        */

        function primaryExpression(beta:BETA) : Ast::EXPR {
            var expr;

            var pos = position();   // Record the source location before consuming the token
            switch (hd ()) {
            case Token::Null:
                next();
                expr = new Ast::LiteralExpr (new Ast::LiteralNull (), pos);
                break;
            case Token::True:
                next();
                expr = new Ast::LiteralExpr (new Ast::LiteralBoolean (true), pos);
                break;
            case Token::False:
                next();
                expr = new Ast::LiteralExpr (new Ast::LiteralBoolean (false), pos);
                break;
            case Token::DecimalLiteral:
                let tx = lexeme();

                // This is all bogus.  All this should be handled in
                // the lexer, and the lexer should only return
                // DecimalLiteral if the literal is supposed to
                // encoded as an ES4 'decimal'.

                // FIXME.  The AVM2 can't handle decimal literals yet.

                let n = 0;
                if (tx.charAt(0) == "0") {
                    if (tx.charAt(1) == "x" || tx.charAt(1) == "X")
                        n = parseInt(tx);
                    else
                        n = parseInt(tx, 8);
                }
                else
                    n = parseFloat(tx);
                let lit = null;
                if (Math.floor(n) === n) {
                    if (n >= -0x80000000 && n <= 0x7FFFFFFF)
                        lit = new Ast::LiteralInt(int(n));
                    else if (n >= 0x80000000 && n <= 0xFFFFFFFF)
                        lit = new Ast::LiteralUInt(uint(n));
                }
                if (lit == null)
                    lit = new Ast::LiteralDouble(n);

                next();
                expr = new Ast::LiteralExpr (lit, pos);
                break;
            case Token::StringLiteral:
                let tx = lexeme();
                next();
                expr = new Ast::LiteralExpr (new Ast::LiteralString (tx), pos);
                break;
            case Token::This:
                next();
                expr = new Ast::ThisExpr ();
                break;
//            else
//            if( lookahead(regexpliteral_token) )
//            {
//                var result = <LiteralRegExp value={scan.tokenText(match(regexpliteral_token))}/>
//            }
//            else
//            if( lookahead(function_token) )
//            {
//                match(function_token);
//                var first = null
//                if( lookahead(identifier_token) )
//                {
//                    first = parseIdentifier();
//                }
//                var result = parseFunctionCommon(first);
//            }
            case Token::LeftParen:
                expr = parenListExpression();
                break;
            case Token::LeftBracket:
                expr = arrayLiteral ();
                break;
            case Token::LeftBrace:
                expr = objectLiteral ();
                break;
            case Token::Function:
                expr = functionExpression ();
                break;
            default:
                expr = primaryName ();
                switch type (expr) {
                case (nd: Ast::UnresolvedPath) {
                    base = resolvePath (nd.Ast::path, null);
                    expr = new Ast::ObjectRef (base, nd.Ast::ident);  // FIXME: not good for package qualified refs
                }
                case (nd:*) {
                    expr = new Ast::LexicalRef (expr, pos);
                }
                }
                break;
            }

            return expr;
        }

        function resolvePath (path /*: [Ast::IDENT]*/, expr: Ast::EXPR)
            resolveObjectPath (path, expr);

        function resolveObjectPath (path /*: [Ast::IDENT]*/, expr: Ast::EXPR) : Ast::EXPR {
            if (path.length === 0)
                return expr;

            var base;
            if (expr === null) 
                base = new Ast::LexicalRef (makeIdentifier (path[0],cx.pragmas.openNamespaces));
            else 
                base = new Ast::ObjectRef (expr, makeIdentifier (path[0],cx.pragmas.openNamespaces));
            return resolveObjectPath (path.slice (1, path.length), base);
        }

        /*

        SuperExpression
            super
            super  Arguments

        */


        /*

        PropertyOperator
            .  ReservedIdentifier
            .  PropertyName
            .  AttributeName
            ..  QualifiedName
            .  ParenListExpression
            .  ParenListExpression  ::  QualifiedNameIdentifier
            Brackets

        */

        function propertyOperator (nd: Ast::EXPR) : [Ast::EXPR] {
            var propref;

            switch (hd ()) {
            case Token::Dot:
                switch (hd2 ()) {
                case Token::LeftParen:
                    Parse::internalError(this, "Filter operator not implemented");
                    break;
                default:
                    //                    if (isReservedIdentifier (hd (ts))) {
                    //                    }
                    next();
                    let propname = propertyName ();
                    propref = new Ast::ObjectRef (nd,propname);
                    break;
                }
                break;
            case Token::LeftBracket:
                next();
                let index = listExpression (allowIn);
                eat (Token::RightBracket);
                propref = new Ast::ObjectRef (nd,new Ast::ExpressionIdentifier (index,cx.pragmas.openNamespaces));
                break;
            case Token::DoubleDot:
                Parse::internalError(this, "descendents operator not implemented");
                break;
            default:
                Parse::internalError("propertyOperator");
                break;
            }

            return propref;
        }

        /*

        Arguments
            (  )
            (  ArgumentList  )

        ArgumentList
            AssignmentExpression(allowIn)
            ArgumentList  ,  AssignmentExpression(allowIn)

        */

        function argumentList () : * /*[Ast::EXPR]*/ {
            var args;

            eat (Token::LeftParen);
            switch (hd ()) {
            case Token::RightParen:
                eat (Token::RightParen);
                args = [];
                break;
            default:
                let nd2 = listExpression (allowIn);
                eat (Token::RightParen);
                args = nd2.Ast::exprs;
                break;
            }

            return args;
        }

        /*

        MemberExpression(beta)
            PrimaryExpression(beta)
            new  MemberExpression(beta)  Arguments
            SuperExpression  PropertyOperator
            MemberExpression(beta)  PropertyOperator

        Refactored:

        MemberExpression(beta)
            PrimaryExpression(beta) MemberExpressionPrime(beta)
            new MemberExpression(beta) Arguments MemberExpressionPrime(beta)
            SuperExpression  PropertyOperator  MemberExpressionPrime(beta)

        MemberExpressionPrime(beta)
            PropertyOperator MemberExpressionPrime(beta)
            empty

        Note: member expressions always have balanced new and (). The LHS parser is
        responsible for dispatching extra 'new' or '()' to 

        */

        function memberExpression (beta:BETA) : Ast::EXPR {
            var expr;

            switch (hd ()) {
            case Token::New:
                next();
                let nd1 = memberExpression (beta);
                let nd2 = this.argumentList ();
                expr = memberExpressionPrime (beta, new Ast::NewExpr (nd1,nd2));
                break;
            case Token::Super:
                let nd1 = superExpression ();
                let nd2 = propertyOperator (nd1);
                expr = memberExpressionPrime (beta, nd2);
            default:
                let nd1 = primaryExpression (beta);
                expr = memberExpressionPrime (beta, nd1);
                break;
            }

            return expr;
        }

        function memberExpressionPrime (beta:BETA, nd: Ast::EXPR) : Ast::EXPR {
            var expr;

            switch (hd ()) {
            case Token::LeftBracket:
            case Token::Dot:
            case Token::DoubleDot:
                let nd1 = propertyOperator (nd);
                expr = memberExpressionPrime (beta, nd1);
                break;
            default:
                expr = nd;
                break;
            }

            return expr;
        }

        /*

        CallExpression(beta)
            MemberExpression(beta) Arguments CallExpressionPrime(beta) 

        CallExpressionPrime(beta)
            Arguments CallExpressionPrime(beta)
            [ Expression ] CallExpressionPrime(beta)
            . Identifier CallExpressionPrime(beta)
            empty

        */

        function callExpression (beta:BETA) : Ast::EXPR {
            var pos = position();
            var nd1 = memberExpression (beta);
            var nd2 = this.argumentList ();
            var expr = callExpressionPrime (beta, new Ast::CallExpr (nd1,nd2,pos));

            return expr;
        }

        function callExpressionPrime (beta:BETA, nd: Ast::EXPR) : Ast::EXPR {
            var expr;

            switch (hd ()) {
            case Token::LeftParen:
                let pos = position();
                let nd1 = this.argumentList ();
                expr = callExpressionPrime (beta, new Ast::CallExpr (nd,nd1,pos));
                break;
            case Token::LeftBracket:
            case Token::Dot:
            case Token::DoubleDot:
                let nd1 = propertyOperator (nd);
                expr = callExpressionPrime (beta, nd1);
                break;
            default:
                expr = nd;
                break;
            }

            return expr;
        }

        /*

        NewExpression
            MemberExpression
            new  NewExpression

        */

        function newExpression (beta:BETA, new_count=0) : Ast::EXPR {
            var expr;

            switch (hd ()) {
            case Token::New:
                next();
                let nd1 = newExpression (beta, new_count+1);
                switch (hd ()) {
                case Token::LeftParen:           // no more new exprs so this paren must start a call expr
                    let pos = position();
                    let nd2 = this.argumentList (); // refer to parser method
                    if (new_count == 0)
                        expr = callExpressionPrime (beta,new Ast::CallExpr (nd1,nd2,pos));
                    else
                        expr = new Ast::NewExpr (nd1,nd2);
                    break;
                default:
                    if (new_count == 0)
                        expr = memberExpressionPrime (beta,nd1);
                    else
                        expr = new Ast::NewExpr (nd1,[]);
                    break;
                }
                break;

            default:
                let nd1 = memberExpression (beta);
                switch (hd ()) {
                case Token::LeftParen:
                    let pos = position();
                    let nd2 = this.argumentList (); // refer to parser method
                    if( new_count == 0 )
                        expr = callExpressionPrime (beta,new Ast::CallExpr (nd1,nd2,pos));
                    else
                        expr = new Ast::NewExpr (nd1,nd2);
                    break;
                default:
                    if( new_count == 0 ) 
                        expr = nd1;
                    else 
                        expr = new Ast::NewExpr (nd1,[]);
                    break;
                }
                break;
            }

            return expr;
        }

        /*

        LeftHandSideExpression
            NewExpression
            CallExpression

        Refactored:

        LeftHandSideExpression
            NewExpression
            MemberExpression Arguments CallExpressionPrime
            MemberExpression

        */

        function leftHandSideExpression (beta:BETA) : Ast::EXPR {
            var expr;

            switch (hd ()) {
            case Token::New:
                var nd1 = newExpression (beta,0);
                switch (hd ()) {
                case Token::LeftParen:
                    let pos = position();
                    let nd2 = this.argumentList (); // refer to parser method
                    expr = callExpressionPrime (beta, new Ast::CallExpr (nd1,nd2,pos));
                    break;
                default:
                    expr = nd1;
                    break;
                }
                break;
            default:
                let nd1 = memberExpression (beta);
                switch (hd ()) {
                case Token::LeftParen:
                    let pos = position();
                    let nd2 = this.argumentList (); // refer to parser method
                    expr = callExpressionPrime (beta, new Ast::CallExpr (nd1,nd2,pos));
                    break;
                default:
                    expr = nd1;
                    break;
                }
                break;
            }

            return expr;
        }

        /*

        PostfixExpression(beta)
            LeftHandSideExpression(beta)
            LeftHandSideExpression(beta)  [no line break]  ++
            LeftHandSideExpression(beta)  [no line break]  --

        */

        function postfixExpression (beta:BETA) : Ast::EXPR {
            var expr;

            let nd1 = leftHandSideExpression (beta);
            switch (hd ()) {
            case Token::PlusPlus:
                next();
                expr = new Ast::UnaryExpr (Ast::postIncrOp,nd1);
                break;
            case Token::MinusMinus:
                next();
                expr = new Ast::UnaryExpr (Ast::postDecrOp,nd1);
                break;
            default:
                expr = nd1;
                break;
            }

            return expr;
        }

        /*

        UnaryExpression(beta)
            PostfixExpression(beta)
            delete  PostfixExpression(beta)
            void  UnaryExpression(beta)
            typeof  UnaryExpression(beta)
            ++   PostfixExpression(beta)
            --  PostfixExpression(beta)
            +  UnaryExpression(beta)
            -  UnaryExpression(beta)
            ~  UnaryExpression(beta)
            !  UnaryExpression(beta)
            type  NullableTypeExpression

        */

        function unaryExpression (beta: BETA) : Ast::EXPR {
            var expr;

            switch (hd ()) {
            case Token::Delete:
                next();
                let nd1 = postfixExpression (beta);
                expr = new Ast::UnaryExpr (Ast::deleteOp,nd1);
                break;
            case Token::Void:
                next();
                let nd1 = unaryExpression (beta);
                expr = new Ast::UnaryExpr (Ast::voidOp,nd1);
                break;
            case Token::TypeOf:
                next();
                let nd1 = unaryExpression (beta);
                expr = new Ast::UnaryExpr (Ast::typeOfOp,nd1);
                break;
            case Token::PlusPlus:
                next();
                let nd1 = postfixExpression (beta);
                expr = new Ast::UnaryExpr (Ast::preIncrOp,nd1);
                break;
            case Token::MinusMinus:
                next();
                let nd1 = postfixExpression (beta);
                expr = new Ast::UnaryExpr (Ast::preDecrOp,nd1);
                break;
            case Token::Plus:
                next();
                let nd1 = unaryExpression (beta);
                expr = new Ast::UnaryExpr (Ast::unaryPlusOp,nd1);
                break;
            case Token::Minus:
                next();
                let nd1 = unaryExpression (beta);
                expr = new Ast::UnaryExpr (Ast::unaryMinusOp,nd1);
                break;
            case Token::BitwiseNot:
                next();
                let nd1 = unaryExpression (beta);
                expr = new Ast::UnaryExpr (Ast::bitwiseNotOp,nd1);
                break;
            case Token::Not:
                next();
                let nd1 = unaryExpression (beta);
                expr = new Ast::UnaryExpr (Ast::logicalNotOp,nd1);
                break;
            case Token::Type:
                next();
                let nd1 = nullableTypeExpression (beta);
                expr = new Ast::TypeExpr (nd1);
                break;
            default:
                expr = postfixExpression (beta);
                break;
            }

            return expr;
        }

        /*

        MultiplicativeExpression
            UnaryExpression
            MultiplicativeExpression  *  UnaryExpression
            MultiplicativeExpression  /  UnaryExpression
            MultiplicativeExpression  %  UnaryExpression

        */

        function multiplicativeExpression (beta:BETA) : Ast::EXPR {
            var nd1 = unaryExpression (beta);

            done:
            while (true) {
                if (hd () === Token::BREAK) 
                    div();

                var op;
                switch (hd ()) {
                case Token::Mult:
                    op = Ast::timesOp;
                    break;
                case Token::Div:
                    op = Ast::divideOp;
                    break;
                case Token::Remainder:
                    op = Ast::remainderOp;
                    break;
                default:
                    break done;
                }

                next();
                let nd2 = unaryExpression (beta);
                nd1 = new Ast::BinaryExpr (op, nd1, nd2);
            }

            return nd1;
        }

        /*

        AdditiveExpression
            MultiplicativeExpression
            AdditiveExpression + MultiplicativeExpression
            AdditiveExpression - MultiplicativeExpression

        */

        function additiveExpression (beta: BETA) : Ast::EXPR {
            var nd1 = multiplicativeExpression (beta);

            done:
            while (true) {
                var op;
                switch (hd ()) {
                case Token::Plus:
                    op = Ast::plusOp;
                    break;
                case Token::Minus:
                    op = Ast::minusOp;
                    break;
                default:
                    break done;
                }

                next();
                let nd2 = multiplicativeExpression (beta);
                nd1 = new Ast::BinaryExpr (op, nd1, nd2);
            }

            return nd1;
        }

        /*

        ShiftExpression
            AdditiveExpression
            ShiftExpression << AdditiveExpression
            ShiftExpression >> AdditiveExpression
            ShiftExpression >>> AdditiveExpression

        */

        function shiftExpression (beta: BETA) : Ast::EXPR {
            var nd1 = additiveExpression (beta);
            
            done:
            while (true) {
                switch (hd ()) {
                case Token::LeftShift:
                    var op = Ast::leftShiftOp;
                    break;
                case Token::RightShift:
                    var op = Ast::rightShiftOp;
                    break;
                case Token::UnsignedRightShift:
                    var op = Ast::rightShiftUnsignedOp;
                    break;
                default:
                    break done;
                }

                next();
                let nd2 = additiveExpression (beta);
                var nd1 = new Ast::BinaryExpr (op, nd1, nd2);
            }

            return nd1;
        }

        /*

        RelationalExpression(noIn)
            ShiftExpression(noIn)
            RelationalExpression(noIn) < ShiftExpression(noIn)
            RelationalExpression(noIn) > ShiftExpression(noIn)
            RelationalExpression(noIn) <= ShiftExpression(noIn)
            RelationalExpression(noIn) >= ShiftExpression(noIn)
            RelationalExpression(noIn) instanceof ShiftExpression(noIn)
            RelationalExpression(noIn) is TypeExpression
            RelationalExpression(noIn) to TypeExpression
            RelationalExpression(noIn) cast TypeExpression

        RelationalExpression(allowIn)
            ShiftExpression(allowIn)
            RelationalExpression(allowIn) < ShiftExpression(allowIn)
            RelationalExpression(allowIn) > ShiftExpression(allowIn)
            RelationalExpression(allowIn) <= ShiftExpression(allowIn)
            RelationalExpression(allowIn) >= ShiftExpression(allowIn)
            RelationalExpression(allowIn) in ShiftExpression(allowIn)
            RelationalExpression(allowIn) instanceof ShiftExpression(allowIn)
            RelationalExpression(allowIn) is TypeExpression
            RelationalExpression(allowIn) to TypeExpression
            RelationalExpression(allowIn) cast TypeExpression

        */

        function relationalExpression (beta: BETA) : Ast::EXPR {
            var nd1 = shiftExpression (beta);

            done:
            while (true) {
                switch (hd ()) {
                case Token::LessThan:
                    next();
                    var nd2 = shiftExpression (beta);
                    nd2 = new Ast::BinaryExpr (Ast::lessOp,nd1,nd2);
                    break;
                case Token::GreaterThan:
                    next();
                    var nd2 = shiftExpression (beta);
                    nd2 = new Ast::BinaryExpr (Ast::greaterOp,nd1,nd2);
                    break;
                case Token::LessThanOrEqual:
                    next();
                    var nd2 = shiftExpression (beta);
                    nd2 = new Ast::BinaryExpr (Ast::lessOrEqualOp,nd1,nd2);
                    break;
                case Token::GreaterThanOrEqual:
                    next();
                    var nd2 = shiftExpression (beta);
                    nd2 = new Ast::BinaryExpr (Ast::greaterOrEqualOp,nd1,nd2);
                    break;
                case Token::In:
                    if (beta == noIn)
                        break done;
                    next();
                    var nd2 = shiftExpression (beta);
                    nd2 = new Ast::BinaryExpr (Ast::inOp,nd1,nd2);
                    break;
                case Token::InstanceOf:
                    next();
                    var nd2 = shiftExpression (beta);
                    nd2 = new Ast::BinaryExpr (Ast::instanceOfOp,nd1,nd2);
                    break;
                case Token::Is:
                    next();
                    var nd2 = typeExpression ();
                    nd2 = new Ast::BinaryTypeExpr (Ast::isOp,nd1,nd2);
                    break;
                case Token::To:
                    next();
                    var nd2 = typeExpression ();
                    nd2 = new Ast::BinaryTypeExpr (Ast::toOp,nd1,nd2);
                    break;
                case Token::Cast:
                    next();
                    var nd2 = typeExpression ();
                    nd2 = new Ast::BinaryTypeExpr (Ast::castOp,nd1,nd2);
                    break;
                default:
                    break done;
                }

                var nd1 = nd2;
            }

            return nd1;
        }

        /*

        EqualityExpression(beta)
            RelationalExpression(beta)
            EqualityExpression(beta) == RelationalExpression(beta)
            EqualityExpression(beta) != RelationalExpression(beta)
            EqualityExpression(beta) === RelationalExpression(beta)
            EqualityExpression(beta) !== RelationalExpression(beta)

        */

        function equalityExpression (beta: BETA) : Ast::EXPR {
            var nd1 = relationalExpression (beta);

            done:
            while (true) {
                var op;
                switch (hd ()) {
                case Token::Equal:
                    op = Ast::equalOp;
                    break;
                case Token::NotEqual:
                    op = Ast::notEqualOp;
                    break;
                case Token::StrictEqual:
                    op = Ast::strictEqualOp;
                    break;
                case Token::StrictNotEqual:
                    op = Ast::strictNotEqualOp;
                    break;
                default:
                    break done;
                }

                next();
                let nd2 = relationalExpression (beta);
                var nd1 = new Ast::BinaryExpr (op, nd1, nd2);
            }

            return nd1;
        }

        /*

        BitwiseAndExpression(beta)
            EqualityExpression(beta)
            BitwiseAndExpressionr(beta) & EqualityExpression(beta)

        */

        function bitwiseAndExpression (beta: BETA) : Ast::EXPR {
            var nd1 = equalityExpression (beta);

            while (hd () === Token::BitwiseAnd) {
                next();
                var nd2 = equalityExpression (beta);
                var nd1 = new Ast::BinaryExpr (Ast::bitwiseAndOp, nd1, nd2);
            }

            return nd1;
        }

        /*

        BitwiseXorExpressionb
            BitwiseAndExpressionb
            BitwiseXorExpressionb ^ BitwiseAndExpressionb

        */

        function bitwiseXorExpression (beta: BETA) : Ast::EXPR {
            var nd1 = bitwiseAndExpression (beta);

            while (hd () === Token::BitwiseXor) {
                next();
                var nd2 = bitwiseAndExpression (beta);
                var nd1 = new Ast::BinaryExpr (Ast::bitwiseXorOp, nd1, nd2);
            }

            return nd1;
        }

        /*

        BitwiseOrExpression(beta)
            BitwiseXorExpression(beta)
            BitwiseOrExpression(beta) | BitwiseXorExpression(beta)

        */

        function bitwiseOrExpression (beta: BETA) : Ast::EXPR {
            var nd1 = bitwiseXorExpression (beta);

            while (hd () === Token::BitwiseOr) {
                next();
                var nd2 = bitwiseXorExpression (beta);
                var nd1 = new Ast::BinaryExpr (Ast::bitwiseOrOp, nd1, nd2);
            }

            return nd1;
        }

        /*

        LogicalAndExpression(beta)
            BitwiseOrExpression(beta)
            LogicalAndExpression(beta) && BitwiseOrExpression(beta)

        */

        function logicalAndExpression (beta: BETA) : Ast::EXPR {
            var nd1 = bitwiseOrExpression (beta);

            while (hd () === Token::LogicalAnd) {
                next();
                var nd2 = bitwiseOrExpression (beta);
                var nd1 = new Ast::BinaryExpr (Ast::logicalAndOp, nd1, nd2);
            }

            return nd1;
        }

        /*

        LogicalXorExpressionb
            LogicalAndExpressionb
            LogicalXorExpressionb ^^ LogicalAndExpressionb

        */

        function logicalXorExpression (beta: BETA) : Ast::EXPR {
            var nd1 = logicalAndExpression (beta);

            while (hd () === Token::LogicalXor) {
                next();
                var nd2 = logicalAndExpression (beta);
                var nd1 = new Ast::BinaryExpr (Ast::logicalXor, nd1, nd2);
            }

            return nd1;
        }

        /*

            LogicalOrExpression(beta)
                LogicalXorExpression(beta)
                LogicalOrExpression(AllowIn) || LogicalXorExpression(beta)

        */

        function logicalOrExpression (beta: BETA) : Ast::EXPR {
            var nd1 = logicalXorExpression (beta);

            while (hd () === Token::LogicalOr) {
                next();
                var nd2 = logicalXorExpression (beta);
                var nd1 = new Ast::BinaryExpr (Ast::logicalOrOp, nd1, nd2);
            }

            return nd1;
        }

        /*

        YieldExpression
            UnaryExpression
            yield  UnaryExpression

        */


        /*

        NonAssignmentExpressiona, b
            LetExpressiona, b
            YieldExpressiona, b
            LogicalOrExpressiona, b
            LogicalOrExpressiona, b  ?  NonAssignmentExpressiona, b  
                                                    :  NonAssignmentExpressiona, b

        */

        function nonAssignmentExpression (beta: BETA) : Ast::EXPR {
            var expr;

            switch (hd ()) {
            case Token::Let:
                expr = letExpression (beta);
                break;
            case Token::Yield:
                expr = yieldExpression (beta);
                break;
            default:
                expr = logicalOrExpression (beta);
                switch (hd ()) {
                case Token::QuestionMark:
                    next();
                    var nd2 = nonAssignmentExpression (beta);
                    eat (Token::Colon);
                    var nd3 = nonAssignmentExpression (beta);
                    expr = new Ast::TernaryExpr (expr,nd2,nd3);
                    break;
                default:
                    break;
                }
                break;
            }

            return expr;
        }

        /*

        ConditionalExpression(beta)
            LetExpression(beta)
            YieldExpression(beta)
            LogicalOrExpression(beta)
            LogicalOrExpression(beta)  ?  AssignmentExpression(beta)
                                       :  AssignmentExpression(beta)

        */

        function conditionalExpression (beta: BETA) : Ast::EXPR {
            var expr;

            switch (hd ()) {
            case Token::Let:
                expr = letExpression (beta);
                break;
            case Token::Yield:
                expr = yieldExpression (beta);
                break;
            default:
                expr = logicalOrExpression (beta);
                switch (hd ()) {
                case Token::QuestionMark:
                    next();
                    var nd2 = assignmentExpression (beta);
                    eat (Token::Colon);
                    var nd3 = assignmentExpression (beta);
                    expr = new Ast::TernaryExpr (expr,nd2,nd3);
                    break;
                default:
                    break;
                }
            }

            return expr
        }

        /*

        AssignmentExpression(beta)
            ConditionalExpression(beta)
            Pattern(beta, allowExpr)  =  AssignmentExpression(beta)
            SimplePattern(beta, allowExpr)  CompoundAssignmentOperator  AssignmentExpression(beta)

        */

        function assignmentExpression (beta: BETA) : Ast::EXPR {
            var op = null;
            var nd1 = conditionalExpression (beta);
            switch (hd ()) {
            case Token::Assign:
                next();
                var nd1 = patternFromExpr (nd1);
                var nd2 = assignmentExpression (beta);
                var [fxtrs,expr,head] = desugarAssignmentPattern (nd1,Ast::anyType,nd2,Ast::assignOp);
                break;
            case Token::PlusAssign: 
                var expr = operateAndAssign(nd1, Ast::assignPlusOp);
                break;
            case Token::MinusAssign:
                var expr = operateAndAssign(nd1, Ast::assignMinusOp);
                break;
            case Token::MultAssign:
                var expr = operateAndAssign(nd1, Ast::assignTimesOp);
                break;
            case Token::DivAssign:
                var expr = operateAndAssign(nd1, Ast::assignDivideOp);
                break;
            case Token::RemainderAssign:
                var expr = operateAndAssign(nd1, Ast::assignRemainderOp);
                break;
            case Token::BitwiseAndAssign:
                var expr = operateAndAssign(nd1, Ast::assignBitwiseAndOp);
                break;
            case Token::BitwiseOrAssign:
                var expr = operateAndAssign(nd1, Ast::assignBitwiseOrOp);
                break;
            case Token::BitwiseXorAssign:
                var expr = operateAndAssign(nd1, Ast::assignBitwiseXorOp);
                break;
            case Token::LeftShiftAssign:
                var expr = operateAndAssign(nd1, Ast::assignLeftShiftOp);
                break;
            case Token::RightShiftAssign:
                var expr = operateAndAssign(nd1, Ast::assignRightShiftOp);
                break;
            case Token::UnsignedRightShiftAssign:
                var expr = operateAndAssign(nd1, Ast::assignRightShiftUnsignedOp);
                break;
            case Token::LogicalAndAssign: 
                // ES4
                var expr = operateAndAssign(nd1, Ast::assignLogicalAndOp);
                break;
            case Token::LogicalOrAssign:
                // ES4
                var expr = operateAndAssign(nd1, Ast::assignLogicalOrOp);
                break;
            default:
                var expr = nd1;
                break;
            }

            return expr;

            function operateAndAssign(nd1, op) : Ast::EXPR {
                next();
                var nd2 = patternFromExpr (nd1);
                if (!(nd2 is SimplePattern))
                    Parse::internalError(this, "operandAndAssign, lhs should be SimplePattern");
                var nd3 = assignmentExpression (beta);
                var [fxtrs,expr,head] = desugarAssignmentPattern (nd2,Ast::anyType,nd3,op);
                return expr;
            }

            // expression to pattern converters

            function patternFromExpr (e: Ast::EXPR) {
                switch type (e) {
                case (e: Ast::LiteralExpr) {
                    switch type (e.Ast::literal) {
                    case (l: Ast::LiteralArray) {
                        var p = arrayPatternFromLiteral (l);
                    }
                    case (l: Ast::LiteralObject) {
                        var p = objectPatternFromLiteral (l);
                    }
                    case (l: *) {
                        Parse::syntaxError(this, "Invalid lhs expr " + e);
                    }
                    }
                }
                case (e: Ast::LexicalRef) {
                    var p = new SimplePattern (e);
                }
                case (e: Ast::ObjectRef) {
                    var p = new SimplePattern (e);
                }
                case (e: *) {
                    Parse::internalError(this, "patternFromExpr, unhandled expression kind " + e);
                }
                }
                return p;
            }

            function arrayPatternFromLiteral (nd: Ast::LITERAL) : PATTERN {
                var nd1 = elementListPatternFromLiteral (nd.Ast::exprs);
                
                return new ArrayPattern (nd1);
            }

            function elementListPatternFromLiteral (nd: Ast::EXPRS) : PATTERNS {
                var nd1 = [];
                
                for (let i=0; i<nd.length; ++i) {
                    var ndx = patternFromExpr (nd[i]);
                    nd1.push (ndx);
                }
                
                return nd1;
            }
                    
            function objectPatternFromLiteral (l: Ast::LITERAL) : PATTERN {
                switch type (l) {
                case (nd: Ast::LiteralObject) {
                    var p = fieldListPatternFromLiteral (nd.Ast::fields);
                }
                case (nd: *) {
                    Parse::syntaxError(this, "objectPatternFromLiteral " + nd);
                }
                }
                        
                return new ObjectPattern (p);
            }
                    
            function fieldListPatternFromLiteral (nd: Ast::LITERAL_FIELDS) : FIELD_PATTERNS {
                var nd1 = [];
                
                for (let i=0; i<nd.length; ++i) {
                    var ndx = fieldPatternFromLiteral (nd[i]);
                    nd1.push (ndx);
                }
                
                return nd1;
            }
                    
            function fieldPatternFromLiteral (nd: Ast::LITERAL_FIELD) : FIELD_PATTERN {
                var nd1 = nd.Ast::ident;
                var nd2 = patternFromExpr (nd.Ast::expr);
                
                return new FieldPattern (nd1,nd2);
            }
        }

        /*

        ListExpression(b)
            AssignmentExpression(b)
            ListExpression(b)  ,  AssignmentExpression(b)

        right recursive:

        ListExpression(b)
            AssignmentExpression(b) ListExpressionPrime(b)

        ListExpressionPrime(b)
            empty
            , AssignmentExpression(b) ListExpressionPrime(b)

        */

        function listExpression (beta: BETA) : Ast::EXPR {
            var nd1 = assignmentExpression (beta);
            var nd2 = listExpressionPrime ();
            nd2.unshift (nd1);

            return new Ast::ListExpr (nd2);

            function listExpressionPrime () : Ast::EXPR {
                switch (hd ()) {
                case Token::Comma:
                    next();
                    var nd1 = assignmentExpression (beta);
                    var nd2 = listExpressionPrime ();
                    nd2.unshift (nd1);
                    break;
                default:
                    var nd2 = [];
                    break;
                }

                return nd2;
            }
        }

//        /*
//
//        LetExpressionb
//            let  (  LetBindingList  )  AssignmentExpressionb
//
//        LetBindingList
//            empty
//            NonemptyLetBindingList
//
//        NonemptyLetBindingList
//            VariableBinding
//            VariableBinding , NonemptyLetBindingList
//
//        */
//
//        function parseLetExpression(mode)
//        {
//            enter("parseLetExpression")
//
//            var prologue = <Prologue/>
//            match(let_token)
//            match(leftparen_token)
//            if( lookahead(rightparen_token) )
//            {
//                var first = <></>
//            }
//            else
//            {
//                var first = <></>
//                first += parseVariableBinding(<Attributes><Let/></Attributes>,var_token,allowIn_mode,prologue)
//                while( lookahead(comma_token) )
//                {
//                    match(comma_token)
//                    first += parseVariableBinding(<Attributes><Let/></Attributes>,var_token,allowIn_mode,prologue)
//                }
//                prologue.* += first
//            }
//            match(rightparen_token)
//            var second = parseAssignmentExpression(mode)
//            var result = <LetExpression>{prologue}{second}</LetExpression>
//
//            exit("parseLetExpression",result)
//            return result
//        }
//
//        /*
//
//        YieldExpressionb
//            yield  AssignmentExpressionb
//
//        */
//
///*
//        function parseYieldExpression(mode)
//        {
//            enter("parseYieldExpression")
//
//            exit("parseYieldExpression",result)
//            return result
//        }
//*/

        // PATTERNS

        /*

          Pattern(beta,gamma)
              SimplePattern(beta,gamma)
              ObjectPattern(gamma)
              ArrayPattern(gamma)

        */

        function pattern (beta: BETA, gamma: GAMMA) : PATTERN {
            switch (hd ()) {
            case Token::LeftBrace:
                var nd1 = objectPattern (gamma);
                break;
            case Token::LeftBracket:
                var nd1 = arrayPattern (gamma);
                break;
            default:
                var nd1 = simplePattern (beta, gamma);
                break;
            }

            return nd1;
        }

        /*

          SimplePattern(beta, noExpr)
              Identifier

          SimplePattern(beta, allowExpr)
              LeftHandSideExpression(beta)

          */

        function simplePattern (beta: BETA, gamma: GAMMA) : PATTERN {
            switch (gamma) {
            case noExpr:
                let nd1 = identifier ();
                var ndx = new IdentifierPattern (nd1);
                break;
            case allowExpr:
                let nd1 = leftHandSideExpression (beta);
                var ndx = new SimplePattern (nd1);
                break;
            }

            return ndx;
        }

        /*

        ArrayPattern(gamma)
            [  ElementListPattern(gamma)  ]
        
        */

        function arrayPattern (gamma: GAMMA) : Ast::EXPR {
            eat (Token::LeftBracket);
            var nd1 = elementListPattern (gamma);
            eat (Token::RightBracket);

            return new ArrayPattern (nd1);
        }

        /*

        ElementListPattern(gamma)
            empty
            LiteralElementPattern
            ,  ElementListPattern
             LiteralElementPattern  ,  ElementListPattern

        LiteralElementPattern
            Pattern(allowColon,allowIn,gamma)

        */

        function elementListPattern (gamma:GAMMA) : Ast::EXPRS {
            var elements = [], element;

            if (hd () !== Token::RightBracket) {
                switch (hd ()) {
                case Token::Comma:
                    let pos = position();
                    eat(Token::Comma);
                    element = new Ast::LiteralExpr (new Ast::LiteralUndefined, pos);
                    break;
                default:
                    element = pattern (allowIn,gamma);
                    break;
                }
                elements.push (element);
                while (hd () === Token::Comma) {
                    eat (Token::Comma);
                    switch (hd ()) {
                    case Token::Comma:
                        element = new Ast::LiteralExpr (new Ast::LiteralUndefined, position());
                        break;
                    default:
                        element = pattern (allowIn,gamma);
                        break;
                    }
                    elements.push (element);
                }
            }

            return elements;
        }

        /*

        ObjectPattern(gamma)
            [  FieldListPattern(gamma)  ]
        
        */

        function objectPattern (gamma: GAMMA) : Ast::EXPR {
            eat (Token::LeftBrace);
            var nd1 = fieldListPattern (gamma);
            eat (Token::RightBrace);

            return new ObjectPattern (nd1); 
        }

        /*

        FieldListPattern(gamma)
            empty
            FieldPattern
            FieldPattern  ,  FieldListPattern

        FieldPattern
            FieldName
            FieldName  :  Pattern(allowColon,allowIn,gamma)

        */

        function fieldListPattern (gamma:GAMMA) : Ast::EXPR {
            var nd1 = [];

            if (hd () !== Token::RightBrace) 
            {
                var ndx = fieldPattern (gamma);
                nd1.push (ndx);
                while (hd () === Token::Comma) {
                    eat (Token::Comma);
                    var ndx = fieldPattern (gamma);
                    nd1.push (ndx);
                }
            }

            return nd1;
        }

        function fieldPattern (gamma:GAMMA) : FIELD_PATTERN {
            var nd1 = fieldName ();
            switch (hd ()) {
            case Token::Colon:
                next();
                var nd2 = pattern (allowIn,gamma);
                break;
            default:
                switch type (nd1) {
                case (nd1: Ast::Identifier) {
                    var nd2 = new IdentifierPattern (nd1.Ast::ident);
                }
                case (nd1:*) {
                    Parse::internalError(this, "unsupported fieldPattern " + nd1);
                }
                }
                break;
            }

            return new FieldPattern (nd1,nd2);
        }

        /*

          TypedIdentifier(beta)
              SimplePattern(beta, noExpr)
              SimplePattern(beta, noExpr)  :  NullableTypeExpression

          TypedPattern(beta)
              Pattern(beta, noExpr)
              Pattern(beta, noExpr)  :  NullableTypeExpression

        */

        function typedPattern (beta: BETA) : [PATTERN,Ast::TYPE_EXPR] {
            var nd1 = pattern (beta,noExpr);
            switch (hd ()) {
            case Token::Colon:
                next();
                var nd2 = nullableTypeExpression ();
                break;
            default:
                var nd2 = Ast::anyType;
                break;
            }

            return [nd1,nd2];
        }

        // TYPE EXPRESSIONS

        /*

        NullableTypeExpression
            TypeExpression
            TypeExpression  ?
            TypeExpression  !

        */

        function nullableTypeExpression () : Ast::TYPE_EXPR {
            var nd1 = typeExpression ();
            switch (hd ()) {
            case Token::QuestionMark:
                next();
                var nd1 = new Ast::NullableType (nd1,true);
                break;
            case Token::Not:
                next();
                var nd1 = new Ast::NullableType (nd1,false);
                break;
            default:
                // do nothing
                break;
            }

            return nd1;
        }

        /*

        TypeExpression
            null
            undefined
            FunctionType
            UnionType
            RecordType
            ArrayType
            PrimaryName

        */

        function typeExpression () : Ast::TYPE_EXPR {
            switch (hd ()) {
            case Token::Mult:
                next();
                var nd1 = Ast::anyType;
                break;
            case Token::Null:
                next();
                var nd1 = Ast::nullType;
                break;
            case Token::Undefined:
                next();
                var nd1 = Ast::undefinedType;
                break;
            case Token::Function:
                var nd1 = functionType ();
                break;
            case Token::LeftParen:
                var nd1 = unionType ();
                break;
            case Token::LeftBrace:
                var nd1 = objectType ();
                break;
            case Token::LeftBracket:
                var nd1 = arrayType ();
                break;
            default:
                var nd1 = primaryName ();
                nd1 = new Ast::TypeName (nd1);
                break;
            }

            return nd1;
        }

        /*

        UnionType
            (  TypeExpressionList  )

        */

        function unionType () : Ast::TYPE_EXPR {
            eat (Token::LeftParen);
            var nd1 = typeExpressionList ();
            eat (Token::RightParen);

            return new Ast::UnionType (nd1);
        }

        /*

        ObjectType
            {  FieldTypeTypeList  }

        */

        function objectType () : Ast::TYPE_EXPR {
            eat (Token::LeftBrace);
            var nd1 = fieldTypeList ();
            eat (Token::RightBrace);

            return new Ast::ObjectType (nd1);
        }

        /*

        FieldTypeList
            empty
            NonemptyFieldTypeList

        NonemptyFieldTypeList
            FieldType
            FieldType  ,  NonemptyFieldTypeList

        */

        function fieldTypeList () /* : [Ast::FIELD_TYPE] */ {
            var nd1 = [];

            if (hd () !== Token::RightBrace) {
                var ndx = fieldType ();
                nd1.push (ndx);
                while (hd () === Token::Comma) {
                    next();
                    var ndx = fieldType ();
                    nd1.push (ndx);
                }
            }

            return nd1;
        }

        function fieldType () : Ast::FIELD_TYPE {
            var nd1 = fieldName ();
            eat (Token::Colon);
            var nd2 = nullableTypeExpression ();
        }

        /*

        ArrayType
            [  ElementTypeList  ]

        ElementTypeList
            empty
            NullableTypeExpression
            ,  ElementTypeList
            NullableTypeExpression  ,  ElementTypeList

        */

        function arrayType () : Ast::TYPE_EXPR {
            eat (Token::LeftBracket);
            var nd1 = elementTypeList ();
            eat (Token::RightBracket);

            return new Ast::ArrayType (nd1);
        }

        function elementTypeList () /* : [Ast::ELEMENT_TYPE] */ {
            var nd1 = [];

            if (hd () !== Token::RightBracket) {
                switch (hd ()) {
                case Token::Comma:
                    let pos = position();
                    eat(Token::Comma);
                    var ndx = new Ast::LiteralExpr (new Ast::LiteralUndefined, position());
                    break;
                default:
                    var ndx = nullableTypeExpression ();
                    break;
                }
                nd1.push (ndx);
                while (hd () === Token::Comma) {
                    eat (Token::Comma);
                    switch (hd ()) {
                    case Token::Comma:
                        var ndx = new Ast::LiteralExpr (new Ast::LiteralUndefined, position());
                        break;
                    default:
                        var ndx = nullableTypeExpression ();
                        break;
                    }
                    nd1.push (ndx);
                }
            }

            return nd1;
        }

        /*

        TypeExpressionList
            NullableTypeExpression
            TypeExpressionList  ,  NullableTypeExpression

        refactored

        TypeExpressionList
            NullableTypeExpression  TypeExpressionListPrime

        TypeExpressionListPrime
            empty
            ,  NullableTypeExpression  TypeExpressionListPrime

        */

        function typeExpressionList () /* : [Ast::TYPE_EXPR] */ {
            var nd1 = [];
            var ndx = nullableTypeExpression ();
            nd1.push (ndx);
            while (hd () === Token::Comma) {
                next();
                var ndx = nullableTypeExpression ();
                nd1.push (ndx);
            }

            return nd1;
        }

        // STATEMENTS

        /*

        Statement(tau, omega)
            BlockStatement(tau)
            BreakStatement Semicolon(omega)
            ContinueStatement Semicolon(omega)
            DefaultXMLNamespaceStatement Semicolon(omega)
            DoStatement Semicolon(omega)
            ExpressionStatement Semicolon(omega)
            ForStatement(omega)
            IfStatement(omega)
            LabeledStatement(omega)
            LetStatement(omega)
            ReturnStatement Semicolon(omega)
            SwitchStatement
            ThrowStatement Semicolon(omega)
            TryStatement
            WhileStatement(omega)
            WithStatement(omega)

        */

        function statement (tau: TAU, omega: OMEGA) : Ast::STMT {
            var stmt;

            switch (hd()) {
            case Token::If:
                stmt = ifStatement (omega);
                break;
            case Token::While:
                stmt = whileStatement (omega);
                break;
            case Token::For:
                stmt = forStatement (omega);
                break;
            case Token::Do:
                stmt = doStatement (omega);
                semicolon(omega);
                break;
            case Token::Return:
                stmt = returnStatement ();
                semicolon (omega);
                break;
            case Token::Break:
                stmt = breakStatement ();
                semicolon (omega);
                break;
            case Token::Continue:
                stmt = continueStatement ();
                semicolon (omega);
                break;
            case Token::LeftBrace:
                stmt = new Ast::BlockStmt ( block (tau) );
                break;
            case Token::Switch:
                if (hd2 () === Token::Type)
                    stmt = switchTypeStatement ();
                else
                    stmt = switchStatement ();
                break;
            case Token::Throw:
                stmt = throwStatement ();
                semicolon (omega);
                break;
            case Token::Try:
                stmt = tryStatement ();
                break;
            case Token::With:
                stmt = withStatement (omega);
                break;
            default:
                if (hd () == Token::Identifier && hd2 () == Token::Colon)
                    stmt = labeledStatement ();
                else {
                    stmt = expressionStatement ();
                    semicolon (omega);
                }
                break;
            }

            return stmt
        }

        function substatement (omega: OMEGA) : Ast::STMT {
            switch (hd()) {
            case Token::SemiColon:
                next();
                var nd1 = new Ast::EmptyStmt;
                break;
            default:
                var nd1 = statement (localBlk,omega);
                break;
            }

            return nd1;
        }

        function semicolon (omega: OMEGA) {
            switch (omega) {
            case fullStmt:
                switch (hd ()) {
                case Token::SemiColon:
                    next();
                    return;
                case Token::EOS:
                case Token::RightBrace:
                    // Inserting it
                    return;
                default:
                    if (!newline ())
                        Parse::syntaxError(this, "Expecting semicolon");
                    // Inserting it
                    return;
                }

            case abbrevStmt:  // Abbrev, ShortIf
                switch (hd ()) {
                case Token::SemiColon:
                    next();
                    return;
                default:
                    // Inserting it
                    return;
                }

            default:
                Parse::internalError(this, "Unhandled statement mode " + omega);
            }
        }

        function labeledStatement () : Ast::STMT {
            var label = identifier ();
            eat(Token::Colon);
            var stmt = substatement(FullStmt);

            addLabel(label, stmt);
            return new Ast::LabeledStmt(label, stmt);

            function addLabel(label, stmt) {
                use namespace Ast;

                switch type (stmt) {
                case (x0: LabeledStmt) {
                    addLabel(label, x0.stmt);
                }
                case (x1: ForInStmt) {
                    x1.labels.push(label);
                }
                case (x2: WhileStmt) {
                    x2.labels.push(label);
                }
                case (x3: DoWhileStmt) {
                    x3.labels.push(label);
                }
                case (x4: ForStmt) {
                    x4.labels.push(label);
                }
                case (x:*) {
                    // Label is not propagated
                }
                }
            }
        }

        function expressionStatement () : Ast::STMT
            new Ast::ExprStmt (listExpression (allowIn));

        function returnStatement () : Ast::STMT {
            eat (Token::Return);

            var expr;

            switch (hd ()) {
            case Token::EOS:
            case Token::SemiColon:
            case Token::RightBrace:
                expr = null;
                break;

            default:
                if (newline())
                    expr = null;
                else
                    expr = listExpression (allowIn);
                break;
            }

            return new Ast::ReturnStmt (expr);
        }

        function breakStatement () : Ast::STMT
            new Ast::BreakStmt( breakOrContinueLabel(Token::Break) );

        function continueStatement () : Ast::STMT
            new Ast::ContinueStmt( breakOrContinueLabel(Token::Continue) );

        function breakOrContinueLabel(tok) {
            eat (tok);
            switch (hd ()) {
            case Token::SemiColon:
                next();
                return null;

            case Token::EOS:
            case Token::RightBrace:
                return null;

            default:
                if (newline())
                    return null;

                return identifier ();
            }
        }

        function ifStatement (omega) : Ast::STMT {
            var test=null, consequent=null, alternate=null;

            eat (Token::If);
            test = parenListExpression ();
            consequent = substatement (omega);
            if ( hd () === Token::Else) {
                eat (Token::Else);
                alternate  = substatement (omega);
            }

            return new Ast::IfStmt (test, consequent, alternate);
        }

        /*

        WhileStatement(omega)
            while ParenListExpression Substatement(omega)

        */

        function whileStatement (omega) : Ast::STMT {
            eat (Token::While);
            var test = parenListExpression ();
            var body = substatement (omega); 
 
            return new Ast::WhileStmt (test, body);
        }

        /*

        DoStatement(omega)
            do Substatement(omega) while expr

        */

        function doStatement (omega) : Ast::STMT {
            eat (Token::Do);
            var body = substatement (omega); 
            eat(Token::While);
            var test = parenListExpression ();
 
            return new Ast::DoWhileStmt (test,body); // same order of args to constructor as 'while'
        }

        /*

            ForStatement(omega)
                for  (  ForInitialiser  ;  OptionalExpression  ;  OptionalExpression  )  Substatement(omega)
                for  (  ForInBinding  in  ListExpression(allowColon, allowIn)  )  Substatement(omega)
                for  each  ( ForInBinding  in  ListExpression(allowColon, allowIn)  )  Substatement(omega)
            
        */

        function forStatement (omega: OMEGA) : Ast::STMT {
            cx.enterLetBlock ();

            var is_each = false;
            
            eat (Token::For);
            if( hd() == Token::Each )
            {
                eat(Token::Each);
                is_each = true;
            }
            eat (Token::LeftParen);
            var init = forInitialiser ();
            if (hd () == Token::In) {
                eat (Token::In);
                var objexpr = listExpression (allowIn);
                eat (Token::RightParen);
                var body = substatement (omega); 
                
                var head = cx.exitLetBlock ();
                
                return new Ast::ForInStmt (head,init,objexpr,body,is_each);
            }
            else {
                if (is_each)
                    Parse::syntaxError(this, "'for each' requires 'in' style loop");
                eat (Token::SemiColon);
                var test = optionalExpression ();
                eat (Token::SemiColon);
                var update = optionalExpression ();
                eat (Token::RightParen);
                var body = substatement (omega); 
                
                var head = cx.exitLetBlock ();
                
                return new Ast::ForStmt (head,init,test,update,body);
            }
        }

        /*

            ForInitialiser
                empty
                ListExpression(allowColon, noIn)
                VariableDefinition(noIn)
            
            ForInBinding
                Pattern(allowColon, noIn, allowExpr)
                VariableDefinitionKind VariableBinding(noIn)

        */

        function forInitialiser () : Ast::EXPR? {
            var init = null;
            switch (hd ()) {
            case Token::SemiColon:
                break;

            case Token::Const:
            case Token::Let:
            case Token::Var:
                init = variableDefinition (noIn,localBlk,cx.pragmas.defaultNamespace,false,false);
                //assert (nd1.length==1);
                switch type (init[0]) {
                case (nd:Ast::ExprStmt) { 
                    init = nd.Ast::expr;
                }
                case (nd:*) { 
                    Parse::syntaxError(this, "forInitialiser " + nd);
                }
                }
                break;
            default:
                init = listExpression (noIn);
                break;
            }
 
            return init;
        }

        /*

        OptionalExpression
            empty
            ListExpression(allowColon, allowIn)

        */

        function optionalExpression () : Ast::EXPR? {
            var expr = null;

            switch (hd ()) {
            case Token::SemiColon:
            case Token::RightParen:
                break;

            default:
                expr = listExpression (noIn);
                break;
            }
 
            return expr;
        }

        /*

        SwitchStatement
            switch  ParenListExpression  {  CaseElements  }

        CaseElements
            empty
            CaseLabel
            CaseLabel  CaseElementsPrefix  CaseLabel
            CaseLabel  CaseElementsPrefix  Directives(abbrev)

        CaseElementsPrefix
            empty
            CaseElementsPrefix  CaseLabel
            CaseElementsPrefix  Directives(full)

        right recursive:

        CaseElementsPrefix
            empty
            CaseLabel  CaseElementsPrefix
            Directives(full)  CaseElementsPrefix

        */

        function switchStatement () : Ast::STMT {
            var expr=null, cases=null;

            eat (Token::Switch);
            expr = parenListExpression ();

            eat (Token::LeftBrace);
            switch (hd ()) {
            case Token::Case:
            case Token::Default:
                cases = caseElementsPrefix ();
                break;
            default:
                // do nothing
                break;
            }
            eat (Token::RightBrace);

            return new Ast::SwitchStmt (expr, cases);
        }

        // FIXME: duplicate defaults could be handled here or in cogen, but
        // we must be sure to handle it.

        function caseElementsPrefix () : Ast::CASES {
            var nd1 = [];
            while (hd () !== Token::RightBrace) {
                switch (hd ()) {
                case Token::Case:
                case Token::Default:
                    var ndx = caseLabel ();
                    nd1.push (new Ast::Case (ndx,[]));
                    break;
                default:
                    var ndx = directive (localBlk,fullStmt);  // 'abbrev' is handled by RightBrace check in head
                    for (var i=0; i<ndx.length; ++i) 
                        nd1[nd1.length-1].Ast::stmts.push (ndx[i]);
                    break;
                }
            }

            return nd1;
        }

        /*

        CaseLabel
            case  ListExpression(allowColon,allowIn)
            default  :

        */

        function caseLabel () : Ast::EXPR? {
            var expr = null;

            switch (hd ()) {
            case Token::Case:
                next();
                expr = listExpression (allowIn);
                break;
            case Token::Default:
                next();
                break;
            default:
                Parse::syntaxError(this, "caseLabel expecting case");
            }
            eat (Token::Colon);

            return expr;
        }

        function throwStatement () : Ast::STMT {
            eat (Token::Throw);
            return new Ast::ThrowStmt( listExpression (allowIn) );
        }

        function tryStatement () : Ast::STMT {
            eat (Token::Try);

            var tryblock = block (localBlk);
            var catchblocks = catches ();
            var finallyblock = null;

            if ( hd () === Token::Finally ) {
                next();
                finallyblocks = block (localBlk);
            }

            return new Ast::TryStmt (tryblock,catchblocks,finallyblock);
        }

        function catches () : Ast::CATCHES {
            var catchblocks = [];

            while (hd () === Token::Catch) {
                next();
                catchblocks.push (catchClause ());
            }

            return catchblocks;
        }

        function catchClause () : Ast::CATCH {
            eat (Token::LeftParen);
            var catchvar = parameter ();
            eat (Token::RightParen);
            var catchblock = block (localBlk);

            var [k,[p,t]] = catchvar;
            var [f,i] = desugarBindingPattern (p, t, new Ast::GetParam (0), Ast::noNS, Ast::varInit, false);
            let head = new Ast::Head (f,[i]);

            return new Ast::Catch (head,catchblock);
        }

        /*

        WithStatement
            with ( expr ) stmt

        */

        function withStatement (omega: OMEGA) : Ast::STMT {
            // Only ES3-style with for now

            eat (Token::With);
            var expr = parenListExpression ();
            var body = substatement (omega);
            return new Ast::WithStmt (expr, body);
        }

        /*

        SwitchTypeStatement
            switch  type  TypedExpression {  TypeCaseElements }
        
        TypeCaseElements
            TypeCaseElement
            TypeCaseElements  TypeCaseElement
            
        TypeCaseElement
            case  (  TypedPattern(allowColon, allowIn)  )  Blocklocal

        */

        function switchTypeStatement () : Ast::STMT {
            eat (Token::Switch);
            eat (Token::Type);
            var expr  = typedExpression ();
            var [e,t] = expr;
            eat (Token::LeftBrace);
            var typecases = typeCases ();
            eat (Token::RightBrace);

            return new Ast::SwitchTypeStmt (e,t,typecases);
        }

        /*

        TypedExpression
            ParenListExpression
            ParenListExpression  :  NullableTypeExpression

        */

        function typedExpression () : [Ast::EXPR,Ast::TYPE_EXPR] {
            var expr = parenListExpression ();
            var texpr = null;
            switch (hd ()) {
            case Token::Colon:
                next();
                var texpr = nullableTypeExpression ();
                break;
            default:
                var texpr = Ast::anyType;
                break;
            }

            return [expr,texpr];
        }

        function typeCases () : Ast::CATCHES {
            var cases = [];

            while (hd () === Token::Case) {
                next();
                cases.push (catchClause () );
            }

            return cases;
        }

        // DEFINITIONS

        /*

        VariableDefinition(beta)
            VariableDefinitionKind  VariableBindingList(beta)


        returns a statement, a list of block fixtures and var fixtures. if the caller
        is a class then it checks the static attribute to know if the var fixtures are
        class fixtures or instance fixtures

        */

        function variableDefinition (beta: BETA, tau: TAU, ns, isPrototype, isStatic) : Ast::STMTS {
            let nd1 = variableDefinitionKind ();

            switch (nd1) {
            case Ast::letConstTag:
                var it = Ast::letInit;
                var ro = true;
                break;
            case Ast::letVarTag:
                var it = Ast::letInit;
                var ro = false;
                break;
            case Ast::constTag:
                var it = Ast::varInit;
                var ro = true;
                break;
            case Ast::varTag:
                var it = Ast::varInit;
                var ro = false;
                break;
            default:
                Parse::syntaxError(this, "variableDefinition kind " + nd1);
            }

            let nd2 = variableBindingList (beta, ns, it, ro);
            let [fxtrs,exprs] = nd2;

            switch (nd1) {
            case Ast::letConstTag:
            case Ast::letVarTag:
                cx.addLetFixtures (fxtrs);
                var stmts = [new Ast::ExprStmt (new Ast::ListExpr(exprs))];
                break;
            default:
                switch (tau) {
                case classBlk:
                    cx.addVarFixtures (fxtrs, isStatic);
                    cx.addVarInits (exprs, isStatic);  // FIXME these aren't inits, they are a kind of settings
                    var stmts = [];
                    break;
                default:
                    cx.addVarFixtures (fxtrs);
                    var stmts = [new Ast::ExprStmt (new Ast::ListExpr(exprs))];
                    break;
                }
            }

            return stmts;
        }

        /*

        VariableDefinitionKind
            const
            let
            let const
            var

        */

        function variableDefinitionKind () : Ast::VAR_DEFN_TAG {
            switch (hd ()) {
            case Token::Const:
                next();
                var ndx = Ast::constTag;
                break;
            case Token::Var:
                next();
                var ndx = Ast::varTag;
                break;
            case Token::Let:
                next();
                switch (hd2 ()) {
                case Token::Const:
                    next();
                    var ndx = Ast::letConstTag;
                    break;
                case Token::Function:
                    Parse::syntaxError(this, "variableDefinitionKind after let");
                    break;
                default:
                    var ndx = Ast::letVarTag;
                    break;
                }
                break;
            default:
                Parse::syntaxError(this, "variableDefinitionKind");
                break;
            }

            return ndx;
        }

        /*

        VariableBindingList(beta)
            VariableBinding(beta)
            VariableBindingList(beta)  ,  VariableBinding(beta)

        VariableBinding(beta)
            TypedIdentifier
            TypedPattern(noIn)  VariableInitialisation(beta)

        VariableInitialisation(beta)
            =  AssignmentExpression(beta)

        */

        function variableBindingList (beta: BETA, ns: Ast::NAMESPACE, it: Ast::INIT_TARGET, ro: boolean ) : [Ast::FIXTURES, Ast::EXPRS] {
            var nd1 = variableBinding (beta);
            var nd2 = variableBindingListPrime ();

            var [f1,i1] = nd1;  // FIXME: fold into patterns above when it works in the RI
            var [f2,i2] = nd2;

            // FIXME: use concat when it works in the RI
            for (let i=0; i<f2.length; ++i)
                f1.push (f2[i]);

            for (let i=0; i<i2.length; ++i)
                i1.push (i2[i]);

            return [f1,i1];

            function variableBindingListPrime () : [Ast::FIXTURES, Ast::EXPRS] {
                switch (hd ()) {
                case Token::Comma:
                    next();
                    var nd1 = variableBinding (beta);
                    var nd2 = variableBindingListPrime ();

                    var [f1,i1] = nd1;  // FIXME: fold into patterns above when it works in the RI
                    var [f2,i2] = nd2;

                    for (let i=0; i<f2.length; ++i) f1.push (f2[i]);  // FIXME: use concat when it works in the RI
                    for (let i=0; i<i2.length; ++i) i1.push (i2[i]);
                    break;
                default:
                    var nd2 = [[],[]];
                    var [f1,i1] = nd2;
                    break;
                }

                return [f1,i1];
            }

            function variableBinding (beta: BETA) : [Ast::FIXTURES, Ast::EXPR] { // FIXME: this return type looks wrong
                let nd1 = typedPattern (beta);
                let [p,t] = nd1;
                switch (hd ()) {
                case Token::Assign:
                    next();
                    let nd2 = assignmentExpression (beta);
                    switch (hd ()) {
                    case Token::In:
                        if (beta === noIn) {
                            // in a binding form
                            if (p is IdentifierPattern) {
                                var [f,i] = desugarBindingPattern (p,t,nd2,ns,it,ro);
                            }
                            else
                                Parse::internalError(this, "Identifier pattern required by for-in binding (for now)");
                            break;
                        } // else fall through
                    default:
                        var [f,i] = desugarBindingPattern (p,t,nd2,ns,it,ro);
                        break;
                    }
                    break;
                default:
                    switch (hd ()) {
                    case Token::In:
                        if (beta === noIn) {
                            // in a binding form
                            if (p is IdentifierPattern) {
                                // This is actually wrong, because it may overwrite a hoisted var
                                // that should not be overwritten if the loop body is never entered
                                var [f,i] = desugarBindingPattern (p,t,new Ast::LiteralExpr(new Ast::LiteralUndefined),ns,it,ro);
                            }
                            else
                                Parse::internalError(this, "Identifier pattern required by for-in binding (for now)");
                            break;
                        } // else fall through
                    default:
                        switch type (p) {
                        case (p: IdentifierPattern) {
                            // See comment above
                            var [f,i] = desugarBindingPattern (p,t,new Ast::LiteralExpr(new Ast::LiteralUndefined),ns,it,ro);
                        }
                        case (x : *) {
                            Parse::syntaxError(this, "destructuring pattern without initializer");
                        }
                        }
                        break;
                    }
                }

                return [f,[i]];
            }
        }

        /*
        function variableBinding (ts: TOKENS, beta: BETA, ns: Ast::NAMESPACE, it: Ast::INIT_TARGET)
            : [TOKENS, [Ast::FIXTURES, Ast::EXPRS]]
        {
            enter("Parser::variableBinding ", ts);

            let [ts1,nd1] = typedPattern (ts,beta);
            let [p,t] = nd1;
            switch (hd (ts1)) {
            case Token::Assign:
                let [ts2,nd2] = assignmentExpression (tl (ts1), beta);
                switch (hd (ts2)) {
                case Token::In:
                    if (beta === noIn) {
                        // in a binding form
                        break;
                    } // else fall through
                default:
                    var [tsx,ndx] = [ts2,desugarBindingPattern (p,t,nd2,ns,it,ro)];
                    break;
                }
                break;
            default:
                switch (hd (ts1)) {
                case Token::In:
                    if (beta === noIn) {
                        // in a binding form
                        break;
                    } // else fall through
                default:
                    switch type (p) {
                    case (p: IdentifierPattern) {
                        var [tsx,ndx] = [ts1,desugarPattern (p,t,null,ns,it)];
                    }
                    case (x : *) {
                        Parse::syntaxError(this, "destructuring pattern without initializer");
                    }
                    }
                break;
                }
            }
            exit("Parser::variableBinding ", tsx);
            return [tsx,ndx];
        }
        */

        /*

        FunctionDefinition(class)
            function  ClassName  ConstructorSignature  FunctionBody(allowIn)
            function  FunctionName  FunctionSignature  FunctionBody(allowIn)
            
        FunctionDefinition(tau)
            function  FunctionName  FunctionSignature  FunctionBody(allowIn)
            let  function  FunctionName  FunctionSignature  FunctionBody(allowIn)
            const  function  FunctionName  FunctionSignature  FunctionBody(allowIn)

        */

        function functionDefinition (tau: TAU, omega: OMEGA, kind, ns, isFinal, isOverride, isPrototype, isStatic, isAbstract)
            : Ast::STMTS
        {
            eat (Token::Function);

            cx.enterFunction();

            var nd1 = functionName ();
            var nd2 = functionSignature ();

            cx.enterVarBlock ();
            var nd3 = functionBody (allowIn, omega);
            var vars = cx.exitVarBlock ();
            
            var attr = cx.exitFunction ();

            var {params:params,defaults:defaults,resultType:resultType,thisType:thisType,hasRest:hasRest,numparams:numparams} = nd2;
            var func = new Ast::Func (nd1,false,nd3,params,numparams,vars,defaults,resultType,attr);

            var name = new Ast::PropName ({ns:ns,id:nd1.ident});
            var fxtr = new Ast::MethodFixture (func,Ast::anyType,true,isOverride,isFinal);
            switch (tau) {
            case classBlk:
                cx.addVarFixtures ([[name,fxtr]], isStatic);
                break;
            default:
                cx.addVarFixtures ([[name,fxtr]]);
                break;
            }

            return [];
        }

        /* ... */
        function functionExpression () : Ast::EXPR {
            var name = null;

            cx.enterFunction();

            var pos = position();
            eat (Token::Function);
            if (hd () == Token::Identifier)
                name = functionName ();

            var signature = functionSignature ();

            cx.enterVarBlock ();
            var body = functionBody (AllowIn, FullStmt);
            var vars = cx.exitVarBlock ();

            var attr = cx.exitFunction();

            var { params:params, numparams:numparams, defaults:defaults, resultType:resultType } = signature;
            var fnexpr = new Ast::LiteralExpr( new Ast::LiteralFunction(new Ast::Func(name, 
                                                                                      false, 
                                                                                      body, 
                                                                                      params, 
                                                                                      numparams,
                                                                                      vars, 
                                                                                      defaults, 
                                                                                      resultType,
                                                                                      attr)), 
                                               pos);

            return fnexpr;
        }

        /*

        ConstructorDefinition
            function  ClassName  ConstructorSignature  FunctionBody(allowIn)

        */

        function constructorDefinition (omega, ns) : Ast::STMTS {
            eat (Token::Function);

            cx.enterFunction();
            var nd1 = identifier ();
            var nd2 = constructorSignature ();

            cx.enterVarBlock ();
            var nd3 = functionBody (allowIn, omega);
            var vars = cx.exitVarBlock ();

            var attr = cx.exitFunction();

            var {params:params,defaults:defaults,hasRest:hasRest,settings:settings,superArgs:superArgs,numparams:numparams} = nd2;

            // print ("superArgs=",superArgs);
            // print ("settings=",settings);
            var func = new Ast::Func ({kind:new Ast::Ordinary,ident:nd1},false,nd3,params,numparams,vars,defaults,Ast::voidType,attr);
            var ctor = new Ast::Ctor (settings,superArgs,func);

            if (cx.ctor !== null)
                Parse::syntaxError(this, "Constructor already defined");

            cx.ctor = ctor;

            return [];
        }

        /*

        ConstructorSignature
            TypeParameters  (  Parameters  )  ConstructorInitialiser
        
        */

        type CTOR_SIG = 
          { typeParams : [Ast::IDENT]
          , params : Ast::HEAD
          , paramTypes : [Ast::TYPE_EXPR]
          , defaults : [Ast::EXPR]
          , hasRest: boolean
          , settings : [Ast::EXPR]
          , superArgs: [Ast::EXPR] }

        type FUNC_SIG = 
          { typeParams : [Ast::IDENT]
          , params : Ast::HEAD
          , paramTypes : [Ast::TYPE_EXPR]
          , defaults : [Ast::EXPR]
          , returnType : Ast::TYPE_EXPR
          , thisType : Ast::TYPE_EXPR?
          , hasRest : boolean }


        function constructorSignature () : CTOR_SIG {
            var nd1 = typeParameters ();
            eat (Token::LeftParen);
            var [nd2,hasRest,numparams] = parameters ();
            eat (Token::RightParen);
            var [settings,superArgs] = constructorInitialiser ();

            // Translate bindings and init steps into fixtures and inits (HEAD)
            let [[f,i],e,t] = nd2;

            return { typeParams: []
                     , params: new Ast::Head (f,i)
                     , paramTypes: t
                     , numparams: numparams
                     , defaults: e
                     , hasRest: hasRest
                     , settings: settings
                     , superArgs: superArgs };
        }

        /*

        ConstructorInitialiser
            empty
            : SettingList
            : SettingList  ,  SuperInitialiser
            : SuperInitialiser
        
        SuperInitialiser
            super  Arguments

        constructor initializers are represented by two lists. the first
        list represents the initializers and will consist of set exprs or
        let exprs (if there are temps for destructuring). the second list
        represents the arguments to the call the the super constructor

        */

        function constructorInitialiser () : [[Ast::EXPR], [Ast::EXPR]] {
            switch (hd ()) {
            case Token::Colon:
                switch (hd2 ()) {
                case Token::Super:
                    next();
                    next();
                    var nd1 = []; // no settings
                    var nd2 = this.argumentList ();
                    break;
                default:
                    next();
                    var nd1 = settingList ();
                    switch (hd ()) {
                    case Token::Super:
                        next();
                        var nd2 = this.argumentList ();
                        break;
                    default:
                        var nd2 = [];
                        break;
                    }
                    break;
                }
                break;
            default:
                var nd1 = [];
                var nd2 = [];
                break;
            }

            return [nd1,nd2];
        }


        /*

        SettingList
            Setting
            SettingList  ,  Setting
        
        Setting
            Pattern(noIn, noExpr)  VariableInitialisation(allowIn)
        
        */

        function settingList () : [Ast::EXPR] {
            var nd1 = setting ();
            var nd2 = settingListPrime ();

            nd2.unshift (nd1);

            return nd2;

            function settingListPrime () : [Ast::EXPR] {
                switch (hd ()) {
                case Token::Comma:
                    eat(Token::Comma);
                    switch (hd2 ()) {
                    case Token::Super:
                        // Leave it alone for the caller to consume; super calls are always last.
                        var nd2 = [];
                        break;
                    default:
                        var nd1 = setting ();
                        var nd2 = settingListPrime ();
                        nd2.unshift (nd1);
                        break;
                    }
                    break;
                default:
                    var nd2 = [];
                    break;
                }

                return nd2;
            }
        }

        /*

        Setting
            Pattern(noIn, allowExpr)  VariableInitialisation(allowIn)


            function A (a) : [q::x,r::y] = a { }


            let ($t0 = a) q::x = $t0[0], r::y = $t0[1]

            let ($t0 = a)
                init (This,q,[x,$t0[0]),
                init (This,r,[y,$t0[1])


        */

        function setting () : Ast::EXPR {
            var nd1 = pattern (allowIn,allowExpr);
            eat (Token::Assign);
            var nd2 = assignmentExpression (allowIn);

            var [fxtrs,ndx] = desugarBindingPattern (nd1, Ast::anyType, nd2, null, Ast::instanceInit,null);
            // FIXME: assert fxtrs is empty

            return ndx;
        }

        /*

        FunctionName
            Identifier
            OverloadedOperator
            get  Identifier
            set  Identifier

        */

        function functionName () : Ast::FUNC_NAME {
            switch (hd ()) {
            case Token::Get:
                next();
                var nd1 = identifier ();
                var ndx = {kind: new Ast::Get, ident: nd1};
                break;
            case Token::Set:
                next();
                var nd1 = identifier ();
                var ndx = {kind: new Ast::Set, ident: nd1};
                break;
            case Token::Plus:
            case Token::Minus:
                // FIXME add other operators here
                // Won't be necessary if we don't support operator overloading
                Parse::internalError(this, "No support for operators as function names");
                break;
            default:
                var nd1 = identifier ();
                var ndx = {kind: new Ast::Ordinary, ident: nd1};
                break;
            }

            return ndx;
        }

        /*

        FunctionSignature
            TypeParameters  (  Parameters  )  ResultType
            TypeParameters  (  this  :  PrimaryIdentifier  )  ResultType
            TypeParameters  (  this  :  PrimaryIdentifier  ,  NonemptyParameters  )  ResultType

        there are two differences between a BINDING_IDENT and a FIXTURE_NAME: the namespace on
        properties, and the offset on parameter indicies.

        */

        function functionSignature () : FUNC_SIG {
            var nd1 = typeParameters ();
            eat (Token::LeftParen);
            switch (hd ()) {
            case Token::This:
                // FIXME implement this
                Parse::internalError(this, "No support for 'this' annotation in parameter list");
                break;
            default:
                var [nd2,hasRest,numparams] = parameters ();
                break;
            }
            eat (Token::RightParen);
            var restype = resultType ();

            // Translate bindings and init steps into fixtures and inits (HEAD)
            let [[f,i],e,t] = nd2;

            return  { typeParams: []
                    , params: new Ast::Head (f,i)
                    , paramTypes: t
                    , numparams: numparams
                    , defaults: e
                    , ctorInits: null
                    , resultType: restype
                    , thisType: null
                    , hasRest: hasRest };
        }

        /*

        TypeParameters
            empty
            .<  TypeParameterList  >

        */

        function typeParameters () : [Ast::IDENT] {
            var tparams;

            switch (hd ()) {
            case Token::LeftDotAngle:
                eat (Token::LeftDotAngle);
                tparams = typeParameterList ();
                eat (Token::GreaterThan);
                break;
            default:
                tparams = [];
                break;
            }

            return tparams;
        }

        /*

        TypeParameterList
            Identifier
            Identifier  ,  TypeParameterList

        */

        function typeParameterList () : [Ast::IDENT] {
            var nd1 = identifier ();
            var nd2 = typeParameterListPrime ();

            nd2.unshift (nd1);

            return nd2;

            function typeParameterListPrime () : [Ast::IDENT] {
                switch (hd ()) {
                case Token::Comma:
                    eat (Token::Comma);
                    var nd1 = identifier ();
                    var nd2 = typeParameterListPrime ();
                    break;
                default:
                    var nd2 = [];
                    break;
                }
            }

            return nd2;
        }

        /*

        Parameters
            empty
            NonemptyParameters

        */

        function parameters () : [[[Ast::FIXTURES, Ast::EXPRS], [Ast::EXPR], [Ast::TYPE_EXPR]], boolean, int] {
            switch (hd ()) {
            case Token::RightParen:
                var hasRest = false;
                var nd1 = [[[],[]],[],[]];
                var numparams = 0;
                break;
            default:
                var [nd1,hasRest,numparams] = nonemptyParameters (0,false);
                break;
            }

            return [nd1,hasRest,numparams];
        }

        /*

        NonemptyParameters
            ParameterInit
            ParameterInit  ,  NonemptyParameters
            RestParameter

        */

        function nonemptyParameters (n:int, initRequired) : [[[Ast::FIXTURES,Ast::EXPRS], Ast::EXPRS, Ast::TYPE_EXPRS], boolean, int] {
            var nd1;
            var hasRest = false;
            var numparams = 0;

            switch (hd ()) {
            case Token::TripleDot:
                nd1 = restParameter (n);
                hasRest = true;
                numparams = 1;
                break;

            default:
                nd1 = parameterInit (n,initRequired);
                numparams = 1;
                switch (hd ()) {
                case Token::Comma:
                    eat (Token::Comma);
                    let [[f1,i1],e1,t1] = nd1;
                    var [nd2,hasRest,numparams2] = nonemptyParameters (n+1, e1.length!=0);
                    let [[f2,i2],e2,t2] = nd2;
                    numparams += numparams2;
                    // FIXME when Array.concat works
                    for (let i=0; i<f2.length; ++i) f1.push(f2[i]);
                    for (let i=0; i<i2.length; ++i) i1.push(i2[i]);
                    for (let i=0; i<e2.length; ++i) e1.push(e2[i]);
                    for (let i=0; i<t2.length; ++i) t1.push(t2[i]);
                    nd1 = [[f1,i1],e1,t1];
                    break;
                case Token::RightParen:
                    // nothing to do
                    break;
                default:
                    Parse::syntaxError(this, "unexpected token in nonemptyParameters");
                }
                break;
            }

            return [nd1,hasRest,numparams];
        }

        /*

        ParameterInit
            Parameter
            Parameter = NonAssignmentExpression(AllowIn)

        */

        function parameterInit (n: int, initRequired) : [[Ast::FIXTURES,Ast::EXPRS], Ast::EXPRS, Ast::TYPE_EXPRS] {
            var nd1;

            nd1 = parameter ();
            switch (hd ()) {
            case Token::Assign:
                eat (Token::Assign);
                var nd2 = [nonAssignmentExpression(allowIn)];
                break;
            default:
                if (initRequired)
                    Parse::syntaxError(this, "Expecting default value expression");
                var nd2 = [];
                break;
            }

            var [k,[p,t]] = nd1;
            var [f,i] = desugarBindingPattern (p, t, new Ast::GetParam (n), Ast::noNS, Ast::letInit, false);
            f.push ([new Ast::TempName (n), new Ast::ValFixture (t,false)]); // temp for desugaring

            return [[f,[i]],nd2,[t]];
        }

        /*

        Parameter
            ParameterKind  TypedIdentifier(AllowIn)
            ParameterKind  TypedPattern

        */

        function parameter () : [Ast::VAR_DEFN_TAG, [PATTERN, Ast::TYPE_EXPR]] {
            var nd1 = parameterKind ();
            var nd2 = typedPattern (allowIn);
            return [nd1,nd2];
        }

        /*

        ParameterKind
            empty
            const

        */

        function parameterKind () : Ast::VAR_DEFN_TAG {
            switch (hd ()) {
            case Ast::Const:
                eat (Ast::Const);
                var nd1 = new Ast::Const;
                break;
            default:
                var nd1 = new Ast::Var;
                break;
            }

            return nd1;
        }

        /*

        ResultType
            empty
            :  void
            :  NullableTypeExpression

        */

        function resultType () : [Ast::IDENT] {
            switch (hd ()) {
            case Token::Colon:
                eat (Token::Colon);
                switch (hd ()) {
                case Token::Void:
                    eat (Token::Void);
                    var nd1 = new Ast::SpecialType (new Ast::VoidType);
                    break;
                default:
                    var nd1 = nullableTypeExpression ();
                    break;
                }
                break;
            default:
                var nd1 = Ast::anyType;
                break;
            }

            return nd1;
        }

        /*

            FunctionBody(beta)
                Block(local)
                AssignmentExpression(beta)

        */

        function functionBody (beta: BETA, omega) : Ast::BLOCK {
            switch (hd ()) {
            case Token::LeftBrace:
                var nd1 = block (localBlk);
                break;
            default:
                var nd1 = assignmentExpression (beta);
                semicolon (omega);
                var nd1 = new Ast::Block (new Ast::Head ([],[]),[new Ast::ReturnStmt (nd1)]);
                break;
            }

            return nd1;
        }

        function classDefinition (ns: Ast::NAMESPACE, isDynamic) : Ast::STMTS {
            eat (Token::Class);

            var nd1 = identifier ();

            var nd2 = typeSignature ();
            var nd3 = classInheritance ();
            currentClassName = nd1;
            cx.enterVarBlock(); // Class
            cx.enterVarBlock (); // Instance
            var blck = classBody ();
            var ihead = cx.exitVarBlock (); // Instance
            var chead = cx.exitVarBlock (); // Class
            currentClassName = "";

            var name = {ns:ns,id:nd1};

            var ctor = cx.ctor;
            if (ctor===null)
            {
                cx.enterFunction();
                let isNative = false;
                let blck = new Ast::Block (new Ast::Head([],[]),[]);
                let params = new Ast::Head([],[]);
                let numparams = 0;
                let vars = new Ast::Head([],[]);
                let defaults = [];
                let ty = Ast::anyType;
                let attr = cx.exitFunction();
                let func = new Ast::Func ({kind:new Ast::Ordinary,ident:nd1},isNative,blck,params,numparams,vars,defaults,ty,attr);
                var ctor = new Ast::Ctor ([],[],func);
            }
            
            // var [i,j] = o
            // var $t = o
            // var i = $t[0]
            // var j = $t[1]

            // let ($t=o) init

            var baseName = {ns: new Ast::PublicNamespace (""), id: "Object"}
            var interfaceNames = [];
            //var chead = new Ast::Head ([],[]);
            var ctype = Ast::anyType;
            var itype = Ast::anyType;
            var cls = new Ast::Cls (name,baseName,interfaceNames,ctor,chead,ihead,ctype,itype);

            var fxtrs = [[new Ast::PropName(name),new Ast::ClassFixture (cls)]];
            cx.addVarFixtures (fxtrs);
            cx.ctor = null;

            var ss4 = [new Ast::ClassBlock (name,blck)];

            return ss4;
        }

        /*

        Typesignature
            TypeParameters
            TypeParameters  !

        */

        function typeSignature () : [[Ast::IDENT], boolean] {
            var nd1 = typeParameters ();

            switch (hd ()) {
            case Token::Not:
                next();
                var nd2 = true;
                break;
            default:
                var nd2 = false;
                break;
            }

            return [nd1,nd2];
        }

        function classInheritance () : [Ast::IDENT_EXPR, [Ast::IDENT_EXPR]] {
            var nd1 = null;
            var nd2;

            if (hd () === Token::Extends) {
                eat(Token::Extends);
                nd1 = primaryName ();
            }

            if (hd () === Token::Implements) {
                eat(Token::Implements);
                nd2 = primaryNameList ();
            }
            else
                nd2 = [];

            return [nd1, nd2];
        }

        function classBody () : Ast::BLOCK
            block (classBlk);

        /*

        NamespaceDefinition(omega)
            namespace  Identifier  NamespaceInitialisation  Semicolon(omega)

        NamespaceInitialisation
            empty
            =  StringLiteral
            =  PrimaryName

        */

        function namespaceDefinition (omega: OMEGA, ns: Ast::NAMESPACE ) : Ast::STMTS {
            eat (Token::Namespace);
            var nd1 = identifier ();
            var nd2 = namespaceInitialisation ();
            semicolon (omega);

            var nsVal;
            if (nd2 === null) 
                nsVal = new Ast::AnonymousNamespace (getAnonymousName(nd1));
            else 
                nsVal = new Ast::UserNamespace (nd2);

            var name = new Ast::PropName ({ns:ns, id:nd1});
            var fxtr = new Ast::NamespaceFixture (nsVal);
            cx.addVarFixtures ([[name,fxtr]]);

            return [];

            function getAnonymousName (seedStr) {
                return seedStr;  // FIXME
            }

        }

        function namespaceInitialisation () : Ast::IDENT? {
            switch (hd ()) {
            case Token::Assign:
                eat(Token::Assign);
                switch (hd ()) {
                case Token::StringLiteral:
                    var nd1 = lexeme();
                    eat(Token::StringLiteral);
                    break;
                default:
                    var nd1 = primaryName ();
                    nd1 = cx.resolveNamespaceFromIdentExpr (nd1);  // FIXME not implemented
                    break;
                }
                break;
            default:
                var nd1 = null;
                break;
            }

            return nd1;
        }


        /*

        TypeDefinition(omega)
            type  Identifier  TypeInitialisation  Semicolon(omega)

        TypeInitialisation
            =  NullableTypeExpression

        */

        function typeDefinition (omega: OMEGA, ns: Ast::NAMESPACE) : Ast::STMTS {
            eat (Token::Type);
            var nd1 = identifier ();

            eat (Token::Assign);
            var nd2 = nullableTypeExpression ();
            semicolon (omega);

            var name = new Ast::PropName ({ns:ns, id:nd1});
            var fxtr = new Ast::TypeFixture (nd2);
            cx.addVarFixtures ([[name,fxtr]]);

            return [];
        }

        // DIRECTIVES

        /*
          Directives(tau)
              empty
              DirectivesPrefix(tau) Directives(tau,full)

        */

        function directives (tau: TAU) : [Ast::PRAGMAS, Ast::STMTS] {
            switch (hd ()) {
            case Token::RightBrace:
            case Token::EOS:
                var nd1 = [[],[]];
                break;
            default:
                var nd1 = directivesPrefix (tau);
                break;
            }

            return nd1;
        }

        /*

          DirectivesPrefix (tau)
              empty
              Pragmas
              DirectivesPrefix(tau) Directive(tau,full)

          right recursive:

          DirectivesPrefix(tau)
              empty
              Pragmas DirectivePrefix'(tau)

          DirectivesPrefix'(tau)
              empty
              Directive(tau,full) DirectivesPrefix'(tau)

          add var fixtures to the vhead and let fixtures to the bhead. the
          context provides a reference to the current vhead and bhead, as
          well as the whole environment, for convenient name addition and
          lookup.


        */

        function directivesPrefix (tau: TAU) : [Ast::PRAGMAS, Ast::STMTS] {
            switch (hd ()) {
            case Token::Use:
            case Token::Import:
                pragmas (); 
                var nd2 = directivesPrefixPrime (tau);
                break;
            default:
                var nd2 = directivesPrefixPrime (tau);
                break;
            }

            return nd2;
        }

        function directivesPrefixPrime (tau: TAU) : Ast::STMTS {
            var nd1 = [];

            while (hd () !== Token::RightBrace && hd () !== Token::EOS ) {
                var ndx = directive (tau,fullStmt);
                for (var i=0; i<ndx.length; ++i) 
                    nd1.push (ndx[i]);
            }

            return nd1;
        }

        function isCurrentClassName (lexeme) : boolean
            lexeme === currentClassName;

        /*

        Directive(t, w)
            EmptyStatement
            Statement(w)
            AnnotatableDirective(t, w)
            Attributes(t)  [no line break]  AnnotatableDirective(t, w)

        */

        function directive (tau: TAU, omega: OMEGA) : Ast::STMTS {
            var nd1;
            switch (hd()) {
            case Token::SemiColon:
                eat(Token::SemiColon);
                nd1 = [new Ast::EmptyStmt];
                break;

            case Token::Let: // FIXME might be function
            case Token::Var:
            case Token::Const:
                nd1 = variableDefinition (allowIn
                                          , tau
                                          , cx.pragmas.defaultNamespace
                                          , false
                                          , false);
                semicolon (omega);
                break;

            case Token::Function:
                if (isCurrentClassName (lexeme2())) 
                    nd1 = constructorDefinition (omega, cx.pragmas.defaultNamespace);
                else 
                    nd1 = functionDefinition (tau, omega, new Ast::Var
                                              , cx.pragmas.defaultNamespace
                                              , false, false, false, false, false);
                //ts1 = semicolon (ts1,omega);
                break;

            case Token::Class:
                nd1 = classDefinition (cx.pragmas.defaultNamespace, false);
                break;

            case Token::Namespace:
                nd1 = namespaceDefinition (omega, cx.pragmas.defaultNamespace);
                break;

            case Token::Type:
                nd1 = typeDefinition (omega, cx.pragmas.defaultNamespace);
                break;

            case Token::LeftBrace:
            case Token::Break:
            case Token::Continue:
            case Token::Default:
            case Token::Do:
            case Token::For:
            case Token::If:
            case Token::Let:
            case Token::Return:
            case Token::Switch:
            case Token::Throw:
            case Token::Try:
            case Token::While:
            case Token::With:
                nd1 = [statement (tau,omega)];
                break;

            case Token::Dynamic:
            case Token::Final:
            case Token::Native:
            case Token::Override:
            case Token::Prototype:
            case Token::Static:
            case Token::Public:
            case Token::Private:
            case Token::Protected:
            case Token::Internal:
            case Token::Intrinsic:
                let attr = attribute (tau,defaultAttrs());
                nd1 = annotatableDirective (tau,omega,attr);
                break;

            case Token::Identifier:
                // FIXME: This should be some variant of directive (), in order to catch "var".
                // But not every directive can be labeled, so just do the simple thing for the
                // time being.
                if (hd2 () == Token::Colon) {
                    nd1 = [statement (tau,omega)];
                    break;
                }
                // Fall through if not label

            default:  // label, attribute, or expr statement
                nd1 = listExpression (allowIn);
                switch (hd ()) {
                case Token::SemiColon:
                    eat(Token::SemiColon);
                    nd1 = [new Ast::ExprStmt (nd1)];
                    break;

                case Token::RightBrace:
                case Token::EOS:
                    nd1 = [new Ast::ExprStmt (nd1)];
                    break;

                default:
                    if (newline ()) // stmt
                        nd1 = [new Ast::ExprStmt (nd1)];
                    else {
                        switch (hd ()) {
                        case Token::Dynamic:
                        case Token::Final:
                        case Token::Native:
                        case Token::Override:
                        case Token::Prototype:
                        case Token::Static:
                        case Token::Let:
                        case Token::Var:
                        case Token::Const:
                        case Token::Function:
                        case Token::Class:
                        case Token::Namespace:
                        case Token::Type:
                            // FIXME check ns attr
                            let ie = nd1.Ast::exprs[0].Ast::ident;  
                            var attrs = defaultAttrs ();
                            attrs.ns = cx.evalIdentExprToNamespace (ie);
                            nd1 = annotatableDirective (tau,omega,attrs);
                            break;

                        default:
                            Parse::internalError(this, "directive should never get here: " + lexeme());
                            break;
                        }
                    }
                }
            }

            return nd1;
        }

        function annotatableDirective (tau: TAU, omega: OMEGA, attrs) : Ast::STMTS {
            var nd2;

            switch (hd()) {
            case Token::Let: // FIXME might be function
            case Token::Var:
            case Token::Const:
                nd2 = variableDefinition (allowIn, tau
                                          , attrs.ns
                                          , attrs.prototype
                                          , attrs.static);
                semicolon (omega);
                break;

            case Token::Function:
                if (isCurrentClassName (lexeme2())) 
                    nd2 = constructorDefinition (omega, attrs.ns);
                else 
                    nd2 = functionDefinition (tau, omega, new Ast::Var
                                              , attrs.ns, attrs.final, attrs.override
                                              , attrs.prototype, attrs.static, attrs.abstract);
                //ts2 = semicolon (ts2,omega);
                break;

            case Token::Class:
                nd2 = classDefinition (attrs.ns, attrs.dynamic);
                break;

            case Token::Namespace:
                nd2 = namespaceDefinition (omega, attrs.ns);
                break;

            case Token::Type:
                nd2 = typeDefinition (omega, attrs.ns);
                break;

            default:  // label, attribute, or expr statement
                let xattrs = attribute (tau,defaultAttrs());
                if (newline ()) 
                    Parse::syntaxError(this, "error unexpected newline before " + lexeme())
                nd2 = annotatableDirective (tau,omega,xattrs);
            }

            return nd2;
        }

//        /*
//
//        Attributes
//            Attribute
//            Attribute [no line break] Attributes
//
//        Attribute
//            SimpleTypeIdentifier
//            ReservedNamespace
//            dynamic
//            final
//            native
//            override
//            prototype
//            static
//            [  AssignmentExpressionallowIn  ]
//
//        */
//

        type ATTRS = Object;  // FIXME object type

        function defaultAttrs () : ATTRS {
            return { ns: cx.pragmas.defaultNamespace
                   , 'true': false
                   , 'false': false
                   , dynamic: false
                   , final: false
                   , native: false
                   , override: false
                   , prototype: false
                   , static: false }
        }

        // Modifies "nd" and returns it too.
        function attribute (tau: TAU, nd: ATTRS) {
            switch (tau) {
            case classBlk:
                switch (hd ()) {
                case Token::Final:
                    eat(Token::Final);
                    nd.final = true;
                    break;
                case Token::Native:
                    eat(Token::Native);
                    nd.native = true;
                    break;
                case Token::Override:
                    eat(Token::Override);
                    nd.override = true;
                    break;
                case Token::Prototype:
                    eat(Token::Prototype);
                    nd.prototype = true;
                    break;
                case Token::Static:
                    eat(Token::Static);
                    nd.static = true;
                    break;
                case Token::Public:
                case Token::Private:
                case Token::Protected:
                case Token::Internal:
                case Token::Intrinsic:
                    nd.ns = reservedNamespace ();
                    break;
                default:
                    nd.ns = cx.evalIdentExprToNamespace (primaryName ());
                    break;
                }
                break;

            case globalBlk:
                switch (hd ()) {
                case Token::True:
                    eat(Token::True);
                    nd['true'] = true;  // FIXME RI bug
                    break;
                case Token::False:
                    eat(Token::False);
                    nd['false'] = false;
                    break;
                case Token::Dynamic:
                    eat(Token::Dynamic);
                    nd.dynamic = true;
                    break;
                case Token::Final:
                    eat(Token::Final);
                    nd.final = true;
                    break;
                case Token::Native:
                    eat(Token::Native);
                    nd.native = true;
                    break;
                case Token::Public:
                case Token::Internal:
                case Token::Intrinsic:
                    nd.ns = reservedNamespace ();
                    break;
                default:
                    nd.ns = cx.evalIdentExprToNamespace (primaryName ());
                    break;
                }
                break;

            case localBlk:
                break;

            default:
                Parse::internalError(this, "error attribute tau " + tau);
            }

            return nd;
        }


        // PRAGMAS

        // Works by side effect on cx.
        function pragmas () {
            while (hd () === Token::Use || hd () === Token::Import) {
                pragma ();
                semicolon (fullStmt);
            }
        }

        function pragma () {
            switch (hd ()) {
            case Token::Use:
                eat(Token::Use);
                pragmaItems ();
                break;
            case Token::Import:
                eat(Token::Import);
                importName ();
                break;
            }
        }

        function pragmaItems () {
            while (true) {
                switch (hd ()) {
                case Token::Decimal:
                    break;
                case Token::Namespace:
                    eat(Token::Namespace);
                    cx.openNamespace (primaryName ());
                    break;
                case Token::Double:
                    break;
                case Token::Int:
                    break;
                case Token::Default:
                    eat(Token::Default);
                    switch (hd ()) {
                    case Token::Namespace:
                        eat(Token::Namespace);
                        let name = primaryName ();
                        cx.defaultNamespace (name);
                        cx.openNamespace (name);
                        break;
                    default:
                        Parse::syntaxError(this, "unexpected token after 'use default'");
                    }
                    break;
                    //            case Token::Number
                    //                break;
                case Token::Precision:
                    break;
                case Token::Rounding:
                    break;
                case Token::Standard:
                    break;
                case Token::Strict:
                    break;
                case Token::UInt:
                    break;
                case Token::Unit:
                    break;
                default:
                    Parse::syntaxError(this, "unknown token in PragmaItem");
                }

                if (hd () !== Token::Comma)
                    break;

                eat (Token::Comma);
            }
        }

        /*

        ImportName
            PackageName  .  *
            PackageName  .  Identifier

        */

        function importName () {
            var nd1 = [identifier ()];
            while (hd () === Token::Dot) {
                eat(Token::Dot);
                // FIXME: This looks anything but safe, it'll accept anything
                nd1.push(lexeme());
                next();
            }

            let ns = namespaceFromPath (nd1);
            cx.openNamespace (ns);

            return;

            function namespaceFromPath (path) 
            {
                var str = "";
                for (var i=0; i<path.length-1; ++i) { // -1 to skip last ident
                    if (i!=0) 
                        str = str + ".";
                    str = str + path[i];
                }

                return new Ast::ReservedNamespace (new Ast::PublicNamespace (str));  // FIXME ReservedNamespace is a misnomer
            }

        }

        // BLOCKS and PROGRAMS

        function block (tau: TAU) : Ast::BLOCK
        {
            eat (Token::LeftBrace);
            cx.enterLetBlock ();
            var nd1 = directives (tau);
            let head = cx.exitLetBlock ();
            eat (Token::RightBrace);

            return new Ast::Block (head,nd1);
        }

        function packages () : [PACKAGE] {
            let pkgs = [];

            // FIXME: "internal".
            do {
                let ids = [];
                eat (Token::Package);
                ids.push( identifier() );
                while (hd() == Token::Dot) {
                    eat(Token::Dot);
                    ids.push( identifier() );
                }
                pkgs.push( new Ast::Package(ids, block(globalBlk)) );
            } while (hd () == Token::Package);
            return pkgs;
        }

        function program () : Ast::PROGRAM {
            start();

            cx.enterVarBlock ();
            var publicNamespace = new Ast::ReservedNamespace (new Ast::PublicNamespace (""));
            cx.openNamespace (publicNamespace);
            cx.defaultNamespace (publicNamespace);

            var nd1;
            if (hd () == Token::Internal || hd () == Token::Package)
                nd1 = packages ();
            else
                nd1 = [];

            currentPackageName = "";
            currentClassName = "";

            cx.enterLetBlock ();
            var nd2 = directives (globalBlk);
            var bhead = cx.exitLetBlock ();
            var vhead = cx.exitVarBlock ();

            switch (hd ()) {
            case Token::EOS:
                break;
            default:
                Parse::syntaxError(this, "extra tokens after end of program.");
            }

            return new Ast::Program ( nd1,
                                      new Ast::Block (bhead,nd2),
                                      vhead,
                                      cx.topFunction(),
                                      filename );
        }
    }

    function test ()
    {
        var programs =
            [ "print('hi')"
              // , readFile ("./tests/self/t.es")
              /*
            , "x<y"
            , "x==y"
            , "m-n;n+m"
            , "10"
            , "p.q.r.x"
            , "q::id"
            , "f() ()"
            , "new A()"
            , "(new Fib(n-1)).val + (new Fib(n-2)).val"
            , "var x = 10, y = 20"
            , "var x = 10; var y"
            , "if (x) y; else z"
            , "new new x (1) (2) . x"
            , "var x : int = 10; var y: string = 'hi'"
            , "function f(x,y,z) { return 10 }"
            , "new new y"
            , "z (1) (2)"
            , "new new x (1) (2)"
            , "new new x (1) (2) . x"
            , "let x = 10"
            , "let const x"
            , "const x"
            , "x.y.z"
            , "while (x) { print(x); x-- }"
            , "function f (x=10) { return x }"
            , "function f (x) { return x }"
              , "x = y"
            , readFile ("./tests/self/prime.es")
              */
              /*
            , "class A { function A() {} }"
            , "class Fib { function Fib (n) { } }"
            , readFile ("./tests/self/hello.es")
            "a .< t .< u .< v > , w .< x > > > >",
            "q::[expr]",
            "(expr)::id",
            "(expr)::[expr]",
            "@a",
            "@q::id",
            "@q::[expr]",
            "@(expr)::id",
            "@(expr)::[expr]",
            "@[expr]",
            "/abcdefg/g",
            "/abcdefg/",
            "/abcdefg/i",
            "/abcdefg/x",
            "true",
            "false",
            "null",
            "(a)::x",
            "(function(a,b,c){})",
            "{x:a,y:b,z:c}",
            "[a,b,c]",
            "{(x):y}",
            "(function(){})",
            "(function f(a:A,b:B){})",
            "(function f.<T,U,V>(a:T,b:U,c:V){})",

            // type expressions

            "T",
            "?T",
            "T!",
            "T~",
            "T.<U>",
            "T.<U.<V>>",
            "T.<{a:A,t:{i:I,s:S}}>",
            "T.<{x:[A,B,C]}>",
            "T.<{x:(A,B,C)}>",
            "T.<U.<V.<W.<[,,,]>>>>",
            "T.<U>!",
            "?T.<U>",

            // Postfixx expressions

            "x.y",
            "new x",
            "new x()",
            "x()",
            "x.y()",
            "x++",
            "x--",
            "x.y++",
            "x.y()++",
            "new x.y++",
            */
        ]

        var n = 0;
            //        for each ( var p in programs )
        for (;n<programs.length;n++)
        {
            var p = programs[n];
            try {
                var parser = new Parser(p);
                var nd1 = parser.program ();

                //                dumpABCFile(cogen.cg(nd1), "hello-test.es");

                var tx1 = Encode::program (nd1);
                print(n, "-1> ", p, tx1);
                var nd2 = Decode::program (eval("("+tx1+")"));
                var tx2 = Encode::program (nd2);
                print(n, "-2> ", p, tx2);

                print("tx1.length=",tx1.length);
                print("tx2.length=",tx2.length);
                for (var i = 0; i < tx1.length; ++i) {
                    if (tx1[i] != tx2[i]) 
                        throw "error at pos "+i+" "+tx1[i]+ " != "+tx2[i]+" prefix: "+tx1.slice(i,tx1.length);
                }
                print("txt==tx2");
            }
            catch(x)
            {
                print(x)
            }
        }
    }
}
