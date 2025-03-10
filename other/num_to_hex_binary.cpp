#include "leetcode.h"
#include <string>

/*
 * given integer 'num', return string representing hexidecimal value.
 * for negative numbers, use two's complement method
 */

class Solution {
public:
  string toHex(int num) {
    string ans;
    while (num) {
      int rem = num % 16;
      if (rem > 9)
        switch (rem) {
        case 10:
          ans = 'a' + ans;
          break;
        case 11:
          ans = 'b' + ans;
          break;
        case 12:
          ans = 'c' + ans;
          break;
        case 13:
          ans = 'd' + ans;
          break;
        case 14:
          ans = 'e' + ans;
          break;
        case 15:
          ans = 'f' + ans;
          break;
        }
      else
        ans = char(rem + 48) + ans;
      num /= 16;
    }
    return ans;
  }
  int toBinary(int num) {
    int ans = 0;
    return ans;
  }
};

int main() {
  Solution obj;
  // obj.toHex(26);
  cout << obj.toHex(26) << endl;    // expect: "1a"
  cout << obj.toHex(-1) << endl;    // expect: "fffffff"
  cout << obj.toBinary(26) << endl; // expect: 11010
  cout << obj.toBinary(-1) << endl; // expect:
}
