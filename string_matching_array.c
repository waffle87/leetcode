// 1408. String Matching in an Array
#include "leetcode.h"

/*
 * given an array of string 'words', return all the strings in 'words' that is a
 * substring of another word. you can return the answer in any order. a
 * substring is a contiguous sequence of characters within a string.
 */

char **stringMatching(char **words, int wordsSize, int *returnSize) {
  char **ans = (char **)malloc(wordsSize * sizeof(char *));
  int k = 0;
  for (int i = 0; i < wordsSize; i++)
    for (int j = i + 1; j < wordsSize; j++)
      if (words[j] && words[i] &&
          (strstr(words[i], words[j]) || strstr(words[j], words[i]))) {
        if (strstr(words[i], words[j])) {
          ans[k] = words[j];
          k++;
          words[j] = NULL;
        } else {
          ans[k] = words[i];
          k++;
          words[i] = NULL;
        }
      }
  *returnSize = k;
  return ans;
}

int main() {
  char *w1[] = {"mass", "as", "hero", "superhero"};
  char *w2[] = {"leetcode", "et", "code"};
  char *w3[] = {"blue", "green", "bu"};
  int rs1, rs2, rs3;
  char **sm1 = stringMatching((char **)w1, ARRAY_SIZE(w1), &rs1);
  char **sm2 = stringMatching((char **)w2, ARRAY_SIZE(w2), &rs2);
  char **sm3 = stringMatching((char **)w3, ARRAY_SIZE(w3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%s ", sm1[i]); // expect: as hero
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", sm2[i]); // expect: et code
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%s ", sm3[i]); // expect: null
  printf("\n");
  free(sm1);
  free(sm2);
  free(sm3);
}
