// 2302. Count Subarrays With Score Less Than K
#include "leetcode.h"

/*
 * the score of an array is defined as the product of its sum and its length.
 * given a positive integer array 'nums' and an integer 'k', return the number
 * of non-empty subarrays of 'nums' whose score is strictly less than 'k'. a
 * subarray is a contiguous sequence of elements within an array.
 */

long long countSubarrays(int *nums, int numsSize, long long k) {
  long long ans = 0, curr = 0;
  for (int j = 0, i = 0; j < numsSize; ++j) {
    curr += nums[j];
    while (curr * (j - i + 1) >= k)
      curr -= nums[i++];
    ans += j - i + 1;
  }
  return ans;
}

int main() {
  int n1[] = {2, 1, 4, 3, 5}, n2[] = {1, 1, 1};
  printf("%lld\n", countSubarrays(n1, ARRAY_SIZE(n1), 10)); // expect: 6
  printf("%lld\n", countSubarrays(n2, ARRAY_SIZE(n2), 5));  // expect: 5
}
