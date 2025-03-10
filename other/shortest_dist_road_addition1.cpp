// 3243. Shortest Distance After Road Addition Queries I
#include "leetcode.h"

/*
 * you are given an integer 'n' and a 2d integer array 'queries'. there are 'n'
 * cities numbered from 0 to 'n - 1'. initially there is a unidirectional road
 * from city 'i' to city 'i + 1' for all '0 <= i < n - 1'. 'queries[i] = [u_i,
 * v_i]' represents the addition of a new unidirectional road from city 'u_i' to
 * city 'v_i'. after each query, you need to find the length of the shortest
 * path from city 0 to city 'n - 1'. return an array 'answer' where for each 'i'
 * in the range of '[0, queries.length - 1]', 'answer[i]' is the length of the
 * shortest path from city 0 to city 'n - 1' after processing the first 'i + 1'
 * queries.
 */

class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>> &queries) {
    vector<int> ans;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n - 1; i++)
      mp[i].push_back(i + 1);
    for (auto i : queries) {
      mp[i[0]].push_back(i[1]);
      vector<int> dp(n, INT_MAX);
      dp[n - 1] = 0;
      for (int j = n - 2; j >= 0; --j)
        for (int next : mp[j])
          dp[j] = min(dp[j], dp[next] + 1);
      ans.push_back(dp[0]);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd q1 = {{2, 4}, {0, 2}, {0, 4}}, q2 = {{0, 3}, {0, 3}};
  vector<int> sdaq1 = obj.shortestDistanceAfterQueries(5, q1);
  vector<int> sdaq2 = obj.shortestDistanceAfterQueries(4, q2);
  for (auto i : sdaq1)
    printf("%d ", i); // expect: 3 2 1
  printf("\n");
  for (auto i : sdaq2)
    printf("%d ", i); // expect: 1 1
  printf("\n");
}
