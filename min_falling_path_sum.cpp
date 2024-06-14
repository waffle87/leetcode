#include "leetcode.h"

/*
 * given NxN array of integers 'matrix' return the minimum
 * sum of any falling path through 'matrix'
 *
 * a falling path starts at any element in row 0 and chooses
 * the element in the next row that is either directly below
 * or diagonally left/right that obviously makes for the lowest sum
 */

class Solution {
public:
  int minFallingPathSum(vvd(int) & matrix) {
    vvd(int) dp(matrix.size(), vector<int>(matrix.size(), INT_MAX));
    for (int i = 0; i < matrix.size(); i++)
      dp[0][i] = matrix[0][i];
    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        if (j > 0 && j < matrix.size() - 1) {
          dp[i][j] =
              min(dp[i - 1][j - 1] + matrix[i][j], dp[i - 1][j] + matrix[i][j]);
          dp[i][j] = min(dp[i - 1][i + 1] + matrix[i][j], dp[i][j]);
        } else if (j == 0)
          dp[i][j] =
              min(dp[i - 1][j + 1] + matrix[i][j], dp[i - 1][j] + matrix[i][j]);
        else if (j == matrix.size() - 1)
          dp[i][j] =
              min(dp[i - 1][j - 1] + matrix[i][j], dp[i - 1][j] + matrix[i][j]);
      }
    }
    int ans = INT_MAX;
    for (auto &x : dp[dp.size() - 1])
      ans = min(ans, x);
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) matrix = {{2, 1, 3},          // 1
                     {6, 5, 4},          //-> 4
                     {7, 8, 9}};         // 8 <-
  cout << obj.minFallingPathSum(matrix); // expect 13
}
