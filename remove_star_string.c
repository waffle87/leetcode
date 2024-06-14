// 2390. Removing Stars From a String
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string 's', which contains stars (*). in one operation
 * you can choose a start in 's', remove the closest non-star
 * character to its left, as well remove the star itself.
 * return string after all stars have been removed. note, the
 * input will be generated such that the operation is always
 * possible, and the resulting string will always be unique
 */

char *removeStars(char *s) {
  int n = strlen(s), idx = 0;
  char *stk = malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++) {
    stk[idx] = s[i];
    if (stk[idx] == '*') {
      if (!idx)
        continue;
      else
        idx -= 2;
    }
    idx++;
  }
  stk[idx] = '\0';
  return stk;
}

int main() {
  char s1[] = {"leet**cod*e"}, s2[] = {"erase*****"};
  char *ans1 = removeStars(s1), *ans2 = removeStars(s2);
  for (int i = 0; i < strlen(s1); i++)
    printf("%c", ans1[i]); // expect: lecoe
  printf("\n");
  for (int i = 0; i < strlen(s2); i++)
    printf("%c", ans2[i]); // expect: null
}
