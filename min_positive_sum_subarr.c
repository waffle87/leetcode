// 3364. Minimum Positive Sum Subarray
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and two integers 'l' and 'r'. your task
 * is to find the minimum sum of a subarrray whose size is between 'l' and 'r'
 * (inclusive) and whose sum is greater than 0. return the minimum sum of such a
 * subarray. if no such subarray exists, return -1.
 */

int minimumSumSubarray(int *nums, int numsSize, int l, int r) {
  int best = INT_MAX;
  for (int i = 0; i < numsSize; i++) {
    int s = 0;
    for (int j = i; j < fmin(i + r, numsSize); ++j) {
      s += nums[j];
      if (j - i + 1 >= l && 0 < s && s < best)
        best = s;
    }
  }
  return best == INT_MAX ? -1 : best;
}

int main() {
  int n1[] = {3, -2, 1, 4};
  int n2[] = {-2, 2, -3, 1};
  int n3[] = {1, 2, 3, 4};
  int r1 = minimumSumSubarray(n1, ARRAY_SIZE(n1), 2, 3);
  int r2 = minimumSumSubarray(n2, ARRAY_SIZE(n2), 2, 3);
  int r3 = minimumSumSubarray(n3, ARRAY_SIZE(n3), 2, 4);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == -1);
  printf("%d\n", r3);
  assert(r3 == 3);
}
