#include "leetcode.h"

class UnionFind {
private:
  vector<int> id, rank;
  int cnt;

public:
  UnionFind(int cnt) : cnt(cnt) {
    id = vector<int>(cnt);
    rank = vector<int>(cnt, 0);
    for (int i = 0; i < cnt; ++i)
      id[i] = i;
  }
  int find(int p) {
    if (id[p] == p)
      return p;
    return id[p] = find(id[p]);
  }
  bool connected(int p, int q) { return find(p) == find(q); }
  void connect(int p, int q) {
    int i = find(p), j = find(q);
    if (i == j)
      return;
    if (rank[i] < rank[j])
      id[i] = j;
    else {
      id[j] = i;
      if (rank[i] == rank[j])
        rank[j]++;
    }
    --cnt;
  }
};

class Solution {
public:
  int numberOfGoodPaths(vector<int> &vals, vvd(int) & edges) {
    int n = vals.size(), goodPaths = 0;
    vvd(int) adj(n);
    map<int, vector<int>> sameVal;
    for (int i = 0; i < n; i++)
      sameVal[vals[i]].push_back(i);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      if (vals[u] >= vals[v])
        adj[u].push_back(v);
      else if (vals[v] >= vals[u])
        adj[v].push_back(u);
    }
    UnionFind uf(n);
    for (auto &[value, allNodes] : sameVal) {
      for (int u : allNodes)
        for (int v : adj[u])
          uf.connect(u, v);
      unordered_map<int, int> group;
      for (int u : allNodes)
        group[uf.find(u)]++;
      goodPaths += allNodes.size();
      for (auto &[_, size] : group)
        goodPaths += (size * (size - 1) / 2);
    }
    return goodPaths;
  }
};

int main() {
  Solution obj;
  vector<int> vals1 = {1, 3, 2, 1, 3}, vals2 = {1, 1, 2, 2, 3}, vals3 = {1};
  vvd(int) edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}},
           edges2 = {{0, 1}, {1, 2}, {2, 3}, {2, 4}}, edges3 = {};
  cout << obj.numberOfGoodPaths(vals1, edges1) << endl; // expect: 6
  cout << obj.numberOfGoodPaths(vals2, edges2) << endl; // expect: 7
  cout << obj.numberOfGoodPaths(vals3, edges3) << endl; // expect: 1
}
