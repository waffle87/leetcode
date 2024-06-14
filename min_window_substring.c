// 76. Minimum Window Substring
#include "leetcode.h"

/*
 * given two strings 's' and 't' of length 'n' and 'm' respectively, return the
 * minimum window substring of 's' such that every character in 't' (including
 * duplicates) is included in the window. if there is no such substring, return
 * the empty string. the testcases will be generated such that the answer is
 * unique.
 */

char *minWindow(char *s, char *t) {
  int m = strlen(s), n = strlen(t), min = INT_MAX, l = -1, r, match = 0,
      a_idx = -1, r_key, l_key;
  int *alpha = calloc(52, sizeof(int));
  int *alpha_copy = calloc(52, sizeof(int));
  for (int i = 0; i < n; i++)
    (t[i] >= 'a') ? alpha[t[i] - 'a']++ : alpha[t[i] - 'A' + 26]++;

  for (r = 0; r < m; r++) {
    r_key = (s[r] >= 'a') ? r_key = s[r] - 'a' : s[r] - 'A' + 26;

    if (alpha[r_key]) {
      if (l == -1)
        l = r;
      alpha_copy[r_key]++;
      if (alpha_copy[r_key] <= alpha[r_key]) {
        match++;
        if (match == n) {
          l_key = (s[l] >= 'a') ? s[l] - 'a' : s[l] - 'A' + 26;
          while (match == n || !alpha[l_key]) {
            if (alpha[l_key]) {
              alpha_copy[l_key]--;
              if (alpha_copy[l_key] < alpha[l_key]) {
                if ((r - l + 1) < min) {
                  min = r - l + 1;
                  a_idx = l;
                }
                match--;
              }
            }
            l++;
            if (l < m)
              l_key = (s[l] >= 'a') ? s[l] - 'a' : s[l] - 'A' + 26;
            else
              break;
          }
        }
      }
    }
  }
  if (a_idx == -1)
    return "";
  char *ans = malloc((min + 1) * sizeof(char));
  ans[min] = '\0';
  strncpy(ans, &s[a_idx], min);
  return ans;
}

int main() {
  char *s1 = "ADOBECODEBANC", *t1 = "ABC";
  char *s2 = "a", *t2 = "a";
  char *s3 = "a", *t3 = "aa";
  printf("%s\n", minWindow(s1, t1)); // expect: BANC
  printf("%s\n", minWindow(s2, t2)); // expect: a
  printf("%s\n", minWindow(s3, t3)); // expect: null
}
