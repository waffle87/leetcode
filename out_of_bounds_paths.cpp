#include "leetcode.h"

class Solution {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    if (!maxMove)
      return 0;
    vector<vector<int>> curr(m + 2, vector<int>(n + 2));
    vector<vector<int>> last(m + 2, vector<int>(n + 2));
    for (int i = 1; i <= m; i++) {
      curr[i][1]++;
      curr[i][n]++;
    }
    for (int j = 1; j <= n; j++) {
      curr[1][j]++;
      curr[m][j]++;
    }
    int ans = curr[startRow + 1][startColumn + 1];
    for (int d = 1; d < maxMove; d++) {
      curr.swap(last);
      for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
          curr[i][j] = (int)(((long)last[i - 1][j] + last[i + 1][j] +
                              last[i][j - 1] + last[i][j + 1]) %
                             1000000007L);
      ans = (ans + curr[startRow + 1][startColumn + 1]) % 1000000007L;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.findPaths(2, 2, 2, 0, 0);
}
