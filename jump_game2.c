// 45. Jump Game II
#include <stdio.h>

/*
 * you are given 0-indexed array of integers 'nums' of length
 * 'n'. you are initially positioned at 'nums[0]' each element
 * 'nums[i]' represents the maximum length of forward jump from
 * from index 'i'. in other words, you can jump to any
 * 'nums[i + j]' where 0 <= j <= nums[i] and i + j < n
 * return the minimum number of jumps to reach 'nums[n - 1]'.
 */

int jump(int *nums, int numsSize) {
  if (numsSize < 2)
    return 0;
  if (nums[0] >= numsSize - 1)
    return 1;
  int cnt = 0, max = 0, min = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    max = nums[i] + i > max ? nums[i] + i : max;
    if (i == min) {
      min = max;
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int nums1[] = {2, 3, 1, 1, 14}, ns1 = 5;
  int nums2[] = {2, 3, 0, 1, 4}, ns2 = 5;
  printf("%d\n", jump(nums1, ns1)); // expect: 2
  printf("%d\n", jump(nums2, ns2)); // expect: 2
}
