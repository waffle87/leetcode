#include "leetcode.h"

class Solution {
public:
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    int n = nums.size(), m = queries.size();
    sort(nums.begin(), nums.end());
    vector<int> ans, pre(n + 1, 0);
    for (int i = 1; i < n; i++)
      pre[i] = pre[i - 1] + nums[i - 1];
    for (int i = 0; i < m; i++) {
      int sum = queries[i];
      auto z = lower_bound(pre.begin(), pre.end(), sum) - pre.begin();
      if (z < n + 1) {
        if (pre[z] == sum)
          ans.push_back(z);
        else
          ans.push_back(z - 1);
      } else if (z == n + 1)
        ans.push_back(n);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {4, 5, 2, 1}, queries = {3, 10, 21};
  for (auto i : obj.answerQueries(nums, queries))
    cout << i << ' ';
}
