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

int totalMoney(int n) {
  int begin = 1, end = 7;
  int sum = 28, total = 0;
  while (n - 7) {
    total += sum;
    sum -= begin++;
    sum += ++end;
    n -= 7;
  }
  for (int i = 0; i < n; ++i) {
    total += begin;
    ++begin;
  }
  return total;
}

int main() {
  printf("%d\n", totalMoney(4));  // expect: 10
  printf("%d\n", totalMoney(10)); // expect: 37
  printf("%d\n", totalMoney(20)); // expect: 96
}
