#include "leetcode.h"

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    vector<int> ans(triangle.size(), triangle[0][0]);
    for (int i = 1; i < triangle.size(); i++)
      for (int j = i; j >= 0; j--) {
        if (j == 0)
          ans[0] += triangle[i][j];
        else if (j == i)
          ans[j] = triangle[i][j] + ans[j - 1];
        else
          ans[j] = triangle[i][j] + min(ans[j - 1], ans[j]);
      }
    return *min_element(ans.begin(), ans.end());
  }
};

int main() {}
