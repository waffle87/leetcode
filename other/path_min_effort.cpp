#include "leetcode.h"

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    int dirs[5] = {-1, 0, 1, 0, -1};
    vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
      int effort = pq.top().first;
      int x = pq.top().second / 100, y = pq.top().second % 100;
      pq.pop();
      if (x == m - 1 && y == n - 1)
        return effort;
      if (effort >= efforts[x][y])
        continue;
      efforts[x][y] = effort;
      for (int i = 0; i < 4; i++) {
        int nX = x + dirs[i], nY = +dirs[i + 1];
        if (nX < 0 || nX >= m || nY < 0 || nY >= n)
          continue;
        int nEffort = max(effort, abs(heights[x][y] - heights[nX][nY]));
        pq.emplace(nEffort, nX * 100 + nY);
      }
    }
    return -1;
  }
};

int min() {}
