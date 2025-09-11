// 2785. Sort Vowels in a String
#include "leetcode.h"

/*
 * given a 0-indexed string 's', permute 's' to get a new string 't'.
  - All consonants remain in their original places. More formally, if there is
 an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] =
 s[i].
 - The vowels must be sorted in the nondecreasing order of their ASCII
 values. More formally, for pairs of indices i, j with 0 <= i < j < s.length
 such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII
 value than t[j].
  * return the resulting string. consonants comprise all letter that are not
 vowels.
  */

bool is_vowel(char c) {
  switch (c) {
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return true;
  default:
    return false;
  }
}

int cmp(const void *a, const void *b) { return (*(char *)a - *(char *)b); }

char *sortVowels(char *s) {
  int n = strlen(s), cnt = 0;
  char *vowels = (char *)malloc(n * sizeof(char));
  for (int i = 0; i < n; ++i)
    if (is_vowel(s[i]))
      vowels[cnt++] = s[i];
  qsort(vowels, cnt, sizeof(char), cmp);
  for (int i = 0, j = 0; j < n; ++i)
    if (is_vowel(s[i]))
      s[i] = vowels[j++];
  free(vowels);
  return s;
}

int main() {
  char s1[] = {"lEetcOde"}, s2[] = {"lYmpH"};
  printf("%s\n", sortVowels(s1)); // expect: lEOtcede
  printf("%s\n", sortVowels(s2)); // expect: lYmpH
}
