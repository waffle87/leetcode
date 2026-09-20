// 3498. Reverse Degree of a String
#include "leetcode.h"

/*
 * given a string 's', calculate its reverse degree. the reverse degree is
 * calculated as follows: for each character, multiply its position in the
 * reversed alphabet with its position in the string (1-indexed). sum these
 * products for all characters in the string. return the reverse degree of 's'.
 */

int reverseDegree(char *s) {
  int ans = 0, n = strlen(s);
  for (int i = 0; i < n; i++)
    ans += (i + 1) * ('z' - s[i] + 1);
  return ans;
}

int main() {
  char *s1 = "abc";
  char *s2 = "zaza";
  int r1 = reverseDegree(s1);
  int r2 = reverseDegree(s2);
  printf("%d\n", r1);
  assert(r1 == 148);
  printf("%d\n", r2);
  assert(r2 == 160);
}
