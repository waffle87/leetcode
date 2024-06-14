// 207. Course Schedule
#include "leetcode.h"

/*
 * there are a total of 'num_courses' courses you have to take labeled from 0 to
 * 'num_courses - 1'. you are given an array 'prerequisites' where
 * 'prerequisites[i] = [ai, bi]' indicates that you must take course 'bi' first
 * if you want to take course 'ai'. return true if you can finish all courses,
 * otherwise, return false
 */

class Solution {
  bool is_cycle(vector<int> adj[], vector<int> &vis, int id) {
    if (vis[id] == 1)
      return true;
    if (!vis[id]) {
      vis[id] = 1;
      for (auto edge : adj[id])
        if (is_cycle(adj, vis, edge))
          return true;
    }
    vis[id] = 2;
    return false;
  }

public:
  bool canFinish(int num_courses, vvd(int) & prerequisites) {
    vector<int> adj[num_courses];
    for (auto edge : prerequisites)
      adj[edge[1]].push_back(edge[0]);
    vector<int> vis(num_courses, 0);
    for (int i = 0; i < num_courses; i++)
      if (is_cycle(adj, vis, i))
        return false;
    return true;
  }
};

int main() {
  Solution obj;
  vvd(int) p1 = {{1, 0}}, p2 = {{1, 0}, {0, 1}};
  printf("%d\n", obj.canFinish(2, p1)); // expect: 1
  printf("%d\n", obj.canFinish(2, p2)); // expect: 0
}
