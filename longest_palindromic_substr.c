// 5. Longest Palindromic Substring
#include "leetcode.h"

/*
 * given a string 's', return the longest palindromic substring in 's'
 */

char *longestPalindrome(char *s) {
  char *start, *end, *p = s, *sub_start = s;
  int max_len = 1;
  while (*p) {
    start = p;
    end = p;
    while (*(end + 1) && *(end + 1) == *end)
      end++;
    p = end + 1;
    while (*(end + 1) && (start > s) && *(end + 1) == *(start - 1)) {
      start--;
      end++;
    }
    if (end - start + 1 > max_len) {
      max_len = end - start + 1;
      sub_start = start;
    }
  }
  char *ans = (char *)calloc(max_len + 1, sizeof(char));
  strncpy(ans, sub_start, max_len);
  return ans;
}

int main() {
  char s1[] = {"babad"}, s2[] = {"cbbd"};
  printf("%s\n", longestPalindrome(s1)); // expect: bab
  printf("%s\n", longestPalindrome(s2)); // expect: bb
}
