// 1048. Longest String Chain
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * you are given an array of 'words' where each word consists of lowercase
 * english letters. 'word[a]' is a predecessor of 'word[b]' if and only if we
 * can insert exactly one letter anywhere in 'word[a]' without changing the
 * order of the other characters to make it equal to 'word[b]'. return the
 * length of the longest possible word chain with words chosen from the given
 * list of words.
 */

int cmp(const void *a, const void *b) {
  char *s1 = *(char **)a;
  char *s2 = *(char **)b;
  return strlen(s1) - strlen(s2);
}

bool strcmp_ex(char *s1, char *s2) {
  int len1 = strlen(s1), len2 = strlen(s2);
  int idx1 = 0, idx2 = 0;
  while (idx1 < len1 && idx2 < len2) {
    if (s1[idx1] == s2[idx2]) {
      idx1++;
      idx2++;
    } else {
      idx2++;
    }
  }
  if (idx1 != len1)
    return false;
  else
    return true;
}

// int longestStrChain(char **words, int words_size) {
int longestStrChain(int c, char words[][c], int words_size) {
  qsort(words, words_size, sizeof(char *), cmp);
  int *dp = malloc(words_size * sizeof(int));
  int i, j, m, n, lsc = 1;
  dp[0] = 1;
  for (i = 1; i < words_size; i++) {
    if (strlen(words[i]) == 1)
      dp[i] = 1;
    else
      break;
  }
  for (j = i; j < words_size; j++) {
    dp[j] = 1;
    for (m = j - 1; m >= 0; m--) {
      if (strlen(words[m]) == strlen(words[j]))
        continue;
      if (strlen(words[m]) < strlen(words[j]) - 1)
        break;
      if (strcmp_ex(words[m], words[j]))
        dp[j] = fmax(dp[m] + 1, dp[j]);
    }
    lsc = fmax(lsc, dp[j]);
  }
  free(dp);
  return lsc;
}

int main() {
  char w1[][4] = {"a", "b", "ba", "bca", "bda", "bdca"};
  char w2[][6] = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
  char w3[][5] = {"abcd", "dbqca"};
  printf("%d\n", longestStrChain(4, w1, 6)); // expect: 4
  printf("%d\n", longestStrChain(6, w2, 6)); // expect: 4
  printf("%d\n", longestStrChain(5, w3, 6)); // expect: 4
}
