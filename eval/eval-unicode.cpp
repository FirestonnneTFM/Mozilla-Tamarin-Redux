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
 * Portions created by the Initial Developer are Copyright (C) 2008
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

#ifdef VMCFG_EVAL

#include "eval.h"

/* Rudimentary Unicode support - enough to handle identifier lexing.  These tables
 * are slightly optimized for space, but more could be done.  In particular, delta
 * coding can be useful because most deltas - both in character ranges and between
 * ranges - fit in a single byte.  Delta coding might shrink the tables by slightly
 * less than a factor of 2.  As it is, the total size of these tables is about 2KB.
 *
 * Speed is not a big issue here because almost no programs have identifiers that
 * contain characters outside the ASCII range, and ASCII is handled specially 
 * outside this file using faster code paths (see code in eval-lex.cpp).
 *
 * The tables are generated from the Unicode data file by generate-unicode-tables.c
 * in this directory.
 */
namespace avmplus
{
	namespace RTC
	{
		struct Range {
			uint16_t lo;
			uint16_t hi;
		};
		
		struct UnicodeTable {
			uint32_t nranges;
			Range const * ranges;
			uint32_t nsingletons;
			uint16_t const * singletons;
		};
		
		static const Range identifier_start_ranges[] = {
		{0x0041, 0x005A},
		{0x0061, 0x007A},
		{0x00C0, 0x00D6},
		{0x00D8, 0x00F6},
		{0x00F8, 0x02C1},
		{0x02C6, 0x02D1},
		{0x02E0, 0x02E4},
		{0x0370, 0x0374},
		{0x0376, 0x0377},
		{0x037A, 0x037D},
		{0x0388, 0x038A},
		{0x038E, 0x03A1},
		{0x03A3, 0x03F5},
		{0x03F7, 0x0481},
		{0x048A, 0x0523},
		{0x0531, 0x0556},
		{0x0561, 0x0587},
		{0x05D0, 0x05EA},
		{0x05F0, 0x05F2},
		{0x0621, 0x064A},
		{0x066E, 0x066F},
		{0x0671, 0x06D3},
		{0x06E5, 0x06E6},
		{0x06EE, 0x06EF},
		{0x06FA, 0x06FC},
		{0x0712, 0x072F},
		{0x074D, 0x07A5},
		{0x07CA, 0x07EA},
		{0x07F4, 0x07F5},
		{0x0904, 0x0939},
		{0x0958, 0x0961},
		{0x0971, 0x0972},
		{0x097B, 0x097F},
		{0x0985, 0x098C},
		{0x098F, 0x0990},
		{0x0993, 0x09A8},
		{0x09AA, 0x09B0},
		{0x09B6, 0x09B9},
		{0x09DC, 0x09DD},
		{0x09DF, 0x09E1},
		{0x09F0, 0x09F1},
		{0x0A05, 0x0A0A},
		{0x0A0F, 0x0A10},
		{0x0A13, 0x0A28},
		{0x0A2A, 0x0A30},
		{0x0A32, 0x0A33},
		{0x0A35, 0x0A36},
		{0x0A38, 0x0A39},
		{0x0A59, 0x0A5C},
		{0x0A72, 0x0A74},
		{0x0A85, 0x0A8D},
		{0x0A8F, 0x0A91},
		{0x0A93, 0x0AA8},
		{0x0AAA, 0x0AB0},
		{0x0AB2, 0x0AB3},
		{0x0AB5, 0x0AB9},
		{0x0AE0, 0x0AE1},
		{0x0B05, 0x0B0C},
		{0x0B0F, 0x0B10},
		{0x0B13, 0x0B28},
		{0x0B2A, 0x0B30},
		{0x0B32, 0x0B33},
		{0x0B35, 0x0B39},
		{0x0B5C, 0x0B5D},
		{0x0B5F, 0x0B61},
		{0x0B85, 0x0B8A},
		{0x0B8E, 0x0B90},
		{0x0B92, 0x0B95},
		{0x0B99, 0x0B9A},
		{0x0B9E, 0x0B9F},
		{0x0BA3, 0x0BA4},
		{0x0BA8, 0x0BAA},
		{0x0BAE, 0x0BB9},
		{0x0C05, 0x0C0C},
		{0x0C0E, 0x0C10},
		{0x0C12, 0x0C28},
		{0x0C2A, 0x0C33},
		{0x0C35, 0x0C39},
		{0x0C58, 0x0C59},
		{0x0C60, 0x0C61},
		{0x0C85, 0x0C8C},
		{0x0C8E, 0x0C90},
		{0x0C92, 0x0CA8},
		{0x0CAA, 0x0CB3},
		{0x0CB5, 0x0CB9},
		{0x0CE0, 0x0CE1},
		{0x0D05, 0x0D0C},
		{0x0D0E, 0x0D10},
		{0x0D12, 0x0D28},
		{0x0D2A, 0x0D39},
		{0x0D60, 0x0D61},
		{0x0D7A, 0x0D7F},
		{0x0D85, 0x0D96},
		{0x0D9A, 0x0DB1},
		{0x0DB3, 0x0DBB},
		{0x0DC0, 0x0DC6},
		{0x0E01, 0x0E30},
		{0x0E32, 0x0E33},
		{0x0E40, 0x0E46},
		{0x0E81, 0x0E82},
		{0x0E87, 0x0E88},
		{0x0E94, 0x0E97},
		{0x0E99, 0x0E9F},
		{0x0EA1, 0x0EA3},
		{0x0EAA, 0x0EAB},
		{0x0EAD, 0x0EB0},
		{0x0EB2, 0x0EB3},
		{0x0EC0, 0x0EC4},
		{0x0EDC, 0x0EDD},
		{0x0F40, 0x0F47},
		{0x0F49, 0x0F6C},
		{0x0F88, 0x0F8B},
		{0x1000, 0x102A},
		{0x1050, 0x1055},
		{0x105A, 0x105D},
		{0x1065, 0x1066},
		{0x106E, 0x1070},
		{0x1075, 0x1081},
		{0x10A0, 0x10C5},
		{0x10D0, 0x10FA},
		{0x1100, 0x1159},
		{0x115F, 0x11A2},
		{0x11A8, 0x11F9},
		{0x1200, 0x1248},
		{0x124A, 0x124D},
		{0x1250, 0x1256},
		{0x125A, 0x125D},
		{0x1260, 0x1288},
		{0x128A, 0x128D},
		{0x1290, 0x12B0},
		{0x12B2, 0x12B5},
		{0x12B8, 0x12BE},
		{0x12C2, 0x12C5},
		{0x12C8, 0x12D6},
		{0x12D8, 0x1310},
		{0x1312, 0x1315},
		{0x1318, 0x135A},
		{0x1380, 0x138F},
		{0x13A0, 0x13F4},
		{0x1401, 0x166C},
		{0x166F, 0x1676},
		{0x1681, 0x169A},
		{0x16A0, 0x16EA},
		{0x16EE, 0x16F0},
		{0x1700, 0x170C},
		{0x170E, 0x1711},
		{0x1720, 0x1731},
		{0x1740, 0x1751},
		{0x1760, 0x176C},
		{0x176E, 0x1770},
		{0x1780, 0x17B3},
		{0x1820, 0x1877},
		{0x1880, 0x18A8},
		{0x1900, 0x191C},
		{0x1950, 0x196D},
		{0x1970, 0x1974},
		{0x1980, 0x19A9},
		{0x19C1, 0x19C7},
		{0x1A00, 0x1A16},
		{0x1B05, 0x1B33},
		{0x1B45, 0x1B4B},
		{0x1B83, 0x1BA0},
		{0x1BAE, 0x1BAF},
		{0x1C00, 0x1C23},
		{0x1C4D, 0x1C4F},
		{0x1C5A, 0x1C7D},
		{0x1D00, 0x1DBF},
		{0x1E00, 0x1F15},
		{0x1F18, 0x1F1D},
		{0x1F20, 0x1F45},
		{0x1F48, 0x1F4D},
		{0x1F50, 0x1F57},
		{0x1F5F, 0x1F7D},
		{0x1F80, 0x1FB4},
		{0x1FB6, 0x1FBC},
		{0x1FC2, 0x1FC4},
		{0x1FC6, 0x1FCC},
		{0x1FD0, 0x1FD3},
		{0x1FD6, 0x1FDB},
		{0x1FE0, 0x1FEC},
		{0x1FF2, 0x1FF4},
		{0x1FF6, 0x1FFC},
		{0x2090, 0x2094},
		{0x210A, 0x2113},
		{0x2119, 0x211D},
		{0x212A, 0x212D},
		{0x212F, 0x2139},
		{0x213C, 0x213F},
		{0x2145, 0x2149},
		{0x2160, 0x2188},
		{0x2C00, 0x2C2E},
		{0x2C30, 0x2C5E},
		{0x2C60, 0x2C6F},
		{0x2C71, 0x2C7D},
		{0x2C80, 0x2CE4},
		{0x2D00, 0x2D25},
		{0x2D30, 0x2D65},
		{0x2D80, 0x2D96},
		{0x2DA0, 0x2DA6},
		{0x2DA8, 0x2DAE},
		{0x2DB0, 0x2DB6},
		{0x2DB8, 0x2DBE},
		{0x2DC0, 0x2DC6},
		{0x2DC8, 0x2DCE},
		{0x2DD0, 0x2DD6},
		{0x2DD8, 0x2DDE},
		{0x3005, 0x3007},
		{0x3021, 0x3029},
		{0x3031, 0x3035},
		{0x3038, 0x303C},
		{0x3041, 0x3096},
		{0x309D, 0x309F},
		{0x30A1, 0x30FA},
		{0x30FC, 0x30FF},
		{0x3105, 0x312D},
		{0x3131, 0x318E},
		{0x31A0, 0x31B7},
		{0x31F0, 0x31FF},
		{0xA000, 0xA48C},
		{0xA500, 0xA60C},
		{0xA610, 0xA61F},
		{0xA62A, 0xA62B},
		{0xA640, 0xA65F},
		{0xA662, 0xA66E},
		{0xA67F, 0xA697},
		{0xA717, 0xA71F},
		{0xA722, 0xA788},
		{0xA78B, 0xA78C},
		{0xA7FB, 0xA801},
		{0xA803, 0xA805},
		{0xA807, 0xA80A},
		{0xA80C, 0xA822},
		{0xA840, 0xA873},
		{0xA882, 0xA8B3},
		{0xA90A, 0xA925},
		{0xA930, 0xA946},
		{0xAA00, 0xAA28},
		{0xAA40, 0xAA42},
		{0xAA44, 0xAA4B},
		{0xF900, 0xFA2D},
		{0xFA30, 0xFA6A},
		{0xFA70, 0xFAD9},
		{0xFB00, 0xFB06},
		{0xFB13, 0xFB17},
		{0xFB1F, 0xFB28},
		{0xFB2A, 0xFB36},
		{0xFB38, 0xFB3C},
		{0xFB40, 0xFB41},
		{0xFB43, 0xFB44},
		{0xFB46, 0xFBB1},
		{0xFBD3, 0xFD3D},
		{0xFD50, 0xFD8F},
		{0xFD92, 0xFDC7},
		{0xFDF0, 0xFDFB},
		{0xFE70, 0xFE74},
		{0xFE76, 0xFEFC},
		{0xFF21, 0xFF3A},
		{0xFF41, 0xFF5A},
		{0xFF66, 0xFFBE},
		{0xFFC2, 0xFFC7},
		{0xFFCA, 0xFFCF},
		{0xFFD2, 0xFFD7},
		{0xFFDA, 0xFFDC},
		};
		
