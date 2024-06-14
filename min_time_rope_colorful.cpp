#include "leetcode.h"

class Solution {
public:
  int minCost(string colors, vector<int> &neededTime) {
    int ans = 0, maxCost = 0, sumCost = 0, n = colors.size();
    for (int i = 0; i < n; ++i) {
      if (i > 0 && colors[i] != colors[i - 1]) {
        ans += sumCost - maxCost;
        sumCost = maxCost = 0;
      }
      sumCost += neededTime[i];
      maxCost = max(maxCost, neededTime[i]);
    }
    ans += sumCost - maxCost;
    return ans;
  }
};

int main() {
  Solution obj;
  string colors = "abaac";
  vector<int> neededTime = {1, 2, 3, 4, 5};
  cout << obj.minCost(colors, neededTime);
}
