#include "leetcode.h"

class Solution {
public:
  bool isNumber(string s) {
    int state = 0, flag = 0;
    while (s[0] == ' ' || s[s.size() - 1] == ' ')
      s.erase(s.size() - 1, 1);
    for (int i = 0; i < s.size(); i++) {
      if ('0' <= s[i] && s[i] <= '9') {
        flag = 1;
        if (state <= 2)
          state = 2;
        else
          state = (state <= 5) ? 5 : 7;
      } else if (s[i] == '+' || s[i] == '-') {
        if (state == 0 || state == 3)
          state++;
        else
          return false;
      } else if (s[i] == '.') {
        if (state <= 2)
          state = 6;
        else
          return false;
      } else if (s[i] == 'e') {
        if (flag && (state == 2 || state == 6 || state == 7))
          state = 3;
        else
          return false;
      } else
        return false;
    }
    return (state == 2 || state == 5 || (flag && state == 6) || state == 7);
  }
};

int main() {
  Solution obj;
  string s = "3";
  if (obj.isNumber(s))
    cout << "true";
  else
    cout << "false";
}
