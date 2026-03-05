// 1758. Minimum Changes To Make Alternating Binary String
#include "leetcode.h"
#include <math.h>
#include <string.h>

/*
 * given a string 's' consisting only of the characters '0' and '1', in one
 * operation, you can change any '0' to '1' or vice versa. the string is called
 * alternating if no two adjacent characters are equal. for example the string
 * "010" is alternating, while the string "0100" is not. return the minimum
 * number of operations needed to make 's' alternating.
 */

int minOperations(char *s) {
  int cnt = 0, n = strlen(s);
  for (int i = 0; i < n; i++)
    cnt += (s[i] ^ i) & 1;
  return fmin(cnt, n - cnt);
}

int main() {
  char *s1 = "0100", *s2 = "10", *s3 = "1111";
  int r1 = minOperations(s1);
  int r2 = minOperations(s1);
  int r3 = minOperations(s1);
  printf("%d\n", r1); // expect: 1
  assert(r1 == 1);
  printf("%d\n", r2); // expect: 0
  assert(r2 == 1);
  printf("%d\n", r3); // expect: 2
  assert(r3 == 1);
}
