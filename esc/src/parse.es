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

use default namespace Parse,
    namespace Parse;

class Pattern {
}

class FieldPattern extends Pattern {
    const ident: Ast::IdentExpr;
    const ptrn: Pattern;
    function FieldPattern (ident,ptrn)
        : ident = ident
        , ptrn = ptrn { }
}

class ObjectPattern extends Pattern {
    const ptrns : [FieldPattern];
    function ObjectPattern (ptrns)
        : ptrns = ptrns { }
}

class ArrayPattern extends Pattern {
    const ptrns : [Pattern];
    function ArrayPattern (ptrns)
        : ptrns = ptrns { }
}

class SimplePattern extends Pattern {
    const expr : Ast::Expr;
    function SimplePattern (expr)
        : expr = expr { }
}

class IdentifierPattern extends Pattern {
    const ident : Ast::IDENT;
    function IdentifierPattern (ident)
        : ident = ident { }
}

class ALPHA extends Util::ENUM { function ALPHA(s) : super(s) {} }
const noColon = new ALPHA("noColon");
const allowColon = new ALPHA("allowColon");

class BETA extends Util::ENUM { function BETA(s) : super(s) {} }
const noIn = new BETA("noIn");
const allowIn = new BETA("allowIn");

class GAMMA extends Util::ENUM { function GAMMA(s) : super(s) {} }
const noExpr = new GAMMA("noExpr");
const allowExpr = new GAMMA("allowExpr");

class TAU extends Util::ENUM { function TAU(s) : super(s) {} }
const globalBlk = new TAU("globalBlk");
const classBlk = new TAU("classBlk");
const interfaceBlk = new TAU("interfaceBlk");
const localBlk = new TAU("localBlk");

class OMEGA extends Util::ENUM { function OMEGA(s) : super(s) {} }
const fullStmt = new OMEGA("fullStmt");
const abbrevStmt = new OMEGA("abbrevStmt");

function extractInfo(ctx) {
    let filename = "";
    let position = 0;
    if (ctx is Context)
        ctx = ctx.parser;
    if (ctx is Parser) {
        filename = ctx.scan.filename;
        position = ctx.position();
    }
    return [filename, position];
}

function syntaxError(ctx, msg) {
    let [filename, position] = extractInfo(ctx);
    Util::syntaxError(filename, position, msg);
}

function internalError(ctx, msg) {
    let [filename, position] = extractInfo(ctx);
    Util::internalError(filename, position, msg);
}

function warning(ctx, msg) {
    let [filename, position] = extractInfo(ctx);
    Util::warning(filename, position, msg);
}

final class Rib 
{
    static const SYSTEM = -1;
    static const GLOBAL = 0;
    static const CLASS_STATIC = 1;
    static const CLASS_INSTANCE = 2;
    static const FUNCTION = 3;
    static const BLOCK = 4;

    var defaultNamespace: (Ast::Expr | Ast::Namespace);
    var strict:           Boolean;
    var head:             Ast::Head;               // 'var' because makeSystemRib overwrites it
    var open_namespaces:  Ast::NamespaceSetList;
    const link:           Rib;
    const tag;

    // Now we can use the trick where if the top namespace has no
    // entries then we reuse it, since it is a completely functional
    // data structure.

    function Rib(tag, link) 
        : tag = tag
        , link = link
        , defaultNamespace = Ast::publicNS
        , head = new Ast::Head([], [])
        , strict = link ? link.strict : false
    {
        if (link == null)
            open_namespaces = new Ast::NamespaceSetList(null, null);
        else if (link.open_namespaces.nsset == null)
            open_namespaces = link.open_namespaces;
        else
            open_namespaces = link.open_namespaces.pushScope();
    }

    function openNamespace(ns) {
        let nss;
        for ( nss = open_namespaces.nsset ; nss != null && !Ast::nsEquals(nss.ns, ns) ; nss = nss.link )
            ;
        if (nss == null)
            open_namespaces = open_namespaces.pushNamespace(ns);
    }

    static function makeSystemRib(topFixtures) {
        let r = new Rib(Rib.SYSTEM, null);
        r.head = new Ast::Head(topFixtures, []);
        return r;
    }
}

// This is a singleton class and it should probably just be inlined
// into Parser, the indirection / abstraction doesn't buy us anything
// but a tiny amount of information hiding.

final class Context
{
    const parser;

    private var env: Rib;
    private var top_function: Ast::FuncAttr;

    function Context (parser, topFixtures)
        : parser = parser
        , env = Rib.makeSystemRib(topFixtures)
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
        findHead(initType, isStatic).fixtures.push(new Ast::Fixture(name,fixture));

    private function findHead(initType, isStatic) {
        if (initType == Ast::letInit)
            return env.head;
        for ( let e=env ; e != null ; e = e.link )
            if (e.tag != Rib.BLOCK && (!isStatic || e.tag == Rib.CLASS_STATIC))
                return e.head;
        Parse::internalError(this, "Fell off the end in Context::findHead(): " + initType + "," + isStatic);
    }

    function getOpenNamespaces()
        env.open_namespaces;

    function getDefaultNamespace()
        env.defaultNamespace;

    function setDefaultNamespace (ident: Ast::IdentExpr) {
        let ns = evalIdentExprToNamespace (ident);
        env.defaultNamespace = ns;
    }

    function openNamespace (ident: Ast::IdentExpr): void
        env.openNamespace( evalIdentExprToNamespace (ident) );

    function pushNamespace(ns): void
        env.openNamespace(ns);

    function getStrict()
        env.strict;

    function setStrict(mode): void
        env.strict = mode;

    function hasName (fxtrs, id, ns) {
        for ( let i=0, limit=fxtrs.length ; i < limit ; i++ ) {
            let pn = fxtrs[i].name;
            if (pn.name.id == id && Ast::nsEquals(pn.name.ns, ns))
                return true;
        }
        return false;
    }

    function getFixture (fxtrs,id,ns) {
        for ( let i=0, limit=fxtrs.length ; i < limit ; i++ ) {
            let pn = fxtrs[i].name;
            if (pn.name.id == id && Ast::nsEquals(pn.name.ns, ns))
                return fxtrs[i];
        }
        Parse::syntaxError(this, "Name not found " + ns + "::" + id);
    }

    /*

    two dimensional search

    repeat for each shadowed name
    each name in each head
    dup is error

    for each namespace set
    find all names in the inner most head

    */

    function findFixtureWithNames (id, nss, it: ? Ast::INIT_TARGET) {
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

    function findFixtureWithNamesInFixtures(fxtrs, id, nss: Ast::NamespaceSet) {
        let ns = null;
        while (nss != null) {
            if (hasName (fxtrs, id, nss.ns)) {
                if (ns !== null)
                    Parse::syntaxError(this, "Ambiguous reference to '" + id + "': defined in " + ns + " and " + nss.ns);
                ns = nss.ns;
            }
            nss = nss.link;
        }

        if (ns != null)
            return getFixture (fxtrs, id, ns);

        return null;
    }

    function findFixtureWithIdentifier (id: Ast::IDENT, it: ? Ast::INIT_TARGET) {
        for ( let nssl = getOpenNamespaces() ; nssl != null ; nssl = nssl.link ) {
            let fx = findFixtureWithNames(id, nssl.nsset, it);
            if (fx != null) 
                return fx;
        }
        return null;
    }

    function evalIdentExprToNamespace (ident: Ast::IdentExpr) : Ast::Namespace {
        let fxtr = null;
        let val = null;

        switch type (ident) {
        case (id: Ast::Identifier) {
            fxtr = findFixtureWithIdentifier (id.ident, null);
            if (fxtr && fxtr.data is Ast::NamespaceFixture)
                return fxtr.data.ns;
            if (fxtr == null)
                Parse::syntaxError(this, "Fixture not found: " + ident);
            Parse::internalError(this, "Fixture with unknown value " + fxtr.data);
        }
        case (x: *) {
            Parse::internalError(this, "evalIdentExprToNamespace: case not implemented " + x);
        }
        }
    }

    function resolveIdentExpr (ident: Ast::IdentExpr, it: Ast::INIT_TARGET) : Ast::FixtureName {
        if (ident is Ast::Identifier)
            return findFixtureWithIdentifier(ident.ident, it).name;

        Parse::internalError(this, "resolveIdentExpr: case not implemented " + ident);
    }
}

final class Parser
{
    const cx      : Context;
    const scan    : Scanner;
    const filename: String;

