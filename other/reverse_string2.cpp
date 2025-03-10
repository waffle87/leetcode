#include "leetcode.h"

class Solution {
public:
  string reverseStr(string s, int k) {
    int len = s.size(), rem = len % (2 * k);
    int start = 0, end = 2 * k, actual = len - rem;
    string ans = "";
    while (actual) {
      string tmp = s.substr(start, end);
      reverse(tmp.begin(), tmp.begin() + k);
      start += 2 * k;
      ans += tmp;
      actual -= 2 * k;
    }
    if (rem > 0) {
      if (rem < k) {
        string tmp = s.substr(len - rem, rem);
        reverse(tmp.begin(), tmp.end());
        ans += tmp;
      } else if (rem <= 2 * k) {
        string tmp = s.substr(len - rem, rem);
        reverse(tmp.begin(), tmp.begin() + k);
        ans += tmp;
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.reverseStr("abcdefg", 2);
}
