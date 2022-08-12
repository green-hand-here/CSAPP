#if 0
      Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
#endif
//1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */


// a^b == (a | b) & (~a | ~b)
//     == ~(~a & ~b) & ~(a & b)
//     == (a & ~b)|(~a & b)
int bitXor(int x, int y) {
	return ~(~x&~y)&~(x&y);
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

// 注意 x = -1 = ~0x0 的情况
// !!-1 = 1
// !!0 = 0
int isTmax(int x) {
  return !((~(x+1) ^ x)) & !!(x+1);
}
/*
 * allOddBits - return 1 if all odd-numbered(奇数) bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */

// 注意 : x == y => !(x ^ y)
// 1. 偶数位 置0
// 2. 和 y 异或
int allOddBits(int x) {
  // int mask = 0xAAAAAAAA;
  int A = 0xA;
  int AA = A | (A << 4);
  int AAAA = AA | (AA << 8);
  int mask = AAAA | (AAAA << 16);
  return !((x & mask) ^ mask);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */

// -x = ~x + 1
int negate(int x) {
  return (~x + 1);
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

// 注意 x 为负数的情况
int isAsciiDigit(int x) {
  int TMin = 1 << 31;
  // (x - 0x30 >= 0) && (0x39 - x) >=0
  return !((x + ~0x30 + 1) & TMin) & !((0x39 + ~x + 1) & TMin);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */

// x 为 true, return y
// x 为 false, return z
int conditional(int x, int y, int z) {
  // 方法 1 : 
  // x == 0, mask = 0x0, return ~mask & z
  // x != 0, mask = ~0x0, return mask & y
  int mask = ((!!x) << 31) >> 31;
  return (~mask & z) | (mask & y);

  // 方法 2 : 
  // x == 0, mask = ~0x0, return mask & z
  // x != 0, mask = 0x0, return ~mask & y
  // int mask = ~(!x) + 1;
  // return (~mask & y) | (mask & z);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */

// 直接用 x - y 可能会爆 int, 需要判断 x, y 符号
int isLessOrEqual(int x, int y) {
  int sign_x = (x >> 31) & 0x1;
  int sign_y = (y >> 31) & 0x1;
  // x, y 异号可能溢出, 需要单独考虑异号情况
  // 情况一 : x == y, 返回 1
  int c1 = !(x ^ y);
  // 情况二 : x为+, y为-, 返回 0
  int c2 = !(~sign_x & sign_y);
  // 情况三 : x为-, y为+, 返回 1
  int c3 = sign_x & ~sign_y;
  // 情况四 : x, y 同号, 且 y - x > 0, 返回 1
  int c4 = !((y + ~x + 1) >> 31);
  // 不满足情况二时, 只要满足情况三和情况四其中一种即可
  return c1 | (c2 & (c3 | c4));
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
  int negX = ~x + 1;
  int sign = ((negX | x) >> 31);
  // 问题 : 为什么这里不能 & 0x1 ?
  return sign + 1;
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

// if(x == 0){
//   return 1;
// } else {
//    x > 0
//       1 + highBit // 0100
//    x < 0
//       111101101
// }
int howManyBits(int x) {
  // get the highest bit without sign bit
  int flag = x >> 31;
  x = (~(flag) & x) | (flag & (~x));
  // 二分法
  int b16, b8, b4, b2, b1, b0;
  // 如果高16位不为0, 则 b16 = 16, 然后 x 至少有16位, 并移位查看高16位情况
  // 如果高16位为 0, 则 x 不移位
  b16 = !!(x >> 16) << 4;
  x >>= b16;

  b8 = !!(x >> 8) << 3;
  x >>= b8;

  b4 = !!(x >> 4) << 2;
  x >>= b4;

  b2 = !!(x >> 2) << 1;
  x >>= b2;

  b1 = !!(x >> 1);
  x >>= b1;

  b0 = x;
  // add the sign bit
  return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}
//float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point(单精度浮点数) values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // expr, sign, frac
  unsigned sign = (uf >> 31) & 0x1;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;
  
  // 0
  if(exp == 0 && frac == 0){
    return uf;
  }

  // infinity or NaN
  if(exp == 0xFF){
    return uf;
  }

  // denormalize
  if(exp == 0){
    frac <<= 1; // f * 2
    return (sign << 31) | frac;
  }

  // normalize 
  exp++; // f * 2
  return (sign << 31) | (exp << 23) | frac;
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
  // exp, sign, frac
  unsigned sign = (uf >> 31) & 0x1;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;

  // 0
  if(exp == 0 && frac == 0){
    return 0;
  }

  // infinity or Nan
  if(exp == 0xFF){
    return (1 << 31);
  }

  // denormalize
  if(exp == 0){
    // E = 1 - 127 = -126
    // frac < 1
    // 结果太小了, 返回 0
    return 0;
  }

  // normalize
  int E = exp - 127;
  int M = frac | (1 << 23); // M = 1.XXXX
  // M * 2^E
  if(E > 31){ // int爆掉
    return 1 << 31;
  }else if(E < 0){
    return 0;
  }

  if(E >= 23){
    M <<= (E - 23);
  }else {
    M >>= (23 - E);
  }

  // 负数
  if(sign){
    return ~M + 1;
  }
  
  return M;
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
  //              lowerbound                upperbound
  // denormalize  2^(-126-23)= 2^(-149)   2^(-126)*(1-ℇ)
  // normalize    2^(-126)          2^(254-127)*(2-ℇ) = 2^127 * (2-ℇ)
  if(x < -149){
    return 0;
  }else if(x < -126){
    // 2^(-126) * M = 2^x
    int shift = 23 + (x + 126);
    return 1 << shift;
  }else if(x <= 127){
    int exp = x + 127;
    return exp << 23;
  }else {
    return (0xFF) << 23;
  }
}
