#include "leetcode.h"
class Solution {
public:
  int countVowelPermutation(int n) {
    int ans = 0;
    memo.resize(n + 1, vector<int>(5, -1));
    for (int i = 0; i < 5; i++)
      ans += dp(n, i), ans %= mod;
    return ans;
  }

private:
  int mod = 1e9 + 7;
  vector<vector<int>> relation = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}}, memo;
  int dp(int n, int v) {
    if (n == 1)
      return 1;
    if (memo[n][v] != -1)
      return memo[n][v];
    memo[n][v] = 0;
    for (int &i : relation[v])
      memo[n][v] += dp(n - 1, i), memo[n][v] %= mod;
    return memo[n][v];
  }
};

int main() {
  Solution obj;
  cout << obj.countVowelPermutation(1);
}
