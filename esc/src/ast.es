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

/* ast.es */

public namespace Ast

{
    use default namespace Ast;
    //    use namespace intrinsic;

    // Bug 425467 that this needs to be public
    public interface ISerializable {
    }

    // BASIC TYPES

    type IDENT = String;   // unicode string
    type IDENTS = [IDENT];

    type HEAD = Head;

    class Head implements ISerializable {
        public const fixtures: FIXTURES;  
        public const exprs: EXPRS;
        function Head (fixtures,exprs)
            : fixtures=fixtures
            , exprs=exprs {}

        function serialize(s)
            s.sClass(this, "Head", "fixtures", "exprs");
    }

    // FIXME
    public interface IFixtureName {
    }

    class TempName implements IFixtureName, ISerializable {
        const index : int;
        function TempName (index) : index=index {}

        function serialize(s)
            s.sClass(this, "TempName", "index");
    }

    class PropName implements IFixtureName, ISerializable {
        const name: Name;
        function PropName(name) : name=name {}

        function serialize(s)
            s.sClass(this, "PropName", "name");
    }

    type FIXTURE_BINDING = [IFixtureName,Fixture];
    type FIXTURES = [FIXTURE_BINDING];

    type INIT_BINDING = [IFixtureName,Expr]
    type INITS = [INIT_BINDING];

    type NAMES = [Name];

    class Name implements ISerializable {
        public const ns;
        public const id;
        function Name(ns, id) : ns=ns, id=id {}
     
        function serialize(s)
            s.sClass(this, "Name", "ns", "id");
    }

    // Namespace

    public interface INamespace {
    }

    type NAMESPACES = [INamespace];

    class IntrinsicNamespace implements INamespace, ISerializable {
        function hash () { return "intrinsic"; }

        function serialize(s)
            s.sClass(this, "IntrinsicNamespace");
    }

    class PrivateNamespace implements INamespace, ISerializable {
        const name : IDENT
        function PrivateNamespace (name)
            : name = name { }
        function hash () { return "private " + name; }

        function serialize(s)
            s.sClass(this, "PrivateNamespace", "name");
    }

    class ProtectedNamespace implements INamespace, ISerializable {
        const name : IDENT
        function ProtectedNamespace (name)
            : name = name { }
        function hash () { return "protected " + name; }

        function serialize(s)
            s.sClass(this, "ProtectedNamespace", "name");
    }

    class PublicNamespace implements INamespace, ISerializable {
        const name : IDENT;
        function PublicNamespace (name)
            : name = name { }
        function hash () { return "public " + name; }

        function serialize(s)
            s.sClass(this, "PublicNamespace", "name");
    }

    class InternalNamespace implements INamespace, ISerializable {
        const name : IDENT;
        function InternalNamespace (name)
            : name = name { }
        function hash () { return "internal " + name; }

        function serialize(s)
            s.sClass(this, "InternalNamespace", "name");
    }

    class UserNamespace implements INamespace, ISerializable {
        const name : IDENT;
        function UserNamespace (name)
            : name = name { }
        function hash () { return "use " + name; }

        function serialize(s)
            s.sClass(this, "UserNamespace", "name");
    }

    class AnonymousNamespace implements INamespace, ISerializable {
        const name : IDENT;
        function AnonymousNamespace (name)
            : name = name { }
        function hash () { return "anon " + name; }

        function serialize(s)
            s.sClass(this, "AnonymousNamespace", "name");
    }

    class ImportNamespace implements INamespace, ISerializable {
        const ident : IDENT
        const ns : PublicNamespace
            function ImportNamespace(ident, ns) : ident=ident, ns=ns {}

        function hash () { return "import " + ns.hash; }

        function serialize(s)
            s.sClass(this, "ImportNamespace", "ident", "ns");
    }

    const noNS = new PublicNamespace ("");

    // Binary type operators

    type BINTYOP = int;

    const castOp = 0;
    const isOp = 1;

    // Binary arithmetic and logical operators

    type BINOP = int;

    const plusOp = 0;
    const minusOp = 1;
    const timesOp = 2;
    const divideOp = 3;
    const remainderOp = 4;
    const leftShiftOp = 5;
    const rightShiftOp = 6;
    const rightShiftUnsignedOp = 7;
    const bitwiseAndOp = 8;
    const bitwiseOrOp = 9;
    const bitwiseXorOp = 10;
    const logicalAndOp = 11;
    const logicalOrOp = 12;
    const instanceOfOp = 13;
    const inOp = 14;
    const equalOp = 15;
    const notEqualOp = 16;
    const strictEqualOp = 17;
    const strictNotEqualOp = 18;
    const lessOp = 19;
    const lessOrEqualOp = 20;
    const greaterOp = 21;
    const greaterOrEqualOp = 22;
    const commaOp = 23;

    // Assignment operators

    type ASSIGNOP = int;

    const assignOp = 0;
    const assignPlusOp = 1;
    const assignMinusOp = 2;
    const assignTimesOp = 3;
    const assignDivideOp = 4;
    const assignRemainderOp = 5;
    const assignLeftShiftOp = 6;
    const assignRightShiftOp = 7;
    const assignRightShiftUnsignedOp = 8;
    const assignBitwiseAndOp = 9;
    const assignBitwiseOrOp = 10;
    const assignBitwiseXorOp = 11;
    const assignLogicalAndOp = 12;
    const assignLogicalOrOp = 13;

    // Unary arithmetic and logical operators

    type UNOP = int;

    const deleteOp = 0;
    const voidOp = 1;
    const typeOfOp = 2;
    const preIncrOp = 3;
    const preDecrOp = 4;
    const postIncrOp = 5;
    const postDecrOp = 6;
    const unaryPlusOp = 7;
    const unaryMinusOp = 8;
    const bitwiseNotOp = 9;
    const logicalNotOp = 10;
    const typeOp = 11;

