use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "fma.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// fma.dectest -- decimal fused multiply add                          --
// copyright (c) ibm corporation, 1981, 2007.  all rights reserved.   --
//----------------------------------------------------------------------
// please see the document "general decimal arithmetic testcases"     --
// at http://www2.hursley.ibm.com/decimal for the description of      --
// these testcases.                                                   --
//                                                                    --
// these testcases are experimental ('beta' versions), and they       --
// may contain errors.  they are offered on an as-is basis.  in       --
// particular, achieving the same results as the tests here is not    --
// a guarantee that an implementation complies with any standard      --
// or specification.  the tests are not exhaustive.                   --
//                                                                    --
// please send comments, suggestions, and corrections to the author:  --
//   mike cowlishaw, ibm fellow                                       --
//   ibm uk, po box 31, birmingham road, warwick cv34 5jl, uk         --
//   mfc@uk.ibm.com                                                   --
//----------------------------------------------------------------------
// version: 2.55
use precision 9;
use rounding HALF_UP;
// these tests comprese three parts:
//   1. sanity checks and other three-operand tests (especially those
//      where the fused operation makes a difference)
//   2. multiply tests (third operand is neutral zero [0e+emax])
//   3. addition tests (first operand is 1)
// the multiply and addition tests are extensive because fma may have
// its own dedicated multiplication or addition routine(s), and they
// also inherently check the left-to-right properties.
// sanity checks
// non-integer exacts
// cases where result is different from separate multiply + add; each
// is preceded by the result of unfused multiply and add
// [this is about 20% of all similar  cases in general]
//               888565290   1557.96930  -86087.7578  -> 1.38435735e+12
//             -85519342.9    735155419     42010431  -> -6.28700084e+16
//                -98025.5  -294603.472   10414348.2  -> 2.88890669e+10
//              5967627.39   83526540.6   498494.810  -> 4.98455271e+14
//               3456.9433    874.39518   197866.615  ->  3220601.18
//              62769.8287   2096.98927    48.420317  ->  131627705
//               -68.81500   59961113.9     -8988862  -> -4.13521291e+9
//              2126341.02   63491.5152    302427455  -> 1.35307040e+11
// infinite combinations
// triple nan propagation
// first snan wins (consider qnan from earlier snan being
// overridden by an snan in third operand)
// multiplication tests ------------------------------------------------
// sanity checks (as base, above)
{
	use precision 6;
	// 1999.12.21: next one is a edge case if intermediate longs are used
}
{
	use precision 15;
}
{
	use precision 30;
}
{
	use precision 9;
	//---
	// zeros, etc.
	// examples from decarith multiply
	// test some intermediate lengths
}
{
	use precision 9;
}
{
	use precision 8;
}
{
	use precision 7;
}
{
	use precision 9;
}
{
	use precision 8;
}
{
	use precision 7;
	// test some more edge cases and carries
}
{
	use precision 33;
	// test some more edge cases without carries
}
{
	use precision 9;
	// test some cases that are close to exponent overflow/underflow
	// long operand triangle
}
{
	use precision 33;
}
{
	use precision 32;
}
{
	use precision 31;
}
{
	use precision 30;
}
{
	use precision 29;
}
{
	use precision 28;
}
{
	use precision 27;
}
{
	use precision 26;
}
{
	use precision 25;
}
{
	use precision 24;
}
{
	use precision 23;
}
{
	use precision 22;
}
{
	use precision 21;
}
{
	use precision 20;
}
{
	use precision 19;
}
{
	use precision 18;
}
{
	use precision 17;
}
{
	use precision 16;
}
{
	use precision 15;
}
{
	use precision 14;
}
{
	use precision 13;
}
{
	use precision 12;
}
{
	use precision 11;
}
{
	use precision 10;
}
{
	use precision 9;
}
{
	use precision 8;
}
{
	use precision 7;
}
{
	use precision 6;
}
{
	use precision 5;
}
{
	use precision 4;
}
{
	use precision 3;
}
{
	use precision 2;
}
{
	use precision 1;
	// test some edge cases with exact rounding
}
{
	use precision 9;
	// fastpath breakers
}
{
	use precision 29;
	// tryzeros cases
}
{
	use precision 7;
	{
		use rounding HALF_UP;
		// mixed with zeros
		{
			use precision 9;
			// specials
			// propagating nans
			// overflow and underflow tests .. note subnormal results
			// signs
			// 'subnormal' boundary (all hard underflow or overflow in base arithemtic)
		}
		{
			use precision 9;
			// [no equivalent of 'subnormal' for overflow]
			// 'subnormal' test edge condition at higher precisions
			// test subnormals rounding
		}
		{
			use precision 5;
			{
				use rounding HALF_EVEN;
				// squares
				// cubes
				// test derived from result of 0.099 ** 999 at 15 digits with unlimited exponent
				{
					use precision 19;
					// long operand overflow may be a different path
				}
				{
					use precision 3;
					// check for double-rounded subnormals
				}
				{
					use precision 5;
					// now explore the case where we get a normal result with underflow
				}
				{
					use precision 16;
					{
						use rounding HALF_UP;
						// prove operands are exact
						// the next rounds to nmin
						// examples from sql proposal (krishna kulkarni)
					}
					{
						use rounding HALF_UP;
						// null tests
						// addition tests ------------------------------------------------------
						{
							use precision 9;
							{
								use rounding HALF_UP;
								// [first group are 'quick confidence check']
								// some carrying effects
								// symmetry:
								// same, higher precision
								{
									use precision 15;
									// examples from decarith
									// zero preservation
								}
								{
									use precision 6;
									// some funny zeros [in case of bad signum]
								}
								{
									use precision 9;
									// some carries
									// more lhs swaps
									// more rhs swaps
									// related
									// [some of the next group are really constructor tests]
									// try borderline precision, with carries, etc.
								}
								{
									use precision 15;
									//             123456789012345      123456789012345      1 23456789012345
									// and some more, including residue effects and different roundings
								}
								{
									use precision 9;
									{
										use rounding HALF_UP;
									}
									{
										use rounding HALF_EVEN;
										// critical few with even bottom digit...
										// input preparation tests (operands should not be rounded)
										{
											use precision 3;
											{
												use rounding HALF_UP;
											}
											{
												use rounding HALF_DOWN;
												// 1 in last place tests
											}
											{
												use rounding HALF_UP;
												// some more cases where fma  1  ing 0 affects the coefficient
												{
													use precision 9;
													// which simply follow from these cases ...
													// tryzeros cases
												}
												{
													use precision 7;
													{
														use rounding HALF_UP;
														// a curiosity from jsr 13 testing
													}
													{
														use rounding HALF_DOWN;
														{
															use precision 10;
														}
														{
															use precision 6;
															{
																use rounding HALF_UP;
																{
																	use precision 10;
																}
																{
																	use precision 6;
																	{
																		use rounding HALF_EVEN;
																		{
																			use precision 10;
																		}
																		{
																			use precision 6;
																			// ulp replacement tests
																		}
																		{
																			use precision 9;
																			// negative ulps
																			// negative ulps
																			// long operands
																		}
																		{
																			use precision 9;
																		}
																		{
																			use precision 15;
																			// still checking
																			// verify a query
																		}
																		{
																			use precision 16;
																			// and using decimal64 bounds...
																		}
																		{
																			use precision 16;
																			// some more residue effects with extreme rounding
																		}
																		{
																			use precision 9;
																			{
																				use rounding HALF_UP;
																			}
																			{
																				use rounding HALF_EVEN;
																			}
																			{
																				use rounding HALF_DOWN;
																			}
																			{
																				use rounding FLOOR;
																			}
																			{
																				use rounding CEILING;
																			}
																			{
																				use rounding HALF_UP;
																			}
																			{
																				use rounding HALF_EVEN;
																			}
																			{
																				use rounding HALF_DOWN;
																			}
																			{
																				use rounding FLOOR;
																			}
																			{
																				use rounding CEILING;
																			}
																			{
																				use rounding HALF_UP;
																			}
																			{
																				use rounding HALF_EVEN;
																			}
																			{
																				use rounding HALF_DOWN;
																			}
																			{
																				use rounding FLOOR;
																			}
																			{
																				use rounding CEILING;
																			}
																			{
																				use rounding HALF_UP;
																			}
																			{
																				use rounding HALF_EVEN;
																			}
																			{
																				use rounding HALF_DOWN;
																			}
																			{
																				use rounding FLOOR;
																			}
																			{
																				use rounding CEILING;
																			}
																			{
																				use rounding HALF_UP;
																			}
																			{
																				use rounding HALF_EVEN;
																			}
																			{
																				use rounding HALF_DOWN;
																			}
																			{
																				use rounding FLOOR;
																			}
																			{
																				use rounding CEILING;
																			}
																			{
																				use rounding HALF_UP;
																			}
																			{
																				use rounding HALF_EVEN;
																			}
																			{
																				use rounding HALF_DOWN;
																			}
																			{
																				use rounding FLOOR;
																			}
																			{
																				use rounding CEILING;
																				// long operand triangle
																			}
																			{
																				use rounding HALF_UP;
																				{
																					use precision 33;
																				}
																				{
																					use precision 32;
																				}
																				{
																					use precision 31;
																				}
																				{
																					use precision 30;
																				}
																				{
																					use precision 29;
																				}
																				{
																					use precision 28;
																				}
																				{
																					use precision 27;
																				}
																				{
																					use precision 26;
																				}
																				{
																					use precision 25;
																				}
																				{
																					use precision 24;
																				}
																				{
																					use precision 23;
																				}
																				{
																					use precision 22;
																				}
																				{
																					use precision 21;
																				}
																				{
																					use precision 20;
																				}
																				{
																					use precision 19;
																				}
																				{
																					use precision 18;
																				}
																				{
																					use precision 17;
																				}
																				{
																					use precision 16;
																				}
																				{
																					use precision 15;
																				}
																				{
																					use precision 14;
																				}
																				{
																					use precision 13;
																				}
																				{
																					use precision 12;
																				}
																				{
																					use precision 11;
																				}
																				{
																					use precision 10;
																				}
																				{
																					use precision 9;
																				}
																				{
																					use precision 8;
																				}
																				{
																					use precision 7;
																				}
																				{
																					use precision 6;
																				}
																				{
																					use precision 5;
																				}
																				{
																					use precision 4;
																				}
																				{
																					use precision 3;
																				}
																				{
																					use precision 2;
																				}
																				{
																					use precision 1;
																					// more zeros, etc.
																					{
																						use rounding HALF_UP;
																						{
																							use precision 9;
																							// specials
																							// propagating nans
																							// overflow, underflow and subnormal tests
																						}
																						{
																							use precision 9;
																						}
																						{
																							use precision 3;
																						}
																						{
																							use precision 3;
																							// next is rounded to nmin
																							// next is rounded to nmin
																							// some non-zero subnormal fma  1  s
																							// negatives...
																							// some 'real' numbers
																						}
																						{
																							use precision 8;
																						}
																						{
																							use precision 7;
																						}
																						{
																							use precision 6;
																							// now the case where we can get underflow but the result is normal
																							// [note this can't happen if the operands are also bounded, as we
																							// cannot represent 1e-399, for example]
																						}
																						{
																							use precision 16;
																							{
																								use rounding HALF_UP;
																								// here we explore the boundary of rounding a subnormal to nmin
																								// check for double-rounded subnormals
																								{
																									use precision 5;
																									// add: lhs and rhs 0
																									// add: lhs >> rhs and vice versa
																									// add: lhs + rhs fma  1  ition carried out
																									// and for round down full and subnormal results
																								}
																								{
																									use precision 16;
																									{
																										use rounding CEILING;
																										{
																											use precision 7;
																											// subnormal boundary
																											// tests based on gunnar degnbol's edge case
																										}
																										{
																											use precision 15;
																											{
																												use rounding HALF_UP;
																												{
																													use precision 16;
																													// more gd edge cases, where difference between the unadjusted
																													// exponents is larger than the maximum precision and one side is 0
																												}
																												{
																													use precision 15;
																													{
																														use rounding HALF_UP;
																														// same, precision 16..
																														{
																															use precision 16;
																															// same, reversed 0
																															// same, es on the 0
																															// next four flag rounded because the 0 extends the result
																															// sum of two opposite-sign operands is exactly 0 and floor => -0
																														}
																														{
																															use precision 16;
																															{
																																use rounding HALF_UP;
																																// exact zeros from zeros
																																// inexact zeros
																																// some exact zeros from non-zeros
																															}
																															{
																																use rounding HALF_DOWN;
																																// exact zeros from zeros
																																// inexact zeros
																																// some exact zeros from non-zeros
																															}
																															{
																																use rounding HALF_EVEN;
																																// exact zeros from zeros
																																// inexact zeros
																																// some exact zeros from non-zeros
																																// exact zeros from zeros
																																// inexact zeros
																																// some exact zeros from non-zeros
																																// exact zeros from zeros
																																// inexact zeros
																																// some exact zeros from non-zeros
																															}
																															{
																																use rounding CEILING;
																																// exact zeros from zeros
																																// inexact zeros
																																// some exact zeros from non-zeros
																																// and the extra-special ugly case; unusual minuses marked by -- *
																															}
																															{
																																use rounding FLOOR;
																																// exact zeros from zeros
																																// inexact zeros
																																// some exact zeros from non-zeros
																																// bigdecimal problem testcases 2006.01.23
																																{
																																	use precision 16;
																																}
																																{
																																	use precision 7;
																																}
																																{
																																	use precision 6;
																																}
																																{
																																	use precision 5;
																																}
																																{
																																	use precision 4;
																																}
																																{
																																	use precision 3;
																																}
																																{
																																	use precision 2;
																																}
																																{
																																	use precision 1;
																																	{
																																		use rounding HALF_EVEN;
																																		{
																																			use precision 7;
																																		}
																																		{
																																			use precision 6;
																																		}
																																		{
																																			use precision 5;
																																		}
																																		{
																																			use precision 4;
																																		}
																																		{
																																			use precision 3;
																																		}
																																		{
																																			use precision 2;
																																		}
																																		{
																																			use precision 1;
																																		}
																																		{
																																			use precision 7;
																																		}
																																		{
																																			use precision 6;
																																		}
																																		{
																																			use precision 5;
																																		}
																																		{
																																			use precision 4;
																																		}
																																		{
																																			use precision 3;
																																		}
																																		{
																																			use precision 2;
																																		}
																																		{
																																			use precision 1;
																																			{
																																				use rounding HALF_UP;
																																				// examples from sql proposal (krishna kulkarni)
																																				//----------------------------------------------------------------------
																																				// same as above, using decimal64 default parameters                  --
																																				//----------------------------------------------------------------------
																																				{
																																					use precision 16;
																																					{
																																						use rounding HALF_EVEN;
																																						// [first group are 'quick confidence check']
																																						// some carrying effects
																																						// symmetry:
																																						// examples from decarith
																																						// from above
																																						// some funny zeros [in case of bad signum]
																																						// some carries
																																						// more lhs swaps
																																						// more rhs swaps
																																						// related
																																						// [some of the next group are really constructor tests]
																																						// try borderline precision, with carries, etc.
																																						//                    1234567890123456      1234567890123456      1 234567890123456
																																						// and some more, including residue effects and different roundings
																																					}
																																					{
																																						use rounding HALF_UP;
																																					}
																																					{
																																						use rounding HALF_EVEN;
																																						// critical few with even bottom digit...
																																						// 1 in last place tests
																																					}
																																					{
																																						use rounding HALF_EVEN;
																																						// some more cases where fma  1  ing 0 affects the coefficient
																																						// which simply follow from these cases ...
																																						// tryzeros cases
																																						// ulp replacement tests
																																						// negative ulps
																																						// negative ulps
																																						// long operands
																																						// verify a query
																																						// and using decimal64 bounds...
																																						// more zeros, etc.
																																					}
																																					{
																																						use rounding HALF_EVEN;
																																						// specials
																																						// propagating nans
																																						// now the case where we can get underflow but the result is normal
																																						// [note this can't happen if the operands are also bounded, as we
																																						// cannot represent 1e-399, for example]
																																						// here we explore the boundary of rounding a subnormal to nmin
																																						// check overflow edge case
																																						//               1234567890123456
																																						// and for round down full and subnormal results
																																					}
																																					{
																																						use rounding CEILING;
																																						// tests based on gunnar degnbol's edge case
																																					}
																																					{
																																						use rounding HALF_EVEN;
																																						// more gd edge cases, where difference between the unadjusted
																																						// exponents is larger than the maximum precision and one side is 0
																																						// same, reversed 0
																																						// same, es on the 0
																																						// next four flag rounded because the 0 extends the result
																																						// sum of two opposite-sign operands is exactly 0 and floor => -0
																																					}
																																					{
																																						use rounding HALF_UP;
																																						// exact zeros from zeros
																																						// inexact zeros
																																						// some exact zeros from non-zeros
																																					}
																																					{
																																						use rounding HALF_DOWN;
																																						// exact zeros from zeros
																																						// inexact zeros
																																						// some exact zeros from non-zeros
																																					}
																																					{
																																						use rounding HALF_EVEN;
																																						// exact zeros from zeros
																																						// inexact zeros
																																						// some exact zeros from non-zeros
																																						// exact zeros from zeros
																																						// inexact zeros
																																						// some exact zeros from non-zeros
																																						// exact zeros from zeros
																																						// inexact zeros
																																						// some exact zeros from non-zeros
																																					}
																																					{
																																						use rounding CEILING;
																																						// exact zeros from zeros
																																						// inexact zeros
																																						// some exact zeros from non-zeros
																																						// and the extra-special ugly case; unusual minuses marked by -- *
																																					}
																																					{
																																						use rounding FLOOR;
																																						// exact zeros from zeros
																																						// inexact zeros
																																						// some exact zeros from non-zeros
																																						// examples from sql proposal (krishna kulkarni)
																																						AddTestCase('fmax361705:p16 r:FLOOR (130e-2 - 120e-2)', 0.10, 130e-2 - 120e-2);
																																						AddTestCase('fmax361706:p16 r:FLOOR (130e-2 - 12e-1)', 0.10, 130e-2 - 12e-1);
																																						AddTestCase('fmax361707:p16 r:FLOOR (130e-2 - 1e0)', 0.30, 130e-2 - 1e0);
																																						AddTestCase('fmax361708:p16 r:FLOOR (1e2 - 1e4)', -9.9e+3, 1e2 - 1e4);
																																						// gappy coefficients; check residue handling even with full coefficient gap
																																					}
																																					{
																																						use rounding HALF_EVEN;
																																						// widening second argument at gap
																																						//                               90123456
																																					}
																																					{
																																						use rounding HALF_EVEN;
																																						// far-out residues (full coefficient gap is 16+15 digits)
																																						// payload decapitate x3
																																						{
																																							use precision 5;
																																							// null tests
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
test();
