// dnw
#include "leetcode.h"

class Solution {
public:
  vector<int> ans;
  vector<int> lexicalOrder(int n) {
    ans.resize(n);
    int pos = 0;
    for (int i = 1; i <= 9 && i <= n; i++)
      helper(i, n, pos);
    return ans;
  }

private:
  void helper(int i, int n, int pos) {
    ans[pos++] = i;
    int tmp;
    for (int j = 0; j <= 9; j++) {
      tmp = i * 10 + j;
      if (tmp > n)
        break;
      helper(tmp, n, pos);
    }
  }
};
