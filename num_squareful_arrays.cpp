// 996. Number of Squareful Arrays
#include "leetcode.h"

/*
 * an array is squareful if the sum of every pair of adjacent elements is a
 * perfect square. given an intger array nums, return the number of permutations
 * of 'nums' that are squareful. two permutations 'perm1' and 'perm2' are
 * different if there is some index 'i' such that 'perm1[i] != perm2[i]'.
 */

class Solution {
  bool is_square(int x) {
    int t = sqrt(x);
    return t * t == x;
  }
  int fact(int x) {
    int t = 1;
    for (int i = 2; i <= x; i++)
      t *= i;
    return t;
  }

public:
  int numSquarefulPerms(vector<int> &nums) {
    int n = nums.size(), cnt = 1;
    sort(nums.begin(), nums.end());
    vector<int> s;
    for (int i = 1; i < n; i++) {
      if (nums[i] != nums[i - 1]) {
        s.push_back(cnt);
        cnt = 0;
      }
      cnt++;
    }
    s.push_back(cnt);
    vvd f(1 << n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
      f[1 << i][i] = 1;
    for (int S = 1; S < 1 << n; S++)
      for (int i = 0; i < n; i++)
        if (S & (1 << i))
          for (int j = 0; j < n; j++)
            if (!(S & (1 << j)) && is_square(nums[i] + nums[j]))
              f[S | (1 << j)][j] += f[S][i];
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += f[(1 << n) - 1][i];
    for (int i = 0; i < s.size(); i++)
      ans /= fact(s[i]);
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 17, 8}, n2 = {2, 2, 2};
  printf("%d\n", obj.numSquarefulPerms(n1)); // expect: 2
  printf("%d\n", obj.numSquarefulPerms(n2)); // expect: 1
}
