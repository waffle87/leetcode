// 28. Find the Index of the First Occurrence in a String
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given two strings 'needle' and 'haystack', return index of the first
 * occurrence of 'needle' in 'haystack', or -1 if 'needle' is not part of
 * 'haystack'
 */

int cmp(char *s, int i, char *p, int n_bytes) {
  int j = 0;
  while (n_bytes--) {
    if (*(s + i) != *(p + j))
      return -1;
    ++i;
    ++j;
  }
  return 0;
}

int strStr(char *haystack, char *needle) {
  int s_len = strlen(haystack), n_len = strlen(needle);
  if (!s_len) {
    if (!n_len)
      return 0;
    return -1;
  }
  if (!n_len)
    return 0;
  int err = 0;
  for (int i = 0; i < s_len; ++i) {
    if (haystack[i] == needle[0]) {
      err = cmp(haystack, i, needle, n_len);
      if (err)
        continue;
      return i;
    }
  }
  return -1;
}

int main() {
  char hs1[] = "sadbutsad", n1[] = "sad";
  char hs2[] = "leetcode", n2[] = "leeto";
  printf("%d\n", strStr(hs1, n1)); // expect: 0
  printf("%d\n", strStr(hs2, n2)); // expect: 0
}
