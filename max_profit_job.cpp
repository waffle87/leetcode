#include "leetcode.h"

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    int n = startTime.size();
    vvd(int) jobs;
    for (int i = 0; i < n; ++i)
      jobs.push_back({endTime[i], startTime[i], profit[i]});
    sort(jobs.begin(), jobs.end());
    map<int, int> dp = {{0, 0}};
    for (auto &j : jobs) {
      int curr = prev(dp.upper_bound(j[1]))->second + j[2];
      if (curr > dp.rbegin()->second)
        dp[j[0]] = curr;
    }
    return dp.rbegin()->second;
  }
};

int main() {
  Solution obj;
  vector<int> startTime = {1, 2, 3, 3};
  vector<int> endTime = {3, 4, 5, 6};
  vector<int> profit = {50, 10, 40, 70};
  cout << obj.jobScheduling(startTime, endTime, profit); // 120
}
