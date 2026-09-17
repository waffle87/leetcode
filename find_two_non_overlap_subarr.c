// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
#include "leetcode.h"

/*
 * you are given an array of integers 'arr' and an integer 'target'. you have to
 * find two non overlapping subarrays of 'arr' each with a sum equal to
 * 'target'. there can be multiple answers so you have to finmd an answer where
 * the sum of the lengths of the two subarrays is minimum. return the minimum
 * sum of the lengths of the two required subarrays or return -1 if you cannot
 * find such two subarrays.
 */

int minSumOfLengths(int *arr, int arrSize, int target) {
  int ans = arrSize + 1, sum = 0, left = 0;
  int *dp = (int *)malloc((arrSize + 1) * sizeof(int));
  for (int i = 0; i <= arrSize; i++)
    dp[i] = arrSize;
  for (int right = 0; right < arrSize; right++) {
    sum += arr[right];
    while (sum > target)
      sum -= arr[left++];
    dp[right + 1] = dp[right];
    if (sum == target) {
      int len = right - left + 1;
      ans = fmin(ans, len + dp[left]);
      dp[right + 1] = fmin(dp[right + 1], len);
    }
  }
  free(dp);
  return ans == arrSize + 1 ? -1 : ans;
}

int main() {
  int a1[] = {3, 2, 2, 4, 3};
  int a2[] = {7, 3, 4, 7};
  int a3[] = {4, 3, 2, 6, 2, 3, 4};
  int r1 = minSumOfLengths(a1, ARRAY_SIZE(a1), 3);
  int r2 = minSumOfLengths(a2, ARRAY_SIZE(a2), 7);
  int r3 = minSumOfLengths(a3, ARRAY_SIZE(a3), 6);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == -1);
}
