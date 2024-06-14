// 139. Word Break
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string 's' and a dictionary of strings 'word_dict', return 'true' if
 * 's' can be segmented into a space-separated sequence of one or more
 * dictionary words. note that the same word in the dictionary may be reused
 * multiple times in the segmentation.
 */

bool process(char *s, char **word_dict, int word_dict_size, int *word_dict_len,
             int len) {
  bool res = false;
  if (!len)
    return true;
  for (int i = 0; i < word_dict_size; i++)
    if (!strncmp(s, word_dict[i], word_dict_len[i]))
      if (process(&s[word_dict_len[i]], word_dict, word_dict_size,
                  word_dict_len, len - word_dict_len[i])) {
        res = true;
        break;
      }
  return res;
}

static int string_compare(const void *p1, const void *p2) {
  return strlen(*(char **)p1) - strlen(*(char **)p2);
}

bool wordBreak(char *s, char **word_dict, int word_dict_size) {
  int i, j, n = strlen(s);
  bool *flag = (bool *)calloc(n + 1, sizeof(bool));
  qsort(word_dict, word_dict_size, sizeof(char *), string_compare);
  int *word_dict_len = (int *)malloc(word_dict_size * sizeof(int));
  for (i = 0; i < word_dict_size; i++)
    word_dict_len[i] = strlen(word_dict[i]);
  int size, begin;
  flag[0] = true;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < word_dict_size; j++) {
      if (word_dict_len[j] > i)
        break;
      else {
        begin = i - word_dict_len[j];
        if (!strncmp(word_dict[j], &s[begin], word_dict_len[j]))
          if (flag[begin]) {
            flag[i] = true;
            break;
          }
      }
    }
  }
  bool ans = flag[n];
  free(flag), free(word_dict_len);
  return ans;
}

int main() {
  char s1[] = {"leetcode"}, s2[] = {"applepenapple"}, s3[] = {"catsanddog"};
  char wd1[2][4] = {{"leet"}, {"code"}}, wd2[2][5] = {{"apple"}, {"pen"}},
       wd3[5][4] = {{"cats"}, {"dog"}, {"sand"}, {"and"}, {"cat"}};
  printf("%d\n", wordBreak(s1, wd1, 2)); // expect: 1
  printf("%d\n", wordBreak(s2, wd2, 2)); // expect: 1
  printf("%d\n", wordBreak(s3, wd3, 5)); // expect: 0
}
