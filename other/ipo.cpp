// 502. IPO
#include "leetcode.h"

/*
 * suppose leetcode will start its ipo soon. in order to sell a good price of
 * its shares to venture capital, leetcode woule like to work on some projects
 * to increase its capital before the ipo. since it has limited resources, it
 * can only finish at most k distinct projects before the ipo. maximise capital
 * after finishing at most 'k' distinct projects. given 'n' projects where the
 * i'th project has a pure profit 'profits[i]' and min capital of 'capital[i]'
 * is needed to start it.
 */

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    priority_queue<int> pq;
    int x = 0;
    vector<pair<int, int>> vp;
    for (int i = 0; i < profits.size(); i++)
      vp.push_back({capital[i], profits[i]});
    sort(vp.begin(), vp.end());
    while (x < vp.size() && k) {
      if (w >= vp[x].first) {
        pq.push(vp[x].second);
        x++;
      } else {
        if (pq.empty())
          return w;
        else {
          w += pq.top();
          pq.pop();
          k--;
        }
      }
    }
    while (k-- && !pq.empty()) {
      w += pq.top();
      pq.pop();
    }
    return w;
  }
};

int main() {
  Solution obj;
  vector<int> profits = {1, 2, 3};
  vector<int> c1 = {0, 1, 1}, c2 = {0, 1, 2};
  cout << obj.findMaximizedCapital(2, 0, profits, c1) << endl; // expect: 4
  cout << obj.findMaximizedCapital(3, 0, profits, c2) << endl; // expect: 6
}
