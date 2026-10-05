// 856. Score of Parentheses
#include "leetcode.h"

/*
 * given the balanced parentheses string '*', return the score of the string.
 * the score of a balanced parentheses string is based on the following rules:
 * '()' has a score of 1, 'AB' has a score of A + B where A and B are valid
 * parentheses strings, and '(A)' has a score of '2 * A' where A is the balanced
 * parentheses string.
 */

int scoreOfParentheses(char *s) {
  int ans = 0, balance = 0;
  for (int i = 0; s[i]; ++i) {
    balance += s[i] == '(' ? 1 : -1;
    if (i && s[i - 1] == '(' && s[i] == ')')
      ans += pow(2, balance);
  }
  return ans;
}

int main() {
  char *s1 = "()";
  char *s2 = "(())";
  char *s3 = "()()";
  int r1 = scoreOfParentheses(s1);
  int r2 = scoreOfParentheses(s2);
  int r3 = scoreOfParentheses(s3);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 2);
}
