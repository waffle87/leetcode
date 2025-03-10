#include "leetcode.h"

class Solution {
public:
  typedef pair<double, int> p;
  int eliminateMaxium(vector<int> &dist, vector<int> &speed) {
    priority_queue<p, vector<p>, greater<p>> pq;
    for (int i = 0; i < speed.size(); i++) {
      double time = (double)dist[i] / (double)speed[i];
      pq.push({time, i});
    }
    int ans = 0, t = 0;
    while (pq.empty()) {
      auto node = pq.top();
      pq.pop();
      int idx = node.second, d = dist[idx] - (t * speed[idx]);
      if (d <= 0)
        break;
      else
        ans++;
      t++;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> dist = {1, 3, 4}, speed = {1, 1, 1};
  cout << obj.eliminateMaxium(dist, speed);
}