    // EXPR

    // Bug 425467 that this needs to be public
    public class Expr {
        public var pos: int;
        function Expr(pos=0) : pos=pos {}
    }

    type EXPRS = [Expr];

    class TernaryExpr extends Expr implements ISerializable {
        const e1 : Expr
        const e2 : Expr
        const e3 : Expr
        function TernaryExpr (e1,e2,e3) : e1=e1, e2=e2, e3=e3 {}

        function serialize(s)
            s.sClass(this, "TernaryExpr", "e1", "e2", "e3");
    }

    class BinaryExpr extends Expr implements ISerializable {
        const op : BINOP
        const e1 : Expr
        const e2 : Expr
        function BinaryExpr (op,e1,e2) : op=op, e1=e1, e2=e2 {}

        function serialize(s)
            s.sClass(this, "BinaryExpr", "op", "e1", "e2");
    }

    class BinaryTypeExpr extends Expr implements ISerializable {
        const op : BINTYOP
        const e1 : Expr
        const e2 : TYPE_EXPR
        function BinaryTypeExpr (op,e1,e2) : op=op, e1=e1, e2=e2 {}

        function serialize(s)
            s.sClass(this, "BinaryTypeExpr", "op", "e1", "e2");
    }

    class UnaryExpr extends Expr implements ISerializable {
        const op : UNOP;
        const e1 : Expr;
        function UnaryExpr (op,e1) : op=op, e1=e1 {}

        function serialize(s)
            s.sClass(this, "UnaryExpr", "op", "e1");
    }

    // FIXME: ex => expr
    class TypeExpr extends Expr implements ISerializable {
        const ex : TYPE_EXPR;
        function TypeExpr (ex) : ex=ex {}

        function serialize(s)
            s.sClass(this, "TypeExpr", "ex");
    }

    class ThisExpr extends Expr implements ISerializable {
        function serialize(s)
            s.sClass(this, "ThisExpr");
    }

    // FIXME: ex => expr
    class YieldExpr extends Expr implements ISerializable {
        const ex : Expr?;
        function YieldExpr (ex=null) : ex=ex {}

        function serialize(s)
            s.sClass(this, "YieldExpr", "ex");
    }

    // FIXME: ex => expr
    class SuperExpr extends Expr implements ISerializable {
        const ex : Expr?;
        function SuperExpr (ex=null) : ex=ex {}

        function serialize(s)
            s.sClass(this, "SuperExpr", "ex");
    }

    class LiteralExpr extends Expr implements ISerializable {
        const literal : LITERAL;
        function LiteralExpr (literal, pos=0)
            : literal=literal
            , super(pos) {}

        function serialize(s)
            s.sClass(this, "LiteralExpr", "literal", "pos");
    }

    class CallExpr extends Expr implements ISerializable {
        const expr : Expr;
        const args : EXPRS;
        function CallExpr (expr,args,pos=0)
            : expr=expr
            , args=args
            , super(pos) {}

        function serialize(s)
            s.sClass(this, "CallExpr", "expr", "args", "pos");
    }

    class ApplyTypeExpr extends Expr implements ISerializable {
        const expr : Expr;
        const args : TYPE_EXPRS;
        function ApplyTypeExpr (expr,args)
            : expr=expr
            , args=args {}

        function serialize(s)
            s.sClass(this, "ApplyTypeExpr", "expr", "args");
    }

    class LetExpr extends Expr implements ISerializable {
        const head : HEAD;
        const expr : Expr;
        function LetExpr (head,expr)
            : head = head
            , expr = expr {}

        function serialize(s)
            s.sClass(this, "LetExpr", "head", "expr");
    }

    class NewExpr extends Expr implements ISerializable {
        const expr : Expr;
        const args : EXPRS;
        function NewExpr (expr,args)
            : expr = expr
            , args = args {}

        function serialize(s)
            s.sClass(this, "NewExpr", "expr", "args");
    }

    class ObjectRef extends Expr implements ISerializable {
        const base : Expr;
        const ident : IdentExpr;
        function ObjectRef (base,ident,pos=0)
            : base = base
            , ident = ident
            , super(pos) { }

        function serialize(s)
            s.sClass(this, "ObjectRef", "base", "ident", "pos");
    }

    class LexicalRef extends Expr implements ISerializable {
        const ident : IdentExpr;
        function LexicalRef (ident, pos=0)
            : ident = ident
            , super(pos) { }

        function serialize(s)
            s.sClass(this, "LexicalRef", "ident", "pos");
    }

    // FIXME: le? re?
    class SetExpr extends Expr implements ISerializable {
        const op : ASSIGNOP;
        const le : Expr;
        const re : Expr;
        function SetExpr (op,le,re,pos=0)
            : op=op
            , le=le
            , re=re 
            , super(pos) {}

        function serialize(s)
            s.sClass(this, "SetExpr", "op", "le", "re");
    }

    class EvalScopeInitExpr extends Expr implements ISerializable {
        const index: int;
        const how: String;
        function EvalScopeInitExpr(index, how)
            : index=index
            , how=how
        {}

        function serialize(s)
            s.sClass(this, "EvalScopeInitExpr", "index", "how");
    }

    type INIT_TARGET = int;

    const varInit = 0;
    const letInit = 1;
    const prototypeInit = 2;
    const instanceInit = 3;

    class InitExpr extends Expr implements ISerializable {
        const target : INIT_TARGET;
        const head : HEAD;               // for desugaring temporaries
        const inits  //: INITS;
        function InitExpr (target, head, inits)
            : target = target
            , head = head
            , inits = inits {}

        function serialize(s)
            s.sClass(this, "InitExpr", "target", "head", "inits");
    }

    class SliceExpr extends Expr implements ISerializable {
        const e1 : Expr;
        const e2 : Expr;
        const e3 : Expr;
        function SliceExpr(e1, e2, e3)
            : e1=e1
            , e2=e2
            , e3=e3 { }

