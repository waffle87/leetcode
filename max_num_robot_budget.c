// 2398. Maximum Number of Robots Within Budget
#include "leetcode.h"

/*
 * you have 'n' robots. you are given two 0 indexed integer arrays 'chargeTimes'
 * and 'runningCosts', both of length 'n'. the i'th robot costs 'chargeTimes[i]'
 * units to charge and costs 'runningCosts[i]' units to run. you are also given
 * an integer 'budget'. the total cost of running 'k' chosen robots is equal to
 * 'max(chargeTimes) + k * sum(runningCosts)' where 'max(chargeTimes)' is the
 * largest charge cost among the 'k' robots and 'sum(runningCosts)' is the sum
 * of running costs among the 'k' robots. return the maximum number of
 * consecutive robots you can run such that the total costs does not exceed
 * 'budget'.
 */

int maximumRobots(int *chargeTimes, int chargeTimesSize, int *runningCosts,
                  int runningCostsSize, long long budget) {
  int lut[50001], idx_head = 0, idx_tail = 0, ans = 0, curr_len = 0;
  long long curr_cost = 0;
  for (int i = 0; i < chargeTimesSize; i++) {
    long long curr_sum;
    curr_cost += runningCosts[i];
    while (idx_head < idx_tail && lut[idx_head] < i - curr_len)
      idx_head++;
    while (idx_head < idx_tail &&
           chargeTimes[lut[idx_tail - 1]] < chargeTimes[i])
      idx_tail--;
    lut[idx_tail++] = i;
    curr_sum = chargeTimes[lut[idx_head]];
    curr_sum += (long long)(++curr_len * curr_cost);
    while (curr_len > 0 && curr_sum > budget) {
      curr_cost -= runningCosts[i - (--curr_len)];
      while (idx_head < idx_tail && lut[idx_head] < i - curr_len)
        idx_head++;
      curr_sum = chargeTimes[lut[idx_head]];
      curr_sum += (long long)(curr_len * curr_cost);
    }
    if (ans < curr_len)
      ans = curr_len;
  }
  return ans;
}

int main() {
  int ct1[] = {3, 6, 1, 3, 4}, ct2[] = {11, 12, 19}, rc1[] = {2, 1, 3, 4, 5},
      rc2[] = {10, 8, 7};
  printf("%d\n", maximumRobots(ct1, ARRAY_SIZE(ct1), rc1, ARRAY_SIZE(rc1),
                               25)); // expect: 3
  printf("%d\n", maximumRobots(ct2, ARRAY_SIZE(ct2), rc2, ARRAY_SIZE(rc2),
                               19)); // expect: 0
}
