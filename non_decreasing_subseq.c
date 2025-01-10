// 491. Non-decreasing Subsequences
#include "leetcode.h"

/*
 * given: integer array 'nums'
 * return: all possible different non-decreasing subsequences
 * of given array with at least two elements. return value can be in any order
 */

int **ans, ansTop, *path, pathTop, *len;

bool find_used(int *uset, int usetSize, int key) {
  for (int i = 0; i < usetSize; i++)
    if (uset[i] == key)
      return true;
  return false;
}

void backtrack(int *nums, int numsSize, int startIdx) {
  if (pathTop >= 2) {
    int *tmp = (int *)malloc(pathTop * sizeof(int));
    for (int i = 0; i < pathTop; i++)
      tmp[i] = path[i];
    len[ansTop] = pathTop;
    ans[ansTop++] = tmp;
  }
  int *uset = (int *)malloc(numsSize * sizeof(int)), usetTop = 0;
  for (int i = startIdx; i < numsSize; i++) {
    if (pathTop > 0 && nums[i] < path[pathTop - 1] ||
        find_used(uset, usetTop, nums[i]))
      continue;
    uset[usetTop++] = nums[i];
    path[pathTop++] = nums[i];
    backtrack(nums, numsSize, i + 1);
    pathTop--;
  }
}

int **findSubsequences(int *nums, int numsSize, int *returnSize,
                       int **returnColumnSizes) {
  ans = (int **)malloc(10000 * sizeof(int *));
  path = (int *)malloc(numsSize * sizeof(int));
  len = (int *)malloc(10000 * sizeof(int));
  pathTop = 0;
  ansTop = 0;
  backtrack(nums, numsSize, 0);
  *returnSize = ansTop;
  *returnColumnSizes = (int *)malloc(ansTop * sizeof(int));
  for (int i = 0; i < ansTop; i++)
    (*returnColumnSizes)[i] = len[i];
  return ans;
}

int main() {
  int n1[] = {4, 6, 7, 7}, n2[] = {4, 4, 3, 2, 1};
  int rs1, rs2, *rcs1, *rcs2;
  int **fs1 = findSubsequences(n1, ARRAY_SIZE(n1), &rs1, &rcs1);
  int **fs2 = findSubsequences(n2, ARRAY_SIZE(n2), &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < *rcs1; j++)
      printf("%d ", fs1[i][j]);
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < *rcs2; j++)
      printf("%d ", fs2[i][j]);
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(fs1[i]);
  for (int i = 0; i < rs2; i++)
    free(fs2[i]);
}