    function Parser(src, topFixtures, filename="") 
        : cx = new Context(this, topFixtures)
        , scan = new Lex::Scanner(src, filename)
        , filename = filename
    { }

    var currentClassName: String = "";
    var alpha           : ALPHA = allowColon;
    var beta            : BETA = allowIn;
    var gamma           : GAMMA = allowExpr;
    var tau             : TAU = globalBlk;
    var omega           : OMEGA = fullStmt;

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

    function matchToken (t) {
        if (T0 == t) {
            next();
            return true;
        }
        return false;
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

    function desugarAssignmentPattern (p: Pattern, t: Ast::TypeExpr, e: Ast::Expr, op: Ast::ASSIGNOP) : [[Ast::Fixture], Ast::Expr]
        desugarPattern (p,t,e,null,null,null,op);

    function desugarBindingPattern (p: Pattern, t: Ast::TypeExpr, e: ? Ast::Expr,
                                    ns: ? Ast::Namespace, it: ? Ast::INIT_TARGET, ro: ? Boolean)
        : [[Ast::Fixture], Ast::Expr]
        desugarPattern (p,t,e,ns,it,ro,null);

    function desugarPattern (p: Pattern, 
                             t: Ast::TypeExpr, 
                             e: ? Ast::Expr,
                             ns: Ast::Namespace, 
                             it: ? Ast::INIT_TARGET, 
                             ro: ? Boolean, 
                             op: ? Ast::ASSIGNOP) : [[Ast::Fixture], Ast::Expr] 
    {
        return desugarSubPattern (p,t,e,0);

        function identExprFromExpr (e: Ast::Expr) : Ast::IdentExpr {
            if (!(e is Ast::IdentExpr))
                Parse::syntaxError(this, "Invalid initializer left-hand-side " + e);
            return e;
        }

        function desugarSubPattern (p: Pattern, t: Ast::TypeExpr, e: ? Ast::Expr, n: int) : [[Ast::Fixture], Ast::Expr] {
            let fxtrs, exprs, expr;
            switch type (p) {
            case (p:IdentifierPattern) {
                let nm = new Ast::PropName (new Ast::Name(ns, p.ident));
                let fx = new Ast::ValFixture (t, ro);
                fxtrs = [new Ast::Fixture(nm, fx)];
                let inits = (e !== null) ? ([new Ast::InitBinding(nm, e)]) : []; // FIXME (fix what??)
                expr = new Ast::InitExpr (it, new Ast::Head ([],[]), inits);
            }
            case (p:SimplePattern) {
                if (e === null) 
                    Parse::syntaxError(this, "Simple pattern without initializer");
                fxtrs = [];
                if (it != null) { // we have an init target so must be an init
                    let ie = identExprFromExpr (p.expr);
                    let nm = cx.resolveIdentExpr (ie,it);
                    expr = new Ast::InitExpr (it, new Ast::Head ([],[]), [new Ast::InitBinding(nm,e)]);
                }
                else {
                    expr = new Ast::SetExpr (op, p.expr, e);
                }
            }
            //case (p: (ArrayPattern|ObjectPattern)) {
            case (p: *) {
                let tn = new Ast::TempName (n);
                fxtrs = [];
                exprs = [];
                let ptrns = p.ptrns;
                for (let i=0; i < ptrns.length; ++i) {
                    let sub = ptrns[i];
                    let typ, exp, ptn;
                    /// switch type (sub) {
                    /// case (sub: FieldPattern) {
                    if (sub is FieldPattern) {
                        typ = new Ast::FieldTypeRef (t, sub.ident);
                        exp = new Ast::ObjectRef (new Ast::GetTemp (n), sub.ident);
                        ptn = sub.ptrn;
                    }
                    /// case (pat: *) {
                    else {
                        typ = new Ast::ElementTypeRef (t,i);
                        exp = new Ast::ObjectRef (new Ast::GetTemp (n), makeIdentifier (String(i), Ast::publicNSSL));
                        // FIXME what is the ns of a temp and how do we refer it
                        ptn = sub;
                    }
                    /// }

                    let [fx,ex] = desugarSubPattern (ptn,typ,exp,n+1);
                    Util::pushOnto(fxtrs, fx);
                    exprs.push(ex);
                }
                let head = new Ast::Head ([new Ast::Fixture(tn, new Ast::ValFixture (Ast::anyType,false))],
                                          [new Ast::InitExpr (Ast::letInit, new Ast::Head([],[]), [new Ast::InitBinding(tn,e)])]);
                expr = new Ast::LetExpr (head, exprListToCommaExpr(exprs));
            }
            }
            return [fxtrs,expr];
        }
    }

    // Parse rountines

    function identifier () : Ast::IDENT {
        if (hd() == Token::Identifier)
            return let (str = lexeme()) next(), str;
        Parse::syntaxError(this, "Expecting identifier, found " + lexeme () );
    }

    function propertyIdentifier(): Ast::IDENT {
        if (hd() == Token::Identifier || Token::isReserved(hd()))
            return let (str = lexeme()) next(), str;
        Parse::syntaxError(this, "Expecting identifier or reserved word, found " + lexeme () );
    }
  
    // (..)::id and ".."::id are handled in primaryExpr
  
    function primaryName(): Ast::IdentExpr {
        if (hd() != Token::Identifier)
            Parse::syntaxError(this, "Expected identifier, found " + lexeme());
  
        let name = makeIdentifier(identifier (), cx.getOpenNamespaces());
        while (match(Token::DoubleColon))
            name = new Ast::QualifiedIdentifier(name, propertyIdentifier());
        return name;
    }
  
    function parenExpression () : Ast::Expr {
        eat (Token::LeftParen);
        let expr = fullCommaExpression ();
        eat (Token::RightParen);

        return expr;
    }

    function exprListToCommaExpr(es) {
        let expr = es[0];
        for ( let i=1 ; i < es.length ; i++ )
            expr = new Ast::BinaryExpr(Ast::commaOp, expr, es[i]);
        return expr;
    }

    function objectLiteral () : Ast::TypeExpr {
        let pos = position();             // Record source location of initial left brace
        eat (Token::LeftBrace);
        let fields = fieldList ();
        eat (Token::RightBrace);

        // FIXME: check that there is not a plain field for which there is
        // also a getter or setter.

        if (cx.getStrict()) {
            // FIXME: check that there are no duplicate field names
        }

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

    function fieldList () : [Ast::LiteralField] {
        let fields = [] : [Ast::LiteralField];
        if (hd () != Token::RightBrace) {
            do
                fields.push (literalField());
            while (match(Token::Comma));
        }
        return fields;
    }

    function literalField () : Ast::FieldType {
        let tag = match(Token::Const) ? Ast::constTag : Ast::varTag;
        let fn = fieldName ();
        let expr = null;

        // The colon could be absent if this is a destructuring
        // shorthand, but we can't expand it here -- that must be
        // done later, and only in legal contexts.

        if (match(Token::Colon)) {
            switch (hd ()) {
            case Token::LeftBrace:   // short cut to avoid recursion
                expr = objectLiteral ();
                break;
            case Token::LeftBracket:
                expr = arrayLiteral ();
                break;
            default:
                expr = fullAssignmentExpression ();
                break;
            }
        }

        return new Ast::LiteralField (tag,fn,expr);
    }

    function fieldName () : Ast::IdentExpr {
        switch (hd ()) {
        case Token::StringLiteral:
            return let (name = new Ast::Identifier(lexeme(), Ast::publicNSSL)) next(), name;

        case Token::IntLiteral:
        case Token::UIntLiteral:
            return let (name = new Ast::Identifier(String(parseInt(lexeme())), Ast::publicNSSL)) next(), name;

        case Token::DoubleLiteral:
            return let (name = new Ast::Identifier(String(parseFloat(lexeme())), Ast::publicNSSL)) next(), name;

        case Token::DecimalLiteral:
            return let (name = new Ast::Identifier(String(new decimal(lexeme())), Ast::publicNSSL)) next(), name;

        default:
            // FIXME: support ns::id here
            if (Token::isReserved(hd ()))
                return let (name = new Ast::Identifier(lexeme(), Ast::publicNSSL)) next(), name;
            return primaryName ();
        }
    }

    function arrayLiteral () : Ast::Expr {
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

    function elementList () : Ast::Expr {
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
                elt = fullAssignmentExpression();
                break;
            }
        }
        if (elt != null)
            elts.push(elt);

        return elts;
    }

    function primaryExpression() : Ast::Expr {
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
            return let (expr = new Ast::ThisExpr(cx.getStrict())) next(), expr;

        case Token::LeftParen: {
            let e = parenExpression();
            if (hd() == Token::DoubleColon) {
                eat(Token::DoubleColon);
                return new Ast::QualifiedIdentifier(e, propertyIdentifier());
            }
            return e;
        }

        case Token::LeftBracket:
            return arrayLiteral ();

        case Token::LeftBrace:
            return objectLiteral ();

        case Token::Function:
            return functionExpression ();

        default:
            return primaryName ();
        }
    }

