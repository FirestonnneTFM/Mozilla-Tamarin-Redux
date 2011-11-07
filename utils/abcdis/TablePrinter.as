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
 * Portions created by the Initial Developer are Copyright (C) 2004-2011
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
package
{
    import IPrinter;
    import flash.utils.ByteArray;
    
    public class TablePrinter
    {
        public function TablePrinter(nCols : uint, minPadding : uint)
        {
            m_nCols = nCols;
            m_minPadding = minPadding;
            m_rows = new Vector.<IRow>();
        }
        
        public function addRow(r : Array) : void
        {
            if (r.length != m_nCols)
                throw new Error("Invalid row");
            m_rows.push(new Row(r));
        }
        
        public function addSpannedRow() : IPrinter
        {
            var r : SpannedRow = new SpannedRow();
            m_rows.push(r);
            return r;
        }
                
        public function toString() : String
        {
            var bytes : ByteArray = new ByteArray();
            var printer : IPrinter = new ByteArrayPrinter(bytes);
            print(printer)
            bytes.position = 0
            return bytes.readUTFBytes(bytes.length)
        }
        
        public function print(p : IPrinter) : void
        {
            var colWidths : Array = new Array(m_nCols);
            var i : uint;
            var r : IRow;
            for ( i = 0; i < m_nCols; ++i)
                colWidths[i] = 0;
            
            for each ( r in m_rows )
                r.measure(colWidths, m_minPadding)
            
            for each ( r in m_rows )
                r.print(p, colWidths)
        }
        
        private var m_nCols : uint;
        private var m_minPadding : uint;
        private var m_rows : Vector.<IRow>;
    }
}

import IPrinter

interface IRow
{
    function measure(colWidths : Array, minPadding : uint) : void;
    function print(p:IPrinter, colWidths : Array) : void;
}

class Row implements IRow
{
    public function Row(cells : Array)
    {
        this.cells = cells;
    }
    
    private var cells : Array;
    
    public function measure(colWidths : Array, minPadding : uint) : void
    {
        for (var i : uint = 0; i < cells.length; ++i )
            colWidths[i] = Math.max(colWidths[i], getRowItemStr(i).length + minPadding);
    }
    
    public function print(p : IPrinter, colWidths : Array) : void
    {
        var rowStr : String = "";
        for (var i : uint = 0; i < cells.length; ++i )
            rowStr += padString(getRowItemStr(i), colWidths[i]);
        p.println(rowStr)
    }
    
    private function getRowItemStr(i : uint) : String
    {
        if (cells[i] === null)
            return "null"
        try
        {
            return cells[i].toString();
        }
        catch (e : *)
        {
            trace(cells[0].toString());
            trace(i);
            trace(cells[i]);
            throw e;
        }
        return null;
    }
    
    private static function padString(s : String, minLength : uint) : String
    {
        while (s.length < minLength)
            s += " ";
        return s;
    }
}

class SpannedRow implements IRow, IPrinter
{
    public function SpannedRow()
    {
        lines = new Vector.<String>();
    }
    
    private var lines : Vector.<String>;
    
    public function measure(colWidths : Array, minPadding : uint) : void
    {
    }
    
    public function print(p : IPrinter, colWidths : Array) : void
    {
        for each ( var s : String in lines)
        {
            p.println(s)
        }
    }
    
    public function println(s : String) : void
    {
        lines.push(s)
    }
}