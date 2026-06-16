// 3612. Process String with Special Operations I
#include "leetcode.h"

/*
 * you are given a string 's' containing lowercase english letters and the
 * special characters '*', '#', and '%'. build a new string 'result' by
 * processing 's' according to the following rules from left to right: if the
 * letter is a lowercase english letter append it to 'result'. a '*' removes the
 * last character from 'result'. a '#' duplicates the current 'result' and
 * appends it to itself. a '%' reverses the current 'result'. return the
 * resulting string.
 */

char *processStr(char *s) {
  int cap = 1024, n = 0;
  char *ans = (char *)malloc(cap * sizeof(char));
  for (int i = 0; s[i] != '\0'; i++) {
    char c = s[i];
    if (c == '*') {
      if (n > 0)
        n--;
    } else if (c == '#') {
      while (n * 2 + 1 > cap) {
        cap *= 2;
        ans = (char *)realloc(ans, cap);
      }
      memcpy(ans + n, ans, n);
      n *= 2;
    } else if (c == '%') {
      for (int l = 0, r = n - 1; l < r; l++, r--) {
        char temp = ans[l];
        ans[l] = ans[r];
        ans[r] = temp;
      }
    } else {
      if (n + 2 > cap) {
        cap *= 2;
        ans = (char *)realloc(ans, cap);
      }
      ans[n++] = c;
    }
  }
  ans[n] = '\0';
  return ans;
}

int main() {
  char *s1 = "a#b%*", *r1 = "ba";
  char *s2 = "z*#", *r2 = "";
  char *ps1 = processStr(s1);
  char *ps2 = processStr(s2);
  printf("%s\n", ps1);
  assert(!strcmp(ps1, r1));
  printf("%s\n", ps2);
  assert(!strcmp(ps2, r2));
}