		static const uint16_t identifier_start_singletons[] = {
		0x00AA,
		0x00B5,
		0x00BA,
		0x02EC,
		0x02EE,
		0x0386,
		0x038C,
		0x0559,
		0x06D5,
		0x06FF,
		0x0710,
		0x07B1,
		0x07FA,
		0x093D,
		0x0950,
		0x09B2,
		0x09BD,
		0x09CE,
		0x0A5E,
		0x0ABD,
		0x0AD0,
		0x0B3D,
		0x0B71,
		0x0B83,
		0x0B9C,
		0x0BD0,
		0x0C3D,
		0x0CBD,
		0x0CDE,
		0x0D3D,
		0x0DBD,
		0x0E84,
		0x0E8A,
		0x0E8D,
		0x0EA5,
		0x0EA7,
		0x0EBD,
		0x0EC6,
		0x0F00,
		0x103F,
		0x1061,
		0x108E,
		0x10FC,
		0x1258,
		0x12C0,
		0x17D7,
		0x17DC,
		0x18AA,
		0x1F59,
		0x1F5B,
		0x1F5D,
		0x1FBE,
		0x2071,
		0x207F,
		0x2102,
		0x2107,
		0x2115,
		0x2124,
		0x2126,
		0x2128,
		0x214E,
		0x2D6F,
		0x2E2F,
		0x3400,
		0x4DB5,
		0x4E00,
		0x9FC3,
		0xAC00,
		0xD7A3,
		0xFB1D,
		0xFB3E,
		};
		
