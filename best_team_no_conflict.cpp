#include "leetcode.h"

class Solution {
public:
  int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    int n = scores.size(), ans = 0;
    vector<int> dp(n, 0);
    vector<pair<int, int>> arr(n, {0, 0});
    for (int i = 0; i < n; ++i) {
      arr[i].first = ages[i];
      arr[i].second = scores[i];
    }
    for (int i = 0; i < n; ++i) {
      dp[i] = arr[i].second;
      for (int j = i - 1; j >= 0; --j)
        if (arr[i].second >= arr[j].second)
          dp[i] = max(dp[i], dp[j] + arr[i].second);
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> scores = {1, 3, 5, 10, 15}, ages = {1, 2, 3, 4, 5};
  cout << obj.bestTeamScore(scores, ages);
}
