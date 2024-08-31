// 410. Split Array Largest Sum
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'k' split 'nums' into 'k' non
 * empty subarrays such that the largest sum of any subarray is minimised.
 * return the minimised largest sum of the split. a subarray is a contiguous
 * part of the array
 */

int splitArray(int *nums, int numsSize, int k) {
  int right = 0, left = 0;
  for (int i = 0; i < numsSize; i++) {
    left = left > nums[i] ? left : nums[i];
    right += nums[i];
  }
  right++;
  while (left < right) {
    int mid = (left + right) / 2, cnt = 1, tmp = 0;
    for (int i = 0; i < numsSize; i++)
      if (tmp + nums[i] > mid) {
        cnt++;
        tmp = nums[i];
      } else {
        tmp += nums[i];
      }
    if (cnt > k)
      left = mid + 1;
    else
      right = mid;
  }
  return (int)left;
}

int main() {
  int n1[] = {7, 2, 5, 10, 8}, n2[] = {1, 2, 3, 4, 5};
  printf("%d\n", splitArray(n1, ARRAY_SIZE(n1), 2)); // expect: 18
  printf("%d\n", splitArray(n2, ARRAY_SIZE(n2), 2)); // expect: 9
}
