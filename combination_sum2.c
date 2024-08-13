// 40. Combination Sum II
#include "leetcode.h"

/*
 * given a collection of candidate numbers and a target number, find all unique
 * combinations in 'candidates' where the candidate numbers sum to 'target'.
 * each number in 'candidates' may only be used once
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void dfs(int *candidates, int candidatesSize, int target, int idx, int *curr,
         int currSize, int *returnSize, int **returnColumnSizes, int ***res) {
  int prev = 0;
  for (int i = idx; i < candidatesSize; i++) {
    if (candidates[i] == target) {
      (*returnSize)++;
      *res = (int **)realloc(*res, (*returnSize) * sizeof(int *));
      (*res)[(*returnSize) - 1] = (int *)malloc((currSize + 1) * sizeof(int));
      memcpy((*res)[(*returnSize) - 1], curr, currSize * sizeof(int));
      (*res)[(*returnSize) - 1][currSize] = candidates[i];
      (*returnColumnSizes) =
          (int *)realloc((*returnColumnSizes), (*returnSize) * sizeof(int));
      (*returnColumnSizes)[(*returnSize) - 1] = currSize + 1;
      break;
    } else if (candidates[i] <= (target / 2) && candidates[i] != prev) {
      curr[currSize] = candidates[i];
      dfs(candidates, candidatesSize, target - candidates[i], i + 1, curr,
          currSize + 1, returnSize, returnColumnSizes, res);
      prev = candidates[i];
    } else if (candidates[i] > target)
      break;
  }
}

int **combinationSum2(int *candidates, int candidatesSize, int target,
                      int *returnSize, int **returnColumnSizes) {
  qsort(candidates, candidatesSize, sizeof(int), cmp);
  int *curr = (int *)malloc(100 * sizeof(int)), currSize = 0;
  int **ans = (int **)malloc(sizeof(int *));
  (*returnColumnSizes) = (int *)malloc(sizeof(int));
  (*returnSize) = 0;
  dfs(candidates, candidatesSize, target, 0, curr, currSize, returnSize,
      returnColumnSizes, &ans);
  free(curr);
  return ans;
}

int main() {
  int c1[] = {10, 1, 2, 7, 6, 1, 5}, c2[] = {2, 5, 2, 1, 2}, rs1, rs2;
  int *rcs1 = (int *)malloc(ARRAY_SIZE(c1) * sizeof(int));
  int *rcs2 = (int *)malloc(ARRAY_SIZE(c2) * sizeof(int));
  int **cs21 = combinationSum2(c1, ARRAY_SIZE(c1), 8, &rs1, (int **)rcs1);
  int **cs22 = combinationSum2(c2, ARRAY_SIZE(c2), 5, &rs2, (int **)rcs2);
  for (int i = 0; i < rs2; i++)
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", cs22[i][j]);
  printf("\n");
  free(cs21), free(cs22), free(rcs1), free(rcs2);
}
