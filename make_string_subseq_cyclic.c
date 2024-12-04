// 2825. Make String a Subsequence Using Cyclic Increments
#include "leetcode.h"

/*
 * you are given two 0-indexed strings 'str1' and 'str2'. in an operation, you
 * select a set of indices in 'str1' and for each index 'i' in the set,
 * increment 'str1[i]' to be the next character cyclically. that is, 'a' becomes
 * 'b', 'b' becomes 'c', and so on. return true if it is possible to make 'str2'
 * a subsequence of 'str1' by performing the operation at most once, and false
 * otherwise. note, a subsequence is a new string that is formed from the
 * original string by deleting some (possible none) of the characters without
 * disturbing the relative positions of the remaining characters
 */

bool canMakeSubsequence(char *str1, char *str2) {
  int j = 0, n = strlen(str1), m = strlen(str2);
  for (int i = 0; i < n && j < m; ++i)
    if (str1[i] == str2[j] || str1[i] + 1 == str2[j] || str1[i] - 25 == str2[j])
      ++j;
  return j == m;
}

int main() {
  char *s11 = "abc", *s21 = "ad";
  char *s12 = "zc", *s22 = "ad";
  char *s13 = "ab", *s23 = "d";
  printf("%d\n", canMakeSubsequence(s11, s21)); // expect: 1
  printf("%d\n", canMakeSubsequence(s12, s22)); // expect: 1
  printf("%d\n", canMakeSubsequence(s13, s23)); // expect: 0
}
