// 2942. Find Words Containing Character
#include "leetcode.h"

/*
 * you are given a 0-indexed array of strings 'words' and a character 'x'.
 * return an array of indices representing the words that contain the character
 * 'x'. note that the returned array may be in any order.
 */

int *findWordsContaining(char **words, int wordsSize, char x, int *returnSize) {
  int *ans = (int *)malloc(wordsSize * sizeof(int)), cnt = 0;
  for (int i = 0; i < wordsSize; i++)
    for (int j = 0; words[i][j]; j++)
      if (words[i][j] == x) {
        ans[cnt++] = i;
        break;
      }
  *returnSize = cnt;
  return ans;
}

int main() {
  char *w1[] = {"leet", "code"}, *w2[] = {"abc", "bcd", "aaaa", "cbc"},
       *w3[] = {"abc", "bcd", "aaaa", "cbc"};
  int rs1, *fwc1 = findWordsContaining((char **)w1, ARRAY_SIZE(w1), 'e', &rs1);
  int rs2, *fwc2 = findWordsContaining((char **)w2, ARRAY_SIZE(w2), 'a', &rs2);
  int rs3, *fwc3 = findWordsContaining((char **)w3, ARRAY_SIZE(w3), 'z', &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fwc1[i]); // expect: 0 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fwc2[i]); // expect: 0 2
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", fwc3[i]); // expect: null
  printf("\n");
  free(fwc1);
  free(fwc2);
  free(fwc3);
}
