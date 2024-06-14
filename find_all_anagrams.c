// 438. Find All Anagrams in a String
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given two strings 's & p', return an array of all the start indices of 'p's
 * anagrams in 's' (any order). an anagram is a word or phrase formed by
 * rearranging the letters of a different word or phrase, typically using all
 * original letters exactly one
 */

int cmp(int *a, int *b) {
  for (int i = 0; i < 26; i++)
    if (a[i] != b[i])
      return 0;
  return 1;
}

int *findAnagrams(char *s, char *p, int *returnSize) {
  int ssz = strlen(s), psz = strlen(p);
  int *ans = (int *)malloc(sizeof(int) * ssz);
  if (ssz < psz)
    return ans;
  int sabc[26] = {0}, pabc[26] = {0};
  (*returnSize) = 0;
  for (int i = 0; i < psz; i++) {
    pabc[p[i] - 'a']++;
    sabc[s[i] - 'a']++;
  }
  for (int i = 0; i < ssz - psz; i++) {
    if (i != 0)
      sabc[s[i + psz - 1] - 'a']++;
    if (cmp(sabc, pabc)) {
      ans[*returnSize] = i;
      (*returnSize)++;
    }
    sabc[s[i] - 'a']--;
  }
  return ans;
}

int main() {
  char s1[] = "cbaebabacd", s2[] = "abc";
  char p1[] = "abc", p2[] = "ab";
  int rs1[] = {2}, rs2[] = {3};
  printf("%d\n", *findAnagrams(s2, p1, rs1)); // expect: 0 6
  printf("%d\n", *findAnagrams(s2, p2, rs2)); // expect: 0 1 2
}
