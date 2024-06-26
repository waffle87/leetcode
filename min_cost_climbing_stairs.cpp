#include "leetcode.h"

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    for (int i = cost.size() - 3; ~i; i--)
      cost[i] += min(cost[i + 1], cost[i + 2]);
    return min(cost[0], cost[1]);
  }
};

int main() {
  Solution obj;
  vector<int> cost = {10, 15, 20};
  cout << obj.minCostClimbingStairs(cost);
}
