// 1930. Unique Length-3 Palindromic Subsequences
#include "leetcode.h"

/*
 * given a string 's', return the number of unique palindromes of length three
 * that that are a subsequence of 's'. note that even if there are multiple ways
 * to obtain the same subsequence, it is still only counted once. a palindrome
 * is a string that reads the same forwards and backwards. a subsequence of a
 * string is a new string generated from the original string with some
 * characters (can be none) deleted without changing the relative order of thhe
 * remaining characters. for example: "ace" is a subsequence of "abcde"
 */

int countPalindromicSubsequence(char *s) {
  int n = strlen(s), ans = 0;
  bool *alpha = calloc(26, sizeof(bool));
  bool *tmp;
  for (int i = 0; i < n; i++) {
    if (alpha[s[i] - 'a'])
      continue;
    alpha[s[i] - 'a'] = 1;
    char c = s[i];
    for (int j = n - 1; j > i + 1; j--) {
      if (s[j] == s[i]) {
        tmp = calloc(26, sizeof(char));
        for (int k = i + 1; k < j; k++) {
          if (!tmp[s[k] - 'a']) {
            tmp[s[k] - 'a'] = 1;
            ans++;
          }
        }
        break;
      }
    }
  }
  return ans;
}

int main() {
  char s1[] = {"aabca"}, s2[] = {"adc"}, s3[] = {"bbcbaba"};
  printf("%d\n", countPalindromicSubsequence(s1)); // expect: 3
  printf("%d\n", countPalindromicSubsequence(s2)); // expect: 0
  printf("%d\n", countPalindromicSubsequence(s3)); // expect: 4
}
