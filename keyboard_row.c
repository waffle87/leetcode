// 500. Keyboard Row
#include "leetcode.h"

/*
 * given an array of strings 'words', return the words that can be typed using
 * letters of the alphabet on only one row of american keyboard like the image
 * below. note that the strings are case insensitive, both lowercased and
 * uppercased of the same letter are treated as if they are at the same row.
 */

char **findWords(char **words, int wordsSize, int *returnSize) {
  char **ans = (char **)malloc(wordsSize * sizeof(char *));
  int idx = 0, lut[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3,
                          3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
  bool same_line = true;
  for (int i = 0; i < wordsSize; i++) {
    same_line = true;
    for (int j = 0; j < strlen(words[i]); j++) {
      if (lut[(words[i][j] - 'A') % 32] != lut[(words[i][j + 1] - 'A') % 32]) {
        same_line = false;
        break;
      }
    }
    if (same_line)
      ans[idx++] = words[i];
  }
  *returnSize = idx;
  return ans;
}

int main() {
  char *w1[] = {"Hello", "Alaska", "Dad", "Peace"}, *w2[] = {"omk"},
       *w3[] = {"adsdf", "sfd"};
  int rs1, rs2, rs3;
  char **fw1 = findWords((char **)w1, ARRAY_SIZE(w1), &rs1);
  char **fw2 = findWords((char **)w2, ARRAY_SIZE(w2), &rs2);
  char **fw3 = findWords((char **)w3, ARRAY_SIZE(w3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%s ", fw1[i]); // expect: Alaska Dad
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", fw2[i]); // expect: omk
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%s ", fw3[i]); // expect: adsdf sfd
  printf("\n");
  free(fw1);
  free(fw2);
  free(fw3);
}
