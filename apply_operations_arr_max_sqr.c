// 2897. Apply Operations on Array to Maximize Sum of Squares
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' and a positive integer 'k'.
 * you can do the following operation on the array any number of times: choose
 * any two distinct indices 'i' and 'j' and simultaneously update the values of
 * 'nums[i]' to '(nums[i] & nums[j])' and 'nums[j]' to '(nums[i] | nums[j])'.
 * you have to choose 'k' elements from the final array and calcluate the sum of
 * their squares. return the maximum sum of squares you can achieve. since the
 * answer can be very large, return it modulo 10^9+7.
 */

int maxSum(int *nums, int numsSize, int k) {
  int cnt[32] = {0};
  for (int i = 0; i < numsSize; i++)
    for (int j = 0; j < 32; j++)
      if (nums[i] & (1 << j))
        cnt[j]++;
  int ans = 0, mod = 1e9 + 7;
  for (int i = 0; i < k; i++) {
    int curr = 0;
    for (int j = 0; j < 32; j++)
      if (cnt[j] > 0) {
        cnt[j]--;
        curr += 1 << j;
      }
    ans = (ans + 1L * curr * curr % mod) % mod;
  }
  return ans;
}

int main() {
  int n1[] = {2, 6, 5, 8}, n2[] = {4, 5, 4, 7};
  printf("%d\n", maxSum(n1, ARRAY_SIZE(n1), 2)); // expect: 261
  printf("%d\n", maxSum(n2, ARRAY_SIZE(n2), 3)); // expect: 90
}
