// 2477. Minimum Fuel Cost to Report to the Capital
#include "leetcode.h"

/*
 * there is a tree (ie. a connected, undirected graph with no cycles) structure
 * country network consisting of 'n' cities numbered from 0 to 'n - 1' and
 * exactly 'n - 1' roads the capital city is city 0. given a 2d integer array
 * 'roads' where 'roads[i] = [ai, bi]' denotes that there exists a bidirectional
 * road connecting cities ai & bi. there is a meeting for the representitive of
 * each city. the meeting is in the capital city. there is a car in each city.
 * given integer seats that indicates the number of seats in each car. a
 * representitive can use the car in their city to travel or change the car and
 * ride with another representitive. the cost of traveling between two cities is
 * 1 liter of fuel. return minimum number of liters of fuel needed to reach
 * capital city.
 */

class Solution {
public:
  long long minimumFuelCost(vvd & roads, int seats) {
    vvd al(roads.size() + 1);
    for (auto &r : roads) {
      al[r[0]].push_back(r[1]);
      al[r[1]].push_back(r[0]);
    }
    long long ans = 0;
    return dfs(0, -1, 0, seats, al, ans);
  }

private:
  long long dfs(int i, int prev, int depth, int seats, vvd & al,
                long long &ans) {
    long long riders = 1;
    for (int j : al[i])
      if (j != prev)
        riders += dfs(j, i, depth + 1, seats, al, ans);
    if (depth == 0)
      return ans;
    ans += (riders / seats) * depth + (riders % seats ? 1 : 0);
    return riders % seats;
  }
};

int main() {
  Solution obj;
  vvd roads1 = {{0, 1}, {0, 2}, {0, 3}};
  vvd roads2 = {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};
  cout << obj.minimumFuelCost(roads1, 5) << endl; // expect: 3
  cout << obj.minimumFuelCost(roads2, 2) << endl; // expect: 7
}
