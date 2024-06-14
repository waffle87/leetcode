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

char map[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

char is_vowel(char c, int *idx) {
  if (c == 'A' || c == 'a')
    return true;
  else if (c == 'E' || c == 'e') {
    (*idx) = 1;
    return true;
  } else if (c == 'I' || c == 'i') {
    (*idx) = 2;
    return true;
  } else if (c == 'O' || c == 'o') {
    (*idx) = 3;
    return true;
  } else if (c == 'U' || c == 'u') {
    (*idx) = 4;
    return true;
  }
  return false;
}

char *sortVowels(char *s) {
  int hash[10] = {0}, len = strlen(s);
  char *ans = (char *)calloc(len + 1, sizeof(char));
  for (int i = 0; i < len; i++) {
    int idx = 0;
    if (is_vowel(s[i], &idx)) {
      if (isupper(s[i]))
        hash[idx]++;
      else
        hash[idx + 5]++;
    }
  }
  int a_idx = 0, tmp;
  for (int i = 0; i < len; i++) {
    if (is_vowel(s[i], &tmp)) {
      for (int j = 0; j < 10; j++) {
        if (hash[j]) {
          ans[a_idx++] = map[j];
          hash[j]--;
          break;
        }
      }
    } else {
      ans[a_idx++] = s[i];
    }
  }
  return ans;
}

int main() {
  char s1[] = {"lEetcOde"}, s2[] = {"lYmpH"};
  printf("%s\n", sortVowels(s1)); // expect: lEOtcede
  printf("%s\n", sortVowels(s2)); // expect: lYmpH
}
