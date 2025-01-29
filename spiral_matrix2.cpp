// 59. Spiral Matrix II
#include "leetcode.h"

// given a positive integer 'n', generate an n x n 'matrix' filled with
// elements from 1 to 'n^2' in spiral order

class Solution {
public:
  vvd generateMatrix(int n) {
    vvd matrix(n, vector<int>(n));
    int num = 1, row = 0, col = 0, dir = 0;
    vector<int> d_r = {0, 1, 0, -1}, d_c = {1, 0, -1, 0};
    while (num <= n * n) {
      matrix[row][col] = num;
      num++;
      int next_row = row + d_r[dir];
      int next_col = col + d_c[dir];
      if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n ||
          matrix[next_row][next_col])
        dir = (dir + 1) % 4;
      row += d_r[dir];
      col += d_c[dir];
    }
    return matrix;
  }
};
