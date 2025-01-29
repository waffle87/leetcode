// 2742. Painting the Walls
#include "leetcode.h"

/*
 * you are given two 0-indexed integer arrays, cost and time of size n
 * representing the costs and the time taken to paint n walls respectively.
 * there are two painters available:
 * - a paid painter that paints the i'th wall in 'time[i]' units of time and
 * takes 'cost[i]' units of money
 * - a free painter that paints any wall in 1 unit of time at a cost of 0. but
 * the free painter can only be used if the paid painter is already occupied
 * return the minimum amount of money required to paint the 'n' walls.
 */

class Solution {
public:
  int paintWalls(vector<int> &cost, vector<int> &time) {
    this->n = cost.size();
    vvd memo(n, vector<int>(n + 1));
    this->cost = cost;
    this->time = time;
    return dfs(0, n, memo);
  }

private:
  int memo[501][501];
  vector<int> cost;
  vector<int> time;
  int n;
  int dfs(int curr, int left_wall, vvd & memo) {
    if (left_wall <= 0)
      return 0;
    if (curr == n)
      return 1e9;
    if (memo[curr][left_wall] != -1)
      return memo[curr][left_wall];
    int paid = cost[curr] + dfs(curr + 1, left_wall - 1 - time[curr], memo);
    int free = dfs(curr + 1, left_wall, memo);
    memo[curr][left_wall] = min(paid, free);
    return memo[curr][left_wall];
  }
};

int main() {
  Solution obj;
  vector<int> c1 = {1, 2, 3, 2}, c2 = {2, 3, 4, 2};
  vector<int> t1 = {1, 2, 3, 2}, t2 = {1, 1, 1, 1};
  printf("%d\n", obj.paintWalls(c1, t1)); // expect: 3
  printf("%d\n", obj.paintWalls(c2, t2)); // expect: 4
}
