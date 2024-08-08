// 885. Spiral Matrix III
#include "leetcode.h"

/*
 * you start at the cell '(rStart, cStart)' of an 'rows * cols' grid facing
 * east. the northwest corner is at the first row and column in the grid, and
 * the southeast corner is at the last row and column. you will walk in a
 * clockwise spiral shape to visit every position in this gid. whenever you move
 * outside the grid's boundary, we continue our walk outside the grid (but may
 * return to the gid boundary later). eventually we reach all 'rows * cols'
 * spaces of the grid. return an array of coordinates representing the positions
 * of the grid in the order visited.
 */

int **spiralMatrixIII(int rows, int cols, int rStart, int cStart,
                      int *returnSize, int **returnColumnSizes) {
  *returnSize = rows * cols;
  *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));
  int **ans = (int **)malloc((*returnSize) * sizeof(int *));
  for (int i = 0; i < (*returnSize); i++) {
    ans[i] = (int *)calloc(2, sizeof(int));
    (*returnColumnSizes)[i] = 2;
  }
  ans[0][0] = rStart;
  ans[0][1] = cStart;
  int up = 1, right = 1, cnt_rl = 0, cnt_ud = 0, idx = 1;
  while (idx < (*returnSize)) {
    for (int shift = 1; shift <= right; shift++) {
      cStart = !(cnt_rl % 2) ? cStart + 1 : cStart - 1;
      if (rStart < rows && cStart < cols && rStart > -1 && cStart > -1) {
        ans[idx][0] = rStart;
        ans[idx][1] = cStart;
        idx++;
      }
    }
    cnt_rl++, right++;
    for (int shift = 1; shift <= up; shift++) {
      rStart = !(cnt_ud % 2) ? rStart + 1 : rStart - 1;
      if (rStart < rows && cStart < cols && rStart > -1 && cStart > -1) {
        ans[idx][0] = rStart;
        ans[idx][1] = cStart;
      }
    }
    cnt_ud++, up++;
  }
  return ans;
}

int main() {
  int rs1, rs2, **rcs1, **rcs2;
  int **sm31 = spiralMatrixIII(1, 4, 0, 0, &rs1, rcs1);
  int **sm32 = spiralMatrixIII(5, 6, 1, 4, &rs1, rcs2);
  for (int i = 0; i < rs1; i++)
    for (int j = 0; j < rcs1[i][j]; j++)
      printf("%d ", sm31[i][j]);
  printf("\n");
  for (int i = 0; i < rs2; i++)
    for (int j = 0; j < rcs2[i][j]; j++)
      printf("%d ", sm32[i][j]);
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(sm31[i]);
  for (int i = 0; i < rs2; i++)
    free(sm32[i]);
  free(sm31), free(sm32);
}
