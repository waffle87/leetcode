// 567. Permutation in String
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given two strings 's1 s2' return true if 's2' contains a permutation of 's1'
 * or false otherwise. in other words, return true if one of 's1's permutations
 * is in the substring of 's2'
 */

bool checkInclusion(char *s1, char *s2) {
  int len1 = strlen(s1), len2 = strlen(s2);
  if (len1 > len2)
    return false;
  int freq1[128] = {0}, freq2[128] = {0};
  for (int i = 0; i < len1; i++) {
    freq1[s1[i]]++;
    freq2[s2[i]]++;
  }
  if (memcmp(freq1, freq2, sizeof(freq1)) == 0)
    return true;
  for (int i = len1; i < len2; i++) {
    --freq2[s2[i - len1]];
    ++freq2[s2[i]];
    if (memcmp(freq1, freq2, sizeof(freq1)) == 0)
      return true;
  }
  return false;
}

int main() {
  char s[] = "ab", s1[] = "eidbaooo", s2[] = "eidboaoo";
  printf("%d\n", checkInclusion(s, s1)); // expect: 1
  printf("%d\n", checkInclusion(s, s2)); // expect: 1
}
