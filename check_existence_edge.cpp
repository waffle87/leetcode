// 1697. Checking Existence of Edge Length Limited Paths
#include "leetcode.h"

/*
 * an undirected graph of 'n' nodes is defined by 'edge_list',
 * where 'edge_list[i] = [ui, vi, disi]' denotes an edge between
 * nodes 'ui' and 'vi' with distance 'disi'. note that there may
 * be multiple edges between two nodes. given an array 'queries',
 * where 'queries[j] = [pj, qj, limitj]', your task is to determine
 * for each 'queries[j]' whthere there is a path between 'pj' and
 * 'qj' such that each edge on the path has a distance strictly less
 * than 'limitj'. return boolean array where 'ans.length == queries.len'
 * and the j'th value of 'ans' is true if there is a path for
 * 'queries[j]' is true, and false otherwise
 */

class UnionFind {
  vector<int> parent;

public:
  UnionFind(int n) : parent(n) { iota(begin(parent), end(parent), 0); }
  void connect(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y)
      return;
    parent[x] = y;
  }
  bool connected(int i, int j) { return find(i) == find(j); }
  int find(int a) { return parent[a] == a ? a : (parent[a] = find(parent[a])); }
};

class Solution {
public:
  vector<bool> distanceLimitedPathsExist(int n, vvd & edge_list,
                                         vvd & queries) {
    vector<bool> ans(queries.size());
    for (int i = 0; i < queries.size(); ++i)
      queries[i].push_back(i);
    sort(begin(queries), end(queries),
         [&](auto &a, auto &b) { return a[2] < b[2]; });
    sort(begin(edge_list), end(edge_list),
         [&](auto &a, auto &b) { return a[2] < b[2]; });
    UnionFind uf(n);
    int i = 0;
    for (auto &q : queries) {
      int u = q[0], v = q[1], limit = q[2], qid = q[3];
      for (; i < edge_list.size() && edge_list[i][2] < limit; ++i)
        uf.connect(edge_list[i][0], edge_list[i][1]);
      ans[qid] = uf.connected(u, v);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd el1 = {{0, 1, 2}, {1, 2, 4}, {2, 0, 8}, {1, 0, 6}};
  vvd q1 = {{0, 1, 2}, {0, 2, 5}};
  vector<bool> dlpe1 = obj.distanceLimitedPathsExist(3, el1, q1);
  vvd el2 = {{0, 1, 10}, {1, 2, 5}, {2, 3, 9}, {3, 4, 13}};
  vvd q2 = {{0, 4, 14}, {1, 4, 13}};
  vector<bool> dlpe2 = obj.distanceLimitedPathsExist(5, el2, q2);
  for (int i = 0; i < 2; i++)
    cout << dlpe1[i] << ' '; // expect: 0 1
  printf("\n");
  for (int i = 0; i < 2; i++)
    cout << dlpe2[i] << ' '; // expect: 1 0
}
