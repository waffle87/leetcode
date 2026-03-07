// 1888. Minimum Number of Flips to Make the Binary String Alternating
#include "leetcode.h"

/*
 * you are given a binary string 's'. you are allowed to perform two types of
 * operations on the string in any sequence: 1: remove the character at the
 * start of the string 's' and append it to the end of the string. 2: pick any
 * characters in 's' and flip its value, ie. if its value is 0 it becomes 1 and
 * vice versa. return the minimum number of type-2 operations needed to perform
 * such that 's' becomes alternating. the string is called alternating if no two
 * adjacent characters are equal. for example, the strings "010" and "1010" are
 * alternating, while the string "0110" is not.
 */

int minFlips(char *s) {
  int n = 0, k = 0;
  for (char c = *s; c; c = s[++n])
    k += (n ^ c) & 1;
  int m = fmin(k, n - k);
  if (n & 1) {
    int i = 0;
    for (char c = *s; c; c = s[++i]) {
      k += ((i ^ c ^ 1) & 1) - ((i ^ c) & 1);
      m = fmin(m, fmin(k, n - k));
    }
  }
  return m;
}

int main() {
  char *s1 = "111000", *s2 = "010", *s3 = "1110";
  int r1 = minFlips(s1);
  int r2 = minFlips(s2);
  int r3 = minFlips(s3);
  printf("%d\n", r1); // expect: 2
  assert(r1 == 2);
  printf("%d\n", r2); // expect: 0
  assert(r2 == 0);
  printf("%d\n", r3); // expect: 1
  assert(r3 == 1);
}
