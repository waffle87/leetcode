#include "leetcode.h"

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> sol;
    helper(ans, sol, k, n);
    return ans;
  }
  void print(vector<vector<int>> &ans) {
    for (int i = 0; i < ans.size(); i++)
      for (int j = 0; j < ans.size(); j++)
        cout << ans[i][j] << ' ';
  }

private:
  void helper(vector<vector<int>> &ans, vector<int> sol, int k, int n) {
    if (sol.size() == k && n == 0) {
      ans.push_back(sol);
      return;
    }
    if (sol.size() < k)
      for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {
        if (n - i < 0)
          break;
        sol.push_back(i);
        helper(ans, sol, k, n - i);
        sol.pop_back();
      }
  }
};

int main() {
  Solution obj;
  vector<vector<int>> ans;
  obj.print(ans);
}
