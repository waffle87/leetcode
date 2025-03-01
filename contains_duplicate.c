// 217. Contains Duplicate
#include "leetcode.h"

/*
 * given an integer array 'nums', return true if any value appears at least
 * twice in the array, and return false if every element is distinct
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

bool containsDuplicate(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = 1; i < numsSize; i++)
    if (nums[i] == nums[i - 1])
      return true;
  return false;
}

int main() {
  int n1[] = {1, 2, 3, 1}, n2[] = {1, 2, 3, 4},
      n3[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  printf("%d\n", containsDuplicate(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", containsDuplicate(n2, ARRAY_SIZE(n2))); // expect: 0
  printf("%d\n", containsDuplicate(n3, ARRAY_SIZE(n3))); // expect: 1
}
