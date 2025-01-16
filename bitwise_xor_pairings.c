// 2425. Bitwise XOR of All Pairings
#include "leetcode.h"

/*
 * you are given two 0-indexed arrays 'nums1' and 'nums2', consisting of
 * non-negative integers. there exists another array, 'nums3', which contains
 * the bitwise xor of all pairings of integers between 'nums1' and 'nums2'
 * (every integer in 'nums1' is paired with every integer in 'nums2' exactly
 * once). return the bitwise xor of all integers in 'nums3'
 */

int xorAllNums(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int x = 0, y = 0;
  for (int i = 0; i < nums1Size; i++)
    x ^= nums1[i];
  for (int i = 0; i < nums2Size; i++)
    y ^= nums2[i];
  return (nums1Size % 2 * y) ^ (nums2Size % 2 * x);
}

int main() {
  int n11[] = {2, 1, 3}, n21[] = {10, 2, 5, 0};
  int n12[] = {1, 2}, n22[] = {3, 4};
  printf("%d\n",
         xorAllNums(n11, ARRAY_SIZE(n11), n21, ARRAY_SIZE(n21))); // expect: 13
  printf("%d\n",
         xorAllNums(n12, ARRAY_SIZE(n12), n22, ARRAY_SIZE(n22))); // expect: 0
}
