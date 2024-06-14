// 1992. Find All Groups of Farmland
#include "leetcode.h"

/*
 * given a 0-indexed 'm * n' binary matrix 'land' where a 0 represents a hectare
 * of forested land and a 1 represents a hectare of farmland. to keep the land
 * organised, there are designated rectangular areas of hectares that consist
 * entirely of farmland. these rectangular areas are called groups. no two
 * groups are adjacent, meaning farmland in one group is not four directionally
 * adjacent to another farmland in another group. return a 2d array containing
 * the 4 length arrays described above for each group o farmland in 'land'.
 */

void dfs(int **land, int rows, int cols, int r, int c, int *top_left,
         int *bottom_right, int *count) {
  if (r < 0 || r >= rows || c < 0 || c >= cols || !land[r][c])
    return;
  (*count)++;
  if (r < top_left[0])
    top_left[0] = r;
  if (c < top_left[1])
    top_left[1] = c;
  if (r > bottom_right[0])
    bottom_right[0] = r;
  if (c > bottom_right[1])
    bottom_right[1] = c;
  land[r][c] = 0;
  dfs(land, rows, cols, r + 1, c, top_left, bottom_right, count);
  dfs(land, rows, cols, r - 1, c, top_left, bottom_right, count);
  dfs(land, rows, cols, r, c + 1, top_left, bottom_right, count);
  dfs(land, rows, cols, r, c - 1, top_left, bottom_right, count);
}

int **findFarmland(int **land, int landSize, int *landColSize, int *returnSize,
                   int **returnColumnSizes) {
  int m = landSize, n = *landColSize;
  int **ans = (int **)malloc(sizeof(int *) * m * n);
  *returnColumnSizes = (int *)malloc(sizeof(int) * (m * n));
  *returnSize = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (land[i][j] == '1') {
        int top_left[2] = {i, j}, bottom_right[2] = {i, j}, cnt = 0, group[4];
        dfs(land, m, n, i, j, top_left, bottom_right, &cnt);
        group[0] = top_left[0];
        group[1] = top_left[1];
        group[2] = bottom_right[0];
        group[3] = bottom_right[1];
        ans[*returnSize] = group;
        (*returnColumnSizes)[*returnSize] = 4;
        (*returnSize)++;
      }
  return ans;
}
