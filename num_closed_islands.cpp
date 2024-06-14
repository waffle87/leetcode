// 1254. Number of Closed Islands
#include "leetcode.h"

/*
 * given 2d 'grid' consists of 0's (land) and 1's (water). an island is a
 * maximal four directionally connected group of 0's and a closed island is an
 * island totally (all left, top, right, bottom) surrouned by 1's. return the
 * number of closed islands.
 */

class Solution {
  int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
  bool is_valid(vvd(int) & grid, int i, int j, int r, int c) {
    if (i >= 0 && i < r && j >= 0 && j < c && grid[i][j] == 0)
      return true;
    else
      return false;
  }
  void dfs(vvd(int) & grid, int i, int j, int r, int c) {
    grid[i][j] = 1;
    for (int x = 0; x < 4; ++x) {
      int new_x = i + dx[x];
      int new_y = i + dy[x];
      if (is_valid(grid, new_x, new_y, r, c))
        dfs(grid, new_x, new_y, r, c);
    }
  }

public:
  int closedIsland(vvd(int) & grid) {
    int r = grid.size(), c = grid[0].size(), ans = 0;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        if (i * j == 0 || i == r - 1 || j == c - 1)
          if (grid[i][j] == 0)
            dfs(grid, i, j, r, c);
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        if (grid[i][j] == 0) {
          ans++;
          dfs(grid, i, j, r, c);
        }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) g1 = {{1, 1, 1, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0, 1, 1, 0},
                 {1, 0, 0, 0, 0, 1, 0, 1},
                 {1, 1, 1, 1, 1, 1, 1, 0}};
  vvd(int) g2 = {{0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}};
  vvd(int)
      g3 = {{1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1},
            {1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1}};
  printf("%d\n", obj.closedIsland(g1)); // expect: 2
  printf("%d\n", obj.closedIsland(g2)); // expect: 1
  printf("%d\n", obj.closedIsland(g3)); // expect: 2
}
