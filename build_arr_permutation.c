// 1920. Build Array from Permutation
#include "leetcode.h"

/*
 * given a 0-based permutation 'nums', build an array 'ans' of the same length
 * where 'ans[i] = nums[nums[i]]' for each '0 <= i < nums.len' and return it. a
 * 0-based permutation 'nums' is an array of distinct integers from 0 to
 * 'nums.len - 1'.
 */

int *buildArray(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  for (int i = 0; i < numsSize; i++)
    nums[i] += (nums[nums[i]] & 1023) << 10;
  for (int i = 0; i < numsSize; i++)
    nums[i] >>= 10;
  return nums;
}

int main() {
  int n1[] = {0, 2, 1, 5, 3, 4}, rs1;
  int n2[] = {5, 0, 1, 2, 3, 4}, rs2;
  int *ba1 = buildArray(n1, ARRAY_SIZE(n1), &rs1);
  int *ba2 = buildArray(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ba1[i]); // expect: 0 1 2 4 5 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ba2[i]); // expect: 4 5 0 1 2 3
  printf("\n");
}
