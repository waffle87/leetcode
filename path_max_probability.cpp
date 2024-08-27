// 1514. Path with Maximum Probability
#include "leetcode.h"

/*
 * given an undirected weighted graph of 'n' nodes (0-indexed). represented by
 * an edge list where 'edges[i] = [a, b]' is an undirected edge connecting the
 * nodes 'a' and 'b' with a probability of success of traversing that edge
 * 'succ_prob[i]'. given two nodes 'start, end', find the path with the maximum
 * probability of success to go from 'start' to 'end' and return its success
 * probability. if there is no path from 'start' to 'end', return 0. your answer
 * will be accepted if it differs from the correct answer by at most '1e-5'
 */

class Solution {
public:
  double maxProbability(int n, vvd(int) & edges, vector<double> &succ_prob,
                        int start, int end) {
    vector<vector<pair<int, double>>> vvp(n);
    for (int i = 0; i < edges.size(); i++) {
      vvp[edges[i][0]].push_back({edges[i][1], succ_prob[i]});
      vvp[edges[i][1]].push_back({edges[i][0], succ_prob[i]});
    }
    vector<int> seen(n, 0);
    priority_queue<pair<double, int>> pqp;
    pqp.push({(double)1.0, start});
    vector<double> mx(n, (double)0.0);
    mx[start] = 1.0;
    while (!pqp.empty()) {
      auto top = pqp.top();
      pqp.pop();
      double prob_a = top.first;
      int node = top.second;
      if (!seen[node]) {
        seen[node]++;
        for (auto to : vvp[node])
          if (mx[to.first] < to.second * prob_a) {
            mx[to.first] = to.second * prob_a;
            pqp.push({mx[to.first], to.first});
          }
      }
    }
    return mx[end];
  }
};

int main() {
  Solution obj;
  vvd(int) e1 = {{0, 1}, {1, 2}, {0, 2}}, e2 = {{0, 1}, {1, 2}, {0, 2}};
  vector<double> sp1 = {0.5, 0.5, 0.2}, sp2 = {0.5, 0.5, 0.3};
  printf("%f\n", obj.maxProbability(3, e1, sp1, 0, 2)); // expect: 0.25000
  printf("%f\n", obj.maxProbability(3, e2, sp2, 0, 2)); // expect: 0.30000
}
