// 2097. Valid Arrangement of Pairs
#include "leetcode.h"

/*
 * you are given a 0-indexed 2d integer array 'pairs' where 'pairs[i] =
 * [start_i, end_i]'. an arrangement of 'pairs' is valid for every index 'i'
 * where '1 <= i < pairs.length', we have 'end_i-1 == start_i'. return any valid
 * arrangement of 'pairs'. note, the inputs will be generated such that there
 * exists a valid arrangement of 'pairs'.
 */

class Solution {
private:
  void euler(unordered_map<int, stack<int>> &adj, vector<vector<int>> &res,
             int curr) {
    auto &st = adj[curr];
    while (!st.empty()) {
      int n = st.top();
      st.pop();
      euler(adj, res, n);
      res.push_back({curr, n});
    }
  }

public:
  vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
    int m = pairs.size();
    unordered_map<int, stack<int>> adj;
    unordered_map<int, int> in, out;
    adj.reserve(m);
    in.reserve(m);
    out.reserve(m);
    for (int i = 0; i < m; i++) {
      int u = pairs[i][0], v = pairs[i][1];
      in[v]++;
      out[u]++;
      adj[u].push(v);
    }
    int start = -1;
    for (auto &p : adj) {
      int i = p.first;
      if (out[i] - in[i] == 1)
        start = i;
    }
    if (start == -1)
      start = adj.begin()->first;
    vector<vector<int>> ans;
    euler(adj, ans, start);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) p1 = {{5, 1}, {4, 5}, {11, 9}, {9, 4}},
           p2 = {{1, 3}, {3, 2}, {2, 1}}, p3 = {{1, 2}, {1, 3}, {2, 1}};
  vvd(int) va1 = obj.validArrangement(p1);
  vvd(int) va2 = obj.validArrangement(p2);
  vvd(int) va3 = obj.validArrangement(p3);
  for (int i = 0; i < va1.size(); i++)
    for (int j = 0; j < va1[0].size(); j++)
      printf("%d ", va1[i][j]); // expect: [[11,9],[9,4],[4,5],[5,1]]
  printf("\n");
  for (int i = 0; i < va2.size(); i++)
    for (int j = 0; j < va2[0].size(); j++)
      printf("%d ", va2[i][j]); // expect: [[1,3],[3,2],[2,1]]
  printf("\n");
  for (int i = 0; i < va3.size(); i++)
    for (int j = 0; j < va3[0].size(); j++)
      printf("%d ", va1[i][j]); // expect: [[1,2],[2,1],[1,3]]
  printf("\n");
}
