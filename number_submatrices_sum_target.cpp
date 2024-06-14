#include "leetcode.h"

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int xLen = matrix[0].size(), yLen = matrix.size(), ans = 0;
    unordered_map<int, int> res;
    for (int i = 0; i < yLen; i++)
      for (int j = 1; j < xLen; j++)
        matrix[i][j] += matrix[i][j - 1];
    for (int j = 0; j < xLen; j++)
      for (int k = j; k < xLen; k++) {
        res.clear();
        res[0] = 1;
        int cSum = 0;
        for (int i = 0; i < yLen; i++) {
          cSum += matrix[i][k] - (j ? matrix[i][j - 1] : 0);
          ans += res.find(cSum - target) != res.end() ? res[cSum - target] : 0;
          res[cSum]++;
        }
      }
    return ans;
  }
};
