// 1863. Sum of All Subset XOR Totals
#include "leetcode.h"

/*
 * the xor total of an array is defined as the bitwise xor of all its elements
 * or 0 if the array is empty. given an array 'nums' return the sum of all xor
 * totals for every subset of 'nums'. an array 'a' is a subset of an array 'b'
 * if 'a' can be obtained from 'b' by deleting some elements of 'b'.
 */

void backtrack(int *nums, int numsSize, int tar, int idx, int *cnt) {
  if (idx == numsSize) {
    return;
  } else {
    for (int i = idx; i < numsSize; i++) {
      tar ^= nums[i];
      *cnt += tar;
      backtrack(nums, numsSize, tar, i + 1, cnt);
      tar ^= nums[i];
    }
  }
}

int subsetXORSum(int *nums, int numsSize) {
  int ans = 0;
  for (int i = 0; i < numsSize; i++) {
    ans += nums[i];
    backtrack(nums, numsSize, nums[i], i + 1, &ans);
  }
  return ans;
}

int main() {
  int n1[] = {1, 3}, n2[] = {5, 1, 6}, n3[] = {3, 4, 5, 6, 7, 8};
  printf("%d\n", subsetXORSum(n1, ARRAY_SIZE(n1))); // expect: 6
  printf("%d\n", subsetXORSum(n2, ARRAY_SIZE(n2))); // expect: 28
  printf("%d\n", subsetXORSum(n3, ARRAY_SIZE(n3))); // expect: 480
}
