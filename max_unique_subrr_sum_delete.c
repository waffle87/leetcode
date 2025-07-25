// 3487. Maximum Unique Subarray Sum After Deletion
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. you are allowed to delete any number
 * of elements from 'nums' without making it empty. after performing the
 * deletions, select a subarray of 'nums' such that all elements in the subarray
 * are unique, and the sum of all elements in the subarray is maximised. return
 * the maximum sum of such a subarray
 */

int maxSum(int *nums, int numsSize) {
  bool negative = true;
  int max = INT_MIN;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] >= 0)
      negative = false;
    if (nums[i] > max)
      max = nums[i];
  }
  if (negative)
    return max;
  bool vis[101] = {false};
  for (int i = 0; i < numsSize; i++)
    if (nums[i] >= 0 && nums[i] < 101)
      vis[nums[i]] = true;
  int sum = 0;
  for (int i = 1; i < 101; i++)
    if (vis[i])
      sum += i;
  return sum;
}

int main() {
  int n1[] = {1, 2, 3, 4, 5}, n2[] = {1, 1, 0, 1, 1},
      n3[] = {1, 2, -1, -2, 1, 0, -1};
  printf("%d\n", maxSum(n1, ARRAY_SIZE(n1))); // expect: 15
  printf("%d\n", maxSum(n2, ARRAY_SIZE(n2))); // expect: 1
  printf("%d\n", maxSum(n3, ARRAY_SIZE(n3))); // expect: 3
}
