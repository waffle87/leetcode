#include "leetcode.h"

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    memset(t, -1, sizeof(t));
    m = s1.size();
    n = s2.size();
    N = s3.size();
    if (m + n != N)
      return false;
    return helper(s1, s2, s3, 0, 0);
  }

private:
  int m, n, N;
  int t[101][101];
  bool helper(string s1, string s2, string s3, int i, int j) {
    if (i >= m && j >= n && i + j >= N)
      return true;
    if (i + j >= N)
      return false;
    if (t[i][j] != -1)
      return t[i][j];
    return t[i][j] = ((s1[i] == s3[i + j] && helper(s1, s2, s3, i + 1, j)) ||
                      (s2[j] == s3[i + j] && helper(s1, s2, s3, i, j + 1)));
  }
};

int main() {
  Solution obj;
  string s1 = "aabcc";
  string s2 = "dbbca";
  string s3 = "aadbbcbcac";
  if (obj.isInterleave(s1, s2, s3))
    cout << "true";
  else
    cout << "false";
}
