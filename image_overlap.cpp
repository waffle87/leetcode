#include "leetcode.h"

class Solution {
public:
  int largestOverlap(vvd & img1, vvd & img2) {
    vector<int> la, lb;
    int n = img1.size();
    unordered_map<int, int> count;
    for (int i = 0; i < n * n; ++i)
      if (img1[i / n][i % n] == 1)
        la.push_back(i / n * 100 + i % n);
    for (int i = 0; i < n * n; ++i)
      if (img2[i / n][i % n] == 1)
        lb.push_back(i / n * 100 + i % n);
    for (int i : la)
      for (int j : lb)
        count[i - j]++;
    int ans = 0;
    for (auto it : count)
      ans = max(ans, it.second);
    return ans;
  }
};
