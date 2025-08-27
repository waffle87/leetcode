// 3197. Find the Minimum Area to Cover All Ones II
#include "leetcode.h"

/*
 * you are giiven a 2d binary array 'grid'. you need to find 3 non-overlapping
 * rectangles having non-zero areas with horizontal and vertical sides such that
 * all the 1's in the 'grid' lie inside these rectangles. return the minimum
 * possible sum of the area of these rectangles. note that the rectangles are
 * allowed to touch.
 */

int min_area(int **grid, int gridSize, int gridColSize) {
  int left = 1e9, top = 1e9, right = -1, bottom = -1;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridColSize; j++) {
      if (grid[i][j] == 1) {
        if (j < left)
          left = j;
        if (i < top)
          top = i;
        if (j > right)
          right = j;
        if (i > bottom)
          bottom = i;
      }
    }
  }
  if (right == -1)
    return 0;
  return (right - left + 1) * (bottom - top + 1);
}

int **rotate(int **grid, int gridSize, int gridColSize) {
  int **res = (int **)malloc(gridColSize * sizeof(int *));
  for (int i = 0; i < gridColSize; i++)
    res[i] = (int *)malloc(gridSize * sizeof(int));
  for (int i = 0; i < gridSize; i++)
    for (int j = 0; j < gridColSize; j++)
      res[j][gridSize - 1 - i] = grid[i][j];
  return res;
}

int minimumSum(int **grid, int gridSize, int *gridColSize) {
  int ans = 1e9;
  for (int rot = 0; rot < 4; rot++) {
    int m = gridColSize[0];
    for (int i = 1; i < gridSize; i++) {
      int a1 = min_area(grid, i, m);
      for (int j = 1; j < m; j++) {
        int **p2 = (int **)malloc((gridSize - i) * sizeof(int *));
        int **p3 = (int **)malloc((gridSize - i) * sizeof(int *));
        for (int r = 0; r < gridSize - i; r++) {
          p2[r] = (int *)malloc(j * sizeof(int));
          p3[r] = (int *)malloc((m - j) * sizeof(int));
          for (int c = 0; c < j; c++)
            p2[r][c] = grid[i + r][c];
          for (int c = j; c < m; c++)
            p3[r][c - j] = grid[i + r][c];
        }
        int a2 = min_area(p3, gridSize - i, j);
        int a3 = min_area(p3, gridSize - i, m - j);
        if (a1 + a2 + a3 < ans)
          ans = a1 + a2 + a3;
      }
    }
    grid = rotate(grid, gridSize, gridColSize[0]);
    int tmp = gridSize;
    gridSize = gridColSize[0];
    gridColSize[0] = tmp;
  }
  return ans;
}

int main() {
  int g1i[2][3] = {{1, 0, 1}, {1, 1, 1}},
      g2i[2][4] = {{1, 0, 1, 0}, {0, 1, 0, 1}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  printf("%d\n", minimumSum(g1->arr, g1->row_size, g1->col_size)); // expect: 5
  printf("%d\n", minimumSum(g2->arr, g2->row_size, g2->col_size)); // expect: 5
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
