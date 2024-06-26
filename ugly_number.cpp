#include "leetcode.h"

class Solution {
public:
  bool isUgly(int n) {
    if (n == 0)
      return false;
    for (int i : {2, 3, 5})
      while (n % i == 0)
        n /= i;
    return n == 1;
  }
};

int main() {
  Solution obj;
  if (obj.isUgly(6))
    cout << "true";
  else
    cout << "false";
}
