#include "leetcode.h"

class Solution {
public:
  unordered_map<int, vector<int>> umv;
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        umv[i - j].push_back(mat[i][j]);
    for (int i = -(n - 1); i < m; i++)
      sort(umv[i].begin(), umv[i].end());
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        mat[i][j] = umv[i - j].back();
        umv[i - j].pop_back();
      }
    }
    return mat;
  }
};
