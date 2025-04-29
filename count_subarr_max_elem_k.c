// 2962. Count Subarrays Where Max Element Appears at Least K Times
#include "leetcode.h"

/*
 * given an integer array 'nums' and a positive integer 'k'. return the number
 * of subarrays where the maximum element of 'nums' appears at least 'k' times
 * in that subarray. a subarray is a contiguous sequence of elements within an
 * array.
 */

long long countSubarrays(int *nums, int numsSize, int k) {
  int max = -1, curr = 0;
  long long ans = 0;
  for (int i = 0; i < numsSize; ++i)
    max = nums[i] > max ? nums[i] : max;
  for (int l = 0, r = 0; r < numsSize; r++) {
    curr += nums[r] == max;
    while (curr >= k)
      curr -= nums[l++] == max;
    ans += l;
  }
  return ans;
}

int main() {
  int n1[] = {1, 3, 2, 3, 3}, n2[] = {1, 4, 2, 1};
  printf("%lld\n", countSubarrays(n1, ARRAY_SIZE(n1), 2)); // expect: 6
  printf("%lld\n", countSubarrays(n2, ARRAY_SIZE(n2), 3)); // expect: 0
}
