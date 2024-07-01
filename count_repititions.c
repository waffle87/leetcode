// 466. Count The Repetitions
#include "leetcode.h"

/*
 * we define 'str = [s, n]' as the string 'str' which consists of the string 's'
 * concatenated 'n' times. for example 'str == ["abc", 3] = "abcabcabc'. we
 * define that strng 's1' can be obtained from string 's2' if we can remove some
 * characters from 's2' such that it becomes 's1'. you are given two strings
 * 's1' and 's2' and two integers 'n1' and 'n2'. you have the two strings 'str1
 * = [s1, n1]' and 'str2 = [s2, n2]'. return the maximum integer 'm' such that
 * 'str = [str2, m]' can be obtained from 'str1'
 */

int getMaxRepetitions(char *s1, int n1, char *s2, int n2) {
  int a = 0, b = 0, c = 0, d = 0, e = -1, f = 0;
  char s1r, s2r = s2[b];
  while (c < n1) {
    if (!(s1r = s1[a++])) {
      c++;
      a = 0;
      continue;
    }
    if (s2r == s1r) {
      if (e == -1)
        e = a;
      else if ((e == a) && (b == 0))
        return ((((n1 * d) / c) - (f == c)) / n2);
      s2r = s2[++b];
    }
    if (!s2r) {
      s2r = s2[(b = 0)];
      d++;
      f = c;
    }
  }
  return (d / n2);
}

int main() {
  char *s11 = "acb", *s21 = "ab", *s12 = "acb", *s22 = "acb";
  printf("%d\n", getMaxRepetitions(s11, 4, s21, 2)); // expect: 2
  printf("%d\n", getMaxRepetitions(s12, 1, s22, 1)); // expect: 1
}
