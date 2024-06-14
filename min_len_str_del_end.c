// 1750. Minimum Length of String After Deleting Similar Ends
#include "leetcode.h"

/*
 * given a string 's' consisting of only characters a, b, and c you are asked to
 * apply the following algorithm on the string any number of times. first, pick
 * a non-empty prefix from the string 's' where all the characters in the prefix
 * are equal. next, pick a non-empty suffix from the string 's' where all the
 * characters in the suffix are equal. the prefix and the suffix should not
 * intersect at any index. the characters from the prefix and the suffix must be
 * the same. delete both the prefix and the suffix. return the minimum length of
 * 's' after performining the above operation any number of times.
 */

int minimumLength(char *s) {
  int n = strlen(s);
  int left = 0, right = n - 1;
  while (left < n && right > left && s[left] == s[right]) {
    char c = s[left];
    while (s[left] == c)
      left++;
    while (right > left && s[right] == c)
      right--;
  }
  return right - left + 1;
}

int main() {
  char *s1 = "ca", *s2 = "cabaabac", *s3 = "aabccabba";
  printf("%d\n", minimumLength(s1)); // expect: 2
  printf("%d\n", minimumLength(s2)); // expect: 0
  printf("%d\n", minimumLength(s3)); // expect: 3
}
