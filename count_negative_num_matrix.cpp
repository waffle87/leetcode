// 1351. Count Negative Numbers in a Sorted Matrix
#include "leetcode.h"

// given an 'm x n' matrix 'grid' which is sorted in non-increasing order both
// row-wise and column-wise, return the number of negative numbers in 'grid'

class Solution {
public:
  int countNegatives(vvd(int) & grid) {
    int ans = 0;
    for (vector<int> row : grid)
      for (int i : row)
        if (i < 0)
          ans++;
    return ans;
    for (vector<int> row : grid)
      ans += upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin();
    return ans;
    int m = grid.size(), n = grid[0].size(), r = 0, c = n - 1;
    while (r < m) {
      while (c >= 0 && grid[r][c] < 0)
        c--;
      ans += n - c - 1;
      r++;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int)
      g1 = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
  vvd(int) g2 = {{3, 2}, {1, 0}};
  printf("%d\n", obj.countNegatives(g1)); // expect: 8
  printf("%d\n", obj.countNegatives(g2)); // expect: 0
}
