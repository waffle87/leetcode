// 1493. Longest Subarray of 1's After Deleting One Element
#include "leetcode.h"

/*
 * given a binary array 'nums', you should delete one element from it. return
 * the size of the longest non-empty subarray containing only 1's in the
 * resulting array. return 0 if there is no such subarray.
 */

int longestSubarray(int *nums, int numsSize) {
  int left = 0, zeros = 0, ans = 0;
  for (int right = 0; right < numsSize; right++) {
    if (!nums[right])
      zeros++;
    while (zeros > 1) {
      if (!nums[left])
        zeros--;
      left++;
    }
    int length = right - left;
    if (length > ans)
      ans = length;
  }
  return ans;
}

int main() {
  int n1[] = {1, 1, 0, 1}, n2[] = {0, 1, 1, 1, 0, 1, 1, 0, 1}, n3[] = {1, 1, 1};
  printf("%d\n", longestSubarray(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", longestSubarray(n2, ARRAY_SIZE(n2))); // expect: 5
  printf("%d\n", longestSubarray(n3, ARRAY_SIZE(n3))); // expect: 2
}
