#include "leetcode.h"

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> qp;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          ans[i][j] = 0;
          qp.push({i, j});
        }
      }
    }
    vector<pair<int, int>> vp{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!qp.empty()) {
      auto curr = qp.front();
      qp.pop();
      int currX = curr.first, currY = curr.second;
      for (auto dirr : vp) {
        int x = currX + dirr.first, y = currY + dirr.second;
        if (x >= 0 && x < m && y >= 0 && y < n) {
          if (ans[x][y] > ans[currX][currY] + 1) {
            ans[x][y] = ans[currX][currY] + 1;
            qp.push({x, y});
          }
        }
      }
    }
    return ans;
  }
};
