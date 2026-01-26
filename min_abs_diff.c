// 1200. Minimum Absolute Difference
#include "leetcode.h"

/*
 * given an array of distinct integers 'arr', find all pairs of elements with
 * the minimum absolute difference of any two elements. return a list of pairs
 * in ascending order (with respect to pairs), each pair '[a, b]' follows: 'a,
 * b' are from 'arr', 'a < b', and 'b - a' equals to the minimum absolute
 * difference of any two elements in 'arr'.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int **minimumAbsDifference(int *arr, int arrSize, int *returnSize,
                           int **returnColumnSizes) {
  qsort(arr, arrSize, sizeof(int), cmp);
  int **ans = (int **)malloc(arrSize * sizeof(int *));
  (*returnColumnSizes) = (int *)malloc(arrSize * sizeof(int));
  *returnSize = 0;
  int min = INT_MAX;
  for (int i = 1; i < arrSize; i++)
    min = fmin(min, arr[i] - arr[i - 1]);
  for (int i = 1; i < arrSize; i++)
    if (arr[i] - arr[i - 1] == min) {
      (*returnColumnSizes)[*returnSize] = 2;
      ans[*returnSize] = (int *)malloc(2 * sizeof(int));
      ans[*returnSize][0] = arr[i - 1];
      ans[(*returnSize)++][1] = arr[i];
    }
  return ans;
}

int main() {
  int a1[] = {4, 2, 1, 3}, rs1, *rcs1;
  int a2[] = {1, 3, 6, 10, 15}, rs2, *rcs2;
  int a3[] = {3, 8, -10, 23, 19, -4, -14, 27}, rs3, *rcs3;
  int **mad1 = minimumAbsDifference(a1, ARRAY_SIZE(a1), &rs1, &rcs1);
  int **mad2 = minimumAbsDifference(a2, ARRAY_SIZE(a2), &rs2, &rcs2);
  int **mad3 = minimumAbsDifference(a3, ARRAY_SIZE(a3), &rs3, &rcs3);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", mad1[i][j]);
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", mad2[i][j]);
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    for (int j = 0; j < rcs3[i]; j++)
      printf("%d ", mad3[i][j]);
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(mad1[i]);
  free(mad1);
  free(rcs1);
  for (int i = 0; i < rs2; i++)
    free(mad2[i]);
  free(mad2);
  free(rcs2);
  for (int i = 0; i < rs3; i++)
    free(mad3[i]);
  free(mad3);
  free(rcs3);
}