    function superExpression() {
        eat(Token::Super);
        return new Ast::SuperExpr(null);
    }

    function brackets() {
        eat(Token::LeftBracket);
        let expr = fullCommaExpression ();
        eat (Token::RightBracket);
        return expr;
    }

    function propertyOperator (obj: Ast::Expr) : [Ast::Expr] {
        switch (hd ()) {
        case Token::Dot:
            eat(Token::Dot);
            return new Ast::ObjectRef (obj, makeIdentifier( propertyIdentifier (), cx.getOpenNamespaces()));
        case Token::LeftBracket:
            return new Ast::ObjectRef (obj, new Ast::ExpressionIdentifier (brackets()));
        default:
            Parse::internalError("propertyOperator: " + hd());
        }
    }

    function argumentList () {
        let args = [];

        eat(Token::LeftParen);
        if (hd() != Token::RightParen) {
            do 
                args.push(fullAssignmentExpression());
            while (match(Token::Comma));
        }
        eat(Token::RightParen);

        return args;
    }

    function memberExpression () : Ast::Expr {
        switch (hd ()) {
        case Token::New:
            next();
            let object_expr = memberExpression ();
            let argument_exprs = argumentList ();
            return memberExpressionPrime (new Ast::NewExpr (object_expr,argument_exprs));
        case Token::Super:
            let super_expr = superExpression ();
            let property_expr = propertyOperator (super_expr);
            return memberExpressionPrime (property_expr);
        default:
            let expr = primaryExpression ();
            return memberExpressionPrime (expr);
        }
    }

    function memberExpressionPrime (expr: Ast::Expr) : Ast::Expr {
        switch (hd ()) {
        case Token::LeftBracket:
        case Token::Dot:
            return memberExpressionPrime (propertyOperator (expr));
        default:
            return expr;
        }
    }

    function callExpression () : Ast::Expr {
        let pos = position();
        let object_expr = memberExpression ();
        let argument_exprs = argumentList ();

        return callExpressionPrime (new Ast::CallExpr (object_expr,argument_exprs,pos,cx.getStrict));
    }

    // shared among many
    function callExpressionPrime (call_expr: Ast::Expr) : Ast::Expr {
        switch (hd ()) {
        case Token::LeftParen:
            let pos = position();
            let argument_exprs = argumentList ();
            return callExpressionPrime (new Ast::CallExpr (call_expr, argument_exprs, pos, cx.getStrict()));
        case Token::LeftBracket:
        case Token::Dot:
            return callExpressionPrime (propertyOperator (call_expr));
        default:
            return call_expr;
        }
    }

    function newExpression (new_count=0) : Ast::Expr {
        let call_expression, is_new;

        if (is_new = match(Token::New))
            call_expression = newExpression (new_count+1);
        else
            call_expression = memberExpression();

        if (hd() == Token::LeftParen) {   // No more new exprs so this paren must start a call expr
            let pos = position();
            let argument_exprs = argumentList ();
            if (new_count > 0)
                return new Ast::NewExpr (call_expression, argument_exprs);
            return callExpressionPrime (new Ast::CallExpr (call_expression, argument_exprs, pos, cx.getStrict()));
        }

        if (new_count > 0)
            return new Ast::NewExpr (call_expression, []);

        if (is_new)
            return memberExpressionPrime (call_expression);
        return call_expression;
    }

    function leftHandSideExpression () : Ast::Expr {
        let operator = (hd() == Token::New) ? newExpression (0) : memberExpression ();
        if (hd () == Token::LeftParen) {
            let pos = position();
            let args = argumentList ();
            return callExpressionPrime (new Ast::CallExpr (operator, args, pos, cx.getStrict()));
        }
        return operator;
    }

    function postfixExpression () : Ast::Expr {
        let expr = leftHandSideExpression ();
        if (noNewline()) {
            if (match(Token::PlusPlus))
                return new Ast::UnaryExpr (Ast::postIncrOp, expr);
            if (match(Token::MinusMinus))
                return new Ast::UnaryExpr (Ast::postDecrOp, expr);
        }

        return expr;
    }

    function unaryExpression () : Ast::Expr {
        let t;

        switch (t = hd ()) {
        case Token::Delete:
            next();
            return new Ast::UnaryExpr(Ast::deleteOp | (cx.getStrict() ? Ast::strictFlag : 0), postfixExpression ());

        case Token::PlusPlus:
        case Token::MinusMinus:
            next();
            return new Ast::UnaryExpr(Ast::tokenToOperator[t + 1000], postfixExpression ());

        case Token::Void:
        case Token::TypeOf:
        case Token::Plus:
        case Token::Minus:
        case Token::BitwiseNot:
        case Token::Not:
            next();
            return new Ast::UnaryExpr(Ast::tokenToOperator[t + 1000], unaryExpression ());

        case Token::Type:
            next();
            return new Ast::TypeOpExpr(nullableTypeExpression ());

        default:
            return postfixExpression();
        }
    }

    function multiplicativeExpression () : Ast::Expr {
        let expr = unaryExpression ();
        let t;

        while (Token::isMultiplicative(t = hd()) || t == Token::BREAK) {
            if (t == Token::BREAK) {
                div();
                if (!Token::isMultiplicative(t = hd()))
                    break;
            }
            next();
            expr = new Ast::BinaryExpr(Ast::tokenToOperator[t], expr, unaryExpression());
        }

        return expr;
    }

    function additiveExpression () : Ast::Expr {
        let expr = multiplicativeExpression ();
        let t;

        while (Token::isAdditive(t = hd())) {
            next();
            expr = new Ast::BinaryExpr(Ast::tokenToOperator[t], expr, multiplicativeExpression());
        }
        return expr;
    }

    function shiftExpression () : Ast::Expr {
        let expr = additiveExpression ();
        let t;

        while (Token::isShift(t = hd())) {
            next();
            expr = new Ast::BinaryExpr(Ast::tokenToOperator[t], expr, additiveExpression());
        }

        return expr;
    }

    // FIXME: Why would we distinguish between BinaryTypeExpr and
    // BinaryExpr here, as long as the operator gives it away
    // anyhow?  (Note we must still dispatch on the subparser).

    function relationalExpression () : Ast::Expr {
        let expr = shiftExpression ();
        let t;

        while (Token::isRelational(t = hd(), beta != noIn)) {
            next();
            if (Token::isRelationalType(t))
                expr = new Ast::BinaryTypeExpr(Ast::tokenToOperator[t], expr, typeExpression());
            else 
                expr = new Ast::BinaryExpr(Ast::tokenToOperator[t], expr, shiftExpression());
        }

        return expr;
    }

