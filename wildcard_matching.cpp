#include "leetcode.h"

class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    int i = 0, j = 0, astr = -1, match;
    while (i < m) {
      if (j < n && p[j] == '*')
        match = i, astr = j++;
      else if (j < n && (s[i] == p[j] || p[j] == '?'))
        i++, j++;
      else if (astr >= 0)
        i = ++match, j = astr + 1;
      else
        return false;
    }
    while (j < n && p[j] == '*')
      j++;
    return j == n;
  }
};

int main() {}
