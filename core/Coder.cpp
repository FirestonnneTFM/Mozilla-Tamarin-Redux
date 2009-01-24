/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4: */
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

#include "avmplus.h"

namespace avmplus
{
#if defined FEATURE_TEEWRITER
    TeeWriter::TeeWriter (CoderContext* ctx, CodeWriter* coder1, CodeWriter* coder2)
        : CodeWriter(ctx), coder1(coder1), coder2(coder2) 
    {
    }

    TeeWriter::~TeeWriter () 
    {
    }

    void TeeWriter::write (FrameState* state, const byte* pc, AbcOpcode opcode) {
        if(coder1) coder1->write (state, pc, opcode);
        if(coder2) coder2->write (state, pc, opcode);
    }

    void TeeWriter::writeOp1(FrameState* state, const byte *pc, AbcOpcode opcode, uint32_t opd1, Traits* type)
    {
        if(coder1) coder1->writeOp1(state, pc, opcode, opd1, type);
        if(coder2) coder2->writeOp1(state, pc, opcode, opd1, type);
    }

    void TeeWriter::writeOp2 (FrameState* state, const byte *pc, AbcOpcode opcode, uint32_t opd1, uint32_t opd2, Traits* type)
    {
        if (coder1) coder1->writeOp2 (state, pc, opcode, opd1, opd2, type);
        if (coder2) coder2->writeOp2 (state, pc, opcode, opd1, opd2, type);
    }

    void TeeWriter::writePrologue(FrameState* state)
    {
        if (coder1) coder1->writePrologue(state);
        if (coder2) coder2->writePrologue(state);
    }

    void TeeWriter::writeEpilogue(FrameState* state)
    {
        if (coder1) coder1->writeEpilogue(state);
        if (coder2) coder2->writeEpilogue(state);
    }
#endif // FEATURE_TEEWRITER

#if defined FEATURE_NULLWRITER
    NullWriter::NullWriter (CoderContext* ctx, CodeWriter* coder)
        : CodeWriter(ctx)
        , coder(coder) {
    }

    NullWriter::~NullWriter () {}

	void NullWriter::write (FrameState* state, const byte* pc, AbcOpcode opcode) 
    {
		if (coder) coder->write (state, pc, opcode);
	}

	void NullWriter::writeOp1(FrameState* state, const byte *pc, AbcOpcode opcode, uint32_t opd1, Traits *type)
	{
		if (coder) coder->writeOp1 (state, pc, opcode, opd1, type);
	}

	void NullWriter::writeOp2 (FrameState* state, const byte *pc, AbcOpcode opcode, uint32_t opd1, uint32_t opd2, Traits* type)
	{
        if (coder) coder->writeOp2 (state, pc, opcode, opd1, opd2, type);
	}

	void NullWriter::writePrologue(FrameState* state)
	{
        if (coder) coder->writePrologue(state);
	}
  
    void NullWriter::writeEpilogue(FrameState* state)
    {
        if (coder) coder->writeEpilogue(state);
    }
#endif // FEATURE_NULLWRITER

}
