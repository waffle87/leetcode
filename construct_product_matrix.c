// 2906. Construct Product Matrix
#include "leetcode.h"

/*
 * given a 0-indexed 2d integer matrix 'grid' of size 'n x m', we define a
 * 0-indexed 2d matrix 'p' of size 'n x m' as the product matrix of 'grid' if
 * the following condition is met: each element 'p[i][j]' is calculated as the
 * product of all elements in 'grid' excpet for the element 'grid[i][j]'. this
 * product is then taken modulo 12345. return the product matrix of 'grid'.
 */

int **constructProductMatrix(int **grid, int gridSize, int *gridColSize,
                             int *returnSize, int **returnColumnSizes) {
  const int mod = 12345;
  int m = gridSize, n = gridColSize[0];
  int **p = (int **)malloc(m * sizeof(int *));
  *returnColumnSizes = (int *)malloc(m * sizeof(int));
  for (int i = 0; i < m; i++) {
    p[i] = (int *)calloc(n, sizeof(int));
    (*returnColumnSizes)[i] = n;
  }
  *returnSize = n;
  long long suffix = 1;
  for (int i = m - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--) {
      p[i][j] = suffix % mod;
      suffix *= grid[i][j] % mod;
    }

  long long prefix = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      p[i][j] *= prefix % mod;
      prefix *= grid[i][j] % mod;
    }
  return p;
}

int main() {
  int g1i[2][2] = {{1, 2}, {3, 4}}, r1[2][2] = {{24, 12}, {8, 6}};
  int g2i[3][1] = {{12345}, {2}, {1}}, r2[3][1] = {{2}, {0}, {0}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  int rs1, *rcs1, rs2, *rcs2;
  int **cpm1 =
      constructProductMatrix(g1->arr, g1->row_size, g1->col_size, &rs1, &rcs1);
  int **cpm2 =
      constructProductMatrix(g2->arr, g2->row_size, g2->col_size, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++) {
      printf("%d ", cpm1[i][j]);
      assert(cpm1[i][j] == r1[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++) {
      printf("%d ", cpm2[i][j]);
      assert(cpm2[i][j] == r2[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(cpm1[i]);
  free(cpm1);
  for (int i = 0; i < rs2; i++)
    free(cpm2[i]);
  free(cpm2);
  free(rcs1);
  free(rcs2);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
