// 2577. Minimum Time to Visit a Cell In a Grid
#include "leetcode.h"

/*
 * you are given an 'm x n' matrix 'grid' consisting of non-negative integers
 * where 'grid[row][col]' represents the minimum time required to be able to
 * visit the cell '(row, col)', which means you can visit the cell '(row, col)'
 * only when the time you visit it is greater than or equal to the value. you
 * are standing in the top left cell of the matrix in the 0th second and you
 * must move to any adjacent cell in the four directions: up, down, left, and
 * right. each move you make takes 1 second. return the minimum time required in
 * which you can visit the bottom right cell of the matrix. if you cannot visit
 * the bottomright cell, then return -1.
 */

class Solution {
public:
  int minimumTime(vector<vector<int>> &grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1)
      return -1;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    pq.push({grid[0][0], 0, 0});
    while (!pq.empty()) {
      int time = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
      pq.pop();
      if (row == m - 1 && col == n - 1)
        return time;
      if (vis[row][col])
        continue;
      vis[row][col] = true;
      for (auto i : dir) {
        int r = row + i[0], c = col + i[1];
        if (r < 0 || r >= m || c < 0 || c >= n || vis[r][c])
          continue;
        int wait = !((grid[r][c] - time) % 2);
        pq.push({max(grid[r][c] + wait, time + 1), r, c});
      }
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vvd g1 = {{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}},
           g2 = {{0, 2, 4}, {3, 2, 1}, {1, 0, 4}};
  printf("%d\n", obj.minimumTime(g1)); // expect: 7
  printf("%d\n", obj.minimumTime(g2)); // expect: -1
}
