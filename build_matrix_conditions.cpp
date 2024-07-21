// 2392. Build a Matrix With Conditions
#include "leetcode.h"

/*
 * you are givne a positive integer 'k'. you are also given a 2d integer array
 * 'rowConditions' of size 'n' where 'rowConditions[i] = [above_i, below_i]' and
 * a 2d integer array 'colConditions' of size 'm' where 'colConditions[i] =
 * [left_i, right_i]'. the two arrays contain integers from 1 to 'k'. you have
 * to build a 'k * k' matrix that contains each of the numbers from 1 to 'k'
 * exactly once. the remaining cells should satisfy the following conditions.
 * the number 'above_i' should appear in a row that is strictly above the row at
 * which the number 'below_i' appears for all 'i'. the number 'left_i' should
 * appear in a column that is strictly left of the column at which the number
 * 'right_i' appears for all 'i'. return any matrix that satisfies these
 * conditions.
 */

class Solution {
private:
  vector<char> colour;
  vector<bool> visited;
  bool dfs(int v, vector<vector<int>> &graph) {
    colour[v] = 1;
    for (int i : graph[v]) {
      if (!colour[i]) {
        if (dfs(i, graph))
          return true;
      } else if (colour[i] == 1)
        return true;
    }
    colour[v] = 2;
    return false;
  }
  bool find_cycle(vector<vector<int>> &graph, int n) {
    colour.assign(n, 0);
    for (int i = 0; i < n; i++)
      if (!colour[i] && dfs(i, graph))
        return true;
    return false;
  }
  void dfs2(int v, vector<vector<int>> &graph, vector<int> &res) {
    visited[v] = true;
    for (int i : graph[v])
      if (!visited[i])
        dfs2(i, graph, res);
    res.push_back(v);
  }
  void topo_sort(vector<vector<int>> &graph, int n, vector<int> &res) {
    visited.assign(n, false);
    res.clear();
    for (int i = 0; i < n; ++i)
      if (!visited[i])
        dfs2(i, graph, res);
    reverse(res.begin(), res.end());
  }

public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                  vector<vector<int>> &colConditions) {
    vector<vector<int>> g1(k), g2(k);
    for (auto i : rowConditions)
      g1[i[0] - 1].push_back(i[1] - 1);
    for (auto i : colConditions)
      g2[i[0] - 1].push_back(i[1] - 1);
    if (find_cycle(g1, k) || find_cycle(g2, k))
      return vector<vector<int>>();
    vector<int> a1, a2;
    topo_sort(g1, k, a1);
    topo_sort(g1, k, a2);
    vector<vector<int>> ans(k, vector<int>(k));
    map<int, int> m;
    for (int i = 0; i < k; i++)
      m[a2[i]] = i;
    for (int i = 0; i < k; i++)
      ans[i][m[a1[i]]] = a1[i] + 1;
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) rc1 = {{1, 2}, {3, 2}}, cc1 = {{2, 1}, {3, 2}};
  vvd(int) rc2 = {{1, 2}, {2, 3}, {3, 1}, {2, 3}}, cc2 = {{2, 1}};
  vvd(int) bm1 = obj.buildMatrix(3, rc1, cc1),
           bm2 = obj.buildMatrix(3, rc2, cc2);
  for (int i = 0; i < bm1.size(); i++) {
    for (int j = 0; j < bm1[0].size(); j++)
      printf("%d ", bm1[i][j]);
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < bm2.size(); i++) {
    for (int j = 0; j < bm2[0].size(); j++)
      printf("%d ", bm2[i][j]);
    printf("\n");
  }
  printf("\n");
}