        function serialize(s)
            s.sClass(this, "SliceExpr", "e1", "e2", "e3");
    }

    class GetTemp extends Expr implements ISerializable {
        const n : int;
        function GetTemp (n)
            : n = n {}

        function serialize(s)
            s.sClass(this, "GetTemp", "n");
    }

    class GetParam extends Expr implements ISerializable {
        const n : int;
        function GetParam (n) 
            : n = n {}

        function serialize(s)
            s.sClass(this, "GetParam", "n");
    }

    // IdentExpr

    public interface IIdentExpr {
    }

    class Identifier extends Expr implements IIdentExpr, ISerializable {
        const ident : IDENT;
        const nss //: NAMESPACES;
        function Identifier (ident,nss)
            : ident = ident
            , nss = nss {}

        function serialize(s)
            s.sClass(this, "Identifier", "ident", "nss");
    }

    class QualifiedExpression extends Expr implements IIdentExpr, ISerializable {
        const qual : Expr;
        const expr : Expr;
        function QualifiedExpression (qual,expr)
            : qual=qual
            , expr=expr {}

        function serialize(s)
            s.sClass(this, "QualifiedExpression", "qual", "expr");
    }

    class AttributeIdentifier extends Expr implements IIdentExpr, ISerializable {
        const ident : IdentExpr;
        function AttributeIdentifier (ident)
            : ident=ident {}

        function serialize(s)
            s.sClass(this, "AttributeIdentifier", "ident");
    }

    class ReservedNamespace extends Expr implements IIdentExpr, ISerializable {
        const ns: INamespace;
        function ReservedNamespace (ns)
            : ns=ns {}

        function serialize(s)
            s.sClass(this, "ReservedNamespace", "ns");
    }

    class ExpressionIdentifier extends Expr implements IIdentExpr, ISerializable {
        const expr: Expr;
        const nss //: [INamespace];
        function ExpressionIdentifier (expr,nss)
            : expr=expr
            , nss = nss { }

        function serialize(s)
            s.sClass(this, "ExpressionIdentifier", "expr", "nss");
    }

    class QualifiedIdentifier extends Expr implements IIdentExpr, ISerializable {
        const qual : Expr;
        const ident : IDENT;
        function QualifiedIdentifier (qual,ident)
            : qual=qual
            , ident=ident {}

        function serialize(s)
            s.sClass(this, "QualifiedIdentifier", "qual", "ident");
    }

    class TypeIdentifier extends Expr implements IIdentExpr, ISerializable {
        const ident : IdentExpr;
        const typeArgs : TYPE_EXPRS;
        function TypeIdentifier (ident,typeArgs)
            : ident=ident
            , typeArgs=typeArgs {}

        function serialize(s)
            s.sClass(this, "TypeIdentifier", "ident", "typeArgs");
    }

    class UnresolvedPath extends Expr implements IIdentExpr, ISerializable {
        const path /*: IDENTS */;
        const ident : IdentExpr;
        function UnresolvedPath (path,ident)
            : path=path
            , ident=ident {}

        function serialize(s)
            s.sClass(this, "UnresolvedPath", "path", "ident");
    }

    class WildcardIdentifier extends Expr implements IIdentExpr, ISerializable {
        function serialize(s)
            s.sClass(this, "WildcardIdentifier");
    }

    // Literal expressions

    public interface ILiteralExpr {
    }

    class LiteralNull extends Expr implements ILiteralExpr, ISerializable {
        function serialize(s)
            s.sClass(this, "LiteralNull");
    }

    class LiteralUndefined extends Expr implements ILiteralExpr, ISerializable {
        function serialize(s)
            s.sClass(this, "LiteralUndefined");
    }

    class LiteralContextDecimal extends Expr implements ILiteralExpr, ISerializable {
        const strValue : String;
        function LiteralContextDecimal (strValue)
            : strValue=strValue {}

        function serialize(s)
            s.sClass(this, "LiteralNull", "strValue");
    }

    // FIXME: obsolete?
    class LiteralContextDecimalInteger extends Expr implements ILiteralExpr, ISerializable {
        const strValue : String;
        function LiteralContextDecimalInteger (strValue)
            : strValue=strValue {}

        function serialize(s)
            s.sClass(this, "LiteralContextDecimalInteger", "strValue");
    }

    // FIXME: obsolete?
    class LiteralContextHexInteger extends Expr implements ILiteralExpr, ISerializable {
        const strValue : String;
        function LiteralContextHexInteger (strValue)
            : strValue=strValue {}

        function serialize(s)
            s.sClass(this, "LiteralContextHexInteger", "strValue");
    }

    class LiteralDouble extends Expr implements ILiteralExpr, ISerializable {
        const doubleValue : Number;
        function LiteralDouble (doubleValue)
            : doubleValue=doubleValue { }

        function serialize(s)
            s.sClass(this, "LiteralDouble", "doubleValue");
    }

    class LiteralDecimal extends Expr implements ILiteralExpr, ISerializable {
        const decimalValue : decimal;
        function LiteralDecimal (decimalValue)
            : decimalValue = decimalValue { }

        function serialize(s)
            s.sClass(this, "LiteralDouble", "decimalValue");
    }

    class LiteralInt extends Expr implements ILiteralExpr, ISerializable {
        const intValue : int;
        function LiteralInt(intValue) 
            : intValue=intValue {}

        function serialize(s)
            s.sClass(this, "LiteralInt", "intValue");
    }

    class LiteralUInt extends Expr implements ILiteralExpr, ISerializable {
        const uintValue : uint;
        function LiteralUInt(uintValue) 
            : uintValue=uintValue {}

        function serialize(s)
            s.sClass(this, "LiteralUInt", "uintValue");
    }

