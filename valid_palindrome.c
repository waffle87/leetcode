// 125. Valid Palindrome
#include "leetcode.h"

/*
 * a phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters, and removing all non-alphanumeric characters, it reads the
 * same forward and backward. alphanumeric characters include only letters and
 * numbers. given a string 's', return true if it is a palindrome, or false
 * otherwise.
 */

bool isPalindrome(char *s) {
  int l = 0, r = strlen(s) - 1;
  while (l < r) {
    if (isalnum(s[l])) {
      if (isalnum(s[r])) {
        if (tolower(s[l]) != tolower(s[r]))
          return false;
        l++, r--;
      } else
        r--;
    } else
      l++;
  }
  return true;
}

int main() {
  char *s1 = "A man, a plan, a canal: Panama";
  char *s2 = "race a car";
  char *s3 = " ";
  printf("%d\n", isPalindrome(s1)); // expect: 1
  printf("%d\n", isPalindrome(s2)); // expect: 0
  printf("%d\n", isPalindrome(s3)); // expect: 1
}
