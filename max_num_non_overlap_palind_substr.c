// 2472. Maximum Number of Non-overlapping Palindrome Substrings
#include "leetcode.h"

/*
 * you are given a string 's' and a positive integer 'k'. select a set of
 * non-overlapping substrings from the string 's' that satisfy the following
 * conditions: the length of each substring is at least 'k', and each substring
 * is a palindrome. return the maximum number of substrings in an optimal
 * selection.
 */

bool palindrome(char *s, int left, int right) {
  while (left < right) {
    if (s[left] != s[right])
      return false;
    left++;
    right--;
  }
  return true;
}

int maxPalindromes(char *s, int k) {
  int n = strlen(s), cnt = 0, last = 0;
  for (int right = k - 1; right < n; right++) {
    int left = right - k + 1;
    bool add = (left >= last && palindrome(s, left, right)) ||
               (left > last && palindrome(s, left - 1, right));
    if (add) {
      cnt++;
      last = right + 1;
    }
  }
  return cnt;
}

int main() {
  char *s1 = "abaccdbbd";
  char *s2 = "adbcda";
  int r1 = maxPalindromes(s1, 3);
  int r2 = maxPalindromes(s2, 2);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 0);
}
