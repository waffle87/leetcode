// 1752. Check if Array Is Sorted and Rotated
#include "leetcode.h"

/*
 * given an array 'nums', return 'true' if the array was originally sorted in
 * non-decreasing order, then rotated some number of positions (including zero).
 * otherwise return 'false'. there may be duplicates in the original array.
 * note: an array 'a' rotated by 'x' positions results in an array 'b' of the
 * same length such that 'a[i] == b[(i + x) % a.len]'.
 */

bool check(int *nums, int numsSize) {
  for (int i = 0, k = 0; i < numsSize; ++i)
    if (nums[i] > nums[(i + 1) % numsSize] && ++k > 1)
      return false;
  return true;
}

int main() {
  int n1[] = {3, 4, 5, 1, 2}, n2[] = {2, 1, 3, 4}, n3[] = {1, 2, 3};
  printf("%d\n", check(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", check(n2, ARRAY_SIZE(n2))); // expect: 0
  printf("%d\n", check(n3, ARRAY_SIZE(n3))); // expect: 1
}
