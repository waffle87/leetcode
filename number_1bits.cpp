#include "leetcode.h"

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
      if ((n & 1) > 0)
        ++count;
      n = n >> 1;
    }
    return count;
  }
};

int main() {
  uint32_t n = 00000000000000000000000000001011;
  Solution obj;
  cout << obj.hammingWeight(n);
}
