// 1190. Reverse Substrings Between Each Pair of Parentheses
#include "leetcode.h"

/*
 * you are given a string 's' that consists of lower case english letters and
 * brackets. reverse the strings in each pair of matching parentheses, starting
 * from the innermost one. your result should not contain any brackets.
 */

char *reverseParentheses(char *s) {
  int n = strlen(s), m = 0, top = -1;
  int *stack = (int *)malloc(n * sizeof(int));
  char *ans = (char *)malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      stack[++top] = m;
    else if (s[i] == ')') {
      int start = stack[top--];
      for (int j = start, k = m - 1; j < k; j++, k--) {
        char tmp = ans[j];
        ans[j] = ans[k];
        ans[k] = tmp;
      }
    } else
      ans[m++] = s[i];
  }
  ans[m] = '\0';
  free(stack);
  return ans;
}

int main() {
  char *s1 = "(abcd)", *r1 = "dcba";
  char *s2 = "(u(love)i)", *r2 = "iloveu";
  char *s3 = "(ed(et(oc))el)", *r3 = "leetcode";
  char *rp1 = reverseParentheses(s1);
  char *rp2 = reverseParentheses(s2);
  char *rp3 = reverseParentheses(s3);
  printf("%s\n", rp1);
  assert(!strcmp(rp1, r1));
  printf("%s\n", rp2);
  assert(!strcmp(rp2, r2));
  printf("%s\n", rp3);
  assert(!strcmp(rp3, r3));
  free(rp1);
  free(rp2);
  free(rp3);
}
