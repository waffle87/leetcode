#include "leetcode.h"

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s == t)
      return true;
    if (s.size() != t.size())
      return false;
    unordered_map<char, int> up;
    for (int i = 0; i < s.size(); i++) {
      up[s[i]]++;
      up[t[i]]--;
    }
    for (auto it : up)
      if (it.second)
        return false;
    return true;
  }
};

int main() {
  Solution obj;
  string s = "anagram", t = "nagaram";
  if (obj.isAnagram(s, t))
    cout << "true";
  else
    cout << "false";
}
