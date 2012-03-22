
/*
This file contains XML definitions of instruction snippets.

XML is often gross, but XML literals in actionscript are
expressive and we don't have to write an XML parser.
*/

var subtract =
<template>
	<coerce_d val=''/>
	<coerce_d val=''/>
	<multiply lhs='' rhs=''/>
</template>

<template>
	<args><x/><y/>
	<subtract>
		<coerce_d val=''/>
		<coerce_d val=''/>
	</subtract>
</template>

// javascript-like
fatsub(x, y) {
	return sub(coerce_d(x), coerce_d(y))
}

// scheme-like
(define (fatsub x y) (sub (coerce_d x) (coerce_d y)))
