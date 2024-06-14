// 140. Word Break II
#include "leetcode.h"

/*
 * given a string 's' and a dictionary of strings 'wordDict', add spaces in 's'
 * to construct a sentence where each word is a valid dictionary word. return
 * all such possible sentences in any order. note that the same word in the
 * dictionary may be reused mutliple times in the segmentation.
 */

void dfs(char *s, char **dict, int dict_size, char **res, int *return_size,
         int *idx, int map_size, int len) {
  if (*s == '\0') {
    res[*return_size] = (char *)malloc(len * sizeof(char));
    char *head = res[*return_size];
    for (int i = 0; i < map_size; ++i) {
      int n = strlen(dict[idx[i]]);
      strcpy(head, dict[idx[i]]);
      head[n] = ' ';
      head += len++;
    }
    res[*return_size][len - 1] = '\0';
    ++(*return_size);
    return;
  }
  for (int i = 0; i < dict_size; ++i) {
    int n = strlen(dict[i]);
    if (!strncmp(s, dict[i], n)) {
      idx[map_size] = i;
      dfs(s + n, dict, dict_size, res, return_size, idx, map_size + 1,
          len + n + 1);
    }
  }
}

char **wordBreak(char *s, char **wordDict, int wordDictSize, int *returnSize) {
  char **ans = (char **)malloc(500 * sizeof(char *));
  int *idx = (int *)malloc(500 * sizeof(int));
  *returnSize = 0;
  dfs(s, wordDict, wordDictSize, ans, returnSize, idx, 0, 0);
  free(idx);
  return ans;
}

int main() {
  char *s1 = "catsanddog", *s2 = "pineapplepenapple", *s3 = "catsandog";
  char *wd1[] = {"cat", "cats", "and", "sand", "dog"},
       *wd2[] = {"apple", "pen", "applepen", "pine", "pineapple"},
       *wd3[] = {"cats", "dog", "sand", "and", "cat"};
  int rs1, rs2, rs3;
  char **wb1 = wordBreak(s1, (char **)wd1, ARRAY_SIZE(wd1), &rs1);
  char **wb2 = wordBreak(s2, (char **)wd2, ARRAY_SIZE(wd2), &rs2);
  char **wb3 = wordBreak(s3, (char **)wd3, ARRAY_SIZE(wd3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%s ", wb1[i]); // expect: "cats and dog","cat sand dog"
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", wb2[i]); // "pine apple pen apple","pineapple pen apple","pine
                           // applepen apple"
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%s ", wb3[i]); // expect: null
  printf("\n");
}
