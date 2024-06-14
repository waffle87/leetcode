// 2429. Minimize XOR
#include "leetcode.h"

/*
 * given two positive integers 'num1' and 'num2', find the positive integer 'x'
 * such that 'x' has the same number of set bits as 'num2', and the value 'x ^
 * num1' is minimal. note that 'xor' is the bitwise xor operator. return the
 * integer 'x'. the test cases are generated such that 'x' is uniqueley
 * determined. the number of set bits of an integer is the number of 1's in its
 * binary representation
 */

int minimizeXor(int num1, int num2) {
  int bit1 = __builtin_popcount(num1);
  int bit2 = __builtin_popcount(num2);
  if (bit1 == bit2)
    return num1;
  int ans = num1;
  for (int i = 0; i < 32; i++) {
    if (!(((uint32_t)1 << i) & num1) && bit2 > bit1) {
      ans ^= 1 << i;
      bit1++;
    }
    if ((((uint32_t)1 << i) & num1) && bit2 < bit1) {
      ans ^= 1 << i;
      bit1--;
    }
  }
  return ans;
}

int main() {
  printf("%d\n", minimizeXor(3, 5));  // expect: 3
  printf("%d\n", minimizeXor(1, 12)); // expect: 3
}
