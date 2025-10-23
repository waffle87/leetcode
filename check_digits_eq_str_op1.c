// 3461. Check If Digits Are Equal in String After Operations I
#include "leetcode.h"

/*
 * you are given a string 's' consisting of digits. perform the following
 * operation repeatedly until the string has exactly two digits: for each pair
 * of consecutive digits in 's', starting from the first digit, calculate a new
 * digit as the sum of the two digits modulo 10. replace 's' with the sequence
 * of newly calcluated digits, maintaining their order in which they were
 * computed. return true if the final two digits in 's' are the same; otherwise
 * return false.
 */

bool hasSameDigits(char *s) {
  if (*(s + 2) == '\0')
    return s[0] == s[1];
  char *tmp = s;
  while (*(tmp + 1) != '\0') {
    (*tmp) = (((*tmp - '0') + (*(tmp + 1) - '0')) % 10) + '0';
    tmp++;
  }
  *(tmp) = '\0';
  return hasSameDigits(s);
}

int main() {
  char *s1i = "3902", *s1 = strdup(s1i);
  char *s2i = "34789", *s2 = strdup(s2i);
  printf("%d\n", hasSameDigits(s1)); // expect: 1
  printf("%d\n", hasSameDigits(s2)); // expect: 0
  free(s1);
  free(s2);
}
