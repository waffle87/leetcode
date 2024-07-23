// 2750. Ways to Split Array Into Good Subarrays
#include "leetcode.h"

/*
 * given a binary array 'nums'. a subarray of an array is good if it contains
 * exactly one element with the value 1. return an integer denoting the number
 * of ways to split the array 'nums' into good subarrays. as the number may be
 * too large, return it 10^9+7. a subarray is contiguous non empty sequence of
 * elements within an array.
 */

int numberOfGoodSubarraySplits(int *nums, int numsSize) {
  long long ans = 0, cnt = 0;
  for (int i = 0; i < numsSize; i++) {
    if (!nums[i])
      cnt += ans > 0;
    else {
      ans = ans ? ans * (cnt + 1) % 1000000007 : 1;
      cnt = 0;
    }
  }
  return ans;
}

int main() {
  int n1[] = {0, 1, 0, 0, 1}, n2[] = {0, 1, 0};
  printf("%d\n", numberOfGoodSubarraySplits(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", numberOfGoodSubarraySplits(n2, ARRAY_SIZE(n2))); // expect: 1
}
