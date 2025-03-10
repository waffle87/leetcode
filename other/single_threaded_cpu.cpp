#include "leetcode.h"

class Solution {
public:
  vector<int> getOrder(vvd & tasks) {
    vector<int> ans, idx(tasks.size());
    priority_queue<pair<int, int>> pqp;
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx),
         [&](int i, int j) { return tasks[i][0] < tasks[j][0]; });
    for (long i = 0, time = 1; i < idx.size() || !pqp.empty();) {
      for (; i < idx.size() && tasks[idx[i]][0] <= time; ++i)
        pqp.push({-tasks[idx[i]][1], -idx[i]});
      if (!pqp.empty()) {
        auto [procTime, j] = pqp.top();
        pqp.pop();
        time -= procTime;
        ans.push_back(-j);
      } else
        time = tasks[idx[i]][0];
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
  for (auto i : obj.getOrder(tasks))
    cout << i << ' '; // expect 0,2,3,1
}
