// 3121. Count the Number of Special Characters II
#include "leetcode.h"

/*
 * you are given a string 'word'. a letter 'c' is called special if it appears
 * both in lowercase and uppercase in 'word', and every lowercase occurence of
 * 'c' appears before the first uppercase occurence of 'c'. return the number of
 * special letters in 'word'.
 */

int numberOfSpecialChars(char *word) {
  uint32_t lower = 0, upper = 0, invalid = 0;
  for (int i = 0; word[i] != '\0'; i++) {
    char curr = word[i];
    bool lowercase = curr > 'Z';
    int idx = curr - 'A' - (lowercase << 5);
    if (lowercase)
      lower |= (1 << idx);
    else
      upper |= (1 << idx);
    invalid |= ((uint32_t)lowercase << idx) & upper;
  }
  uint32_t common = lower & upper & ~invalid;
  return __builtin_popcount(common);
}

int main() {
  char *w1 = "aaAbcBC";
  char *w2 = "abc";
  char *w3 = "AbBCab";
  int r1 = numberOfSpecialChars(w1);
  int r2 = numberOfSpecialChars(w2);
  int r3 = numberOfSpecialChars(w3);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 0);
}
