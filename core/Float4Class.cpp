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
#include "BuiltinNatives.h"
#include <float.h>
#ifdef VMCFG_FLOAT

namespace avmplus
{
    Float4Class::Float4Class(VTable* cvtable)
    : ClassClosure(cvtable)
    {
        toplevel()->_float4Class = this;
        // prototype objects are always vanilla objects.
        createVanillaPrototype();
    }

    float4_t Float4Class::fromComponents(float x, float y, float z, float t){
        float4_t retval = { x, y, z, t};
        return retval;
    }
    Atom Float4Class::construct(int argc, Atom* argv)
    {
        // Float called as constructor creates new Float instance
        // Note: new Float() with no args returns 0 - as does Number
        if (argc == 0)
            return core()->float4Atom(zeroIntAtom);  

        if(argc == 1)
            return core()->float4Atom(argv[1]);
        
        if(argc != 4)
            vtable->init->argcError(argc);

        return core()->float4ToAtom( fromComponents( AvmCore::singlePrecisionFloat(argv[1]), 
                                                     AvmCore::singlePrecisionFloat(argv[2]), 
                                                     AvmCore::singlePrecisionFloat(argv[3]), 
                                                     AvmCore::singlePrecisionFloat(argv[4])) );
    }

    // OPTIMIZEME: These are generic implementations.  Faster MMX/SSE/Neon implementations are
    // desirable but mostly in jitted code, so these may be OK for the interpreter and calls
    // from the runtime.  Still, if there are precision differences between the C++ implementations
    // and the native MMX/SSE/Neon implementations then we'd be better off deferring to the
    // intrinsics here so that there's no divergence between jitted and interpreted code.
#define F4OP2(s1,s2,op) { op( f4_x(s1),f4_x(s2)) , op(f4_y(s1), f4_y(s2)) , op( f4_z(s1), f4_z(s2)) , op(f4_w(s1), f4_w(s2)) }
#define F4OP2SEL(s1,s2,op) { f4_x(s1) op f4_x(s2) ? 1.0f: 0.0f , \
                             f4_y(s1) op f4_y(s2) ? 1.0f: 0.0f , \
                             f4_z(s1) op f4_z(s2) ? 1.0f: 0.0f , \
                             f4_w(s1) op f4_w(s2) ? 1.0f: 0.0f }
#define F4OP2SELe(s1,s2,op) {f4_x(s1) op f4_x(s2) ? f4_x(s1): f4_x(s2) , \
                             f4_y(s1) op f4_y(s2) ? f4_y(s1): f4_y(s2) , \
                             f4_z(s1) op f4_z(s2) ? f4_z(s1): f4_z(s2) , \
                             f4_w(s1) op f4_w(s2) ? f4_w(s1): f4_w(s2) }