    class LiteralBoolean extends Expr implements ILiteralExpr, ISerializable {
        const booleanValue : Boolean;
        function LiteralBoolean(booleanValue) 
            : booleanValue=booleanValue {}

        function serialize(s)
            s.sClass(this, "LiteralBoolean", "booleanValue");
    }

    class LiteralString extends Expr implements ILiteralExpr, ISerializable {
        const strValue : String;
        function LiteralString (strValue)
            : strValue = strValue {}

        function serialize(s)
            s.sClass(this, "LiteralString", "strValue");
    }

    class LiteralArray extends Expr implements ILiteralExpr, ISerializable {
        const exprs //: [EXPR];
        const type : TYPE_EXPR;
        function LiteralArray (exprs,ty)
            : exprs = exprs
            , type = ty { }

        function serialize(s)
            s.sClass(this, "LiteralArray", "exprs", "type");
    }

    class LiteralXML extends Expr implements ILiteralExpr, ISerializable {
        const exprs : [Expr];
        function LiteralXML(exprs) 
            : exprs = exprs {}

        function serialize(s)
            s.sClass(this, "LiteralXML", "exprs");
    }

    class LiteralNamespace extends Expr implements ILiteralExpr, ISerializable {
        const namespaceValue : INamespace;
        function LiteralNamespace (namespaceValue)
            : namespaceValue = namespaceValue { }

        function serialize(s)
            s.sClass(this, "LiteralNamespace", "namespaceValue");
    }

    class LiteralObject extends Expr implements ILiteralExpr, ISerializable {
        const fields : LITERAL_FIELDS;
        const type : TYPE_EXPR;
        function LiteralObject (fields, ty)
            : fields = fields
            , type = ty { }

        function serialize(s)
            s.sClass(this, "LiteralObject", "fields", "type");
    }
    
    type LITERAL_FIELD = LiteralField;
    type LITERAL_FIELDS = [LiteralField];

    class LiteralField implements ISerializable {
        const kind: VAR_DEFN_TAG;
        const ident: IdentExpr;
        const expr: Expr;
        function LiteralField (kind,ident,expr)
            : kind = kind
            , ident = ident
            , expr = expr {}

        function serialize(s)
            s.sClass(this, "LiteralField", "kind", "ident", "expr");
    }

    type FIELD_TYPE = FieldType;
    type FIELD_TYPES = [FIELD_TYPE];

    class LiteralFunction extends Expr implements ILiteralExpr, ISerializable {
        const func : FUNC;
        function LiteralFunction (func)
            : func = func {}

        function serialize(s)
            s.sClass(this, "LiteralFunction", "func");
    }

    class LiteralRegExp extends Expr implements ILiteralExpr, ISerializable {
        const src : String;
        function LiteralRegExp(src)
            : src= src {}

        function serialize(s)
            s.sClass(this, "LiteralRegExp", "src");
    }

    type VAR_DEFN_TAG = int;

    const constTag = 0;
    const varTag = 1;
    const letVarTag = 2;
    const letConstTag = 3;

    class VariableDefn implements ISerializable {
        const ns: INamespace;
        const isStatic: Boolean;
        const isPrototype: Boolean;
        const kind: VAR_DEFN_TAG;
        const bindings: BINDING_INITS;
        function VariableDefn (ns,isStatic,isPrototype,kind,bindings)
            : ns = ns
            , isStatic = isStatic
            , isPrototype = isPrototype
            , kind = kind
            , bindings = bindings {}

        function serialize(s)
            s.sClass(this, "VariableDefn", "ns", "isStatic", "isPrototype", "kind", "bindings");
    }

    // CLS

    type CLS = Cls;

    class Cls implements ISerializable {
        const name //: Name;
        const baseName; //: Name?;
        const interfaceNames; //: NAMES;
        const protectedns;
        const constructor : CTOR;
        const classHead: HEAD;
        const instanceHead: HEAD;
        const classType; //: ObjectType;
        const instanceType; //: InstanceType;
        const classBody;
        const isDynamic;
        const isFinal;
        function Cls (name,baseName,interfaceNames,protectedns,constructor,classHead,instanceHead
                     ,classType,instanceType,classBody,isDynamic,isFinal)
            : name = name
            , baseName = baseName
            , interfaceNames = interfaceNames
            , protectedns = protectedns
            , constructor = constructor
            , classHead = classHead
            , instanceHead = instanceHead
            , classType = classType
            , instanceType = instanceType
            , classBody = classBody
            , isDynamic = isDynamic
            , isFinal = isFinal
        {}

        function serialize(s)
            s.sClass(this, "Cls", 
                     "name", "baseName", "interfaceNames", "protectedns", "constructor",
                     "classHead", "instanceHead", "classType", "instanceType", "classBody",
                     "isDynamic", "isFinal");
    }

    class Interface implements ISerializable {
        const name //: Name;
        const interfaceNames; //: NAMES;
        const instanceHead: HEAD;
        function Interface (name,interfaceNames,instanceHead)
            : name = name
            , interfaceNames = interfaceNames
            , instanceHead = instanceHead
        {}

        function serialize(s)
            s.sClass(this, "Cls", "name", "interfaceNames", "instanceHead");
    }

    // FUNC

    type FUNC = Func;

    class FuncName implements ISerializable {
        public const kind: FUNC_NAME_KIND;
        public const ident: IDENT;
        function FuncName(kind, ident) : kind=kind, ident=ident {}

        function serialize(s)
            s.sClass(this, "FuncName", "kind", "ident");
    }

    type FUNC_NAME_KIND = int;

    const ordinaryFunction = 0;
    const getterFunction = 1;
    const setterFunction = 2;

    class FuncAttr implements ISerializable {
        /* Outer function, or null if the function is at the global
           level (including for class methods). */
        const parent: FuncAttr;

        /* Nested functions and function expressions, empty for leaf functions */
        const children;

