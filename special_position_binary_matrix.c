// 1582. Special Positions in a Binary Matrix
#include "leetcode.h"

/*
 * given an 'm * n' binary matrix 'mat', return the number of special positions
 * in 'mat'. a position '(i, j)' is called special  if 'mat[i][j] == 1'  and all
 * other elements in a row and column are 0
 */

int numSpecial(int **mat, int matSize, int *matColSize) {
  int n = matSize, m = matColSize[0];
  int *row_sum = (int *)calloc(n, sizeof(int));
  int *col_sum = (int *)calloc(m, sizeof(int));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mat[i][j]) {
        row_sum[i]++;
        col_sum[j]++;
      }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mat[i][j] && row_sum[i] == 1 && col_sum[j] == 1)
        cnt++;
  free(row_sum);
  free(col_sum);
  return cnt;
}

int main() {
  int m1i[3][3] = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
  int m2i[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  int r1 = numSpecial(m1->arr, m1->row_size, m1->col_size);
  int r2 = numSpecial(m2->arr, m2->row_size, m2->col_size);
  printf("%d\n", r1); // expect: 1
  assert(r1 == 1);
  printf("%d\n", r2); // expect: 3
  assert(r2 == 3);
  two_d_arr_free(m1);
  two_d_arr_free(m2);
}
