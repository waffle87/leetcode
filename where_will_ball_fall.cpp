#include "leetcode.h"

class Solution {
public:
  vector<int> findBall(vvd & grid) {
    int m = grid.size(), n = grid[0].size();
    vvd ugrid(m * 3, vector<int>(n * 3));
    for (auto i = 0; i < m; i++)
      for (auto j = 0; j < n; j++) {
        ugrid[i * 3 + 1][j * 3 + 1] = 1;
        ugrid[i * 3][j * 3] = ugrid[i * 3 + 2][j * 3 + 2] = grid[i][j] == 1;
        ugrid[i * 3][j * 3 + 2] = ugrid[i * 3 + 2][j * 3] = grid[i][j] != 1;
      }
    vector<int> ans;
    for (auto i = 0; i < n; ++i)
      ans.push_back(drop(i * 3 + 1, ugrid, m * 3, n * 3));
    return ans;
  }

private:
  vector<pair<int, int>> dir{{1, 0}, {0, -1}, {0, 1}};
  int drop(int pos, vvd & ugrid, int m, int n) {
    queue<pair<int, int>> qp;
    qp.push({0, pos});
    while (!qp.empty()) {
      auto [i, j] = qp.front();
      qp.pop();
      if (i == m - 1)
        return j / 3;
      ugrid[i][j] = 1;
      for (auto [di, dj] : dir)
        if (j + dj >= 0 && j + dj < n && !ugrid[i + di][j + dj]) {
          qp.push({i + di, j + dj});
          break;
        }
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vvd grid = {{1, 1, 1, -1, -1},
                   {1, 1, 1, -1, -1},
                   {-1, -1, -1, 1, 1},
                   {1, 1, 1, 1, -1},
                   {-1, -1, -1, -1, -1}};
  for (auto i : obj.findBall(grid))
    cout << i << ' ';
}
