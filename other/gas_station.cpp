#include "leetcode.h"

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size(), totalSurplus = 0, surplus = 0, start = 0;
    for (int i = 0; i < n; i++) {
      totalSurplus += gas[i] - cost[i];
      surplus += gas[i] - cost[i];
      if (surplus < 0) {
        surplus = 0;
        start = i + 1;
      }
    }
    return (totalSurplus < 0) ? -1 : start;
  }
};

int main() {
  Solution obj;
  vector<int> gas1 = {1, 2, 3, 4, 5}, gas2 = {2, 3, 4}, cost1 = {3, 4, 5, 1, 2},
              cost2 = {3, 4, 3};
  cout << obj.canCompleteCircuit(gas1, cost1) << endl; // expect: 3
  cout << obj.canCompleteCircuit(gas2, cost1) << endl; // expect: -1
}
