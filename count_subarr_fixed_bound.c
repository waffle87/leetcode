// 2444. Count Subarrays With Fixed Bounds
#include "leetcode.h"

/*
 * given an integer array 'nums' and two integer 'mink' and 'maxk'. a fixed
 * bound subarray of 'nums' is a subarray that satisfies the following
 * conditions. the minimum value in the subarray is equal to 'mink' and the
 * maximum value in the subarray is equal to 'maxk'. return the number of fixed
 * bound subarrays. a subarray is a contiguous part of an array.
 */

long long countSubarrays(int *nums, int numsSize, int minK, int maxK) {
  long long ans = 0;
  int last_min = -1, last_max = -1, start = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > maxK || nums[i] < minK)
      start = i + 1;
    if (nums[i] == maxK)
      last_max = i;
    if (nums[i] == minK)
      last_min = i;
    int pos = fmin(last_max, last_min);
    if (start > pos)
      continue;
    ans += pos - start + 1;
  }
  return ans;
}

int main() {
  int n1[] = {1, 3, 5, 2, 7, 5}, n2[] = {1, 1, 1, 1};
  printf("%lld\n", countSubarrays(n1, ARRAY_SIZE(n1), 1, 5)); // expect: 2
  printf("%lld\n", countSubarrays(n2, ARRAY_SIZE(n2), 1, 1)); // expect: 10
}
