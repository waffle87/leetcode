// 859. Buddy Strings
#include "leetcode.h"

/*
 * given two strings 's' and 'goal', return 'true' if you can swap two letters
 * in 's' so the result is equal to 'goal', otherwise, return 'false'. swapping
 * letters is defined as taking two indices 'i' and 'j' 0-indexed such that 'i
 * != j' and swapping the characters at 's[i]' and 's[j]'. for example, swapping
 * indices at '0' and '2' in "abcd" results in "cbad"
 */

class Solution {
public:
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size())
      return false;
    if (s == goal) {
      unordered_map<char, int> cnt;
      for (auto i : s) {
        cnt[i]++;
        if (cnt[i] > 1)
          return true;
      }
      return false;
    }
    vector<int> diff;
    for (int i = 0; i < s.size(); i++)
      if (s[i] != goal[i]) {
        diff.push_back(i);
        if (diff.size() > 2)
          return false;
      }
    if (diff.size() != 2)
      return false;
    if ((s[diff[0]] == goal[diff[1]]) && (s[diff[1]] == goal[diff[0]]))
      return true;
    return false;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.buddyStrings("ab", "ba")); // expect: 1
  printf("%d\n", obj.buddyStrings("ab", "ab")); // expect: 0
  printf("%d\n", obj.buddyStrings("aa", "aa")); // expect: 1
}
