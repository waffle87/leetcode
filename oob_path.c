// 576. Out of Boundary Paths
#include "leetcode.h"

/*
 * there is an 'm * n' grid with a ball. the ball is initially at the position
 * '[start_row, start_column]'. you are allowed to move the ball to one of the
 * four adjacent cells in the grid (possible out of the grid crossing the grid
 * boundary). you can apply at most 'max_move' moves to the ball. given the give
 * integers, 'm', 'n', 'max_move', 'start_row', 'and start_column', return the
 * number of paths to move the ball out of the grid boundary. since the answer
 * can be very large, return it modulo 10^9+7
 */

void dfs(int m, int n, int max, int x, int y, int k, long *cnt, long ***cache) {
  if (x >= m || x < 0 || y >= n || y < 0) {
    (*cnt)++;
    (*cnt) %= 1000000007;
    return;
  }
  if (cache[x][y][k] != -1) {
    (*cnt) = cache[x][y][k];
    return;
  }
  if (k == max)
    return;
  long a = 0, b = 0, c = 0, d = 0;
  dfs(m, n, max, x + 1, y, k + 1, &a, cache);
  dfs(m, n, max, x - 1, y, k + 1, &b, cache);
  dfs(m, n, max, x, y + 1, k + 1, &c, cache);
  dfs(m, n, max, x, y - 1, k + 1, &d, cache);
  cache[x][y][k] = a + b + c + d;
  cache[x][y][k] %= 1000000007;
  (*cnt) = cache[x][y][k];
}

int findPaths(int m, int n, int max_move, int start_row, int start_column) {
  if (!max_move)
    return 0;
  long ***cache = (long ***)malloc(m * sizeof(long **));
  for (int i = 0; i < m; i++) {
    cache[i] = (long **)malloc(n * sizeof(long *));
    for (int j = 0; j < n; j++) {
      cache[i][j] = (long *)malloc((max_move + 1) * sizeof(long));
      memset(cache[i][j], -1, (max_move + 1) * sizeof(long));
    }
  }
  long cnt = 0;
  dfs(m, n, max_move, start_row, start_column, 0, &cnt, cache);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      free(cache[i][j]);
  free(cache);
  return cnt;
}

int main() {
  printf("%d\n", findPaths(2, 2, 2, 0, 0)); // expect: 6
  printf("%d\n", findPaths(1, 3, 3, 0, 1)); // expect: 12
}
