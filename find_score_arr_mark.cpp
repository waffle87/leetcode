// 2593. Find Score of an Array After Marking All Elements
#include "leetcode.h"

/*
 * given an array 'nums' consisting of positive integers. starting with 'score =
 * 0', apply the following algorithm
 * - choose the smallest integer of the array that is not marked. if there is a
 * tie, choose the one with the smallest index
 * - add the value of the chosen integer to 'score'
 * - mark the chosen element and its two adjacent elements if they exist
 * - repeat until all the array elements are marked
 * return the score you get after applying the above algorithm
 */

class Solution {
public:
  long long findScore(vector<int> &nums) {
    long long ans = 0;
    set<pair<int, int>> s;
    for (int i = 0; i < nums.size(); ++i)
      s.insert({nums[i], i});
    for (auto i : s)
      if (nums[i.second]) {
        nums[i.second] = 0;
        if (i.second - 1 >= 0)
          nums[i.second - 1] = 0;
        if (i.second + 1 < nums.size())
          nums[i.second + 1] = 0;
        ans += i.first;
      }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {2, 1, 3, 4, 5, 2}, n2 = {2, 3, 5, 1, 3, 2};
  printf("%lld\n", obj.findScore(n1)); // expect: 7
  printf("%lld\n", obj.findScore(n2)); // expect: 5
}
