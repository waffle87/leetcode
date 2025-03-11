// 371. Sum of Two Integers
#include "leetcode.h"

/*
 * given two integers 'a' and 'b', return the sum of the two integers without
 * using the operators '+' and '-'.
 */

int getSum(int a, int b) {
  int trigger = a & b, ans = a ^ b;
  while (trigger) {
    int carry = (trigger & 0xFFFFFFFF) << 1;
    trigger = carry & ans;
    ans ^= carry;
  }
  return ans;
}

int main() {
  printf("%d\n", getSum(1, 2)); // expect: 3
  printf("%d\n", getSum(2, 3)); // expect: 5
}
