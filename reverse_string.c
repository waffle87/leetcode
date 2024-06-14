// 344. Reverse String
#include "leetcode.h"

/*
 * write a function that reverses a string. the input string is given as an
 * array of characters 's'. you must do this by modifying teh input array in
 * place with 'O(1)' extra memroy
 */

void reverseString(char *s, int sSize) {
  char *ptr = s + sSize - 1, tmp = *s;
  if (sSize <= 1)
    return;
  *s = *ptr;
  *ptr = tmp;
  reverseString(s + 1, sSize - 2);
}

int main() {
  char *s1 = "hello", *s2 = "Hannah";
  reverseString(s1, strlen(s1));
  reverseString(s2, strlen(s2));
  printf("%s\n", s1); // expect: olleh
  printf("%s\n", s2); // expect: hannaH
}
