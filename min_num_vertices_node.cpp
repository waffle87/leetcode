// 1557. Minimum Number of Vertices to Reach All Nodes
#include "leetcode.h"

/*
 * given a directed acyclic graph, with 'n' vertices numbered from 0 to 'n - 1',
 * and an array 'edges', where 'edges[i] = [fromi, toi]' representes a directed
 * edge from node 'fromi' to node 'toi'. find the smallest set of vertices from
 * which all nodes in the graph are reachale. it's guaranteed that a unique
 * solution exists. notice you cano return the vertices in any order.
 */

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vvd(int) & edges) {
    vector<int> ans, seen(n);
    for (auto e : edges)
      seen[e[1]] = 1;
    for (int i = 0; i < n; ++i)
      if (!seen[i])
        ans.push_back(i);
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) e1 = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
  vvd(int) e2 = {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}};
  for (auto i : obj.findSmallestSetOfVertices(6, e1))
    printf("%d ", i); // expect: 0 3
  printf("\n");
  for (auto i : obj.findSmallestSetOfVertices(5, e2))
    printf("%d ", i); // expect: 0 2 3
}
