// 3110. Score of a String
#include "leetcode.h"

/*
 * you are given a string 's'. the score of a string is defined as the sume of
 * the absolute different between the ascii values of adjacent characters.
 * return the score of 's'.
 */

int scoreOfString(char *s) {
  int ans = 0, val = 0, n = strlen(s);
  while (--n) {
    val = *s - *(s + 1);
    if (val < 0)
      val = -val;
    ans += val;
    s++;
  }
  return ans;
}

int main() {
  char *s1 = "hello", *s2 = "zaz";
  printf("%d\n", scoreOfString(s1)); // expect: 13
  printf("%d\n", scoreOfString(s2)); // expect: 50
}
