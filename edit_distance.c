// 72. Edit Distance
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b, c)                                                           \
  ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

/*
 * given two strings 'word1' and 'word2', return minimum number of operations
 * required to convert 'word1' to 'word2'. the following operations are
 * permitted: insert character, delete character, replace character
 */

int minDistance(char *word1, char *word2) {
  int len1 = strlen(word1), len2 = strlen(word2);
  if (len1 == 0)
    return len2;
  if (len2 == 0)
    return len1;
  int **table = (int **)malloc(len1 * sizeof(int *));
  for (int i = 0; i < len1; i++)
    table[i] = (int *)malloc(len2 * sizeof(int));
  if (word1[0] == word2[0])
    table[0][0] = 0;
  else
    table[0][0] = 1;
  for (int i = 1; i < len2; i++) {
    if (word1[0] == word2[i])
      table[0][i] = i;
    else
      table[0][i] = table[0][i - 1] + 1;
  }
  for (int i = 1; i < len1; i++) {
    if (word2[0] == word1[i])
      table[i][0] = i;
    else
      table[i][0] = table[i - 1][0] + 1;
  }
  for (int i = 1; i < len1; i++)
    for (int j = 1; j < len2; j++) {
      if (word1[i] == word2[i])
        table[i][j] = table[i - 1][j - 1];
      else
        table[i][j] =
            MIN(table[i - 1][j], table[i][j - 1], table[i - 1][j - 1]);
    }
  int ans = table[len1 - 1][len2 - 1];
  for (int i = 0; i < len1; i++)
    free(table[i]);
  free(table);
  return ans;
}

int main() {
  char w11[] = "horse", w21[] = "ros";
  char w12[] = "intention", w22[] = "execution";
  printf("%d\n", minDistance(w11, w21)); // expect: 3
  printf("%d\n", minDistance(w12, w22)); // expect: 5
}
