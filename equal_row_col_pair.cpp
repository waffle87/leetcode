// 2352. Equal Row and Column Pairs
#include "leetcode.h"

/*
 * given a 0-indexed n x n integer matrix 'grid', return the number of pairs
 * (ri, cj) such that row 'ri' and column 'ci' are equal. a row and column pair
 * is considered equal if they contain the same elements in the same order (ie.
 * an equal array)
 */

class Solution {
public:
  int equalPairs(vvd(int) & grid) {
    int ans = 0;
    map<vector<int>, int> mv;
    for (int i = 0; i < grid.size(); i++)
      mv[grid[i]]++;
    for (int i = 0; i < grid[0].size(); i++) {
      vector<int> v;
      for (int j = 0; j < grid.size(); j++)
        v.push_back(grid[j][i]);
      ans += mv[v];
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) g1 = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
  vvd(int) g2 = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
  printf("%d\n", obj.equalPairs(g1)); // expect: 1
  printf("%d\n", obj.equalPairs(g2)); // expect: 3
}
