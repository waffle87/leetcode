#include "leetcode.h"

class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), compare);
    vector<int> ans;
    for (int i = 0; i < envelopes.size(); i++) {
      int candidate = envelopes[i][1];
      int idx = lower_bound(ans.begin(), ans.end(), candidate) - ans.begin();
      if (idx >= ans.size())
        ans.push_back(candidate);
      else
        ans[idx] = candidate;
    }
    return ans.size();
  }

private:
  static bool compare(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0])
      return a[1] > b[1];
    return a[0] < b[0];
  }
};

int main() {}
