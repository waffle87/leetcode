#include "leetcode.h"

class Solution {
public:
  vvd(int) findWinners(vvd(int) & matches) {
    map<int, int> lost;
    for (auto m : matches) {
      if (!lost.count(m[0]))
        lost[m[0]] = 0;
      lost[m[1]]++;
    }
    vector<int> zero, ones;
    for (auto [k, l] : lost) {
      if (l == 0)
        zero.push_back(k);
      if (l == 1)
        ones.push_back(k);
    }
    return {zero, ones};
  }
};
