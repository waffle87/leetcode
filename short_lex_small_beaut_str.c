// 2904. Shortest and Lexicographically Smallest Beautiful String
#include "leetcode.h"

/*
 * you are given a binary string 's' and a positive integer 'k'. a substring of
 * 's' is beautiful if the number of 1's in it is exactly 'k'. let 'len' be the
 * length of the shortest beautiful substring. return the lexicographically
 * smallest beautiful substring of 's' with length equal to 'len'. if 's'
 * doesn't contain a beautiful substring, return an empty string.
 */

char *shortestBeautifulSubstring(char *s, int k) {
  int n = strlen(s), m = n + 1, l = 0;
  int cnt1 = 0, len = 0;
  __int128 x = (__int128)-1, win = 0;
  for (int r = 0; r < n; r++) {
    bool one = (s[r] == '1');
    win = (win << 1) | one;
    cnt1 += one;
    len++;
    while (cnt1 > k || (cnt1 == k && s[l] == '0')) {
      win &= ((__int128)1 << (len - 1)) - 1;
      len--;
      cnt1 -= (s[l] == '1');
      l++;
    }
    if (cnt1 == k) {
      if (len < m) {
        m = len;
        x = win;
      } else if (len == m)
        x = fmin(x, win);
    }
  }
  if (m == n + 1) {
    char *ans = (char *)malloc(1 * sizeof(char));
    ans[0] = '\0';
    return ans;
  }
  char *ans = (char *)malloc((m + 1) * sizeof(char));
  for (int i = 0; i < m; i++) {
    int bit = (x >> (m - 1 - i)) & 1;
    ans[i] = bit ? '1' : '0';
  }
  ans[m] = '\0';
  return ans;
}

int main() {
  char *s1 = "100011001", *r1 = "11001";
  char *s2 = "1011", *r2 = "11";
  char *s3 = "000", *r3 = "";
  char *sbs1 = shortestBeautifulSubstring(s1, 5);
  char *sbs2 = shortestBeautifulSubstring(s2, 2);
  char *sbs3 = shortestBeautifulSubstring(s3, 1);
  printf("%s\n", sbs1);
  assert(!strcmp(r1, sbs1));
  printf("%s\n", sbs2);
  assert(!strcmp(r2, sbs2));
  printf("%s\n", sbs3);
  assert(!strcmp(r3, sbs3));
  free(sbs1);
  free(sbs2);
  free(sbs3);
}
