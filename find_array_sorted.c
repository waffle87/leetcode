// 3011. Find if Array Can Be Sorted
#include "leetcode.h"

/*
 * given a 0-indexed array of positive integers 'nums', in one operation you can
 * swap any two adjacent elements if they have the same number of set bits. you
 * are allowed to do this operation any number of times (including zero). return
 * true if you can sort the array, otherwise return false.
 */

bool canSortArray(int *nums, int numsSize) {
  int prev_cnt = 0, prev_max = INT_MIN, prev_min = 0;
  int curr_cnt, curr_max = 0, curr_min;
  for (int i = 0; i < numsSize; i++) {
    curr_cnt = __builtin_popcount(nums[i]);
    if (curr_cnt != prev_cnt) {
      if (curr_max < prev_max || curr_min < prev_max)
        return false;
      prev_max = curr_max;
      curr_max = nums[i];
      curr_min = nums[i];
      prev_cnt = curr_cnt;
    } else {
      curr_max = fmax(curr_max, nums[i]);
      curr_min = fmin(curr_min, nums[i]);
    }
  }
  if (curr_max < prev_max || curr_min < prev_max)
    return false;
  return true;
}

int main() {
  int n1[] = {8, 4, 2, 30, 15}, n2[] = {1, 2, 3, 4, 5}, n3[] = {3, 16, 8, 4, 2};
  printf("%d\n", canSortArray(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", canSortArray(n2, ARRAY_SIZE(n2))); // expect: 1
  printf("%d\n", canSortArray(n3, ARRAY_SIZE(n3))); // expect: 0
}
