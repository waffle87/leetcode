#include "leetcode.h"

class Solution {
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), cmp);
    int ans = 0;
    for (auto box : boxTypes) {
      int n = min(box[0], truckSize);
      ans += (n * box[1]);
      truckSize -= n;
      if (!truckSize)
        break;
    }
    return ans;
  }

private:
  static bool cmp(vector<int> &a, vector<int> &b) { return a[1] > b[1]; }
};
