// 1255. Maximum Score Words Formed by Letters
#include "leetcode.h"

/*
 * given a list of 'words' list of single 'letters' (potentially repeating), and
 * 'score' of every character. return the maximum score of any valid set of
 * words formed by using the given letters ('words[i]' cannot be used two or
 * more times). it is not necessary to use all characters in 'letters' and each
 * letter can only be used once. score of letters a through z is given by
 * 'score[i]' respectively.
 */

struct pair {
  bool valid;
  int len;
  int score;
};

int process(char *str, int *hash, struct pair *p, int idx, bool *no_add) {
  if (!(*no_add)) {
    for (int i = 0; i < p[idx].len; i++)
      hash[str[i] - 'a']++;
  } else {
    for (int i = 0; i < p[idx].len; i++) {
      if (!hash[str[i] - 'a']) {
        for (int j = 0; j < i; j++)
          hash[str[j] - 'a']++;
        return 0;
      }
      hash[str[i] - 'a']--;
    }
    *no_add = false;
  }
  return p[idx].score;
}

void dfs(char **words, int wordsSize, int *hash, struct pair *p, int *cnt,
         int *res, int idx) {
  if (idx == wordsSize) {
    *res = fmax(*cnt, *res);
    return;
  }
  for (int i = idx; i < wordsSize; i++) {
    bool no_add = true;
    if (p[i].valid)
      *cnt += process(words[i], hash, p, i, &no_add);
    dfs(words, wordsSize, hash, p, cnt, res, i + 1);
    if (!no_add)
      *cnt -= process(words[i], hash, p, i, &no_add);
  }
}

int maxScoreWords(char **words, int wordsSize, char *letters, int lettersSize,
                  int *score, int scoreSize) {
  int hash[26] = {0}, cnt = 0, ans = 0;
  for (int i = 0; i < lettersSize; i++)
    hash[letters[i] - 'a']++;
  struct pair *p = (struct pair *)calloc(wordsSize, sizeof(struct pair));
  for (int i = 0; i < wordsSize; i++) {
    int n = strlen(words[i]), res = 1, tmp = 0;
    p[i].len = n;
    for (int j = 0; j < n; j++) {
      tmp += score[words[i][j] - 'a'];
      if (!hash[words[i][j] - 'a']) {
        res = 0;
        break;
      }
    }
    p[i].valid = res;
    p[i].score = !p[i].valid ? 0 : tmp;
  }
  dfs(words, wordsSize, hash, p, &cnt, &ans, 0);
  free(p);
  return ans;
}

int main() {
  char *w1[] = {"dog", "cat", "dad", "good"},
       *w2[] = {"xxxz", "ax", "bx", "cx"}, *w3[] = {"leetcode"},
       *l1[] = {"a", "a", "c", "d", "d", "d", "g", "o", "o"},
       *l2[] = {"z", "a", "b", "c", "x", "x", "x"},
       *l3[] = {"l", "e", "t", "c", "o", "d"};
  int s1[] = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
              0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      s2[] = {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10},
      s3[] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0,
              0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  printf("%d\n",
         maxScoreWords((char **)w1, ARRAY_SIZE(w1), (char *)l1, ARRAY_SIZE(l1),
                       s1, ARRAY_SIZE(s1))); // expect: 23
  printf("%d\n",
         maxScoreWords((char **)w2, ARRAY_SIZE(w2), (char *)l2, ARRAY_SIZE(l2),
                       s2, ARRAY_SIZE(s2))); // expect: 27
  printf("%d\n",
         maxScoreWords((char **)w3, ARRAY_SIZE(w3), (char *)l3, ARRAY_SIZE(l3),
                       s3, ARRAY_SIZE(s3))); // expect: 0
}
