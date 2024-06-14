// 746. Min Cost Climbing Stairs
#include "leetcode.h"

/*
 * you are given an integer array 'cost' where 'cost[i]' is the cost of the i'th
 * step on a staircase. once you pay the cost, you can either climb one or two
 * steps. you can either start from the step with index 0 or the step with
 * index 1. return the minimum cost to reach the top of the floor.
 */

int minCostClimbingStairs(int *cost, int cost_size) {
  int ans;
  int *stairs = (int *)malloc(sizeof(int) * cost_size);
  stairs[0] = cost[0];
  stairs[1] = cost[1];
  for (int i = 0; i < cost_size; i++)
    stairs[i] = (stairs[i - 1] <= stairs[i - 2]) ? (stairs[i - 1] + cost[i])
                                                 : (stairs[i - 2] + cost[i]);
  ans = fmin(stairs[cost_size - 1], stairs[cost_size - 2]);
  free(stairs);
  return ans;
}

int main() {
  int c1[] = {10, 15, 20}, c2[] = {0, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  printf("%d\n", minCostClimbingStairs(c1, 3));  // expect: 15
  printf("%d\n", minCostClimbingStairs(c2, 10)); // expect: 5
}
