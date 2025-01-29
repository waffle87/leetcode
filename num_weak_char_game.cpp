#include "leetcode.h"

class Solution {
public:
  int numberOfWeakCharacters(vvd & properties) {
    sort(properties.begin(), properties.end(), compare);
    int currMax = INT_MIN, ans = 0;
    for (auto p : properties) {
      if (currMax > p[1])
        ans++;
      else
        currMax = p[1];
    }
    return ans;
  }

private:
  static bool compare(vector<int> &a, vector<int> &b) {
    if (a[0] != b[0])
      return a[0] > b[0];
    return a[1] < b[1];
  }
};
