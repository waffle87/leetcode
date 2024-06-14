// 2962. Count Subarrays Where Max Element Appears at Least K Times
#include "leetcode.h"

/*
 * given an integer array 'nums' and a positive integer 'k'. return the number
 * of subarrays where the maximum element of 'nums' appears at least 'k' times
 * in that subarray. a subarray is a contiguous sequence of elements within an
 * array.
 */

long long countSubarrays(int *nums, int numsSize, int k) {
  int max = 0, cnt = 0, idx[numsSize];
  long long ans = 0;
  for (int i = 0; i < numsSize; i++)
    max = max > nums[i];
  for (int i = 0; i < numsSize; i++)
    if (nums[i] == max)
      idx[cnt++] = i;
  for (int i = 0; i <= cnt - k; i++) {
    long long left = idx[i], right = idx[i + k - 1],
              bound = i - 1 >= 0 ? idx[i - 1] : -1;
    if (!i)
      bound = -1;
    ans += (left - bound) * (numsSize - right);
  }
  return ans;
}

int main() {
  int n1[] = {1, 3, 2, 3, 3}, n2[] = {1, 4, 2, 1};
  printf("%lld\n", countSubarrays(n1, ARRAY_SIZE(n1), 2)); // expect: 6
  printf("%lld\n", countSubarrays(n2, ARRAY_SIZE(n2), 3)); // expect: 0
}
