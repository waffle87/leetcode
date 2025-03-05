// 89. Gray Code
#include "leetcode.h"

/*
 * an n-bit gray code sequence is a sequence of '2^n' integers where every
 * integer is in the inclusive range '[0, 2^n - 1]', the first integer is 0, an
 * integer appears no more than once in the sequence, the binary representation
 * of every pair of adjacent integers differs by exactly one bit and the binary
 * representation of the first and last integers differs by exactly one bit.
 * given an integer 'n', return any valid n-bit gray code sequence
 */

int convert(int n) { return n ^ (n >> 1); }

int *grayCode(int n, int *returnSize) {
  int base = 1;
  for (int i = 0; i < n; i++)
    base *= 2;
  *returnSize = base;
  int *ans = (int *)calloc(base, sizeof(int));
  for (int i = 0; i < base; i++)
    ans[i] = convert(i);
  return ans;
}

int main() {
  int rs1, *gc1 = grayCode(2, &rs1);
  int rs2, *gc2 = grayCode(1, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d", gc1[i]); // expect: 0 1 3 2
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d", gc2[i]); // expect: 0 1
  printf("\n");
  free(gc1);
  free(gc2);
}
