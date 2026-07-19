// 1081. Smallest Subsequence of Distinct Characters
#include "leetcode.h"

/*
 * given a string 's', return the lexicographically smallest subsequence of 's'
 * that contains all the distinct characters of 's' exactly once.
 */

char *smallestSubsequence(char *s) {
  int freq[128] = {0}, n = strlen(s), top = 0;
  bool vis[128] = {false};
  char *stack = (char *)malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++)
    freq[(unsigned char)s[i]]++;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    freq[(unsigned char)c]--;
    if (vis[(unsigned char)c])
      continue;
    while (top > 0 && stack[top - 1] > c &&
           freq[(unsigned char)stack[top - 1]] > 0) {
      vis[(unsigned char)stack[top - 1]] = false;
      top--;
    }
    stack[top++] = c;
    vis[(unsigned char)c] = true;
  }
  stack[top] = '\0';
  return stack;
}

int main() {
  char *s1 = "bcabc", *r1 = "abc";
  char *s2 = "cbacdcbc", *r2 = "acdb";
  char *ss1 = smallestSubsequence(s1);
  char *ss2 = smallestSubsequence(s2);
  printf("%s\n", ss1);
  assert(!strcmp(ss1, r1));
  printf("%s\n", ss2);
  assert(!strcmp(ss2, r2));
  free(ss1);
  free(ss2);
}
