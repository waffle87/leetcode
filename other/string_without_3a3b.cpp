// 984. String Without AAA or BBB
#include "leetcode.h"

/*
 * given two integers 'a' and 'b', return any string 's' such that
 * - 's' has length 'a + b' and contains exactly 'a' a letters and exactly 'b' b
 * letters.
 * - the substring 'aaa' does not occur in 's' and
 * - the substring 'bbb' does not occur in 's'
 */

class Solution {
public:
  string strWithout3a3b(int a, int b) {
    string ans = "";
    int cnta = 0, cntb = 0, total = a + b;
    for (int i = 0; i < total; i++) {
      if ((b >= a && cntb < 2) || (cnta == 2 && b)) {
        ans += 'b';
        b--;
        cntb++;
        cnta = 0;
      } else if ((a >= b && cnta < 2) || (cntb == 2 && a)) {
        ans += 'a';
        a--;
        cnta++;
        cntb = 0;
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.strWithout3a3b(1, 2) << endl; // expect: "abb"
  cout << obj.strWithout3a3b(4, 1) << endl; // expect: "aabaa"
}
