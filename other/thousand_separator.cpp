#include "leetcode.h"
#include <cmath>
#include <string>

class Solution {
public:
  string thousandSeparator(int n) {
    string s = to_string(n);
    if (trunc(log10(n)) + 1 < 4)
      return s;

    return s;
  }
};

int main() {
  Solution obj;
  obj.thousandSeparator(1234);
  // cout << obj.thousandSeparator(1234);
}