        /* True iff identifier "arguments" lexically referenced in function body.
           Note that the parameter list is excluded. */
        var uses_arguments = false;
        
        /* True iff identifier expression "eval" is lexically referenced 
           in the function body as the operator in a call expression. */
        var uses_eval = false;

        /* True iff ...<id> appears in the parameter list. */
        var uses_rest = false;
        
        /* True iff the body has a "with" statement */
        var uses_with = false;

        /* True iff the body has a "try" statement with a "catch" clause */
        var uses_catch = false;

        /* True iff the body has a "try" statement with a "finally" clause */
        var uses_finally = false;

        /* True iff this function is native */
        var is_native = false;

        /* True iff the function must capture its statement result value and return it if 
           control falls off the end */
        var capture_result = false;

        /* Synthesized: true iff activation object must be reified for any reason */
        var reify_activation = false;

        function FuncAttr(...rest) {
            if (rest.length == 1) {
                this.parent = rest[0];
                this.children = [];
            }
            else {
                // Unserialization.  An ad hoc pass over the AST will (hopefully) take 
                // care of patching up parent/children.
                [uses_arguments, uses_eval, uses_rest, uses_with, uses_catch, 
                 uses_finally, is_native, capture_result, reify_activation] = rest;
            }
        }

        function serialize(s)
            s.sClass(this, "FuncAttr", "uses_arguments", "uses_eval", "uses_rest", "uses_with",
                     "uses_catch", "uses_finally", "is_native", "capture_result", "reify_activation");
    }

    class Func implements ISerializable {
        const name //: FUNC_NAME;
        const block: BLOCK;
        const params: HEAD;
        const numparams: int;
        const vars: HEAD;
        const defaults: EXPRS;
        const type: ITypeExpr;
        const attr: FuncAttr;
        function Func (name,block,params,numparams,vars,defaults,ty,attr)
            : name = name
            , block = block
            , params = params
            , numparams = numparams
            , vars = vars
            , defaults = defaults
            , type = ty
            , attr = attr {}

        function serialize(s)
            s.sClass(this, "Func", "name", "block", "params", "numparams", "vars", "defaults", "type", "attr");
    }

    // CTOR

    type CTOR = Ctor;

    class Ctor implements ISerializable {
        const settings : EXPRS;
        const superArgs : EXPRS;
        const func : FUNC;
        function Ctor (settings,superArgs,func)
            : settings = settings
            , superArgs = superArgs
            , func = func {}

        function serialize(s)
            s.sClass(this, "Ctor", "settings", "superArgs", "func");
    }

    // BINDING_INIT

    type BINDING_INITS = [[BINDING],[INIT_STEP]];

    type BINDING = Binding;

    class Binding implements ISerializable {
        const ident : BINDING_IDENT;
        const type : TYPE_EXPR?;
        function Binding (ident,ty)  // FIXME 'type' not allowed as param name in the RI
            : ident = ident
            , type = ty { }

        function serialize(s)
            s.sClass(this, "Binding", "ident", "type");
    }

    public interface IBindingIdent {
    }

    class TempIdent implements IBindingIdent, ISerializable {
        const index : int;
        function TempIdent (index)
            : index = index {}

        function serialize(s)
            s.sClass(this, "TempIdent", "index");
    }

    class ParamIdent implements IBindingIdent, ISerializable {
        const index : int;
        function ParamIdent (index)
            : index = index {}

        function serialize(s)
            s.sClass(this, "ParamIdent", "index");
    }

    class PropIdent implements IBindingIdent, ISerializable {
        const ident : IDENT;
        function PropIdent (ident)
            : ident = ident { }
 
        function serialize(s)
            s.sClass(this, "PropIdent", "ident");
    }

    public interface IInitStep {
    }

    class InitStep implements IInitStep, ISerializable {
        const ident : BINDING_IDENT;
        const expr : Expr;
        function InitStep (ident,expr)
            : ident = ident
            , expr = expr { }
 
        function serialize(s)
            s.sClass(this, "InitStep", "ident", "expr");
    }

    class AssignStep implements IInitStep, ISerializable {
        const le : Expr;
        const re : Expr;
        function AssignStep (le,re)
            : le = le
            , re = re {}

        function serialize(s)
            s.sClass(this, "AssignStep", "le", "re");
    }

    // FIXTURE

    public interface IFixture {
    }

    class NamespaceFixture implements IFixture, ISerializable {
        const ns : INamespace;
        function NamespaceFixture (ns)
            : ns = ns {}

        function serialize(s)
            s.sClass(this, "NamespaceFixture", "ns");
    }

    class ClassFixture implements IFixture, ISerializable {
        const cls : CLS;
        function ClassFixture (cls)
            : cls = cls {}

        function serialize(s)
            s.sClass(this, "ClassFixture", "cls");
    }

    class InterfaceFixture implements IFixture, ISerializable {
        const iface : Interface;
        function InterfaceFixture (iface)
            : iface = iface {}

        function serialize(s)
            s.sClass(this, "InterfaceFixture", "iface");
    }

    class TypeVarFixture implements IFixture, ISerializable {
        function serialize(s)
            s.sClass(this, "TypeVarFixture");
    }

    class TypeFixture implements IFixture, ISerializable {
        const type: TYPE_EXPR;
        function TypeFixture (ty)
            : type = ty {}

        function serialize(s)
            s.sClass(this, "TypeFixture", "type");
    }

    class MethodFixture implements IFixture, ISerializable {
        const func : FUNC;
        const type : TYPE_EXPR;
        const isReadOnly : Boolean;
        const isOverride : Boolean;
        const isFinal : Boolean;
        function MethodFixture(func, ty, isReadOnly, isOverride, isFinal) 
            : func = func
            , type = ty
            , isReadOnly = isReadOnly
            , isOverride = isOverride
            , isFinal = isFinal { }

