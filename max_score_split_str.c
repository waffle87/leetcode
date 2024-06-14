// 1422. Maximum Score After Splitting a String
#include "leetcode.h"

/*
 * given a string 's' of zeros and ones, return the maximum score after
 * splitting the string into two non-empty substrings (ie. left and right). the
 * score after splitting a string is the number of zeros in the left substring
 * plus the number of ones in the right substring.
 */

int maxScore(char *s) {
  int n = strlen(s), ans = 0;
  int *suffix_one = malloc(n * sizeof(int));
  int *prefix_zero = malloc(n * sizeof(int));
  suffix_one[n - 1] = (s[n - 1] == '1');
  for (int i = n - 2; i >= 0; i--)
    suffix_one[i] = suffix_one[i + 1] + (s[i] == '1');
  prefix_zero[0] = (s[0] == '0');
  for (int i = 1; i < n; i++)
    prefix_zero[i] = prefix_zero[i - 1] + (s[i] == '0');
  for (int i = 1; i < n; i++)
    ans = fmax(ans, suffix_one[i] + prefix_zero[i - 1]);
  return ans;
}

int main() {
  char *s1 = "011101", *s2 = "00111", *s3 = "1111";
  printf("%d\n", maxScore(s1)); // expect: 5
  printf("%d\n", maxScore(s2)); // expect: 5
  printf("%d\n", maxScore(s3)); // expect: 3
}
