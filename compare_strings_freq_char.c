// 1170. Compare Strings by Frequency of the Smallest Character
#include "leetcode.h"

/*
 * let the function 'f(s)' be the frequency of the lexicographically smallest
 * character in a non empty string 's'. for example, if 's = dcce' then 'f(s) =
 * 2' because the lexicographically smallest character is 'c', which has a
 * frequency of 2. you are given an array of strings 'words' and another array
 * of query strings 'queries'. for each query 'queries[i]', count the number of
 * words in 'words' such that 'f(queries[i]) < f(w)' for each 'w' in 'words'.
 * return an integer array 'answer' where each 'answer[i]' is the answer to the
 * i'th query
 */

int lex_freq(char *w) {
  int *map = (int *)calloc('z' - 'a' + 1, sizeof(int)), res;
  char smallest = 'z';
  for (int i = 0; w[i]; i++) {
    map[w[i] - 'a']++;
    smallest = fmin(smallest, w[i]);
  }
  res = map[smallest - 'a'];
  free(map);
  return res;
}

int *numSmallerByFrequency(char **queries, int queriesSize, char **words,
                           int wordsSize, int *returnSize) {
  int *word_freq = (int *)malloc(wordsSize * sizeof(int));
  int *ans = (int *)calloc(queriesSize, sizeof(int)), freq;
  *returnSize = queriesSize;
  for (int i = 0; i < wordsSize; i++)
    word_freq[i] = lex_freq(words[i]);
  for (int i = 0; i < queriesSize; i++) {
    freq = lex_freq(queries[i]);
    for (int j = 0; j < wordsSize; j++)
      if (freq < word_freq[j])
        ans[i]++;
  }
  free(word_freq);
  return ans;
}

int main() {
  char *q1[] = {"cbd"}, *q2[] = {"bbb", "cc"};
  char *w1[] = {"zaaaz"}, *w2[] = {"a", "aa", "aaa", "aaaa"};
  int rs1, rs2;
  int *nsbf1 = numSmallerByFrequency((char **)q1, ARRAY_SIZE(q1), (char **)w1,
                                     ARRAY_SIZE(w1), &rs1);
  int *nsbf2 = numSmallerByFrequency((char **)q2, ARRAY_SIZE(q2), (char **)w2,
                                     ARRAY_SIZE(w2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", nsbf1[i]); // expect: 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", nsbf2[i]); // expect: 1 2
  printf("\n");
  free(nsbf1), free(nsbf2);
}
