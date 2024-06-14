// 1137. N-th Tribonacci Number
#include "leetcode.h"

/*
 * the tribonacci sequence t^n is defined as follows
 * t0 = 0, t1 = 1, t2 = 1, & tn+3 = tn + tn+1 + tn+2 for n >= 0
 * given n, return value of tn
 * eg.
 * n = 4, output: 4
 * t3 = 0 + 1 + 1 = 2
 * t4 = 1 + 1 + 2 = 4
 */

int tribonacci(int n) {
  if (n == 0)
    return 0;
  if (n == 1 || n == 2)
    return 1;
  int *tmp = malloc(sizeof(int) * (n + 1));
  tmp[0] = 0;
  tmp[1] = 1;
  tmp[2] = 1;
  for (int i = 3; i <= n; i++)
    tmp[i] = tmp[i - 1] + tmp[i - 2] + tmp[i - 3];
  return tmp[n];
}

int main() {
  printf("%d\n", tribonacci(4));  // expect: 4
  printf("%d\n", tribonacci(25)); // expect: 1389537
}
