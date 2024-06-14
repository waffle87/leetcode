// 64. Minimum Path Sum
#include "leetcode.h"

// given 'm x n grid' filled with non-negative numbers, find a path from top
// left to bottom right, which minimises the sum of all numbers along its path

class Solution {
public:
  int minPathSum(vvd(int) & grid) {
    int m = grid.size(), n = grid[0].size();
    vvd(int) sum(m, vector<int>(n, grid[0][0]));
    for (int i = 1; i < m; i++)
      sum[i][0] = sum[i - 1][0] + grid[i][0];
    for (int j = 1; j < n; j++)
      sum[0][j] = sum[0][j - 1] + grid[0][j];
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
        sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
    return sum[m - 1][n - 1];
  }
};

int main() {
  Solution obj;
  vvd(int) g1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  vvd(int) g2 = {{1, 2, 3}, {4, 5, 6}};
  printf("%d\n", obj.minPathSum(g1)); // expect: 7
  printf("%d\n", obj.minPathSum(g2)); // expect: 12
}
