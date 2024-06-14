#include "leetcode.h"

class Solution {
public:
  unordered_map<int, int> um{{0, 0}};
  inline int bto0(int b) { return (1 << (b + 1)) - 1; }
  int minimumOneBitOperations(int n) {
    if (um.count(n))
      return um[n];
    int b = 31 - __builtin_clz(n);
    return um[n] = bto0(b) - minimumOneBitOperations(n - (1 << b));
  }
};

int main() {
  Solution obj;
  cout << obj.minimumOneBitOperations(39769175); // expect 4
}
