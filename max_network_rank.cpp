// 1615. Maximal Network Rank
#include "leetcode.h"

/*
 * there is an infrastructure of 'n' cities with some number of 'roads'
 * connecting these cities. each 'roads[i] = [ai, bi]'. indicates that there is
 * a bidirectional road between cities 'ai' and 'bi'. the network rank of two
 * different cities is defined as the total number of directly conncected roads
 * to either city. if a road is directly connected to both cities, it is only
 * counted once. the maximal network rank of the infrastructure is the maximum
 * network rank of all pairs of different cities. given the integer 'n' and the
 * array 'roads', return the maximal network rank of the entire infrastructure.
 */

class Solution {
public:
  int maximalNetworkRank(int n, vvd(int) & roads) {
    vector<unordered_set<int>> graph(n);
    for (auto r : roads) {
      graph[r[0]].insert(r[1]);
      graph[r[1]].insert(r[0]);
    }
    int maximal = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int network_rank = graph[i].size();
        if (graph[j].count(i))
          --network_rank;
        maximal = max(maximal, network_rank);
      }
    }
    return maximal;
  }
};

int main() {
  Solution obj;
  vvd(int) r1 = {{0, 1}, {0, 3}, {1, 2}, {1, 3}},
           r2 = {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}},
           r3 = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}};
  printf("%d\n", obj.maximalNetworkRank(4, r1)); // expect: 4
  printf("%d\n", obj.maximalNetworkRank(5, r2)); // expect: 5
  printf("%d\n", obj.maximalNetworkRank(8, r3)); // expect: 5
}
