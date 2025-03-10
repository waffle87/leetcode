// 1569. Number of Ways to Reorder Array to Get Same BST
#include "leetcode.h"

/*
 * given an array 'nums' that represents a permutation of integers from '1 to
 * n'. we are going to construct a binary search tree (BST) by inserting the
 * elements of 'nums' in order into an initially empty BST. find the number of
 * different ways to reorder 'nums' so that the constructed BST is identical to
 * that formed from the original array 'nums'. for example given 'nums =
 * [2,1,3]', we will have 2 as the root, 1 as a left child, and three as a right
 * child. the array [2,3,1] also yields the same BST, but '[3,2,1]' yields a
 * different BST. return the number of ways to reorder 'nums' such that the BST
 * formed is identical to the original BST formed from 'nums'. since the answer
 * may be large, return it modulo 10^9+7
 */

class Solution {
  int mod = 1e+9 + 7;
  long l[10001][10001] = {0};
  bool init = false;
  long combination(int n, int r) {
    if (init)
      return l[n][r];
    l[0][0] = 1;
    for (int i = 1; i < 1001; i++) {
      l[i][0] = 1;
      for (int j = 1; j < i + 1; j++)
        l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]) % mod;
    }
    init = true;
    return l[n][r];
  }
  long dfs(vector<int> &nums) {
    if (nums.size() < 3)
      return 1;
    vector<int> l, r;
    for (auto n : nums) {
      if (n > nums[0])
        l.push_back(n);
      if (n < nums[0])
        r.push_back(n);
    }
    long c = combination(l.size() + r.size(), l.size());
    return c * dfs(l) % mod * dfs(r) % mod;
  }

public:
  int numOfWays(vector<int> &nums) { return dfs(nums) - 1; }
};

int main() {
  Solution obj;
  vector<int> n1 = {2, 1, 3}, n2 = {3, 4, 5, 1, 2}, n3 = {1, 2, 3};
  printf("%d\n", obj.numOfWays(n1)); // expect: 1
  printf("%d\n", obj.numOfWays(n2)); // expect: 5
  printf("%d\n", obj.numOfWays(n3)); // expect: 0
}
