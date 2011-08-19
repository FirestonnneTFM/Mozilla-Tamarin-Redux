/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2009
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *	 Adobe AS3 Team
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
package abcasm;

import static abcasm.AbcConstants.*;


class Name implements java.lang.Comparable
{
	int kind;
	String baseName;   // May be "" but is never null
	Nsset qualifiers;  // May be null

	// Always a QName, even if 'qualifiers' is represented as a set
	Name(String unqualifiedName)
	{
		baseName = unqualifiedName;
		kind = CONSTANT_Qname;
		qualifiers = new Nsset( new Namespace(CONSTANT_PackageNs));
	}

	// Always a QName, even if 'qualifiers' is represented as a set
	Name(String ns, String unqualifiedName)
	{
		baseName = unqualifiedName;
		kind = CONSTANT_Qname;
		qualifiers = new Nsset( new Namespace(CONSTANT_Namespace, ns));
	}
	
	// All other cases, pass null for missing parts
	Name(Nsset multiname_qualifiers, String _baseName)
	{
		baseName = (_baseName == null) ? "" : _baseName;
		qualifiers = multiname_qualifiers == null ? new Nsset() : multiname_qualifiers;
		if (multiname_qualifiers == null)
		{
			if (_baseName == null)
				kind = CONSTANT_RTQnameL;
			else
				kind = CONSTANT_RTQname;
		}
		else
		{
			if (_baseName == null)
				kind = CONSTANT_MultinameL;
			else
				kind = CONSTANT_Multiname;
		}
	}

	public String toString()
	{
		StringBuffer result = new StringBuffer();

		if ( qualifiers != null )
		{
			result.append(qualifiers.toString());
		}
		result.append("::");
		result.append(baseName);

		return result.toString();
	}

	public int compareTo(Object o)
	{

		if ( !(o instanceof Name ))
		{
			return -1;
		}

		int result = 0;

		Name other = (Name)o;

		if ( this.qualifiers != null )
		{
			if ( other.qualifiers != null )
			{
				result =  this.qualifiers.compareTo(other.qualifiers);
			}
			else
			{
				result = 1;
			}
		}
		else if ( other.qualifiers != null )
		{
			result = -1;
		}

		if ( 0 == result )
			result = baseName.compareTo(other.baseName);

		return result;
	}

	Namespace getSingleQualifier()
	{
		assert(this.qualifiers.namespaces.size() == 1);
		return this.qualifiers.namespaces.elementAt(0);
	}
}

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

