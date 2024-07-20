// 1605. Find Valid Matrix Given Row and Column Sums
#include "leetcode.h"

/*
 * given two arrays 'rowSum' and 'colSum' of non negative integers where
 * 'rowSum[i]' is the sum of the elements in the i'th row and 'colSum[i]' is the
 * sum of the elemtns in the i'th row and 'colSum[j]' is the sum of the elemtns
 * of the j'th column of a 2d matrix. in other words, you do not know the
 * elements of the matrix, but you do know the sumes of each row and column.
 */

int **restoreMatrix(int *rowSum, int rowSumSize, int *colSum, int colSumSize,
                    int *returnSize, int **returnColumnSizes) {
  int *store = (int *)malloc(rowSumSize * colSumSize * sizeof(*store));
  int **ans = (int **)malloc(rowSumSize * sizeof(*ans));
  for (int i = 0; i < rowSumSize; i++)
    ans[i] = store + i * colSumSize;
  *returnSize = rowSumSize;
  *returnColumnSizes = (int *)malloc(rowSumSize * sizeof(*returnColumnSizes));
  for (int i = 0; i < rowSumSize; i++)
    (*returnColumnSizes)[i] = colSumSize;
  for (int i = 0; i < rowSumSize; i++)
    for (int j = 0; j < colSumSize; j++) {
      ans[i][j] = fmin(rowSum[i], colSum[j]);
      rowSum[i] -= ans[i][j];
      colSum[j] -= ans[i][j];
    }
  return ans;
}

int main() {
  int rs1[] = {3, 8}, cs1[] = {4, 7}, res1, rcs1[] = {2, 2};
  int rs2[] = {5, 7, 10}, cs2[] = {8, 6, 8}, res2, rcs2[] = {3, 3, 3};
  int **rm1 = restoreMatrix(rs1, ARRAY_SIZE(rs1), cs1, ARRAY_SIZE(cs1), &res1,
                            (int **)rcs1);
  int **rm2 = restoreMatrix(rs2, ARRAY_SIZE(rs2), cs2, ARRAY_SIZE(cs2), &res2,
                            (int **)rcs2);
  for (int i = 0; i < res1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", rm1[i][j]);
    printf("\n");
  }
  for (int i = 0; i < res2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", rm2[i][j]);
    printf("\n");
  }
  for (int i = 0; i < res1; i++)
    free(rm1[i]);
  for (int i = 0; i < res2; i++)
    free(rm2[i]);
  free(rm1), free(rm2);
}
