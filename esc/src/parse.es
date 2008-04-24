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

use default namespace Parse;

type PATTERNS = [PATTERN];
type PATTERN =
    ( ObjectPattern
    | ArrayPattern
    | SimplePattern
    | IdentifierPattern );

type FIELD_PATTERNS = [FIELD_PATTERN];
type FIELD_PATTERN = FieldPattern;

class FieldPattern {
    const ident: Ast::IDENT_EXPR;
    const ptrn: PATTERN;
    function FieldPattern (ident,ptrn)
        : ident = ident
        , ptrn = ptrn { }
}

class ObjectPattern {
    const ptrns; //: FIELD_PATTERNS;
    function ObjectPattern (ptrns)
        : ptrns = ptrns { }
}

class ArrayPattern {
    const ptrns; //: PATTERNS;
    function ArrayPattern (ptrns)
        : ptrns = ptrns { }
}

class SimplePattern {
    const expr : Ast::EXPR;
    function SimplePattern (expr)
        : expr = expr { }
}

class IdentifierPattern {
    const ident : Ast::IDENT;
    function IdentifierPattern (ident)
        : ident = ident { }
}

// public for now because there's a bug in the compiler

public class ENUM {
    const s;
    function ENUM(s) : s=s {}
    
    function toString() {
        return s;
    }
}

class ALPHA extends ENUM { function ALPHA(s) : super(s) {} }
const noColon = new ALPHA("noColon");
const allowColon = new ALPHA("allowColon");

class BETA extends ENUM { function BETA(s) : super(s) {} }
const noIn = new BETA("noIn");
const allowIn = new BETA("allowIn");

class GAMMA extends ENUM { function GAMMA(s) : super(s) {} }
const noExpr = new GAMMA("noExpr");
const allowExpr = new GAMMA("allowExpr");

class TAU extends ENUM { function TAU(s) : super(s) {} }
const globalBlk = new TAU("globalBlk");
const classBlk = new TAU("classBlk");
const interfaceBlk = new TAU("interfaceBlk");
const localBlk = new TAU("localBlk");

class OMEGA extends ENUM { function OMEGA(s) : super(s) {} }
const fullStmt = new OMEGA("fullStmt");
const abbrevStmt = new OMEGA("abbrevStmt");

function syntaxError(ctx, msg) {
    let filename = "";
    let position = 0;
    if (ctx is Context)
        ctx = ctx.parser;
    if (ctx is Parser) {
        filename = ctx.scan.filename;
        position = ctx.position();
    }
    Util::syntaxError(filename, position, msg);
}

function internalError(ctx, msg) {
    let filename = "";
    let position = 0;
    if (ctx is Context)
        ctx = ctx.parser;
    if (ctx is Parser) {
        filename = ctx.scan.filename;
        position = ctx.position();
    }
    Util::internalError(filename, position, msg);
}

final class Rib 
{
    static const SYSTEM = -1;
    static const GLOBAL = 0;
    static const CLASS_STATIC = 1;
    static const CLASS_INSTANCE = 2;
    static const FUNCTION = 3;
    static const BLOCK = 4;

    var tag;
    var head: Ast::Head;
    var link: Rib;
    var defaultNamespace;
    var open_namespaces;

    function Rib(tag, link) 
        : tag = tag
        , link = link
        , open_namespaces = null        // lazily cloned from 'link'
        , defaultNamespace = Ast::noNS  // 'use default namespace' is shallow
        , head = new Ast::Head([], [])
    {
    }

    function get openNamespaces() 
        open_namespaces != null ? open_namespaces : link.openNamespaces;

    function openNamespace(ns) {
        if (open_namespaces == null) {
            let l = link;
            while (l.open_namespaces == null)
                l = l.link;
            open_namespaces = Util::copyArray(l.openNamespaces);
            open_namespaces.push([]);
        }

        let last = open_namespaces[open_namespaces.length-1];
        for ( let i=0, limit=last.length ; i < limit ; i++ )
            if (Ast::nsEquals(last[i], ns))
                return;
        last.push (ns);
    }

    static function makeSystemRib(topFixtures) {
        let r = new Rib(Rib.SYSTEM, null);
        r.head = new Ast::Head(topFixtures, []);
        r.open_namespaces = [[]];
        return r;
    }
}

// This is a singleton class and it should probably just be inlined
// into Parser, the indirection / abstraction doesn't buy us anything
// but a tiny amount of information hiding.

final class Context
{
    private var env: Rib;
    private var top_function: Ast::FuncAttr;

    function Context (topFixtures)
        : env = Rib.makeSystemRib(topFixtures)
        , top_function = new Ast::FuncAttr(null)
    {
    }

    function enterGlobal(): void 
        enterRib(Rib.GLOBAL);

    function exitGlobal() 
        exitRib();

    function enterClassStatic(): void 
        enterRib(Rib.CLASS_STATIC);

    function exitClassStatic() 
        exitRib();

    function enterClassInstance(): void 
        enterRib(Rib.CLASS_INSTANCE);

    function exitClassInstance() 
        exitRib();

    function enterFunction(attrs): void {
        let node = new Ast::FuncAttr(top_function);
        node.is_native = attrs.native;
        top_function.children.push(node);
        top_function = node;
        enterRib(Rib.FUNCTION);
    }

    function exitFunction() {
        let vars = exitRib();
        let attr = top_function;
        top_function = top_function.parent;

        return [vars, attr];
    }

    function topFunction() {
        return top_function;
    }

    function enterBlock(): void 
        enterRib(Rib.BLOCK);

    function exitBlock() 
        exitRib();

    private function enterRib(tag): void
        env = new Rib(tag, env);

    private function exitRib(): Ast::Head {
        let head = env.head;
        env = env.link;
        return head;
    }

    function addFixtures(initType, fixtures, isStatic=false): void
        Util::pushOnto(findHead(initType, isStatic).fixtures, fixtures);

    function addInits(initType, inits, isStatic=false): void
        Util::pushOnto(findHead(initType, isStatic).exprs, inits);

    function addFixture(initType, name, fixture, isStatic=false): void
        findHead(initType, isStatic).fixtures.push([name,fixture]);

    private function findHead(initType, isStatic) {
        if (initType == Ast::letInit)
            return env.head;
        for ( let e=env ; e != null ; e = e.link )
            if (e.tag != Rib.BLOCK && (!isStatic || e.tag == Rib.CLASS_STATIC))
                return e.head;
        Parse::internalError(this, "Fell off the end in Context::findHead(): " + initType + "," + isStatic);
    }

    function getOpenNamespaces()
        env.openNamespaces;

    function getDefaultNamespace()
        env.defaultNamespace;

    function setDefaultNamespace (ident: Ast::IDENT_EXPR) {
        let ns = evalIdentExprToNamespace (ident);
        env.defaultNamespace = ns;
    }

    function openNamespace (ident: Ast::IDENT_EXPR): void
        env.openNamespace( evalIdentExprToNamespace (ident) );

    function pushNamespace(ns): void
        env.openNamespace(ns);

    function hasName (fxtrs,id,ns) {
        if (fxtrs.length==0)
            return false;

        let pn = fxtrs[0][0];
        if (pn.name.id == id && Ast::nsEquals(pn.name.ns, ns))
            return true;
        return hasName (fxtrs.slice(1,fxtrs.length), id, ns);
    }

    function getFixture (fxtrs,id,ns) {
        if (fxtrs.length===0) 
            Parse::syntaxError(this, "Name not found " + ns + "::" + id);

        let pn = fxtrs[0][0];
        if (pn.name.id==id && pn.name.ns.toString()==ns.toString()) 
            return fxtrs[0];
        return getFixture (fxtrs.slice (1,fxtrs.length),id,ns);
    }

    /*

    two dimensional search

    repeat for each shadowed name
    each name in each head
    dup is error

    for each namespace set
    find all names in the inner most head

    */

    function findFixtureWithNames (id, nss, it: Ast::INIT_TARGET?) {
        let env = this.env;

        if (it == Ast::instanceInit) {
            while (env != null && env.tag != Rib.CLASS_INSTANCE)
                env = env.link;
            return findFixtureWithNamesInFixtures(env.head.fixtures, id, nss);
        }

        while (env != null) {
            let result = findFixtureWithNamesInFixtures(env.head.fixtures, id, nss);
            if (result != null)
                return result;
            env = env.link;
        }
        
        return null;
    }

    function findFixtureWithNamesInFixtures(fxtrs, id, nss) {
        let ns = null;
        for (let j=nss.length-1; j>=0; --j) {
            if (hasName (fxtrs,id,nss[j])) {
                if (ns !== null)
                    Parse::syntaxError(this, "Ambiguous reference to '" + id + "': defined in " + ns + " and " + nss[j]);
                ns = nss[j];
            }
        }

        if (ns != null)
            return getFixture (fxtrs,id,ns);

        return null;
    }

    function findFixtureWithIdentifier (id: Ast::IDENT, it: Ast::INIT_TARGET?) {
        let nsss = env.openNamespaces;
        for (let i=nsss.length-1; i>=0; --i) {
            let fx = findFixtureWithNames (id, nsss[i], it);
            if (fx !== null) 
                return fx;
        }
    }

    function evalIdentExprToNamespace (ident: Ast::IDENT_EXPR) : Ast::NAMESPACE {
        let fxtr = null;
        let val = null;

        switch type (ident) {
        case (id: Ast::Identifier) {
            fxtr = findFixtureWithIdentifier (id.ident,null);
            if (fxtr[1] is Ast::NamespaceFixture)
                return fxtr[1].ns;
            Parse::internalError(this, "Fixture with unknown value " + fxtr[1]);
        }
        case (reserved_ns: Ast::ReservedNamespace) {
            // this goes away soon, probably?
            return reserved_ns.ns;
        }
        case (x: *) {
            Parse::internalError(this, "evalIdentExprToNamespace: case not implemented " + x);
        }
        }
    }

    function resolveIdentExpr (ident: Ast::IDENT_EXPR, it: Ast::INIT_TARGET) : Ast::FIXTURE_NAME {
        if (ident is Ast::Identifier)
            return findFixtureWithIdentifier (ident.ident, it)[0];

        Parse::internalError(this, "resolveIdentExpr: case not implemented " + ident);
    }
}

final class Parser
{
    var scan    : Scanner;
    var cx      : Context;
    var filename: String;

    function Parser(src, topFixtures, filename="") {
        this.cx = new Context(topFixtures);
        this.scan = new Lex::Scanner(src,filename);
        this.filename = filename;
    }

    var defaultNamespace: Ast::NAMESPACE;
    var currentInternalName: string;
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

    function regexp() {
        Util::assert( T0 === Token::BREAK && T1 === Token::NONE );
        T0 = scan.regexp();
        L0 = scan.lnCoord;
        return hd();
    }

    function hd ()
        tokenStore[T0].kind;

    function lexeme ()
        tokenStore[T0].text;

