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
#ifdef FEATURE_SAMPLER
	void CallStackNode::initialize(MethodEnv *			env,
								   AbstractFunction *	info,
								   Atom*				framep,
								   Traits**				traits,
								   int					argc,
								   uint32 *				ap,
								   sintptr volatile *	eip)
	{
		AvmCore *core = info->core();

		this->info      = info;
		this->eip		= eip;     // ptr to where the current instruction pointer is stored

#ifdef DEBUGGER
		this->env       = env;
		this->ap        = ap;
		this->argc      = argc;
		this->framep	= framep;  // pointer to top of AS registers
		this->traits    = traits;  // pointer to traits of top of AS registers
		filename        = NULL;
		linenum         = 0;

		// scopechain stuff
		#ifdef AVMPLUS_INTERP
		this->scopeDepth = NULL;
		#endif
#else
		// Avoid compiler warnings
		(void)ap;
		(void)argc;
		(void)traits;
		(void)framep;
		(void)env;

#endif
		// link into callstack
		next            = core->callStack;
		core->callStack = this;

		depth           = next ? (next->depth+1) : 1;
		AvmAssert(info != NULL);
	}

	void CallStackNode::exit()
	{
		info->core()->callStack = next;
		next = NULL;
	}
#ifdef DEBUGGER
	void** CallStackNode::scopeBase()
	{
		// If we were given a real frame, calculate the scope base; otherwise return NULL
		if (framep && info)
			return (void**) (framep + ((MethodInfo*)info)->local_count);
		else
			return NULL;
	}
	// Dump a filename.  The incoming filename is of the form
	// "C:\path\to\package\root;package/package;filename".  The path format
	// will depend on the platform on which the movie was originally
	// compiled, NOT the platform the the player is running in.
	//
	// We want to replace the semicolons with path separators.  We'll take
	// a guess at the appropriate path separator of the compilation
	// platform by looking for any backslashes in the path.  If there are
	// any, then we'll assume backslash is the path separator.  If not,
	// we'll use forward slash.
	void StackTrace::dumpFilename(Stringp filename, PrintWriter& out) const
	{
		wchar semicolonReplacement = '/';
		int length = filename->length();
		wchar ch;
		int i;

		// look for backslashes; if there are any, then semicolons will be
		// replaced with backslashes, not forward slashes
		for (i=0; i<length; ++i) {
			ch = (*filename)[i];
			if (ch == '\\') {
				semicolonReplacement = '\\';
				break;
			}
		}

		// output the entire path
		bool previousWasSlash = false;
		for (i=0; i<length; ++i) {
			ch = (*filename)[i];
			if (ch == ';') {
				if (previousWasSlash)
					continue;
				ch = semicolonReplacement;
				previousWasSlash = true;
			} else if (ch == '/' || ch == '\\') {
				previousWasSlash = true;
			} else {
				previousWasSlash = false;
			}
			out << ch;
		}
	}

	Stringp StackTrace::format(AvmCore* core)
	{
		if(!stringRep)
		{
			Stringp s = core->kEmptyString;
			int displayDepth = depth;
			if (displayDepth > kMaxDisplayDepth) {
				displayDepth = kMaxDisplayDepth;
			}
			const Element *e = elements;
			for (int i=0; i<displayDepth; i++, e++)
			{
				// omit fake functions which are only for profiling purposes
				if(e->info->isFakeFunction())
					continue;
				if(i != 0)
					s = core->concatStrings(s, core->knewline);

				Stringp filename=NULL;
				if(e->filename)
				{
					StringBuffer sb(core->gc);
					dumpFilename(e->filename, sb);
					filename = core->newString(sb.c_str());
				}
				s = core->concatStrings(s, e->info->getStackTraceLine(filename));
				if(e->filename)
				{
					s = core->concatStrings(s, core->intToString(e->linenum));
					s = core->concatStrings(s, core->krightbracket);
				}
			}
			stringRep = s;
		}
		return stringRep;
	}

#endif /* DEBUGGER */

#endif /* FEATURE_SAMPLER */
}
