#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check(char *word, char *lookup, char *q) {
  memset(lookup, -1, 26);
  for (int i = 0; word[i] != '\0'; ++i) {
    if (lookup[word[i] - 'a'] == -1)
      lookup[word[i] - 'a'] = i;
    if (q[i] != lookup[word[i] - 'a'])
      return false;
  }
  return true;
}

// note the returned array must be malloc'd (assume caller free()'s)

char **findAndReplacePattern(char **words, int wordsSize, char *pattern,
                             int *returnSize) {
  char lookup[26];
  memset(lookup, -1, 26);
  char q[50] = {0};
  char **ans = malloc(sizeof(char **) * wordsSize);
  size_t len = strlen(pattern);
  for (int i = 0; i < len; ++i) {
    if (lookup[pattern[i] - 'a'] == -1)
      lookup[pattern[i] - 'a'] = i;
    q[i] = lookup[pattern[i] - 'a'];
  }
  int sz = 0;
  for (int i = 0; i < wordsSize; ++i) {
    if (check(words[i], lookup, q)) {
      char *k = malloc(sizeof(char) * (len + 1));
      memcpy(k, words[i], len + 1);
      ans[sz++] = k;
    }
  }
  *returnSize = sz;
  return ans;
}

int main() {
  char *words1[] = {"abc", "deq", "mee", "aqq", "dkd", "ccc"},
       *words2[] = {"a", "b", "c"};
  char pattern1[] = {"abb"}, pattern2[] = {"a"};
}
