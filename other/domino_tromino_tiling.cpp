#include "leetcode.h"
#include <vector>

class Solution {
public:
  int numTilings(int n) {
    int mod = 1e9;
    mod += 7;
    vector<long long> ans(1001, 0);
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 5;
    if (n <= 3)
      return ans[n];
    for (int i = 4; i <= n; ++i) {
      ans[i] = 2 * ans[i - 1] + ans[i - 3];
      ans[i] %= mod;
    }
    return ans[n];
  }
};

int main() {
  Solution obj;
  cout << obj.numTilings(3); // 5
  cout << endl;
  cout << obj.numTilings(1); // 1
}
