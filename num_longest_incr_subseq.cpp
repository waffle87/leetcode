// 673. Number of Longest Increasing Subsequence
#include "leetcode.h"

/*
 * given an integer array 'nums', return the number of longest increasing
 * subsequences. notice that the sequence has to strictly increasing.
 */

class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    if (nums.empty())
      return 0;
    vector<vector<pair<int, int>>> dyn(nums.size() + 1);
    int curr_max = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int l = 0, r = curr_max;
      while (l < r) {
        int mid = l + (r - l) / 2;
        if (dyn[mid].back().first < nums[i])
          l = mid + 1;
        else
          r = mid;
      }
      int options = 1, row = l - 1;
      if (row >= 0) {
        int l1 = 0, r1 = dyn[row].size();
        while (l1 < r1) {
          int mid = l1 + (r1 - l1) / 2;
          if (dyn[row][mid].first < nums[i])
            r1 = mid;
          else
            l1 = mid + 1;
        }
        options = dyn[row].back().second;
        options -= !l1 ? 0 : dyn[row][l1 - 1].second;
      }
      dyn[l].push_back(
          {nums[i],
           (dyn[l].empty() ? options : dyn[l].back().second + options)});
      if (l == curr_max)
        curr_max++;
    }
    return dyn[curr_max - 1].back().second;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 3, 5, 4, 7}, n2 = {2, 2, 2, 2, 2};
  printf("%d\n", obj.findNumberOfLIS(n1)); // expect: 2
  printf("%d\n", obj.findNumberOfLIS(n2)); // expect: 5
}
