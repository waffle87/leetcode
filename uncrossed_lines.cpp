// 1035. Uncrossed Lines
#include "leetcode.h"

/*
 * given two integer arrays 'nums1' and 'num2'. we write the integers of 'nums1'
 * and 'nums2' (in the order they are given) on two separate horizontal lines.
 * we may draw connecting lines: a straight line connecting two numbers
 * 'nums1[i]' and 'nums2[j]' such thatyr
 * - 'nums1[i] == nums2[j]' and
 * - the line we draw does not intersect any other connecting (non-horizontal)
 * line note that a connecting line cannot intereset even at the endpoints.
 * return the maximum number of connecting lines we can draw in this way.
 */

class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    vvd(int) dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (nums1[i - 1] == nums2[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    return dp[n][m];
  }
};

int main() {
  Solution obj;
  vector<int> n11 = {1, 4, 2}, n21 = {1, 2, 4};
  vector<int> n12 = {2, 5, 1, 2, 5}, n22 = {10, 5, 2, 1, 5, 2};
  vector<int> n13 = {1, 3, 7, 1, 7, 5}, n23 = {1, 9, 2, 5, 1};
  printf("%d\n", obj.maxUncrossedLines(n11, n21)); // expect: 2
  printf("%d\n", obj.maxUncrossedLines(n12, n22)); // expect: 3
  printf("%d\n", obj.maxUncrossedLines(n13, n23)); // expect: 2
}