        function serialize(s)
            s.sClass(this, "MethodFixture", "func", "type", "isReadOnly", "isOverride", "isFinal");
    }

    class ValFixture implements IFixture, ISerializable {
        const type : TYPE_EXPR;
        const isReadOnly : Boolean;
        function ValFixture(ty, isReadOnly) 
            : type=ty
            , isReadOnly=isReadOnly {}

        function serialize(s)
            s.sClass(this, "ValFixture", "type", "isReadOnly");
    }

    class VirtualValFixture implements IFixture, ISerializable {
        const type : TYPE_EXPR;
        const getter : FUNC?;
        const setter : FUNC?;

        function VirtualValFixture(ty, getter, setter)
            : type=ty
            , getter=getter
            , setter=setter {}

        function serialize(s)
            s.sClass(this, "VirtualValFixture", "type", "getter", "setter");
    }

    // TYPE_EXPR

    public interface ITypeExpr {
    }

    type TYPE_EXPRS = [ITypeExpr];

    type SPECIAL_TYPE_KIND = int;

    class SpecialType implements ITypeExpr, ISerializable {
        const kind : SPECIAL_TYPE_KIND;
        function SpecialType(kind) : kind=kind {}

        function serialize(s)
            s.sConstant("Ast::specialTypes[" + kind + "]");
    }

    const specialTypes = [new SpecialType(0), 
                          new SpecialType(1), 
                          new SpecialType(2), 
                          new SpecialType(3)];

    const [anyType, nullType, undefinedType, voidType] = specialTypes;

    // These may not be required any more, serialization and
    // deserialization preserves identity of the special type objects.

    function isAnyType(t:ITypeExpr): Boolean
        t is SpecialType && t.kind == 0;

    function isNullType(t:ITypeExpr): Boolean
        t is SpecialType && t.kind == 1;

    function isUndefinedType(t:ITypeExpr): Boolean
        t is SpecialType && t.kind == 2;

    function isVoidType(t:ITypeExpr): Boolean
        t is SpecialType && t.kind == 3;

    class UnionType implements ITypeExpr, ISerializable {
        const types : TYPE_EXPRS;
        function UnionType (types)
            : types = types { }

        function serialize(s)
            s.sClass(this, "UnionType", "types");
    }

    class ArrayType implements ITypeExpr, ISerializable {
        const types : TYPE_EXPRS;
        function ArrayType (types)
            : types = types { }

        function serialize(s)
            s.sClass(this, "ArrayType", "types");
    }

    class TypeName implements ITypeExpr, ISerializable {
        const ident : IdentExpr;
        function TypeName (ident)
            : ident = ident {}

        function serialize(s)
            s.sClass(this, "TypeName", "ident");
    }

    class ElementTypeRef implements ITypeExpr, ISerializable {
        const base : TYPE_EXPR;
        const index : int;
        function ElementTypeRef (base,index)
            : base = base
            , index = index { }

        function serialize(s)
            s.sClass(this, "ElementTypeRef", "base", "index");
    }

    class FieldTypeRef implements ITypeExpr, ISerializable {
        const base : TYPE_EXPR;
        const ident : IdentExpr;
        function FieldTypeRef (base,ident)
            : base = base
            , ident = ident { }

        function serialize(s)
            s.sClass(this, "FieldTypeRef", "base", "ident");
    }

    class FunctionType implements ITypeExpr, ISerializable {
        const ftype /* ??? maybe FUNC_SIG from parse.es, maybe not -- node not in use */;
        function FunctionType(ftype) : ftype=ftype {}

        function serialize(s) 
            s.sClass(this, "FunctionType", "ftype");
    }

    class ObjectType implements ISerializable {
        const fields : [FIELD_TYPE];
        function ObjectType (fields)
            : fields = fields { }

        function serialize(s)
            s.sClass(this, "ObjectType", "fields");
    }

    class FieldType implements ISerializable {
        const ident: IDENT;
        const type: TYPE_EXPR;
        function FieldType (ident,ty)
            : ident = ident
            , type = ty {}

        function serializable(s)
            s.sClass(this, "FieldType", "ident", "type");
    }

    class AppType implements ISerializable {
        const base : TYPE_EXPR;
        const args : TYPE_EXPRS;
        function AppType (base,args)
            : base = base
            , args = args { }

        function serializable(s)
            s.sClass(this, "AppType", "base", "args");
    }

    class NullableType implements ISerializable {
        const type : TYPE_EXPR;
        const isNullable : Boolean;
        function NullableType (ty,isNullable)
            : type = ty
            , isNullable = isNullable { }

        function serialize(s)
            s.sClass(this, "NullableType", "type", "isNullable");
    }

    class InstanceType implements ISerializable {
        const name : Name;
        const typeParams : IDENTS;
        const type : TYPE_EXPR;
        const isDynamic : Boolean;
        function InstanceType(name, typeParams, ty, isDynamic)
            : name=name
            , typeParams=typeParams
            , type=ty
            , isDynamic=isDynamic
        { }

        function serialize(s)
            s.sClass(this, "InstanceType", "name", "typeParams", "type", "isDynamic");
    }


    // Statements

    // Bug 425467 that this needs to be public
    public interface IStmt {
        // No common methods, this is just a tag
    }

    type STMTS = [Ast::IStmt];

    class EmptyStmt implements IStmt, ISerializable {
        function serialize(s)
            s.sClass(this, "EmptyStmt");
    }

    class ExprStmt implements IStmt, ISerializable {
        const expr : Expr;
        function ExprStmt (expr)
            : expr = expr {}

        function serialize(s)
            s.sClass(this, "ExprStmt", "expr");
    }

    class ForInStmt implements IStmt, ISerializable {
        const vars : HEAD;
        const init : Expr?;
        const obj  : Expr;
        const stmt : IStmt;
        const is_each : boolean;
        const labels : IDENTS;
        function ForInStmt (vars,init,obj,stmt,is_each=false,labels=null)
            : vars = vars
            , init = init
            , obj = obj
            , stmt = stmt
            , is_each = is_each
            , labels = labels == null ? [] : labels {}

