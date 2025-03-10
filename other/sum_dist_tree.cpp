#include "leetcode.h"

class Solution {
public:
  vector<int> sumOfDistancesInTree(int n, vvd & edges) {
    tree.resize(n);
    ans.assign(n, 0);
    count.assign(n, 1);
    for (auto e : edges) {
      tree[e[0]].insert(e[1]);
      tree[e[1]].insert(e[0]);
    }
    dfs(0, -1);
    dfs2(0, -1);
    return ans;
  }

private:
  vector<unordered_set<int>> tree;
  vector<int> ans, count;
  void dfs(int root, int pre) {
    for (auto i : tree[root]) {
      if (i == pre)
        continue;
      dfs(i, root);
      count[root] += count[i];
      ans[root] += ans[i] + count[i];
    }
  }
  void dfs2(int root, int pre) {
    for (auto i : tree[root]) {
      if (i == pre)
        continue;
      ans[i] = ans[root] - count[i] + count.size() - count[i];
      dfs2(i, root);
    }
  }
};

int main() {
  Solution obj;
  vvd edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
  for (auto i : obj.sumOfDistancesInTree(6, edges))
    cout << i << ' '; // expect: 8 12 6 10 10 10
}
