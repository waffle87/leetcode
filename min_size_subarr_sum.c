// 209. Minimum Size Subarray Sum
#include <limits.h>
#include <stdio.h>

/*
 * given an array of positive integer 'nums' and a positive integer 'target',
 * return the minimal length of a subarray whose sum is greater than or equal to
 * 'target'. if there is no such subarray, return 0 instead.
 */

int minSubArrayLen(int target, int *nums, int nums_size) {
  int sum = 0, cnt = INT_MAX, left = 0, right = 0;
  for (int i = 0; i < nums_size; i++) {
    right++;
    sum += nums[i];
    if (sum >= target && (right - left) < cnt)
      cnt = right - left;
    while (sum > target) {
      sum -= nums[left];
      left++;
      if (sum >= target && (right - left) < cnt)
        cnt = right - left;
    }
  }
  if (cnt == INT_MAX)
    return 0;
  else
    return cnt;
}

int main() {
  int n1[] = {2, 3, 1, 2, 4, 3}, n2[] = {1, 4, 4},
      n3[] = {1, 1, 1, 1, 1, 1, 1, 1};
  printf("%d\n", minSubArrayLen(7, n1, 6));  // expect: 2
  printf("%d\n", minSubArrayLen(4, n2, 3));  // expect: 1
  printf("%d\n", minSubArrayLen(11, n3, 8)); // expect: 0
}