    function equalityExpression () : Ast::Expr {
        let expr = relationalExpression ();
        let t;

        while (Token::isEquality(t = hd())) {
            next();
            expr = new Ast::BinaryExpr (Ast::tokenToOperator[t], expr, relationalExpression ());
        }

        return expr;
    }

    function bitwiseAndExpression () : Ast::Expr {
        let expr = equalityExpression ();

        while (match(Token::BitwiseAnd))
            expr = new Ast::BinaryExpr (Ast::bitwiseAndOp, expr, equalityExpression ());

        return expr;
    }

    function bitwiseXorExpression () : Ast::Expr {
        let expr = bitwiseAndExpression ();

        while (match(Token::BitwiseXor))
            expr = new Ast::BinaryExpr (Ast::bitwiseXorOp, expr, bitwiseAndExpression ());

        return expr;
    }

    function bitwiseOrExpression () : Ast::Expr {
        let expr = bitwiseXorExpression ();

        while (match(Token::BitwiseOr)) 
            expr = new Ast::BinaryExpr (Ast::bitwiseOrOp, expr, bitwiseXorExpression ());

        return expr;
    }

    function logicalAndExpression () : Ast::Expr {
        let expr = bitwiseOrExpression ();

        while (match(Token::LogicalAnd)) 
            expr = new Ast::BinaryExpr (Ast::logicalAndOp, expr, bitwiseOrExpression ());

        return expr;
    }

    function logicalXorExpression () : Ast::Expr {
        let expr = logicalAndExpression ();

        while (match(Token::LogicalXor))
            expr = new Ast::BinaryExpr (Ast::logicalXor, expr, logicalAndExpression ());

        return expr;
    }

    function logicalOrExpression () : Ast::Expr {
        let expr = logicalXorExpression ();

        while (match(Token::LogicalOr)) 
            expr = new Ast::BinaryExpr (Ast::logicalOrOp, expr, logicalXorExpression ());

        return expr;
    }

    function letExpression() {
        eat(Token::Let);
        eat(Token::LeftParen);
        let [fixtures, inits] = variableBindingList(Ast::publicNS, Ast::letInit, false);
        eat(Token::RightParen);
        let expr = commaExpression();
        return new Ast::LetExpr(new Ast::Head(fixtures, inits), expr);
    }

    function yieldExpression() {
        cx.topFunction().uses_yield = true;
        eat(Token::Yield);
        let expr = assignmentExpression();
        return new Ast::YieldExpr(expr);
    }

    // Experimental extension: dynamically scoped binding.
    //
    // The values of the variables in the head are read and saved; the
    // expressions are computed left-to-right yielding new values,
    // then assigned left-to-right to the variables; the body
    // expression is evaluated; the saved values are assigned
    // left-to-right to the variables; and the result of the body
    // expression is returned.  If the body expression throws an
    // exception then the original values are restored to the
    // variables but the exception is propagagated out of the
    // expression.
    //
    // If a variable name has computable parts (eg o.x) then the
    // computable parts are computed only once, but each variable is
    // considered independently, that is, "o" is evaluated twice in
    // the list (o.x=1, o.y=2).
    // 
    // If the expressions throw, or the reads or writes throw (because
    // they are getter or setter call that throw, or because the code
    // is strict and a property is read-only or missing, or for any
    // other reason), then the dynamic override expression as a whole
    // throws that exception, and the variables are left in the
    // intermediate state they were in when the exception was thrown.
    // That is, only the body of the form is protected by an exception
    // handler.
    //
    //   "dynamic" "override" "(" PrimaryName "=" AssignmentExpr "," ... ")" CommaExpression
    //
    // For example,
    //
    //   dynamic override (ns::x = E1, y = E2) ...
    //
    // (The ESC parser uses this form extensively for the grammar
    // parameters; grep this file.)
    //
    // The syntax "dynamic override" is vile but was chosen because
    //
    //   * "let dynamic" isn't quite right -- all other let forms are
    //     lexical scoping forms and bind only simple names, neither of
    //     which is the case here
    //
    //   * "dynamic" or "override" by itself followed by leftparen is
    //     syntactically ambiguous at the statement level (the leftparen
    //     could introduce a namespace expression)
    //
    // FIXME: general patterns should be allowed on the lhs of the "=".
    //
    // FIXME: there are use cases for a statement form, mirroring
    // let-block statements:
    //
    //        dynamic override (...) {
    //          ...
    //        }

    function dynamicOverrideExpression() {
        eat(Token::Dynamic);
        eat(Token::Override);
        eat(Token::LeftParen);
        let names = [];
        let exprs = [];
        if (hd() != Token::RightParen) {
            do {
                names.push(primaryName());
                eat(Token::Assign);
                exprs.push(fullAssignmentExpression());
            } while (match(Token::Comma));
        }
        eat(Token::RightParen);
        let body = commaExpression();
        return new Ast::DynamicOverrideExpr(names, exprs, body);
    }

    function nonAssignmentExpression () : Ast::Expr {
        switch (hd ()) {
        case Token::Let:
            return letExpression ();

        case Token::Yield:
            return yieldExpression ();

        case Token::Dynamic:
            return dynamicOverrideExpression ();

        default: {
            let expr = logicalOrExpression ();
            if (match(Token::QuestionMark)) {
                let consequent = dynamic override (alpha=noColon) nonAssignmentExpression ();
                eat (Token::Colon);
                let alternate = nonAssignmentExpression ();
                return new Ast::TernaryExpr (expr, consequent, alternate);
            }
            return expr;
        }
        }
    }

    function conditionalExpression () : Ast::Expr {
        switch (hd ()) {
        case Token::Let:
            return letExpression ();

        case Token::Yield:
            return yieldExpression ();

        case Token::Dynamic:
            return dynamicOverrideExpression ();

        default: {
            let expr = logicalOrExpression ();
            if (match(Token::QuestionMark)) {
                let consequent = dynamic override (alpha=noColon) assignmentExpression (); 
                eat (Token::Colon);
                let alternate = assignmentExpression ();
                return new Ast::TernaryExpr (expr, consequent, alternate);
            }
            return expr;
        }
        }
    }

    function fullAssignmentExpression(): Ast::Expr
        dynamic override (alpha=allowColon, beta=allowIn) assignmentExpression();

    function assignmentExpression () : Ast::Expr {
        let lhs = conditionalExpression ();
        let t;

        if ((t = hd()) == Token::Assign || Token::isOpAssign(t)) {
            next();
            let pat = patternFromExpr (lhs);
            if (t != Token::Assign && !(pat is SimplePattern))
                Parse::internalError(this, "The lhs of op= must be a name or property reference.");
            let rhs = assignmentExpression ();
            let [_, expr] = desugarAssignmentPattern (pat,Ast::anyType,rhs,Ast::tokenToOperator[t] | (cx.getStrict() ? Ast::strictFlag : 0));
            return expr;
        }
        return lhs;
    }

    // FIXME: This looks partial.  There can't be holes in array
    // patterns here.

    function patternFromExpr (e: Ast::Expr) {
        if (e is Ast::IdentExpr || e is Ast::ObjectRef)
            return new SimplePattern (e);

        if (e is Ast::LiteralArray)
            return new ArrayPattern( Util::map(patternFromExpr, e.exprs) );

        if (e is Ast::LiteralObject)
            return new ObjectPattern( Util::map(function (f) { return new FieldPattern (f.ident, f.expr || f.ident) }, 
                                                e.fields) );

        Parse::internalError(this, "patternFromExpr, unhandled or invalid expression kind " + e);
    }

    function fullCommaExpression(): Ast::Expr 
        dynamic override (alpha=allowColon, beta=allowIn) commaExpression();

    function commaExpression(): Ast::Expr {
        let expr = assignmentExpression();
        while (match(Token::Comma))
            expr = new Ast::BinaryExpr(Ast::commaOp, expr, assignmentExpression());
        return expr;
    }

    // PATTERNS

