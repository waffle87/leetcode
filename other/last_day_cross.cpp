// 1970. Last Day Where You Can Still Cross
#include "leetcode.h"

/*
 * there is a 1-based binary matrix where 0 represents land and 1 represents
 * water. you are given integers 'row' and 'col' representing the number of rows
 * and columns in the matrix, respectively. initially on day 0, the entire
 * matrix is land. however each day a new cell becomes flooded with water. you
 * are given a 1-based 2d array 'cells', where 'cells[i] = [ri, ci]' represnts
 * that on the i'th day, the cell on the r[i'th] row and c[i'th] column (1-based
 * coordinates) will be covered with water (ie. changed to 1). you want to find
 * the last day that it is possible to walk from the top to the bottom by only
 * walking on land cells. you can start from any cell in the top row and end in
 * any cell in the bottom row. you can only travel in the four cardinal
 * directions (left, right, up, down) return the last day where it is possible
 * to walk from the top to the bottom by only walking on land cells
 */

class Solution {
public:
  int latestDayToCross(int row, int col, vvd & cells) {
    vvd grid(row, vector<int>(col, 1));
    p = vector<int>(row * col + 3, -1);
    int start_g = row * col + 1, end_g = row * col + 2;
    for (int i = 0; i < col; i++) {
      uni(i, start_g);
      uni((row - 1) * col + i, end_g);
    }
    for (int i = row * col - 1; i >= 0; i--) {
      int r = cells[i][0] - 1, c = cells[i][1] - 1;
      grid[r][c] = 0;
      int key = r * col + c;
      for (int k = 0; k < 4; ++k) {
        int n_r = r + dir[k][0], n_c = c + dir[k][1];
        if (n_r >= 0 && n_r < row && n_c >= 0 && n_c < col && !grid[n_r][n_c]) {
          int n_key = n_r * col + n_c;
          uni(key, n_key);
        }
      }
    }
    return row * col - 1;
  }

private:
  vector<int> p;
  const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  void uni(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return;
    p[y] = x;
  }
};

int main() {
  Solution obj;
  vvd c1 = {{1, 1}, {2, 1}, {1, 2}, {2, 2}},
           c2 = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
  printf("%d\n", obj.latestDayToCross(2, 2, c1)); // expect: 2
  printf("%d\n", obj.latestDayToCross(2, 2, c2)); // expect: 1
}
