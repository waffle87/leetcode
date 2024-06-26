#include "leetcode.h"

class Solution {
public:
  int mirrorReflection(int p, int q) {
    while ((p % 2 == 0) && (q % 2 == 0)) {
      p /= 2;
      q /= 2;
    }
    if ((p % 2) == 0 && (q % 2) != 0)
      return 2;
    if ((p % 2) != 0 && (q % 2) != 0)
      return 1;
    return 0;
  }
};

int main() {
  Solution obj;
  cout << obj.mirrorReflection(2, 1);
}
