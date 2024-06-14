// 546. Remove Boxes
#include "leetcode.h"

/*
 * given several 'boxes' with different colours represented by different
 * positive numbers. you may experience several rounds to remove boxes until
 * there is no box left. each time you can choose some continuous boxes with the
 * same colour (ie. composed of 'k' boxes, 'k >= 1'), remove them and get 'k *
 * k' points. return the maximum points you can get.
 */

class Solution {
  int dp[100][100][100] = {0};
  int dfs(vector<int> &boxes, int i, int j, int k) {
    if (j < i)
      return 0;
    if (dp[i][j][k])
      return dp[i][j][k];
    int res = (1 + k) * (1 + k) + dfs(boxes, i + 1, j, 0);
    for (int m = i + 1; m <= j; m++)
      if (boxes[m] == boxes[i])
        res = max(res, dfs(boxes, i + 1, m - 1, 0) + dfs(boxes, m, j, k + 1));
    dp[i][j][k] = res;
    return res;
  }

public:
  int removeBoxes(vector<int> &boxes) {
    int n = boxes.size();
    return dfs(boxes, 0, n - 1, 0);
  }
};

int main() {
  Solution obj;
  vector<int> b1 = {1, 3, 2, 2, 2, 3, 4, 3, 1}, b2 = {1, 1, 1}, b3 = {1};
  printf("%d\n", obj.removeBoxes(b1)); // expect: 23
  printf("%d\n", obj.removeBoxes(b2)); // expect: 9
  printf("%d\n", obj.removeBoxes(b3)); // expect: 1
}
