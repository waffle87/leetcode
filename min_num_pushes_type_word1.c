// 3014. Minimum Number of Pushes to Type Word I
#include "leetcode.h"

/*
 * you are given a string 'word' containing distinct lowercase english letters.
 * telephone keypas have keys mapped with distinct collections of lowercase
 * english letters, which can be used to form words by pushing them. it is
 * allowed to remap the keys numbered 2 - 9 to distinct collections of letters.
 * the keys can be remapped to any amount of letters, but each letter must be
 * mapped to exactly one key. you need to find  the minimum number of times the
 * keys will be pushed to type the string 'word'.
 */

int minimumPushes(char *word) {
  int n = strlen(word);
  int q = n >> 3, r = n & 7;
  return ((q << 2) + r) * (q + 1);
}

int main() {
  char *w1 = "abcde", *w2 = "xycdefghij";
  int r1 = minimumPushes(w1);
  int r2 = minimumPushes(w2);
  printf("%d\n", r1);
  assert(r1 == 5);
  printf("%d\n", r2);
  assert(r2 == 12);
}
