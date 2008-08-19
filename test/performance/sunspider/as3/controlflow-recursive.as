/*
 Copyright (C) 2007 Apple Inc.  All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
*/
package {
	
	var _sunSpiderStartDate:int = getTimer();

	// The Computer Language Shootout
	// http://shootout.alioth.debian.org/
	// contributed by Isaac Gouy

	function ack(m:int, n:int):int{
	   if (m==0) { return n+1; }
	   if (n==0) { return ack(m-1,1); }
	   return ack(m-1, ack(m,n-1) );
	}

	function fib(n:Number):Number {
	    if (n < 2){ return 1; }
	    return fib(n-2) + fib(n-1);
	}

	function tak(x:Number,y:Number,z:Number):Number {
	    if (y >= x) return z;
	    return tak(tak(x-1,y,z), tak(y-1,z,x), tak(z-1,x,y));
	}

	for ( var i:int = 3; i <= 5; i++ ) {
	    ack(3,i);
	    fib(17.0+i);
	    tak(3*i+3,2*i+2,i+1);
	}


	var _sunSpiderInterval:Number = getTimer() - _sunSpiderStartDate;

	print("metric controlflow-recursive-as3 " + _sunSpiderInterval);

}