		static const UnicodeTable identifier_start = {
			263,
			identifier_start_ranges,
			71,
			identifier_start_singletons
		};

		static const Range identifier_subsequent_ranges[] = {
		{0x0030, 0x0039},
		{0x0300, 0x036F},
		{0x0483, 0x0487},
		{0x0591, 0x05BD},
		{0x05C1, 0x05C2},
		{0x05C4, 0x05C5},
		{0x0610, 0x061A},
		{0x064B, 0x065E},
		{0x0660, 0x0669},
		{0x06D6, 0x06DC},
		{0x06DF, 0x06E4},
		{0x06E7, 0x06E8},
		{0x06EA, 0x06ED},
		{0x06F0, 0x06F9},
		{0x0730, 0x074A},
		{0x07A6, 0x07B0},
		{0x07C0, 0x07C9},
		{0x07EB, 0x07F3},
		{0x0901, 0x0903},
		{0x093E, 0x094D},
		{0x0951, 0x0954},
		{0x0962, 0x0963},
		{0x0966, 0x096F},
		{0x0981, 0x0983},
		{0x09BE, 0x09C4},
		{0x09C7, 0x09C8},
		{0x09CB, 0x09CD},
		{0x09E2, 0x09E3},
		{0x09E6, 0x09EF},
		{0x0A01, 0x0A03},
		{0x0A3E, 0x0A42},
		{0x0A47, 0x0A48},
		{0x0A4B, 0x0A4D},
		{0x0A66, 0x0A71},
		{0x0A81, 0x0A83},
		{0x0ABE, 0x0AC5},
		{0x0AC7, 0x0AC9},
		{0x0ACB, 0x0ACD},
		{0x0AE2, 0x0AE3},
		{0x0AE6, 0x0AEF},
		{0x0B01, 0x0B03},
		{0x0B3E, 0x0B44},
		{0x0B47, 0x0B48},
		{0x0B4B, 0x0B4D},
		{0x0B56, 0x0B57},
		{0x0B62, 0x0B63},
		{0x0B66, 0x0B6F},
		{0x0BBE, 0x0BC2},
		{0x0BC6, 0x0BC8},
		{0x0BCA, 0x0BCD},
		{0x0BE6, 0x0BEF},
		{0x0C01, 0x0C03},
		{0x0C3E, 0x0C44},
		{0x0C46, 0x0C48},
		{0x0C4A, 0x0C4D},
		{0x0C55, 0x0C56},
		{0x0C62, 0x0C63},
		{0x0C66, 0x0C6F},
		{0x0C82, 0x0C83},
		{0x0CBE, 0x0CC4},
		{0x0CC6, 0x0CC8},
		{0x0CCA, 0x0CCD},
		{0x0CD5, 0x0CD6},
		{0x0CE2, 0x0CE3},
		{0x0CE6, 0x0CEF},
		{0x0D02, 0x0D03},
		{0x0D3E, 0x0D44},
		{0x0D46, 0x0D48},
		{0x0D4A, 0x0D4D},
		{0x0D62, 0x0D63},
		{0x0D66, 0x0D6F},
		{0x0D82, 0x0D83},
		{0x0DCF, 0x0DD4},
		{0x0DD8, 0x0DDF},
		{0x0DF2, 0x0DF3},
		{0x0E34, 0x0E3A},
		{0x0E47, 0x0E4E},
		{0x0E50, 0x0E59},
		{0x0EB4, 0x0EB9},
		{0x0EBB, 0x0EBC},
		{0x0EC8, 0x0ECD},
		{0x0ED0, 0x0ED9},
		{0x0F18, 0x0F19},
		{0x0F20, 0x0F29},
		{0x0F3E, 0x0F3F},
		{0x0F71, 0x0F84},
		{0x0F86, 0x0F87},
		{0x0F90, 0x0F97},
		{0x0F99, 0x0FBC},
		{0x102B, 0x103E},
		{0x1040, 0x1049},
		{0x1056, 0x1059},
		{0x105E, 0x1060},
		{0x1062, 0x1064},
		{0x1067, 0x106D},
		{0x1071, 0x1074},
		{0x1082, 0x108D},
		{0x108F, 0x1099},
		{0x1712, 0x1714},
		{0x1732, 0x1734},
		{0x1752, 0x1753},
		{0x1772, 0x1773},
		{0x17B6, 0x17D3},
		{0x17E0, 0x17E9},
		{0x180B, 0x180D},
		{0x1810, 0x1819},
		{0x1920, 0x192B},
		{0x1930, 0x193B},
		{0x1946, 0x194F},
		{0x19B0, 0x19C0},
		{0x19C8, 0x19C9},
		{0x19D0, 0x19D9},
		{0x1A17, 0x1A1B},
		{0x1B00, 0x1B04},
		{0x1B34, 0x1B44},
		{0x1B50, 0x1B59},
		{0x1B6B, 0x1B73},
		{0x1B80, 0x1B82},
		{0x1BA1, 0x1BAA},
		{0x1BB0, 0x1BB9},
		{0x1C24, 0x1C37},
		{0x1C40, 0x1C49},
		{0x1C50, 0x1C59},
		{0x1DC0, 0x1DE6},
		{0x1DFE, 0x1DFF},
		{0x203F, 0x2040},
		{0x20D0, 0x20DC},
		{0x20E5, 0x20F0},
		{0x2DE0, 0x2DFF},
		{0x302A, 0x302F},
		{0x3099, 0x309A},
		{0xA620, 0xA629},
		{0xA67C, 0xA67D},
		{0xA823, 0xA827},
		{0xA880, 0xA881},
		{0xA8B4, 0xA8C4},
		{0xA8D0, 0xA8D9},
		{0xA900, 0xA909},
		{0xA926, 0xA92D},
		{0xA947, 0xA953},
		{0xAA29, 0xAA36},
		{0xAA4C, 0xAA4D},
		{0xAA50, 0xAA59},
		{0xFE00, 0xFE0F},
		{0xFE20, 0xFE26},
		{0xFE33, 0xFE34},
		{0xFE4D, 0xFE4F},
		{0xFF10, 0xFF19},
		};
		
