#include "leetcode.h"

class Solution {
public:
  int shortestPath(vvd(int) & grid, int k) {
    int rows = grid.size(), cols = grid[0].size();
    int minStep = max(0, rows + cols - 2), obstacles = minStep - 1,
        minStepNext = minStep;
    if (obstacles <= k)
      return minStep;
    vvd(int) dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    list<vector<int>> togo;
    togo.push_back({0, 0, k});
    vector<int> visited(rows * cols, -1);
    visited[0] = k;
    int steps = 0;
    while (togo.size()) {
      steps++;
      minStep = minStepNext;
      for (int i = togo.size(); i > 0; i--) {
        int a = togo.front()[0], b = togo.front()[1], c = togo.front()[2];
        togo.pop_front();
        for (auto &d : dirs) {
          int aa = a + d[0], bb = b + d[1];
          if (aa < 0 || aa >= rows || bb < 0 || bb >= cols)
            continue;
          int cc = c - grid[aa][bb];
          if (visited[aa * cols + bb] >= cc)
            continue;
          int stepsToTarget = rows - aa - 1 + cols - bb - 1;
          if (stepsToTarget - 1 <= cc && stepsToTarget == minStep - 1)
            return steps + stepsToTarget;
          togo.push_back({aa, bb, cc});
          visited[aa * cols + bb] = cc;
          minStepNext = min(minStepNext, stepsToTarget);
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vvd(int) grid = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
  int k = 1;
  cout << obj.shortestPath(grid, k);
}
