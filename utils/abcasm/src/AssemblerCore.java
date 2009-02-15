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
	 * Functions defined by this translation unit in entry order.
	 */
	List<Function> functionsByNumber = new ArrayList<Function>();
	
	Map<String,Function> functionsByName = new HashMap<String, Function>();
	Function currentFunction = null;
	
	List<String> syntaxErrors = new LinkedList<String>();

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
	
	/*
	 * Opcode mappings extracted from ActionBlockConstants
	 */
	static Map<String, Integer> opcodeNameToOpcode = new HashMap<String, Integer>();
	static Map<Integer, String> opcodeToOpcodeName = new HashMap<Integer, String>();

	AssemblerCore(AssemblerOptions options)
	{
		this.options = options;
	}

	//  FIXME: Should be a Name
	void newFunction(String name)
	{
		semanticAssertion(
			null == functionsByName.get(name),
			"Duplicate function : " + name
			);

		currentFunction = new Function(name);
		functionsByName.put(name, currentFunction);
		functionsByNumber.add(currentFunction);
	}

	void startBlock(Label blockLabel)
	{
		currentFunction.startBlock(blockLabel);
	}
	
	void startBlock()
	{
		currentFunction.startBlock();
	}
	
	void insn(org.antlr.runtime.Token opcode_token)
	{
		insn( decodeOpcodeName(opcode_token.getText()));
	}
	
	void insn(org.antlr.runtime.Token opcode_token, Label label)
	{
		insn( decodeOpcodeName(opcode_token.getText()), label);
	}

	void insn(int opcode, Label label)
	{
		currentFunction.insn(opcode, label);
	}

	void insn(org.antlr.runtime.Token opcode_token, java.util.ArrayList<Integer> imm_list)
	{
		insn(decodeOpcodeName(opcode_token.getText()), imm_list);
	}

	void insn(int opcode, java.util.ArrayList<Integer> imm_list)
	{
		int[] imm_array = new int[imm_list.size()];
		
		int idx = 0;
		for ( Integer imm: imm_list )
		{
			imm_array[idx++] = imm;
		}
		
		currentFunction.insn(opcode, imm_array);
	}

	void insn(int opcode)
	{
		insn(opcode, new int[]{});
	}
	
	void insn(int opcode, int[] imm)
	{
		currentFunction.insn(opcode, imm);
	}
	
	void insn(org.antlr.runtime.Token opcode_token, Name name, int imm)
	{
		currentFunction.insn(decodeOpcodeName(opcode_token.getText()), name, new int[]{imm});
	}

	void insn(org.antlr.runtime.Token opcode_token, Name name)
	{
		currentFunction.insn(decodeOpcodeName(opcode_token.getText()), name, new int[0]);
	}

	void insn(int opcode, Object value)
	{
		currentFunction.insn(opcode, value);
	}

	void poolInsn(int opcode, Object value)
	{
		if ( OP_pushint == opcode )
		{
			Integer iKey = (Integer)value;
			intPool.add(iKey);
			currentFunction.insn(opcode, iKey);
		}
		else if ( OP_pushuint == opcode )
		{
			Long lKey = (Long)value;
			uintPool.add(lKey);
			currentFunction.insn(opcode, lKey);
		}
		else if ( OP_pushdouble == opcode )
		{
			Double dKey = (Double)value;
			doublePool.add(dKey);
			currentFunction.insn(opcode, dKey);
		}
		else if ( OP_pushstring == opcode || OP_debugfile == opcode )
		{
			String sKey = (String)value;
			stringPool.add(sKey);
			currentFunction.insn(opcode, sKey);
		}
		else
			throw new IllegalArgumentException("Don't have a pool for " + opcode);
	}
	
	int decodeOpcodeName(String opcodeName)
	{
		String opcodeKey = opcodeName.toLowerCase();
		
		if ( opcodeNameToOpcode.size() == 0)
		{
			loadOpcodes();
		}
		
		semanticAssertion(opcodeNameToOpcode.containsKey(opcodeKey), "Unknown opcode: " + opcodeName);
		
		return opcodeNameToOpcode.get(opcodeKey);
	}

	static private void loadOpcodes()
	{
		//  Traverse the names of the OP_foo constants
		//  in ActionBlockConstants and load their values.
		for ( Field f: macromedia.asc.embedding.avmplus.ActionBlockConstants.class.getFields())
		{
			String field_name = f.getName();
			
			if ( field_name.startsWith("OP_"))
			{
				String opcode = field_name.substring(3);
				try
				{
					int field_value = f.getInt(null);
					opcodeNameToOpcode.put(opcode, field_value);
					opcodeToOpcodeName.put(field_value, opcode);
				}
				catch ( Exception noFieldValue)
				{
					//  Ignore, continue...
				}
					
			}
		}
	}

	void semanticAssertion(boolean cond, String diagnostic )
	{
		if (!cond)
			throw new IllegalArgumentException(diagnostic);
	}

	void syntaxError(String diagnostic)
	{
		syntaxErrors.add(diagnostic);
	}
	
	void dump(java.io.PrintStream out)
	{
		for ( String fname: functionsByName.keySet() )
			functionsByName.get(fname).dump(out);
	}


	static String decodeOp(int opcode)
	{
		if ( opcodeToOpcodeName.containsKey(opcode))
			return opcodeToOpcodeName.get(opcode);
		else
			return "OP_" + Integer.toHexString(opcode);
	}


	Name getName(String unqualifiedName)
	{
		nsPool.add(new Namespace(CONSTANT_PackageNamespace));
		Name result = new Name(unqualifiedName);
		
		namePool.add(result);
		stringPool.add(unqualifiedName);
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
}
