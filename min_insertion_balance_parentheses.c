// 1541. Minimum Insertions to Balance a Parentheses String
#include "leetcode.h"

/*
 * given a parentheses string 's' containing only the characters '(' and ')'. a
 * parenthese string is balanced if any left parenthesis '(' must have the
 * corresponding two right parentheses '))'. return the minimum number of
 * insertions needed to make 's' balanced.
 */

int minInsertions(char *s) {
  int p = 0, k = 0, n = strlen(s);
  for (int i = 0; i < n; i++) {
    bool open = s[i] == '(';
    p += (open << 1) - (!open);
    bool odd = p & 1, neg = p < 0;
    k += (open & odd) + (!open & neg);
    p += -(open & odd) + ((!open & neg) << 1);
  }
  return p + k;
}

int main() {
  char *s1 = "(()))";
  char *s2 = "())";
  char *s3 = "))())(";
  int r1 = minInsertions(s1);
  int r2 = minInsertions(s2);
  int r3 = minInsertions(s3);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 3);
}
