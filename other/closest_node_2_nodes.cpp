#include "leetcode.h"

class Solution {
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    pair<int, int> p1 = dfs(edges, node1, node2);
    pair<int, int> p2 = dfs(edges, node2, node1);
    if (p1.second != -1 && p1.first < p2.first)
      return p1.second;
    else if (p2.second != -1 && p2.first < p1.first)
      return p2.second;
    else if (p1.first == p2.first) {
      if (p1.second < p2.second)
        return p1.second;
      else
        return p2.second;
    }
    return -1;
  }

private:
  pair<int, int> dfs(vector<int> &edges, int node1, int node2) {
    unordered_map<int, int> um;
    int n = edges.size();
    vector<int> vis1(n + 2, 0), vis2(n + 2, 0);
    um[node1] = 1;
    int len = 0;
    while (edges[node1] != -1 && vis1[node1] != 1) {
      vis1[node1] = 1;
      node1 = edges[node1];
      um[node1] = len++;
    }
    pair<int, int> pp = make_pair(INT_MAX, -1);
    if (um.find(node2) != um.end()) {
      pp = make_pair(um[node2], node2);
      return pp;
    }
    while (edges[node2] != -1 && vis2[node2] != 1) {
      vis2[node2] = 1;
      node2 = edges[node2];
      if (um.find(node2) != um.end()) {
        pp = make_pair(um[node2], node2);
        return pp;
      }
    }
    return pp;
  }
};

int main() {
  Solution obj;
  vector<int> edges1 = {2, 2, 3, -1}, edges2 = {1, 2, -1};
  cout << obj.closestMeetingNode(edges1, 0, 2) << endl; // expect: 2
  cout << obj.closestMeetingNode(edges2, 0, 2) << endl; // expect: 2
}
