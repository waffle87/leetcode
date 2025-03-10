#include "leetcode.h"

class Solution {
public:
  bool validPath(int n, vvd & edges, int source, int destination) {
    vector<int> ds(n, -1);
    for (auto &e : edges) {
      int p1 = find(ds, e[0]), p2 = find(ds, e[1]);
      if (p1 != p2)
        ds[p2] = p1;
    }
    return find(ds, source) == find(ds, destination);
  }

private:
  int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
  }
};

int main() {
  Solution obj;
  vvd edges = {{0, 1}, {1, 2}, {2, 0}};
  if (obj.validPath(3, edges, 0, 2))
    cout << "true";
  else
    cout << "false";
}
