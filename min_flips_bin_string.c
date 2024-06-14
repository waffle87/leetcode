// 1888. Minimum Number of Flips to Make the Binary String Alternating
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * you are given a binary string 's'. you are allowed to perform two types of
 * operations on the string in any sequence: 1: remove the character at the
 * start of the string 's' and append it to the end of the string. 2: pick any
 * characters in 's' and flip its value, ie. if its value is 0 it becomes 1 and
 * vice versa. return the minimum number of type-2 operations needed to perform
 * such that 's' becomes alternating. the string is called alternating if no two
 * adjacent characters are equal. for example, the strings "010" and "1010" are
 * alternating, while the string "0110" is not.
 */

int minFlips(char *s) {
  int n = strlen(s), idx = 0, min_ops = INT_MAX, diff1 = 0, diff2 = 0, left = 0,
      right = 0;
  char *g_str = calloc(1, 2 * n + 1);
  char *z_tar = calloc(1, 2 * n + 1);
  char *o_tar = calloc(1, 2 * n + 1);
  strcat(g_str, s);
  strcat(g_str, s);
  for (int i = 0; i < 2 * n; i++) {
    z_tar[idx] = i % 2 ? '1' : '0';
    o_tar[idx++] = i % 2 ? '0' : '1';
  }
  while (right < 2 * n) {
    diff1 += g_str[right] != z_tar[right];
    diff2 += g_str[right] != o_tar[right];
    if (right - left + 1 > n) {
      if (g_str[left] != z_tar[left])
        diff1--;
      if (g_str[left] != o_tar[left])
        diff2--;
      left++;
    }
    if (right - left + 1 == n)
      min_ops = fmin(min_ops, fmin(diff1, diff2));
    right++;
  }
  return min_ops;
}

int main() {
  char s1[] = {"111000"}, s2[] = {"010"}, s3[] = {"1110"};
  printf("%d\n", minFlips(s1)); // expect: 2
  printf("%d\n", minFlips(s2)); // expect: 0
  printf("%d\n", minFlips(s3)); // expect: 1
}
