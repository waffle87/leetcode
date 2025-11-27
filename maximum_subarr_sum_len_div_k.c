// 3381. Maximum Subarray Sum With Length Divisible by K
#include "leetcode.h"

/*
 * you are given an array of integers 'nums' and an integer 'k'. return the
 * maximum sum of a subarray of 'nums', such that the size of the subarray is
 * divisble by 'k'.
 */

long long maxSubarraySum(int *nums, int numsSize, int k) {
  long long ans = LLONG_MIN, total = 0;
  long long *pre = (long long *)malloc(k * sizeof(long long));
  for (int i = 0; i < k; i++)
    pre[i] = LLONG_MAX / 2;
  pre[k - 1] = 0;
  for (int i = 0; i < numsSize; i++) {
    total += nums[i];
    ans = fmax(ans, total - pre[i % k]);
    pre[i % k] = fmin(pre[i % k], total);
  }
  free(pre);
  return ans;
}

int main() {
  int n1[] = {1, 2}, n2[] = {-1, -2, -3, -4, -5}, n3[] = {-5, 1, 2, -3, 4};
  printf("%lld\n", maxSubarraySum(n1, ARRAY_SIZE(n1), 1)); // expect: 3
  printf("%lld\n", maxSubarraySum(n2, ARRAY_SIZE(n2), 4)); // expect: -10
  printf("%lld\n", maxSubarraySum(n3, ARRAY_SIZE(n3), 2)); // expect: 4
}
