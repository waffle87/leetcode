// 1091. Shortest Path in Binary Matrix
#include "leetcode.h"

/*
 * given an n x n binary matrix 'grid', return the length of the shortest clear
 * path in the matrix. if there is no clear path, return -1. a clear path in a
 * binary matrix is a path from the top-left cell (ie. 0,0) to the bottom-right
 * cell (ie. n - 1, n - 1) such thatyt
 * - all the visited cells are of the path 0
 * - all the adjacent cells of the path are 8-directionally connected (ie. they
 * are different and they share an edge of a corner) the length of a clear path
 * is the number of visited cells of this path
 */

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    if (grid[0][0] || grid.back().back())
      return -1;
    int ans = 2, n = 1, nr = grid[0].size() - 1, nc = grid.size() - 1;
    queue<pair<int, int>> qp;
    if (!nr && !nc)
      return 1 - (grid[0][0] << 1);
    qp.push({0, 0});
    grid[0][0] = -1;
    while (n) {
      while (n--) {
        auto [cx, cy] = qp.front();
        qp.pop();
        for (int i = max(0, cx - 1), lmtx = min(cx + 1, nr); i <= lmtx; i++)
          for (int j = max(0, cy - 1), lmty = min(cy + 1, nc); j <= lmty; j++) {
            if (i == nr && j == nc)
              return ans;
            if (!grid[j][i]) {
              grid[j][i] = -1;
              qp.push({i, j});
            }
          }
      }
      ans++;
      n = qp.size();
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vvd g1 = {{0, 1}, {1, 0}};
  vvd g2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  vvd g3 = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  printf("%d\n", obj.shortestPathBinaryMatrix(g1)); // expect: 2
  printf("%d\n", obj.shortestPathBinaryMatrix(g2)); // expect: 4
  printf("%d\n", obj.shortestPathBinaryMatrix(g3)); // expect: -1
}
