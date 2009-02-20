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
package adobe.abcasm;


import java.util.*;

import java.lang.reflect.Field;

import static macromedia.asc.embedding.avmplus.ActionBlockConstants.*;

class AssemblerCore
{
	AssemblerOptions options;

	/**
	 *  Scripts defined by this translation unit.
	 */
	Vector<ScriptInfo> scripts = new Vector<ScriptInfo>();
	
	/**
	 * Functions defined by this translation unit in method ID order.
	 */
	Vector<MethodInfo> methodSignatures = new Vector<MethodInfo>();
	int methodMasterId = 0;

	Map<String,Integer> methodsByName = new HashMap<String,Integer>();

	/**
	 *  Method bodies, in entry order.
	 */
	List<MethodBodyInfo> methodBodies = new ArrayList<MethodBodyInfo>();
	
	List<String> syntaxErrors = new LinkedList<String>();
	List<String> semanticErrors = new LinkedList<String>();

	/*
	 *  ABC pools.
	 */
	Pool<Name> namePool = new Pool<Name>(1);
	Pool<String> stringPool = new Pool<String>(1);
	Pool<Integer> intPool = new Pool<Integer>(1);
	Pool<Long> uintPool = new Pool<Long>(1);
	Pool<Double> doublePool = new Pool<Double>(1);
	Pool<Namespace> nsPool = new Pool<Namespace>(1);
	Pool<Nsset> nssetPool = new Pool<Nsset>(1);

	AssemblerCore(AssemblerOptions options)
	{
		this.options = options;
	}

	void addMethodInfo(MethodInfo new_function)
	{
		if ( methodsByName.containsKey(new_function.methodName) )
		{
			throw new IllegalArgumentException (
				"Duplicate method name: " + new_function.methodName
			);
		}
		methodSignatures.add(new_function);
		new_function.methodId = methodMasterId++;

		if ( new_function.methodName != null )
		{
			createPoolId(new_function.methodName);
			methodsByName.put(new_function.methodName, new_function.methodId);
		}
	}

	void addMethodBodyInfo(MethodBodyInfo new_body)
	{
		methodBodies.add(new_body);
	}

	int createPoolId(Object value)
	{
		if ( null == value )
			return 0;
		else if ( value instanceof Integer )
		{
			Integer iKey = (Integer)value;
			return intPool.add(iKey);
		}
		else if ( value instanceof Long )
		{
			Long lKey = (Long)value;
			return uintPool.add(lKey);
		}
		else if ( value instanceof Double )
		{
			Double dKey = (Double)value;
			return doublePool.add(dKey);
		}
		else if ( value instanceof String )
		{
			String sKey = (String)value;
			return stringPool.add(sKey);
		}
		else
			throw new IllegalArgumentException("Don't have a pool for " + value.getClass().getSimpleName());
	}
	
	int getPoolId(Object value )
	{
		if ( null == value )
			return 0;
		else if ( value instanceof Integer )
		{
			Integer iKey = (Integer)value;
			return intPool.id(iKey);
		}
		else if ( value instanceof Long )
		{
			Long lKey = (Long)value;
			return uintPool.id(lKey);
		}
		else if ( value instanceof Double )
		{
			Double dKey = (Double)value;
			return doublePool.id(dKey);
		}
		else if ( value instanceof String )
		{
			String sKey = (String)value;
			return stringPool.id(sKey);
		}
		else
			throw new IllegalArgumentException("Don't have a pool for " + value.getClass().getSimpleName());
	}

	void semanticAssertion(boolean cond, String diagnostic )
	{
		if (!cond)
			semanticErrors.add(diagnostic);
	}

	void syntaxError(String diagnostic)
	{
		syntaxErrors.add(diagnostic);
	}
	
	void dump(java.io.PrintStream out)
	{
		for ( String fname: methodsByName.keySet() )
			/* FIXME: not working right now... functionsByName.get(fname).dump(out) */;
	}

	Name getName(String unqualifiedName)
	{
		//  Ensure the package namespace is present.
		getNamespace("package");
		Name result = new Name(unqualifiedName);
		
		if ( !"*".equals(unqualifiedName))
		{
			namePool.add(result);
			stringPool.add(unqualifiedName);
		}

		return result;
	}
	
	Name getName(Nsset qualifiers, String baseName)
	{
		Name result = new Name(qualifiers, baseName);
		
		namePool.add(result);
		stringPool.add(baseName);
		return result;
	}
	
	Namespace getNamespace(String nsName)
	{
		Namespace result;
		String nsPoolName;

		if ( "Package".equalsIgnoreCase(nsName))
		{
			nsPoolName = "";
			result = new Namespace(CONSTANT_PackageNamespace, "");
		}
		else if ( "Private".equalsIgnoreCase(nsName))
		{
			nsPoolName = "";
			result = new Namespace(CONSTANT_PrivateNamespace, "");
		}
		else
		{
			nsPoolName = nsName;
			result = new Namespace(CONSTANT_Namespace, nsName);
		}
		
		stringPool.add(nsPoolName);
		nsPool.add(result);
		return result;
	}
	
	Nsset getNsset(Vector<Namespace> namespaces)
	{
		Nsset result = new Nsset(namespaces);
		this.nssetPool.add(result);
		return result;
	}
	
	/**
	 *  Supports a convenience in the syntax:
	 *  if a multiname doesn't have qualfiers,
	 *  then hack together a Nsset with the
	 *  commonly-searched namespaces.
	 * 	@return
	 */
	Nsset getUsualSuspectNamespaces()
	{
		Vector<Namespace> namespaces = new Vector<Namespace>();
		namespaces.add(getNamespace("package"));
		namespaces.add(getNamespace("private"));
		
		return getNsset(namespaces);
	}
	Label getLabel(String labelName)
	{
		return new Label(labelName);
	}
	
	void addScript(ScriptInfo s)
	{
		scripts.add(s);
	}
	
	void semanticAnalysis()
	{
		//  Add a default script if none was specified.
		if ( scripts.isEmpty() )
		{
			scripts.add(new ScriptInfo());
		}
		else
		{
			for ( ScriptInfo s: scripts )
			{
				s.init_id  = translateFunctionId(s.init_id);
			}
		}
	}
	
	Integer translateFunctionId(Object func_name)
	{
		if ( func_name instanceof Integer )
		{
			//  ID was specified.
			return (Integer) func_name;
		}
		//  FIXME: Should be functionID special form
		//  to also support .slot_id(foo)
		else if ( func_name instanceof String )
		{
			//  ID should be in the table.
			if ( methodsByName.containsKey(func_name.toString()))
				return methodsByName.get(func_name.toString());
		}

		//  No match.
		throw new IllegalArgumentException("Unknown function_id " + func_name.toString());
	}
	
	int getNameId(Name n)
	{
		if ( null == n  || n.baseName.equals("*"))
			return 0;
		else
			return namePool.id(n);
	}
}
