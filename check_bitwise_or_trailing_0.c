// 2980. Check if Bitwise OR Has Trailing Zeros
#include "leetcode.h"

/*
 * given an array of positive integers 'nums'. you have to check if it is
 * possible to select two or more elements in the array such that the bitwise or
 * of the selected elements has at least one trailing zero in its binary
 * representation. return true if it is possible to select two or more elements
 * whose bitwise or has trailing zeros, return false otherwise.
 */

bool hasTrailingZeros(int *nums, int numsSize) {
  int cnt = 0;
  for (int i = 0; i < numsSize; i++)
    if (!(nums[i] % 2)) {
      cnt++;
      if (cnt == 2)
        return true;
    }
  return false;
}

int main() {
  int n1[] = {1, 2, 3, 4, 5}, n2[] = {2, 4, 8, 16}, n3[] = {1, 3, 5, 7, 9};
  printf("%d\n", hasTrailingZeros(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", hasTrailingZeros(n2, ARRAY_SIZE(n2))); // expect: 1
  printf("%d\n", hasTrailingZeros(n3, ARRAY_SIZE(n3))); // expect: 0
}
