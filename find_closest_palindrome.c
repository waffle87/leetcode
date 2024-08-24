// 564. Find the Closest Palindrome
#include "leetcode.h"

/*
 * given a string 'n' representing an integer, return the closest integer (not
 * including itself), which is a palindrome. if there is a tie, return the
 * smaller one. the closest is defined as the absolute difference minimised
 * between two integers.
 */

static inline void substr(char *str, char *sub, int start, int size) {
  memcpy(sub, &str[start], size);
  sub[size] = '\0';
}

static long get_palindrome(long prefix, bool even_size) {
  long long res = prefix;
  if (!even_size)
    prefix /= 10;
  while (prefix) {
    res = res * 10 + prefix % 10;
    prefix /= 10;
  }
  return res;
}

char *nearestPalindromic(char *n) {
  int len = strlen(n);
  if (len == 1) {
    n[0] = (((n[0] - '0') - 1) + '0');
    return n;
  }
  char *ans = (char *)malloc((len + 3) * sizeof(char));
  bool even_size = len % 2 ? false : true;
  int prefix_size = even_size ? len / 2 - 1 : len / 2;
  char *prefix_sub = (char *)malloc((prefix_size + 2) * sizeof(char));
  substr(n, prefix_sub, 0, prefix_size + 1);
  char *n_end;
  long long prefix = strtoll(prefix_sub, &n_end, 10);
  long long combinations[5] = {0};
  combinations[0] = get_palindrome(prefix, even_size);
  combinations[1] = get_palindrome(prefix - 1, even_size);
  combinations[2] = get_palindrome(prefix + 1, even_size);
  combinations[3] = (long long)(pow(10, len - 1) - 1);
  combinations[4] = (long long)(pow(10, len) + 1);
  long long diff = INT64_MAX, res = 0, orig_num = strtol(n, &n_end, 10);
  for (int i = 0; i < 5; i++) {
    long long curr = orig_num - combinations[i];
    curr = abs((int)curr);
    if (!curr)
      continue;
    else if (curr == diff && combinations[i] > res)
      continue;
    else if (fmin(curr, diff) == curr) {
      res = combinations[i];
      diff = curr;
    }
  }
  sprintf(ans, "%lld", res);
  free(prefix_sub);
  return ans;
}

int main() {
  char *n1 = "123", *n2 = "1";
  printf("%s\n", nearestPalindromic(n1)); // expect: 121
  printf("%s\n", nearestPalindromic(n2)); // expect: 0
}