        function serialize(s)
            s.sClass(this, "ForInStmt", "vars", "init", "obj", "stmt", "is_each", "labels");
    }

    class ThrowStmt implements IStmt, ISerializable {
        const expr : Expr;
        function ThrowStmt (expr)
            : expr = expr { }

        function serialize(s)
            s.sClass(this, "ThrowStmt", "expr");
    }

    class ReturnStmt implements IStmt, ISerializable {
        const expr : Expr?;
        function ReturnStmt(expr) 
            : expr = expr { }

        function serialize(s)
            s.sClass(this, "ReturnStmt", "expr");
    }

    class BreakStmt implements IStmt, ISerializable {
        const ident : IDENT?;
        function BreakStmt (ident)
            : ident = ident { }

        function serialize(s)
            s.sClass(this, "BreakStmt", "ident");
    }

    class ContinueStmt implements IStmt, ISerializable {
        const ident : IDENT?;
        function ContinueStmt (ident)
            : ident = ident { }

        function serialize(s)
            s.sClass(this, "ContinueStmt", "ident");
    }

    class BlockStmt implements IStmt, ISerializable {
        const block : BLOCK;
        function BlockStmt (block)
            : block = block {}

        function serialize(s)
            s.sClass(this, "BlockStmt", "block");
    }

    class LabeledStmt implements IStmt, ISerializable {
        const label : IDENT;
        const stmt : IStmt;
        function LabeledStmt (label,stmt)
            : label = label
            , stmt = stmt { }

        function serialize(s)
            s.sClass(this, "LabeledStmt", "label", "stmt");
    }

    class LetStmt implements IStmt, ISerializable {
        const block : BLOCK;
        function LetStmt (block)
            : block = block {}

        function serialize(s)
            s.sClass(this, "LetStmt", "block");
    }

    class WhileStmt implements IStmt, ISerializable {
        const expr : Expr;
        const stmt : IStmt;
        const labels : IDENTS;
        function WhileStmt (expr,stmt,labels=null)
            : expr = expr
            , stmt = stmt
            , labels = labels == null ? [] : labels {}

        function serialize(s)
            s.sClass(this, "WhileStmt", "expr", "stmt", "labels");
    }

    class DoWhileStmt implements IStmt, ISerializable {
        const expr : Expr;
        const stmt : IStmt;
        const labels : IDENTS;
        function DoWhileStmt (expr,stmt,labels=null)
            : expr = expr
            , stmt = stmt 
            , labels = labels == null ? [] : labels {}

        function serialize(s)
            s.sClass(this, "DoWhileStmt", "expr", "stmt", "labels");
    }

    class ForStmt implements IStmt, ISerializable {
        const vars : HEAD;
        const init : Expr?;
        const cond : Expr?;
        const incr : Expr?;
        const stmt : IStmt;
        const labels : IDENTS;
        function ForStmt (vars,init,cond,incr,stmt,labels=null)
            : vars = vars
            , init = init
            , cond = cond
            , incr = incr
            , stmt = stmt
            , labels = labels == null ? [] : labels {}

        function serialize(s)
            s.sClass(this, "ForStmt", "vars", "init", "cond", "incr", "stmt", "labels");
    }

    class IfStmt implements IStmt, ISerializable {
        const expr : Expr;
        const then : IStmt;
        const elseOpt : IStmt?;
        function IfStmt (expr,then,elseOpt)
            : expr = expr
            , then = then
            , elseOpt = elseOpt { }

        function serialize(s)
            s.sClass(this, "IfStmt", "expr", "cases");
    }

    class SwitchStmt implements IStmt, ISerializable {
        const expr : Expr;
        const cases : CASES;
        function SwitchStmt (expr, cases)
            : expr = expr
            , cases = cases { }

        function serialize(s)
            s.sClass(this, "SwitchStmt", "expr", "cases");
    }

    type CASE = Case;
    type CASES = [CASE];

    class Case implements IStmt, ISerializable {
        const expr : Expr?;  // null for default
        const stmts : STMTS;
        function Case (expr,stmts)
            : expr = expr
            , stmts = stmts { }

        function serialize(s)
            s.sClass(this, "Case", "expr", "stmts");
    }

    class WithStmt implements IStmt, ISerializable {
        const expr : Expr;
        const stmt : IStmt;
        function WithStmt (expr,stmt)
            : expr = expr
            , stmt = stmt { }

        function serialize(s)
            s.sClass(this, "WithStmt", "expr", "stmt");
    }

    class TryStmt implements IStmt, ISerializable {
        const block : BLOCK;
        const catches: CATCHES;
        const finallyBlock: BLOCK?;
        function TryStmt (block,catches,finallyBlock)
            : block = block
            , catches = catches
            , finallyBlock = finallyBlock { }

        function serialize(s)
            s.sClass(this, "TryStmt", "block", "catches", "finallyBlock");
    }

    class SwitchTypeStmt implements IStmt, ISerializable {
        const expr: Expr;
        const type: TYPE_EXPR;
        const cases: CATCHES;
        function SwitchTypeStmt (expr,ty,cases)
            : expr = expr
            , type = ty
            , cases = cases { }

        function serialize(s)
            s.sClass(this, "SwitchTypeStmt", "expr", "ty", "cases");
    }

    type CATCH = Catch;
    type CATCHES = [CATCH];

    class Catch implements ISerializable {
        const param: HEAD;
        const block: BLOCK;
        function Catch (param,block)
            : param = param
            , block = block { }

        function serialize(s)
            s.sClass(this, "Catch", "param", "block");
    }

    class DXNStmt implements IStmt {
    }

    /*
        BLOCK
    */

    type BLOCK = Block;

