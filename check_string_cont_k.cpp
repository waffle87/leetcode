#include "leetcode.h"

class Solution {
public:
  bool hasAllCodes(string s, int k) {
    int bitLimit = 1 << k, n = 0;
    bool combos[bitLimit];
    for (int i = 0; i < bitLimit; i++)
      combos[i] = true;
    for (int i = 0, limit = k - 1; i < limit; i++)
      n = (n << 1) + (s[i] == '1');
    for (int i = k - 1, limit = s.size(), total = bitLimit; i < limit; i++) {
      n = (n << 1) + (s[i] == '1');
      if (n >= bitLimit)
        n -= bitLimit;
      if (combos[n])
        combos[n] = false, total--;
      if (!total)
        return true;
    }
    return false;
  }
};

int main() {
  Solution obj;
  string s = "00110110";
  int k = 2;
  cout << obj.hasAllCodes(s, k);
}
