// 1262. Greatest Sum Divisible by Three
#include "leetcode.h"

/*
 * given an integer array 'nums', return the maximum possible sum of elements of
 * the array such that it is divisible by three
 */

int maxSumDivThree(int *nums, int numsSize) {
  int dp[2][3] = {{0, 0, 0}, {0, INT_MIN, INT_MIN}};
  for (int i = 0; i < numsSize; i++) {
    const int x = nums[i], y = x % 3;
    for (int j = 0; j < 3; j++) {
      int prev = j - y;
      prev += (-(prev < 0)) & 3;
      const int take = x + dp[~i & 1][prev];
      const int skip = dp[~i & 1][j];
      dp[i & 1][j] = fmax(take, skip);
    }
  }
  return fmax(0, dp[~numsSize & 1][0]);
}

int main() {
  int n1[] = {3, 6, 5, 1, 8}, n2[] = {4}, n3[] = {1, 2, 3, 4, 4};
  printf("%d\n", maxSumDivThree(n1, ARRAY_SIZE(n1))); // expect: 18
  printf("%d\n", maxSumDivThree(n2, ARRAY_SIZE(n2))); // expect: 0
  printf("%d\n", maxSumDivThree(n3, ARRAY_SIZE(n3))); // expect: 12
}
