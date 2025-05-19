// 3024. Type of Triangle
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' of size 3 which can form the
 * sides of a triangle. return a string representing the type of triangle that
 * can be formed, or none if it cannot form a triangle.
 */

inline void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

char *triangleType(int *nums, int numsSize) {
  for (int i = 0; i < 2; i++) {
    if (nums[2] < nums[i])
      swap(&nums[i], &nums[2]);
    else if (nums[1] < nums[i])
      swap(&nums[i], &nums[1]);
  }
  if (nums[2] >= nums[0] + nums[1])
    return "none";
  if (nums[0] == nums[2])
    return "equilateral";
  if (nums[0] == nums[1] || nums[1] == nums[2])
    return "isosceles";
  return "scalene";
}

int main() {
  int n1[] = {3, 3, 3}, n2[] = {3, 4, 5};
  printf("%s\n", triangleType(n1, ARRAY_SIZE(n1))); // expect: equilateral
  printf("%s\n", triangleType(n2, ARRAY_SIZE(n2))); // expect: scalene
}
