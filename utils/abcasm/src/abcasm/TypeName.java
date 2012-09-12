/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

import static abcasm.AbcConstants.*;

class TypeName extends Name
{
    Name n1, n2;

    TypeName(Name n1, Name n2) {
        super("", null);
        kind = CONSTANT_TypeName;
        this.n1 = n1;
        this.n2 = n2;
    }

    public String toString() {
        return "#" + n1 + ".<" + n2 + ">";
    }

    public int compareTo(Object o) {
        if (!(o instanceof TypeName))
            return -1;
        TypeName other = (TypeName)o;
        int r = n1.compareTo(other.n1);
        if (r != 0)
            return r;
        else
            return n2.compareTo(other.n2);
    }
}

