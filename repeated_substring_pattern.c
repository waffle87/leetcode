// 459. Repeated Substring Pattern
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
 * given a string 's', check if it can be constructed by taking a substring of
 * it and appending multiple copies of the substring together.
 */

bool repeatedSubstringPattern(char *s) {
  int n = strlen(s), sub_len;
  bool ans;
  if (n == 1)
    return false;
  for (sub_len = 1; sub_len <= n / 2; sub_len++) {
    if (n % sub_len) {
      ans = false;
      continue;
    }
    ans = true;
    for (int i = 0; i < n; i += sub_len)
      if (strncmp(s + i, s, sub_len)) {
        ans = false;
        break;
      }
    if (ans)
      return true;
  }
  return ans;
}

int main() {
  char s1[] = {"abab"}, s2[] = {"aba"}, s3[] = {"abcabcabcabc"};
  printf("%d\n", repeatedSubstringPattern(s1)); // expect: 1
  printf("%d\n", repeatedSubstringPattern(s2)); // expect: 0
  printf("%d\n", repeatedSubstringPattern(s3)); // expect: 1
}
