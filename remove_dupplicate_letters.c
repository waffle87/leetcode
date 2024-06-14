// 316. Remove Duplicate Letters
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string 's', remove duplicate letters so that every letter appears
 * once and only once. you must make sure your result is the smallest in
 * lexicographical order among all possible results.
 */

char *removeDuplicateLetters(char *s) {
  int n = strlen(s), a_idx = 0;
  int *digit = calloc(26, sizeof(int));
  for (int i = 0; i < n; i++)
    digit[s[i] - 'a']++;
  bool *set = calloc(26, sizeof(bool));
  char *ans = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    if (set[s[i] - 'a']) {
      digit[s[i] - 'a']--;
      continue;
    }
    while (a_idx && s[i] < ans[a_idx] && digit[ans[a_idx - 1] - 'a']) {
      set[ans[a_idx - 1] - 'a'] = false;
      a_idx--;
    }
    ans[a_idx] = s[i];
    a_idx++;
    digit[s[i] - 'a']--;
    set[s[i] - 'a'] = true;
  }
  ans[a_idx] = '\0';
  return ans;
}

int main() {
  char s1[] = {"bcabc"}, s2[] = {"cbacdcbc"};
  printf("%s\n", removeDuplicateLetters(s1)); // expect: abc
  printf("%s\n", removeDuplicateLetters(s2)); // expect: acdb
}
