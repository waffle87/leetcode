// 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
#include "leetcode.h"

/*
 * given a weighted undirected connected graph with 'n' vertices numbered from 0
 * to 'n - 1' and an array 'edges' where 'edges[i] = [ai, bi, weighti]'
 * represents a bidrectional and weighted edge between nodes 'ai' and 'bi'. a
 * minimum spanning tree (MST) is a subset of the graph's edges that connects
 * all vertices withoutcycles and with the minimum possible total edge weight.
 * find all critical and pseudo-critical edges in the given graph's MST. an MST
 * edge whose deletion from the graph would casue the MST weight to increase is
 * called a critical edge. on the other hand, a pseudo-critical edge is that
 * which can appear in some MSTs butnot all. note that you can return the
 * indices of the edges in any order.
 */

class UnionFind {
  vector<int> f, rank;

public:
  UnionFind(int n) {
    rank = vector<int>(n, 1);
    f.resize(n);
    for (int i = 0; i < n; ++i)
      f[i] = i;
  }
  int find(int x) {
    if (f[x] == x)
      return x;
    else
      return f[x] = find(f[x]);
  }
  void uinion(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy)
      return;
    if (rank[fx] > rank[fy])
      swap(fx, fy);
    f[fx] = fy;
    if (rank[fx] == rank[fy])
      rank[fy]++;
  }
};

class Solution {
  int get_mst(const int n, const vvd & edges, int block_edge,
              int pre_edge = -1) {
    UnionFind uf(n);
    int weight = 0;
    if (pre_edge != -1) {
      weight += edges[pre_edge][2];
      uf.uinion(edges[pre_edge][0], edges[pre_edge][1]);
    }
    for (int i = 0; i < edges.size(); ++i) {
      if (block_edge == i)
        continue;
      const auto &e = edges[i];
      if (uf.find(e[0]) == uf.find(e[1]))
        continue;
      uf.uinion(e[0], e[1]);
      weight += e[2];
    }
    for (int i = 0; i < n; ++i)
      if (uf.find(i) != uf.find(0))
        return 1e9 + 7;
    return weight;
  }

public:
  vvd findCriticalAndPseudoCriticalEdges(int n, vvd & edges) {
    for (int i = 0; i < edges.size(); ++i)
      edges[i].push_back(i);
    sort(
        edges.begin(), edges.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });
    int origin_mst = get_mst(n, edges, -1);
    vector<int> critical, non_critical;
    for (int i = 0; i < edges.size(); ++i) {
      if (origin_mst < get_mst(n, edges, i))
        critical.push_back(edges[i][3]);
      else if (origin_mst == get_mst(n, edges, -1, i))
        non_critical.push_back(edges[i][3]);
    }
    return {critical, non_critical};
  }
};

int main() {
  Solution obj;
  vvd e1 = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2},
                 {0, 4, 3}, {3, 4, 3}, {1, 4, 6}},
           e2 = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1}};
  for (auto i : obj.findCriticalAndPseudoCriticalEdges(5, e1))
    for (auto j : i)
      printf("%d ", j);
  printf("\n");
  for (auto i : obj.findCriticalAndPseudoCriticalEdges(4, e2))
    for (auto j : i)
      printf("%d ", j);
  printf("\n");
}
