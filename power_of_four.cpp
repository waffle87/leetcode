#include "leetcode.h"

class Solution {
public:
  bool isPowerOfFour(int num) {
    if (num < 0)
      return false;
    int ans = 0, pos = 1, ones = 0;
    while (num) {
      if (num & 1)
        ans += 1, ones = pos;
      num >>= 1, pos += 1;
    }
    return ans == 1 && ones & 1;
  }
};

int main() {
  Solution obj;
  if (obj.isPowerOfFour(16))
    cout << "true";
  else
    cout << "false";
}
