// 945. Minimum Increment to Make Array Unique
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'nums'. in one move, you can pick an index 'i' where
 * '0 <= i  < nums.length' and increment 'nums[i]' by 1. return the minimum
 * number of moves to make every value in 'nums' unique. the test cases are
 * generated so that the answer fits in a 32-bit integer.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int minIncrementForUnique(int *nums, int nums_size) {
  qsort(nums, nums_size, sizeof(int), cmp);
  int ans = 0, min = nums[0];
  for (int i = 1; i < nums_size; i++) {
    if (nums[i] <= min) {
      ans += (min + 1 - nums[i]);
      nums[i] = min + 1;
    }
    min = nums[i];
  }
  return ans;
}

int main() {
  int n1[] = {1, 2, 2}, n2[] = {3, 2, 1, 2, 1, 7};
  printf("%d\n", minIncrementForUnique(n1, 3)); // expect: 1
  printf("%d\n", minIncrementForUnique(n2, 6)); // expect: 6
}