    class Block implements ISerializable {
        const head: HEAD?;
        const stmts : STMTS;
        function Block (head,stmts)
            : head = head
            , stmts = stmts { }

        function serialize(s) 
            s.sClass(this, "Block", "head", "stmts");
    }

    /*
        PACKAGE
    */

    type PACKAGE = Package;
    type PACKAGES = [PACKAGE];

    // FIXME: any reason these properties are var, not const?
    class Package implements ISerializable {
        var name: IDENTS;
        var block: BLOCK;
        function Package (name, block)
            : name = name
            , block = block {}

        function serialize(s)
            s.sClass(this, "Package", "name", "block");
    }

    /*
        PROGRAM
    */

    type PROGRAM = Program

    // FIXME: any reason these properties are var, not const?
    class Program implements ISerializable {
        var packages: PACKAGES;
        var block: BLOCK;
        var head: HEAD;
        var file: String?;
        var attr: FuncAttr;
        function Program (packages, block, head, attr, file=null)
            : packages = packages
            , block = block
            , head = head
            , attr = attr
            , file = file {}

        function serialize(s)
            s.sClass(this, "Program", "packages", "block", "head", "attr", "file");
    }

    class Serializer {
        public function serialize(obj) {
            if (obj is ISerializable)
                return obj.serialize(this);

            if (obj is Array) 
                return serializeArray(obj, true);

            if (obj is Number || obj is Boolean || obj is int || obj is uint || obj === null || obj === undefined)
                return String(obj);

            if (obj is String)
                return "'" + sanitize(obj) + "'";

            throw new Error("Unserializable datum " + obj);
        }

        function serializeArray(obj, linebreak) {
            let s = "[";
            let separator = linebreak ? "\n," : ",";
            let lastWasOK = true;
            for ( let i=0, limit=obj.length ; i < limit ; i++ ) {
                lastWasOK = false;
                if (i > 0)
                    s += separator;
                if (obj.hasOwnProperty(i)) {
                    lastWasOK = true;
                    s += serialize(obj[i]);
                }
            }
            if (!lastWasOK)
                s += separator;
            s += "]";
            return s;
        }

        function sanitize(s) {
            let r = "";
            let i = 0;
            let l = s.length;
        outer:
            while (i < l) {
                let start = i;
                while (i < l) {
                    let c = s.charCodeAt(i);
                    if (c < 32 || 
                        c == Char::BackSlash || 
                        c == Char::SingleQuote || 
                        c == Char::DoubleQuote ||
                        c == Char::UnicodePS ||
                        c == Char::UnicodeLS) {
                        r += s.substring(start, i);
                        s += uescape(c);
                        i++;
                        continue outer;
                    }
                    i++;
                }
                r += s.substring(start, i);
            }
            return r;
        }

        function uescape(c)
            "\\u" + (c+0x10000).toString(16).substring(1);

        public function sClass(obj, ...rest) {
            // The 'ast_layout' is reduced to the class name the day 
            // Tamarin performs enumeration/itemization in insertion 
            // order.  If size concerns us (not likely) then we can
            // compress by maintaining an indexed dictionary of
            // layout arrays, which is emitted as part of the output.

            let s = "{ 'ast_layout': " + serializeArray(rest, false);
            for ( let i=1, limit=rest.length ; i < limit ; i++ ) {
                s += "\n, '" + rest[i] + "': ";
                s += serialize(obj[rest[i]]);
            }
            s += "}";
            return s;
        }

        public function sConstant(expr)
            "{ 'ast_constant': '" + expr + "' }";
    }

    // FIXME I:
    // The unserializer uses 'eval' for three things:
    //   - to decode the JSON input (dangerous)
    //   - to create constructor functions for classes
    //   - to look up global constant properties
    //
    // The latter two could be gotten rid of by using 
    //
    //    new Ast::[tag](...desc.map(decode))
    //
    // and
    //
    //    Ast::[constName]
    //
    // respectively (if the serializer cooperates; right now the
    // constName expression is not a name so that wouldn't work), 
    // but for that we need bracket syntax and splat to work.
    //
    // FIXME II:
    // The function 'globalEval' should be removed and invocations
    // of it should be replaced simply by 'global.eval', but that
    // requires a working notion of 'global' in tamarin.

    class Unserializer {
        public function unserializeText(s) 
            decode(globalEval("(" + s + ")"));

        public function unserializeObject(obj) 
            decode(obj);

        function decode(x) {
            if (x is Boolean || x is Number || x is int || x is uint || x is String)
                return x;

            if (x is Array) {
                for ( let i=0, limit=x.length ; i < limit ; i++ )
                    if (x.hasOwnProperty(i))
                        x[i] = decode(x[i]);
                return x;
            }

            if (x.hasOwnProperty("ast_layout")) {
                let desc = x.ast_layout;
                let tag = desc[0];
                desc.shift(1);
                return (getConstructor(tag, desc.length)).apply(null, Util::map(function (n) { return decode(x[n]) }, desc));
            }

            if (x.hasOwnProperty("ast_constant"))
                return globalEval(x.ast_constant);

            let s = "{ ";
            for ( let n in x )
                if (x.hasOwnProperty(n))
                    s += "'" + n + "': " + x[n];
            s += "}";
            throw new Error("Unknown datum type: object without a tag: " + s);
        }

        // A map from name to function that constructs instance of name.
        var constructors = {};

        function getConstructor(name, arity) {
            if (!constructors.hasOwnProperty(name)) {
                // FIXME: An array comprehension would be pretty here...
                let args = [];
                for ( let i=0 ; i < arity ; i++ )
                    args.push("_p" + i);
                constructors[name] = globalEval("(function (" + args + ") { return new Ast::" + name + "(" + args + ") })");
            }
            return constructors[name];
        }

        function globalEval(s)
            ESC::evaluateInScopeArray([s], [], "");
    }
}
