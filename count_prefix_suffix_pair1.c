// 3042. Count Prefix and Suffix Pairs I
#include "leetcode.h"

/*
 * you are given a 0-indexed string array 'words'. let's define a boolean
 * function 'isPrefixSuffix' that takes two strings 'str1' and 'str2'.
 * 'isPrefixSuffix()' returns true if 'str1' is both a prefix and suffix of
 * 'str2', and false otherwise. return an integer denoting the number of index
 * pairs '(i, j)' such that 'i < j' and 'isPrefixSuffix(words[i], words[j])' is
 * true.
 */

bool isPrefixAndSuffix(char *str1, char *str2) {
  int n = strlen(str1), m = strlen(str2);
  for (int i = 0, j = 0; str1[i]; i++, j++)
    if (str1[i] != str2[j])
      return false;
  for (int i = n - 1, j = m - 1; j >= 0 && i >= 0; i--, j--)
    if (str1[i] != str2[j])
      return false;
  return true;
}

int countPrefixSuffixPairs(char **words, int wordsSize) {
  int cnt = 0;
  for (int i = 0; i < wordsSize; i++)
    for (int j = i + 1; j < wordsSize; j++)
      if (isPrefixAndSuffix(words[i], words[j]))
        cnt++;
  return cnt;
}

int main() {
  char *w1[] = {"a", "aba", "ababa", "aa"},
       *w2[] = {"pa", "papa", "ma", "mama"}, *w3[] = {"abab", "ab"};
  printf("%d\n",
         countPrefixSuffixPairs((char **)w1, ARRAY_SIZE(w1))); // expect: 4
  printf("%d\n",
         countPrefixSuffixPairs((char **)w2, ARRAY_SIZE(w2))); // expect: 2
  printf("%d\n",
         countPrefixSuffixPairs((char **)w3, ARRAY_SIZE(w3))); // expect: 0
}
