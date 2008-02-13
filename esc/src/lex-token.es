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

use namespace intrinsic;

public namespace Token

{
    use default namespace Token;

    /* A token has a "kind" (the token type) and a "text" (the lexeme).

       For predefined tokens the kind is equal to its index in the
       token store.

       NOTE, the parser in-lines tokenKind and tokenText manually, and
       knows what a Tok looks like, so don't treat Tok as an abstraction.
    */
    class Tok
    {
        var kind;
        var text;

        function Tok(kind,text)
            : kind = kind
            , text = text
        {
        }
    }

    function tokenKind (tid: int) : int
        tokenStore[tid].kind;

    function tokenText ( tid : int ) : String
        tokenStore[tid].text;

    // Map from (kind, text) to index in tokenStore.  It is used to
    // dramatically speed up duplicate testing in makeInstance(), below.

    const tokenHash = 
        new Util::Hashtable(function(x) { return Util::hash_number(x.kind) ^ Util::hash_string(x.text) },
                            function(a,b) { return a.kind === b.kind && a.text === b.text },
                            false );
    
    // Map from token number to a Tok structure.
    // FIXME: Really "Vector.<Tok>".
    //
    // Metric: Self-compiling parse.es, about 1000 unique tokens are
    // created (beyond the 157 that initially populate the token store).

    const tokenStore = new Array;

    // hash_helper is used to avoid allocation on the fast path inside
    // makeInstance.  It may not make much difference, but there you
    // have it.

    var hash_helper = { kind: 0, text: "" };

    function makeInstance(kind:int, text:String) : int {
        use namespace Util;

        hash_helper.kind = kind;
        hash_helper.text = text;
        var tid = tokenHash.read(hash_helper);
        if (tid === false) {
            tid = tokenStore.length;
            tokenStore.push(new Tok(kind, text));
            tokenHash.write({kind: kind, text: text}, tid);
        }
        return tid;
    }

    function setup(id, name) {
        tokenStore[id] = new Tok(id,name);
    }

