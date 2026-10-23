// 3644. Maximum K to Sort a Permutation
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' where 'nums' is a
 * permutation of the numbers in the range '[0 ... n - 1]'. you may swap
 * elements at indices 'i' and 'j' only if 'nums[i] & nums[j] == k' where '&'
 * denote the bitwise and operation. return the maximum value of 'k' such that
 * the array can be sorted in non-decreasing order using any number of such
 * swaps. if 'nums' is already sorted, return 0.
 */

int sortPermutation(int *nums, int numsSize) {
  int k = -1;
  for (int i = 0; i < numsSize; i++)
    if (nums[i] != i) {
      k &= nums[i];
      if (!k)
        return 0;
    }
  return fmax(k, 0);
}

int main() {
  int n1[] = {0, 3, 2, 1};
  int n2[] = {0, 1, 3, 2};
  int n3[] = {3, 2, 1, 0};
  int r1 = sortPermutation(n1, ARRAY_SIZE(n1));
  int r2 = sortPermutation(n2, ARRAY_SIZE(n2));
  int r3 = sortPermutation(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 0);
}
