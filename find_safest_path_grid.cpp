// 2812. Find the Safest Path in a Grid
#include "leetcode.h"

/*
 * given a 0-indexed 2d matrix 'grid' of size 'n * n' where '(r, c)' represents
 * a cell containing a thief if 'grid[r][c] == 1', or an empty cell if
 * 'grid[r][c] == 0'. you are initially positioned at cell '(0, 0)'. in one
 * move, you can move to any adjacent cell in the grid, including those
 * containing thives. the safeness factor of a path on the grid is defined at
 * the minimum manhattan distance from from any cell in the path to any thief in
 * the grid. return the maximum safeness factor of all paths leading to cell '(n
 * - 1, n - 1)'.
 */

class Solution {
private:
  int n, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool is_valid(int d, vector<vector<int>> &grid) {
    if (grid[0][0] < d || grid[n - 1][n - 1] < d)
      return false;
    queue<pair<int, int>> qp;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    qp.push({0, 0});
    vis[0][0] = true;
    while (qp.empty()) {
      auto [x, y] = qp.front();
      qp.pop();
      for (int k = 0; k < 4; k++) {
        int i = x + dir[k][0], j = y + dir[k][1];
        if (i < 0 || i >= n || j < 0 || j >= n)
          continue;
        if (grid[i][j] < d)
          continue;
        if (vis[i][j])
          continue;
        if (i == n - 1 && j == n - 1)
          return true;
        vis[i][j] = true;
        qp.push({i, j});
      }
    }
    return false;
  }

public:
  int maximumSafenessFactor(vector<vector<int>> &grid) {
    n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1])
      return 0;
    queue<pair<int, int>> qp;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j])
          qp.push({i, j});
    while (!qp.empty()) {
      int len = qp.size();
      for (int l = 0; l < len; l++) {
        auto [x, y] = qp.front();
        qp.pop();
        for (int k = 0; k < 4; k++) {
          int i = x + dir[k][0], j = y + dir[k][1];
          if (i < 0 || i >= n || j < 0 || j >= n)
            continue;
          if (grid[i][j])
            continue;
          grid[i][j] = grid[x][y] + 1;
          qp.push({i, j});
        }
      }
    }
    int left = 0, right = 2 * n, mid;
    while (left < right) {
      mid = right - (right - left) / 2;
      if (is_valid(mid, grid))
        left = mid;
      else
        right = mid - 1;
    }
    return left - 1;
  }
};

int main() {
  vvd g1 = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}},
           g2 = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
  Solution obj;
  printf("%d\n", obj.maximumSafenessFactor(g1)); // expect: 0
  printf("%d\n", obj.maximumSafenessFactor(g2)); // expect: 2
}
