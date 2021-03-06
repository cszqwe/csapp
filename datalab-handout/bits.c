/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int a = x & ~y;
  int b = ~x & y;
  return ~(~a & ~b);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // x + 1 + x should be all ones
  // x + 1 should not be zero
  return (!(~(x + 1 + x))) & (!(!(x+1)))  ;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int tmp = 0xAA;
  int t0 = x & tmp;
  int t1 = x >> 8 & t0;
  int t2 = x >> 16 & t1;
  int t3 = x >> 24 & t2;
  return !(t3 ^ tmp);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // only look at last 6 digits
  int tmp1 = !(x >> 6);
  // have 11xxxx
  int tmp2 = !((x & 0x30) ^ 0x30);
  // after +6, still have 11xxxx
  int tmp3 = !(((x+6) & 0x30) ^ 0x30);
  return tmp1 & tmp2 & tmp3;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int tmp1 = ~(!x)+1;
  int tmp2 = ~tmp1 & y;
  int tmp3 = tmp1 & z; 
  return tmp2 | tmp3;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int nx = ~x +1;
  int tmp1 = y + nx;
  // tmp1 might overflow, also need to check the sign of y and x
  int tmp2 = (!(y >> 31)) & (x >> 31);
  int tmp3 = (y >> 31) & (!(x >> 31));
  return (!tmp3 & (!(tmp1 >> 31 & 1))) | tmp2;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int tmp1 = x | (x >> 16);
  int tmp2 = tmp1 | (tmp1 >> 8);
  int tmp3 = tmp2 | (tmp2 >> 4);
  int tmp4 = tmp3 | (tmp3 >> 2);
  int tmp5 = tmp4 | (tmp4 >> 1);
  return (tmp5 & 1) ^ 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // if x < 0, not x
  int isNeg = !(!(x & 1 << 31));
  int isNegMask = ~isNeg + 1; // if is neg, isNegMask = 0xFFFFFFFF
  int x1 = x ^ isNegMask; // if is neg, x would become not x

  int tmp1 = x1 >> 16;
  int allZero1 = !tmp1;
  int mask1 = ~allZero1 + 1; // mask = 0xFFFFFF if allZero, 0x00 otherwise
  // if allZero, ans += 16 
  int ans1 = 16 & mask1;
  // determine left part or right part
  // if allZero, right part, else left part
  int x2 = x1 << (16 & mask1);
  
  int tmp2 = x2 >> 24;
  int allZero2 = !tmp2;
  int mask2 = ~allZero2 + 1;
  int ans2 = ans1 + (8 & mask2);
  int x3 = x2 << (8 & mask2);

  int tmp3 = x3 >> 28;
  int allZero3 = !tmp3;
  int mask3 = ~allZero3 + 1;
  int ans3 = ans2 + (4 & mask3);
  int x4 = x3 << (4 & mask3);

  int tmp4 = x4 >> 30;
  int allZero4 = !tmp4;
  int mask4 = ~allZero4 + 1;
  int ans4 = ans3 + (2 & mask4);
  int x5 = x4 << (2 & mask4);

  int tmp5 = x5 >> 31;
  int allZero5 = !tmp5;
  int mask5 = ~allZero5 + 1;
  int ans5 = ans4 + (1 & mask5);
  int x6 = x5 << (1 & mask5);

  int tmp6 = x6 >> 31;
  int allZero6 = !tmp6;
  int mask6 = ~allZero6 + 1;
  int ans6 = ans5 + (1 & mask6);

  int ans7 = 32 + (~ans6 + 1);
  int ans8 = ans7 + 1; //!(originX >> 31) - !(originX);
  //printf("debug x:%d isNeg:%d isNegMask:%d x1:%d ans1:%d ans2:%d ans3:%d tmp2:%d allZero2:%d mask2:%d ans6:%d\n", x, isNeg, isNegMask, x1, ans1, ans2, ans3, tmp2, allZero2, mask2, ans6);
  return ans8;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int exp = (uf & 0x7f800000) >> 23;
  int sign = uf & (1 << 31);
  if (exp == 0) {
    // -inf
    return uf << 1 | sign;
  }
  if (exp == 255) {
    // inf
    return uf;
  }
  exp++;
  if (exp == 255) {
    // inf
    return 0x7f800000 | sign;
  }
  return (exp << 23) | (uf & 0x807fffff);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int sign = uf & (1 << 31);
  int fraction = (uf & 0x7fffff) | 0x00800000;
  int exp = ((uf & 0x7f800000) >> 23) - 127;
  //printf("debug %d\n", exp);
  if (!(uf & 0x7fffffff)) {
    return 0;
  }
  if (exp > 31) {
    return 0x80000000;
  }
  if (exp < 0) {
    return 0;
  }
  if (exp > 23) {
    fraction <<= (exp - 23);
  }
  else {
    fraction >>= (23 - exp);
  }
  if ((fraction >> 31) == sign >> 31) {
    return fraction;
  }
  if (!sign) {
    return 0x80000000;
  }
  return ~fraction + 1;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  int exp = x + 127;
  if (exp < 0) {
    return 0;
  }
  if (exp > 255) {
    return 0xff << 23;
  }
  return exp << 23;
}
