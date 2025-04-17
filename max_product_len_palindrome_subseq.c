// 2002. Maximum Product of the Length of Two Palindromic Subsequences
#include "leetcode.h"

/*
 * given a string 's', find two disjoint palindromic subsequences of 's' such
 * that the product of their lengths is maximised. the two subsequences are
 * disjoint if they do not both pick a character at the same index. return the
 * maximum possible product of the lengths of the two palindromic subsequences.
 * a subsequence is a string that can be derived from another string by deleting
 * some or none of its characters without changing the ordering of the remaining
 * characters. a string is palindromic if it reads the same forward and backward
 */

int maxProduct(char *s) {
  int n = strlen(s), *bits = (int *)calloc(1 << n, sizeof(int));
  for (int i = 1; i < 1 << n; i++)
    bits[i] = bits[i >> 1] + (i & 1);
  for (int i = (1 << n) - 1; i >= 0; i--) {
    int l = 0, r = n - 1;
    while (l < r) {
      while (l < n && !(i & (1 << l)))
        l++;
      while (r >= 0 && !(i & (1 << r)))
        r--;
      if (l < r && s[l] != s[r]) {
        bits[i] = 0;
        break;
      }
      l++, r--;
    }
  }
  int ans = 1;
  for (int i = (1 << n) - 1; i > 0; i--)
    if (bits[i])
      for (int j = (i + 1) & ~i; j < 1 << n; j = ((j | i) + 1) & ~i)
        if (bits[j])
          ans = fmax(ans, bits[i] * bits[j]);
  return ans;
}

int main() {
  char *s1 = "leetcodecom", *s2 = "bb", *s3 = "accbcaxxcxx";
  printf("%d\n", maxProduct(s1)); // expect: 9
  printf("%d\n", maxProduct(s2)); // expect: 1
  printf("%d\n", maxProduct(s3)); // expect: 25
}
