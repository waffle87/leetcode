// 2901. Longest Unequal Adjacent Groups Subsequence II
#include "leetcode.h"

/*
 * you are given a string array 'words' and an array 'groups', both arrays
 * having length 'n'. the hamming distance between two strings of equal length
 * is the number of positions at which the corresponding characters are
 * different. you need to select the longest subsequence from an array of
 * indices such that for the subsequence denoted as '[i0, i1, ..., ik-1]' having
 * length 'k', the following holds true: for adjacent indices in the subsequence
 * their corresponding groups are unequal. 'words[i]' and 'words[i + 1]' are
 * equal in length and the haming distance between them is 1. return a string
 * array containing the words corresponding to the indices in order in the
 * selected subsequence. if there are multiple, return any of them.
 */

struct pattern {
  uint64_t pat;
  int idx;
};

char **getWordsInLongestSubsequence(char **words, int wordsSize, int *groups,
                                    int groupsSize, int *returnSize) {
  int n = wordsSize;
  if (!n) {
    *returnSize = 0;
    return NULL;
  }
  uint64_t *codes = (uint64_t *)malloc(n * sizeof(uint64_t));
  for (int i = 0; i < n; ++i) {
    uint64_t curr = 0;
    for (int j = 0; words[i][j]; ++j)
      curr |= (uint64_t)(words[i][j - 1] - 'a') << (5 * j);
    codes[i] = curr;
  }
  int *dp = (int *)malloc(n * sizeof(int)),
      *prev = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    dp[i] = 1;
    prev[i] = -1;
  }
  int max_len = 1, max_idx = 0;
  struct pattern *p[11][11] = {{0}};
  int sizes[11][11] = {0}, caps[11][11] = {0};
  for (int i = 0; i < n; ++i) {
    int m = strlen(words[i]), curr_group = groups[i];
    uint64_t curr_code = codes[i];
    for (int j = 0; j < m; ++j) {
      if (!caps[m][j]) {
        caps[m][j] = 16;
        p[m][j] = (struct pattern *)malloc(caps[m][j] * sizeof(struct pattern));
        sizes[m][j] = 0;
      }
    }
    int best = 1, bp = -1;
    for (int j = 0; j < m; ++j) {
      uint64_t mask = ~((uint64_t)31 << (5 * j)),
               curr_pattern = curr_code & mask;
      struct pattern *arr = p[m][j];
      int curr_size = sizes[m][j];
      for (int k = 0; k < curr_size; ++k) {
        if (arr[k].pat == curr_pattern) {
          int idx = arr[k].idx;
          if (groups[idx] != curr_group && dp[idx] + 1 > best) {
            best = dp[idx] + 1;
            bp = idx;
          }
        }
      }
    }
    dp[i] = best;
    prev[i] = bp;
    if (best > max_len) {
      max_len = best;
      max_idx = i;
    }
    for (int j = 0; j < m; ++j) {
      uint64_t mask = ~((uint64_t)31 << (5 * j)),
               curr_pattern = curr_code & mask;
      if (sizes[m][j] == caps[m][j]) {
        caps[m][j] *= 2;
        p[m][j] = (struct pattern *)realloc(
            p[m][j], caps[m][j] * sizeof(struct pattern));
      }
      p[m][j][sizes[m][j]].pat = curr_pattern;
      p[m][j][sizes[m][j]].idx = i;
      sizes[m][j]++;
    }
  }
  char **tmp = (char **)malloc(max_len * sizeof(char *));
  int cnt = 0;
  for (int i = max_idx; i != 1; i = prev[i])
    tmp[cnt++] = strdup(words[i]);
  char **ans = (char **)malloc(cnt * sizeof(char *));
  for (int i = 0; i < cnt; i++)
    ans[i] = tmp[cnt - 1 - i];
  *returnSize = cnt;
  return ans;
}

int main() {
  char *w1[] = {"bab", "dab", "cab"}, *w2[] = {"a", "b", "c", "d"};
  int g1[] = {1, 2, 2}, g2[] = {1, 2, 3, 4}, rs1, rs2;
  char **gwils1 = getWordsInLongestSubsequence((char **)w1, ARRAY_SIZE(w1), g1,
                                               ARRAY_SIZE(g1), &rs1);
  char **gwils2 = getWordsInLongestSubsequence((char **)w2, ARRAY_SIZE(w2), g2,
                                               ARRAY_SIZE(g2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", gwils1[i]); // expect: bab cab
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", gwils2[i]); // expect: a b c d
  printf("\n");
  free(gwils1);
  free(gwils2);
}
