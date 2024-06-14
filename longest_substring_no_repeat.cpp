#include "leetcode.h"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0)
      return 0;
    map<char, int> charsInSub;
    int ans = 0, j = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (charsInSub.find(s[i]) != charsInSub.end())
        charsInSub.find(s[i])->second++;
      else
        charsInSub.insert(pair<char, int>(s[i], 1));
      while (charsInSub.find(s[i])->second > 1) {
        charsInSub.find(s[j])->second--;
        ++j;
      }
      ans = ans >= i - j + 1 ? ans : i - j + 1;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  string s = "abcabcbb";
  cout << obj.lengthOfLongestSubstring(s);
}
