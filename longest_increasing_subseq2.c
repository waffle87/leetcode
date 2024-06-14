// 1143. Longest Common Subsequence
#include "leetcode.h"

/*
 * given two strings 'text1' and 'text2', return the length of their longest
 * common subsequence. if there is no common subsequence, return 0. a
 * subsequence of a string is a new string generated from the original string
 * with some characers (can be none) deleted without changing the relative order
 * of the remaining characters. a common subsequence of two strings is a
 * subsequence that is common to both strings.
 */

int longestCommonSubsequence(char *text1, char *text2) {
  int x = strlen(text1) + 1;
  int y = strlen(text2) + 1;
  int **matrix = malloc(y * sizeof(int *));
  for (int i = 0; i < y; i++) {
    matrix[i] = malloc(x * sizeof(int));
    matrix[i][0] = 0;
  }
  for (int i = 0; i < x; i++)
    matrix[0][i] = 0;
  for (int i = 1; i < y; i++)
    for (int j = 1; j < x; j++) {
      if (text1[j - 1] == text2[i - 1])
        matrix[i][j] = matrix[i - 1][j - 1] + 1;
      else if (matrix[i - 1][j] >= matrix[i][j - 1])
        matrix[i][j] = matrix[i - 1][j];
      else
        matrix[i][j] = matrix[i][j - 1];
    }
  return matrix[y - 1][x - 1];
}

int main() {
  char *t11 = "abcde", *t21 = "ace";
  char *t12 = "abc", *t22 = "abc";
  char *t13 = "abc", *t23 = "def";
  printf("%d\n", longestCommonSubsequence(t11, t21)); // expect: 3
  printf("%d\n", longestCommonSubsequence(t12, t22)); // expect: 3
  printf("%d\n", longestCommonSubsequence(t13, t23)); // expect: 0
}
