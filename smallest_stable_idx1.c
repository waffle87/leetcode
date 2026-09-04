// 3903. Smallest Stable Index I
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' and an integer 'k'. for
 * each index 'i', define its instability score as 'max(nums[0..i]) -
 * min(nums[i..n - 1])'. an index 'i' is called stable if its instability score
 * is less than or equal to 'k'. return the smallest stable index. if no such
 * index exists, return -1.
 */

int firstStableIndex(int *nums, int numsSize, int k) {
  int *suffix = (int *)malloc(numsSize * sizeof(int));
  int min = INT_MAX, max = 0;
  for (int i = numsSize - 1; i >= 0; i--) {
    min = fmin(min, nums[i]);
    suffix[i] = min;
  }
  for (int i = 0; i < numsSize; i++) {
    max = fmax(max, nums[i]);
    int score = max - suffix[i];
    if (score <= k) {
      free(suffix);
      return i;
    }
  }
  free(suffix);
  return -1;
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
