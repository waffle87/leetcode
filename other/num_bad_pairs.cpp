// 2364. Count Number of Bad Pairs
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums'. a pair of indices '(i, j)' is
 * a bad pair if 'i < j' and 'j - i != nums[j] - nums[i]'. return the total
 * number of bad pairs in 'nums'.
 */

class Solution {
public:
  long long countBadPairs(vector<int> &nums) {
    long long ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i) {
      ans += i - mp[nums[i] - i];
      mp[nums[i] - i]++;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {4, 1, 3, 3}, n2 = {1, 2, 3, 4, 5};
  printf("%lld\n", obj.countBadPairs(n1)); // expect: 5
  printf("%lld\n", obj.countBadPairs(n2)); // expect: 0
}
