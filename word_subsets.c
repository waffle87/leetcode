// 916. Word Subsets
#include "leetcode.h"

/*
 * you are given two string arrays 'words1' and 'words2'. a string 'b' is a
 * subset of string 'a' if every letter in 'b' occurs in 'a' including
 * multiplicity. a string 'a' from 'words1' is universal if for every string 'b'
 * in 'words2', 'b' is a subset of 'a'. return an array of all the universal
 * strins in 'words1'. you may return the answer in any order.
 */

char **wordSubsets(char **words1, int words1Size, char **words2, int words2Size,
                   int *returnSize) {
  int max_freq[26] = {0}, tmp_freq[26];
  for (int i = 0; i < words2Size; ++i) {
    memset(tmp_freq, 0, sizeof(tmp_freq));
    for (int j = 0; words2[i][j] != '\0'; ++j)
      tmp_freq[words2[i][j] - 'a']++;
    for (int j = 0; j < 26; ++j)
      max_freq[j] = fmax(max_freq[j], tmp_freq[j]);
  }
  char **ans = (char **)malloc(words1Size * sizeof(char *));
  *returnSize = 0;
  for (int i = 0; i < words1Size; ++i) {
    memset(tmp_freq, 0, sizeof(tmp_freq));
    for (int j = 0; words1[i][j] != '\0'; ++j)
      tmp_freq[words1[i][j] - 'a']++;
    bool universal = true;
    for (int j = 0; j < 26; ++j)
      if (max_freq[j] > tmp_freq[j]) {
        universal = false;
        break;
      }
    if (universal)
      ans[(*returnSize)++] = words1[i];
  }
  return ans;
}

int main() {
  char *w11[] = {"amazon", "apple", "facebook", "google", "leetcode"},
       *w21[] = {"e", "o"};
  char *w12[] = {"amazon", "apple", "facebook", "google", "leetcode"},
       *w22[] = {"l", "e"};
  int rs1, rs2;
  char **ws1 = wordSubsets((char **)w11, ARRAY_SIZE(w11), (char **)w21,
                           ARRAY_SIZE(w21), &rs1);
  char **ws2 = wordSubsets((char **)w12, ARRAY_SIZE(w12), (char **)w22,
                           ARRAY_SIZE(w22), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", ws1[i]); // expect: ["facebook","google","leetcode"]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", ws2[i]); // expect: ["apple","google","leetcode"]
  printf("\n");
  free(ws1), free(ws2);
}
