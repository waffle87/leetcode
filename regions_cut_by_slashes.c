// 959. Regions Cut By Slashes
#include "leetcode.h"

/*
 * an 'n * n' grid is composed of 1 * 1 squares where each 1 * 1 square consists
 * of a '/' or '\' or blank space ' '. these characters divide the square into
 * contiguous regions. given the grid 'grid' represented as a string array,
 * return the number of regions. note that backslash characters are escaped.
 */

void dfs(int **grid, int x, int y, int n) {
  if (x < 0 || x >= 3 * n || y < 0 || y >= 3 * n || grid[x][y])
    return;
  grid[x][y] = -1;
  dfs(grid, x + 1, y, n);
  dfs(grid, x - 1, y, n);
  dfs(grid, x, y + 1, n);
  dfs(grid, x, y - 1, n);
}

int regionsBySlashes(char **grid, int gridSize) {
  int expand_size = gridSize * 3, ans = 0;
  int **expand = (int **)malloc(expand_size * sizeof(int *));
  for (int i = 0; i < expand_size; i++) {
    expand[i] = (int *)malloc(expand_size * sizeof(int));
    memset(expand[i], 0, expand_size * sizeof(int));
  }
  for (int i = 0; i < gridSize; i++)
    for (int j = 0; j < gridSize; j++)
      if (grid[i][j] == '/') {
        expand[i * 3][j * 3 + 2] = 1;
        expand[i * 3 + 2][j * 3 + 1] = 1;
        expand[i * 3 + 2][j * 3] = 1;
      } else if (grid[i][j] == '\\') {
        expand[i * 3][j * 3] = 1;
        expand[i * 3 + 2][j * 3 + 1] = 1;
        expand[i * 3 + 2][j * 3 + 2] = 1;
      }
  for (int i = 0; i < expand_size; i++)
    for (int j = 0; j < expand_size; j++)
      if (!expand[i][j]) {
        dfs(expand, i, j, gridSize);
        ans++;
      }
  for (int i = 0; i < expand_size; i++)
    free(expand[i]);
  free(expand);
  return ans;
}

int main() {
  char *g1[] = {" /", "/ "}, *g2[] = {" /", "  "}, *g3[] = {"/\\", "\\/"};
  printf("%d\n", regionsBySlashes((char **)g1, ARRAY_SIZE(g1))); // expect: 2
  printf("%d\n", regionsBySlashes((char **)g2, ARRAY_SIZE(g2))); // expect: 1
  printf("%d\n", regionsBySlashes((char **)g3, ARRAY_SIZE(g3))); // expect: 5
}
