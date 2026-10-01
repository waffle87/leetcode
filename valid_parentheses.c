// 20. Valid Parentheses
#include "leetcode.h"

/*
 * given a string 's' containing just the characters '(, ), {, }, [, ]',
 * determine if the input string is valid. a input string is valid if open
 * brackets must be closed by the same type of brackets. open brackets must be
 * closed in the correct order. every close bracket has a corresponding open
 * bracket of the same type.
 */

bool isValid(char *s) {
  int n = strlen(s), j = 0;
  for (int i = n - 1; i >= 0 && j > 0; i--) {
    int b = s[i];
    int c = (b >> 1 ^ b) & 1;
    s[n - j] = b - 1 - (b >> 6);
    j += 2 * c - 1 - (((s[n - j + 1] ^ b) & ~-c) << 14);
  }
  return j == 1;
}

int main() {
  char *s1 = "()";
  char *s2 = "()[]{}";
  char *s3 = "(]";
  bool r1 = isValid(s1);
  bool r2 = isValid(s2);
  bool r3 = isValid(s3);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == true);
  printf("%d\n", r3);
  assert(r3 == false);
}
