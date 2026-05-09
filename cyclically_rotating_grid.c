// 1914. Cyclically Rotating a Grid
#include "leetcode.h"

/*
 * you are given an 'm x n' integer matrix 'grid', where 'm' and 'n' are both
 * even integers, and an integer 'k'. the matrix is composed of several layers.
 * a cyclic rotation of the matrix is done by rotating each layer once, each
 * element in the layer will take the place of the adjacent element in the
 * counter-clocwise direction. return the matrix after applying 'k' cyclic
 * rotations to it.
 */

int **rotateGrid(int **grid, int gridSize, int *gridColSize, int k,
                 int *returnSize, int **returnColumnSizes) {
  int m = gridSize, n = gridColSize[0];
  int **ans = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    ans[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++)
      ans[i][j] = grid[i][j];
  }
  *returnSize = m;
  *returnColumnSizes = (int *)malloc(m * sizeof(int));
  for (int i = 0; i < m; i++)
    (*returnColumnSizes)[i] = n;
  int num_layers = fmin(m, n) / 2, max_perimeter = 2 * (m + n);
  int *r_coords = (int *)malloc(max_perimeter * sizeof(int));
  int *c_coords = (int *)malloc(max_perimeter * sizeof(int));
  int *vals = (int *)malloc(max_perimeter * sizeof(int));
  for (int layer = 0; layer < num_layers; layer++) {
    int r1 = layer, c1 = layer;
    int r2 = m - 1 - layer, c2 = n - 1 - layer;
    int count = 0;
    for (int r = r1; r <= r2; r++) {
      r_coords[count] = r;
      c_coords[count] = c1;
      count++;
    }
    for (int c = c1 + 1; c <= c2; c++) {
      r_coords[count] = r2;
      c_coords[count] = c;
      count++;
    }
    for (int r = r2 - 1; r >= r1; r--) {
      r_coords[count] = r;
      c_coords[count] = c2;
      count++;
    }
    for (int c = c2 - 1; c > c1; c--) {
      r_coords[count] = r1;
      c_coords[count] = c;
      count++;
    }
    for (int i = 0; i < count; i++)
      vals[i] = grid[r_coords[i]][c_coords[i]];
    int shift = k % count;
    for (int i = 0; i < count; i++) {
      int r = r_coords[i];
      int c = c_coords[i];
      ans[r][c] = vals[(i + count - shift) % count];
    }
  }
  free(r_coords);
  free(c_coords);
  free(vals);
  return ans;
}

int main() {
  int g1i[2][2] = {{40, 10}, {30, 20}};
  int r1[2][2] = {{10, 20}, {40, 30}};
  int g2i[4][4] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int r2[4][4] = {
      {3, 4, 8, 12}, {2, 11, 10, 16}, {1, 7, 6, 15}, {5, 9, 13, 14}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  int rs1, *rcs1,
      **rg1 = rotateGrid(g1->arr, g1->row_size, g1->col_size, 1, &rs1, &rcs1);
  int rs2, *rcs2,
      **rg2 = rotateGrid(g2->arr, g2->row_size, g2->col_size, 2, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++) {
      printf("%d ", rg1[i][j]);
      assert(rg1[i][j] == r1[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++) {
      printf("%d ", rg2[i][j]);
      assert(rg2[i][j] == r2[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(rg1[i]);
  free(rg1);
  free(rcs1);
  for (int i = 0; i < rs2; i++)
    free(rg2[i]);
  free(rg2);
  free(rcs2);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
