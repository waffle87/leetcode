// 633. Sum of Square Numbers
#include "leetcode.h"

/*
 * given a non-negative integer 'c', decide whether there are two integers 'a'
 * and 'b' such that 'a^2 + b^2 = c'
 */

bool judgeSquareSum(int c) {
  int bound = sqrt(c);
  for (int i = 0; i <= bound; i++) {
    int a = i * i, b = sqrt(c - a);
    if (b * b == c - a)
      return true;
  }
  return false;
}

int main() {
  printf("%d\n", judgeSquareSum(5)); // expect: 1
  printf("%d\n", judgeSquareSum(3)); // expect: 0
}
