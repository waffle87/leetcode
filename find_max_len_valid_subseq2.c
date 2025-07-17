// 3202. Find the Maximum Length of Valid Subsequence II
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and a positive integer 'k'. a
 * subsequence 'sub' of 'nums' with length 'x' is called valid if it satisfies
 * '(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x
 * - 1]) % k'. return the length of the longest valid subsequence of 'nums'
 */

int maximumLength(int *nums, int numsSize, int k) {
  int *right = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i)
    right[i] = nums[i] % k;
  int **left = (int **)malloc(k * sizeof(int *));
  int *sizes = (int *)calloc(k, sizeof(int));
  for (int i = 0; i < k; ++i)
    left[i] = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) {
    int rem = right[i];
    left[rem][sizes[rem]++] = i;
  }
  int max = 0;
  for (int i = 0; i < k; ++i)
    if (sizes[i] > max)
      max = sizes[i];
  if (!k || k == 1) {
    for (int i = 0; i < k; ++i)
      free(left[i]);
    free(left), free(right), free(sizes);
    return max;
  }
  for (int x = 0; x < k; ++x)
    for (int y = x + 1; y < k; ++y) {
      int *a = left[x], la = sizes[x];
      int *b = left[y], lb = sizes[y];
      if (!la && !lb)
        continue;
      int i = 0, j = 0;
      int sx = 0, sy = 0;
      while (i < la || j < lb) {
        if (j == lb || (i < la && a[i] < b[j])) {
          int nx = sy > 0 ? sy + 1 : 1;
          if (nx > sx)
            sx = nx;
          ++i;
        } else {
          int ny = sx > 0 ? sx + 1 : 1;
          if (ny > sy)
            sy = ny;
          ++j;
        }
      }
      int curr = sx > sy ? sx : sy;
      if (curr > max)
        max = curr;
    }
  for (int i = 0; i < k; ++i)
    free(left[i]);
  free(left), free(right), free(sizes);
  return max;
}

int main() {
  int n1[] = {1, 2, 3, 4, 5}, n2[] = {1, 4, 2, 3, 1, 4};
  printf("%d\n", maximumLength(n1, ARRAY_SIZE(n1), 2)); // expect: 5
  printf("%d\n", maximumLength(n2, ARRAY_SIZE(n2), 3)); // expect: 4
}
