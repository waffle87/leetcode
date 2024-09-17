// 884. Uncommon Words from Two Sentences
#include "leetcode.h"

/*
 * a sentence is a string of single space separated words where each word
 * consists of only lowercase letters. a word is uncommon if it appears exactly
 * once in the sentences, and does not appear in the other sentence. given two
 * sentences 's1' and 's2', return a list of all the uncommon words. you may
 * return the answer in any order
 */

struct word_hash {
  char str[32];
  int cnt;
  UT_hash_handle hh;
};

char **uncommonFromSentences(char *s1, char *s2, int *returnSize) {
  struct word_hash *h = NULL, *m = NULL;
  char *s;
  int n = 0, start_idx = 0, idx = 0, cnt = 0;
  for (int i = 0; i < 2; i++) {
    s = !i ? s1 : s2;
    n = strlen(s);
    start_idx = 0;
    idx = 0;
    do {
      if (s[idx] == ' ' || idx == n - 1) {
        cnt = idx - start_idx;
        if (idx == n - 1)
          cnt++;
        char *curr = (char *)calloc(cnt + 1, sizeof(char));
        strncpy(curr, &s[start_idx], cnt);
        curr[cnt] = '\0';
        HASH_FIND_STR(h, curr, m);
        if (!m) {
          m = (struct word_hash *)calloc(1, sizeof(struct word_hash));
          strncpy(m->str, curr, cnt);
          HASH_ADD_STR(h, str, m);
        }
        m->cnt++;
        start_idx = idx + 1;
      }
      idx++;
    } while (idx < n);
    cnt = n - start_idx;
  }
  char **ans = (char **)calloc(100, sizeof(char *));
  int ans_idx = 0;
  for (m = h; m; m = h->hh.next) {
    if (m->cnt == 1) {
      ans[ans_idx] = (char *)calloc(strlen(m->str) + 1, sizeof(char));
      strcpy(ans[ans_idx++], m->str);
    }
  }
  *returnSize = ans_idx;
  return ans;
}

int main() {
  char *s11 = "this apple is sweet", *s21 = "this apple is sour";
  char *s12 = "apple apple", *s22 = "banana";
  int rs1, rs2;
  char **ufs1 = uncommonFromSentences(s11, s21, &rs1);
  char **ufs2 = uncommonFromSentences(s12, s22, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", ufs1[i]); // expect: sweet sour
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", ufs2[i]); // expect: banana
  printf("\n");
  free(ufs1), free(ufs2);
}
