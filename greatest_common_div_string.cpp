// 1071. Greatest Common Divisor of Strings
#include "leetcode.h"

/*
 * for two strings 's' & 't', we say 't' divides 's' if and only if s = t + ...
 * + t ie. 't' is concatenated with itself one or more times given two strings
 * 'str1' & 'str2', return largest string 'x' such that 'x' divides both 'str1'
 * & 'str2'
 */

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    /* first check if finding gcd is even possible
     * eg. ABAB + AB == AB + ABAB
     *     LEET + CODE != CODE + LEET
     */
    if (str1 + str2 == str2 + str1) {
      // get gcd of string sizes
      // eg. ABAB (4) and AB (2), gcd = 2
      int gcd = __gcd(str1.size(), str2.size());
      // return substring of (either) string
      // beginning at element 0 and a length of gcd
      return str1.substr(0, gcd);
      // if gcd isn't possible, return empty string
    } else
      return "";
  }
};

int main() {
  Solution obj;
  cout << obj.gcdOfStrings("ABCABC", "ABC") << endl;  // expect: ABC
  cout << obj.gcdOfStrings("ABABAB", "ABAB") << endl; // expect: AB
  cout << obj.gcdOfStrings("LEET", "CODE") << endl;   // expect: n/a
}
