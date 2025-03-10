// 2596. Check Knight Tour Configuration
#include "leetcode.h"

/*
 * there is a knight on an 'n * n' chessboard. in a valid config
 * the knight starts at the topl-left cell of the board and visits
 * every cell on the board exactly once. you are given an 'n * n'
 * integer matrix 'grid' consisting of distinct integers from the
 * range '[0, n * n - 1]' where 'grid[row][col]' indicates that
 * the cell '(row, col)' is the 'grid[row][col]'th cell that the
 * knight visited. the moves are 0-indexed. return true if grid
 * represents a valid configuration of the knight's movements or
 * false otherwise. note that a valid knight move consists of
 * moving two squares vertically and one square horizontally,
 * or two squares horizontally and one square vertically. the
 * figure illustrates all possible 8 moves of a knight from cell
 */

class Solution {
public:
  bool checkValidGrid(vvd & grid) {
    int dir[8][2] = {{1, -2}, {2, -1}, {2, 1},   {1, 2},
                     {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
    int cnt = 0, max_cnt = grid.size() * grid.size() - 1;
    int x = 0, y = 0, i, j;
    if (grid[x][y] != cnt)
      return false;
    while (cnt < max_cnt) {
      cnt++;
      int flag = 1;
      for (auto d : dir) {
        i = x + d[0];
        j = y + d[1];
        if (i >= 0 && j >= 0 && i < grid.size() && j < grid.size() &&
            grid[i][j] == cnt) {
          x = i;
          y = j;
          flag = 0;
          break;
        }
      }
      if (flag)
        return false;
    }
    return true;
  }
};

int main() {
  Solution obj;
  vvd g1 = {{0, 11, 16, 5, 20},
                 {17, 4, 19, 10, 15},
                 {12, 1, 8, 21, 6},
                 {3, 18, 23, 14, 9},
                 {24, 13, 2, 7, 22}};
  vvd g2 = {{0, 3, 6}, {5, 8, 1}, {2, 7, 4}};
  printf("%d\n", obj.checkValidGrid(g1)); // expect: 1
  printf("%d\n", obj.checkValidGrid(g2)); // expect: 0
}
