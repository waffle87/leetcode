// 984. String Without AAA or BBB
#include <stdio.h>
#include <stdlib.h>

/*
 * given two integers 'a' and 'b', return any string 's' such that
 * - 's' has length 'a + b' and contains exactly 'a' a letters and exactly 'b' b
 * letters.
 * - the substring 'aaa' does not occur in 's' and
 * - the substring 'bbb' does not occur in 's'
 */

char *strWithout3a3b(int a, int b) {
  int n = a + b;
  char *ans = malloc(n + 1);
  ans[n] = '\0';
  int idx = 0;
  while (a && b) {
    if (a == b) {
      ans[idx] = 'a';
      idx++;
      ans[idx] = 'b';
      idx++;
      a--;
      b--;
    } else if (a > b) {
      ans[idx] = 'a';
      idx++;
      ans[idx] = 'a';
      idx++;
      ans[idx] = 'b';
      idx++;
      a -= 2;
      b--;
    } else {
      ans[idx] = 'b';
      idx++;
      ans[idx] = 'b';
      idx++;
      ans[idx] = 'a';
      idx++;
      a--;
      b -= 2;
    }
  }
  while (a) {
    ans[idx] = 'a';
    idx++;
    a--;
  }
  while (b) {
    ans[idx] = 'b';
    idx++;
    b--;
  }
  return ans;
}

int main() {
  printf("%s\n", strWithout3a3b(1, 2)); // expect: "abb"
  printf("%s\n", strWithout3a3b(4, 1)); // expect: "aabaa"
}
