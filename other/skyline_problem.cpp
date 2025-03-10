#include "leetcode.h"

class Solution {
public:
  vvd getSkyline(vvd & buildings) {
    vvd ans;
    map<int, vector<pair<int, int>>> mvp;
    for (auto &b : buildings) {
      mvp[b[0]].push_back({b[2], 0});
      mvp[b[1]].push_back({b[2], 1});
    }
    multiset<int> m;
    for (auto &[pos, heights] : mvp) {
      for (auto &[height, type] : heights) {
        if (type == 0)
          m.insert(height);
        else
          m.erase(m.find(height));
      }
      int newHeight = m.empty() ? 0 : *m.begin();
      if (!ans.empty() && ans.back()[1] == newHeight)
        continue;
      else
        ans.push_back(vector<int>({pos, newHeight}));
    }
    return ans;
  }
};
