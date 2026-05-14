// 2784. Check if Array is Good
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. we consider an array good if it is a
 * permutation of an array 'base[n]'. 'base[n] = [1,2, ..., n - 1, n]'. return
 * true if the given array is good, otherwise return false. note: a permutation
 * of integers represents an arrangement of these numbers.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

bool isGood(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = 0; i < numsSize - 1; i++)
    if (nums[i] != i + 1)
      return false;
  return nums[numsSize - 1] == numsSize - 1;
}

int main() {
  int n1[] = {2, 1, 3}, n2[] = {1, 3, 3, 2}, n3[] = {1, 1};
  bool r1 = isGood(n1, ARRAY_SIZE(n1));
  bool r2 = isGood(n2, ARRAY_SIZE(n2));
  bool r3 = isGood(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == false);
  printf("%d\n", r2);
  assert(r2 == true);
  printf("%d\n", r3);
  assert(r3 == true);
}
