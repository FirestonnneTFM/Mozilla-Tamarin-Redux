/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;


class Instruction
{
    /**
     * @see AbcConstants
     */
    int opcode;
    
    /**
     *  Immediate operands as specified by the program,
     *  symbolic references may still be present.
     */
    Object[] operands;

    /**
     *  Cooked immediate operands, symbolic references resolved.
     */
    int [] imm;
    
    /**
     *  Name reference for instructions that operate on a named entity.
     */
    Name n;
    
    /**
     *  Control-flow target for branch/jump instructions.
     */
    Label target;
    
    Instruction(int opcode, Object[] operands)
    {
        this.opcode = opcode;
        this.operands = operands;
    }
    
    Instruction(int opcode, Object v)
    {
        this(opcode, new Object[]{v});
    }
    
    public String toString()
    {
        StringBuffer result = new StringBuffer(MethodBodyInfo.decodeOp(opcode));
        
        if ( n != null )
        {
            result.append(" ");
            result.append(n);
        }
        
        if ( target != null )
        {
            result.append(" ");
            result.append(target);
        }
        
        for ( Object x: operands)
        {
            result.append(" ");
            result.append(x);
        }
        
        return result.toString();
    }
}

