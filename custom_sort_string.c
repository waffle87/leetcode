// 791. Custom Sort String
#include "leetcode.h"

/*
 * given two strings 'order' and 's'. all the characters of 'order' are unique
 * and were sorted in some custom order previously. permute the characters of
 * 's' so that they atch the order that 'order' was sorted. more specifically,
 * if a character 'x' occurs before character 'y' in 'order', then 'x' should
 * occur before 'y' in permuted string. return any permutation of 's' that
 * satisfies this property.
 */

static char pattern[26] = {0};

int cmp(const void *a, const void *b) {
  return pattern[*(char *)a - 'a'] - pattern[*(char *)b - 'a'];
}

char *customSortString(char *order, char *s) {
  for (int i = 0; i < 26; i++)
    pattern[i] = 0;
  for (int i = 0; i < strlen(order); i++)
    pattern[order[i] - 'a'] = i + 1;
  qsort(s, strlen(s), sizeof(char), cmp);
  return s;
}

int main() {
  char *o1 = "cba", *s1 = "abcd", *o2 = "bcafg", *s2 = "abcd";
  printf("%s\n", customSortString(o1, s1)); // expect:
  printf("%s\n", customSortString(o2, s2)); // expect:
}
