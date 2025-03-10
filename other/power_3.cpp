#include "leetcode.h"

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n > 1)
      while (n % 3 == 0)
        n /= 3;
    return n == 1;
  }
};

int main() {
  Solution obj;
  if (obj.isPowerOfThree(27))
    cout << "true";
  else
    cout << "false";
}
