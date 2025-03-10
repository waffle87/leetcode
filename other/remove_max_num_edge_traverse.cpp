// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
#include "leetcode.h"

/*
 * alice and bob have an undirected graph of 'n' nodes and three
 * types of edges:
 * type1: can be traversed by alice only
 * type2: can be traversed by bob only
 * type3: can be traversed by both alice and bob
 * given an array of 'edges' where 'edges[i] = [typei, ui, vi]'
 * represents a bidirectional edge of type 'typei' between nodes
 * 'ui' and 'vi', find the maximum number of edges you can remove
 * so that after removing the edges, the graph can still be fully
 * traversed by alice and bob if starting from any node, they can
 * reach all other nodes. return the maximum number of edges you
 * can remove, or return -1 if alice and bob cannot traverse graph
 */

class Solution {
public:
  int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
  }
  int maxNumEdgesToRemove(int n, vvd & edges) {
    vector<int> ds_both(n + 1, -1);
    int used = 0;
    for (int type = 3; type > 0; --type) {
      auto ds_one = ds_both;
      auto &ds = type == 3 ? ds_both : ds_one;
      for (auto &e : edges) {
        if (e[0] == type) {
          int i = find(ds, e[1]), j = find(ds, e[2]);
          if (i != j) {
            ++used;
            if (ds[j] < ds[i])
              swap(i, j);
            ds[i] += ds[j];
            ds[j] = i;
          }
        }
      }
      if (type != 3 && ds[find(ds, 1)] != -n)
        return -1;
    }
    return edges.size() - used;
  }
};

int main() {
  Solution obj;
  vvd
      e1 = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
  vvd e2 = {{3, 1, 2}, {3, 2, 3}, {1, 1, 4}, {2, 1, 4}};
  vvd e3 = {{3, 2, 3}, {1, 1, 2}, {2, 3, 4}};
  printf("%d\n", obj.maxNumEdgesToRemove(4, e1));
  printf("%d\n", obj.maxNumEdgesToRemove(4, e2));
  printf("%d\n", obj.maxNumEdgesToRemove(4, e3));
}
