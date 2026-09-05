// 3904. Smallest Stable Index II
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' and an integer 'k'. for
 * each index 'i', define its instability score as 'max(nums[0..i]) -
 * min(nums[i..n - 1])'. an index 'i' is called stable if its instability score
 * is less than or equal to 'k'. return the smallest stable index. if no such
 * index exists, return -1.
 */

int firstStableIndex(int *nums, int numsSize, int k) {
  int idx = 0, ans_max = INT_MIN, total_max = INT_MIN;
  for (int i = 0; i < numsSize; i++) {
    total_max = fmax(total_max, nums[i]);
    if (i == idx)
      ans_max = fmax(ans_max, nums[i]);
    if (nums[i] < ans_max - k) {
      idx = i + 1;
      ans_max = total_max;
    }
  }
  return idx < numsSize ? idx : -1;
}

int main() {
  int n1[] = {5, 0, 1, 4};
  int n2[] = {3, 2, 1};
  int n3[] = {0};
  int r1 = firstStableIndex(n1, ARRAY_SIZE(n1), 3);
  int r2 = firstStableIndex(n2, ARRAY_SIZE(n2), 1);
  int r3 = firstStableIndex(n3, ARRAY_SIZE(n3), 0);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == -1);
  printf("%d\n", r3);
  assert(r3 == 0);
}
