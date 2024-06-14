// 2272. Substring With Largest Variance
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * the variance of a string is defined as the largest difference between the
 * number of ocurrences of any '2' characters present in the string. note the
 * two characters may or may not be the same. given a string 's', consisting of
 * lowercase english letters only, return the largest variance possible among
 * all substrings 's'. a substring is a contiguous sequence of characters witin
 * a string.
 */

int largestVariance(char *s) {
  int *freq = (int *)calloc(26, sizeof(int));
  for (int i = 0; i < strlen(s); i++)
    freq[s[i] - 'a']++;
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i == j || !freq[i] || !freq[j])
        continue;
      char major = 'a' + i, minor = 'a' + j;
      int major_cnt = 0, minor_cnt = 0, rem = freq[j];
      for (int k = 0; k < strlen(s); k++) {
        if (s[k] == major)
          major_cnt++;

        if (s[k] == minor) {
          minor_cnt++;
          rem--;
        }
        if (minor_cnt)
          ans = fmax(ans, major_cnt - minor_cnt);
        if (major_cnt < minor_cnt && rem) {
          major_cnt = 0;
          minor_cnt = 0;
        }
      }
    }
  }
  return ans;
}
