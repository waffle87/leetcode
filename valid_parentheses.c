// 20. Valid Parentheses
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string 's' containing just the characters '(, ), {, }, [, ]',
 * determine if the input string is valid. a input string is valid if open
 * brackets must be closed by the same type of brackets. open brackets must be
 * closed in the correct order. every close bracket has a corresponding open
 * bracket of the same type.
 */

bool isValid(char *s) {
  int len = strlen(s);
  if (len % 2)
    return false;
  int n = len / 2, idx = 0;
  char *stack = malloc(n), c, top;
  for (int i = 0; i < len; i++) {
    c = s[i];
    if (c == '(' || c == '[' || c == '{') {
      if (idx == n)
        return false;
      else
        stack[idx++] = c;
    } else {
      if (!idx)
        return false;
      top = stack[idx - 1];
      if (top == '(' && c == ')' || top == '[' && c == ']' ||
          top == '{' && c == '}')
        idx--;
      else
        return false;
    }
  }
  return !idx;
}

int main() {
  char s1[] = {"()"}, s2[] = {"()[]{}"}, s3[] = {"(]"};
  printf("%d\n", isValid(s1)); // expect: 1
  printf("%d\n", isValid(s2)); // expect: 1
  printf("%d\n", isValid(s3)); // expect: 0
}
