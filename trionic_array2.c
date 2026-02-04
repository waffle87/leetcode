// 3640. Trionic Array II
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n'. a trionic subarray is a
 * contiguous subarray 'nums[l ... r]' for which there exists indices 'nums[l
 * ... p]' is stricly increasing, 'nums[p ... q]' is strictly decreasing, and
 * 'nums[p ... r]' is strictly increasing. return the maximum sum of any trionic
 * subarray in 'nums'.
 */

long long maxSumTrionic(int *nums, int numsSize) {
  long long ans = LLONG_MIN, cnt = nums[0];
  for (int l = 0, p = 0, q = 0, r = 1; r < numsSize; ++r) {
    cnt += nums[r];
    if (nums[r - 1] == nums[r]) {
      l = r;
      cnt = nums[r];
    } else if (nums[r - 1] > nums[r]) {
      if (r > 1 && nums[r - 2] < nums[r - 1]) {
        p = r - 1;
        while (l < q)
          cnt -= nums[l++];
        while (l + 1 < p && nums[l] < 0)
          cnt -= nums[l++];
      }
    } else {
      if (r > 1 && nums[r - 2] > nums[r - 1])
        q = r - 1;
      if (l < p && p < q)
        ans = fmax(ans, cnt);
    }
  }
  return ans;
}

int main() {
  int n1[] = {0, -2, -1, -3, 0, 2, -1}, n2[] = {1, 4, 2, 7};
  long long r1 = maxSumTrionic(n1, ARRAY_SIZE(n1));
  long long r2 = maxSumTrionic(n2, ARRAY_SIZE(n2));
  printf("%lld\n", r1); // expect: -4
  assert(r1 == -4);
  printf("%lld\n", r2); // expect: 14
  assert(r2 == 14);
}
