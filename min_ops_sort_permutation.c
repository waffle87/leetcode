// 3942. Minimum Operations to Sort a Permutation
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' where 'nums' is a
 * permutation of the integers from 0 to 'n - 1'. you may perform only the
 * following operations: reverse the entire array, rotate left by one: move the
 * first element to the end of the array, and rest elements to the left by one
 * position. return an integer denoting the minimum number of operations
 * required to sort the array in increasing order. if it is not possible to sort
 * the array using only the given operations return -1.
 */

int minOperations(int *nums, int numsSize) {
  int n = numsSize, k = nums[0], ans = INT_MAX;
  bool forward = true, reverse = true;
  for (int i = 0; i < n; i++) {
    if (nums[i] != (k + i) % n)
      forward = false;
    if (nums[i] != ((k - i) % n + n) % n)
      reverse = false;
  }
  if (forward)
    ans = fmin((n - k) % n, k + 2);
  if (reverse)
    ans = fmin(ans, fmin(1 + (k + 1) % n, 1 + (n - k - 1) % n));
  return ans == INT_MAX ? -1 : ans;
}

int main() {
  int n1[] = {0, 2, 1};
  int n2[] = {1, 0, 2};
  int n3[] = {2, 0, 1, 3};
  int r1 = minOperations(n1, ARRAY_SIZE(n1));
  int r2 = minOperations(n2, ARRAY_SIZE(n2));
  int r3 = minOperations(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == -1);
}
