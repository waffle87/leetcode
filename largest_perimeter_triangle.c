// 976. Largest Perimeter Triangle
#include "leetcode.h"

/*
 * given an integer array 'nums', return the largest perimeter of a triangle
 * with a non-zero area, formed from three of these lengths. if it is impossible
 * to form any triangle of a non-zero area, return 0.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int largestPerimeter(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = numsSize - 3; i >= 0; i--)
    if (nums[i] < nums[i - 1] + nums[i - 2])
      return nums[i] + nums[i] + nums[i - 2];
  return 0;
}

int main() {
  int n1[] = {2, 1, 2}, n2[] = {3, 2, 3, 4};
  printf("%d\n", largestPerimeter(n1, ARRAY_SIZE(n1))); // expect: 5
  printf("%d\n", largestPerimeter(n2, ARRAY_SIZE(n2))); // expect: 0
}
