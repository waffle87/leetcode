// 1404. Number of Steps to Reduce a Number in Binary Representation to One
#include "leetcode.h"

/*
 * given the binary representation of an integer as a string 's', return the
 * number of steps to reduce it to 1 under the following rules. if the current
 * number is even, you have to divide it by 2. if the current number is odd, you
 * have to add 1 to it. it is guaranteed that you can always reach one for all
 * test cases.
 */

int numSteps(char *s) {
  int n = strlen(s), ops = 0, carry = 0;
  for (int i = n - 1; i > 0; i--) {
    if (((s[i] - '0') + carry) % 2) {
      ops += 2;
      carry = 1;
    } else
      ops++;
  }
  return ops + carry;
}

int main() {
  char *s1 = "1101", *s2 = "10", *s3 = "1";
  int r1 = numSteps(s1);
  int r2 = numSteps(s2);
  int r3 = numSteps(s3);
  printf("%d\n", r1); // expect: 6
  assert(r1 == 6);
  printf("%d\n", r2); // expect: 1
  assert(r2 == 1);
  printf("%d\n", r3); // expect: 0
  assert(r3 == 0);
}
