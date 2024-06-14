// 78. Subsets
#include "leetcode.h"

/*
 * given an integer array 'nums' of unique elements return all possible subsets
 * (the power set). the solution set must not contain duplicate subsets. return
 * the solution in any order.
 */

void dfs(int *nums, int numsSize, int **res, int *returnSize,
         int **returnColumnSizes, int *tmp, int target_size, int idx,
         int start) {
  if (idx == target_size) {
    *returnColumnSizes[*returnSize] = idx;
    res[*returnSize] = (int *)malloc(idx * sizeof(int));
    if (target_size)
      memcpy(res[*returnSize], tmp, idx * sizeof(int));
    (*returnSize)++;
  } else {
    for (int i = start; i < numsSize; i++) {
      tmp[idx] = nums[i];
      dfs(nums, numsSize, res, returnSize, returnColumnSizes, tmp, target_size,
          idx + 1, i + 1);
    }
  }
}

int **subsets(int *nums, int numsSize, int *returnSize,
              int **returnColumnSizes) {
  int size = pow(2, numsSize);
  *returnSize = 0;
  *returnColumnSizes = (int *)malloc(size * sizeof(int));
  int **ans = (int **)malloc(size * sizeof(int));
  int *tmp = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i <= numsSize; i++)
    dfs(nums, numsSize, ans, returnSize, returnColumnSizes, tmp, i, 0, 0);
  free(tmp);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3}, n2[] = {0}, rs1, rs2, **rcs1, **rcs2;
  int **s1 = subsets(n1, ARRAY_SIZE(n1), &rs1, rcs1);
  int **s2 = subsets(n2, ARRAY_SIZE(n2), &rs2, rcs2);
  for (int i = 0; i < rs1; i++)
    for (int j = 0; j < *rcs1[i]; j++)
      printf("%d ", s1[i][j]); // [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    for (int j = 0; j < *rcs2[i]; j++)
      printf("%d ", s2[i][j]); // expect: [[],[0]]
  printf("\n");
}
