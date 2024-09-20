// 214. Shortest Palindrome
#include "leetcode.h"

/*
 * you are given a string 's'. you can convert 's' to a palindrome by adding
 * characters in front of it. return the shortest palindrome you can find by
 * performing this transformation.
 */

char *shortestPalindrome(char *s) {
  int n = strlen(s), dropped, right = 0, left = 0;
  int *lut = (int *)malloc((n >> 1) * sizeof(int));
  char *ans = (char *)malloc((n << 1) * sizeof(char));
  if (n < 2)
    return s;
  lut[right++] = 0;
  while (right < n >> 1) {
    if (s[right] == s[left])
      lut[right++] = ++left;
    else if (!left)
      lut[right++] = left;
    else
      left = lut[--left];
  }
  dropped = left = 0;
  right = --n;
  while (left < right)
    if (s[left] == s[right]) {
      left++;
      right--;
    } else if (left && lut[left - 1]) {
      left = lut[--left];
      dropped = n - right - left;
    } else {
      left = 0;
      right--;
      dropped = n - right;
    }
  free(lut);
  for (left = 0; left < dropped; left++)
    ans[left] = s[n - left];
  for (left, right = 0; right <= n; left++, right++)
    ans[left] = s[right];
  ans[left] = '\0';
  return ans;
}
int main() {
  char *s1 = "aacecaaa", *s2 = "abcd";
  printf("%s\n", shortestPalindrome(s1)); // expect: aaacecaaa
  printf("%s\n", shortestPalindrome(s2)); // expect: dcbabcd
}
