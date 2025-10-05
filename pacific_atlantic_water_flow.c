// 417. Pacific Atlantic Water Flow
#include "leetcode.h"

/*
 * there is an 'm x n' rectangular island that bords both the pacific and
 * atlantic ocean. the pacific ocean touches the island's left and top edges,
 * and the atlantic ocean touches the islands right and bottom edges. the island
 * is partitioned into a grid of square cells. you are given an 'm x n' integer
 * matrix 'heights' where 'heights[r][c]' represents the height above sea level
 * of the cell at coordinate '(r, c)'. the island receives a lot of rain, and
 * the rain water can flow to neighbouring cells directly in any cardinal
 * direction. return a 2d list of grid coordinates 'result' where 'result[i] =
 * [r_i, c_i]' denotes that rain water can flow from cell '(r_i, c_i)' to both
 * the pacific and atlantic oceans.
 */

#define MASK 0x1FFFF
#define PACIFIC 0x40000000
#define ATLANTIC 0x20000000
#define BOTH 0x60000000

int check_inner(int **heights, int heightsSize, int heightsColSize, int type,
                int row, int col) {
  heights[row][col] |= type;
  int res = (heights[row][col] & BOTH) == BOTH;
  int val = heights[row][col] & MASK;
  if (row && !(heights[row - 1][col] & type) &&
      (heights[row - 1][col] & MASK) >= val)
    res +=
        check_inner(heights, heightsSize, heightsColSize, type, row - 1, col);
  if (col && !(heights[row][col - 1] & type) &&
      (heights[row][col - 1] & MASK) >= val)
    res +=
        check_inner(heights, heightsSize, heightsColSize, type, row, col - 1);
  if (col < heightsColSize && !(heights[row][col + 1] & type) &&
      (heights[row][col + 1] & MASK) >= val)
    res +=
        check_inner(heights, heightsSize, heightsColSize, type, row, col + 1);
  if (row < heightsSize && !(heights[row + 1][col] & type) &&
      (heights[row + 1][col] & MASK) >= val)
    res +=
        check_inner(heights, heightsSize, heightsColSize, type, row + 1, col);
  return res;
}

int **pacificAtlantic(int **heights, int heightsSize, int *heightsColSize,
                      int *returnSize, int **returnColumnSizes) {
  int n = heightsSize - 1, m = *heightsColSize - 1;
  for (int i = 0; i < m; i++)
    if (!(heights[0][i] & PACIFIC))
      check_inner(heights, n, m, PACIFIC, 0, i);
  for (int i = 1; i <= n; i++)
    if (!(heights[i][0] & PACIFIC))
      check_inner(heights, n, m, PACIFIC, i, 0);
  int res_size = 0;
  for (int i = 0; i <= m; i++)
    if (!(heights[n][i] & ATLANTIC))
      res_size += check_inner(heights, n, m, ATLANTIC, n, i);
  for (int i = 0; i < n; i++)
    if (!(heights[i][m] & ATLANTIC))
      res_size += check_inner(heights, n, m, ATLANTIC, i, m);
  *returnSize = res_size;
  *returnColumnSizes = (int *)malloc(res_size * sizeof(int));
  int **ans = (int **)malloc(res_size * sizeof(int *));
  res_size = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      if ((heights[i][j] & BOTH) == BOTH) {
        (*returnColumnSizes)[res_size] = 2;
        ans[res_size] = (int *)malloc(2 * sizeof(int));
        ans[res_size][0] = i;
        ans[res_size][1] = j;
        res_size++;
      }
  return ans;
}

int main() {
  int h1i[5][5] = {{1, 2, 2, 3, 5},
                   {3, 2, 3, 4, 4},
                   {2, 4, 5, 3, 1},
                   {6, 7, 1, 4, 5},
                   {5, 1, 1, 2, 4}},
      h2i[1][1] = {{1}};
  struct two_d_arr *h1 =
      two_d_arr_init(ARRAY_SIZE(h1i), ARRAY_SIZE(h1i[0]), h1i);
  struct two_d_arr *h2 =
      two_d_arr_init(ARRAY_SIZE(h2i), ARRAY_SIZE(h2i[0]), h2i);
  int rs1, *rcs1,
      **pa1 = pacificAtlantic(h1->arr, h1->row_size, h1->col_size, &rs1, &rcs1);
  int rs2, *rcs2,
      **pa2 = pacificAtlantic(h2->arr, h2->row_size, h2->col_size, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ",
             pa1[i][j]); // expect: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
    printf("\n");
  }
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", pa2[i][j]); // expect: [[0,0]]
    printf("\n");
  }
  for (int i = 0; i < rs1; i++)
    free(pa1[i]);
  free(pa1);
  free(rcs1);
  for (int i = 0; i < rs2; i++)
    free(pa2[i]);
  free(pa2);
  free(rcs2);
}
