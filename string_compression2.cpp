#include "leetcode.h"

class Solution {
public:
  int getLengthOfOptimalCompression(string s, int k) {
    memset(dp, -1, sizeof(dp));
    str = s, p = s.size();
    return solve(0, k);
  }

private:
  const static int N = 127;
  int dp[N][N], p;
  string str;
  inline int helper(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }
  int solve(int left, int k) {
    if (k < 0)
      return N;
    if (left >= p || p - left <= k)
      return 0;
    int &ans = dp[left][k];
    if (ans != -1)
      return ans;
    ans = N;
    int count[26] = {0};
    for (int i = left, j = 0; i < p; i++) {
      j = max(j, ++count[str[j] - 'a']);
      ans = min(ans, 1 + helper(j) + solve(i + 1, k - (i - left + 1 - j)));
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.getLengthOfOptimalCompression("aaabcccd", 2);
}
