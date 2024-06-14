// 767. Reorganize String
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string 's', rearrange the characters of 's' so that any two adjacent
 * characters are not the same. return any possible arrangement of 's', or
 * return "" if not possible.
 */

char find_max(int hist[26], char c) {
  int max = 0;
  char out = '\0';
  for (int i = 0; i < 26; i++)
    if (i + 'a' != c && hist[i] > max) {
      max = hist[i];
      out = i + 'a';
    }
  return out;
}

char *reorganizeString(char *s) {
  int hist[26] = {0};
  if (!strlen(s))
    return s;
  for (int i = 0; i < strlen(s); i++)
    hist[s[i] - 'a']++;
  char max = find_max(hist, '\0'), last;
  int idx = 0;
  char *out = (char *)malloc(sizeof(char) * (strlen(s) + 1));
  while (max != '\0') {
    out[idx++] = max;
    last = max;
    hist[last - 'a']--;
    max = find_max(hist, last);
  }
  if (idx != strlen(s)) {
    free(out);
    return "";
  }
  out[idx] = '\0';
  strcpy(s, out);
  free(out);
  return s;
}

int main() {
  char s1[] = {"aab"}, s2[] = {"aaab"};
  printf("%s\n", reorganizeString(s1)); // expect: aba
  printf("%s\n", reorganizeString(s2)); // expect:
}
