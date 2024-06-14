#include "leetcode.h"

class Solution {
public:
  int removePalindromeSub(string s) {
    if (s.size() == 0)
      return 0;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
      if (s[i] != s[j])
        return 2;
    return 1;
  }
};

int main() {
  string s = "ababa";
  Solution obj;
  cout << obj.removePalindromeSub(s);
}
