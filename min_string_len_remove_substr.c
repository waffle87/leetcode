// 2696. Minimum String Length After Removing Substrings
#include "leetcode.h"

/*
 * you are given a string 's' consisting only of uppercase english letters. you
 * can apply some operations to this string where in one operation you can
 * remove any occurence of one of the sbustrings 'AB' or 'CD' from 's'. return
 * the minimum possible length of the resulting string that you can obtain. note
 * that the string concatenates after removing the substring and could produce
 * new 'AB' or 'CD' substrings
 */

int minLength(char *s) {
  int n = strlen(s), top = -1, ans;
  char *stack = (char *)malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++) {
    if (top >= 0 &&
        (stack[top] == 'A' && s[i] == 'B' || stack[top] == 'C' && s[i] == 'D'))
      top--;
    else
      stack[++top] = s[i];
  }
  stack[++top] = '\0';
  ans = top;
  free(stack);
  return ans;
}

int main() {
  char *s1 = "ABFCACDB", *s2 = "ACBBD";
  printf("%d\n", minLength(s1)); // expect: 2
  printf("%d\n", minLength(s2)); // expect: 5
}