    function pattern () : Pattern {
        switch (hd ()) {
        case Token::LeftBrace:   return objectPattern ();
        case Token::LeftBracket: return arrayPattern ();
        default:                 return simplePattern ();
        }
    }

    function simplePattern () : Pattern {
        switch (gamma) {
        case noExpr:    return new IdentifierPattern (identifier ());
        case allowExpr: return new SimplePattern (dynamic override (alpha=allowColon) leftHandSideExpression ());
        }
    }

    function arrayPattern () : Ast::Expr {
        eat (Token::LeftBracket);
        let pattern = elementListPattern ();
        eat (Token::RightBracket);

        return new ArrayPattern (pattern);
    }

    function elementListPattern () : [Ast::Expr] {
        let elements = [], element;

        if (hd () !== Token::RightBracket) {
            switch (hd ()) {
            case Token::Comma:
                let pos = position();
                eat(Token::Comma);
                element = new Ast::LiteralUndefined(pos);
                break;
            default:
                element = dynamic override (beta=allowIn) pattern ();
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
                    element = dynamic override (beta=allowIn) pattern ();
                    break;
                }
                elements.push (element);
            }
        }

        return elements;
    }

    function objectPattern () : Ast::Expr {
        eat (Token::LeftBrace);
        let fields = fieldListPattern ();
        eat (Token::RightBrace);

        return new ObjectPattern (fields); 
    }

    function fieldListPattern () : Ast::Expr {
        let fields = [];

        if (hd () != Token::RightBrace) {
            do 
                fields.push (fieldPattern ());
            while (match(Token::Comma));
        }

        return fields;
    }

    function fieldPattern () : FieldPattern {
        let field_name = fieldName ();
        let field_pattern;

        if (match(Token::Colon))
            field_pattern = dynamic override (beta=allowIn) pattern ();
        else if (field_name is Ast::Identifier) 
            field_pattern = new IdentifierPattern (field_name.ident);
        else
            Parse::internalError(this, "unsupported fieldPattern " + field_name);

        return new FieldPattern (field_name, field_pattern);
    }

    function typedPattern () : [Pattern,Ast::TypeExpr] {
        let the_pattern = dynamic override (gamma=noExpr) pattern ();

        if (match(Token::Colon)) 
            return [the_pattern, nullableTypeExpression ()];
        return [the_pattern, Ast::anyType];
    }

    // TYPE EXPRESSIONS

    function nullableTypeExpression () : Ast::TypeExpr {
        let hasNullability = false;
        let nullable = false;

        if (match(Token::QuestionMark)) {
            hasNullability = true;
            nullable = true;
        }
        else if (match(Token::Not)) {
            hasNullability = true;
            nullable = false;
        }
        let t = typeExpression ();

        if (hasNullability)
            return new Ast::NullableType (t,nullable);
        return t;
    }

    function typeExpression () : Ast::TypeExpr {
        switch (hd ()) {
        case Token::Mult:        return next(), Ast::anyType;
        case Token::Null:        return next(), Ast::nullType;
        case Token::Function:    return functionType();
        case Token::LeftParen:   return unionType();
        case Token::LeftBrace:   return objectType();
        case Token::LeftBracket: return arrayType();
        default:                
            if (matchToken(Token::id_undefined))
                return Ast::undefinedType;
            return new Ast::TypeName (primaryName ());
        }
    }

    function unionType () : Ast::TypeExpr {
        eat (Token::LeftParen);
        let type_exprs = typeExpressionListBar ();
        eat (Token::RightParen);

        return new Ast::UnionType (type_exprs);
    }

    function objectType () : Ast::TypeExpr {
        eat (Token::LeftBrace);
        let field_types = fieldTypeList ();
        eat (Token::RightBrace);

        return new Ast::ObjectType (field_types);
    }

    function fieldTypeList () : [Ast::FieldType] {
        let types = [];
        if (hd () !== Token::RightBrace) {
            do 
                types.push (fieldType ());
            while (match(Token::Comma));
        }
        return types;
    }

    function fieldType () : Ast::FieldType {
        let name = fieldName ();
        eat (Token::Colon);
        let t = nullableTypeExpression ();

        return new Ast::FieldType(name, t);
    }

    function arrayType () : Ast::TypeExpr {
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

    function typeExpressionList () : [Ast::TypeExpr]
        listOfNullableTypeExpressions(Token::Comma);

    function typeExpressionListBar () : [Ast::TypeExpr]
        listOfNullableTypeExpressions(Token::BitwiseOr);

    function listOfNullableTypeExpressions(separator) {
        let types = [];
        do 
            types.push (nullableTypeExpression ()); 
        while (match(separator))
            return types;
    }

    // STATEMENTS

    function statement () : Ast::Stmt {
        switch (hd()) {
        case Token::LeftBrace: return new Ast::BlockStmt( statementBlock() );
        case Token::Break:     return let (stmt = breakStatement ()) semicolon(omega), stmt;
        case Token::Continue:  return let (stmt = continueStatement ()) semicolon(omega), stmt;
        case Token::Do:        return let (stmt = doStatement()) semicolon(omega), stmt;
        case Token::For:       return forStatement();
        case Token::If:        return ifStatement();
        case Token::Return:    return let (stmt = returnStatement()) semicolon(omega), stmt;
        case Token::Switch:    return (hd2() == Token::Type) ? switchTypeStatement() : switchStatement();
        case Token::Throw:     return let (stmt = throwStatement()) semicolon(omega), stmt;
        case Token::Try:       return tryStatement ();
        case Token::While:     return whileStatement();
        case Token::With:      return withStatement ();
        default:
            if (hd() == Token::Identifier && hd2() == Token::Colon)
                return labeledStatement ();
            return let (stmt = expressionStatement ()) semicolon(omega), stmt;
        }
    }

    function substatement () : Ast::Stmt {
        if (match(Token::SemiColon))
            return new Ast::EmptyStmt;
        return statement ();
    }

    // Yes, takes omega explicitly
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

    function statementBlock () : Ast::Block {
        eat (Token::LeftBrace);
        cx.enterBlock ();
        let [directive_list,_] = dynamic override (omega=fullStmt, tau=localBlk) directivesLocal();
        let head = cx.exitBlock ();
        eat (Token::RightBrace);

        return new Ast::Block (head, directive_list);
    }

    function labeledStatement () : Ast::Stmt {
        let label = identifier ();
        eat(Token::Colon);

        let stmt = dynamic override (omega=fullStmt) substatement();

        let s = stmt;
        while (s is Ast::LabeledStmt)
            s = s.stmt;
        if (s is Ast::LabelSet)
            s.labels.push(label);

        return new Ast::LabeledStmt(label, stmt);
    }

    function expressionStatement () : Ast::Stmt
        new Ast::ExprStmt (fullCommaExpression ());

    function returnStatement () : Ast::Stmt {
        eat (Token::Return);
        return new Ast::ReturnStmt (noNewline() ? fullCommaExpression() : null);
    }

    function breakStatement () : Ast::Stmt
        new Ast::BreakStmt( breakOrContinueLabel(Token::Break) );

    function continueStatement () : Ast::Stmt
        new Ast::ContinueStmt( breakOrContinueLabel(Token::Continue) );

    function breakOrContinueLabel(tok) {
        eat(tok);
        return noNewline() ? identifier() : null;
    }

    function ifStatement () : Ast::Stmt {
        eat(Token::If);
        let test = parenExpression();
        let consequent = substatement();
        let alternate = null;
        if (match(Token::Else))
            alternate = substatement();

        return new Ast::IfStmt(test, consequent, alternate);
    }

    function whileStatement () : Ast::Stmt {
        eat(Token::While);
        let test = parenExpression();
        let body = substatement(); 
 
        return new Ast::WhileStmt (test, body);
    }

    function doStatement () : Ast::Stmt {
        eat(Token::Do);
        let body = substatement(); 
        eat(Token::While);
        let test = parenExpression ();
 
        return new Ast::DoWhileStmt (test, body);
    }

    function forStatement () : Ast::Stmt {
        cx.enterBlock ();

        eat (Token::For);
        let is_each = matchToken(Token::id_each);
        eat (Token::LeftParen);
        let init = forInitialiser ();
        if (match(Token::In)) {
            let objexpr = fullCommaExpression ();
            eat (Token::RightParen);
            let body = substatement (); 
            let head = cx.exitBlock ();
                
            return new Ast::ForInStmt (head,init,objexpr,body,is_each);
        }
        else {
            if (is_each)
                Parse::syntaxError(this, "'for each' requires 'in' style loop");
            eat (Token::SemiColon);
            let test = hd() == Token::SemiColon ? null : fullCommaExpression();
            eat (Token::SemiColon);
            let update = hd() == Token::RightParen ? null : fullCommaExpression();
            eat (Token::RightParen);
            let body = substatement (); 
            let head = cx.exitBlock ();
                
            return new Ast::ForStmt (head,init,test,update,body);
        }
    }

    function forInitialiser () : ? Ast::Expr {
        switch (hd ()) {
        case Token::SemiColon:
            return null;

        case Token::Const:
        case Token::Let:
        case Token::Var:
            return bindingForInitialiser();

        default:
            return dynamic override (alpha=allowColon, beta=noIn) commaExpression ();
        }
    }

    function bindingForInitialiser() {
        let [it, ro] = dynamic override (tau=localBlk) variableDefinitionKind();
        let in_allowed = true;
        let init_expr = null;

        for (;;) {
            let [pattern, annotation] = dynamic override (beta=noIn) typedPattern ();
            let initializer = null;

            if (match(Token::Assign))
                initializer = dynamic override (alpha=allowColon, beta=noIn) assignmentExpression ();
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

    function caseElements () : [Ast::Case] {
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
                let item = fullCommaExpression();
                eat(Token::Colon);
                cases.push (new Ast::Case (item,[]));
                break;
            }
            default: {
                let [items,_] = dynamic override (tau=localBlk) directivesLocal(1);            // 'abbrev' is handled by RightBrace check in head
                Util::pushOnto(cases[cases.length-1].stmts, items);
                break;
            }
            }
        }

        return cases;
    }

