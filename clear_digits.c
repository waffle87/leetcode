// 3174. Clear Digits
#include "leetcode.h"

/*
 * you are given a string 's'. your task is to remove all digits by doing this
 * operation repeatedly: delete the first digit and the closest non digit
 * character to its left. return the resulting string after removing all digits.
 */

char *clearDigits(char *s) {
  int n = strlen(s), top = -1;
  char *stack = (char *)malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++) {
    if (isdigit(s[i])) {
      if (top >= 0)
        top--;
    } else
      stack[++top] = s[i];
  }
  stack[++top] = '\0';
  return stack;
}

int main() {
  char *s1 = "abc", *s2 = "cb34";
  printf("%s\n", clearDigits(s1)); // expect: abc
  printf("%s\n", clearDigits(s2)); // expect: null
}
