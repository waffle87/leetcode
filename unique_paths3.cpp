#include "leetcode.h"

class Solution {
public:
  int uniquePathsIII(vvd(int) & grid) {
    auto i1 = 0, j1 = 0, t_steps = 0;
    for (auto i = 0; i < grid.size(); ++i)
      for (auto j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1)
          i1 = i, j1 = j;
        if (grid[i][j] != -1)
          ++t_steps;
      }
    return dfs(grid, i1, j1, 1, t_steps);
  }

private:
  int dfs(vvd(int) & grid, int i, int j, int step, int t_step) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] == -1)
      return 0;
    if (grid[i][j] == 2)
      return step == t_step ? 1 : 0;
    grid[i][j] = -1;
    int paths = dfs(grid, i + 1, j, step + 1, t_step) +
                dfs(grid, i - 1, j, step + 1, t_step) +
                dfs(grid, i, j + 1, step + 1, t_step) +
                dfs(grid, i, j - 1, step + 1, t_step);
    grid[i][j] = 0;
    return paths;
  }
};

int main() {
  Solution obj;
  vvd(int) grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
  cout << obj.uniquePathsIII(grid); // expect: 2
}
