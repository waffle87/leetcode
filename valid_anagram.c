// 242. Valid Anagram
#include "leetcode.h"

/*
 * given two strings 's' and 't', return 'true' if 't' is an anagram of 's', and
 * false otherwise. an anagram is a word or phrase formed by rearranging the
 * letters of a different word or phrase, typically using all the original
 * letters exactly once.
 */

bool isAnagram(char *s, char *t) {
  if (strlen(s) != strlen(t))
    return 0;
  int mask[256] = {};
  char *c = s;
  while (*c)
    mask[*c++]++;
  c = t;
  while (*c) {
    if (mask[*c])
      mask[*c++]--;
    else
      return 0;
  }
  return 1;
}

int main() {
  char *s1 = "anagram", *t1 = "nagaram";
  char *s2 = "rat", *t2 = "car";
  printf("%d\n", isAnagram(s1, t1)); // expect: true
  printf("%d\n", isAnagram(s2, t2)); // expect: false
}
