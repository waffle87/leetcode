#include "leetcode.h"

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.size() == 0)
      return "";
    int i = 0, j = 0, n = s.size();
    bool p[n][n] = {false};
    for (int x = 0; x < n; x++) {
      p[x][x] = true;
      if (x == n - 1)
        break;
      p[x][x + 1] = (s[x] == s[x + 1]);
    }
    for (int i = n - 3; i >= 0; --i)
      for (int j = i + 2; j < n; ++j)
        p[i][j] = (p[i + 1][j - 1] && s[i] == s[j]);
    int max = 0;
    string ans = "";
    for (int i = 0; i < n; i++)
      for (int j = i; j < n; j++)
        if (p[i][j] == true && j - i + 1 > max) {
          max = j - i + 1;
          ans = s.substr(i, j - i + 1);
        }
    return ans;
  }
};

int main() {
  Solution obj;
  string s = "babad";
  cout << obj.longestPalindrome(s);
}
