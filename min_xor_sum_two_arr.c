// 1879. Minimum XOR Sum of Two Arrays
#include "leetcode.h"

/*
 * you are given two integer arrays 'nums1' and 'nums2' of length 'n'. the xor
 * sum of the two integer arrays is '(nums1[0] ^ nums2[0]) + (nums1[1] ^
 * nums2[1]) + ...' (0-indexed). rearrange the elements of 'nums2' such that
 * resulting xor sum is minimised. return the xor sum after the rearrangement.
 */

static int dp[1 << 14] = {[0 ... 16383] = INT_MAX};

int dfs(int *nums1, int *nums2, int n, int i, int mask) {
  if (i >= n)
    return 0;
  if (dp[mask] == -1)
    for (int j = 0; j < n; ++j)
      if (!(mask & (1 << j)))
        dp[mask] =
            fmin(dp[mask], (nums1[i] ^ nums2[j]) +
                               dfs(nums1, nums2, n, i + 1, mask + (1 << j)));
  return dp[mask];
}

int minimumXORSum(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  return dfs(nums1, nums2, nums1Size, 0, 0);
}

int main() {
  int n11[] = {1, 2}, n21[] = {2, 3}, n12[] = {1, 0, 3}, n22[] = {5, 3, 4};
  printf("%d\n", minimumXORSum(n11, ARRAY_SIZE(n11), n21,
                               ARRAY_SIZE(n21))); // expect: 2
  printf("%d\n", minimumXORSum(n12, ARRAY_SIZE(n12), n22,
                               ARRAY_SIZE(n22))); // expect: 8
}
