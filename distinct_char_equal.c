// 2531. Make Number of Distinct Characters Equal
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given: 2 0-indexed strings 'word1' & 'word2'
 * a move consists of choosing two indices i and j such that 0 <= i < word1.len
 * and 0 <= j < word2.len and swapping word1[i] with word2[i]
 * return true if it is possible to get the number of distinct characters
 * in 'word1' & 'word2' to be equal **with exactly one** move
 */

bool isItPossible(char *word1, char *word2) {
  int n1 = strlen(word1), n2 = strlen(word2);
  int *a1 = calloc(26, sizeof(int)), *a2 = calloc(26, sizeof(int));
  int t1 = 0, t2 = 0;
  for (int i = 0; i < n1; i++) {
    a1[word1[i] - 'a']++;
    if (a1[word1[i] - 'a'] == 1)
      t1++;
  }
  for (int i = 0; i < n2; i++) {
    a2[word2[i] - 'a']++;
    if (a2[word2[i] - 'a'] == 1)
      t2++;
  }
  for (int i = 0; i < 26; i++) {
    if (a1[i] == 0)
      continue;
    for (int j = 0; j < 26; j++) {
      if (a2[j] == 0)
        continue;
      if (i == j) {
        if (t1 == t2)
          return true;
        else
          return false;
      }
      int tee1 = t1, tee2 = t2;
      if ((a1[i] - 1) == 0)
        tee1--;
      if ((a2[j] - 1) == 0)
        tee2--;
      if (a1[j] == 0)
        tee1++;
      if (a2[i] == 0)
        tee2++;
      if (tee1 == tee2)
        return true;
    }
  }
  return false;
}

int main() {
  char word11[] = {"ac"}, word21[] = {"b"};
  char word12[] = {"abcc"}, word22[] = {"aab"};
  char word13[] = {"abcde"}, word23[] = {"fghij"};
  printf("%d\n", isItPossible(word11, word21)); // expect: 0
  printf("%d\n", isItPossible(word11, word21)); // expect: 1
  printf("%d\n", isItPossible(word11, word21)); // expect: 1
}
