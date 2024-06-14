#include "leetcode.h"

class Solution {
public:
  string makeGood(string s) {
    int n = s.size();
    if (n < 2)
      return s;
    while (n > 1) {
      bool pair = false;
      for (int i = 0; i < n; i++) {
        char curr = s[i], next = s[i + 1];
        if (abs(curr - next) == 32) {
          s = s.substr(0, i) + s.substr(i + 2);
          pair = true;
          break;
        }
      }
      if (!pair)
        break;
    }
    return s;
  }
};

int main() {
  Solution obj;
  cout << obj.makeGood("HhvmLxpqQPXlMVQWwq");
}
