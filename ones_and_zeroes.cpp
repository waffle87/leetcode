#include "leetcode.h"
#include <vector>

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<pair<int, int>> vp;
    for (auto i : strs) {
      int one = 0, zero = 0;
      for (auto j : i)
        (j == '1') ? one++ : zero++;
      vp.push_back({one, zero});
    }
    return helper(vp, 0, m, n);
  }

private:
  int helper(vector<pair<int, int>> &vp, int idx, int m, int n) {
    int j = vp.size();
    if (idx == j || (m == 0 && n == 0))
      return 0;
    if (vp[idx].first > n || vp[idx].second > m)
      return helper(vp, idx + 1, m, n);
    int include =
        1 + helper(vp, idx + 1, n - vp[idx].first, m - vp[idx].second);
    int exclude = helper(vp, idx + 1, m, n);
    return max(include, exclude);
  }
};

int main() {
  Solution obj;
  vector<string> strs = {"10", "0001", "111001", "1", "0"};
  int m = 5, n = 3;
  cout << obj.findMaxForm(strs, m, n);
}
