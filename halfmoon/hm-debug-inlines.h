/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

// Debug assistance code.

#ifndef HM_DEBUG_INLINES_H_
#define HM_DEBUG_INLINES_H_

namespace halfmoon {

/**
 *
 * @param instr
 * @return return true if instr is listed amongst those instructions which
 * should be translated as calls to stub routines rather than generated code
 */
inline bool debugStub( Instr *instr) {
  return stub_out[kind(instr)];
}

} //namespace halfmoon

#endif /* HM_DEBUG_INLINES_H_ */
