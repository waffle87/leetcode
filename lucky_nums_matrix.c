// 1380. Lucky Numbers in a Matrix
#include "leetcode.h"

/*
 * given an 'm * n' matrix of distinct numbers, return all lucky numbers in the
 * matrix in any order. a lucky number is an element of the matrix such that it
 * is the minimum element in its row and maximum in its column
 */

int *luckyNumbers(int **matrix, int matrixSize, int *matrixColSize,
                  int *returnSize) {
  int n = 0, *ans = (int *)malloc((matrixSize + 1) * sizeof(int));
  for (int r = 0; r < matrixSize; r++)
    for (int c = 0; c < *matrixColSize; c++) {
      int curr = matrix[r][c];
      bool flag1 = false, flag2 = false;
      for (int i = 0; !flag1 && i < *matrixColSize; i++)
        if (matrix[r][i] < curr)
          flag1 = true;
      for (int i = 0; !flag2 && i < matrixSize; i++)
        if (matrix[i][c] > curr)
          flag2 = true;
      if (!flag1 && !flag2) {
        ans[n] = curr;
        n++;
      }
    }
  *returnSize = n;
  return ans;
}

int main() {
  int m1[3][3] = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}},
      m2[3][4] = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}},
      m3[2][2] = {{7, 8}, {1, 2}};
  int mcs1[] = {3, 3, 3}, mcs2[] = {3, 3, 3, 3}, mcs3[] = {2, 2}, rs1, rs2, rs3;
  int *ln1 = luckyNumbers((int **)m1, ARRAY_SIZE(m1), mcs1, &rs1);
  int *ln2 = luckyNumbers((int **)m2, ARRAY_SIZE(m2), mcs2, &rs2);
  int *ln3 = luckyNumbers((int **)m3, ARRAY_SIZE(m3), mcs3, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ln1[i]); // expect: 15
  printf("\n");
  for (int i = 0; i < rs1; i++)
    printf("%d ", ln1[i]); // expect: 15
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ln2[i]); // expect: 12
  for (int i = 0; i < rs3; i++)
    printf("%d ", ln3[i]); // expect: 7
  printf("\n");
  free(ln1), free(ln2), free(ln3);
}
