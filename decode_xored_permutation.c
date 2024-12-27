// 1734. Decode XORed Permutation
#include "leetcode.h"

/*
 * there is a positive integer array 'perm' that is a permutation of the first
 * 'n' positive integers, where 'n' is always odd. it was encoded into another
 * integer array 'encoded' of length 'n - 1', such that 'encoded[i] = perm[i] ^
 * perm[i + 1]'. given the 'encoded' array, return the original array 'perm'. it
 * is guaranteed that the answer exists and is unique
 */

int *decode(int *encoded, int encodedSize, int *returnSize) {
  *returnSize = encodedSize + 1;
  int *ans = (int *)malloc(*returnSize * sizeof(int)), all = 0;
  for (int i = 0; i < *returnSize; i++)
    all ^= i + 1;
  int first = all;
  for (int i = 1; i < encodedSize; i += 2)
    first ^= encoded[i];
  ans[0] = first;
  for (int i = 0; i < encodedSize; i++)
    ans[i + 1] = ans[i] ^ encoded[i];
  return ans;
}

int main() {
  int e1[] = {3, 1}, e2[] = {6, 5, 4, 6}, rs1, rs2;
  int *d1 = decode(e1, ARRAY_SIZE(e1), &rs1);
  int *d2 = decode(e2, ARRAY_SIZE(e2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", d1[i]); // expect: 1 2 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", d2[i]); // expect: 2 4 1 5 3
  printf("\n");
  free(d1), free(d2);
}
