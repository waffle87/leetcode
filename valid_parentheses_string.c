// 678. Valid Parenthesis String
#include "leetcode.h"

/*
 * given a string 's' containing only three types of characters, return true if
 * 's' is valid. the following rules define a valid string: any left parenthesis
 * must have a corresponding right parenthesis. any right parenthesis must have
 * a corresponding left parenthesis. left parenthesis must go before the
 * corresponding right parenthesis. start could be treated as a single right
 * parenthesis, a single left parenthesis, or an empty string.
 */

bool checkValidString(char *s) {
  int n = strlen(s), cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(' || s[i] == '*')
      cnt++;
    else {
      cnt--;
      if (cnt < 0)
        return 0;
    }
  }
  cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == ')' || s[i] == '*')
      cnt++;
    else {
      cnt--;
      if (cnt < 0)
        return 0;
    }
  }
  return 1;
}

int main() {
  char *s1 = "()", *s2 = "(*)", *s3 = "(*))";
  printf("%d\n", checkValidString(s1)); // expect: 1
  printf("%d\n", checkValidString(s2)); // expect: 1
  printf("%d\n", checkValidString(s3)); // expect: 1
}
