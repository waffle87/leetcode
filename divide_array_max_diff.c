// 2966. Divide Array Into Arrays With Max Difference
#include "leetcode.h"

/*
 * given an integer array 'nums' of size 'n' and a positive integer 'k'. divide
 * the array into one or more arrays of size 3 satisfying the following
 * conditions. each element of 'nums' should be in exactly one array. the
 * different between any two elements in one array is less than or equal to 'k'.
 * return a 2d array containing all the arrays if it is impossible to satisfy
 * the conditions, return an empty array. and if there are multiple answers,
 * return any of them
 */

int cmp(const void *a, const void *b) { return (*(int *)a) - (*(int *)b); }

int **divideArray(int *nums, int numsSize, int k, int *returnSize,
                  int **returnColumnSizes) {
  int num_arr = numsSize / 3;
  int **ans = (int **)calloc(num_arr, sizeof(int *));
  *returnColumnSizes = (int *)calloc(num_arr, sizeof(int));
  *returnSize = 0;
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = 0; i < num_arr; i++) {
    ans[i] = (int *)calloc(3, sizeof(int));
    (*returnColumnSizes)[i] = 3;
    for (int j = 0; j < 3; j++) {
      int idx = i * 3 + j;
      if (j && nums[idx] - nums[i * 3] > k)
        return ans;
      ans[i][j] = nums[idx];
    }
  }
  *returnSize = num_arr;
  return ans;
}
