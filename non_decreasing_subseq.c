// 491. Non-decreasing Subsequences
#include <stdio.h>
#include <stdlib.h>

/*
 * given: integer array 'nums'
 * return: all possible different non-decreasing subsequences
 * of given array with at least two elements. return value can be in any order
 *
 * returns an array of arrays of size '*returnSize'
 * sizes of the arrays are returned as '*returnColumnSizes' array
 * note: both returned array and '*columnSizes' array must be malloc'd
 * (assume caller free()'s)
 */

int **ans, ansTop, *path, pathTop, *len;

int findUsed(int *uset, int usetSize, int key) {
  for (int i = 0; i < usetSize; i++)
    if (uset[i] == key)
      return 1;
  return 0;
}

void backtracking(int *nums, int numsSize, int startIdx) {
  if (pathTop >= 2) {
    int *tmp = malloc(sizeof(int) * pathTop);
    for (int i = 0; i < pathTop; i++)
      tmp[i] = path[i];
    len[ansTop] = pathTop;
    ans[ansTop++] = tmp;
  }
  int *uset = malloc(sizeof(int) * numsSize), usetTop = 0;
  for (int i = startIdx; i < numsSize; i++) {
    if (pathTop > 0 && nums[i] < path[pathTop - 1] ||
        findUsed(uset, usetTop, nums[i]))
      continue;
    uset[usetTop++] = nums[i];
    path[pathTop++] = nums[i];
    backtracking(nums, numsSize, i + 1);
    pathTop--;
  }
}

int **findSubsequences(int *nums, int numsSize, int *returnSize,
                       int **returnColumnSizes) {
  ans = malloc(sizeof(int *) * 40000);
  path = malloc(sizeof(int) * numsSize);
  len = malloc(sizeof(int) * 40000);
  pathTop = ansTop = 0;
  backtracking(nums, numsSize, 0);
  *returnSize = ansTop;
  *returnColumnSizes = malloc(sizeof(int) * ansTop);
  for (int i = 0; i < ansTop; i++)
    (*returnColumnSizes)[i] = len[i];
  return ans;
}

int main() { int nums1[] = {4, 6, 7, 7}, nums2[] = {4, 4, 3, 2, 1}; }
