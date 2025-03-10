#include "leetcode.h"

class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    vvd dp(m + 1, vector<int>(n + 1));
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (nums1[i - 1] == nums2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = 0;
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {1, 2, 3, 2, 1}, nums2 = {3, 2, 1, 4, 7};
  cout << obj.findLength(nums1, nums2);
}
