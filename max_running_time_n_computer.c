// 2141. Maximum Running Time of N Computers
#include "leetcode.h"

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

int cmp(const void *a, const void *b) { return (*(int *)a) - (*(int *)b); }

long long maxRunTime(int n, int *batteries, int batteriesSize) {
  long long total = 0;
  for (int i = 0; i < batteriesSize; i++)
    total += batteries[i];
  qsort(batteries, batteriesSize, sizeof(int), cmp);
  for (int i = batteriesSize - 1; i >= 0; i--) {
    if (batteries[i] > total / n) {
      total -= batteries[i];
      n--;
    } else
      break;
  }
  return total / n;
}

int main() {
  int b1[] = {3, 3, 3}, b2[] = {1, 1, 1, 1};
  printf("%lld\n", maxRunTime(2, b1, ARRAY_SIZE(b1))); // expect: 4
  printf("%lld\n", maxRunTime(2, b2, ARRAY_SIZE(b2))); // expect: 2
}
