// 3068. Find the Maximum Sum of Node Values
#include "leetcode.h"

/*
 * there exists an undirected tree with 'n' nodes numbered 0 to 'n - 1'. you are
 * given a 0-indexed 2d integer array 'edges' of length 'n - 1', where 'edges[i]
 * = [ui,vi]' indicates that there is an edge between nodes 'ui' and 'vi' in the
 * tree. you are also given a positive integer 'k' and a 0 indexed array of non
 * negative integers 'nums' of length 'n' where 'nums[i]' represents the value
 * of the node numbered 'i'. return the maximum possible sum of the values alice
 * can achieve by performing the operation any number of times.
 */

class Solution {
public:
  long long maximumValueSum(vector<int> &nums, int k,
                            vector<vector<int>> &edges) {
    int change = 0;
    long long sum = 0LL, ans = 0LL;
    for (auto &n : nums) {
      if ((n ^ k) > n) {
        change++;
        sum += (n ^ k);
      } else
        sum += n;
    }
    if (!(change & 1))
      return sum;
    for (int i = 0; i < nums.size(); i++)
      ans = max(ans, sum - abs(nums[i] - (nums[i] ^ k)));
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 2, 1}, n2 = {2, 3}, n3 = {7, 7, 7, 7, 7, 7};
  vvd e1 = {{0, 1}, {0, 2}}, e2 = {{0, 1}},
           e3 = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
  printf("%lld\n", obj.maximumValueSum(n1, 3, e1)); // expect: 6
  printf("%lld\n", obj.maximumValueSum(n2, 7, e2)); // expect: 9
  printf("%lld\n", obj.maximumValueSum(n3, 3, e3)); // expect: 42
}
