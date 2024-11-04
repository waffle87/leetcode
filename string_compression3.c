// 3163. String Compression III
#include "leetcode.h"

/*
 * given a string 'word', compress it using the following algorithm: begin with
 * an empty string 'comp'. while 'word' is not empty, use the following
 * operation: remove a maximum length prefix of 'word' made of a single
 * character 'c' repeating at most 9 times. append the length of the prefix
 * followed by 'c' to 'comp'. return the string 'comp'
 */

char *compressedString(char *word) {
  int n = strlen(word), cnt = 1, idx = 0;
  char *comp = (char *)calloc(2 * n + 1, sizeof(char));
  for (int i = 0; i < n; i++) {
    if (i == n || word[i] != word[i + 1] || cnt == 9) {
      comp[idx] = cnt + '0';
      idx++;
      comp[idx] = word[i];
      idx++;
      cnt = 1;
    } else
      cnt++;
  }
  comp[idx] = '\0';
  return comp;
}

int main() {
  char *w1 = "abcde", *w2 = "aaaaaaaaaaaaaabb";
  char *cs1 = compressedString(w1);
  char *cs2 = compressedString(w2);
  printf("%s\n", cs1); // expect: 1a1b1c1d1e
  printf("%s\n", cs2); // expect: 9a5a2b
  free(cs1), free(cs2);
}
