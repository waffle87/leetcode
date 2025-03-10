// 491. Non-decreasing Subsequences
#include "leetcode.h"

/*
 * given: integer array 'nums'
 * return: all possible different non-decreasing subsequences
 * of given array with at least two elements. return value
 * can be in any order
 */

class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    set<vector<int>> seqs = {vector<int>(0)};
    for (int i = 0; i < nums.size(); i++) {
      vector<vector<int>> built(seqs.size());
      copy(seqs.begin(), seqs.end(), built.begin());
      for (auto s : built)
        if (s.empty() || nums[i] >= s.back()) {
          s.push_back(nums[i]);
          seqs.insert(s);
        }
    }
    vector<vector<int>> ans;
    for (auto s : seqs)
      if (s.size() > 1)
        ans.push_back(s);
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {4, 6, 7, 7}, n2 = {4, 4, 3, 2, 1};
  for (auto i : obj.findSubsequences(n1)) {
    for (auto j : i)
      printf("%d ", j);
    printf("\n");
  }
  printf("\n");
  for (auto i : obj.findSubsequences(n2)) {
    for (auto j : i)
      printf("%d ", j);
    printf("\n");
  }
}
