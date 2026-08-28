// 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
#include "leetcode.h"

/*
 * you are given two strings 's' and 'target', each of length 'n', consisting of
 * lowercase english letters. return the lexicographically smallest string that
 * is both a palindromic permutation of 's' and strictly greater than 'target'.
 * if no such permutation exists, return an empty string.
 */

char *lexPalindromicPermutation(char *s, char *target) {
  int n = strlen(s);
  if (n == 1) {
    if (strcmp(s, target) > 0) {
      char *result = (char *)malloc(2);
      strcpy(result, s);
      return result;
    }
    return "";
  }

  int cnt[26] = {0};
  for (int i = 0; i < n; i++)
    cnt[s[i] - 'a']++;
  char odd_char = '\0';
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2 == 1) {
      if (odd_char != '\0')
        return "";
      odd_char = 'a' + i;
    }
    cnt[i] /= 2;
  }
  char *prefix = (char *)malloc((n / 2 + 1) * sizeof(char));
  int prefix_len = 0;
  prefix[0] = '\0';
  for (int i = 0; i < n / 2; i++) {
    bool found = false;
    for (int j = 0; j < 26; j++) {
      if (!cnt[j])
        continue;
      cnt[j]--;
      char *left = (char *)malloc((n / 2 + 2) * sizeof(char));
      int left_len = 0;
      strcpy(left, prefix);
      left_len = prefix_len;
      left[left_len++] = 'a' + j;
      for (int k = 25; k >= 0; k--)
        for (int m = 0; m < cnt[k]; m++)
          left[left_len++] = 'a' + k;
      left[left_len] = '\0';
      int palindrome_len = left_len * 2 + 1;
      char *palindrome = (char *)malloc((palindrome_len + 1) * sizeof(char));
      strcpy(palindrome, left);
      int pos = left_len;
      if (odd_char != '\0')
        palindrome[pos++] = odd_char;
      for (int k = left_len - 1; k >= 0; k--)
        palindrome[pos++] = left[k];
      palindrome[pos] = '\0';
      if (strcmp(palindrome, target) > 0) {
        prefix[prefix_len++] = 'a' + j;
        prefix[prefix_len] = '\0';
        found = true;
        free(left);
        free(palindrome);
        break;
      } else {
        cnt[j]++;
        free(left);
        free(palindrome);
      }
    }
    if (!found) {
      free(prefix);
      return "";
    }
    if (prefix[i] > target[i]) {
      char *left = (char *)malloc((n / 2 + 1) * sizeof(char));
      strcpy(left, prefix);
      int left_len = prefix_len;
      for (int j = 0; j < 26; j++)
        for (int k = 0; k < cnt[j]; k++)
          left[left_len++] = 'a' + j;
      left[left_len] = '\0';
      int palindrome_len = left_len * 2 + 1;
      char *palindrome = (char *)malloc((palindrome_len + 1) * sizeof(char));
      strcpy(palindrome, left);
      int pos = left_len;
      if (odd_char != '\0')
        palindrome[pos++] = odd_char;
      for (int k = left_len - 1; k >= 0; k--)
        palindrome[pos++] = left[k];
      palindrome[pos] = '\0';
      free(prefix);
      free(left);
      return palindrome;
    }
  }
  int ans_len = prefix_len * 2 + 1;
  char *ans = (char *)malloc((ans_len + 1) * sizeof(char));
  strcpy(ans, prefix);
  int pos = prefix_len;
  if (odd_char != '\0')
    ans[pos++] = odd_char;
  for (int k = prefix_len - 1; k >= 0; k--)
    ans[pos++] = prefix[k];
  ans[pos] = '\0';
  free(prefix);
  return ans;
}

int main() {
  char *s1 = "baba", *t1 = "abba", *r1 = "baab";
  char *s2 = "bab", *t2 = "bbaa", *r2 = "";
  char *s3 = "abc", *t3 = "abb", *r3 = "";
  char *lpp1 = lexPalindromicPermutation(s1, t1);
  char *lpp2 = lexPalindromicPermutation(s2, t2);
  char *lpp3 = lexPalindromicPermutation(s3, t3);
  printf("%s\n", lpp1);
  assert(!strcmp(lpp1, r1));
  printf("%s\n", lpp2);
  assert(!strcmp(lpp2, r2));
  printf("%s\n", lpp3);
  assert(!strcmp(lpp3, r3));
}