#define F4OP1(s1,op, ... ) { op(f4_x(s1) __VA_ARGS__), op(f4_y(s1) __VA_ARGS__), op(f4_z(s1) __VA_ARGS__), op(f4_w(s1) __VA_ARGS__) }

    float4_t Float4Class::isGreater(float4_t x, float4_t y)
    {
        
        float4_t result = F4OP2SEL(x, y, > );
        return result;
    }

    float4_t Float4Class::isGreaterOrEqual(float4_t x, float4_t y)
    {
        float4_t result = F4OP2SEL(x, y, >= );
        return result;
    }

    float4_t Float4Class::isLess(float4_t x, float4_t y) 
    {
        float4_t result = F4OP2SEL(x, y, < );
        return result;
    }
    
    float4_t Float4Class::isLessOrEqual(float4_t x, float4_t y)
    {
        float4_t result = F4OP2SEL(x, y, <= );
        return result;
    }

    float4_t Float4Class::isEqual(float4_t x, float4_t y)
    {
        float4_t result = F4OP2SEL(x, y, == );
        return result;
    }

    float4_t Float4Class::isNotEqual(float4_t x, float4_t y)
    {
        float4_t result = F4OP2SEL(x, y, != );
        return result;
    }

    float4_t Float4Class::abs(float4_t x)
    {
        float4_t result = F4OP1(x,fabsf);
        return result;
    }

    float4_t Float4Class::acos(float4_t x)
    {
        float4_t result = F4OP1(x,acosf);
        return result;
    }

    float4_t Float4Class::asin(float4_t x)
    {
        float4_t result = F4OP1(x,asinf);
        return result;
    }

    float4_t Float4Class::atan(float4_t x)
    {
        float4_t result = F4OP1(x,atanf);
        return result;
    }

    float4_t Float4Class::atan2(float4_t y, float4_t x)
    {
        float4_t result = F4OP2(y,x,atan2f);
        return result;
    }

    float4_t Float4Class::ceil(float4_t x)
    {
        float4_t result = F4OP1(x,ceilf);
        return result;
    }

    float4_t Float4Class::cos(float4_t x)
    {
        float4_t result = F4OP1(x,cosf);
        return result;
    }
    
    float4_t Float4Class::exp(float4_t x)
    {
        float4_t result = F4OP1(x,expf);
        return result;
    }

    float4_t Float4Class::floor(float4_t x)
    {
        float4_t result = F4OP1(x,floorf);
        return result;
    }

    float4_t Float4Class::log(float4_t x)
    {
        float4_t result = F4OP1(x,logf);
        return result;
    }

    // FIXME: Probably not right for either NaN nor -0 vs +0
    float4_t Float4Class::min(float4_t x, float4_t y)
    {
        float4_t result = F4OP2SELe(x,y,<);
        return result;
    }

    // FIXME: Probably not right for either NaN nor -0 vs +0
    float4_t Float4Class::max(float4_t x, float4_t y)
    {
        float4_t result = F4OP2SELe(x,y,>);
        return result;
    }

    float4_t Float4Class::pow(float4_t x, float p)
    {
        float4_t result = F4OP1(x, powf, ,p);
        return result;
    }

   // FIXME: Here we allow reduced precision so we almost certainly want to delegate to the
    // native SIMD implementation to get consistent interpreter/JIT behavior.
    float4_t Float4Class::reciprocal(float4_t x)
    {
        float4_t result = F4OP1(x, 1.0f/ );
        return result;
    }

    float4_t Float4Class::round(float4_t x)
    {
        float4_t result = F4OP1(x, floorf, +0.5f);
        return result;
    }

    float4_t Float4Class::rsqrt(float4_t x)
    {
        float4_t result = F4OP1(x, 1.0f/sqrtf );
        return result;
    }

    float4_t Float4Class::sin(float4_t x)
    {
        float4_t result = F4OP1(x,sinf);
        return result;
    }

    float4_t Float4Class::sqrt(float4_t x)
    {
        float4_t result = F4OP1(x,sqrtf);
        return result;
    }

    float4_t Float4Class::tan(float4_t x)
    {
        float4_t result = F4OP1(x,tanf);
        return result;
    }

    float4_t Float4Class::normalize(float4_t x)
    {
        float m = magnitude(x);
        float4_t result = F4OP1(x,,/m);
        return result;
    }

    float4_t Float4Class::cross(float4_t a, float4_t b)
    {
        float4_t result = { f4_y(a)*f4_z(b)-f4_z(a)*f4_y(b),\
                            f4_z(a)*f4_x(b)-f4_x(a)*f4_z(b),\
                            f4_x(a)*f4_y(b)-f4_y(a)*f4_x(b),\
                            0.0f };
        return result;
    }

    float Float4Class::dot(float4_t a, float4_t b)
    {
        return f4_x(a) *  f4_x(b) +
               f4_y(a) *  f4_y(b) +
               f4_z(a) *  f4_z(b) +
               f4_w(a) *  f4_w(b);
    }
    float Float4Class::dot2(float4_t a, float4_t b)
    {
        return f4_x(a) *  f4_x(b) +
               f4_y(a) *  f4_y(b);
    }
    
    float Float4Class::dot3(float4_t a, float4_t b)
    {
        return f4_x(a) *  f4_x(b) +
               f4_y(a) *  f4_y(b) +
               f4_z(a) *  f4_z(b);
    }

    float Float4Class::magnitude(float4_t x)
    {
        return sqrtf( dot(x,x) );
    }
    
    float Float4Class::magnitude2(float4_t x)
    {
        return sqrtf( dot2(x,x) );
    }

    float Float4Class::magnitude3(float4_t x)
    {
        return sqrtf( dot3(x,x) );
    }
    
    float Float4Class::distance(float4_t x, float4_t y)
    {
        return magnitude(f4_sub(x,y));
    }

    float Float4Class::distance2(float4_t x, float4_t y)
    {
        return magnitude2(f4_sub(x,y));
    }

    float Float4Class::distance3(float4_t x, float4_t y)
    {
        return magnitude3(f4_sub(x,y));
    }

    // The four low nibbles of "how" specify which field to get, with the high nibble specifying x and the low nibble w.
    // FIXME: For some reason the field names are offset by 1 so subtract that; we should fix that, it's useless overhead & confusing.

    float4_t Float4Class::_swizzle(float4_t val, int32_t how)
    {
        AvmAssert( how>=0 && how<256);
        switch(how){ // must explicitly expand; the "shuffle" intrinsic doesn't take variables. 
#define CASE(x)  case x: return f4_shuffle(val,x);
            CASE(0);CASE(1);CASE(2);CASE(3);CASE(4);CASE(5);CASE(6);CASE(7);CASE(8);CASE(9);
            CASE(10);CASE(11);CASE(12);CASE(13);CASE(14);CASE(15);CASE(16);CASE(17);CASE(18);CASE(19);
            CASE(20);CASE(21);CASE(22);CASE(23);CASE(24);CASE(25);CASE(26);CASE(27);CASE(28);CASE(29);
            CASE(30);CASE(31);CASE(32);CASE(33);CASE(34);CASE(35);CASE(36);CASE(37);CASE(38);CASE(39);
            CASE(40);CASE(41);CASE(42);CASE(43);CASE(44);CASE(45);CASE(46);CASE(47);CASE(48);CASE(49);
            CASE(50);CASE(51);CASE(52);CASE(53);CASE(54);CASE(55);CASE(56);CASE(57);CASE(58);CASE(59);
            CASE(60);CASE(61);CASE(62);CASE(63);CASE(64);CASE(65);CASE(66);CASE(67);CASE(68);CASE(69);
            CASE(70);CASE(71);CASE(72);CASE(73);CASE(74);CASE(75);CASE(76);CASE(77);CASE(78);CASE(79);
            CASE(80);CASE(81);CASE(82);CASE(83);CASE(84);CASE(85);CASE(86);CASE(87);CASE(88);CASE(89);
            CASE(90);CASE(91);CASE(92);CASE(93);CASE(94);CASE(95);CASE(96);CASE(97);CASE(98);CASE(99);
            CASE(100);CASE(101);CASE(102);CASE(103);CASE(104);CASE(105);CASE(106);CASE(107);CASE(108);CASE(109);
            CASE(110);CASE(111);CASE(112);CASE(113);CASE(114);CASE(115);CASE(116);CASE(117);CASE(118);CASE(119);
            CASE(120);CASE(121);CASE(122);CASE(123);CASE(124);CASE(125);CASE(126);CASE(127);CASE(128);CASE(129);
            CASE(130);CASE(131);CASE(132);CASE(133);CASE(134);CASE(135);CASE(136);CASE(137);CASE(138);CASE(139);
            CASE(140);CASE(141);CASE(142);CASE(143);CASE(144);CASE(145);CASE(146);CASE(147);CASE(148);CASE(149);
            CASE(150);CASE(151);CASE(152);CASE(153);CASE(154);CASE(155);CASE(156);CASE(157);CASE(158);CASE(159);
            CASE(160);CASE(161);CASE(162);CASE(163);CASE(164);CASE(165);CASE(166);CASE(167);CASE(168);CASE(169);
            CASE(170);CASE(171);CASE(172);CASE(173);CASE(174);CASE(175);CASE(176);CASE(177);CASE(178);CASE(179);
            CASE(180);CASE(181);CASE(182);CASE(183);CASE(184);CASE(185);CASE(186);CASE(187);CASE(188);CASE(189);
            CASE(190);CASE(191);CASE(192);CASE(193);CASE(194);CASE(195);CASE(196);CASE(197);CASE(198);CASE(199);
            CASE(200);CASE(201);CASE(202);CASE(203);CASE(204);CASE(205);CASE(206);CASE(207);CASE(208);CASE(209);
            CASE(210);CASE(211);CASE(212);CASE(213);CASE(214);CASE(215);CASE(216);CASE(217);CASE(218);CASE(219);
            CASE(220);CASE(221);CASE(222);CASE(223);CASE(224);CASE(225);CASE(226);CASE(227);CASE(228);CASE(229);
            CASE(230);CASE(231);CASE(232);CASE(233);CASE(234);CASE(235);CASE(236);CASE(237);CASE(238);CASE(239);
            CASE(240);CASE(241);CASE(242);CASE(243);CASE(244);CASE(245);CASE(246);CASE(247);CASE(248);CASE(249);
            CASE(250);CASE(251);CASE(252);CASE(253);CASE(254);CASE(255);
#undef CASE
            default: break;
        }
        AvmAssert(false); // How did we get here?
        return val;
    }
}
#endif
