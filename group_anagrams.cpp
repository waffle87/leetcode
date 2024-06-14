#include "leetcode.h"

class Solution {
public:
  vvd(string) groupAnagrams(vector<string> &strs) {
    map<array<int, 26>, vector<string>> groups;
    for (string s : strs) {
      array<int, 26> hash = {0};
      for (char c : s)
        ++hash[c - 'a'];
      groups[hash].push_back(s);
    }
    vvd(string) ans;
    for (auto [hash, group] : groups)
      ans.push_back(group);
    return ans;
  }
};
