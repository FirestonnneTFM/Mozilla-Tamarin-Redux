/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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
    Namespacep Multiname::getNamespace(int32_t i) const
    {
        AvmAssert(!isRtns() && !isAnyNamespace());
        if (flags&NSSET)
        {
            AvmAssert(i >= 0 && i < namespaceCount());
            return nsset ? nsset->nsAt(i) : NULL;
        }
        else
        {
            AvmAssert(i == 0);
            return ns;
        }
    }

    bool Multiname::contains(Namespacep ns) const
    {
        if (flags & NSSET)
        {
            return nsset && nsset->contains(ns);
        }
        else
        {
            return this->ns == ns;
        }
    }

    bool Multiname::matches(const Multiname* qname) const
    {
        // For attributes (XML::getprop page 12)
        //if (((n.[[Name]].localName == "*") || (n.[[Name]].localName == a.[[Name]].localName)) &&
        //  ((n.[[Name]].uri == nulll) || (n.[[Name]].uri == a.[[Name]].uri)))

        // For regular element props (XML::getprop page 12)
        //  if (n.localName = "*" OR m2 and (m2.localName == n.localName)
        //  and (!n.uri) or (m2) and (n.uri == m2.uri)))

        //Stringp n1 = core->string(this->name);

        if (qname)
        {
            //Stringp n2 = core->string(m2->name);

            if (this->isAttr() != qname->isAttr())
                return false;
        }

        // An anyName that is not qualified matches all properties
        if (this->isAnyName() && !this->isQName())
            return true;

        // Not an anyName, if m2 is valid, verify names are identical
        if (!this->isAnyName() && qname && (this->name != qname->getName()))
            return false;

        if (!qname)
            return false;

        if (this->isAnyNamespace())
            return true;

        // find a matching namespace between m2 and this
        // if no match return false
        Stringp u2 = qname->getNamespace()->getURI();
        uint8 type2 = (uint8)(qname->getNamespace()->getType());
        //Stringp s2 = core->string(u2);

        for (int i = 0; i < this->namespaceCount(); i++)
        {
            // We'd like to just compare namespace objects but we need
            // to check URIs since two namespaces with different prefixes
            // are considered a match
            Stringp u1 = getNamespace(i)->getURI();
            uint8 type1 = (uint8)(getNamespace(i)->getType());
            //Stringp s1 = core->string(u1);
            if (u1 == u2 && type1 == type2)
                return true;
        }

        return false;
    }

    PrintWriter& operator<<(PrintWriter& prw, const Multiname::Format& mnf)
    {
        if (mnf._ns->isPublic() ||
            ( // backwards compatibility
            mnf._ns->getType() != Namespace::NS_Public))
        {
            prw << mnf._name;
        }
        else 
        {
            prw << mnf._ns->getURI() << "::" << mnf._name;
        }
        return prw;
    }

    PrintWriter& operator<<(PrintWriter& prw, const Multiname::FormatNameOnly& mnf)
    {
        return mnf._mn->print(prw, Multiname::MULTI_FORMAT_NAME_ONLY);
    }
    
    // @TODO can we get rid of this ?!? 
    /*static*/ PrintWriter& Multiname::print(PrintWriter& prw, Namespacep ns, Stringp name, bool attr, bool hideNonPublicNamespaces)
    {
        if (ns->isPublic() ||
            (hideNonPublicNamespaces && // backwards compatibility
            ns->getType() != Namespace::NS_Public)) 
        {
            prw << name;
        }
        else 
        {
            (attr) ? prw << "@" << ns->getURI() << "::" << name 
                   : prw << ns->getURI() << "::" << name;
        }
        return prw;
    }

    PrintWriter& Multiname::printName(PrintWriter& prw) const
    {
        this->isAnyName() ? prw << "*"
                          : (this->isRtname() ? prw << "[]" : prw << getName());
        return prw;        
    }

    PrintWriter& Multiname::print(PrintWriter& prw, MultiFormat form) const
    {
        char attr = this->isAttr() ? '@' : '\0';
        bool isAny = this->isAnyNamespace();
        bool isRt = this->isRtns() ? true : false;
        
        if (isAny) 
        {
            prw << attr << "*::";
            return printName(prw);
        }            
        else if (isRt)
        {
            prw << attr << "[]::";
            return printName(prw);
        }
        else if (namespaceCount() == 1 && isQName())
        {
            if (!ns->isPublic())
                prw << ns->getURI() << "::";
            prw << attr;
            return printName(prw);
        }
        else
        {
            // various switches
            bool showNs = (form == MULTI_FORMAT_FULL) || (form == MULTI_FORMAT_NS_ONLY);
            bool showName = (form == MULTI_FORMAT_FULL) || (form == MULTI_FORMAT_NAME_ONLY);
            bool showBrackets = (form == MULTI_FORMAT_FULL);
            if (showNs)
            {
                if (showBrackets)
                    prw << attr << "{";

                for (int i=0,n=namespaceCount(); i < n; i++)
                {
                    if (getNamespace(i)->isPublic())
                        prw << "public";
                    else
                        prw << getNamespace(i)->getURI();
                    if (i+1 < n)
                        prw << ",";
                }

                if (showBrackets)
                    prw << "}::";
            }

            if (showName)
                printName(prw);
            return prw;
        }
    }

    // NOTE NOTE NOTE
    // Write barrier note: the container for a HeapMultiname is *not* 'this';
    // HeapMultiname figures as a field in eg QNameObject and XMLListObject.
    // You *must* call FindBeginningFast(this) to get the right container.
    //
    // NOTE NOTE NOTE
    // This version is only safe if 'this' is on the first block of the object - because
    // GC::GetGC() is not reliable otherwise.  See bugzilla 525875.  Use the more
    // reliable version below if in doubt.
    void HeapMultiname::setMultiname(const Multiname& that)
    {
        MMgc::GC* gc = this->gc();
        const void *container = gc->FindBeginningFast(this);
        setMultiname(gc, container, that);
    }

    // This is always safe.  We must /not/ use WBRC_NULL here, only the full WBRC functions that
    // take the gc and container explicitly will be safe.  See bugzilla 525875.
    void HeapMultiname::setMultiname(MMgc::GC* gc, const void* container, const Multiname& that)
    {
        WBRC(gc, container, &name.name, that.name);

        bool const this_nsset = name.isNsset() != 0;
        bool const that_nsset = that.isNsset() != 0;

        if (this_nsset != that_nsset)
        {
            // gc->rc or vice versa... we have to explicitly null out
            // any existing value (before setting a new one) because WB/WBRC
            // assume any existing value is a GCObject/RCObject respectively.
            if (this_nsset)
                WB_NULL(&name.ns);                      // WB_NULL is safe
            else
                WBRC(gc, container, &name.ns, NULL);    // DO NOT USE WBRC_NULL
        }

        if (that_nsset)
        {
            WB(gc, container, &name.nsset, that.nsset);
        }
        else
        {
            WBRC(gc, container, &name.ns, that.ns);
        }

        name.flags = that.flags;
        name.next_index = that.next_index;
    }

    // This is only safe if 'this' is on the first block of the object - because GC::GetGC() is
    // not reliable otherwise.  See bugzilla 525875.  To destroy objects beyond the first block,
    // use the safe version of setMultiname() with an empty Multiname argument.
    HeapMultiname::~HeapMultiname()
    {
        // Our embedded Multiname will zero itself, but we should call WBRC to
        // adjust the refcounts correctly...
        WBRC_NULL(&name.name);
        if (!name.isNsset())
            WBRC_NULL(&name.ns);
    }

}
