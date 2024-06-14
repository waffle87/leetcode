// 953. Verifying an Alien Dictionary
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * in an alien language, they also use english lowercase letters but in
 * different 'order'. the 'order' of the alphabet is some permutation of
 * lowercase letters. given a sequence of 'words' written in the alien language,
 * and the 'order' of the alphabet, return 1 if and only if the given 'words'
 * are sorted lexicographically in this alien language.
 */

bool cmp(char *a, char *b, int *j) {
  int sizeA = strlen(a), sizeB = strlen(b);
  for (int i = 0; i < sizeA && i < sizeB; i++) {
    if (j[a[i] - 'a'] < j[b[i] - 'a'])
      return true;
    else if (j[a[i] - 'a'] > j[b[i] - 'a'])
      return false;
  }
  return sizeA < sizeB;
}

bool isAlienSorted(char **words, int wordsSize, char *order) {
  int j[26] = {0};
  for (int i = 0; i < 26; i++)
    j[order[i] - 'a'] = i;
  for (int i = 0; i < wordsSize - 1; i++)
    if (!cmp(words[i], words[i + 1], j))
      return false;
  return true;
}
