// 2192. All Ancestors of a Node in a Directed Acyclic Graph
#include "leetcode.h"

/*
 * given a positive integer 'n' representing the number of nodes of a directed
 * acyclic graph (dag). the nodes are numbered from 0 to 'n - 1' inclusively.
 * you are also given a 2d integer array 'edges' where 'edges[i] = [fromi, toi]'
 * denotes that there is a unidirectional edge from 'fromi' to 'toi' in the
 * graph. return a list 'answer' where 'answer[i]' is the list of ancestors of
 * the i'th node, sorted in ascending order. a node 'u' is an ancestor of
 * another node 'v' if 'u' can reach 'v' via a set of edges.
 */

class Solution {
private:
  void dfs(int x, int curr, vector<vector<int>> &res,
           vector<vector<int>> &direct_child) {
    for (auto &i : direct_child[curr])
      if (!res[i].size() || res[i].back() != x) {
        res[i].push_back(x);
        dfs(x, i, res, direct_child);
      }
  }

public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> ans(n), direct_child(n);
    for (auto &i : edges)
      direct_child[i[0]].push_back(i[1]);
    for (int i = 0; i < n; i++)
      dfs(i, i, ans, direct_child);
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) e1 = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7},
                 {3, 5}, {3, 6}, {3, 7}, {4, 6}};
  vvd(int) e2 = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2},
                 {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
  vvd(int) ga1 = obj.getAncestors(8, e1), ga2 = obj.getAncestors(5, e2);
  for (int i = 0; i < ga1.size(); i++) {
    for (int j = 0; j < ga1[0].size(); j++)
      printf("%d ",
             ga1[i][j]); // expect:
                         // [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < ga2.size(); i++) {
    for (int j = 0; j < ga2[0].size(); j++)
      printf("%d ",
             ga2[i][j]); // expect: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
    printf("\n");
  }
  printf("\n");
}
