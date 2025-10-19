// 1625. Lexicographically Smallest String After Applying Operations
#include "leetcode.h"

/*
 * you are given a string 's' of even length consisting of digits from 0 to 9,
 * and two integers 'a' and 'b'. you can apply either of the following two
 * operations any number of times in any order on 's': add 'a' to all odd
 * indices of 's', or rotate 's' to the right by 'b' positions. return the
 * lexicographically smallest string you can obtain by applying the above
 * operations. a string 'a' is lexicographically smaller than a string 'b' if in
 * the first position where 'a' and 'b' differ, string 'a' has a letter that
 * appears earlier in the alphabet than the corresponding letter in 'b'.
 */

char *findLexSmallestString(char *s, int a, int b) {
  int n = strlen(s);
  bool *vis = (bool *)calloc(n, sizeof(int));
  char *ans = (char *)calloc(n + 1, sizeof(char));
  strcpy(ans, s);
  char *str = (char *)malloc((2 * n + 1) * sizeof(char));
  sprintf(str, "%s%s", s, s);
  for (int i = 0; !vis[i]; i = (i + b) % n) {
    vis[i] = true;
    for (int j = 0; j < 10; j++) {
      int lim = !(b % 2) ? 0 : 9;
      for (int k = 0; k <= lim; k++) {
        char *tmp = (char *)malloc((n + 1) * sizeof(char));
        strncpy(tmp, str + i, n);
        tmp[n] = '\0';
        for (int p = 1; p < n; p += 2)
          tmp[p] = '0' + (tmp[p] - '0' + j * a) % 10;
        for (int p = 0; p < n; p += 2)
          tmp[p] = '0' + (tmp[p] - '0' + k * a) % 10;
        if (strcmp(tmp, ans) < 0)
          strcpy(ans, tmp);
        free(tmp);
      }
    }
  }
  free(vis);
  free(str);
  return ans;
}

int main() {
  char *s1 = "5525", *flss1 = findLexSmallestString(s1, 9, 2);
  char *str = "74", *flss2 = findLexSmallestString(str, 5, 1);
  char *s3 = "0011", *flss3 = findLexSmallestString(s3, 4, 2);
  printf("%s\n", flss1); // expect: 2050
  printf("%s\n", flss2); // expect: 24
  printf("%s\n", flss3); // expect:  0011
  free(flss1);
  free(flss2);
  free(flss3);
}