    function throwStatement () : Ast::Stmt {
        eat (Token::Throw);
        return new Ast::ThrowStmt( fullCommaExpression () );
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

    function catches () : [Ast::Catch] {
        let catchblocks = [];

        while (match(Token::Catch))
            catchblocks.push (catchClause ());

        cx.topFunction().uses_catch = catchblocks.length > 0;
        return catchblocks;
    }

    function catchClause () : Ast::Catch {
        eat (Token::LeftParen);
        let catchvar = parameter ();
        eat (Token::RightParen);
        let catchblock = statementBlock ();

        let [k,[p,t]] = catchvar;
        let [f,i] = desugarBindingPattern (p, t, new Ast::GetParam (0), Ast::publicNS, Ast::varInit, false);
        let head = new Ast::Head (f,[i]);

        return new Ast::Catch (head,catchblock);
    }

    function withStatement () : Ast::Stmt {
        if (cx.getStrict())
            Parse::syntaxError(this, "The 'with' statement is not allowed in strict mode.");
        eat (Token::With);
        cx.topFunction().uses_with = true;
        let expr = parenExpression ();
        let body = substatement ();
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

    function typedExpression () : [Ast::Expr,Ast::TypeExpr] {
        let expr = parenExpression ();
        let texpr = match(Token::Colon) ? nullableTypeExpression () : Ast::anyType;
        return [expr,texpr];
    }

    function typeCases () : [Ast::Catch] {
        let cases = [];
        while (match(Token::Case))
            cases.push(catchClause());
            // Switch type currently compiles to a try/catch, so the function
            // needs to know that a catch is used.
            cx.topFunction().uses_catch = true;
            
        return cases;
    }

    // DEFINITIONS

    function variableDefinition (attrs) : ? Ast::Expr {
        let [it, ro] = variableDefinitionKind ();
        let [fxtrs,exprs] = variableBindingList (attrs.ns, it, ro);

        cx.addFixtures (it, fxtrs, attrs.static);
        if (tau == classBlk && !attrs.static) {
            cx.addInits(it, exprs);
            return null;
        }
        return exprListToCommaExpr(exprs);
    }

    function variableDefinitionKind () {
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

    function variableBindingList (ns: Ast::Namespace, it: Ast::INIT_TARGET, ro: boolean ) : [[Ast::Fixture], [Ast::Expr]] {
        let fixtures = [], exprs = [];
        do
            variableBinding(ns, it, ro, fixtures, exprs);
        while (match(Token::Comma));
        return [fixtures, exprs];
    }

    function variableBinding (ns, it, ro, fixtures, exprs) {
        let [pattern, annotation] = typedPattern ();
        let initializer;
        let f, i;

        if (match(Token::Assign))
            initializer = dynamic override (alpha=allowColon) assignmentExpression ();
        else if (!(pattern is IdentifierPattern)) 
            Parse::syntaxError(this, "destructuring pattern without initializer");
        else
            initializer = new Ast::LiteralUndefined();
        [f,i] = desugarBindingPattern (pattern,annotation,initializer,ns,it,ro);

        Util::pushOnto(fixtures, f);
        exprs.push(i);
    }

    function functionDefinition (attrs: ATTRS) : [Ast::Stmt] {
        let is_const = match(Token::Const);  // FIXME: not currently used
        eat (Token::Function);

        cx.enterFunction(attrs);

        let name = functionName ();
        let signature = functionSignature ();
        let body, strict;

        if (attrs.native || tau == interfaceBlk) {
            semicolon(fullStmt);
            body = [];
            strict = false;
        }
        else {
            [body, strict] = dynamic override (beta=allowIn) functionBody ();
            semicolon(omega);
        }

        let [vars,attr] = cx.exitFunction();

        let {params, defaults, resultType, thisType, numparams} = signature;
        let func = new Ast::Func (name, body, params, numparams, vars, defaults, resultType, attr, strict);

        if (strict)
            checkStrictFunction(func);

        let name = new Ast::PropName (new Ast::Name(attrs.ns, name.ident));
        let fxtr = new Ast::MethodFixture (func, Ast::anyType, true, attrs.override, attrs.final);
        cx.addFixture(tau == localBlk ? Ast::letInit : Ast::varInit, name, fxtr, attrs.static);
    }

    function functionExpression (skip_header=false) : Ast::Expr {
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

        let [body, strict] = dynamic override (beta=allowIn, omega=fullStmt) functionBody ();
        let [vars,attr] = cx.exitFunction();
        let {params, numparams, defaults, resultType} = signature;
        let func = new Ast::Func(name, 
                                 body, 
                                 params, 
                                 numparams,
                                 vars, 
                                 defaults, 
                                 resultType,
                                 attr,
                                 strict);
        if (strict)
            checkStrictFunction(func);

        let fnexpr = new Ast::LiteralFunction(func, pos);

        return fnexpr;
    }

    function constructorDefinition (ns, attrs) : [Ast::Stmt] {
        eat (Token::Function);

        cx.enterFunction(attrs);

        let name = identifier ();
        let signature = constructorSignature ();
        let body;
        let strict;

        if (attrs.native) {
            semicolon(fullStmt);
            body = [];
            strict = false;
        }
        else {
            eat(Token::LeftBrace);
            [body,strict] = dynamic override (omega=fullStmt, tau=localBlk) directivesLocal();
            eat (Token::RightBrace);
            semicolon(omega);
        }

        let [vars,attr] = cx.exitFunction();
        let {params, defaults, settings, superArgs, numparams} = signature;
        let func = new Ast::Func (new Ast::FuncName(Ast::ordinaryFunction, name), 
                                  body, 
                                  params, 
                                  numparams, 
                                  vars, 
                                  defaults, 
                                  Ast::voidType, 
                                  attr,
                                  strict);
        if (strict)
            checkStrictFunction(func);
        return new Ast::Ctor (settings,superArgs,func);
    }

    static type CTOR_SIG = 
    { typeParams : [Ast::IDENT]
      , params : Ast::Head
      , paramTypes : [Ast::TypeExpr]
      , defaults : [Ast::Expr]
      , settings : [Ast::Expr]
      , superArgs: [Ast::Expr] }

    static type FUNC_SIG = 
    { typeParams : [Ast::IDENT]
      , params : Ast::Head
      , paramTypes : [Ast::TypeExpr]
      , defaults : [Ast::Expr]
      , resultType : Ast::TypeExpr
      , thisType : ? Ast::TypeExpr }

    function constructorSignature () : CTOR_SIG {
        eat (Token::LeftParen);
        let ps = parameters ();
        eat (Token::RightParen);
        let [settings,superArgs] = constructorInitialiser ();

        // Translate bindings and init steps into fixtures and inits (Head)
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

    function constructorInitialiser () : [[Ast::Expr], [Ast::Expr]] {
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

    function setting () : Ast::Expr {
        let lhs = dynamic override (beta=allowIn, gamma=allowExpr) pattern ();
        eat (Token::Assign);
        let rhs = fullAssignmentExpression ();

        let [fxtrs,inits] = desugarBindingPattern (lhs, Ast::anyType, rhs, null, Ast::instanceInit, null);
        // FIXME: assert fxtrs is empty

        return inits;
    }

    // FIXME: needs to handle plain functions called 'get' and 'set'
    // FIXME: needs to handle catchalls

    function functionName () : Ast::FUNC_NAME {
        let kind;

        if (matchToken(Token::id_get))      kind = Ast::getterFunction;
        else if (matchToken(Token::id_set)) kind = Ast::setterFunction;
        else                                kind = Ast::ordinaryFunction;

        let ident = propertyIdentifier();
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

        // Translate bindings and init steps into fixtures and inits (Head)
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

    function checkStrictFunction(fn) {
        /*
        let ht = new Util::Hashtable(Util::hash_string, (function (x,y) x==y), undefined);
        
        for ( let ps = fn.params.fixtures, limit=ps.length, i=0 ; i < ps.length ; i++ )
            if (ht.read(ps[i][0] ???  -- no common API here
        */
        // FIXME
        // no duplicate parameter names
        // no bound var (including fn) at the body top-level that is also a param name
        // no duplicate var/fn
    }

    function typeParameters () : [Ast::IDENT] {
        let tparams = [];
        if (match(Token::LeftDotAngle)) {
            do 
                tparams.push(identifier());
            while(match(Token::Comma));
            eat(Token::GreaterThan);
        }
        return tparams;
    }

    static type PARAMETERS = {
        fixtures: [Ast::Fixture],
        inits: [Ast::Expr],
        exprs: [Ast::Expr],
        types: [Ast::TypeExpr],
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
            desugarBindingPattern((dynamic override (beta=noIn, gamma=noExpr) simplePattern()), 
                                  Ast::anyType, 
                                  new Ast::GetParam(params.numparams), 
                                  Ast::publicNS, 
                                  Ast::letInit, 
                                  false);
        f.push(new Ast::Fixture(new Ast::TempName(params.numparams), 
                                new Ast::ValFixture(Ast::anyType,false)));

        Util::pushOnto(params.fixtures, f);
        params.inits.push(i);
        params.types.push(Ast::anyType);
    }

    function parameterInit (params, initRequired) {
        let param = parameter ();
        let initexpr = null;

        if (match(Token::Assign))
            initexpr = dynamic override (alpha=allowColon, beta=allowIn) nonAssignmentExpression();
        else if (initRequired)
            Parse::syntaxError(this, "Expecting default value expression");

        let [k,[p,t]] = param;
        let [f,i] = desugarBindingPattern (p, t, new Ast::GetParam (params.numparams), Ast::publicNS, Ast::letInit, false);
        f.push (new Ast::Fixture(new Ast::TempName (params.numparams), 
                                 new Ast::ValFixture (t,false))); // temp for desugaring

        Util::pushOnto(params.fixtures, f);
        params.inits.push(i);
        if (initexpr)
            params.exprs.push(initexpr);
        params.types.push(t);

        return initexpr != null;
    }

    function parameter () : [Ast::VAR_DEFN_TAG, [Pattern, Ast::TypeExpr]] {
        let kind = match(Token::Const) ? Ast::constTag : Ast::varTag;
        var pattern = dynamic override (beta=allowIn) typedPattern ();
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

    function functionBody () : [Ast::Stmt, Boolean] {
        if (match(Token::LeftBrace)) {
            let r = dynamic override (omega=fullStmt, tau=localBlk) directivesLocal();
            eat (Token::RightBrace);
            return r;
        }

        let expr = dynamic override (alpha=allowColon) assignmentExpression ();
        return [[new Ast::ReturnStmt (expr)], false];
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
        let superinterfaces = interfaceList(Token::id_implements);
        let protectedNs = new Ast::ProtectedNamespace (classid);  // FIXME: needs to use attrs.ns too!
        let privateNs = new Ast::PrivateNamespace (classid);      // FIXME: needs to use attrs.ns too!

        currentClassName = classid;                               // FIXME: needs to use attrs.ns too!
        cx.enterClassStatic();
        cx.enterClassInstance();
        cx.pushNamespace(protectedNs);
        cx.pushNamespace(privateNs);
        cx.addFixture(Ast::varInit,
                      new Ast::PropName(new Ast::Name(privateNs, "private")),
                      new Ast::NamespaceFixture(privateNs),
                      true);
        cx.addFixture(Ast::varInit,
                      new Ast::PropName(new Ast::Name(privateNs, "protected")),
                      new Ast::NamespaceFixture(protectedNs),
                      true);

        eat (Token::LeftBrace);
        let [directive_list, ctor] = directivesClass();
        eat (Token::RightBrace);

        let ihead = cx.exitClassInstance();
        let chead = cx.exitClassStatic();
        currentClassName = "";

        if (ctor == null)
            ctor = makeDefaultCtor(classid);
            
        if (superclass == null)
            superclass = new Ast::Identifier("Object", Ast::publicNSSL);

        let cname = new Ast::Name(attrs.ns, classid);
        let ctype = Ast::anyType;                                 // FIXME: proper class type
        let itype = Ast::anyType;                                 // FIXME: proper instance type
        let cls = new Ast::Cls (cname,
                                superclass,
                                superinterfaces,
                                protectedNs,
                                ctor,
                                chead,
                                ihead,
                                ctype,
                                itype,
                                directive_list,
                                attrs.dynamic,
                                attrs.final);

        cx.addFixture(Ast::varInit, new Ast::PropName(cname), new Ast::ClassFixture (cls));
    }

    function interfaceDefinition(attrs): void {
        eat (Token::Interface);
            
        let interfaceid = identifier ();
        let signature = typeSignature ();       // FIXME: not used yet
        let superinterfaces = interfaceList(Token::id_extends);

        currentClassName = "";

        cx.enterClassInstance();
        interfaceBody ();
        let ihead = cx.exitClassInstance();

        let iname = new Ast::Name(attrs.ns, interfaceid);
        let iface = new Ast::Interface(iname, superinterfaces, ihead);

        cx.addFixture(Ast::varInit, new Ast::PropName(iname), new Ast::InterfaceFixture (iface));
    }

    function makeDefaultCtor(classname) {
        cx.enterFunction(makeAttrs());
        let ctorbody = [];
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
                                  attr,
                                  false);
        return new Ast::Ctor ([],[], func);
    }

    function typeSignature () : [[Ast::IDENT], boolean] {
        let type_params = typeParameters ();
        let is_nonnullable = match(Token::Not);

        return [type_params, is_nonnullable];
    }

    function extendsClause() {
        if (matchToken(Token::id_extends))
            return primaryName ();
        return null;
    }

    function interfaceList(tok) {  // tok is Token::id_extends or Token::id_implements
        let names = [];
        if (matchToken(tok)) {
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

    function directivesGlobal(): [Ast::Stmt] {
        // pragma, var, let, const, function, type, namespace, class, interface, statement
        let stmts = [];

        Util::assert(tau == globalBlk);
        while (hd () != Token::RightBrace && hd () != Token::EOS) {
            let attrs = 0;
            let ns = null;
            let labels = null;

            loop:
            for (;;) {
                switch (hd()) {
                // "Dynamic" is handled below
                case Token::Final:    attrs = checkAttr(attrs, ATTR_FINAL, "final"); next(); break;
                case Token::Native:   attrs = checkAttr(attrs, ATTR_NATIVE, "native"); next(); break;

                case Token::Use:
                    if (attrs != 0 || ns != null)
                        Parse::syntaxError(this, "Illegal attribute on pragma.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled pragma.");
                    pragma(true);
                    break loop;

                case Token::Var:
                case Token::Let:
                case Token::Const:
                    if (hd() != Token::Const || hd2() != Token::Function) {
                        if (attrs != 0)
                            Parse::syntaxError(this, "Illegal attribute on variable definition.");
                        let e = dynamic override (beta=allowIn) variableDefinition (makeAttrs(ns, attrs));
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
                    dynamic override (omega=fullStmt) functionDefinition (makeAttrs(ns, attrs));
                    firstdirective = false;
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
                    dynamic override (tau = classBlk) classDefinition(makeAttrs(ns, attrs));
                    break loop;

                case Token::Interface:
                    if (attrs != 0)
                        Parse::syntaxError(this, "Illegal attribute on interface definition.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled interface definition.");
                    dynamic override (tau = interfaceBlk) interfaceDefinition(makeAttrs(ns, attrs));
                    break loop;

                default: {
                    // Extension: "dynamic override" expression forms, see
                    // dynamicOverrideExpression(), above.
                    if (hd() == Token::Dynamic && hd2() != Token::Override) {
                        attrs = checkAttr(attrs, ATTR_DYNAMIC, "dynamic"); 
                        next(); 
                        break;
                    }

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

    function directivesClass(): [Ast::Stmt, Ast::Ctor] {
        // pragma, var, const, function, type, namespace, static-init
        let stmts = [];
        let ctor = null;

        Util::assert( tau == classBlk );
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
                case Token::__Proto__: attrs = checkAttr(attrs, ATTR_PROTOTYPE, "prototype"); next(); break;

                case Token::Use:
                    pragma(true);
                    break loop;

                case Token::Var:
                case Token::Const: {
                    if ((attrs & ~(ATTR_PROTOTYPE | ATTR_STATIC)) != 0)
                        Parse::syntaxError(this, "Illegal attribute on variable definition.");
                    let e = dynamic override (beta=allowIn) variableDefinition (makeAttrs(ns, attrs));
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
                        ctor = dynamic override (omega=fullStmt) constructorDefinition (cx.getDefaultNamespace(), makeAttrs(ns, attrs));
                    }
                    else
                        dynamic override (omega=fullStmt) functionDefinition (makeAttrs(ns, attrs));
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
        Util::assert( tau == interfaceBlk );
        while (hd () != Token::RightBrace && hd () != Token::EOS) {
            let ns = null;

            loop:
            for (;;) {
                if (hd() == Token::Function) {
                    dynamic override (omega=fullStmt) functionDefinition(makeAttrs(ns, 0));
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
    // they should be evaluated, and a strict-mode flag.

    function directivesLocal(n=1e500): [Ast::Stmt, Boolean] {
        // pragma, var, let, const, function, statement
        let stmts = [];
        let strict_pragma_ok = true;

        Util::assert( tau == localBlk );
        while (hd () != Token::RightBrace && hd () != Token::EOS && n-- != 0) {
            let attrs = 0;
            let ns = null;
            let labels = null;

            loop:
            for (;;) {
                if (hd() != Token::Use)
                    strict_pragma_ok = false;

                switch (hd()) {
                case Token::Use:
                    if (attrs != 0)
                        Parse::syntaxError(this, "Illegal attribute on pragma.");
                    if (labels != null)
                        Parse::syntaxError(this, "Illegal labeled pragma.");
                    pragma(strict_pragma_ok);
                    break loop;

                case Token::Var:
                case Token::Let:
                case Token::Const:
                    if (hd() != Token::Const || hd2() != Token::Function) {
                        if (attrs != 0)
                            Parse::syntaxError(this, "Illegal attribute on variable definition.");
                        let e = dynamic override (beta=allowIn) variableDefinition (makeAttrs(Ast::publicNS, attrs));
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
                    dynamic override (omega=fullStmt) functionDefinition (makeAttrs(Ast::publicNS, attrs));
                    break loop;

                default: {
                    // Actually namespaces aren't allowed so push that test down for better error reporting.
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

        return [stmts, cx.getStrict()];
    }

    function plausibleNamespaceName() {
        if (hd() == Token::Identifier)
            return cx.evalIdentExprToNamespace (primaryName ());
        return null;
    }
  
    function statementOrNamespace(stmts, ns, labels) {
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
            pushStmt(stmts, labels, (dynamic override (omega=fullStmt) statement()));
            return false;
        }

        let e = fullCommaExpression ();
        let t = hd();
        if (t == Token::SemiColon || t == Token::RightBrace || t == Token::EOS || newline()) {
            semicolon(fullStmt);
            pushStmt(stmts, labels, new Ast::ExprStmt (e));
            return false;
        }

        if (!(e is Ast::IdentExpr))
            Parse::syntaxError(this, "Namespace attribute required here.");
        if (ns != null)
            Parse::syntaxError(this, "Duplicate namespace attribute.");
        ns = cx.evalIdentExprToNamespace(e);
        return [ns, labels];
    }


    function pushStmt(stmts, labels, s) {
        if (labels != null) {
            if (s is Ast::LabelSet)
                Util::pushOnto(s.labels, labels);
            for ( let i=labels.length-1 ; i >= 0 ; --i )
                s = new Ast::LabeledStmt(labels[i], s);
        }
        stmts.push(s);
    }

    // PRAGMAS

    function pragma (strict_ok_here=false) {
        eat(Token::Use);
        do {
            if (match(Token::Namespace)) 
                cx.openNamespace (primaryName ());
            else if (match(Token::Default)) {
                eat(Token::Namespace);
                if (tau == localBlk)
                    Parse::syntaxError(this, "Pragma 'use default namespace' is not allowed in blocks.");
                let name = primaryName ();
                cx.setDefaultNamespace(name);
            }
            else if (matchToken(Token::id_strict)) {
                if (tau != globalBlk && !strict_ok_here)
                    Parse::syntaxError(this, "Pragma 'use strict' is not allowed here.");
                cx.setStrict(true);
            }
            else if (matchToken(Token::id_standard)) {
                if (tau != globalBlk)
                    Parse::syntaxError(this, "Pragma 'use standard' is not allowed except at the global level.");
                cx.setStrict(false);
            }
            else
                Parse::syntaxError(this, "Unknown token following 'use': " + lexeme());
        } while (match(Token::Comma));
        semicolon (fullStmt);
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

    function program () : Ast::Program {
        start();

        // FIXME: The following realization of the internal namespace
        // is not at all safe, but using a random number here makes
        // testing more difficult, and using a hash of the input is
        // slow.  So this will do for the moment.

        let internalNamespace = new Ast::InternalNamespace("<#internal " + filename + ">");

        cx.enterGlobal ();
        cx.addFixture(Ast::varInit, 
                      new Ast::PropName(new Ast::Name(internalNamespace, "internal")),
                      new Ast::NamespaceFixture(internalNamespace));
        cx.addFixture(Ast::varInit,
                      new Ast::PropName(new Ast::Name(internalNamespace, "public")),
                      new Ast::NamespaceFixture(Ast::publicNS));
        cx.pushNamespace(internalNamespace);
        cx.pushNamespace(Ast::publicNS);

        let global_directives = directivesGlobal ();
        let vhead = cx.exitGlobal ();

        if (hd () != Token::EOS)
            Parse::syntaxError(this, "extra tokens after end of program.");

        computeAttributes(cx.topFunction());

        return new Ast::Program ( global_directives,
                                  vhead,
                                  cx.topFunction(),
                                  filename );
    }
}
