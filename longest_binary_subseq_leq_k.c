// 2311. Longest Binary Subsequence Less Than or Equal to K
#include "leetcode.h"

/*
 * you are given a binary string 's' and a positive integer 'k'. return the
 * length of the longest subsequence of 's' that makes up a binary number less
 * than or equal to 'k'. note the subsequence can contain leading zeros, the
 * empty string is considered to be equal to 0, and a subsequence is a string
 * that can be derived from another string by deleting some or no characters
 * without changing the order of the remaining characters.
 */

int longestSubsequence(char *s, int k) {
  int ans = 0, cost = 1, n = strlen(s);
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0' || cost <= k) {
      k -= cost * (s[i] - '0');
      ans++;
    }
    if (cost <= k)
      cost *= 2;
  }
  return ans;
}

int main() {
  char *s1 = "1001010", *s2 = "00101001";
  printf("%d\n", longestSubsequence(s1, 5)); // expect: 5
  printf("%d\n", longestSubsequence(s2, 1)); // expect: 6
}
