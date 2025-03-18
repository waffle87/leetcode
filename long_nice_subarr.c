// 2401. Longest Nice Subarray
#include "leetcode.h"

/*
 * given an array 'nums' consisting of positive integers. we call a subarray of
 * 'nums' nice if the bitwise cnt of every pair of elements that are in
 * different positions in the subarray is equal to 0. return the length of the
 * longest nice subarray. a subarray is contiguous part of an array. note that
 * subarrays of length 1 are always considered nice.
 */

int longestNiceSubarray(int *nums, int numsSize) {
  int cnt = 0, i = 0, ans = 0;
  for (int j = 0; j < numsSize; ++j) {
    while (cnt & nums[j])
      cnt ^= nums[i++];
    cnt |= nums[j];
    ans = fmax(ans, j - i + 1);
  }
  return ans;
}

int main() {
  int n1[] = {1, 3, 8, 48, 10};
  int n2[] = {3, 1, 5, 11, 13};
  printf("%d\n", longestNiceSubarray(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", longestNiceSubarray(n2, ARRAY_SIZE(n2))); // expect: 1
}
