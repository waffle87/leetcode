// 70. Climbing Stairs
#include "leetcode.h"

/*
 * you are climbinga staircase. it takes 'n' steps to reach the top. each time
 * you can either climb one or two steps. in how many distinct ways can you
 * climb to the top?
 */

double combination(int m, int n) {
  if (!n || m == n)
    return 1;
  double res = 1;
  for (int i = m; i > m - n; i--)
    res *= i;
  for (int i = n; i >= 1; i--)
    res /= i;
  return res;
}

int climbingStairs(int n) {
  int one_step, two_step, total_step;
  double method = 0;
  for (int i = 0; i <= floor((double)n / 2); i++) {
    two_step = i;
    one_step = n - 2 * i;
    total_step = one_step + two_step;
    method += combination(total_step, one_step);
  }
  return (int)method;
}

int main() {
  printf("%d\n", climbingStairs(2)); // expect: 2
  printf("%d\n", climbingStairs(3)); // expect: 3
}