    const Minus = 0;                                        setup(Token::Minus,"minus");
    const MinusMinus = Token::Minus + 1;                    setup(Token::MinusMinus,"minusminus");
    const Not = Token::MinusMinus + 1;                      setup(Token::Not,"not");
    const NotEqual = Token::Not + 1;                        setup(Token::NotEqual,"notequals");
    const StrictNotEqual = Token::NotEqual + 1;             setup(Token::StrictNotEqual,"strictnotequals");
    const Remainder = Token::StrictNotEqual + 1;            setup(Token::Remainder,"modulus");
    const RemainderAssign = Token::Remainder + 1;           setup(Token::RemainderAssign,"modulusassign");
    const BitwiseAnd = Token::RemainderAssign + 1;          setup(Token::BitwiseAnd,"bitwiseand");
    const LogicalAnd = Token::BitwiseAnd + 1;               setup(Token::LogicalAnd,"logicaland");
    const LogicalAndAssign = Token::LogicalAnd + 1;         setup(Token::LogicalAndAssign,"logicalandassign");
    const BitwiseAndAssign = Token::LogicalAndAssign + 1;   setup(Token::BitwiseAndAssign,"bitwiseandassign");
    const LeftParen = Token::BitwiseAndAssign + 1;          setup(Token::LeftParen,"leftparen");
    const RightParen = Token::LeftParen + 1;                setup(Token::RightParen,"rightparen");
    const Mult = Token::RightParen + 1;                     setup(Token::Mult,"mult");
    const MultAssign = Token::Mult + 1;                     setup(Token::MultAssign,"multassign");
    const Comma = Token::MultAssign  + 1;                   setup(Token::Comma,"comma");
    const Dot = Token::Comma + 1;                           setup(Token::Dot,"dot");
    const DoubleDot = Token::Dot + 1;                       setup(Token::DoubleDot,"doubledot");
    const TripleDot = Token::DoubleDot + 1;                 setup(Token::TripleDot,"tripledot");
    const LeftDotAngle = Token::TripleDot + 1;              setup(Token::LeftDotAngle,"leftdotangle");
    const Div = Token::LeftDotAngle + 1;                    setup(Token::Div,"div");
    const DivAssign = Token::Div + 1;                       setup(Token::DivAssign,"divassign");
    const Colon = Token::DivAssign + 1;                     setup(Token::Colon,"colon");
    const DoubleColon = Token::Colon + 1;                   setup(Token::DoubleColon,"doublecolon");
    const SemiColon = Token::DoubleColon + 1;               setup(Token::SemiColon,"semicolon");
    const QuestionMark = Token::SemiColon + 1;              setup(Token::QuestionMark,"questionmark");
    const At = Token::QuestionMark + 1;                     setup(Token::At,"at");
    const LeftBracket = Token::At + 1;                      setup(Token::LeftBracket,"leftbracket");
    const RightBracket = Token::LeftBracket + 1;            setup(Token::RightBracket,"rightbracket");
    const LogicalXor = Token::RightBracket + 1;             setup(Token::LogicalXor,"logicalxor");
    const LogicalXorAssign = Token::LogicalXor + 1;         setup(Token::LogicalXorAssign,"logicalxorassign");
    const LeftBrace = Token::LogicalXorAssign + 1;          setup(Token::LeftBrace,"leftbrace");
    const LogicalOr = Token::LeftBrace + 1;                 setup(Token::LogicalOr,"logicalor");
    const LogicalOrAssign = Token::LogicalOr + 1;           setup(Token::LogicalOrAssign,"logicalorassign");
    const BitwiseOr = Token::LogicalOrAssign + 1;           setup(Token::BitwiseOr,"bitwiseor");
    const BitwiseOrAssign = Token::BitwiseOr + 1;           setup(Token::BitwiseOrAssign,"bitwiseorassign");
    const BitwiseXor = Token::BitwiseOrAssign + 1;          setup(Token::BitwiseXor,"bitwisexor");
    const BitwiseXorAssign = Token::BitwiseXor + 1;         setup(Token::BitwiseXorAssign,"bitwisexorassign");
    const RightBrace = Token::BitwiseXorAssign + 1;         setup(Token::RightBrace,"rightbrace");
    const BitwiseNot = Token::RightBrace + 1;               setup(Token::BitwiseNot,"bitwisenot");
    const Plus = Token::BitwiseNot + 1;                     setup(Token::Plus,"plus");
    const PlusPlus = Token::Plus + 1;                       setup(Token::PlusPlus,"plusplus");
    const PlusAssign = Token::PlusPlus + 1;                 setup(Token::PlusAssign,"plusassign");
    const LessThan = Token::PlusAssign + 1;                 setup(Token::LessThan,"lessthan");
    const LeftShift = Token::LessThan + 1;                  setup(Token::LeftShift,"leftshift");
    const LeftShiftAssign = Token::LeftShift + 1;           setup(Token::LeftShiftAssign,"leftshiftassign");
    const LessThanOrEqual = Token::LeftShiftAssign + 1;     setup(Token::LessThanOrEqual,"lessthanorequals");
    const Assign = Token::LessThanOrEqual + 1;              setup(Token::Assign,"assign");
    const MinusAssign = Token::Assign + 1;                  setup(Token::MinusAssign,"minusassign");
    const Equal = Token::MinusAssign + 1;                   setup(Token::Equal,"equals");
    const StrictEqual = Token::Equal + 1;                   setup(Token::StrictEqual,"strictequals");
    const GreaterThan = Token::StrictEqual + 1;             setup(Token::GreaterThan,"greaterthan");
    const GreaterThanOrEqual = Token::GreaterThan + 1;      setup(Token::GreaterThanOrEqual,"greaterthanorequals");
    const RightShift = Token::GreaterThanOrEqual + 1;       setup(Token::RightShift,"rightshift");
    const RightShiftAssign = Token::RightShift + 1;         setup(Token::RightShiftAssign,"rightshiftassign");
    const UnsignedRightShift = Token::RightShiftAssign + 1; setup(Token::UnsignedRightShift,"unsignedrightshift");
    const UnsignedRightShiftAssign = Token::UnsignedRightShift + 1;   setup(Token::UnsignedRightShiftAssign,"unsignedrightshiftassign");

    /* reserved identifiers */

