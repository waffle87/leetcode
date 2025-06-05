// 1061. Lexicographically Smallest Equivalent String
#include "leetcode.h"

/*
 * you are given two strings of the same length 's1' and 's2' and a string
 * 'baseStr'. we say 's1[i]' and 's2[i]' are equivalent characters. equivalent
 * characters follow the usual rules of any equivalence relation: reflexivity,
 * symmetry, and transitivity. return the lexicographically smallest equivalent
 * string of 'baseStr' by using the equivalency information from 's1' and 's2'.
 */

char *smallestEquivalentString(char *s1, char *s2, char *baseStr) {
  char *ans = baseStr, table[26], to_rep, rep_with;
  for (int i = 0; i < 26; i++)
    table[i] = i + 'a';
  while (*s1) {
    if (table[*s2 - 'a'] < table[*s1 - 'a']) {
      to_rep = table[*s1 - 'a'];
      rep_with = table[*s2 - 'a'];
      for (int i = 0; i < 26; i++)
        if (table[i] == to_rep)
          table[i] = rep_with;
    } else if (table[*s1 - 'a'] < table[*s2 - 'a']) {
      to_rep = table[*s2 - 'a'];
      rep_with = table[*s1 - 'a'];
      for (int i = 0; i < 26; i++)
        if (table[i] == to_rep)
          table[i] = rep_with;
    }
    s1++, s2++;
  }
  while (*baseStr) {
    *baseStr = table[*baseStr - 'a'];
    baseStr++;
  }
  return ans;
}

int main() {
  char *s11 = "parker", *s21 = "morris", *b1 = "parser";
  char *s12 = "hello", *s22 = "world", *b2 = "hold";
  char *s13 = "leetcode", *s23 = "programs", *b3 = "sourcecode";
  printf("%s\n", smallestEquivalentString(s11, s21, b1)); // expect: makkek
  printf("%s\n", smallestEquivalentString(s12, s22, b2)); // expect: hdld
  printf("%s\n", smallestEquivalentString(s13, s23, b3)); // expect: aauaaaaada
}
