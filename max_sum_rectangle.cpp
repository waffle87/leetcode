#include "leetcode.h"

class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int ans = INT_MIN, rows = matrix.size(), cols = matrix[0].size();
    for (int l = 0; l < cols; ++l) {
      vector<int> sums(rows);
      for (int r = l; r < cols; ++r) {
        int pMin = 0, pMax = INT_MIN;
        for (int i = 0; i < rows; ++i) {
          sums[i] += matrix[i][r];
          pMin = max(pMin + sums[i], sums[i]);
          pMax = max(pMax, pMin);
        }
        if (pMax <= k) {
          ans = max(ans, pMax);
          continue;
        }
        set<int> s = {0};
        int runSum = 0;
        for (int sum : sums) {
          runSum += sum;
          auto it = s.lower_bound(runSum - k);
          if (it != end(s))
            ans = max(ans, runSum - *it);
          s.insert(runSum);
        }
      }
    }
    return ans;
  }
};
