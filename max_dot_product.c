// 1458. Max Dot Product of Two Subsequences
#include <stdio.h>
#include <stdlib.h>

/*
 * given two arrays 'nums1, nums2'. return the maximum dot product between
 * non-empty subsequences of nums1 and nums2 with the same length. a subsequence
 * of an array is a new array which is formed from the original array by
 * deleting some (can be none) of the characters without disturbing the relative
 * positions of the remaining characters.
 */

int maxDotProduct(int *nums1, int num1_size, int *nums2, int nums2_size) {
  int n = A.size(), m = B.size();
  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j] = A[i] * B[j];
      if (i && j)
        dp[i][j] += max(dp[i - 1][j - 1], 0);
      if (i)
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (j)
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
    }
  }
  return dp[n - 1][m - 1];
}
int main() {
  int n11[] = {2, 1, -2, 5}, n21[] = {3, 0, -6};
  int n12[] = {3, -2}, n22[] = {2, -6, 7};
  int n13[] = {-1, -1}, n23[] = {1, 1};
  printf("%d\n", maxDotProduct(n11, 4, n21, 3)); // expect: 18
  printf("%d\n", maxDotProduct(n12, 2, n22, 3)); // expect: 21
  printf("%d\n", maxDotProduct(n13, 2, n23, 2)); // expect: -1
}
