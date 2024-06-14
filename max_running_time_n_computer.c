// 2141. Maximum Running Time of N Computers
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * you have 'n' computers. you are given the integer 'n' and a 0-indexed integer
 * array 'batteries' where the i'th battery can run a computer for
 * 'batteries[i]' minutes. you are interested in running all 'n' computers
 * simultaneously using the given batteries. initially, you can insert at most
 * one battery into each computer. after that and at any integer time moment,
 * you can remove a battery from a computer and insert another battery any
 * number of times. the inserted battery can be a totally new battery or a
 * battery forom another computer. you may assume that the removing and
 * inserting process takes no time. note that the batteries canot be recharged.
 * return the maximum number of minutes you can run all the 'n' computers
 * simultaneously.
 */

bool check(int n, int *batteries, int batteries_size, long long time) {
  long long total = time * n, sum = 0;
  for (int i = 0; i < batteries_size; i++) {
    sum += fmin(time, batteries[i]);
    if (sum >= total)
      return true;
  }
  return false;
}

long long maxRunTime(int n, int *batteries, int batteries_size) {
  long long left = 0, right = 1e14;
  while (left < right) {
    long long mid = right - (right - left) / 2;
    if (check(n, batteries, batteries_size, mid))
      left = mid;
    else
      right = mid - 1;
  }
  return left;
}

int main() {
  int b1[] = {3, 3, 3}, b2[] = {1, 1, 1, 1};
  printf("%lld\n", maxRunTime(2, b1, 3)); // expect: 4
  printf("%lld\n", maxRunTime(2, b2, 4)); // expect: 2
}
