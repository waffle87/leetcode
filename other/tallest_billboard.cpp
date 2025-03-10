#include "leetcode.h"

class Solution {
public:
  int tallestBillboard(vector<int> &rods) {
    unordered_map<int, int> dp;
    dp[0] = 0;
    for (int i : rods) {
      unordered_map<int, int> tmp;
      for (auto &it : dp) {
        int diff = it.first;
        tmp[diff + i] = max(tmp[diff + i], dp[diff] + i);
        tmp[diff - i] = max(tmp[diff - i], dp[diff]);
      }
      dp.clear();
      dp.insert(tmp.begin(), tmp.end());
    }
    return dp[0];
  }
};

int main() {
  Solution obj;
  vector<int> rods = {1, 2, 3, 6};
  cout << obj.tallestBillboard(rods);
}
