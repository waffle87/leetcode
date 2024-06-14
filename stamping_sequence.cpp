#include "leetcode.h"

class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    if (stamp == target)
      return {0};
    int sLen = stamp.size(), tLen = target.size() - sLen + 1, i, j;
    vector<int> ans;
    bool tDiff = true, sDiff;
    while (tDiff) {
      for (i = 0, tDiff = false; i < tLen; i++) {
        for (j = 0, sDiff = false; j < sLen; j++) {
          if (target[i + j] == '*')
            continue;
          else if (target[i + j] != stamp[j])
            break;
          else
            sDiff = true;
        }
        if (j == sLen && sDiff) {
          for (j = i, tDiff = true; j < sLen + i; j++)
            target[j] = '*';
          ans.push_back(i);
        }
      }
      for (i = 0; i < target.size(); i++)
        if (target[i] != '*')
          return {};
      reverse(ans.begin(), ans.end());
    }
    return ans;
  }
};
