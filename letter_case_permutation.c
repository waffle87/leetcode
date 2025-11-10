// 784. Letter Case Permutation
#include "leetcode.h"

/*
 * given a string 's', you can transform every letter individually to be
 * lowercase or uppercase. return a list of all possible strings we could
 * create. return the output in any order.
 */

void helper(char *s, int n, int j, char **res, int *cnt, char *str) {
  if (j == n) {
    char *tmp = (char *)malloc((n + 1) * sizeof(char));
    memcpy(tmp, str, n);
    tmp[n] = '\0';
    res[(*cnt)++] = tmp;
    return;
  }
  char c1 = *(s + j);
  if (!(c1 >= '0' && c1 <= '9')) {
    char c2 = c1 >= 'a' ? c1 - ('a' - 'A') : c1 + ('a' - 'A');
    str[j] = c2;
    helper(s, n, j + 1, res, cnt, str);
  }
  str[j] = c1;
  helper(s, n, j + 1, res, cnt, str);
}

char **letterCasePermutation(char *s, int *returnSize) {
  char *perm = s;
  int total = 1, n = 0, cnt = 0;
  while (*perm) {
    if (!(*perm >= '0' && *perm <= '9'))
      total *= 2;
    perm++;
    n++;
  }
  char **ans = (char **)malloc(total * sizeof(char *));
  char *str = malloc((n + 1) * sizeof(char));
  helper(s, n, 0, ans, &cnt, str);
  *returnSize = total;
  return ans;
}

int main() {
  char *s1 = "a1b2", *s2 = "3z4";
  int rs1, rs2;
  char **lcp1 = letterCasePermutation(s1, &rs1);
  char **lcp2 = letterCasePermutation(s2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", lcp1[i]); // expect: ["a1b2","a1B2","A1b2","A1B2"]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", lcp2[i]); // expect: ["3z4","3Z4"]
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(lcp1[i]);
  free(lcp1);
  for (int i = 0; i < rs2; i++)
    free(lcp2[i]);
  free(lcp2);
}
