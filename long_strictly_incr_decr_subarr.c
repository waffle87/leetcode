// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
#include "leetcode.h"

/*
 * you are given an array of integers 'nums'. return the legnth of the longest
 * subarray of 'nums' which is either strictly increasing or strictly
 * decreasing.
 */

int longestMonotonicSubarray(int *nums, int numsSize) {
  int ans = 1, inc = 1, dec = 1;
  for (int i = 1; i < numsSize; i++) {
    bool a = nums[i] > nums[i - 1], b = nums[i] < nums[i - 1];
    inc = a * inc + 1;
    dec = b * dec + 1;
    ans = fmax(ans, fmax(inc, dec));
  }
  return ans;
}

int main() {
  int n1[] = {1, 4, 3, 3, 2}, n2[] = {3, 3, 3, 3}, n3[] = {3, 2, 1};
  printf("%d\n", longestMonotonicSubarray(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", longestMonotonicSubarray(n2, ARRAY_SIZE(n2))); // expect: 1
  printf("%d\n", longestMonotonicSubarray(n3, ARRAY_SIZE(n3))); // expect: 3
}
