// 228. Summary Ranges
#include "leetcode.h"

/*
 * given a sorted unique integer array 'nums'. a range '[a, b]' isthe set of all
 * integers from 'a' to 'b' (inclusive). return the smallest sorted list of
 * ranges that cover all the numbers in the array exactlyh. that is, each
 * element of 'nums' is covered by exactly one of the ranges, and there is no
 * integer 'x' such that 'x' is in one of the ranges but not in 'nums' each
 * range '[a, b]' in the list should be outgput as:
 * - "a->b" if a != b
 * - "a" if a == b
 */

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    int n = nums.size();
    vector<string> ans;
    string tmp = "";
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j + 1 < n && nums[j + 1] == nums[j] + 1)
        j++;
      if (j > i) {
        tmp += to_string(nums[i]);
        tmp += "->";
        tmp += to_string(nums[j]);
      } else
        tmp += to_string(nums[i]);
      ans.push_back(tmp);
      tmp = "";
      i = j;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {0, 1, 2, 4, 5, 7}, n2 = {0, 2, 3, 4, 6, 8, 9};
  for (auto i : obj.summaryRanges(n1))
    cout << i << ' '; // expect: 0.2 4.5 7
  printf("\n");
  for (auto i : obj.summaryRanges(n2))
    cout << i << ' '; // expect: 0.4 6 8.9
}
