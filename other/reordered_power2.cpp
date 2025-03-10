#include "leetcode.h"

class Solution {
public:
  bool reorderedPowerOf2(int n) {
    string ans1 = to_string(n);
    sort(ans1.begin(), ans1.end());
    for (int i = 0; i < 30; i++) {
      string ans2 = to_string(1 << i);
      sort(ans2.begin(), ans2.end());
      if (ans1 == ans2)
        return true;
    }
    return false;
  }
};

int main() {
  Solution obj;
  if (obj.reorderedPowerOf2(10))
    cout << "true";
  else
    cout << "false";
}
