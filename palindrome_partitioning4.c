// 1745. Palindrome Partitioning IV
#include "leetcode.h"

/*
 * given a string 's' return true if it is possible to split the string 's' into
 * three non empty palindromic substrings. otherwise, return false. a string is
 * said to be a palindrome if it is the same string when reversed
 */

bool helper(bool **is_palindrome, int k, int a, int b) {
  if (k == 1)
    return is_palindrome[a][b];
  for (int i = a; i <= b - (k - 1); i++)
    if (is_palindrome[a][i] && helper(is_palindrome, k - 1, i + 1, b))
      return true;
  return false;
}

bool checkPartitioning(char *s) {
  int n = strlen(s);
  bool **is_palindrome = (bool **)malloc(n * sizeof(bool *));
  for (int i = 0; i < n; i++)
    is_palindrome[i] = (bool *)calloc(n, sizeof(bool));
  for (int i = 0; i < n; i++)
    is_palindrome[i][i] = true;
  for (int i = 0; i < n - 1; i++)
    is_palindrome[i][i + 1] = (s[i] == s[i + 1]);
  for (int len = 3; len <= n; len++)
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      if (s[i] == s[j])
        is_palindrome[i][j] = is_palindrome[i + 1][j - 1];
    }
  bool ans = helper(is_palindrome, 3, 0, n - 1);
  for (int i = 0; i < n; i++)
    free(is_palindrome[i]);
  free(is_palindrome);
  return ans;
}

int main() {
  char *s1 = "abcbdd", *s2 = "bcbddxy";
  printf("%d\n", checkPartitioning(s1)); // expect: 1
  printf("%d\n", checkPartitioning(s2)); // expect: 0
}
