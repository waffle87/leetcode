// 1910. Remove All Occurrences of a Substring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given two strings 's' and 'part', perform the following operation on 's'
 * until all occurrences of the substring 'part' are removed; find the leftmost
 * occurrence of the substring 'part' and remove it from 's'. return 's' after
 * removing all occurrences of 'part'. a substring is a contiguous sequence of
 * characters in a string
 */

char *removeOccurrences(char *s, char *part) {
  int s_len = strlen(s), p_len = strlen(part), idx = 0;
  char *ans = (char *)malloc((s_len + 1) * sizeof(char));
  for (int i = 0; i < s_len; i++) {
    ans[idx++] = s[i];
    if (idx >= p_len && (!strncmp(ans + idx - p_len, part, p_len)))
      idx -= p_len;
  }
  ans[idx] = '\0';
  return ans;
}

int main() {
  char s1[] = {"daabcbaabcbc"}, p1[] = {"abc"};
  char s2[] = {"axxxxyyyyb"}, p2[] = {"xy"};
  printf("%s\n", removeOccurrences(s1, p1)); // expect: dab
  printf("%s\n", removeOccurrences(s2, p2)); // expect: ab
}
