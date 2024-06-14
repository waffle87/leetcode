// 87. Scramble String
#include "leetcode.h"

/*
 * string 's' can be scrambled to get string 't' using the following algorithm:
 * if length of string is 1, exit
 * if lenght of string is > 1:
 *   split string into two non-empty substrings at random index
 *   randomly decide to swap two substrings or to keep them in same order
 *   apply step 1 recursively
 * given two strings 's1' and 's2' of the same length, return true if 's2' is a
 * scrambled string of 's1', otherwise return false
 */

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size())
      return false;
    return is_scrambled(s1, s2);
  }

private:
  unordered_map<string, bool> um;
  bool is_scrambled(string s1, string s2) {
    int n = s1.size();
    if (s1 == s2 || n == 0)
      return true;
    string key = s1 + ' ' + s2;
    if (um.find(key) != um.end())
      return um[key];
    bool flag = false;
    for (int i = 1; i < n; i++) {
      if (is_scrambled(s1.substr(0, i), s2.substr(n - i, i)) &&
          is_scrambled(s1.substr(i, n - i), s2.substr(0, n - i))) {
        flag |= true;
        break;
      }
      if (is_scrambled(s1.substr(0, i), s2.substr(0, i)) &&
          is_scrambled(s1.substr(i, n - i), s2.substr(i, n - i))) {
        flag |= true;
        break;
      }
    }
    um[key] = flag;
    return flag;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.isScramble("great", "rgeat")); // expect: 1
  printf("%d\n", obj.isScramble("abcde", "caebd")); // expect: 0
  printf("%d\n", obj.isScramble("a", "a"));         // expect: 1
}
