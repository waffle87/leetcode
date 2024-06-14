// 1897. Redistribute Characters to Make All Strings Equal
#include "leetcode.h"

/*
 * given an array of strings 'words' in one operation, pick two distinct indices
 * 'i' and 'j' where 'words[i]' is a non empty string and ove any character from
 * words[i] to any position in 'words[j]'. return 1 if you can make every string
 * in 'words' equal using any number of operations, and 0 otherwise.
 */

bool makeEqual(char **words, int words_size) {
  int n = words_size;
  int *alpha = calloc(26, sizeof(int));
  for (int i = 0; i < n; i++) {
    int l = strlen(words[i]);
    for (int j = 0; j < l; j++)
      alpha[words[i][j] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
    if (alpha[i] % n)
      return false;
  return true;
}

int main() {
  char **w1 = {"abc", "aabc", "bc"}, **w2 = {"ab", "a"};
  printf("%d\n", makeEqual(w1, ARRAY_SIZE(w1))); // expect: 1
  printf("%d\n", makeEqual(w2, ARRAY_SIZE(w2))); // expect: 0
}
