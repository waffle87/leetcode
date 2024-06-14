// 1208. Get Equal Substrings Within Budget
#include "leetcode.h"

/*
 * you are given two strings 's' and 't' of the same length and an integer
 * 'maxCost'. you want to change 's' to 't'. changing the i'th character of 's'
 * to the i'th character of 't' costs '|s[i] - t[i]|'. return the maximum length
 * of a substring of 's' that can be changed to be the same as the corresponding
 * substring of 't' with a cost less than or equal to 'maxCost'. if there is no
 * substring from 's' that can be changed to its corresponding substring from
 * 't', return 0
 */

int equalSubstring(char *s, char *t, int maxCost) {
  int n = strlen(s), ans = 0, sum = 0, l = 0, r;
  char *diff = (char *)malloc(n * sizeof(char));
  for (int i = 0; i < n; i++)
    diff[i] = abs(s[i] - t[i]);
  for (r = 0; r < n; r++) {
    sum += diff[r];
    if (sum > maxCost) {
      ans = fmax(ans, r - l);
      while (sum > maxCost) {
        sum -= diff[l];
        l++;
      }
    }
  }
  ans = fmax(ans, r - l);
  free(diff);
  return ans;
}

int main() {
  char *s1 = "abcd", *t1 = "bcdf", *s2 = "abcd", *t2 = "cdef", *s3 = "abcd",
       *t3 = "acde";
  printf("%d\n", equalSubstring(s1, t1, 3)); // expect: 3
  printf("%d\n", equalSubstring(s2, t2, 3)); // expect: 1
  printf("%d\n", equalSubstring(s3, t3, 0)); // expect: 1
}
