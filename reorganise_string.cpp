// 767. Reorganize String
#include "leetcode.h"

/*
 * given a string 's', rearrange the characters of 's' so that any two adjacent
 * characters are not the same. return any possible arrangement of 's', or
 * return "" if not possible.
 */

class Solution {
public:
  string reorganizeString(string s) {
    vector<int> cnt(26);
    int most_freq = 0, i = 0;
    for (char c : s)
      if (++cnt[c - 'a'] > cnt[most_freq])
        most_freq = (c - 'a');
    if (2 * cnt[most_freq] - 1 > s.size())
      return "";
    while (cnt[most_freq]) {
      s[i] = ('a' + most_freq);
      i += 2;
      cnt[most_freq]--;
    }
    for (int j = 0; j < 26; j++)
      while (cnt[j]) {
        if (i >= s.size())
          i = 1;
        s[i] = ('a' + j);
        cnt[j]--;
        i += 2;
      }
    return s;
  }
};

int main() {
  Solution obj;
  cout << obj.reorganizeString("aab");  // expect: aba
  cout << obj.reorganizeString("aaab"); // expect:
}
