#include "leetcode.h"

class Solution {
public:
  const int mod = 1e9 + 7;
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency,
                     int k) {
    priority_queue<int, vector<int>, greater<int>> pqvg;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
      vp.push_back({efficiency[i], speed[i]});
    sort(vp.rbegin(), vp.rend());
    long totSpeed = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      int currEff = vp[i].first, currSpeed = vp[i].second;
      if (pqvg.size() == k) {
        totSpeed -= pqvg.top();
        pqvg.pop();
      }
      pqvg.push(currSpeed);
      totSpeed += currSpeed;
      ans = max(ans, totSpeed * currEff);
    }
    return ans % mod;
  }
};

int main() {
  Solution obj;
  int n = 6, k = 2;
  vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};
  cout << obj.maxPerformance(n, speed, efficiency, k);
}