    function hd2 () {
        if (T1 === Token::NONE) {
            T1 = scan.start();
            L1 = scan.lnCoord;
        }
        return tokenStore[T1].kind;
    }

    function lexeme2 () {
        hd2 ();
        return tokenStore[T1].text;
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

    function position ()
        L0;

    function tokenText(t)
        tokenStore[t].text;

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

    function match (tc) {
        let tk = hd ();
        if (tk !== tc)
            return false;
        next ();
        return true;
    }

    function makeIdentifier(id, nss) : Ast::Identifier {
        let ident = new Ast::Identifier(id, nss);
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

    function desugarAssignmentPattern (p: PATTERN, t: Ast::TYPE_EXPR, e: Ast::EXPR, op: Ast::ASSIGNOP) : [Ast::FIXTURES, Ast::EXPR]
        desugarPattern (p,t,e,null,null,null,op);

    function desugarBindingPattern (p: PATTERN, t: Ast::TYPE_EXPR, e: Ast::EXPR?,
                                    ns: Ast::NAMESPACE?, it: Ast::INIT_TARGET?, ro: boolean?)
        : [Ast::FIXTURES, Ast::EXPR]
        desugarPattern (p,t,e,ns,it,ro,null);

    function desugarPattern (p: PATTERN, 
                             t: Ast::TYPE_EXPR, 
                             e: Ast::EXPR?,
                             ns: Ast::NAMESPACE?, 
                             it: Ast::INIT_TARGET?, 
                             ro: boolean?, 
                             op: Ast::ASSIGNOP?) : [Ast::FIXTURES, Ast::EXPR] 
    {
        return desugarSubPattern (p,t,e,0);

        function identExprFromExpr (e: Ast::EXPR) : Ast::IDENT_EXPR {
            if (!(e is Ast::LexicalRef))
                Parse::syntaxError(this, "Invalid initializer left-hand-side " + e);
            return ie = e.ident;
        }

        function desugarSubPattern (p: PATTERN, t: Ast::TYPE_EXPR, e: Ast::EXPR?, n: int) : [Ast::FIXTURES, Ast::EXPR] {
            let fxtrs, exprs, expr;
            switch type (p) {
            case (p:IdentifierPattern) {
                let nm = new Ast::PropName (new Ast::Name(ns,p.ident));
                let fx = new Ast::ValFixture (t,ro);
                fxtrs = [[nm,fx]];
                let inits = (e !== null) ? ([[nm,e]]) : []; // FIXME
                expr = new Ast::InitExpr (it, new Ast::Head ([],[]), inits);
            }
            case (p:SimplePattern) {
                if (e === null) 
                    Parse::syntaxError(this, "Simple pattern without initializer");
                fxtrs = [];
                if (it != null) { // we have an init target so must be an init
                    let ie = identExprFromExpr (p.expr);
                    let nm = cx.resolveIdentExpr (ie,it);
                    expr = new Ast::InitExpr (it, new Ast::Head ([],[]), [[nm,e]]);
                }
                else {
                    expr = new Ast::SetExpr (op,p.expr,e);
                }
            }
            //case (p: (ArrayPattern|ObjectPattern)) {
            case (p: *) {
                let tn = new Ast::TempName (n);
                fxtrs = [];
                exprs = [];
                let ptrns = p.ptrns;
                for (let i=0; i<ptrns.length; ++i) {
                    let sub = ptrns[i];
                    let typ, exp, ptn;
                    /// switch type (sub) {
                    /// case (sub: FieldPattern) {
                    if (sub is FieldPattern) {
                        typ = new Ast::FieldTypeRef (t,sub.ident);
                        exp = new Ast::ObjectRef (new Ast::GetTemp (n), sub.ident);
                        ptn = sub.ptrn;
                    }
                    /// case (pat: *) {
                    else {
                        typ = new Ast::ElementTypeRef (t,i);
                        exp = new Ast::ObjectRef (new Ast::GetTemp (n), makeIdentifier (i,[[Ast::noNS]]));
                        // FIXME what is the ns of a temp and how do we refer it
                        ptn = sub;
                    }
                    /// }

                    let [fx,ex] = desugarSubPattern (ptn,typ,exp,n+1);
                    for (let j=0; j<fx.length; ++j) fxtrs.push(fx[j]);
                    exprs.push(ex);
                }
                let head = new Ast::Head ([[tn,new Ast::ValFixture (Ast::anyType,false)]],
                                          [new Ast::InitExpr (Ast::letInit,new Ast::Head([],[]),[[tn,e]])]);
                expr = new Ast::LetExpr (head, exprListToCommaExpr(exprs));
            }
            }
            return [fxtrs,expr];
        }
    }

    // Parse rountines

    function identifier () : Ast::IDENT {
        let t = hd();
        if (t == Token::Identifier || Token::isCtxReserved(t))
            return let (str = lexeme()) next(), str;
        Parse::syntaxError(this, "Expecting identifier, found " + lexeme () );
    }

    function qualifier() : (Ast::IDENT | Ast::NAMESPACE) {
        switch (hd()) {
        case Token::Internal:
        case Token::Intrinsic:
        case Token::Private:
        case Token::Protected:
        case Token::Public:
            return reservedNamespace();
        case Token::Mult:
            return let (qual = lexeme ()) next(), qual;
        default:
            return identifier ();
        }
    }

    function reservedNamespace () : Ast::NAMESPACE {
        switch (hd ()) {
        case Token::Internal:  return let (ns = new Ast::InternalNamespace (currentInternalName)) next(), ns;
        case Token::Public:    return next(), Ast::noNS;
        case Token::Intrinsic: return let (ns = new Ast::IntrinsicNamespace) next(), ns;
        case Token::Private:   return let (ns = new Ast::PrivateNamespace (currentClassName)) next(), ns;
        case Token::Protected: return let (ns = new Ast::ProtectedNamespace (currentClassName)) next(), ns;
        default:               return null;
        }
    }

    function qualifiedNameIdentifier (qual: Ast::EXPR) : Ast::IDENT_EXPR {
        switch (hd()) {
        case Token::LeftBracket: return new Ast::QualifiedExpression(qual, brackets());
        case Token::Mult:        next(); return new Ast::QualifiedIdentifier(qual, "*"); // Iffy, E4X
        default:                 return new Ast::QualifiedIdentifier(qual, identifier());
        }
    }

    function brackets() {
        eat(Token::LeftBracket);
        let expr = commaExpression (allowColon, allowIn);
        eat (Token::RightBracket);
        return expr;
    }

    function simpleQualifiedName () : Ast::IDENT_EXPR {
        let qual = qualifier ();

        if (match(Token::DoubleColon)) {
            if (qual is String)
                qual = new Ast::LexicalRef (makeIdentifier (qual,cx.getOpenNamespaces()));
            else
                qual = new Ast::LiteralNamespace (qual, position());
            return qualifiedNameIdentifier (qual);
        }

        if (qual is String)
            return makeIdentifier (qual, cx.getOpenNamespaces());

        return new Ast::ReservedNamespace (qual);
    }

    function nonAttributeQualifiedName () : Ast::IDENT_EXPR 
        hd() == Token::LeftParen ? expressionQualifiedIdentifier() : simpleQualifiedName();

    function propertyName () : Ast::IDENT_EXPR {
        let name = nonAttributeQualifiedName ();
        if (match(Token::LeftDotAngle)) {
            Parse::internalError(this, "Broken parser rules");
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

    function primaryName () : Ast::IDENT_EXPR {
        if (hd() === Token::Identifier && hd2() === Token::Dot) {
            let path_element = lexeme ();
            next();
            next();
            let path_elements = path ([path_element]);
            let name = propertyName ();
            return new Ast::UnresolvedPath (path_elements, name);
        }
        return propertyName ();
    }

    function path (path_elements: [Ast::IDENT]) : [Ast::IDENT] {
        while (hd() === Token::Identifier && hd2() === Token::Dot) {
            path_elements.push( lexeme() );
            next();
            next();
        }
        return path_elements;
    }

    function parenExpression () : Ast::EXPR {
        eat (Token::LeftParen);
        let expr = commaExpression (allowColon, allowIn);
        eat (Token::RightParen);

        return expr;
    }

    function exprListToCommaExpr(es) {
        let expr = es[0];
        for ( let i=1 ; i < es.length ; i++ )
            expr = new Ast::BinaryExpr(Ast::commaOp, expr, es[i]);
        return expr;
    }

    function objectLiteral (alpha: ALPHA) : Ast::TYPE_EXPR {
        let pos = position();             // Record source location of initial left brace
        eat (Token::LeftBrace);
        let fields = fieldList (alpha);
        eat (Token::RightBrace);

        let texpr;
        switch (alpha) {
        case allowColon:
            texpr = match(Token::Colon) ? typeExpression () : new Ast::ObjectType ([]); // FIXME I mean {*}
            break;
        default:
            texpr = new Ast::ObjectType ([]); // FIXME I mean {*}
            break;
        }

        return new Ast::LiteralObject (fields, texpr, pos);
    }

    function fieldList (alpha: ALPHA) : LITERAL_FIELDS {
        let fields = [] : [LITERAL_FIELD];
        if (hd () != Token::RightBrace) {
            do 
                fields.push (literalField(alpha));
            while (match(Token::Comma));
        }
        return fields;
    }

    function literalField (alpha: ALPHA) : Ast::FIELD_TYPE {
        let tag = match(Token::Const) ? Ast::constTag : Ast::varTag;
        let fn = fieldName ();
        let expr = null;

        // The colon could be absent if this is a destructuring
        // shorthand, but we can't expand it here -- that must be
        // done later, and only in legal contexts.

        if (match(Token::Colon)) {
            switch (hd ()) {
            case Token::LeftBrace:   // short cut to avoid recursion
                expr = objectLiteral (alpha);
                break;
            case Token::LeftBracket:
                expr = arrayLiteral (alpha);
                break;
            default:
                expr = assignmentExpression (allowColon, allowIn);
                break;
            }
        }

        return new Ast::LiteralField (tag,fn,expr);
    }

    function fieldName () : Ast::IDENT_EXPR {
        switch (hd ()) {
        case Token::StringLiteral:
            return let (name = new Ast::Identifier(lexeme(), [[Ast::noNS]])) next(), name;

        case Token::IntLiteral:
        case Token::UIntLiteral:
            return let (name = new Ast::Identifier(String(parseInt(lexeme())), [[Ast::noNS]])) next(), name;

        case Token::DoubleLiteral:
            return let (name = new Ast::Identifier(String(parseFloat(lexeme())), [[Ast::noNS]])) next(), name;

        case Token::DecimalLiteral:
            return let (name = new Ast::Identifier(String(new decimal(lexeme())), [[Ast::noNS]])) next(), name;

        default:
            // FIXME: support ns::id here
            if (Token::isReserved(hd ()))
                return let (name = new Ast::Identifier(lexeme(), [[Ast::noNS]])) next(), name;
            return nonAttributeQualifiedName ();
        }
    }

    function arrayLiteral (alpha: ALPHA) : Ast::EXPR {
        let pos = position();   // Record source location of initial left bracket
        eat (Token::LeftBracket);
        let elts = elementList ();
        if (elts.length == 1 && hd() == Token::For) {
            // FIXME
            Parse::internalError(this, "Array comprehension not implemented");
        }
        else {
            eat (Token::RightBracket);
            let t = null;
            if (alpha == allowColon && match(Token::Colon)) {
                t = typeExpression();
                if (!(t is Ast::ArrayType))
                    Parse::syntaxError(this, "Array type required");
            }
            else
                t = new Ast::ArrayType([]);
            return new Ast::LiteralArray (elts, t, pos);
        }
    }

    function elementList () : Ast::EXPR {
        let elts = [];

        let elt = null;
        loop:
        for (;;) {
            switch (hd()) {
            case Token::RightBracket:
            case Token::For:
                break loop;
            case Token::Comma:
                let pos = position();
                next();
                if (elt == null)
                    elt = new Ast::LiteralUndefined(pos);
                elts.push(elt);
                elt = null;
                break;
            default:
                if (elt != null)
                    eat(Token::Comma);
                elt = assignmentExpression(allowColon, allowIn);
                break;
            }
        }
        if (elt != null)
            elts.push(elt);

        return elts;
    }

    function primaryExpression(alpha: ALPHA, beta:BETA) : Ast::EXPR {
        if (hd() == Token::BREAK)
            regexp();

        let pos = position();   // Record the source location before consuming the token
        switch (hd ()) {
        case Token::Null:
            return let (expr = new Ast::LiteralNull(pos)) next(), expr;

        case Token::True:
        case Token::False:
            return let (expr = new Ast::LiteralBoolean(hd() == Token::True, pos)) next(), expr;

        case Token::IntLiteral:
            return let (expr = new Ast::LiteralInt(parseInt(lexeme()), pos)) next(), expr;

        case Token::UIntLiteral:
            return let (expr = new Ast::LiteralUInt(parseInt(lexeme()), pos)) next(), expr;

        case Token::DoubleLiteral:
            return let (expr = new Ast::LiteralDouble(parseFloat(lexeme()), pos)) next(), expr;

        case Token::DecimalLiteral:
            return let (expr = new Ast::LiteralDecimal(new decimal(lexeme()), pos)) next(), expr;

        case Token::StringLiteral:
            return let (expr = new Ast::LiteralString (lexeme(), pos)) next(), expr;

        case Token::RegexpLiteral:
            return let (expr = new Ast::LiteralRegExp(lexeme(), pos)) next(), expr;

        case Token::This:
            return let (expr = new Ast::ThisExpr()) next(), expr;

        case Token::LeftParen:
            return parenExpression();

        case Token::LeftBracket:
            return arrayLiteral (alpha);

        case Token::LeftBrace:
            return objectLiteral (alpha);

        case Token::Function:
            return functionExpression ();

        default: {
            // FIXME: Can't call it expr here, compiler bug (has to do with let renaming?)
            let expr77 = primaryName ();
            // FIXME: not good for package qualified refs
            if (expr77 is Ast::UnresolvedPath)
                return new Ast::ObjectRef (resolvePath (expr77.path, null), expr77.ident); 
            return new Ast::LexicalRef (expr77, pos);
        }
        }
    }

    function resolvePath (path: [Ast::IDENT], expr: Ast::EXPR) : Ast::EXPR {
        if (path.length === 0)
            return expr;

        let base;
        if (expr === null) 
            base = new Ast::LexicalRef (makeIdentifier (path[0],cx.getOpenNamespaces()));
        else 
            base = new Ast::ObjectRef (expr, makeIdentifier (path[0],cx.getOpenNamespaces()));
        return resolvePath (path.slice (1, path.length), base);
    }

    function superExpression(alpha: ALPHA) {
        eat(Token::Super);
        return new Ast::SuperExpr(null);
    }

    function propertyOperator (obj: Ast::EXPR) : [Ast::EXPR] {
        switch (hd ()) {
        case Token::Dot:
            switch (hd2 ()) {
            case Token::LeftParen:
                Parse::internalError(this, "Filter operator not implemented");

            default:
                eat(Token::Dot);
                return new Ast::ObjectRef (obj, propertyName ());
            }
        case Token::LeftBracket:
            return new Ast::ObjectRef (obj, new Ast::ExpressionIdentifier (brackets(), cx.getOpenNamespaces()));

        case Token::DoubleDot:
            Parse::internalError(this, "descendents operator not implemented");

        default:
            Parse::internalError("propertyOperator: " + hd());
        }
    }

    function argumentList () {
        let args = [];

        eat(Token::LeftParen);
        if (hd() != Token::RightParen) {
            do 
                args.push(assignmentExpression(allowColon, allowIn));
            while (match(Token::Comma));
        }
        eat(Token::RightParen);

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

    function memberExpression (alpha:ALPHA, beta:BETA) : Ast::EXPR {
        switch (hd ()) {
        case Token::New:
            next();
            let object_expr = memberExpression (alpha, beta);
            let argument_exprs = argumentList ();
            return memberExpressionPrime (alpha, beta, new Ast::NewExpr (object_expr,argument_exprs));
        case Token::Super:
            let super_expr = superExpression (alpha);
            let property_expr = propertyOperator (super_expr);
            return memberExpressionPrime (alpha, beta, property_expr);
        default:
            let expr = primaryExpression (alpha, beta);
            return memberExpressionPrime (alpha, beta, expr);
        }
    }

    function memberExpressionPrime (alpha: ALPHA, beta:BETA, expr: Ast::EXPR) : Ast::EXPR {
        switch (hd ()) {
        case Token::LeftBracket:
        case Token::Dot:
        case Token::DoubleDot:
            return memberExpressionPrime (alpha, beta, propertyOperator (expr));
        default:
            return expr;
        }
    }

    function callExpression (alpha:ALPHA, beta:BETA) : Ast::EXPR {
        let pos = position();
        let object_expr = memberExpression (alpha, beta);
        let argument_exprs = argumentList ();

        return callExpressionPrime (beta, new Ast::CallExpr (object_expr,argument_exprs,pos));
    }

    // shared among many
    function callExpressionPrime (beta:BETA, call_expr: Ast::EXPR) : Ast::EXPR {
        switch (hd ()) {
        case Token::LeftParen:
            let pos = position();
            let argument_exprs = argumentList ();
            return callExpressionPrime (beta, new Ast::CallExpr (call_expr, argument_exprs, pos));
        case Token::LeftBracket:
        case Token::Dot:
        case Token::DoubleDot:
            return callExpressionPrime (beta, propertyOperator (call_expr));
        default:
            return call_expr;
        }
    }

    function newExpression (alpha:ALPHA, beta:BETA, new_count=0) : Ast::EXPR {
        let call_expression, is_new;

        if (is_new = match(Token::New))
            call_expression = newExpression (alpha, beta, new_count+1);
        else
            call_expression = memberExpression(alpha, beta);

        if (hd() == Token::LeftParen) {   // No more new exprs so this paren must start a call expr
            let pos = position();
            let argument_exprs = argumentList ();
            if (new_count > 0)
                return new Ast::NewExpr (call_expression, argument_exprs);
            return callExpressionPrime (beta, new Ast::CallExpr (call_expression, argument_exprs, pos));
        }

        if (new_count > 0)
            return new Ast::NewExpr (call_expression, []);

        if (is_new)
            return memberExpressionPrime (alpha, beta, call_expression);
        return call_expression;
    }

    function leftHandSideExpression (alpha: ALPHA, beta:BETA) : Ast::EXPR {
        let operator = (hd() == Token::New) ? newExpression (alpha, beta, 0) : memberExpression (alpha, beta);
        if (hd () == Token::LeftParen) {
            let pos = position();
            let args = argumentList ();
            return callExpressionPrime (beta, new Ast::CallExpr (operator, args, pos));
        }
        return operator;
    }

    function postfixExpression (alpha: ALPHA, beta:BETA) : Ast::EXPR {
        let expr = leftHandSideExpression (alpha, beta);
        if (noNewline()) {
            if (match(Token::PlusPlus))
                return new Ast::UnaryExpr (Ast::postIncrOp, expr);
            if (match(Token::MinusMinus))
                return new Ast::UnaryExpr (Ast::postDecrOp, expr);
        }

        return expr;
    }

    function unaryExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let t;

        switch (t = hd ()) {
        case Token::Delete:
        case Token::PlusPlus:
        case Token::MinusMinus:
            next();
            return new Ast::UnaryExpr(Ast::tokenToOperator[t + 1000], postfixExpression (alpha, beta));

        case Token::Void:
        case Token::TypeOf:
        case Token::Plus:
        case Token::Minus:
        case Token::BitwiseNot:
        case Token::Not:
            next();
            return new Ast::UnaryExpr(Ast::tokenToOperator[t + 1000], unaryExpression (alpha, beta));

        case Token::Type:
            next();
            return new Ast::TypeExpr(nullableTypeExpression ());

        default:
            return postfixExpression(alpha, beta);
        }
    }

    function multiplicativeExpression (alpha, beta:BETA) : Ast::EXPR {
        let expr = unaryExpression (alpha, beta);
        let t;

        while (Token::isMultiplicative(t = hd()) || t == Token::BREAK) {
            if (t == Token::BREAK) {
                div();
                if (!Token::isMultiplicative(t = hd()))
                    break;
            }
            next();
            expr = new Ast::BinaryExpr(Ast::tokenToOperator[t], expr, unaryExpression(alpha, beta));
        }

        return expr;
    }

    function additiveExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let expr = multiplicativeExpression (alpha, beta);
        let t;

        while (Token::isAdditive(t = hd())) {
            next();
            expr = new Ast::BinaryExpr(Ast::tokenToOperator[t], expr, multiplicativeExpression(alpha, beta));
        }
        return expr;
    }

    function shiftExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let expr = additiveExpression (alpha, beta);
        let t;

        while (Token::isShift(t = hd())) {
            next();
            expr = new Ast::BinaryExpr(Ast::tokenToOperator[t], expr, additiveExpression(alpha, beta));
        }

        return expr;
    }

    // FIXME: Why would we distinguish between BinaryTypeExpr and
    // BinaryExpr here, as long as the operator gives it away
    // anyhow?  (Note we must still dispatch on the subparser).

    function relationalExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let expr = shiftExpression (alpha, beta);
        let t;

        while (Token::isRelational(t = hd(), beta != noIn)) {
            next();
            if (Token::isRelationalType(t))
                expr = new Ast::BinaryTypeExpr(Ast::tokenToOperator[t], expr, typeExpression());
            else 
                expr = new Ast::BinaryExpr(Ast::tokenToOperator[t], expr, shiftExpression(alpha, beta));
        }

        return expr;
    }

    function equalityExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let expr = relationalExpression (alpha, beta);
        let t;

        while (Token::isEquality(t = hd())) {
            next();
            expr = new Ast::BinaryExpr (Ast::tokenToOperator[t], expr, relationalExpression (alpha, beta));
        }

        return expr;
    }

