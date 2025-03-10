#include "leetcode.h"

class Solution {
public:
  int compress(vector<char> &chars) {
    string ans;
    int c = 1, i;
    for (i = 1; i < chars.size(); i++) {
      if (chars[i] == chars[i - 1])
        c++;
      else if (chars[i] != chars[i - 1] && c == 1)
        ans += chars[i - 1];
      else {
        ans += chars[i - 1];
        ans += to_string(c);
        c = 1;
      }
    }
    if (c == 1)
      ans += chars[i - 1];
    else
      ans += chars[i - 1] + to_string(c);
    for (int i = 0; i < ans.size(); i++)
      chars[i] = ans[i];
    vector<char>::iterator it, ty;
    it = chars.begin() + ans.size();
    ty = chars.begin() + chars.size();
    chars.erase(it, ty);
    return ans.size();
  }
};
