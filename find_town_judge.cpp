// 997. Find the Town Judge
#include "leetcode.h"

/*
 * in a town, there are 'n' people labeled from 1 to 'n'. there is a rumor that
 * one of these people is secretly the town judge. if the town judge exists,
 * then: the town judge trusts nobody. everybody (except the judge) trusts the
 * judge. given: array 'trust' where 'trust[i]' = [ai, bi] representing the the
 * person labeled ai trusts the person labeled bi. return label of judge, if
 * they exist.
 */

class Solution {
public:
  int findJudge(int n, vvd trust) {
    vector<unordered_set<int>> graph(n + 1, unordered_set<int>());
    for (auto &edge : trust) {
      int a = edge[0], b = edge[1];
      graph[a].insert(b); // a trusts b
    }
    int townJudge = -1;
    for (int i = 1; i <= n; ++i)
      if (graph[i].size() == 0) {
        townJudge = i;
        break;
      }
    if (townJudge == -1)
      return -1;
    for (int i = 1; i <= n; ++i) {
      if (i == townJudge)
        continue;
      if (!graph[i].count(townJudge))
        return -1;
    }
    return townJudge;
  }
};

int main() {
  Solution obj;
  vvd trust1 = {{1, 2}}, trust2 = {{1, 3}, {2, 3}},
           trust3 = {{1, 3}, {2, 3}, {3, 1}};
  cout << obj.findJudge(2, trust1) << endl; // expect: 2
  cout << obj.findJudge(3, trust2) << endl; // expect: 3
  cout << obj.findJudge(3, trust3) << endl; // expect: -1
}
