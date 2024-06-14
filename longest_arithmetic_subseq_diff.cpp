// 1218. Longest Arithmetic Subsequence of Given Difference
#include "leetcode.h"

/*
 * given an integer array 'arr' and an integer 'difference', return the length
 * of the longest subsequence in 'arr' which is an arithmetic sequence such that
 * the difference between adjacent elements in the subsequence equals
 * 'difference'. a subsequence is a sequence that can be derived from 'arr' by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 */

class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    int ans = 1;
    unordered_map<int, int> max;
    for (int i = 0; i < arr.size(); i++)
      max[arr[i]] = max[arr[i] - difference] + 1;
    for (auto i : max)
      ans = std::max(ans, i.second);
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> a1 = {1, 2, 3, 4}, a2 = {1, 3, 5, 7},
              a3 = {1, 5, 7, 8, 5, 3, 4, 2, 1};
  printf("%d\n", obj.longestSubsequence(a1, 1));  // expect: 4
  printf("%d\n", obj.longestSubsequence(a2, 1));  // expect: 1
  printf("%d\n", obj.longestSubsequence(a3, -2)); // expect: 4
}
