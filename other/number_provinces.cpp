// 547. Number of Provinces
#include "leetcode.h"

/*
 * dthere are 'n' cities. some of them are connected, while some are not. if
 * city 'a' is connected directly with city 'b', and city 'b' is connected
 * directly with city 'c', then city 'a' is connected indirectly with city 'c'.
 * a province is a group of directly or indirectly connected cities and no other
 * cities outside of the group. given an 'n x n' matrix 'is_connected' where
 * 'is_connected[i][j] = 1' if the i'th city and the j'th city are directly
 * connected, and 'is_connected[i][j] = 0' otherwise. return the total number of
 * provinces
 */

class Solution {
  void dfs(int i, vvd & is_connected, vector<bool> &vis) {
    vis[i] = true;
    for (int j = 0; j < vis.size(); j++)
      if (i != j && is_connected[i][j] && !vis[j])
        dfs(j, is_connected, vis);
  }

public:
  int findCircleNum(vvd & is_connected) {
    if (is_connected.empty())
      return 0;
    int n = is_connected.size(), groups = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < vis.size(); i++)
      groups += !vis[i] ? dfs(i, is_connected, vis), 1 : 0;
    return groups;
  }
};

int main() {
  Solution obj;
  vvd ic1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  vvd ic2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  printf("%d\n", obj.findCircleNum(ic1)); // expect: 2
  printf("%d\n", obj.findCircleNum(ic2)); // expect: 3
}
