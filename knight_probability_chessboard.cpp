// 688. Knight Probability in Chessboard
#include "leetcode.h"

/*
 * on an 'n x n' chessboard, a knight starts at the cell '(row, column)' and
 * attempts to make exactly 'k' moves. the rows and columns are 0-indexed, so
 * the top-left cell is '(0, 0)', and the bottom-right cell is '(n - 1, n - 1)'.
 * a chess knight has eight possible moves it can make, as illustrated below
 * [see image]. each move is two cells in a cardinal direction, then one cell in
 * an orthogonal direction.
 */

class Solution {
public:
  double knightProbability(int n, int k, int row, int col) {
    unordered_map<int, unordered_map<int, unordered_map<int, double>>> dp;
    if (dp.count(row) && dp[row].count(col) && dp[row][row].count(k))
      return dp[row][col][k];
    if (row < 0 || row >= n || col < 0 || col >= n)
      return 0;
    if (!k)
      return 1;
    double total = knightProbability(n, k - 1, row - 1, col - 2) +
                   knightProbability(n, k - 1, row - 2, col - 1) +
                   knightProbability(n, k - 1, row - 1, col + 2) +
                   knightProbability(n, k - 1, row - 2, col + 1) +
                   knightProbability(n, k - 1, row + 1, col + 2) +
                   knightProbability(n, k - 1, row + 2, col + 1) +
                   knightProbability(n, k - 1, row + 1, col - 2) +
                   knightProbability(n, k - 1, row + 2, col - 1);
    double ans = total / 8;
    dp[row][col][k] = ans;
    return ans;
  }
};

int main() {
  Solution obj;
  printf("%f\n", obj.knightProbability(3, 2, 0, 0)); // expect: 0.06250
  printf("%f\n", obj.knightProbability(1, 0, 0, 0)); // expect: 1.00000
}
