// 2448. Minimum Cost to Make Array Equal
#include "leetcode.h"

/*
 * given two 0-indexed arrays 'nums' and 'cost' consisting each of 'n' positive
 * integers. you can do the following operation any number of times:
 * - increase or decrease any element of the array 'nums' by 1
 * the cost of doing one operation on the i'th element is 'cost[i]'. return the
 * minimum total cost such that all the elements of the array 'nums' become
 * equal
 */

class Solution {
  long long helper(vector<int> &nums, vector<int> &cost, int x) {
    long long res = 0;
    for (int i = 0; i < nums.size(); ++i)
      res += 1L * abs(nums[i] - x) * cost[i];
    return res;
  }

public:
  long long minCost(vector<int> &nums, vector<int> &cost) {
    long long left = 1, right = 1000000, ans = helper(nums, cost, 1), mid;
    while (left < right) {
      mid = (left + right) / 2;
      long long y1 = helper(nums, cost, mid);
      long long y2 = helper(nums, cost, mid + 1);
      ans = min(y1, y2);
      if (y1 < y2)
        right = mid;
      else
        left = mid + 1;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 3, 5, 2}, c1 = {2, 3, 1, 14};
  vector<int> n2 = {2, 2, 2, 2, 2}, c2 = {4, 2, 8, 1, 3};
  printf("%lld\n", obj.minCost(n1, c1)); // expect: 8
  printf("%lld\n", obj.minCost(n2, c2)); // expect: 0
}
