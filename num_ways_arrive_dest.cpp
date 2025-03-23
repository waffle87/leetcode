// 1976. Number of Ways to Arrive at Destination
#include "leetcode.h"

/*
 * you are in a city that consists of 'n' intersections numbered from 0 to 'n -
 * 1' with bi directional roads between some intersections. the inputs are
 * generated such that you can reach any intersection from any other
 * intersection and that there is at most one road between any two
 * intersections. you are given an integer 'n' and a 2d integer array 'roads'
 * where 'roads[i] = [u_i, v_i, t_i]' means that there is a road between
 * intersections 'u' and 'v' that takes 't' minutes to travel. you want to know
 * in how many ways you can travel from interseciton 0 to intersection 'n - 1'.
 */

class Solution {
public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<pair<long long, long long>>> graph(n);
    for (auto &r : roads) {
      long long u = r[0], v = r[1], t = r[2];
      graph[u].push_back({v, t});
      graph[v].push_back({u, t});
    }
    return dijkstra(graph, n, 0);
  }

private:
  int mod = 1e9 + 7;
  int dijkstra(const vector<vector<pair<long long, long long>>> &graph, int n,
               int src) {
    vector<long long> dist(n, LONG_MAX), ways(n);
    ways[src] = 1;
    dist[src] = 0;
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>, greater<>>
        pq;
    pq.push({0, 0});
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dist[u])
        continue;
      for (auto [v, t] : graph[u]) {
        if (dist[v] > d + t) {
          dist[v] = d + t;
          ways[v] = ways[u];
        } else if (dist[v] == d + t)
          ways[v] = (ways[v] + ways[u]) % mod;
      }
    }
    return ways[n - 1];
  }
};

int main() {
  Solution obj;
  vvd r1 = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3},
            {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
  vvd r2 = {{1, 0, 10}};
  printf("%d\n", obj.countPaths(7, r1)); // expect: 4
  printf("%d\n", obj.countPaths(2, r2)); // expect: 1
}
