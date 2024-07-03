// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
#include "leetcode.h"

/*
 * given an integer array 'nums'. in one move you can choose one element of
 * 'nums' and change it to any value. return the minimum difference between the
 * largest and smallest value of 'nums' after performing at most three moves.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int minDifference(int *nums, int numsSize) {
  if (numsSize <= 3)
    return 0;
  qsort(nums, numsSize, sizeof(int), cmp);
  int a, b, c, d;
  a = nums[numsSize - 4] - nums[0];
  b = nums[numsSize - 3] - nums[1];
  c = nums[numsSize - 2] - nums[2];
  d = nums[numsSize - 1] - nums[3];
  return fmin(fmin(a, b), fmin(c, d));
}

int main() {
  int n1[] = {5, 3, 2, 4}, n2[] = {1, 5, 0, 10, 14}, n3[] = {3, 100, 20};
  printf("%d\n", minDifference(n1, ARRAY_SIZE(n1))); // expect: 0
  printf("%d\n", minDifference(n2, ARRAY_SIZE(n2))); // expect: 1
  printf("%d\n", minDifference(n3, ARRAY_SIZE(n3))); // expect: 0
}
