// 3471. Find the Largest Almost Missing Integer
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'k'. an integer 'x' is
 * almost missing from 'nums' if 'x' appears in exactly one subarray of size 'k'
 * within 'nums'. return the largest almost missing integer from 'nums'. if no
 * such integer exists, return -1. a subarray is a contiguous sequence of
 * elements within an array.
 */

int largestInteger(int *nums, int numsSize, int k) {
  int freq[51] = {0}, ans = -1;
  for (int i = 0; i < numsSize; i++)
    freq[nums[i]]++;
  for (int i = 0; i < numsSize; i++)
    if (k == numsSize ||
        (freq[nums[i]] == 1 && (k == 1 || !i || i == numsSize - 1)))
      ans = fmax(ans, nums[i]);
  return ans;
}

int main() {
  int n1[] = {3, 9, 2, 1, 7};
  int n2[] = {3, 9, 7, 2, 1, 7};
  int n3[] = {0, 0};
  int r1 = largestInteger(n1, ARRAY_SIZE(n1), 3);
  int r2 = largestInteger(n2, ARRAY_SIZE(n2), 4);
  int r3 = largestInteger(n3, ARRAY_SIZE(n3), 1);
  printf("%d\n", r1);
  assert(r1 == 7);
  printf("%d\n", r2);
  assert(r2 == 3);
  printf("%d\n", r3);
  assert(r3 == -1);
}
