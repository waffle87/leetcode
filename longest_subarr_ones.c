// 1493. Longest Subarray of 1's After Deleting One Element
#include <math.h>
#include <stdio.h>

/*
 * given a binary array 'nums', you should delete one element from it. return
 * the size of the longest non-empty subarray containing only 1's in the
 * resulting array. return 0 if there is no such subarray.
 */

int longestSubarray(int *nums, int nums_size) {
  int n = nums_size, zero_cnt = 0, ans = 0, left = 0;
  for (int right = 0; right < n; right++) {
    if (!nums[right])
      zero_cnt++;
    while (zero_cnt > 1) {
      if (!nums[left])
        zero_cnt--;
      left++;
    }
    ans = fmax(ans, right - left);
  }
  return ans;
}

int main() {
  int n1[] = {1, 1, 0, 1}, n2[] = {0, 1, 1, 1, 0, 1, 1, 0, 1}, n3[] = {1, 1, 1};
  printf("%d\n", longestSubarray(n1, 4)); // expect: 3
  printf("%d\n", longestSubarray(n2, 9)); // expect: 5
  printf("%d\n", longestSubarray(n3, 3)); // expect: 2
}