    function bitwiseAndExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let expr = equalityExpression (alpha, beta);

        while (match(Token::BitwiseAnd))
            expr = new Ast::BinaryExpr (Ast::bitwiseAndOp, expr, equalityExpression (alpha, beta));

        return expr;
    }

    function bitwiseXorExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let expr = bitwiseAndExpression (alpha, beta);

        while (match(Token::BitwiseXor))
            expr = new Ast::BinaryExpr (Ast::bitwiseXorOp, expr, bitwiseAndExpression (alpha, beta));

        return expr;
    }

    function bitwiseOrExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let expr = bitwiseXorExpression (alpha, beta);

        while (match(Token::BitwiseOr)) 
            expr = new Ast::BinaryExpr (Ast::bitwiseOrOp, expr, bitwiseXorExpression (alpha, beta));

        return expr;
    }

    function logicalAndExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let expr = bitwiseOrExpression (alpha, beta);

        while (match(Token::LogicalAnd)) 
            expr = new Ast::BinaryExpr (Ast::logicalAndOp, expr, bitwiseOrExpression (alpha, beta));

        return expr;
    }

    function logicalXorExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let expr = logicalAndExpression (alpha, beta);

        while (match(Token::LogicalXor))
            expr = new Ast::BinaryExpr (Ast::logicalXor, expr, logicalAndExpression (alpha, beta));

        return expr;
    }

    function logicalOrExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let expr = logicalXorExpression (alpha, beta);

        while (match(Token::LogicalOr)) 
            expr = new Ast::BinaryExpr (Ast::logicalOrOp, expr, logicalXorExpression (alpha, beta));

        return expr;
    }

    function letExpression(alpha:ALPHA, beta: BETA) {
        eat(Token::Let);
        eat(Token::LeftParen);
        let [fixtures, inits] = variableBindingList(beta, Ast::noNS, Ast::letInit, false);
        eat(Token::RightParen);
        let expr = commaExpression(alpha, beta);  // FIXME: grammar says assignmentExpression
        return new Ast::LetExpr(new Ast::Head(fixtures, inits), expr);
    }

    function yieldExpression(alpha: ALPHA, beta: BETA) {
        cx.topFunction().uses_yield = true;
        eat(Token::Yield);
        let expr = assignmentExpression(alpha, beta);  // FIXME: according to spec, but probably optimizing the wrong good
        return new Ast::YieldExpr(expr);
    }

    function nonAssignmentExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        switch (hd ()) {
        case Token::Let:
            return letExpression (alpha, beta);

        case Token::Yield:
            return yieldExpression (alpha, beta);

        default: {
            let expr = logicalOrExpression (alpha, beta);
            if (match(Token::QuestionMark)) {
                let consequent = nonAssignmentExpression (noColon, beta);
                eat (Token::Colon);
                let alternate = nonAssignmentExpression (alpha, beta);
                return new Ast::TernaryExpr (expr, consequent, alternate);
            }
            return expr;
        }
        }
    }

    function conditionalExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        switch (hd ()) {
        case Token::Let:
            return letExpression (alpha, beta);

        case Token::Yield:
            return yieldExpression (alpha, beta);

        default: {
            let expr = logicalOrExpression (alpha, beta);
            if (match(Token::QuestionMark)) {
                let consequent = assignmentExpression (noColon, beta); 
                eat (Token::Colon);
                let alternate = assignmentExpression (alpha, beta);
                return new Ast::TernaryExpr (expr, consequent, alternate);
            }
            return expr;
        }
        }
    }

    function assignmentExpression (alpha: ALPHA, beta: BETA) : Ast::EXPR {
        let lhs = conditionalExpression (alpha, beta);
        let t;

        if ((t = hd()) == Token::Assign || Token::isOpAssign(t)) {
            next();
            let pat = patternFromExpr (lhs);
            if (t != Token::Assign && !(pat is SimplePattern))
                Parse::internalError(this, "The lhs of op= must be a name or property reference.");
            let rhs = assignmentExpression (alpha, beta);
            let [fxtrs,expr,head] = desugarAssignmentPattern (pat,Ast::anyType,rhs,Ast::tokenToOperator[t]);
            return expr;
        }
        return lhs;
    }

    // FIXME: This looks partial.  There can't be holes in array
    // patterns here.

    function patternFromExpr (e: Ast::EXPR) {
        if (e is Ast::LexicalRef || e is Ast::ObjectRef)
            return new SimplePattern (e);

        if (e is Ast::LiteralArray)
            return new ArrayPattern( Util::map(patternFromExpr, e.exprs) );

        if (e is Ast::LiteralObject)
            return new ObjectPattern( Util::map(function (f) { return new FieldPattern (f.ident, f.expr || f.ident) }, 
                                                e.fields) );

        Parse::internalError(this, "patternFromExpr, unhandled or invalid expression kind " + e);
    }

    function commaExpression(alpha: ALPHA, beta: BETA): Ast::EXPR {
        let expr = assignmentExpression(alpha, beta);
        while (match(Token::Comma))
            expr = new Ast::BinaryExpr(Ast::commaOp, expr, assignmentExpression(alpha, beta));
        return expr;
    }

    // PATTERNS

    function pattern (beta: BETA, gamma: GAMMA) : PATTERN {
        switch (hd ()) {
        case Token::LeftBrace:   return objectPattern (gamma);
        case Token::LeftBracket: return arrayPattern (gamma);
        default:                 return simplePattern (beta, gamma);
        }
    }

    function simplePattern (beta: BETA, gamma: GAMMA) : PATTERN {
        switch (gamma) {
        case noExpr:    return new IdentifierPattern (identifier ());
        case allowExpr: return new SimplePattern (leftHandSideExpression (allowColon, beta));
        }
    }

    function arrayPattern (gamma: GAMMA) : Ast::EXPR {
        eat (Token::LeftBracket);
        let pattern = elementListPattern (gamma);
        eat (Token::RightBracket);

        return new ArrayPattern (pattern);
    }

    function elementListPattern (gamma:GAMMA) : Ast::EXPRS {
        let elements = [], element;

        if (hd () !== Token::RightBracket) {
            switch (hd ()) {
            case Token::Comma:
                let pos = position();
                eat(Token::Comma);
                element = new Ast::LiteralUndefined(pos);
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
                    element = new Ast::LiteralUndefined(position());
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

    function objectPattern (gamma: GAMMA) : Ast::EXPR {
        eat (Token::LeftBrace);
        let fields = fieldListPattern (gamma);
        eat (Token::RightBrace);

        return new ObjectPattern (fields); 
    }

    function fieldListPattern (gamma:GAMMA) : Ast::EXPR {
        let fields = [];

        if (hd () != Token::RightBrace) {
            do 
                fields.push (fieldPattern (gamma));
            while (match(Token::Comma));
        }

        return fields;
    }

    function fieldPattern (gamma:GAMMA) : FIELD_PATTERN {
        let field_name = fieldName ();
        let field_pattern;

        if (match(Token::Colon))
            field_pattern = pattern (allowIn,gamma);
        else if (field_name is Ast::Identifier) 
            field_pattern = new IdentifierPattern (field_name.ident);
        else
            Parse::internalError(this, "unsupported fieldPattern " + field_name);

        return new FieldPattern (field_name, field_pattern);
    }

    function typedPattern (beta: BETA) : [PATTERN,Ast::TYPE_EXPR] {
        let the_pattern = pattern (beta,noExpr);

        if (match(Token::Colon)) 
            return [the_pattern, nullableTypeExpression ()];
        return [the_pattern, Ast::anyType];
    }

    // TYPE EXPRESSIONS

    function nullableTypeExpression () : Ast::TYPE_EXPR {
        let t = typeExpression ();

        if (match(Token::QuestionMark))
            return new Ast::NullableType (t,true);
        
        if (match(Token::Not))
            return new Ast::NullableType (t,false);

        return t;
    }

    function typeExpression () : Ast::TYPE_EXPR {
        switch (hd ()) {
        case Token::Mult:        return next(), Ast::anyType;
        case Token::Null:        return next(), Ast::nullType;
        case Token::Undefined:   return next(), Ast::undefinedType;
        case Token::Function:    return functionType();
        case Token::LeftParen:   return unionType();
        case Token::LeftBrace:   return objectType();
        case Token::LeftBracket: return arrayType();
        default:                 return new Ast::TypeName (primaryName ());
        }
    }

    function unionType () : Ast::TYPE_EXPR {
        eat (Token::LeftParen);
        let type_exprs = typeExpressionListBar ();
        eat (Token::RightParen);

        return new Ast::UnionType (type_exprs);
    }

    function objectType () : Ast::TYPE_EXPR {
        eat (Token::LeftBrace);
        let field_types = fieldTypeList ();
        eat (Token::RightBrace);

        return new Ast::ObjectType (field_types);
    }

    function fieldTypeList () : [Ast::FIELD_TYPE] {
        let types = [];
        if (hd () !== Token::RightBrace) {
            do 
                types.push (fieldType ());
            while (match(Token::Comma));
        }
        return types;
    }

    function fieldType () : Ast::FIELD_TYPE {
        let name = fieldName ();
        eat (Token::Colon);
        let t = nullableTypeExpression ();

        return new Ast::FieldType(name, t);
    }

    function arrayType () : Ast::TYPE_EXPR {
        eat (Token::LeftBracket);
        let elements = elementTypeList ();
        eat (Token::RightBracket);

        return new Ast::ArrayType (elements);
    }

    function elementTypeList () : [Ast::ELEMENT_TYPE] {
        let element_types = [];

        if (hd () !== Token::RightBracket) {
            let pos = position();
            switch (hd ()) {
            case Token::Comma:
                eat(Token::Comma);
                element_types.push( new Ast::LiteralUndefined(pos) );
                break;
            default:
                element_types.push( nullableTypeExpression () );
                break;
            }

            while (match(Token::Comma)) {
                let pos = position();
                switch (hd ()) {
                case Token::Comma:
                    element_types.push( new Ast::LiteralUndefined(pos) );
                    break;
                default:
                    element_types.push( nullableTypeExpression () );
                    break;
                }
            }
        }

        return element_types;
    }

    function typeExpressionList () : [Ast::TYPE_EXPR]
        listOfNullableTypeExpressions(Token::Comma);

    function typeExpressionListBar () : [Ast::TYPE_EXPR]
        listOfNullableTypeExpressions(Token::BitwiseOr);

    function listOfNullableTypeExpressions(separator) {
        let types = [];
        do 
            types.push (nullableTypeExpression ()); 
        while (match(separator))
            return types;
    }

    // STATEMENTS

    function statement (omega: OMEGA) : Ast::Stmt {
        switch (hd()) {
        case Token::LeftBrace: return new Ast::BlockStmt( statementBlock() );
        case Token::Break:     return let (stmt = breakStatement ()) semicolon(omega), stmt;
        case Token::Continue:  return let (stmt = continueStatement ()) semicolon(omega), stmt;
        case Token::Do:        return let (stmt = doStatement(omega)) semicolon(omega), stmt;
        case Token::For:       return forStatement(omega);
        case Token::If:        return ifStatement(omega);
        case Token::Return:    return let (stmt = returnStatement()) semicolon(omega), stmt;
        case Token::Switch:    return (hd2() == Token::Type) ? switchTypeStatement() : switchStatement();
        case Token::Throw:     return let (stmt = throwStatement()) semicolon(omega), stmt;
        case Token::Try:       return tryStatement ();
        case Token::While:     return whileStatement(omega);
        case Token::With:      return withStatement (omega);
        default:
            if (hd() == Token::Identifier && hd2() == Token::Colon)
                return labeledStatement ();
            return let (stmt = expressionStatement ()) semicolon(omega), stmt;
        }
    }

    function substatement (omega: OMEGA) : Ast::Stmt {
        if (match(Token::SemiColon))
            return new Ast::EmptyStmt;
        return statement (omega);
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

    function noNewline() {
        switch (hd ()) {
        case Token::EOS:
        case Token::SemiColon:
        case Token::RightBrace:
            return false;
        default:
            if (newline())
                return false;
            return true;
        }
    }

    function statementBlock () : Ast::BLOCK {
        eat (Token::LeftBrace);
        cx.enterBlock ();
        let directive_list = directivesLocal(fullStmt);
        let head = cx.exitBlock ();
        eat (Token::RightBrace);

        return new Ast::Block (head, directive_list);
    }

    function labeledStatement () : Ast::Stmt {
        let label = identifier ();
        eat(Token::Colon);

        let stmt = substatement(fullStmt);

        let s = stmt;
        while (s is Ast::LabeledStmt)
            s = s.stmt;
        if (s is ILabelSet)
            s.labels.push(label);

        return new Ast::LabeledStmt(label, stmt);
    }

    function expressionStatement () : Ast::Stmt
        new Ast::ExprStmt (commaExpression (allowColon, allowIn));

    function returnStatement () : Ast::Stmt {
        eat (Token::Return);
        return new Ast::ReturnStmt (noNewline() ? commaExpression(allowColon, allowIn) : null);
    }

    function breakStatement () : Ast::Stmt
        new Ast::BreakStmt( breakOrContinueLabel(Token::Break) );

    function continueStatement () : Ast::Stmt
        new Ast::ContinueStmt( breakOrContinueLabel(Token::Continue) );

    function breakOrContinueLabel(tok) {
        eat(tok);
        return noNewline() ? identifier() : null;
    }

    function ifStatement (omega) : Ast::Stmt {
        eat(Token::If);
        let test = parenExpression();
        let consequent = substatement(omega);
        let alternate = null;
        if (match(Token::Else))
            alternate = substatement(omega);

        return new Ast::IfStmt(test, consequent, alternate);
    }

    function whileStatement (omega) : Ast::Stmt {
        eat(Token::While);
        let test = parenExpression();
        let body = substatement(omega); 
 
        return new Ast::WhileStmt (test, body);
    }

    function doStatement (omega) : Ast::Stmt {
        eat(Token::Do);
        let body = substatement(omega); 
        eat(Token::While);
        let test = parenExpression ();
 
        return new Ast::DoWhileStmt (test, body);
    }

    function forStatement (omega: OMEGA) : Ast::Stmt {
        cx.enterBlock ();

        eat (Token::For);
        let is_each = match(Token::Each);
        eat (Token::LeftParen);
        let init = forInitialiser ();
        if (match(Token::In)) {
            let objexpr = commaExpression (allowColon, allowIn);
            eat (Token::RightParen);
            let body = substatement (omega); 
            let head = cx.exitBlock ();
                
            return new Ast::ForInStmt (head,init,objexpr,body,is_each);
        }
        else {
            if (is_each)
                Parse::syntaxError(this, "'for each' requires 'in' style loop");
            eat (Token::SemiColon);
            let test = hd() == Token::SemiColon ? null : commaExpression(allowColon, allowIn);
            eat (Token::SemiColon);
            let update = hd() == Token::RightParen ? null : commaExpression(allowColon, allowIn);
            eat (Token::RightParen);
            let body = substatement (omega); 
            let head = cx.exitBlock ();
                
            return new Ast::ForStmt (head,init,test,update,body);
        }
    }

    function forInitialiser () : Ast::EXPR? {
        switch (hd ()) {
        case Token::SemiColon:
            return null;

        case Token::Const:
        case Token::Let:
        case Token::Var:
            return bindingForInitialiser();

        default:
            return commaExpression (allowColon, noIn);
        }
    }

    function bindingForInitialiser() {
        let [it, ro] = variableDefinitionKind(localBlk);
        let in_allowed = true;
        let init_expr = null;

        for (;;) {
            let [pattern, annotation] = typedPattern (noIn);
            let initializer = null;

            if (match(Token::Assign))
                initializer = assignmentExpression (allowColon, noIn);
            else
                initializer = new Ast::LiteralUndefined();  // Probably wrong, see comment below

            if (hd() != Token::Comma && hd() != Token::SemiColon)
                break;

            let [fixtures,init] = desugarBindingPattern (pattern, annotation, initializer, cx.getDefaultNamespace(), it, ro);

            cx.addFixtures(it, fixtures);

            init_expr = init_expr ? new Ast::BinaryExpr(Ast::commaOp, init_expr, init) : init;

            if (hd() == Token::SemiColon)
                return init_expr;

            in_allowed = false;
            eat(Token::Comma);
        }

        if (hd() != Token::In)
            Parse::syntaxError("'in' is required here");

        if (!in_allowed)
            Parse::syntaxError("'in' does not allow multiple binding clauses in the loop head.");

        // FIXME: More elaborate handling of patterns here.
        // A destructuring pattern is legal in a for-in head
        // even if it does not have an initializing expression.
        if (!(pattern is IdentifierPattern))
            Parse::internalError(this, "Identifier pattern required by for-in binding (for now)");

        if (initializer == null) {
            // FIXME: This is wrong, because it may overwrite a hoisted var that 
            // should not be overwritten if the loop body is never entered.
            initializer = new Ast::LiteralUndefined();
        }

        let [fixtures,init] = desugarBindingPattern (pattern,annotation,initializer,cx.getDefaultNamespace(),it,ro);
        if (init == null)
            Parse::syntaxError(this, "forInitialiser: " + init);
            
        cx.addFixtures(it, fixtures);
        return init;
    }

    function switchStatement () : Ast::Stmt {
        eat (Token::Switch);
        let expr = parenExpression ();

        eat (Token::LeftBrace);
        let cases = null;
        if (hd () == Token::Case || hd() == Token::Default) 
            cases = caseElements ();
        eat (Token::RightBrace);

        return new Ast::SwitchStmt (expr, cases);
    }

    function caseElements () : Ast::CASES {
        let cases = [];
        let hasDefault = false;
        loop:
        for (;;) {
            switch (hd ()) {
            case Token::RightBrace:
                break loop;
            case Token::Default:
                eat(Token::Default);
                eat(Token::Colon);
                if (hasDefault)
                    Parse::syntaxError(this, "Duplicate 'default' clause in 'switch'");
                hasDefault = true;
                cases.push(new Ast::Case(null, []));
                break;
            case Token::Case: {
                eat(Token::Case);
                let item = commaExpression(allowColon, allowIn);
                eat(Token::Colon);
                cases.push (new Ast::Case (item,[]));
                break;
            }
            default: {
                let items = directivesLocal(1);            // 'abbrev' is handled by RightBrace check in head
                Util::pushOnto(cases[cases.length-1].stmts, items);
                break;
            }
            }
        }

        return cases;
    }

    function throwStatement () : Ast::Stmt {
        eat (Token::Throw);
        return new Ast::ThrowStmt( commaExpression (allowColon, allowIn) );
    }

    function tryStatement () : Ast::Stmt {
        eat (Token::Try);

        let tryblock = statementBlock ();
        let catchblocks = catches ();
        let finallyblock = null;

        if (match(Token::Finally)) {
            cx.topFunction().uses_finally = true;
            finallyblocks = statementBlock ();
        }

        return new Ast::TryStmt (tryblock,catchblocks,finallyblock);
    }

    function catches () : Ast::CATCHES {
        let catchblocks = [];

        while (match(Token::Catch))
            catchblocks.push (catchClause ());

        cx.topFunction().uses_catch = catchblocks.length > 0;
        return catchblocks;
    }

    function catchClause () : Ast::CATCH {
        eat (Token::LeftParen);
        let catchvar = parameter ();
        eat (Token::RightParen);
        let catchblock = statementBlock ();

        let [k,[p,t]] = catchvar;
        let [f,i] = desugarBindingPattern (p, t, new Ast::GetParam (0), Ast::noNS, Ast::varInit, false);
        let head = new Ast::Head (f,[i]);

        return new Ast::Catch (head,catchblock);
    }

    function withStatement (omega: OMEGA) : Ast::Stmt {
        eat (Token::With);
        cx.topFunction().uses_with = true;
        let expr = parenExpression ();
        let body = substatement (omega);
        return new Ast::WithStmt (expr, body);
    }

    function switchTypeStatement () : Ast::Stmt {
        eat (Token::Switch);
        eat (Token::Type);
        let expr  = typedExpression ();
        let [e,t] = expr;
        eat (Token::LeftBrace);
        let typecases = typeCases ();
        eat (Token::RightBrace);

        return new Ast::SwitchTypeStmt (e,t,typecases);
    }

    function typedExpression () : [Ast::EXPR,Ast::TYPE_EXPR] {
        let expr = parenExpression ();
        let texpr = match(Token::Colon) ? nullableTypeExpression () : Ast::anyType;
        return [expr,texpr];
    }

    function typeCases () : Ast::CATCHES {
        let cases = [];
        while (match(Token::Case))
            cases.push(catchClause());
        return cases;
    }

    // DEFINITIONS

    function variableDefinition (beta: BETA, tau: TAU, attrs) : Ast::EXPR? {
        let [it, ro] = variableDefinitionKind (tau);
        let [fxtrs,exprs] = variableBindingList (beta, attrs.ns, it, ro);

        cx.addFixtures (it, fxtrs, attrs.static);
        if (tau == classBlk && !attrs.static) {
            cx.addInits(it, exprs);
            return null;
        }
        return exprListToCommaExpr(exprs);
    }

    function variableDefinitionKind (tau: TAU) {
        if (match(Token::Const)) {
            if (match(Token::Function))
                Parse::syntaxError(this, "'const function' not allowed here");
            return [tau == classBlk ? Ast::varInit : Ast::letInit, true];
        }

        if (match(Token::Var))
            return [Ast::varInit, false];

        if (match(Token::Let))
            return [Ast::letInit, false];

        Parse::syntaxError(this, "Illegal binding keyword " + lexeme());
    }

    function variableBindingList (beta: BETA, ns: Ast::NAMESPACE, it: Ast::INIT_TARGET, ro: boolean ) : [Ast::FIXTURES, Ast::EXPRS] {
        let fixtures = [], exprs = [];
        do
            variableBinding(beta, ns, it, ro, fixtures, exprs);
        while (match(Token::Comma));
        return [fixtures, exprs];
    }

    function variableBinding (beta, ns, it, ro, fixtures, exprs) {
        let [pattern, annotation] = typedPattern (beta);
        let initializer;
        let f, i;

        if (match(Token::Assign))
            initializer = assignmentExpression (allowColon, beta);
        else if (!(pattern is IdentifierPattern)) 
            Parse::syntaxError(this, "destructuring pattern without initializer");
        else
            initializer = new Ast::LiteralUndefined();
        [f,i] = desugarBindingPattern (pattern,annotation,initializer,ns,it,ro);

        Util::pushOnto(fixtures, f);
        exprs.push(i);
    }

    function functionDefinition (tau: TAU, omega: OMEGA, attrs: ATTRS) : Ast::STMTS {
        let is_const = match(Token::Const);  // FIXME: not currently used
        eat (Token::Function);

        cx.enterFunction(attrs);

        let name = functionName ();
        let signature = functionSignature ();
        let body;

        if (attrs.native || tau == interfaceBlk) {
            semicolon(fullStmt);
            body = new Ast::Block(null, []);
        }
        else 
            body = functionBody (allowIn, omega);

        let [vars,attr] = cx.exitFunction();

        let {params, defaults, resultType, thisType, numparams} = signature;
        let func = new Ast::Func (name, body, params, numparams, vars, defaults, resultType, attr);

        let name = new Ast::PropName (new Ast::Name(attrs.ns, name.ident));
        let fxtr = new Ast::MethodFixture (func, Ast::anyType, true, attrs.override, attrs.final);
        cx.addFixture(tau == localBlk ? Ast::letInit : Ast::varInit, name, fxtr, attrs.static);
    }

    function functionExpression (skip_header=false) : Ast::EXPR {
        let name = null;
        let signature;
        let pos = position();
        
        cx.enterFunction(makeAttrs());

        if (!skip_header) {
            eat (Token::Function);
            if (hd () == Token::Identifier)
                name = functionName ();
            signature = functionSignature ();
        }
        else
            signature = emptySignature();

        let body = functionBody (allowIn, fullStmt);

        let [vars,attr] = cx.exitFunction();

        let {params, numparams, defaults, resultType} = signature;
        let fnexpr = new Ast::LiteralFunction(new Ast::Func(name, 
                                                            body, 
                                                            params, 
                                                            numparams,
                                                            vars, 
                                                            defaults, 
                                                            resultType,
                                                            attr),
                                              pos);

        return fnexpr;
    }

    function constructorDefinition (omega, ns, attrs) : Ast::STMTS {
        eat (Token::Function);

        cx.enterFunction(attrs);

        let name = identifier ();
        let signature = constructorSignature ();
        let body;

        if (attrs.native) {
            semicolon(fullStmt);
            body = new Ast::Block(null, []);
        }
        else
            body = functionBody (allowIn, omega);  // bogus, expression closure not allowed in constructors

        let [vars,attr] = cx.exitFunction();

        let {params, defaults, settings, superArgs, numparams} = signature;

        let func = new Ast::Func (new Ast::FuncName(Ast::ordinaryFunction, name), 
                                  body, 
                                  params, 
                                  numparams, 
                                  vars, 
                                  defaults, 
                                  Ast::voidType, 
                                  attr);
        return new Ast::Ctor (settings,superArgs,func);
    }

    static type CTOR_SIG = 
    { typeParams : [Ast::IDENT]
      , params : Ast::HEAD
      , paramTypes : [Ast::TYPE_EXPR]
      , defaults : [Ast::EXPR]
      , settings : [Ast::EXPR]
      , superArgs: [Ast::EXPR] }

    static type FUNC_SIG = 
    { typeParams : [Ast::IDENT]
      , params : Ast::HEAD
      , paramTypes : [Ast::TYPE_EXPR]
      , defaults : [Ast::EXPR]
      , resultType : Ast::TYPE_EXPR
      , thisType : Ast::TYPE_EXPR? }

    function constructorSignature () : CTOR_SIG {
        eat (Token::LeftParen);
        let ps = parameters ();
        eat (Token::RightParen);
        let [settings,superArgs] = constructorInitialiser ();

        // Translate bindings and init steps into fixtures and inits (HEAD)
        let { fixtures, inits, exprs, types, numparams } = ps;

        return { typeParams: []
                                 , params: new Ast::Head (fixtures,inits)
                                 , paramTypes: types
                                 , numparams: numparams
                                 , defaults: exprs
                                 , settings: settings
                                 , superArgs: superArgs };
    }

    /*

    constructor initializers are represented by two lists. the first
    list represents the initializers and will consist of set exprs or
    let exprs (if there are temps for destructuring). the second list
    represents the arguments to the call the the super constructor

    */

    function constructorInitialiser () : [[Ast::EXPR], [Ast::EXPR]] {
        let settings=[];
        let superargs=null;

        if (match(Token::Colon)) {
            while (hd() != Token::Super) {
                settings.push(setting());
                if (!match(Token::Comma))
                    break;
            }
            if (match(Token::Super))
                superargs = argumentList();
        }

        return [settings, superargs || []];
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
        let lhs = pattern (allowIn,allowExpr);
        eat (Token::Assign);
        let rhs = assignmentExpression (allowColon, allowIn);

        let [fxtrs,inits] = desugarBindingPattern (lhs, Ast::anyType, rhs, null, Ast::instanceInit, null);
        // FIXME: assert fxtrs is empty

        return inits;
    }

    // FIXME: needs to handle plain functions called 'get' and 'set'
    // FIXME: needs to handle catchalls

    function functionName () : Ast::FUNC_NAME {
        let kind;

        if (match(Token::Get))      kind = Ast::getterFunction;
        else if (match(Token::Set)) kind = Ast::setterFunction;
        else                        kind = Ast::ordinaryFunction;

        let ident = identifier();
        return new Ast::FuncName(kind, ident);
    }

    function functionSignature () : FUNC_SIG {
        let type_params = typeParameters (); // FIXME: not used

        eat (Token::LeftParen);
        if (match(Token::This)) {
            // FIXME implement this
            Parse::internalError(this, "No support for 'this' annotation in parameter list");
        }
        let ps = parameters();
        eat (Token::RightParen);
        let restype = resultType ();

        // Translate bindings and init steps into fixtures and inits (HEAD)
        let { fixtures, inits, exprs, types, numparams } = ps;
        return  { typeParams: []
                , params: new Ast::Head (fixtures,inits)
                , paramTypes: types
                , numparams: numparams
                , defaults: exprs
                , ctorInits: null
                , resultType: restype
                , thisType: null };
    }

    function emptySignature() {
        return { typeParams: []
               , params: new Ast::Head([],[])
               , paramTypes: []
               , numparams: 0
               , defaults: []
               , ctorInits: null
               , resultType: Ast::anyType
               , thisType: null };
    }

    function typeParameters () : [Ast::IDENT] {
        if (match(Token::LeftDotAngle))
            return let (tparams = typeParameterList()) eat(Token::GreaterThan), tparams;
        return [];
    }

    function typeParameterList () : [Ast::IDENT] {
        let tparams = [];
        do
            tparams.push(identifier ());
        while(match(Token::Comma));
        return tparams;
    }

    static type PARAMETERS = {
        fixtures: [Ast::FIXTURE_BINDING],
        inits: [Ast::EXPR],
        exprs: [Ast::EXPR],
        types: [Ast::TYPE_EXPR],
        numparams: *
    };

    function parameters () : PARAMETERS {
        let params = { fixtures: [], inits: [], exprs: [], types: [], numparams: 0 };
        let initRequired = false;

        while (hd() != Token::RightParen) {
            if (hd() == Token::TripleDot) {
                cx.topFunction().uses_rest = true;
                restParameter (params);
                break;
            }

            initRequired = parameterInit(params, initRequired);
            params.numparams++;

            if (!match(Token::Comma))
                break;
        }
        return params;
    }

    function restParameter(params) {
        eat(Token::TripleDot);
        let [f, i] =
            desugarBindingPattern(simplePattern(noIn, noExpr), 
                                  Ast::anyType, 
                                  new Ast::GetParam(params.numparams), 
                                  Ast::noNS, 
                                  Ast::letInit, 
                                  false);
        f.push([new Ast::TempName(params.numparams), new Ast::ValFixture(Ast::anyType,false)]);

        Util::pushOnto(params.fixtures, f);
        params.inits.push(i);
        params.types.push(Ast::anyType);
    }

    function parameterInit (params, initRequired) {
        let param = parameter ();
        let initexpr = null;

        if (match(Token::Assign))
            initexpr = nonAssignmentExpression(allowColon, allowIn);
        else if (initRequired)
            Parse::syntaxError(this, "Expecting default value expression");

        let [k,[p,t]] = param;
        let [f,i] = desugarBindingPattern (p, t, new Ast::GetParam (params.numparams), Ast::noNS, Ast::letInit, false);
        f.push ([new Ast::TempName (params.numparams), new Ast::ValFixture (t,false)]); // temp for desugaring

        Util::pushOnto(params.fixtures, f);
        params.inits.push(i);
        if (initexpr)
            params.exprs.push(initexpr);
        params.types.push(t);

        return initexpr != null;
    }

    function parameter () : [Ast::VAR_DEFN_TAG, [PATTERN, Ast::TYPE_EXPR]] {
        let kind = match(Token::Const) ? Ast::constTag : Ast::varTag;
        var pattern = typedPattern (allowIn);
        return [kind,pattern];
    }

    function resultType () : [Ast::IDENT] {
        if (match(Token::Colon)) {
            if (match(Token::Void))
                return Ast::voidType;
            return nullableTypeExpression ();
        }
        return Ast::anyType;
    }

    // FIXME: this should just return a directive_list, the head is always empty
    function functionBody (beta: BETA, omega) : Ast::BLOCK {
        if (match(Token::LeftBrace)) {
            let directive_list = directivesLocal(fullStmt);
            eat (Token::RightBrace);

            return new Ast::Block (new Ast::Head([],[]), directive_list);
        }

        let expr = assignmentExpression (allowColon, beta);
        semicolon (omega);
        return new Ast::Block (new Ast::Head ([],[]),[new Ast::ReturnStmt (expr)]);
    }

    // Instance variables are initialized by executing initializing
    // expressions in top-to-bottom order, then calling the
    // constructor.  'ihead' may have both fixtures and initializing
    // expressions.
    //
    // Class variables are initialized by executing initializing
    // expressions and blocks in top-to-bottom order.  'chead' may
    // have fixtures, but will not have initializing expressions --
    // those are all in the 'body'.

    function classDefinition (attrs): void  {
        eat (Token::Class);

        let classid = identifier ();
        let signature = typeSignature ();                         // FIXME: not used yet
        let superclass = extendsClause();
        let superinterfaces = interfaceList(Token::Implements);
        let protectedNs = new Ast::ProtectedNamespace (classid);  // FIXME: needs to use attrs.ns too!
        let privateNs = new Ast::PrivateNamespace (classid);      // FIXME: needs to use attrs.ns too!

        currentClassName = classid;                               // FIXME: needs to use attrs.ns too!
        cx.enterClassStatic();
        cx.enterClassInstance();
        cx.pushNamespace(protectedNs);
        cx.pushNamespace(privateNs);

        eat (Token::LeftBrace);
        let [directive_list, ctor] = directivesClass();
        eat (Token::RightBrace);

        let body = new Ast::Block(new Ast::Head([],[]), directive_list);

        let ihead = cx.exitClassInstance();
        let chead = cx.exitClassStatic();
        currentClassName = "";

        if (ctor == null)
            ctor = makeDefaultCtor(classid);
            
        let baseName;
        if (superclass == null)
            baseName = new Ast::Name(Ast::noNS, "Object");
        else 
            baseName = superTypeToName(superclass);

        let interfaceNames = Util::map(superTypeToName, superinterfaces);

        let cname = new Ast::Name(attrs.ns, classid);
        let ctype = Ast::anyType;
        let itype = Ast::anyType;
        let cls = new Ast::Cls (cname,
                                baseName,
                                interfaceNames,
                                protectedNs,
                                ctor,
                                chead,
                                ihead,
                                ctype,
                                itype,
                                body,
                                attrs.dynamic,
                                attrs.final);

        cx.addFixture(Ast::varInit, new Ast::PropName(cname), new Ast::ClassFixture (cls));
    }

    function interfaceDefinition(attrs): void {
        eat (Token::Interface);
            
        let interfaceid = identifier ();
        let signature = typeSignature ();       // FIXME: not used yet
        let superinterfaces = interfaceList(Token::Extends);

        currentClassName = "";

        cx.enterClassInstance();
        interfaceBody ();
        let ihead = cx.exitClassInstance();

        let interfaceNames = Util::map(superTypeToName, superinterfaces);
            
        let iname = new Ast::Name(attrs.ns, interfaceid);
        let iface = new Ast::Interface(iname, interfaceNames, ihead);

        cx.addFixture(Ast::varInit, new Ast::PropName(iname), new Ast::InterfaceFixture (iface));
    }

    function makeDefaultCtor(classname) {
        cx.enterFunction(makeAttrs());
        let ctorbody = new Ast::Block (new Ast::Head([],[]),[]);
        let params = new Ast::Head([],[]);
        let numparams = 0;
        let vars = new Ast::Head([],[]);
        let defaults = [];
        let ty = Ast::anyType;
        let attr = cx.exitFunction();
        let func = new Ast::Func (new Ast::FuncName(Ast::ordinaryFunction, classname),
                                  ctorbody,
                                  params,
                                  numparams,
                                  vars,
                                  defaults,
                                  ty,
                                  attr);
        return new Ast::Ctor ([],[], func);
    }

    function superTypeToName(s) {
        switch type (s) {
        case (x:Ast::Identifier) {
            return new Ast::Name(Ast::noNS, x.ident);
        }
        case (x:*) {
            Parse::internalError(this, "Can't handle this base type name " + s);
        }
        }
    }

    function typeSignature () : [[Ast::IDENT], boolean] {
        let type_params = typeParameters ();
        let is_nonnullable = match(Token::Not);

        return [type_params, is_nonnullable];
    }

    function extendsClause() {
        if (match(Token::Extends))
            return primaryName ();
        return null;
    }

    function interfaceList(tok) {  // tok is Token::Extends or Token::Implements
        let names = [];
        if (match(tok)) {
            do 
                names.push(primaryName());
            while (match(Token::Comma));
        }
        return names;
    }

    function interfaceBody() {
        eat(Token::LeftBrace);
        directivesInterface();
        eat(Token::RightBrace);
    }

    function namespaceDefinition (attrs): void {
        eat (Token::Namespace);
        let name = identifier ();
        let initializer = null;

        if (match(Token::Assign)) {
            if (hd () == Token::StringLiteral)
                initializer = let (nsstring = lexeme()) next(), nsstring;
            else
                initializer = cx.resolveNamespaceFromIdentExpr (primaryName ());
        }
        semicolon (fullStmt);

        let nsVal;
        if (initializer === null) 
            nsVal = new Ast::UnforgeableNamespace (getAnonymousName(name));
        else 
            nsVal = new Ast::ForgeableNamespace (initializer);

        let fxname = new Ast::PropName (new Ast::Name(attrs.ns, name));
        let fxtr = new Ast::NamespaceFixture (nsVal);
        cx.addFixture(Ast::varInit, fxname, fxtr, attrs.static);
    }

    // FIXME: not what you want, and anyhow it looks completely
    // ill-defined since any property name is possible in the 
    // global object.

    function getAnonymousName (seedStr) {
        return seedStr;
    }

    function typeDefinition (attrs): void {
        eat (Token::Type);
        let typename = identifier ();
        eat (Token::Assign);
        let typedef = nullableTypeExpression ();
        semicolon (fullStmt);

        var name = new Ast::PropName (new Ast::Name(attrs.ns, typename));
        var fxtr = new Ast::TypeFixture (typedef);
        cx.addFixture(Ast::varInit, name, fxtr, attrs.static);
    }

    // DIRECTIVES

    static const ATTR_FINAL = 1;
    static const ATTR_DYNAMIC = 2;
    static const ATTR_NATIVE = 4;
    static const ATTR_OVERRIDE = 8;
    static const ATTR_PROTOTYPE = 16;
    static const ATTR_STATIC = 32;

    function checkAttr(bitvector, bit, name) {
        if (bitvector & bit)
            Parse::syntaxError(this, "Duplicate '" + name + "' attribute.");
        return bitvector | bit;
    }

    function makeAttrs(ns=null, bits=0) : ATTRS {
        return { ns: ns || cx.getDefaultNamespace()
               , dynamic: (bits & ATTR_DYNAMIC) != 0
               , final: (bits & ATTR_FINAL) != 0
               , native: (bits & ATTR_NATIVE) != 0
               , override: (bits & ATTR_OVERRIDE) != 0
               , prototype: (bits & ATTR_PROTOTYPE) != 0
               , static: (bits & ATTR_STATIC) != 0 }
    }

    // This returns a list of top-level statements in the order
    // they should be evaluated.

    function directivesGlobal(): [Ast::STMT] {
        // pragma, var, let, const, function, type, namespace, class, interface, statement
        let stmts = [];

        while (hd () != Token::RightBrace && hd () != Token::EOS) {
            let attrs = 0;
            let ns = null;
            let labels = null;

            loop:
            for (;;) {
                switch (hd()) {
                case Token::Dynamic:  attrs = checkAttr(attrs, ATTR_DYNAMIC, "dynamic"); next(); break;
                case Token::Final:    attrs = checkAttr(attrs, ATTR_FINAL, "final"); next(); break;
                case Token::Native:   attrs = checkAttr(attrs, ATTR_NATIVE, "native"); next(); break;

                case Token::Use:
                    if (attrs != 0 || ns != null)
                        Parse::syntaxError(this, "Illegal attribute on pragma.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled pragma.");
                    // FIXME: this is a hack
                    pragmas(globalBlk);
                    break loop;

                case Token::Var:
                case Token::Let:
                case Token::Const:
                    if (hd() != Token::Const || hd2() != Token::Function) {
                        if (attrs != 0)
                            Parse::syntaxError(this, "Illegal attribute on variable definition.");
                        let e = variableDefinition (allowIn, globalBlk, makeAttrs(ns, attrs));
                        semicolon(fullStmt);
                        if (e != null) {
                            // explicitly ignoring the labels here
                            stmts.push(new Ast::ExprStmt(e));
                        }
                        break loop;
                    }
                    // otherwise fall through to the 'function' case, for 'const function'

                case Token::Function:
                    if ((attrs & ~ATTR_NATIVE) != 0)
                        Parse::syntaxError(this, "Illegal attribute on function definition.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled function definition.");
                    functionDefinition (globalBlk, fullStmt, makeAttrs(ns, attrs));
                    break loop;

                case Token::Type:
                    if (attrs != 0)
                        Parse::syntaxError(this, "Illegal attribute on type definition.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled type definition.");
                    typeDefinition (makeAttrs(ns, attrs));
                    break loop;

                case Token::Namespace:
                    if (attrs != 0)
                        Parse::syntaxError(this, "Illegal attribute on namespace definition.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled namespace definition.");
                    namespaceDefinition (makeAttrs(ns, attrs));
                    break loop;

                case Token::Class:
                    if ((attrs & ~(ATTR_DYNAMIC | ATTR_FINAL)) != 0)
                        Parse::syntaxError(this, "Illegal attribute on class definition.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled class definition.");
                    classDefinition(makeAttrs(ns, attrs));
                    break loop;

                case Token::Interface:
                    if (attrs != 0)
                        Parse::syntaxError(this, "Illegal attribute on interface definition.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled interface definition.");
                    interfaceDefinition(makeAttrs(ns, attrs));
                    break loop;

                default: {
                    let maybe = statementOrNamespace(stmts, ns, labels);
                    if (maybe)
                        [ns, labels] = maybe;
                    else
                        break loop;
                }
                }
            }
        }

        return stmts;
    }

    // This returns the statements for the instance initializer, and
    // the constructor (or null).  The statements incorporate static
    // intializer blocks.

    function directivesClass(): [Ast::STMT, CTOR] {
        // pragma, var, const, function, type, namespace, static-init
        let stmts = [];
        let ctor = null;

        while (hd () != Token::RightBrace && hd () != Token::EOS) {
            let attrs = 0;
            let ns = null;

            loop:
            for (;;) {
                switch (hd()) {
                case Token::Static:
                    eat(Token::Static);
                    if (noNewline() && hd() == Token::LeftBrace) {
                        stmts.push(new Ast::ExprStmt(new Ast::CallExpr(functionExpression(true), [])));
                        break loop;
                    }
                    else
                        attrs = checkAttr(attrs, ATTR_STATIC, "static");
                    break;

                case Token::Final:     attrs = checkAttr(attrs, ATTR_FINAL, "final"); next(); break;
                case Token::Native:    attrs = checkAttr(attrs, ATTR_NATIVE, "native"); next(); break;
                case Token::Override:  attrs = checkAttr(attrs, ATTR_OVERRIDE, "override"); next(); break;
                case Token::Prototype: attrs = checkAttr(attrs, ATTR_PROTOTYPE, "prototype"); next(); break;

                case Token::Use:
                    // FIXME: This is a hack
                    pragmas(classBlk);
                    break loop;

                case Token::Var:
                case Token::Const: {
                    if ((attrs & ~(ATTR_PROTOTYPE | ATTR_STATIC)) != 0)
                        Parse::syntaxError(this, "Illegal attribute on variable definition.");
                    let e = variableDefinition (allowIn, classBlk, makeAttrs(ns, attrs));
                    semicolon(fullStmt);
                    if (e != null)
                        stmts.push(new Ast::ExprStmt(e));
                    break loop;
                }

                case Token::Function:
                    if (currentClassName == lexeme2()) {
                        if (attrs != 0)
                            Parse::syntaxError(this, "Illegal attribute on constructor function.");
                        if (ctor != null)
                            Parse::syntaxError(this, "A constructor has already been defined for this class.");
                        ctor = constructorDefinition (fullStmt, cx.getDefaultNamespace(), makeAttrs(ns, attrs));
                    }
                    else
                        functionDefinition (classBlk, fullStmt, makeAttrs(ns, attrs));
                    break loop;

                case Token::Type:
                    if ((attrs & ATTR_STATIC) == 0)
                        Parse::syntaxError(this, "'type' definition must be static.");
                    if ((attrs & ~ATTR_STATIC) != 0)
                        Parse::syntaxError(this, "Illegal attribute on type definition.");
                    typeDefinition(makeAttrs(ns, attrs));
                    break loop;

                case Token::Namespace:
                    if ((attrs & ATTR_STATIC) == 0)
                        Parse::syntaxError(this, "'namespace' definition must be static.");
                    if ((attrs & ~ATTR_STATIC) != 0)
                        Parse::syntaxError(this, "Illegal attribute on namespace definition.");
                    namespaceDefinition(makeAttrs(ns, attrs));
                    break loop;

                default: {
                    let pnsn = plausibleNamespaceName();
                    if (pnsn == null)
                        Parse::syntaxError(this, "Property definition or pragma is required here.");
                    if (ns != null)
                        Parse::syntaxError(this, "Duplicate namespace attribute.");
                    ns = pnsn;
                    if (!noNewline())
                        Parse::syntaxError(this, "Line break not allowed here.");
                }
                }
            }
        }
        return [stmts, ctor];
    }

    // This operates by side effect on the context: it defines a
    // type that has no code or data.

    function directivesInterface(): void {
        // function
        while (hd () != Token::RightBrace && hd () != Token::EOS) {
            let ns = null;

            loop:
            for (;;) {
                if (hd() == Token::Function) {
                    functionDefinition(interfaceBlk, fullStmt, makeAttrs(ns, 0));
                    break loop;
                }
                else {
                    let pnsn = plausibleNamespaceName();
                    if (pnsn == null)
                        Parse::syntaxError(this, "'function' is required here.");
                    if (ns != null)
                        Parse::syntaxError(this, "Duplicate namespace attribute.");
                    ns = pnsn;
                    if (!noNewline())
                        Parse::syntaxError(this, "Line break not allowed here.");
                }
            }
        }
    }

    // This returns a list of block-local statements in the order
    // they should be evaluated.

    function directivesLocal(n=1e500): [Ast::STMT] {
        // pragma, var, let, const, function, statement
        let stmts = [];

        while (hd () != Token::RightBrace && hd () != Token::EOS && n-- != 0) {
            let attrs = 0;
            let ns = null;
            let labels = null;

            loop:
            for (;;) {
                switch (hd()) {
                case Token::Use:
                    if (attrs != 0)
                        Parse::syntaxError(this, "Illegal attribute on pragma.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled pragma.");
                    // FIXME: this is a hack
                    pragmas(localBlk);
                    break loop;

                case Token::Var:
                case Token::Let:
                case Token::Const:
                    if (hd() != Token::Const || hd2() != Token::Function) {
                        if (attrs != 0)
                            Parse::syntaxError(this, "Illegal attribute on variable definition.");
                        let e = variableDefinition (allowIn, localBlk, makeAttrs(Ast::noNS, attrs));
                        semicolon(fullStmt);
                        if (e != null)
                            stmts.push(new Ast::ExprStmt(e));
                        break loop;
                    }
                    // otherwise fall through to the 'function' case, for 'const function'

                case Token::Function:
                    if ((attrs & ~ATTR_NATIVE) != 0)
                        Parse::syntaxError(this, "Illegal attribute on function definition.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled function definition.");
                    functionDefinition (localBlk, fullStmt, makeAttrs(Ast::noNS, attrs));
                    break loop;

                default: {
                    let maybe = statementOrNamespace(stmts, ns, labels);
                    if (maybe) {
                        [ns, labels] = maybe;
                        if (ns != null)
                            Parse::syntaxError(this, "Illegal namespace attribute.");
                    }
                    else
                        break loop;
                }
                }
            }
        }

        return stmts;
    }

    function plausibleNamespaceName() {
        switch (hd()) {
        case Token::Public:     // FIXME: remove
        case Token::Private:    // FIXME: remove
        case Token::Protected:  // FIXME: remove
        case Token::Internal:   // FIXME: remove
        case Token::Intrinsic:  // FIXME: remove
            return reservedNamespace();
        case Token::Identifier:
            return cx.evalIdentExprToNamespace (primaryName ());
            // FIXME: also some contextually reserved names
        default:
            return null;
        }
    }

    function statementOrNamespace(stmts, ns, labels) {
        // Maybe this should also allow some contextually reserved names.

        if (hd() == Token::Identifier && hd2() == Token::Colon) {
            if (labels == null)
                labels = [];
            labels.push(lexeme());
            next();
            next();
            return [ns, labels];
        }

        switch (hd()) {
        case Token::SemiColon:
            eat(Token::SemiColon);
            return false;
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
            pushStmt(stmts, labels, statement(fullStmt));
            return false;
        }

        let e = commaExpression (allowColon, allowIn);
        let t = hd();
        if (t == Token::SemiColon || t == Token::RightBrace || t == Token::EOS || newline()) {
            semicolon(fullStmt);
            pushStmt(stmts, labels, new Ast::ExprStmt (e));
            return false;
        }

        if (!(e is Ast::LexicalRef)) // Too restrictive
            Parse::syntaxError(this, "Namespace attribute required here.");
        if (ns != null)
            Parse::syntaxError(this, "Duplicate namespace attribute.");
        ns = cx.evalIdentExprToNamespace(e.ident);
        return [ns, labels];
    }


    function pushStmt(stmts, labels, s) {
        if (labels != null) {
            if (s is ILabelSet)
                Util::pushOnto(s.labels, labels);
            for ( let i=labels.length-1 ; i >= 0 ; --i )
                s = new Ast::LabeledStmt(labels[i], s);
        }
        stmts.push(s);
    }

    // PRAGMAS

    // Works by side effect on cx.
    //
    // But that is wrong?
    //
    // use namespace is cumulative, stmts evaluated later see more
    // namespaces than those evaluated before the pragma.
    //
    // use default namespace sets a value that is in effect in the
    // current scope until new values are seen.
    //
    // use strict affects the interpretation of code while it is
    // effect.

    function pragmas (tau) {
        while (match(Token::Use)) {
            pragmaItems (tau);
            semicolon (fullStmt);
        }
    }

    function pragmaItems (tau) {
        do {
            if (match(Token::Namespace))
                cx.openNamespace (primaryName ());
            else if (match(Token::Default)) {
                eat(Token::Namespace);
                if (tau == localBlk)
                    Parse::syntaxError(this, "Pragma 'use default namespace' is not allowed in blocks.");
                let name = primaryName ();
                cx.setDefaultNamespace(name);
                cx.openNamespace (name);
            }
            else if (match(Token::Strict)) {
                // FIXME: turn on strict mode
            }
            else
                Parse::syntaxError(this, "Unknown token following 'use'");
        } while (match(Token::Comma));
    }

    // PROGRAMS

    // Synthesize attributes in f.

    function computeAttributes(f: FuncAttr) {
        let reify_activation = false;

        // If there's eval then variable lookup will be by name;
        // new names may be added at run-time.

        reify_activation = reify_activation || f.uses_eval;

        // If there's with then variable lookup will be by name;
        // the set of names in the object is generally unknown.
        // (It's possible to do better for objects of known
        // non-dynamic types, but that's unlikely to be a common
        // case.)

        reify_activation = reify_activation || f.uses_with;

        // If there's a nested function definition or function expression 
        // then it will close over its reified scope.
        //
        // FIXME: If the nested function has no free variables, or its
        // free variables have constant values, then optimizations are
        // possible.

        reify_activation = reify_activation || f.children.length > 0;

        // Catch/finally both imply the use of newcatch/pushscope
        // in a simplistic model.
        //
        // FIXME: In actuality, newcatch/pushscope and lookup by
        // name of the catch var are not necessary unless there is
        // a method in the catch handler that captures the
        // environment, so we can do better -- similar to "let"
        // optimization.

        reify_activation = reify_activation || (f.uses_catch || f.uses_finally); 

        // Even assuming having a nested function does not require
        // reifying the activation, do reify it if the child
        // requires its activation to be reified.

        for ( let i=0, limit=f.children.length ; i < limit ; i++ ) {
            let c = f.children[i];
            computeAttributes(c);
            reify_activation = reify_activation || c.reify_activation;
        }
        f.reify_activation = reify_activation;
    }

    function program () : Ast::PROGRAM {
        start();

        // FIXME: The following realization of the internal namespace
        // is not at all safe, but using a random number here makes
        // testing more difficult, and using a hash of the input is
        // slow.  So this will do for the moment.

        currentInternalName = "<#internal " + filename + ">";
        currentClassName = "";

        cx.enterGlobal ();
        let publicNamespace = new Ast::ReservedNamespace (Ast::noNS);
        cx.openNamespace (publicNamespace);
        cx.setDefaultNamespace (publicNamespace);

        let internalNamespace = new Ast::ReservedNamespace (new Ast::InternalNamespace(currentInternalName));
        cx.openNamespace (internalNamespace);

        let global_directives = directivesGlobal ();
        let vhead = cx.exitGlobal ();

        if (hd () != Token::EOS)
            Parse::syntaxError(this, "extra tokens after end of program.");

        computeAttributes(cx.topFunction());

        // FIXME: the head is always empty here, because vhead does the job.
        return new Ast::Program ( new Ast::Block (new Ast::Head([],[]), global_directives),
                                  vhead,
                                  cx.topFunction(),
                                  filename );
    }
}
