#include "leetcode.h"

class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    int n = stations.size(), ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i <= n; i++) {
      int dist = i == n ? target : stations[i][0];
      while (startFuel < dist) {
        if (!pq.size())
          return -1;
        startFuel += pq.top();
        ans++;
        pq.pop();
      }
      if (i < n)
        pq.push(stations[i][1]);
    }
    return ans;
  }
};
