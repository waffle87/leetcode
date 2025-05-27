// 2894. Divisible and Non-divisible Sums Difference
#include "leetcode.h"

/*
 * you are given a positive integers 'n' and 'm'. define two integers as
 * follows: 'num1': the sum of all integers in the range '[1, n]' that are not
 * divisible by 'm'. 'num2': the sum of all integers in the range '[1, n]' that
 * are divisible by 'm'. return the integer 'num1 - num2'
 */

int differenceOfSums(int n, int m) {
  return (1 + n) * n / 2 - (1 + n / m) * (n / m) * m;
}

int main() {
  printf("%d\n", differenceOfSums(10, 3)); // expect: 19
  printf("%d\n", differenceOfSums(5, 6));  // expect: 15
  printf("%d\n", differenceOfSums(5, 1));  // expect: -15
}
