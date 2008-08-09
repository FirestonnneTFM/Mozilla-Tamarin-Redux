/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2004-2007
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

#ifndef __avmplus_msc_inttypes__
#define __avmplus_msc_inttypes__

typedef unsigned char    uint8_t;
typedef unsigned short   uint16_t;
typedef signed char      int8_t;
typedef short            int16_t;
typedef unsigned int     uint32_t; 
typedef signed int       int32_t;
typedef __int64          int64_t;
typedef unsigned __int64 uint64_t;
typedef long long          int64_t;
typedef unsigned long long         uint64_t;

// math friendly pointer (64 bits in LP 64 systems)
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#define AVMPLUS_TYPE_IS_POINTER_SIZED __w64
#else
#define AVMPLUS_TYPE_IS_POINTER_SIZED
#endif	

#ifdef AVMPLUS_64BIT
typedef AVMPLUS_TYPE_IS_POINTER_SIZED uint64_t uintptr_t;
typedef AVMPLUS_TYPE_IS_POINTER_SIZED int64_t intptr_t;
#else
typedef AVMPLUS_TYPE_IS_POINTER_SIZED uint32_t uintptr_t;
typedef AVMPLUS_TYPE_IS_POINTER_SIZED int32_t intptr_t;
#endif

#endif	
