// 787. Cheapest Flights Within K Stops
#include "leetcode.h"

/*
 * there are 'n' cities connected by some number of flights. you are given array
 * 'flights' where 'flight[i] = [fromi, toi, pricei]' indicates that there is a
 * flight from city 'fromi' to city 'toi' with cost 'pricei'.
 * you are also given three integers 'src, dst, & k'. return the cheapest price
 * from 'src' to 'dst' with at most 'k' stops. if there is no such route, -1
 */

typedef tuple<int, int, int> tp;
class Solution {
public:
  int findCheapestPrice(int n, vvd(int) & flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> vvp(n);
    for (const auto &f : flights)
      vvp[f[0]].emplace_back(f[1], f[2]);
    priority_queue<tp, vector<tp>, greater<tp>> pqvg;
    pqvg.emplace(0, src, k + 1);
    while (!pqvg.empty()) {
      auto [cost, u, stops] = pqvg.top();
      pqvg.pop();
      if (u == dst)
        return cost;
      if (!stops)
        continue;
      for (auto to : vvp[u]) {
        auto [v, w] = to;
        pqvg.emplace(cost + w, v, stops - 1);
      }
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vvd(int) flights1 = {
      {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  vvd(int) flights2 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  vvd(int) flights3 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  cout << obj.findCheapestPrice(4, flights1, 0, 3, 1) << endl; // expect: 700
  cout << obj.findCheapestPrice(3, flights2, 0, 2, 1) << endl; // expect: 200
  cout << obj.findCheapestPrice(3, flights3, 0, 2, 0) << endl; // expect: 500
}
