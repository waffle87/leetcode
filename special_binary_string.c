// 761. Special Binary String
#include "leetcode.h"

/*
 * special binary strings are binary strings with the following two properties:
 * the number of 0's is equal to the number of 1's, and every prefix of the
 * binary tring has at least as many 1's as 0's. you are given a special binary
 * string 's'. a move consists of choosing two consecutive non-empty special
 * substrings of 's', and swapping them. two strings are consecutive if the last
 * character of the first string is exactly one index before the first character
 * of the second string. return the lexicographically largest resulting string
 * possible after applying the mentioned operations on the string.
 */

int cmp(const void *a, const void *b) {
  char *aa = *(char **)a, *bb = *(char **)b;
  return strcmp(bb, aa);
}

char *makeLargestSpecial(char *s) {
  int n = strlen(s);
  if (n <= 2)
    return strdup(s);
  char **substr = (char **)malloc(n * sizeof(char *));
  int cnt = 0, balance = 0, start = 0;
  for (int i = 0; i < n; i++) {
    balance += (s[i] == '1') ? 1 : -1;
    if (!balance) {
      int len = i - start + 1;
      char *inner = (char *)malloc((len - 1) * sizeof(char));
      strncpy(inner, s + start + 1, len - 2);
      inner[len - 2] = '\0';
      char *processed = makeLargestSpecial(inner);
      free(inner);
      char *full = (char *)malloc((len + 1) * sizeof(char));
      full[0] = '1';
      strcpy(full + 1, processed);
      full[len - 1] = '0';
      full[len] = '\0';
      free(processed);
      substr[cnt++] = full;
      start = i + 1;
    }
  }
  qsort(substr, cnt, sizeof(char *), cmp);
  char *ans = (char *)malloc((n + 1) * sizeof(char));
  ans[0] = '\0';
  for (int i = 0; i < cnt; i++) {
    strcat(ans, substr[i]);
    free(substr[i]);
  }
  free(substr);
  return ans;
}

int main() {
  char *s1 = "11011000", *r1 = "11100100";
  char *s2 = "10", *r2 = "10";
  char *mls1 = makeLargestSpecial(s1);
  char *mls2 = makeLargestSpecial(s2);
  printf("%s\n", mls1); // expect: 11100100
  assert(!strcmp(r1, mls1));
  printf("%s\n", mls2); // expect: 10
  assert(!strcmp(r2, mls2));
  free(mls1);
  free(mls2);
}
