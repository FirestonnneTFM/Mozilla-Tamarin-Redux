/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

import java.util.Vector;

class MethodInfo
{
    byte flags;

    /**
     * Denormalized method id, carried here
     * so the syntax-directed translator can access it.
     */
    int methodId;

    String methodName;

    Name returnType;
    Vector<Name> paramTypes = new Vector<Name>();
    public int getParamCount()
    {
        return paramTypes.size() + 1;
    }
}
