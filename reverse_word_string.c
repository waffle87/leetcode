// 557. Reverse Words in a String III
#include <stdio.h>
#include <string.h>

/*
 * given a string 's', reverse the order of characters in each word within a
 * sentence while still preserving whitespace and initial word order
 */

void reverse(int b, int e, char *s) {
  while (b < e) {
    s[b] ^= s[e];
    s[e] ^= s[b];
    s[b] ^= s[e];
    b++;
    e--;
  }
}

char *reverseWords(char *s) {
  int s_len = strlen(s), idx = 0;
  for (int i = 0; i <= s_len; i++)
    if (s[i] == ' ' || s[i] == '\0') {
      reverse(idx, i - 1, s);
      idx = i + 1;
    }
  return s;
}

int main() {
  char s1[] = {"Let's take Leetcode contest"};
  char s2[] = {"God Ding"};
  printf("%s\n", reverseWords(s1)); // expect: s'teL ekat edoCteeL tsetnoc
  printf("%s\n", reverseWords(s2)); // expect: doG gniD
}
