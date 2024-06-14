// 1608. Special Array With X Elements Greater Than or Equal X
#include "leetcode.h"

/*
 * given an array 'nums' of non negative integers. 'nums' is considered special
 * if there exists a number 'x' such that there are exactly 'x' numbers in
 * 'nums' that are greater than or equal to 'x'. notice that 'x' does not have
 * to be an element in 'nums'. return 'x' if the array is special, otherwise,
 * return -1. it can be proven that if 'nums' is special, the value for 'x' is
 * unique.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int specialArray(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = 0; i < numsSize; i++)
    if (nums[i] >= numsSize - i) {
      if (!i)
        return numsSize - i;
      else {
        if (nums[i - 1] < numsSize - i)
          return numsSize - i;
      }
    }
  return -1;
}

int main() {
  int n1[] = {3, 5}, n2[] = {0, 0}, n3[] = {0, 4, 3, 0, 4};
  printf("%d\n", specialArray(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", specialArray(n2, ARRAY_SIZE(n2))); // expect: -1
  printf("%d\n", specialArray(n3, ARRAY_SIZE(n3))); // expect: 3
}
