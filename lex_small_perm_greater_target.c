// 3720. Lexicographically Smallest Permutation Greater Than Target
#include "leetcode.h"

/*
 * you are given two strings 's' and 'target', both having legnth 'n',
 * consisting of lowercase english letters. return the lexicographically
 * smallest permutation of 's' that is strictly greater than 'target'. if no
 * permutation of 's' is lexicographically strictly greater than 'target',
 * return an empty string.
 */

char *get_min_str(int *cnt) {
  int total = 0, idx = 0;
  for (int i = 0; i < 26; i++)
    total += cnt[i];
  char *res = (char *)malloc((total + 1) * sizeof(char));
  for (int i = 0; i < 26; i++)
    for (int k = 0; k < cnt[i]; k++)
      res[idx++] = 'a' + i;
  res[idx] = '\0';
  return res;
}

char *lexGreaterPermutation(char *s, char *target) {
  int n = strlen(s), cnt[26] = {0};
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
    cnt[target[i] - 'a']--;
  }
  char *tmp = strdup(target);
  for (int i = n - 1; i >= 0; i--) {
    int b = tmp[i] - 'a';
    cnt[b]++;
    int min_val = cnt[0];
    for (int k = 1; k < 26; k++)
      min_val = fmin(min_val, cnt[k]);
    if (min_val < 0)
      continue;
    for (int j = b + 1; j < 26; j++) {
      if (cnt[j] > 0) {
        cnt[j]--;
        tmp[i] = 'a' + j;
        tmp[i + 1] = '\0';
        char *suffix = get_min_str(cnt);
        char *ans =
            (char *)malloc((strlen(tmp) + strlen(suffix) + 1) * sizeof(char));
        strcpy(ans, tmp);
        strcat(ans, suffix);
        free(suffix);
        free(tmp);
        return ans;
      }
    }
  }
  free(tmp);
  return strdup("");
}

int main() {
  char *s1 = "abc", *t1 = "bba", *r1 = "bca";
  char *s2 = "leet", *t2 = "code", *r2 = "eelt";
  char *s3 = "baba", *t3 = "bbaa", *r3 = "";
  char *lgp1 = lexGreaterPermutation(s1, t1);
  char *lgp2 = lexGreaterPermutation(s2, t2);
  char *lgp3 = lexGreaterPermutation(s3, t3);
  printf("%s\n", lgp1);
  assert(!strcmp(lgp2, r2));
  printf("%s\n", lgp2);
  assert(!strcmp(lgp2, r2));
  printf("%s\n", lgp3);
  assert(!strcmp(lgp3, r3));
  free(lgp1);
  free(lgp2);
  free(lgp3);
}
