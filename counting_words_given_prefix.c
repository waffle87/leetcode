// 2185. Counting Words With a Given Prefix
#include "leetcode.h"

/*
 * you are given an array of strings 'words' and a string 'pref'. return the
 * number of strings in 'words' that contain 'pref' as a prefix. a prefix of a
 * string 's' is any leading contiguous substring of 's'.
 */

int prefixCount(char **words, int wordsSize, char *pref) {
  int cnt = 0, n = strlen(pref);
  for (int i = 0; i < wordsSize; i++)
    if (!strncmp(words[i], pref, n))
      cnt++;
  return cnt;
}

int main() {
  char *w1[] = {"pay", "attention", "practice", "attend"}, *p1 = "at";
  char *w2[] = {"leetcode", "win", "loops", "success"}, *p2 = "code";
  printf("%d\n", prefixCount((char **)w1, ARRAY_SIZE(w1), p1)); // expect: 2
  printf("%d\n", prefixCount((char **)w2, ARRAY_SIZE(w2), p2)); // expect: 0
}
