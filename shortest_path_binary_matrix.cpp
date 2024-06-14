#include "leetcode.h"
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    if (grid[0][0] || grid.back().back())
      return -1;
    int ans = 2, len = 1, nX = grid[0].size() - 1, nY = grid.size() - 1;
    queue<pair<int, int>> qp;
    if (!nX && !nY)
      return 1 - (grid[0][0] << 1);
    qp.push({0, 0});
    grid[0][0] = -1;
    while (len) {
      while (len--) {
        auto [cX, cY] = qp.front();
        qp.pop();
        for (int i = max(0, cX - 1), lmtX = min(cX + 1, nX); i <= lmtX; i++) {
          for (int j = max(0, cY - 1), lmtY = min(cY + 1, nY); j <= lmtY; j++) {
            if (i == nX && j == nY)
              return ans;
            if (!grid[j][i]) {
              grid[j][i] = -1;
              qp.push({i, j});
            }
          }
        }
      }
      ans++;
      len = qp.size();
    }
    return -1;
  }
};

int main() {}
