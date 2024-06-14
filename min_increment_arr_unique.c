// 945. Minimum Increment to Make Array Unique
#include "leetcode.h"

/*
 * given an integer array 'nums'. in one move you can pick an index i where 0 <=
 * i < nums.len and increment nums[i] by 1. return the minimum number of moves
 * to make every value in nums unique. the test cases are generated so that the
 * answer fits in a 32 bit integer.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int minIncrementForUnique(int *nums, int numsSize) {
  int ans = 0, min;
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = 1; i < numsSize; i++) {
    min = nums[0];
    if (nums[i] > min)
      min = nums[i];
    else
      ans += (++min) - nums[i];
  }
  return ans;
}

int main() {
  int n1[] = {1, 2, 2}, n2[] = {3, 2, 1, 2, 1, 7};
  printf("%d\n", minIncrementForUnique(n1, sizeof(n1))); // expect: 1
  printf("%d\n", minIncrementForUnique(n2, sizeof(n2))); // expect: 1
}
