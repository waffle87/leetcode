// 1614. Maximum Nesting Depth of the Parentheses
#include "leetcode.h"

int maxDepth(char *s) {
  int ans = 0, k = 0, n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      k++;
    if (s[i] == ')')
      k--;
    if (k > ans)
      ans = k;
  }
  return ans;
}

int main() {
  char *s1 = "(1+(2*3)+((8)/4))+1", *s2 = "(1)+((2))+(((3)))";
  printf("%d\n", maxDepth(s1)); // expect: 3
  printf("%d\n", maxDepth(s2)); // expect: 3
}
