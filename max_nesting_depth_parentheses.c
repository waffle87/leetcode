// 1614. Maximum Nesting Depth of the Parentheses
#include "leetcode.h"

/*
 * given a valid parentheses string 's', return the nestign depth of 's'. the
 * nesting depth is the maximum number of nested parentheses.
 */

int maxDepth(char *s) {
  int ans = 0, curr = 0;
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      ans = fmax(ans, ++curr);
    if (s[i] == ')')
      curr--;
  }
  return ans;
}

int main() {
  char *s1 = "(1+(2*3)+((8)/4))+1";
  char *s2 = "(1)+((2))+(((3)))";
  int r1 = maxDepth(s1);
  int r2 = maxDepth(s2);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 3);
}