    const Break = Token::UnsignedRightShiftAssign + 1;      setup(Token::Break,"break");
    const Case = Token::Break + 1;                          setup(Token::Case,"case");
    const Catch = Token::Case + 1;                          setup(Token::Catch,"catch");
    const Class = Token::Catch + 1;                         setup(Token::Class,"class");
    const Continue = Token::Class + 1;                      setup(Token::Continue,"continue");
    const Default = Token::Continue + 1;                    setup(Token::Default,"default");
    const Delete = Token::Default + 1;                      setup(Token::Delete,"delete");
    const Do = Token::Delete + 1;                           setup(Token::Do,"do");
    const Else = Token::Do + 1;                             setup(Token::Else,"else");
    const Enum = Token::Else + 1;                           setup(Token::Enum,"enum");
    const Extends = Token::Enum + 1;                        setup(Token::Extends,"extends");
    const False = Token::Extends + 1;                       setup(Token::False,"false");
    const Finally = Token::False + 1;                       setup(Token::Finally,"finally");
    const For = Token::Finally + 1;                         setup(Token::For,"for");
    const Function = Token::For + 1;                        setup(Token::Function,"function");
    const If = Token::Function + 1;                         setup(Token::If,"if");
    const In = Token::If + 1;                               setup(Token::In,"in");
    const InstanceOf = Token::In + 1;                       setup(Token::InstanceOf,"instanceof");
    const New = Token::InstanceOf + 1;                      setup(Token::New,"new");
    const Null = Token::New + 1;                            setup(Token::Null,"null");
    const Return = Token::Null + 1;                         setup(Token::Return,"return");
    const Super = Token::Return + 1;                        setup(Token::Super,"super");
    const Switch = Token::Super + 1;                        setup(Token::Switch,"switch");
    const This = Token::Switch + 1;                         setup(Token::This,"this");
    const Throw = Token::This + 1;                          setup(Token::Throw,"throw");
    const True = Token::Throw + 1;                          setup(Token::True,"true");
    const Try = Token::True + 1;                            setup(Token::Try,"try");
    const TypeOf = Token::Try + 1;                          setup(Token::TypeOf,"typeof");
    const Var = Token::TypeOf + 1;                          setup(Token::Var,"var");
    const Void = Token::Var + 1;                            setup(Token::Void,"void");
    const While = Token::Void + 1;                          setup(Token::While,"while");
    const With = Token::While + 1;                          setup(Token::With,"with");

    /* contextually reserved identifiers */

    const Call = Token::With + 1;                           setup(Token::Call,"call");
    const Cast = Token::Call + 1;                           setup(Token::Cast,"cast");
    const Const = Token::Cast + 1;                          setup(Token::Const,"const");
    const Decimal = Token::Const + 1;                       setup(Token::Decimal,"decimal");
    const Double = Token::Decimal + 1;                      setup(Token::Double,"double");
    const Dynamic = Token::Double + 1;                      setup(Token::Dynamic,"dynamic");
    const Each = Token::Dynamic + 1;                        setup(Token::Each,"each");
    const Eval = Token::Each + 1;                           setup(Token::Eval,"eval");
    const Final = Token::Eval + 1;                          setup(Token::Final,"final");
    const Get = Token::Final + 1;                           setup(Token::Get,"get");
    const Has = Token::Get + 1;                             setup(Token::Has,"has");
    const Implements = Token::Has + 1;                      setup(Token::Implements,"implements");
    const Import = Token::Implements + 1;                   setup(Token::Import,"import");
    const Int = Token::Import + 1;                          setup(Token::Int,"int");
    const Interface = Token::Int + 1;                       setup(Token::Interface,"interface");
    const Internal = Token::Interface + 1;                  setup(Token::Internal,"internal");
    const Intrinsic = Token::Internal + 1;                  setup(Token::Intrinsic,"intrinsic");
    const Is = Token::Intrinsic + 1;                        setup(Token::Is,"is");
    const Let = Token::Is + 1;                              setup(Token::Let,"let");
    const Namespace = Token::Let + 1;                       setup(Token::Namespace,"namespace");
    const Native = Token::Namespace + 1;                    setup(Token::Native,"native");
    const Number = Token::Native + 1;                       setup(Token::Number,"Number");
    const Override = Token::Number + 1;                     setup(Token::Override,"override");
    const Package = Token::Override + 1;                    setup(Token::Package,"package");
    const Precision = Token::Package + 1;                   setup(Token::Precision,"precision");
    const Private = Token::Precision + 1;                   setup(Token::Private,"private");
    const Protected = Token::Private + 1;                   setup(Token::Protected,"protected");
    const Prototype = Token::Protected + 1;                 setup(Token::Prototype,"prototype");
    const Public = Token::Prototype + 1;                    setup(Token::Public,"public");
    const Rounding = Token::Public + 1;                     setup(Token::Rounding,"rounding");
    const Standard = Token::Rounding + 1;                   setup(Token::Standard,"standard");
    const Strict = Token::Standard + 1;                     setup(Token::Strict,"strict");
    const To = Token::Strict + 1;                           setup(Token::To,"to");
    const Set = Token::To + 1;                              setup(Token::Set,"set");
    const Static = Token::Set + 1;                          setup(Token::Static,"static");
    const Type = Token::Static + 1;                         setup(Token::Type,"type");
    const UInt = Token::Type + 1;                           setup(Token::UInt,"uint");
    const Undefined = Token::UInt + 1;                      setup(Token::Undefined,"undefined");
    const Unit = Token::Undefined + 1;                      setup(Token::Unit,"unit");
    const Use = Token::Unit + 1;                            setup(Token::Use,"use");
    const Xml = Token::Use + 1;                             setup(Token::Xml,"xml");
    const Yield = Token::Xml + 1;                           setup(Token::Yield,"yield");

