// 54. Spiral Matrix
#include "leetcode.h"

// given an m x n 'matrix', return all elements of the 'matrix' in spiral order

class Solution {
public:
  vector<int> spiralOrder(vvd(int) & matrix) {
    vvd(int) dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> ans, n_step{cols, rows - 1};
    if (!rows || !cols)
      return ans;
    int i_dir = 0, i_row = 0, i_col = -1;
    while (n_step[i_dir % 2]) {
      for (int i = 0; i < n_step[i_dir % 2]; ++i) {
        i_row += dirs[i_dir][0];
        i_col += dirs[i_dir][1];
        ans.push_back(matrix[i_row][i_col]);
      }
      n_step[i_dir % 2]--;
      i_dir = (i_dir + 1) % 4;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vvd(int) m2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  for (auto i : obj.spiralOrder(m1))
    printf("%d, ", i);
  printf("\n"); // expect: 1,2,3,6,9,8,7,4,5
  for (auto i : obj.spiralOrder(m2))
    printf("%d, ", i); // expect: 1,2,3,4,8,12,11,10,9,5,6,7
}
