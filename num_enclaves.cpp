// 1020. Number of Enclaves
#include "leetcode.h"

/*
 * given an 'm * n' binary matrix grid, where 0 represents a sea
 * cell and 1 represents a land cell. a move consists of walking
 * from one land cell to another adjacent (4-directionally) land
 * cell o walking off the boundary of the 'grid'. return number
 * of land cells in 'grid' for which we cannot walk off the
 * boundary of the grid in any number of moves.
 */

class Solution {
  int dfs(vvd(int) & grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] == 0)
      return 0;
    grid[i][j] = 0;
    return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) +
           dfs(grid, i, j + 1);
  }

public:
  int numEnclaves(vvd(int) & grid) {
    int ones = 0, zeros = 0;
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        ones += grid[i][j];
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        if ((i == 0 || j == 0 || i == grid.size() - 1 ||
             j == grid[0].size() - 1) &&
            grid[i][j] == 1)
          zeros += dfs(grid, i, j);
    return ones - zeros;
  }
};

int main() {
  Solution obj;
  vvd(int) g1 = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  vvd(int) g2 = {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  printf("%d\n", obj.numEnclaves(g1)); // expect: 3
  printf("%d\n", obj.numEnclaves(g2)); // expect: 0
}
