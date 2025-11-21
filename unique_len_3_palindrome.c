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
  int n = strlen(s), first[26], last[26];
  memset(first, n, sizeof(first));
  memset(last, -1, sizeof(last));
  for (int i = 0; i < n; i++) {
    int c = s[i] - 'a';
    if (i < first[c])
      first[c] = i;
    last[c] = i;
  }
  int ans = 0;
  for (int c = 0; c < 26; c++) {
    int l = first[c], r = last[c];
    if (r - l < 2)
      continue;
    bool memo[26] = {false};
    for (int i = l + 1; i < r; i++) {
      int idx = s[i] - 'a';
      if (!memo[idx]) {
        memo[idx] = true;
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  char *s1 = "aabca", *s2 = "adc", *s3 = "bbcbaba";
  printf("%d\n", countPalindromicSubsequence(s1)); // expect: 3
  printf("%d\n", countPalindromicSubsequence(s2)); // expect: 0
  printf("%d\n", countPalindromicSubsequence(s3)); // expect: 4
}
