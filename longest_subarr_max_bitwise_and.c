// 2419. Longest Subarray With Maximum Bitwise AND
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of size 'n'. consider a non-empty
 * subarray from 'nums' that has the maximum possible bitwise and. in other
 * words, let 'k' be the maximum value of the bitwise and of any subarray of
 * 'nums'. then, only subarrays with a bitwise and equal to 'k' should be
 * considered. return the length of the longest such subarray. the bitwise and
 * of an array is the bitwise and of all the numbers in it. a subarray is a
 * contiguous sequence of elements within an array
 */

int longestSubarray(int *nums, int numsSize) {
  int max = 0, ans = 0;
  for (int i = 0, j = 0; i < numsSize; i++) {
    if (nums[i] > max) {
      max = nums[i];
      j = 1;
      ans = 1;
    } else if (nums[i] == max)
      j++;
    else
      j = 0;
    if (j > ans)
      ans = j;
  }
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 3, 2, 2}, n2[] = {1, 2, 3, 4};
  printf("%d\n", longestSubarray(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", longestSubarray(n2, ARRAY_SIZE(n2))); // expect: 1
}
