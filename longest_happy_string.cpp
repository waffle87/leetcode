// 1405. Longest Happy String
#include "leetcode.h"

/*
 * a string 's' is called happy if it satisfies the following conditions: 's'
 * only contains the letters 'a', 'b', 'c', does not contain any of 'aaa',
 * 'bbb', or 'ccc' as a substring, contains at most 'n' occurences of the
 * letters 'a', 'b', 'c'. given three integers, return the longest possible
 * happy string. if there are multiple longest happy strings, return any of
 * them. if there is no such string, return the empty string
 */

class Solution {
public:
  string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b',
                              char cc = 'c') {
    if (a < b)
      return longestDiverseString(b, a, c, bb, aa, cc);
    if (b < c)
      return longestDiverseString(a, c, b, aa, cc, bb);
    if (!b)
      return string(min(2, a), aa);
    auto use_a = min(2, a), use_b = a - use_a >= b ? 1 : 0;
    return string(use_a, aa) + string(use_b, bb) +
           longestDiverseString(a - use_a, b - use_b, c, aa, bb, cc);
  }
};

int main() {
  Solution obj;
  cout << obj.longestDiverseString(1, 1, 7) << endl; // expect: ccaccbcc
  cout << obj.longestDiverseString(7, 1, 0) << endl; // expect: aabaa
}
