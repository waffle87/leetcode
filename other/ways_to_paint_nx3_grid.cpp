#include "leetcode.h"

class Solution {
public:
  int numOfWays(int n) {
    long a = 6, b = 6, c, d, mod = 1e9 + 7;
    for (int i = 1; i < n; ++i) {
      c = a * 3 + b * 2;
      d = a * 2 + b * 2;
      a = c % mod;
      b = d % mod;
    }
    return (a + b) % mod;
  }
};

int main() {
  Solution obj;
  cout << obj.numOfWays(1);
}
