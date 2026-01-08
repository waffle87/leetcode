// 1458. Max Dot Product of Two Subsequences
#include "leetcode.h"

/*
 * given two arrays 'nums1, nums2'. return the maximum dot product between
 * non-empty subsequences of nums1 and nums2 with the same length. a subsequence
 * of an array is a new array which is formed from the original array by
 * deleting some (can be none) of the characters without disturbing the relative
 * positions of the remaining characters.
 */

int maxDotProduct(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int **dp = (int **)malloc(nums1Size * sizeof(int *));
  for (int i = 0; i < nums1Size; i++)
    dp[i] = (int *)malloc(nums2Size * sizeof(int));
  for (int i = 0; i < nums1Size; ++i) {
    for (int j = 0; j < nums2Size; ++j) {
      dp[i][j] = nums1[i] * nums2[j];
      if (i && j)
        dp[i][j] += fmax(dp[i - 1][j - 1], 0);
      if (i)
        dp[i][j] = fmax(dp[i][j], dp[i - 1][j]);
      if (j)
        dp[i][j] = fmax(dp[i][j], dp[i][j - 1]);
    }
  }
  int ans = dp[nums1Size - 1][nums2Size - 1];
  for (int i = 0; i < nums1Size; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  int n11[] = {2, 1, -2, 5}, n21[] = {3, 0, -6};
  int n12[] = {3, -2}, n22[] = {2, -6, 7};
  int n13[] = {-1, -1}, n23[] = {1, 1};
  printf("%d\n", maxDotProduct(n11, ARRAY_SIZE(n11), n21,
                               ARRAY_SIZE(n21))); // expect: 18
  printf("%d\n", maxDotProduct(n12, ARRAY_SIZE(n12), n22,
                               ARRAY_SIZE(n22))); // expect: 21
  printf("%d\n", maxDotProduct(n13, ARRAY_SIZE(n13), n23,
                               ARRAY_SIZE(n23))); // expect: -1
}
