// 498. Diagonal Traverse
#include "leetcode.h"

/*
 * given an 'm x n' matrix 'mat', return an array of all the elements of the
 * array in a diagonal order.
 */

int *findDiagonalOrder(int **mat, int matSize, int *matColSize,
                       int *returnSize) {
  int n = matSize * matColSize[0], row = 0, col = 0;
  int *ans = (int *)malloc(n * sizeof(int));
  *returnSize = n;
  for (int i = 0; i < n; i++) {
    ans[i] = mat[row][col];
    if (!((row + col) % 2)) {
      if (col == matSize - 1)
        row++;
      else if (!row)
        col++;
      else {
        row--;
        col++;
      }
    } else {
      if (row == matColSize[0] - 1)
        col++;
      else if (!col)
        row++;
      else {
        row++;
        col--;
      }
    }
  }
  return ans;
}

int main() {
  int m1i[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
      m2i[2][2] = {{1, 2}, {3, 4}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  int rs1, *fdo1 = findDiagonalOrder(m1->arr, m1->row_size, m1->col_size, &rs1);
  int rs2, *fdo2 = findDiagonalOrder(m2->arr, m2->row_size, m2->col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fdo1[i]); // expect: 1 2 4 7 5 3 6 8 9
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fdo2[i]); // expect: 1 2 3 4
  printf("\n");
  free(fdo1);
  free(fdo2);
  two_d_arr_free(m1);
  two_d_arr_free(m2);
}
