// 3330. Find the Original Typed String I
#include "leetcode.h"

/*
 * alice is attmpting to type a specific string on her computer. however, she
 * tends to be clumsy and may press a key for too long, resulting a character
 * being typed multiple times. although alice tried to focus on her typing, she
 * is aware that she may still have done this at least once. you are given a
 * string 'word', which represents the final output displayed on alices screen.
 * return the total number of possible original strings that alice might have
 * intended to type.
 */

int possibleStringCount(char *word) {
  int n = strlen(word), ans = n;
  for (int i = 1; i < n; ++i)
    ans -= word[i] != word[i - 1];
  return ans;
}

int main() {
  char *w1 = "abbcccc", *w2 = "abcd", *w3 = "aaaa";
  printf("%d\n", possibleStringCount(w1)); // expect: 5
  printf("%d\n", possibleStringCount(w2)); // expect: 1
  printf("%d\n", possibleStringCount(w3)); // expect: 4
}
