// 3651. Minimum Cost Path with Teleportations
#include "leetcode.h"

/*
 * you are given an 'm x n' 2d integer array 'grid' and an integer 'k'. you
 * start at the top-left cell '(0, 0)' and your goal is to reach the
 * bottom-right cell '(m - 1, n - 1)'. there are two types of moves available:
 * normal move you can move righ or down from your current cell '(i, j)' ie. you
 * can move to '(i, j + 1)' (right) or '(i + 1, j)' (down). the cost is the
 * value of the destination cell. teleportation you can teleport from any cell
 * '(i, j)' to any cell '(x, y)' such that 'grid[x][y] <= grid[i][j]'; the cost
 * of this move is 0. you may teleport at most 'k' times. return the minimum
 * total cost to reach cell (m - 1, n - 1) from '(0, 0)'.
 */

int minCost(int **grid, int gridSize, int *gridColSize, int k) {
  int m = gridSize, n = gridColSize[0];
  int total = (k + 1) * m * n;
  int *dp = (int *)malloc(total * sizeof(int));
  int *min_cost = (int *)malloc(10002 * sizeof(int));
  for (int i = 0; i < total; i++)
    dp[i] = INT_MAX;
  dp[0] = 0;
  for (int t = 0; t <= k; t++) {
    int offset = t * m * n;
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        int curr = offset + r * n + c;
        if (dp[curr] == INT_MAX)
          continue;
        int cost = dp[curr];
        if (r + 1 < m) {
          int down = offset + (r + 1) * n + c;
          long long next = (long long)cost + grid[r + 1][c];
          dp[down] = fmin(dp[down], next);
        }
        if (c + 1 < n) {
          int right = offset + r * n + (c + 1);
          long long next = (long long)cost + grid[r][c + 1];
          dp[right] = fmin(dp[right], next);
        }
      }
    }
    if (t < k) {
      for (int i = 0; i < 10002; i++)
        min_cost[i] = INT_MAX;
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          int idx = offset + r * n + c;
          if (dp[idx] != INT_MAX) {
            int val = grid[r][c];
            min_cost[val] = fmin(min_cost[val], dp[idx]);
          }
        }
      }
      int curr_min = INT_MAX;
      for (int v = 10000; v >= 0; v--) {
        if (min_cost[v] < curr_min)
          curr_min = min_cost[v];
        else
          min_cost[v] = curr_min;
      }
      int next = (t + 1) * m * n;
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          int val = grid[r][c];
          int idx = next + r * n + c;
          dp[idx] = fmin(dp[idx], min_cost[val]);
        }
      }
    }
  }
  int ans = INT_MAX, idx = (m - 1) * n + (n - 1);
  for (int t = 0; t <= k; t++) {
    int i = t * m * n + idx;
    ans = fmin(ans, dp[idx]);
  }
  free(dp);
  free(min_cost);
  return ans;
}

int main() {
  int g1i[3][3] = {{1, 3, 3}, {2, 5, 4}, {4, 3, 5}};
  int g2i[3][2] = {{1, 2}, {2, 3}, {3, 4}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  printf("%d\n", minCost(g1->arr, g1->row_size, g1->col_size, 2)); // expect: 7
  printf("%d\n", minCost(g2->arr, g2->row_size, g2->col_size, 1)); // expect: 9
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
