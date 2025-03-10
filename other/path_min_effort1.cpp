#include "leetcode.h"
#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <utility>
#include <vector>

class Solution {
  const int d4x[4] = {-1, 0, 1, 0}, d4y[4] = {0, 1, 0, -1};

public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int n = heights.size(), m = heights[0].size();
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    dis[0][0] = 0;
    pq.push({0, {0, 0}});
    while (!pq.empty()) {
      pair<int, pair<int, int>> curr = pq.top();
      pq.pop();
      int d = curr.first, r = curr.second.first, c = curr.second.second;
      if (r == n - 1 && c == m - 1)
        return d;
      for (int i = 0; i < 4; ++i) {
        int nX = r + d4x[i], nY = x + d4y[i];
        if (nX < 0 || nX >= n || nY < 0 || nY >= m)
          continue;
        int nD = max(d, abs(h[nX][nY] - h[r][c]));
        if (nD < dis[nX][nY]) {
          dis[nX][nY] = nD;
          pq.push({nD, {nX, nY}});
        }
      }
    }
    return 0;
  }
};

int main() {}
