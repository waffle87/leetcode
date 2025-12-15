// 943. Find the Shortest Superstring
#include "leetcode.h"

/*
 * given an array of strings 'words', return the smallest string that contains
 * each string in 'words' as a substring. if there multiple valid strings of the
 * smallest length, return any of them. you may assume that no string in 'words'
 * is a substring of another string in 'words'.
 */

struct connection {
  char *suffix;
  int overlap;
};

struct dp_state {
  int total_len;
  int prev;
};

struct connection connect_strings(const char *w1, const char *w2) {
  int n = strlen(w1), m = strlen(w2);
  struct connection res = {.overlap = 0};
  for (int i = 0; i <= n; i++) {
    if (!i) {
      res.suffix = (char *)malloc((m + 1) * sizeof(char));
      strcpy(res.suffix, w2);
      res.overlap = 0;
    } else if (i <= m && !strncmp(w1 + n - i, w2, i))
      if (i > res.overlap) {
        res.overlap = i;
        free(res.suffix);
        res.suffix = (char *)malloc(m - i + 1);
        strcpy(res.suffix, w2 + i);
      }
  }
  return res;
}

void generate_permutation(int *indices, int cnt, int *p1, int *p2,
                          int *perm_cnt) {
  *perm_cnt = 0;
  for (int i = 0; i < cnt; i++)
    for (int j = 0; j < cnt; j++)
      if (i != j) {
        p1[*perm_cnt] = indices[i];
        p2[*perm_cnt] = indices[j];
        (*perm_cnt)++;
      }
}

char *shortestSuperstring(char **words, int wordsSize) {
  int total = 1 << wordsSize;
  struct dp_state **dp =
      (struct dp_state **)malloc(total * sizeof(struct dp_state *));
  for (int i = 0; i < total; i++) {
    dp[i] = (struct dp_state *)malloc(wordsSize * sizeof(struct dp_state));
    for (int j = 0; j < wordsSize; j++) {
      dp[i][j].total_len = INT_MAX;
      dp[i][j].prev = -1;
    }
  }
  for (int i = 0; i < wordsSize; i++) {
    int mask = 1 << i;
    dp[mask][i].total_len = strlen(words[i]);
    dp[mask][i].prev = -1;
  };
  struct connection **conns =
      (struct connection **)malloc(wordsSize * sizeof(struct connection *));
  for (int i = 0; i < wordsSize; i++) {
    conns[i] =
        (struct connection *)malloc(wordsSize * sizeof(struct connection));
    for (int j = 0; j < wordsSize; j++)
      if (i != j)
        conns[i][j] = connect_strings(words[i], words[j]);
  }
  for (int mask = 1; mask < total; mask++) {
    int *indices = (int *)malloc(wordsSize * sizeof(int)), cnt = 0;
    for (int j = 0; j < wordsSize; j++)
      if (mask & (1 << j))
        indices[cnt++] = j;
    if (cnt < 2)
      continue;
    int *p1 = (int *)malloc(cnt * cnt * sizeof(int));
    int *p2 = (int *)malloc(cnt * cnt * sizeof(int));
    int perm_cnt;
    generate_permutation(indices, cnt, p1, p2, &perm_cnt);
    free(indices);
    for (int p = 0; p < perm_cnt; p++) {
      int j = p1[p], k = p2[p], prev_mask = mask ^ (1 << j);
      if (dp[prev_mask][k].total_len == INT_MAX)
        continue;
      int new_len = dp[prev_mask][k].total_len + conns[k][j].overlap;
      if (new_len < dp[mask][j].total_len) {
        dp[mask][j].total_len = new_len;
        dp[mask][j].prev = k;
      }
    }
    free(p1);
    free(p2);
  }
  int final_mask = total - 1, best_len = INT_MAX, prev_word = -1;
  for (int i = 0; i < wordsSize; i++) {
    if (dp[final_mask][i].total_len < best_len) {
      best_len = dp[final_mask][i].total_len;
      prev_word = i;
    }
  }
  int mask = final_mask, curr = prev_word, prev = dp[mask][curr].prev,
      total_len = best_len;
  char *ans = (char *)malloc((total_len + 1) * sizeof(char));
  ans[0] = '\0';
  char **parts = (char **)malloc(wordsSize * sizeof(char *));
  int part_cnt = 0;
  while (prev != -1) {
    parts[part_cnt++] = strdup(conns[prev][curr].suffix);
    mask ^= (1 << curr);
    curr = prev;
    prev = dp[mask][curr].prev;
  }
  strcpy(ans, words[curr]);
  for (int i = part_cnt - 1; i >= 0; i--) {
    strcat(ans, parts[i]);
    free(parts[i]);
  }
  free(parts);
  for (int i = 0; i < wordsSize; i++) {
    for (int j = 0; j < wordsSize; j++)
      if (i != j)
        free(conns[i][j].suffix);
    free(conns[i]);
  }
  free(conns);
  for (int i = 0; i < total; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  char *w1[] = {"alex", "loves", "leetcode"};
  char *w2[] = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
  char *ss1 = shortestSuperstring(w1, ARRAY_SIZE(w1));
  char *ss2 = shortestSuperstring(w2, ARRAY_SIZE(w2));
  printf("%s\n", ss1); // expect: alexlovesleetcode
  printf("%s\n", ss2); // expect: gctaagttcatgcatc
  free(ss1);
  free(ss2);
}
