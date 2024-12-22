// 2940. Find Building Where Alice and Bob Can Meet
#include "leetcode.h"

/*
 * you are given a 0-indexed array 'heights' of positive integers where
 * 'heights[i]' represents the height of the i'th building. if a person is in
 * building 'i', they can move to any other building 'j' if and only if 'i < j'
 * and 'heights[i] < heights[j]'. you are also given an array 'queries' where
 * 'queries[i] = [a_i, b_i]'. on the i'th query, alice is in building 'a_i', and
 * bob is in building 'b_i'. return array 'ans' where 'ans[i]' is the index of
 * the leftmost building where alice and bob can meet on i'th query. if alice
 * and bob cannot move to a common building on query 'i', set 'ans[i]' to -1
 */

class Solution {
public:
  vector<int> leftmostBuildingQueries(vector<int> &heights,
                                      vector<vector<int>> &queries) {
    int hn = heights.size(), qn = queries.size();
    vector<vector<vector<int>>> q(hn);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> ans(qn, -1);
    for (int qi = 0; qi < qn; qi++) {
      int i = queries[qi][0], j = queries[qi][1];
      if (i < j && heights[i] < heights[j])
        ans[qi] = j;
      else if (i > j && heights[i] > heights[j])
        ans[qi] = i;
      else if (i == j)
        ans[qi] = i;
      else
        q[max(i, j)].push_back({max(heights[i], heights[j]), qi});
    }
    for (int i = 0; i < hn; i++) {
      while (!pq.empty() && pq.top()[0] < heights[i]) {
        ans[pq.top()[1]] = i;
        pq.pop();
      }
      for (auto &j : q[i])
        pq.push(j);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> h1 = {6, 4, 8, 5, 2, 7}, h2 = {5, 3, 8, 2, 6, 1, 4, 6};
  vvd(int) q1 = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}},
           q2 = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};
  vector<int> lmbq1 = obj.leftmostBuildingQueries(h1, q1);
  vector<int> lmbq2 = obj.leftmostBuildingQueries(h2, q2);
  for (auto i : lmbq1)
    printf("%d ", i); // expect: 2 5 -1 5 2
  printf("\n");
  for (auto i : lmbq2)
    printf("%d ", i); // expect: 7 6 -1 4 6
  printf("\n");
}
