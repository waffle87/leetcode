#include "leetcode.h"

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> um;
    for (int n : nums)
      um[n]++;
    vector<int> ans;
    priority_queue<pair<int, int>> pqp;
    for (auto it = um.begin(); it != um.end(); it++) {
      pqp.push(make_pair(it->second, it->first));
      if (pqp.size() > um.size() - k)
        ans.push_back(pqp.top().second), pqp.pop();
    }
    return ans;
  }
};
