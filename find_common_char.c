// 1002. Find Common Characters
#include "leetcode.h"

/*
 * given a string array 'words' return an array of all characters that show up
 * in all strings within the 'words' including duplicates. you may return the
 * answer in any order.
 */

#define MAX_WORD_LEN 100

char **commonChars(char **words, int wordsSize, int *returnSize) {
  int table[MAX_WORD_LEN][26] = {0}, cnt = 0;
  char **ans = (char **)malloc(MAX_WORD_LEN * sizeof(char *));
  for (int i = 0; i < MAX_WORD_LEN; i++)
    ans[i] = (char *)malloc(2 * sizeof(char));
  for (int i = 0; i < wordsSize; i++)
    for (int j = 0; j < words[i][j]; ++j)
      table[i][words[i][j] - 'a']++;
  for (int i = 0; i < 26; i++) {
    int c = 0, min = MAX_WORD_LEN + 1;
    for (int j = 0; j < wordsSize; j++)
      if (table[j][i]) {
        ++c;
        if (table[j][i] < min)
          min = table[j][i];
      }
    if (c == wordsSize && min != MAX_WORD_LEN + 1)
      for (int j = 0; j < min; ++j) {
        ans[cnt][0] = (char)(i + 'a');
        ans[cnt][1] = '\0';
        ++cnt;
      }
  }
  *returnSize = cnt;
  return ans;
}

int main() {
  char *w1[] = {"bella", "label", "roller"}, *w2[] = {"cool", "lock", "cook"};
  int rs1, rs2;
  char **cc1 = commonChars((char **)w1, ARRAY_SIZE(w1), &rs1);
  char **cc2 = commonChars((char **)w2, ARRAY_SIZE(w2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", cc1[i]);
  printf("\n"); // expect: e l l
  for (int i = 0; i < rs2; i++)
    printf("%s ", cc2[i]);
  printf("\n"); // expect: c o
  free(cc1), free(cc2);
}
