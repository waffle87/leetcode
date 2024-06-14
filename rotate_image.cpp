#include "leetcode.h"

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size(), depth = n / 2;
    for (int i = 0; i < depth; i++) {
      int len = n - 2 * i - 1, opp = n - 1 - i;
      for (int j = 0; j < len; j++) {
        int tmp = matrix[i][i + j];
        matrix[i][i + j] = matrix[opp - j][i];
        matrix[opp - j][i] = matrix[opp][opp - j];
        matrix[opp][opp - j] = matrix[i + j][opp];
        matrix[i + j][opp] = tmp;
      }
    }
  }
};
