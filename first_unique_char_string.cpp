#include "leetcode.h"

class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, pair<int, int>> ump;
    int idx = s.size();
    for (int i = 0; i < s.size(); i++) {
      ump[s[i]].first++;
      ump[s[i]].second = i;
    }
    for (const auto &[c, p] : ump)
      if (p.first == 1)
        idx = min(idx, p.second);
    return idx == s.size() ? -1 : idx;
  }
};

int main() {
  Solution obj;
  cout << obj.firstUniqueChar("loveleetcode");
}
