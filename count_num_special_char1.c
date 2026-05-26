// 3120. Count the Number of Special Characters I
#include "leetcode.h"

/*
 * you are given a string 'word'. a letter is called special if it appears both
 * in lowercase and uppercase in 'word'. return the number of special characters
 * in 'word'.
 */

int numberOfSpecialChars(char *word) {
  int lower = 0, upper = 0, n = strlen(word);
  for (int i = 0; i < n; i++) {
    if (word[i] >= 'a' && word[i] <= 'z')
      lower |= (1 << (word[i] - 'a'));
    else
      upper |= (1 << (word[i] - 'a'));
  }
  int common = lower & upper;
  return __builtin_popcount(common);
}

int main() {
  char *w1 = "aaAbcBC";
  char *w2 = "abc";
  char *w3 = "abBCab";
  int r1 = numberOfSpecialChars(w1);
  int r2 = numberOfSpecialChars(w2);
  int r3 = numberOfSpecialChars(w3);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 1);
}
