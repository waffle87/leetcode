#include "leetcode.h"

class Solution {
public:
  int integerBreak(int n) {
    if (n <= 2)
      return true;
    vector<int> arrMax(n + 1, 0);
    arrMax[1] = 0, arrMax[2] = 1;
    for (int i = 3; i <= n; i++)
      for (int j = 1; j < i; j++)
        arrMax[i] = max(arrMax[i], max(j * (i - j), j * arrMax[i - j]));
    return arrMax[n];
  }
};

int main() {
  Solution obj;
  cout << obj.integerBreak(2);
}