		static const uint16_t identifier_subsequent_singletons[] = {
		0x005F,
		0x05BF,
		0x05C7,
		0x0670,
		0x0711,
		0x093C,
		0x09BC,
		0x09D7,
		0x0A3C,
		0x0A51,
		0x0A75,
		0x0ABC,
		0x0B3C,
		0x0B82,
		0x0BD7,
		0x0CBC,
		0x0D57,
		0x0DCA,
		0x0DD6,
		0x0E31,
		0x0EB1,
		0x0F35,
		0x0F37,
		0x0F39,
		0x0FC6,
		0x135F,
		0x17DD,
		0x18A9,
		0x2054,
		0x20E1,
		0xA66F,
		0xA802,
		0xA806,
		0xA80B,
		0xAA43,
		0xFB1E,
		0xFF3F,
		};
		
		static const UnicodeTable identifier_subsequent = {
			148,
			identifier_subsequent_ranges,
			37,
			identifier_subsequent_singletons
		};
		
		static bool testNonASCIICharacter(const UnicodeTable* tbl, wchar c)
		{
			int32_t lo = 0;
			int32_t hi = tbl->nranges-1;
			
			while (lo <= hi) {
				int32_t mid = (lo + hi) / 2;
				if (tbl->ranges[mid].lo <= c && c <= tbl->ranges[mid].hi)
					return true;
				if (c < tbl->ranges[mid].lo)
					hi = mid;
				else
					lo = mid;
			}

			lo = 0;
			hi = tbl->nsingletons-1;
			while (lo <= hi) {
				int32_t mid = (lo + hi) / 2;
				if (tbl->singletons[mid] == c)
					return true;
				if (c < tbl->singletons[mid])
					hi = mid-1;
				else
					lo = mid+1;
			}
			
			return false;
		}
		
		bool isNonASCIIIdentifierStart(wchar c) 
		{
			return testNonASCIICharacter(&identifier_start, c);
		}
		
		bool isNonASCIIIdentifierSubsequent(wchar c)
		{
			return testNonASCIICharacter(&identifier_start, c) ||
				   testNonASCIICharacter(&identifier_subsequent, c);
		}
	}
}

#endif // VMCFG_EVAL
