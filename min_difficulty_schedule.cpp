#include "leetcode.h"
#include <algorithm>
#include <vector>

class Solution {
public:
  int minDifficulty(vector<int> &jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d)
      return -1;
    vector<int> dp(n, 1000), dp2(n), stack;
    for (int i = 0; i < d; ++i) {
      stack.clear();
      for (int j = i; j < n; j++) {
        dp2[j] = j ? dp[j - 1] + jobDifficulty[j] : jobDifficulty[j];
        while (stack.size() &&
               jobDifficulty[stack.back()] <= jobDifficulty[j]) {
          int k = stack.back();
          stack.pop_back();
          dp[j] = min(dp2[j], dp2[k] - jobDifficulty[k] + jobDifficulty[j]);
        }
        if (stack.size())
          dp2[j] = min(dp2[j], dp2[stack.back()]);
        stack.push_back(j);
      }
      swap(dp, dp2);
    }
    return dp[n - 1];
  }
};

int main() {
  Solution obj;
  vector<int> jobDifficulty = {6, 5, 4, 3, 2, 1};
  cout << obj.minDifficulty(jobDifficulty, 2);
}
