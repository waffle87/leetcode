// 300. Longest Increasing Subsequence
#include "leetcode.h"

/*
 * given an integer array 'nums', return the length of the longest strictly
 * increasing subsequence.
 */

int lengthOfLIS(int *nums, int nums_size) {
  int dp[nums_size], max_len = 0;
  for (int i = 0; i < nums_size; ++i)
    dp[i] = 1;
  for (int i = 0; i < nums_size; ++i)
    for (int j = 0; j < i; ++j)
      if (nums[i] > nums[j])
        dp[i] = fmax(dp[i], dp[j] + 1);
  for (int i = 0; i < nums_size; ++i)
    max_len = fmax(max_len, dp[i]);
  return max_len;
}

int main() {
  int n1[] = {10, 9, 2, 5, 3, 7, 101, 18}, n2[] = {0, 1, 0, 3, 2, 3},
      n3[] = {7, 7, 7, 7, 7, 7, 7};
  printf("%d\n", lengthOfLIS(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", lengthOfLIS(n2, ARRAY_SIZE(n2))); // expect: 4
  printf("%d\n", lengthOfLIS(n3, ARRAY_SIZE(n3))); // expect: 1
}
