#include "leetcode.h"

class Solution {
public:
  vvd allPathsSourceTarget(vvd & graph) {
    vvd ans;
    vector<int> path;
    dfs(graph, ans, path, 0);
    return ans;
  }

private:
  void dfs(vvd & graph, vvd & ans, vector<int> &path, int curr) {
    path.push_back(curr);
    if (curr == graph.size() - 1)
      ans.push_back(path);
    else
      for (auto it : graph[curr])
        dfs(graph, ans, path, it);
    path.pop_back();
  }
};

int main() {
  Solution obj;
  vvd graph = {{1, 2}, {3}, {3}, {}};
  for (auto i : obj.allPathsSourceTarget(graph))
    for (auto j : i)
      cout << j << ' ';
}
