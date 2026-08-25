// 3718. Smallest Missing Multiple of K
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'k', return the smallest
 * positive muliple of  lk that is missing from 'nums'. a multiple of 'k' is any
 * positive integer divisible by 'k'.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int missingMultiple(int *nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int m = k;
  for (int i = 0; i < numsSize; i++)
    if (nums[i] == k)
      m += k;
  return m;
}

int main() {
  int n1[] = {8, 2, 3, 4, 6};
  int n2[] = {1, 4, 7, 10, 15};
  int r1 = missingMultiple(n1, ARRAY_SIZE(n1), 2);
  int r2 = missingMultiple(n2, ARRAY_SIZE(n2), 5);
  printf("%d\n", r1);
  assert(r1 == 10);
  printf("%d\n", r2);
  assert(r2 == 5);
}
