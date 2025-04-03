// 2874. Maximum Value of an Ordered Triplet II
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums'. return the maximum value over
 * all triplets of indices '(i, j, k)' such that 'i < j < k'. if all such
 * triplets have a negative value, return 0. the value of a triplet of indices
 * '(i, j, k)' is equal to '(nums[i] - nums[j]) * nums[k]'
 */

long long maximumTripletValue(int *nums, int numsSize) {
  if (numsSize < 3)
    return 0;
  long long ans = 0, curr = nums[0], diff = 0;
  for (int i = 1; i < numsSize; i++) {
    ans = fmax(ans, (long long)diff * nums[i]);
    diff = fmax(diff, curr - nums[i]);
    curr = fmax(curr, nums[i]);
  }
  return ans;
}

int main() {
  int n1[] = {12, 6, 1, 2, 7}, n2[] = {1, 10, 3, 4, 19}, n3[] = {1, 2, 3};
  printf("%lld\n", maximumTripletValue(n1, ARRAY_SIZE(n1))); // expect: 77
  printf("%lld\n", maximumTripletValue(n2, ARRAY_SIZE(n2))); // expect: 133
  printf("%lld\n", maximumTripletValue(n3, ARRAY_SIZE(n3))); // expect: 0
}
