// 1957. Delete Characters to Make Fancy String
#include "leetcode.h"

/*
 * a fancy string is a string where no three consecutive characters are equal.
 * given a string 's', delete the minimum possible number of characters from 's'
 * to make it fancy. return the final string after the deletion. it can be shown
 * that the answer will always be unique
 */

char *makeFancyString(char *s) {
  int n = strlen(s);
  if (n < 3)
    return s;
  int cnt = 1, j = 0;
  for (int i = 1; i < n; i++) {
    cnt = s[i] == s[i - 1] ? cnt + 1 : 1;
    if (cnt <= 2)
      s[++j] = s[i];
  }
  s[j + 1] = '\0';
  return s;
}

int main() {
  char *s1 = "leeetcode", *s2 = "aaabaaaa", *s3 = "aab";
  printf("%s\n", makeFancyString(s1)); // expect: leetcode
  printf("%s\n", makeFancyString(s2)); // expect: aabaa
  printf("%s\n", makeFancyString(s3)); // expect: aab
}
