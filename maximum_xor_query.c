// 1829. Maximum XOR for Each Query
#include "leetcode.h"

/*
 * you are given a sorted array 'nums' of 'n' non negative integers and an
 * integer 'maximumBit'. you want to perform the following query 'n' times: find
 * a non-negative integer 'k < 2^maximumBit' such that 'nums[0] ^ nums[1] ^ ...
 * ^ nums[n]' is maximised. 'k' is the answer to the i'th query. remove the last
 * element from the current array 'nums'. return an array 'answer' where
 * 'answer[i]' is the answer to the i'th query.
 */

int *getMaximumXor(int *nums, int numsSize, int maximumBit, int *returnSize) {
  int *ans = (int *)malloc(numsSize * sizeof(int));
  *returnSize = numsSize;
  int max = pow(2, maximumBit) - 1;
  for (int i = 1; i < numsSize; i++)
    nums[i] ^= nums[i - 1];
  for (int i = 0; i < numsSize; i++)
    ans[i] = nums[numsSize - i - 1] ^ max;
  return ans;
}

int main() {
  int n1[] = {0, 1, 1, 3}, rs1;
  int n2[] = {2, 3, 4, 7}, rs2;
  int n3[] = {0, 1, 2, 2, 5, 7}, rs3;
  int *gmx1 = getMaximumXor(n1, ARRAY_SIZE(n1), 2, &rs1);
  int *gmx2 = getMaximumXor(n2, ARRAY_SIZE(n2), 3, &rs2);
  int *gmx3 = getMaximumXor(n3, ARRAY_SIZE(n3), 3, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", gmx1[i]); // expect: 0 3 2 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", gmx2[i]); // expect: 5 2 6 5
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", gmx3[i]); // expect: 4 3 6 4 6 7
  printf("\n");
  free(gmx1), free(gmx2), free(gmx3);
}
