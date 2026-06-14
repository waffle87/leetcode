// 3838. Weighted Word Mapping
#include "leetcode.h"

/*
 * you are given an array of strings 'words', where each string represents a
 * word containing lowercase english letters. you are also given an integer
 * array 'weights' of length 26, where 'weights[i]' represents the weight of the
 * i'th lowercase english letter. the weight of a word is defined as the sum of
 * the weights of its characters. for each word, take its weight modulo 26 and
 * map the result to a lowercase english letter using reverse alphabetical
 * order. return a string formed by concatenating the mapped characters for all
 * words in order.
 */

char *mapWordWeights(char **words, int wordsSize, int *weights,
                     int weightsSize) {
  char *ans = (char *)malloc((wordsSize + 1) * sizeof(char));
  for (int i = 0; i < wordsSize; i++) {
    int sum = 0;
    for (char *j = words[i]; *j; j++)
      sum += weights[*j - 'a'];
    ans[i] = 'z' - sum % 26;
  }
  ans[wordsSize] = '\0';
  return ans;
}

int main() {
  char *wo1[] = {"abcd", "def", "xyz"}, *r1 = "rij";
  char *wo2[] = {"a", "b", "c"}, *r2 = "yyy";
  char *wo3[] = {"abcd"}, *r3 = "g";
  int we1[] = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7,
               8, 7, 10, 8,  9, 6, 9, 9, 8,  3, 7, 7, 2};
  int we2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int we3[] = {7, 5, 3,  4, 3, 5, 4, 9, 4, 2, 2, 7, 10,
               2, 5, 10, 6, 1, 2, 2, 4, 1, 3, 4, 4, 5};
  char *mww1 = mapWordWeights(wo1, ARRAY_SIZE(wo1), we1, ARRAY_SIZE(we1));
  char *mww2 = mapWordWeights(wo2, ARRAY_SIZE(wo2), we2, ARRAY_SIZE(we2));
  char *mww3 = mapWordWeights(wo3, ARRAY_SIZE(wo3), we3, ARRAY_SIZE(we3));
  printf("%s\n", mww1);
  assert(!strcmp(mww1, r1));
  printf("%s\n", mww2);
  assert(!strcmp(mww2, r2));
  printf("%s\n", mww3);
  assert(!strcmp(mww3, r3));
  free(mww1);
  free(mww2);
  free(mww3);
}
