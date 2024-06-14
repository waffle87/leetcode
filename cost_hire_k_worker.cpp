// 2462. Total Cost to Hire K Workers
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'costs' where 'costs[i]' is the cost of
 * hiring the i'th worker. you are also given two integers 'k, candidates'. we
 * want to hire exactly 'k' workders according to the following rules:
 * - you will run 'k' sessions and hire exactly one worker in each session
 * - in each hiring session, choose the worker with the lowest cost from either
 * the first 'candidates' workers or the last 'candidates' workers. break the
 * tie by the smallest index.
 * - if there are fewer than candidates workers remaining, choose the workder
 * with the lowest cost among them. break the tie by the smallest index.
 * - a worker can only be chosen once
 * return the total cost to hire eactly 'k' workers.
 */

class Solution {
public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    int i = 0, j = costs.size() - 1;
    priority_queue<int, vector<int>, greater<int>> pq1, pq2;
    long long ans;
    while (k--) {
      while (pq1.size() < candidates && i <= j)
        pq1.push(costs[i++]);
      while (pq2.size() < candidates && i <= j)
        pq2.push(costs[j--]);
      int t1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
      int t2 = pq2.size() > 0 ? pq2.top() : INT_MAX;
      if (t1 <= t2) {
        ans += t1;
        pq1.pop();
      } else {
        ans += t2;
        pq2.pop();
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> c1 = {17, 12, 10, 2, 7, 2, 11, 20, 8}, c2 = {1, 2, 4, 1};
  printf("%lld\n", obj.totalCost(c1, 3, 4)); // expect: 11
  printf("%lld\n", obj.totalCost(c2, 3, 3)); // expect: 4
}
