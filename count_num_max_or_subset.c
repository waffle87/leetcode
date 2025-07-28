// 2044. Count Number of Maximum Bitwise-OR Subsets
#include "leetcode.h"

/*
 * given an integer array 'nums', find the maximum possible bitwise or of a
 * subset of 'nums' and return the number of different non-empty subsets with
 * the maximum bitwise or. an array 'a' is a subset of an array 'b' if 'a' can
 * be obtained from 'b' by deleting some (possibly zero) elements of 'b'. two
 * subsets are considered different if the indices of the elements chosen are
 * different. the bitwise or of an array 'a' is equal to 'a[0] | a[1] | ... |
 * a[a.length - 1]'
 */

int countMaxOrSubsets(int *nums, int numsSize) {
  int max = 0, dp[1 << 17] = {1};
  for (int i = 0; i < numsSize; i++) {
    for (int j = max; j >= 0; --j)
      dp[j | nums[i]] += dp[j];
    max |= nums[i];
  }
  return dp[max];
}

int main() {
  int n1[] = {3, 1}, n2[] = {2, 2, 2}, n3[] = {3, 2, 1, 5};
  printf("%d\n", countMaxOrSubsets(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", countMaxOrSubsets(n2, ARRAY_SIZE(n2))); // expect: 7
  printf("%d\n", countMaxOrSubsets(n3, ARRAY_SIZE(n3))); // expect: 6
}
