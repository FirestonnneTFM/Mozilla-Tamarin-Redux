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

#ifndef __avmplus_XMLClass__
#define __avmplus_XMLClass__


namespace avmplus
{
    /**
     * class XMLClass
     */
    class XMLClass : public ClassClosure
    {
    public:
        XMLClass(VTable* cvtable);
        ~XMLClass();

        // this = argv[0]
        // arg1 = argv[1]
        // argN = argv[argc]
        Atom call(int argc, Atom* argv);

        // this = argv[0] (ignored)
        // arg1 = argv[1]
        // argN = argv[argc]
        Atom construct(int argc, Atom* argv);

        Atom ToXML(Atom arg);

        enum flags
        {
            kFlagIgnoreComments = 0x01,
            kFlagIgnoreProcessingInstructions = 0x02,
            kFlagIgnoreWhitespace = 0x04,
            kFlagPrettyPrinting = 0x08
        };

        // static props/funcs off the XML object
        // XML.ignoreComments
        // XML.ignoreProcessingInstructions
        // XML.ignoreWhitespace
        // XML.prettyPrinting
        // XML.prettyIndent
        // XML.settings (in AS)
        // XML.setSettings ([settings]) (in AS)
        // XML.defaultSettings() (in AS)

        void set_ignoreComments(uint32_t ignoreFlag);
        uint32_t get_ignoreComments();

        void set_ignoreProcessingInstructions(uint32_t ignoreFlag);
        uint32_t get_ignoreProcessingInstructions();

        void set_ignoreWhitespace(uint32_t ignoreFlag);
        uint32_t get_ignoreWhitespace();

        void set_prettyPrinting(uint32_t prettyPrinting);
        uint32_t get_prettyPrinting();

        void set_prettyIndent(int indent);
        int get_prettyIndent();

        bool okToPrettyPrint() { return (get_prettyPrinting() && (m_prettyIndent >= 0)); }

    // ------------------------ DATA SECTION BEGIN
    public:
        int m_prettyIndent;
        uint8_t m_flags;
        
    private:
        DECLARE_SLOTS_XMLClass;
    // ------------------------ DATA SECTION END
    };

    /**
     * class QName
     */
    class QNameClass : public ClassClosure
    {
    public:
        QNameClass(VTable* cvtable);

        // this = argv[0]
        // arg1 = argv[1]
        // argN = argv[argc]
        Atom call(int argc, Atom* argv);

        // this = argv[0] (ignored)
        // arg1 = argv[1]
        // argN = argv[argc]
        Atom construct(int argc, Atom* argv);

    // ------------------------ DATA SECTION BEGIN
    private:
        DECLARE_SLOTS_QNameClass;
    // ------------------------ DATA SECTION END
    };
}

#endif /* __avmplus_XMLClass__ */
