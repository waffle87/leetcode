// 647. Palindromic Substrings
#include "leetcode.h"

/*
 * given a string 's', return the number of palindromic substrings in it. a
 * string is a palindrome when it reads the same backward as forward. a
 * substring is a contiguous sequence of charcters within the string.
 */

int countSubstrings(char *s) {
  int i = 0, num = 0, left = 0, right = 0;
  while (s[i] != '\0') {
    left = right = i;
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
      num++;
      left--;
      right++;
    }
    left = i;
    right = i + 1;
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
      num++;
      left--;
      right++;
    }
    i++;
  }
  return num;
}

int main() {
  char *s1 = "abc", *s2 = "aaa";
  printf("%d\n", countSubstrings(s1)); // expect: 3
  printf("%d\n", countSubstrings(s2)); // expect: 6
}
