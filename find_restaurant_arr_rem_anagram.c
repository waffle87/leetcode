// 2273. Find Resultant Array After Removing Anagrams
#include "leetcode.h"

/*
 * you are given a 0-indexed string array 'words' where 'words[i]' consists of
 * lowercase english letters. in one operation, select any index 'i' such that
 * '0 < i < words.length' and 'words[i - 1]' and 'words[i]' are anagrams, and
 * delete 'words[i]' from 'words'. keep performing this operation as long as yu
 * can select an index that satisfies the conditions. return 'words' after
 * performining all operations. it can be shown that selecting the indices for
 * each operation in any arbitrary order will lead to the same result. an
 * anagram is a word or phrase formed by rearranging the letters of a different
 * word or phrase using all the original letters exactly once.
 */

bool anagram(char *s, char *t) {
  int hash[26] = {0};
  if (strlen(s) != strlen(t))
    return false;
  for (int i = 0; i < strlen(s); i++)
    hash[s[i] - 'a']++;
  for (int i = 0; i < strlen(t); i++)
    hash[t[i] - 'a']--;
  for (int i = 0; i < 26; i++)
    if (hash[i])
      return false;
  return true;
}

char **removeAnagrams(char **words, int wordsSize, int *returnSize) {
  char **ans = (char **)calloc(wordsSize, sizeof(char *));
  int idx = 0;
  ans[idx++] = words[0];
  for (int i = 1; i < wordsSize; i++)
    if (!anagram(words[i - 1], words[i]))
      ans[idx++] = words[i];
  *returnSize = idx;
  return ans;
}

int main() {
  char *w1[] = {"abba", "baba", "bbaa", "cd", "cd"},
       *w2[] = {"a", "b", "c", "d", "e"};
  int rs1, rs2;
  char **ra1 = removeAnagrams((char **)w1, ARRAY_SIZE(w1), &rs1);
  char **ra2 = removeAnagrams((char **)w2, ARRAY_SIZE(w2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", ra1[i]);
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", ra2[i]);
  printf("\n");
  free(ra1);
  free(ra2);
}
