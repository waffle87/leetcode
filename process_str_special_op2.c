// 3614. Process String with Special Operations II
#include "leetcode.h"

/*
 * you are given a string 's' consisting of lowercase english letters and the
 * special characters '*', '#', and '%'. you are also given an integer 'k'.
 * build a new string 'result' by processing 's' according to the following
 * rules from left to right: if the letter is a lowercase english letter append
 * it to 'result'. a '*' removes the last character from 'result'. a '#'
 * duplicates the current 'result' and appends it to itself. a '%' reverses the
 * current 'result'. return the k'th character of the final string 'result'. if
 * 'k' is out of the bounds of 'result', return '.'.
 */

char processStr(char *s, long long k) {
  long long l = 0, p = k;
  for (int i = 0; s[i] != '\0'; i++) {
    char c = s[i];
    if (c == '*') {
      if (l > 0)
        l--;
    } else if (c == '#')
      l *= 2;
    else if (c == '%')
      continue;
    else
      l++;
  }
  if (k >= l)
    return '.';
  int n = 0;
  while (s[n] != '\0')
    n++;
  for (int i = n - 1; i >= 0; i--) {
    char c = s[i];
    if (c == '*')
      l++;
    else if (c == '#') {
      if (p >= l / 2)
        p -= l / 2;
      l /= 2;
    } else if (c == '%')
      p = l - 1 - p;
    else {
      if (l == p + 1)
        return c;
      l--;
    }
  }
  return '.';
}

int main() {
  char *s1 = "a#b%*";
  char *s2 = "cd%#*#";
  char *s3 = "z*#";
  char r1 = processStr(s1, 1);
  char r2 = processStr(s2, 3);
  char r3 = processStr(s3, 0);
  printf("%c\n", r1);
  assert(r1 == 'a');
  printf("%c\n", r2);
  assert(r2 == 'd');
  printf("%c\n", r3);
  assert(r3 == '.');
}
