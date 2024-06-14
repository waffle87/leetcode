// 795. Number of Subarrays with Bounded Maximum
#include "leetcode.h"

/*
 * given an integer array 'nums' and two integers 'left' and 'right', return the
 * number of contiguous non empty subarrays such that the value of the maximum
 * array element in that subarray is in the range '[left, right]'. the test
 * cases are generated such that the answer will fit into a 32 bit integer.
 */

int helper(int *nums, int n, int left) {
  if (!n)
    return 0;
  long long res = (long long)(n + 1) * n / 2;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] < left)
      cnt++;
    else {
      res -= (cnt + 1) * cnt / 2;
      cnt = 0;
    }
  }
  res -= (cnt + 1) * cnt / 2;
  return res;
}

int numSubarrayBoundedMax(int *nums, int numsSize, int left, int right) {
  int ans = 0, prev = 0;
  for (int i = 0; i < numsSize; i++)
    if (nums[i] > right) {
      ans += helper(&nums[prev], i - prev, left);
      prev = i + 1;
    }
  ans += helper(&nums[prev], numsSize - prev, left);
  return ans;
}

int main() {
  int n1[] = {2, 1, 4, 3}, n2[] = {2, 9, 2, 5, 6};
  printf("%d\n", numSubarrayBoundedMax(n1, ARRAY_SIZE(n1), 2, 3)); // expect: 3
  printf("%d\n", numSubarrayBoundedMax(n2, ARRAY_SIZE(n2), 2, 8)); // expect: 7
}
