// 190. Reverse Bits
#include "leetcode.h"
#include <stdio.h>

/*
 * reverse the bitof a given 32 bits unsigned integer.
 */

uint32_t reverseBits(uint32_t n) {
  n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
  n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
  n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
  n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
  n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
  return n;
}

int main() {
  uint32_t n1 = 0b00000010100101000001111010011100;
  uint32_t n2 = 0b11111111111111111111111111111101;
  uint32_t r1 = reverseBits(n1);
  uint32_t r2 = reverseBits(n2);
  printf("%d (", r1); // expect: 964176192 (00111001011110000010100101000000)
  while (r1) {
    printf("%d", r1 & 1 ? 1 : 0);
    r1 >>= 1;
  }
  printf(")\n");
  printf("%d (", r2); // expect: 3221225471 (10111111111111111111111111111111)
  while (r2) {
    printf("%d", r2 & 1 ? 1 : 0);
    r2 >>= 1;
  }
  printf(")\n");
}
