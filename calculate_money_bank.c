// 1716. Calculate Money in Leetcode Bank
#include "leetcode.h"

/*
 * hercy wants to save money for his first car. he puts money in the leetcode
 * bank every day. he starts by putting in $1 on monday, the first day. every
 * day from tuesday to sunday he will put in 1 more dollar than the day before.
 * on every subsequent monday, he will put in 1 more than the previous monday.
 * given 'n', return the total amount of money he will have in the leetcode bank
 * at the end of the n'th day.
 */

int prog(int next, int prev, int terms) { return (next + prev) * terms / 2; }

int totalMoney(int n) {
  int q = n / 7, r = n % 7;
  return prog(28, 28 + (q - 1) * 7, q) + prog(q + 1, q + r, r);
}

int main() {
  printf("%d\n", totalMoney(4));  // expect: 10
  printf("%d\n", totalMoney(10)); // expect: 37
  printf("%d\n", totalMoney(20)); // expect: 96
}
