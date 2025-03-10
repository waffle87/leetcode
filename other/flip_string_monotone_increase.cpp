#include "leetcode.h"

/*
 * a binary string is monotone increasing if it consists of some number
 * of 0's (none is valid), followed by some number of 1's (none is valid)
 * given: binary string 's'. you can flip 's[i]' changing for 0 to 1 or vice
 * versa. return the minimum number of flips to make 's' monotone increasing.
 */

class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int flips = 0, cnt = 0;
    for (auto i : s) {
      if (i == '1')
        cnt++;
      else
        flips++;
      flips = min(flips, cnt);
    }
    return flips;
  }
};

int main() {
  Solution obj;
  cout << obj.minFlipsMonoIncr("00110") << endl;
  // expect: 1
  // flip last digit to get 00111
  cout << obj.minFlipsMonoIncr("010110") << endl;
  // expect: 2
  // flip s[1] s[5] to get 000111
  cout << obj.minFlipsMonoIncr("00011000") << endl;
  // expect: 2
  // flip s[3] s[4] to get 00000000
}
