#include "leetcode.h"

class Solution {
public:
  vector<int> findOriginalArray(vector<int> &changed) {
    int count[100001] = {}, i = 0;
    vector<int> ans;
    for (auto n : changed)
      ++count[n];
    for (int i = 0; i <= 50000; ++i)
      if (count[i]) {
        if (--count[i * 2] < 0 || --count[i] < 0)
          return {};
        ans.push_back(i--);
      }
    return accumulate(begin(count) + 50000, end(count), 0ll) ? vector<int>()
                                                             : ans;
  }
};