    /* literals */

    const AttributeIdentifier = Token::Yield + 1;           setup(Token::AttributeIdentifier,"attributeidentifier");
    const BlockComment = Token::AttributeIdentifier + 1;    setup(Token::BlockComment,"blockcomment");
    const DocComment = Token::BlockComment + 1;             setup(Token::DocComment,"doccomment");
    const Eol = Token::DocComment + 1;                      setup(Token::Eol,"eol");
    const Identifier = Token::Eol + 1;                      setup(Token::Identifier,"identifier");

    // The interpretation of these 4 literal types can be done during lexing

    const ExplicitDecimalLiteral = Token::Identifier + 1;            setup(Token::ExplicitDecimalLiteral,"explicitdecimalliteral");
    const ExplicitDoubleLiteral = Token::ExplicitDecimalLiteral + 1; setup(Token::ExplicitDoubleLiteral,"explicitdoubleliteral");
    const ExplicitIntLiteral = Token::ExplicitDoubleLiteral + 1;     setup(Token::ExplicitIntLiteral,"explicitintliteral");
    const ExplicitUIntLiteral = Token::ExplicitIntLiteral + 1;       setup(Token::ExplicitUIntLiteral,"explicituintliteral");

    // The interpretation of these 3 literal types is deferred until defn phase

    const DecimalIntegerLiteral = Token::ExplicitUIntLiteral + 1;    setup(Token::DecimalIntegerLiteral,"decimalintegerliteral");
    const DecimalLiteral = Token::DecimalIntegerLiteral + 1;         setup(Token::DecimalLiteral,"decimalliteral");
    const HexIntegerLiteral = Token::DecimalLiteral + 1;             setup(Token::HexIntegerLiteral,"hexintegerliteral");

    const RegexpLiteral = Token::HexIntegerLiteral + 1;     setup(Token::RegexpLiteral,"regexpliteral");
    const SlashSlashComment = Token::RegexpLiteral + 1;     setup(Token::SlashSlashComment,"linecomment");
    const StringLiteral = Token::SlashSlashComment + 1;     setup(Token::StringLiteral,"stringliteral");
    const Space = Token::StringLiteral + 1;                 setup(Token::Space,"space");
    const XmlLiteral = Token::Space + 1;                    setup(Token::XmlLiteral,"xmlliteral");
    const XmlPart = Token::XmlLiteral + 1;                  setup(Token::XmlPart,"xmlpart");
    const XmlMarkup = Token::XmlPart + 1;                   setup(Token::XmlMarkup,"xmlmarkup");
    const XmlText = Token::XmlMarkup + 1;                   setup(Token::XmlText,"xmltext");
    const XmlTagEndEnd = Token::XmlText + 1;                setup(Token::XmlTagEndEnd,"xmltagendend");
    const XmlTagStartEnd = Token::XmlTagEndEnd + 1;         setup(Token::XmlTagStartEnd,"xmltagstartend");

    // meta

    const ERROR = Token::XmlTagStartEnd + 1;                setup(Token::ERROR,"ERROR");
    const EOS = Token::ERROR + 1;                           setup(Token::EOS,"EOS");
    const BREAK = Token::EOS + 1;                           setup(Token::BREAK,"BREAK");
    const NONE = Token::BREAK + 1;                          setup(Token::NONE,"NONE");
}

