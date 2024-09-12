// 1684. Count the Number of Consistent Strings
#include "leetcode.h"

/*
 * you are given a string 'allowed' consisting of distinct characters and an
 * array of strings 'words'. a string is consistent if all characters in the
 * string appear in the string 'allowed'. return the number of consistent
 * strings in the array
 */

int countConsistentStrings(char *allowed, char **words, int wordsSize) {
  int s = 0, ans = 0;
  for (int i = 0; allowed[i]; i++)
    s |= 1 << (allowed[i] - 'a');
  for (int i = 0; i < wordsSize; i++) {
    int c = 0;
    for (int j = 0; words[i][j]; j++)
      c |= 1 << (words[i][j] - 'a');
    if (s == (c | s))
      ans++;
  }
  return ans;
}

int main() {
  char *a1 = "ab", *w1[] = {"ad", "bd", "aaab", "baa", "badab"};
  char *a2 = "abc", *w2[] = {"a", "b", "c", "ab", "ac", "bc", "abc"};
  char *a3 = "cad", *w3[] = {"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"};
  printf("%d\n",
         countConsistentStrings(a1, (char **)w1, ARRAY_SIZE(w1))); // expect: 2
  printf("%d\n",
         countConsistentStrings(a2, (char **)w2, ARRAY_SIZE(w1))); // expect: 7
  printf("%d\n",
         countConsistentStrings(a3, (char **)w3, ARRAY_SIZE(w1))); // expect: 4
}
