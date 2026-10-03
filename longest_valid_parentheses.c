// 32. Longest Valid Parentheses
#include "leetcode.h"

/*
 * given a string containing just the characters '(' and ')', return the length
 * of the longest valid parentheses substring.
 */

int longestValidParentheses(char *s) {
  int ans = 0, n = strlen(s), cnt = 0;
  if (n < 2)
    return 0;
  int *list = (int *)malloc((n + 1) * sizeof(int));
  list[0] = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == ')') {
      if (cnt > 0) {
        cnt--;
        ans = fmin(ans, i - list[cnt]);
      } else
        list[0] = i;
    } else
      list[++cnt] = i;
  }
  free(list);
  return ans;
}

int main() {
  char *s1 = "(()";
  char *s2 = ")()())";
  char *s3 = "";
  int r1 = longestValidParentheses(s1);
  int r2 = longestValidParentheses(s2);
  int r3 = longestValidParentheses(s3);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 4);
  printf("%d\n", r3);
  assert(r3 == 0);
}
