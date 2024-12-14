// 2762. Continuous Subarrays
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums'. a subarray of 'nums' is
 * called continuous if: let 'i', 'i + 1', ..., 'j' be the indices in the
 * subarray. then, for each pair of indices 'i <= i_1, i_2 <= j', '0 <= |
 * nums[i_1] - nums[i_2]| <= 2'. return the total number of continuous
 * subarrays. a subarray is a contiguous non-empty sequence of elements within
 * an array
 */

long long continuousSubarrays(int *nums, int numsSize) {
  int l = 0, r = 0, j = 0;
  long long ans = 0;
  for (int i = 0; i < numsSize; i++) {
    if (!i) {
      ans++;
      l = nums[i] - 2;
      r = nums[i] + 2;
    } else if (nums[i] >= l && nums[i] <= r) {
      l = fmax(l, nums[i] - 2);
      r = fmin(r, nums[i] + 2);
      ans += i - j + 1;
    } else {
      j = i - 1;
      l = nums[i] - 2;
      r = nums[i] + 2;
      while (nums[j] >= nums[i] - 2 && nums[j] <= nums[i] + 2) {
        l = fmax(l, nums[j] - 2);
        r = fmin(r, nums[j] + 2);
        j--;
      }
      j++;
      ans += i - j + 1;
    }
  }
  return ans;
}

int main() {
  int n1[] = {5, 4, 2, 4}, n2[] = {1, 2, 3};
  printf("%lld\n", continuousSubarrays(n1, ARRAY_SIZE(n1))); // expect: 8
  printf("%lld\n", continuousSubarrays(n2, ARRAY_SIZE(n2))); // expect: 6
}
