// 2441. Largest Positive Integer That Exists With Its Negative
#include "leetcode.h"

/*
 * given an integer array 'nums'that does not contain any zeros, find the
 * largest positive integer 'k' such that '-k' also exists in the array. return
 * the positive integer 'k'. if there is no such integer, return -1;
 */

int findMaxK(int *nums, int numsSize) {
  for (int i = 0; i < numsSize - 1; i++)
    for (int j = i + 1; j < numsSize; j++)
      if (nums[i] > nums[j]) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
      }
  int j = numsSize - 1, i = 0;
  while (i < j) {
    if (!(nums[i] + nums[j]))
      return nums[j];
    else if (nums[i] + nums[j] < 0)
      i++;
    else
      j--;
  }
  return -1;
}

int main() {
  int n1[] = {-1, 2 - 3, 3}, n2[] = {-1, 10, 6, 7, -7, 1},
      n3[] = {-10, 8, 6, 7, -2, -3};
  printf("%d\n", findMaxK(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", findMaxK(n2, ARRAY_SIZE(n2))); // expect: 7
  printf("%d\n", findMaxK(n3, ARRAY_SIZE(n3))); // expect: -1
}
