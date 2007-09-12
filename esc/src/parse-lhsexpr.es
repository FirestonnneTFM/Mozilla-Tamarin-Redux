/* -*- mode: java; mode: font-lock; tab-width: 4; insert-tabs-mode: nil; indent-tabs-mode: nil -*- */
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

    {
        function parenExpression (ts: TOKENS)
            : [TOKENS, Ast::EXPR]
        {
            enter("Parser::parenExpression ", ts);

            var ts1 = eat (ts,Token::LeftParen);
            var [ts2,ndx] = assignmentExpression (ts1, allowIn);
            var tsx = eat (ts2,Token::RightParen);

            exit ("Parser::parenExpression ", tsx);
            return [tsx, ndx];
        }

        function parenListExpression (ts: TOKENS)
            : [TOKENS, [Ast::EXPR]]
        {
            enter("Parser::parenListExpression ", ts);

            var ts1 = eat (ts,Token::LeftParen);
            var [ts2,ndx] = listExpression (ts1, allowIn);
            var tsx = eat (ts2,Token::RightParen);

            exit ("Parser::parenListExpression ", tsx);
            return [tsx, ndx];
        }

        /*

        ObjectLiteral(noColon)
            {  FieldList  }

        ObjectLiteral(allowColon)
            {  FieldList  }
            {  FieldList  }  :  TypeExpression

        */

        function objectLiteral (ts: TOKENS /*, alpha: ALPHA*/)
            : [TOKENS, Ast::TYPE_EXPR]
        {
            enter("Parser::objectLiteral ", ts);

            var alpha: ALPHA = allowColon;    // FIXME need to get this from caller
            ts = eat (ts,Token::LeftBrace);
            var [ts1,nd1] = fieldList (ts);
            ts1 = eat (ts1,Token::RightBrace);
            switch (alpha) {
            case allowColon:
                switch (hd (ts1)) {
                case Token::Colon:
                    var [ts2,nd2] = typeExpression (tl (ts1));
                    break;
                default:
                    var [ts2,nd2] = [ts1,new Ast::ObjectType ([])]; // FIXME I mean {*}
                    break;
                }
                break;
            default:
                var [ts2,nd2] = [ts1,new Ast::ObjectType ([])]; // FIXME I mean {*}
                break;
            }

            exit("Parser::objectLiteral ", ts2);
            return [ts2,new Ast::LiteralExpr (new Ast::LiteralObject (nd1,nd2))];
        }

        /*

        FieldList
            empty
            LiteralField
            LiteralField  ,  LiteralFieldList

        */

        function fieldList (ts: TOKENS)
            //            : [TOKENS, [Ast::FIELD_TYPE]]
        {
            enter("Parser::fieldList ", ts);

            var nd1 = [];
            var ts1 = ts;

            if (hd (ts) !== Token::RightBrace) 
            {
                var [ts1,ndx] = literalField (ts);
                nd1.push (ndx);
                while (hd (ts1) === Token::Comma) {
                    var [ts1,ndx] = literalField (tl (ts1));
                    nd1.push (ndx);
                }
            }

            exit ("Parser::fieldList ", ts1);
            return [ts1,nd1];
        }

        /*

          LiteralField
              FieldKind  FieldName  :  AssignmentExpressionallowColon, allowIn
              get  FieldName  FunctionSignature  FunctionExpressionBodyallowColon, allowIn
              set  FieldName  FunctionSignature  FunctionExpressionBodyallowColon, allowIn

        */

        function literalField (ts: TOKENS)
            : [TOKENS, Ast::FIELD_TYPE]
        {
            enter ("Parser::literalField");

            switch (hd (ts)) {
            case Token::Const:
                var [ts1,nd1] = [tl (ts), constTag];
                break;
            default:
                var [ts1,nd1] = [ts,Ast::varTag];
                break;
            }

            var [ts2,nd2] = fieldName (ts);
            ts2 = eat (ts2,Token::Colon);

            switch (hd (ts2)) {
            case Token::LeftBrace:   // short cut to avoid recursion
                var [ts3,nd3] = objectLiteral (ts2);
                break;
            case Token::LeftBracket:
                var [ts3,nd3] = arrayLiteral (ts2);
                break;
            default:
                var [ts3,nd3] = assignmentExpression (ts2,allowIn);
                break;
            }

            exit ("Parser::literalField", ts3);
            return [ts3, new Ast::LiteralField (nd1,nd2,nd3)];
        }

        /*

        FieldName
            NonAttributeQualifiedName
            StringLiteral
            NumberLiteral
            ReservedIdentifier

        */

        function fieldName (ts: TOKENS)
            : [TOKENS, Ast::IDENT_EXPR]
        {
            enter ("Parser::fieldName");

            switch (hd (ts)) {
            case Token::StringLiteral:
                var [ts1,nd1] = [tl (ts), new Ast::Identifier (Token::tokenText (ts.head()),cx.pragmas.openNamespaces)];
                break;
            case Token::DecimalLiteral:
            case Token::DecimalIntegerLiteral:
            case Token::HexIntegerLiteral:
                throw "unsupported fieldName " + hd(ts);
                break;
            default:
                if (isReserved (hd (ts))) {
                    var [ts1,nd1] = [tl (ts), new Ast::Identifier (Token::tokenText (ts.head()),cx.pragmas.openNamespaces)];
                                     // NOTE we use openNamespaces here to indicate that the name is 
                                     //      unqualified. the generator should use the expando namespace,
                                     //      which is probably Public "".
                }
                else {
                    var [ts1,nd1] = nonAttributeQualifiedName (ts);
                }
                break;
            }

            exit ("Parser::fieldName");
            return [ts1,nd1];
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

        function arrayLiteral (ts: TOKENS)
            : [TOKENS, Ast::EXPR]
        {
            enter("Parser::arrayLiteral ", ts);

            ts = eat (ts,Token::LeftBracket);
            var [ts1,nd1] = elementList (ts);
            ts1 = eat (ts1,Token::RightBracket);

            exit ("Parser::arrayLiteral ", ts1);
            return [ts1, new Ast::LiteralExpr (new Ast::LiteralArray (nd1,new Ast::ArrayType ([])))];
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

        function elementList (ts: TOKENS)
            : [TOKENS, Ast::EXPR]
        {
            enter("Parser::elementList ", ts);

            var nd1 = [];
            var ts1 = ts;

            if (hd (ts) !== Token::RightBracket) 
            {
                switch (hd (ts)) {
                case Token::Comma:
                    var [ts1,ndx] = [tl (ts),new Ast::LiteralExpr (new Ast::LiteralUndefined)];
                    break;
                default:
                    switch (hd (ts1)) {
                    case Token::LeftBrace:
                        var [ts1,ndx] = objectLiteral (ts1);
                        break;
                    case Token::LeftBracket:
                        var [ts1,ndx] = arrayLiteral (ts1);
                        break;
                    default:
                        var [ts1,ndx] = assignmentExpression (ts1,allowIn);
                        break;
                    }
                    break;
                }
                nd1.push (ndx);
                while (hd (ts1) === Token::Comma) {
                    ts1 = eat (ts1,Token::Comma);
                    switch (hd (ts1)) {
                    case Token::Comma:
                        var [ts1,ndx] = [ts1,new Ast::LiteralExpr (new Ast::LiteralUndefined)];
                        break;
                    case Token::RightBracket:
                        continue;  // we're done
                    default:
                        switch (hd (ts1)) {
                        case Token::LeftBrace:
                            var [ts1,ndx] = objectLiteral (ts1);
                            break;
                        case Token::LeftBracket:
                            var [ts1,ndx] = arrayLiteral (ts1);
                            break;
                        default:
                            var [ts1,ndx] = assignmentExpression (ts1,allowIn);
                            break;
                        }
                        break;
                    }
                    nd1.push (ndx);
                }
            }

            exit ("Parser::elementList ", ts1);
            return [ts1, nd1];
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

        function primaryExpression(ts:TOKENS,beta:BETA)
            : [TOKENS,Ast::EXPR]
        {
            enter("Parser::primaryExpression ",ts);

            switch (hd (ts)) {
            case Token::Null:
                var [ts1,nd1] = [tl (ts), new Ast::LiteralExpr (new Ast::LiteralNull ())];
                break;
            case Token::True:
                var [ts1,nd1] = [tl (ts), new Ast::LiteralExpr (new Ast::LiteralBoolean (true))];
                break;
            case Token::False:
                var [ts1,nd1] = [tl (ts), new Ast::LiteralExpr (new Ast::LiteralBoolean (false))];
                break;
            case Token::DecimalLiteral:
                var [ts1,nd1] = [tl (ts), new Ast::LiteralExpr (new Ast::LiteralDecimal (Token::tokenText (ts.head())))];
                break;
            case Token::StringLiteral:
                var [ts1,nd1] = [tl (ts), new Ast::LiteralExpr (new Ast::LiteralString (Token::tokenText (ts.head())))];
                break;
            case Token::This:
                var [ts1,nd1] = [tl (ts), new Ast::ThisExpr ()];
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
                var [ts1,nd1] = parenListExpression(ts);
                break;
            case Token::LeftBracket:
                var [ts1,nd1] = arrayLiteral (ts);
                break;
            case Token::LeftBrace:
                var [ts1,nd1] = objectLiteral (ts);
                break;
            default:
                var [ts1,nd1] = primaryName (ts);
                switch type (nd1) {
                case (nd: Ast::UnresolvedPath) {
                    base = resolvePath (nd.Ast::path,null);
                    nd1 = new Ast::ObjectRef (base,nd.Ast::ident);  // FIXME: not good for package qualified refs
                }
                case (nd:*) {
                    nd1 = new Ast::LexicalRef (nd1);
                }
                }
                break;
            }

            exit("Parser::primaryExpression ",ts1);
            return [ts1,nd1];
        }

        function resolvePath (path/*: [Ast::IDENT]*/, expr: Ast::EXPR)
        {
            return resolveObjectPath (path,expr);
        }

        function resolveObjectPath (path /*: [Ast::IDENT]*/, expr: Ast::EXPR)
            : Ast::EXPR
        {
            if (path.length === 0) {
                return expr;
            }
            else
            if (expr === null) 
            {
                var base = new Ast::LexicalRef (new Ast::Identifier (path[0],cx.pragmas.openNamespaces));
                return resolveObjectPath (path.slice (1,path.length), base);
            }
            else 
            {
                var base = new Ast::ObjectRef (expr, new Ast::Identifier (path[0],cx.pragmas.openNamespaces));
                return resolveObjectPath (path.slice (1,path.length), base);
            }
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

        function propertyOperator (ts: TOKENS, nd: Ast::EXPR)
            : [TOKENS, [Ast::EXPR]]
        {
            enter("Parser::propertyOperator ", ts);

            switch (hd (ts)) {
            case Token::Dot:
                switch (hd (tl (ts))) {
                case Token::LeftParen:
                    throw "filter operator not implemented";
                    break;
                default:
                    //                    if (isReservedIdentifier (hd (ts))) {
                    //                    }
                    let [ts1,nd1] = propertyName (tl (ts));
                    var [tsx,ndx] = [ts1, new Ast::ObjectRef (nd,nd1)];
                    break;
                }
                break;
            case Token::LeftBracket:
                let [ts1,nd1] = listExpression (tl (ts), allowIn);
                ts1 = eat (ts1,Token::RightBracket);
                var [tsx,ndx] = [ts1, new Ast::ObjectRef (nd,new Ast::ExpressionIdentifier (nd1,cx.pragmas.openNamespaces))];
                break;
            case Token::DoubleDot:
                throw "descendents operator not implemented";
                break;
            default:
                throw "internal error: propertyOperator";
                break;
            }

            exit ("Parser::propertyOperator ", tsx);
            return [tsx, ndx];
        }

        /*

        Arguments
            (  )
            (  ArgumentList  )

        ArgumentList
            AssignmentExpression(allowIn)
            ArgumentList  ,  AssignmentExpression(allowIn)

        */

        function arguments (ts: TOKENS)
            : [TOKENS, * /*[Ast::EXPR]*/]
        {
            enter("Parser::arguments ", ts);

            var ts1 = eat (ts,Token::LeftParen);
            switch (hd (ts1)) {
            case Token::RightParen:
                var tsx = eat (ts1,Token::RightParen);
                var ndx = [];
                break;
            default:
                let [ts2,nd2] = listExpression (ts1, allowIn);
                var tsx = eat (ts2,Token::RightParen);
                var ndx = nd2.Ast::exprs;
                break;
            }
            exit ("Parser::arguments ", tsx);
            return [tsx, ndx];
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

        function memberExpression (ts: TOKENS, beta:BETA)
            : [TOKENS, Ast::EXPR]
        {
            enter("Parser::memberExpression ", ts);

            switch (hd (ts)) {
            case Token::New:
                let [ts1,nd1] = memberExpression (tl (ts), beta);
                let [ts2,nd2] = this.arguments (ts1);
                var [tsx,ndx] = memberExpressionPrime (ts2, beta, new Ast::NewExpr (nd1,nd2));
                break;
            case Token::Super:
                let [ts1,nd1] = superExpression (ts);
                let [ts2,nd2] = propertyOperator (ts1,nd1);
                var [tsx,ndx] = memberExpressionPrime (ts2, beta, nd2);
            default:
                let [ts1,nd1] = primaryExpression (ts,beta);
                var [tsx,ndx] = memberExpressionPrime (ts1, beta, nd1);
                break;
            }

            exit ("Parser::memberExpression ", tsx);
            return [tsx, ndx];
        }

        function memberExpressionPrime (ts: TOKENS, beta:BETA, nd: Ast::EXPR)
            : [TOKENS, Ast::EXPR]
        {
            enter("Parser::memberExpressionPrime ", ts);

            switch (hd (ts)) {
            case Token::LeftBracket:
            case Token::Dot:
            case Token::DoubleDot:
                let [ts1,nd1] = propertyOperator (ts,nd);
                var [tsx,ndx] = memberExpressionPrime (ts1, beta, nd1);
                break;
            default:
                var [tsx,ndx] = [ts,nd]
                break;
            }

            exit ("Parser::memberExpressionPrime ", tsx);
            return [tsx, ndx];
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

        function callExpression (ts: TOKENS, beta:BETA)
            : [TOKENS, Ast::EXPR]
        {
            enter("Parser::callExpression ", ts);

            var [ts1,nd1] = memberExpression (ts,beta);
            var [ts2,nd2] = this.arguments (ts);
            var [tsx,ndx] = callExpressionPrime (ts2, beta, new Ast::CallExpr (nd1,nd2));

            exit ("Parser::callExpressionPrime ", ndx);
            return [tsx, ndx];
        }

        function callExpressionPrime (ts: TOKENS, beta:BETA, nd: Ast::EXPR)
            : [TOKENS, Ast::EXPR]
        {
            enter("Parser::callExpressionPrime ", ts);

            switch (hd (ts)) {
            case Token::LeftParen:
                let [ts1,nd1] = this.arguments (ts);
                var [tsx,ndx] = callExpressionPrime (ts1, beta, new Ast::CallExpr (nd,nd1));
                break;
            case Token::LeftBracket:
            case Token::Dot:
            case Token::DoubleDot:
                let [ts1,nd1] = propertyOperator (ts,nd);
                var [tsx,ndx] = callExpressionPrime (ts1, beta, nd1);
                break;
            default:
                var [tsx,ndx] = [ts,nd]
                break;
            }

            exit ("Parser::callExpressionPrime ", ndx);
            return [tsx, ndx];
        }

        /*

        NewExpression
            MemberExpression
            new  NewExpression

        */

        function newExpression (ts: TOKENS, beta:BETA, new_count=0)
            : [TOKENS, Ast::EXPR]
        {
            enter("Parser::newExpression ", ts);

            switch (hd (ts)) {
            case Token::New:
                let [ts1,nd1] = newExpression (tl (ts), beta, new_count+1);
                switch (hd (ts1)) {
                case Token::LeftParen:  // no more new exprs so this paren must start a call expr
                    let [ts2,nd2] = this.arguments (ts1); // refer to parser method
                    if (new_count == 0)
                    {
                        var [tsx,ndx] = callExpressionPrime (ts2,beta,new Ast::CallExpr (nd1,nd2));
                    }
                    else
                    {
                        var [tsx,ndx] = [ts2,new Ast::NewExpr (nd1,nd2)];
                    }
                    break;
                default:
                    if (new_count == 0)
                    {
                        var [tsx,ndx] = memberExpressionPrime (ts1,beta,nd1);
                    }
                    else
                    {
                        var [tsx,ndx] = [ts1,new Ast::NewExpr (nd1,[])];
                    }
                    break;
                }
                break;
            default:
                let [ts1,nd1] = memberExpression (ts,beta);
                switch (hd (ts1)) {
                case Token::LeftParen:
                    let [ts2,nd2] = this.arguments (ts1); // refer to parser method
                    if( new_count == 0 )
                    {
                       var [tsx,ndx] = callExpressionPrime (ts2,beta,new Ast::CallExpr (nd1,nd2));
                    }
                    else
                    {
                        var [tsx,ndx] = [ts2,new Ast::NewExpr (nd1,nd2)];
                    }
                    break;
                default:
                    if( new_count == 0 ) 
                    {
                        var [tsx,ndx] = [ts1,nd1];
                    }
                    else 
                    {
                        var [tsx,ndx] = [ts1,new Ast::NewExpr (nd1,[])];
                    }
                    break;
                }
                break;
            }

            exit ("Parser::newExpression ", ndx);
            return [tsx, ndx];
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

        function leftHandSideExpression (ts: TOKENS, beta:BETA)
            : [TOKENS, Ast::EXPR]
        {
            enter("Parser::leftHandSideExpression ", ts);

            switch (hd (ts)) {
            case Token::New:
                var [ts1,nd1] = newExpression (ts,beta,0);
                switch (hd (ts1)) {
                case Token::LeftParen:
                    let [ts2,nd2] = this.arguments (ts1); // refer to parser method
                    var [tsx,ndx] = callExpressionPrime (ts2, beta, new Ast::CallExpr (nd1,nd2));
                    break;
                default:
                    var [tsx,ndx] = [ts1,nd1];
                    break;
                }
                break;
            default:
                let [ts1,nd1] = memberExpression (ts,beta);
                switch (hd (ts1)) {
                case Token::LeftParen:
                    let [ts2,nd2] = this.arguments (ts1); // refer to parser method
                    var [tsx,ndx] = callExpressionPrime (ts2, beta, new Ast::CallExpr (nd1,nd2));
                    break;
                default:
                    var [tsx,ndx] = [ts1,nd1];
                    break;
                }
                break;
            }

            exit ("Parser::leftHandSideExpression ", ndx);
            return [tsx, ndx];
        }
    }
}
