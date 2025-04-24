// 2799. Count Complete Subarrays in an Array
#include "leetcode.h"

/*
 * you are given an array 'nums' consisting of positive integers. we call a
 * subarray of an array complete if the following condition is satisfied. the
 * number of distinct elements in the subarray is equal to the number of
 * distinct elements in the whole array. return the number of complete
 * subarrays. a subarray is a contiguous non-empty part of an array.
 */

int countCompleteSubarrays(int *nums, int numsSize) {
  int elem[2001] = {0}, distinct = 0, ans = 0;
  for (int i = 0; i < numsSize; i++) {
    if (!elem[nums[i]])
      distinct++;
    elem[nums[i]]++;
  }
  int low = 0, high = 0, curr = 0;
  memset(elem, 0, sizeof(elem));
  while (curr < distinct) {
    if (!elem[nums[high]])
      curr++;
    elem[nums[high]]++;
    high++;
  }
  ans += numsSize - high + 1;
  while (low < numsSize) {
    elem[nums[low]]--;
    if (!elem[nums[low]])
      curr--;
    while (high < numsSize && curr < distinct) {
      if (!elem[nums[high]])
        curr++;
      elem[nums[high]]++;
      high++;
    }
    if (curr < distinct)
      break;
    ans += numsSize - high + 1;
    low++;
  }
  return ans;
}

int main() {
  int n1[] = {1, 3, 1, 2, 2}, n2[] = {5, 5, 5, 5};
  printf("%d\n", countCompleteSubarrays(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", countCompleteSubarrays(n2, ARRAY_SIZE(n2))); // expect: 10
}
