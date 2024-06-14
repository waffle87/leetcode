#include "leetcode.h"

class Solution {
public:
  int minPartitions(string n) {
    char ans = '0';
    for (char c : n)
      if (c > ans)
        ans = c;
    return ans - '0';
  }
};

int main() {
  Solution obj;
  string n = "32";
  cout << obj.minPartitions(n);
}
