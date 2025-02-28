// 1092. Shortest Common Supersequence
#include "leetcode.h"

/*
 * given two strings 'str1' and 'str2', return the shortest string that has both
 * str1 and str2 as subsequences. if there are multiple valid strings, return
 * any of them. a string 's' is a supersequence if string 't' if deleting some
 * number of characters from 't' (possibly 0) results in string 's'.
 */

struct letters {
  int len;
  int att;
};

void check(char *str1, char *str2, struct letters **list, int i, int j) {
  if (list[i][j].len)
    return;
  if (str1[i] == str2[j]) {
    check(str1, str2, list, i + 1, j + 1);
    list[i][j].len = list[i + 1][j + 1].len + 1;
    list[i][j].att = -1;
  } else {
    check(str1, str2, list, i + 1, j);
    int k = j + 1;
    while (str2[k] != str1[i] && str2[k] != '\0')
      k++;
    if (str2[k] == '\0') {
      list[i][j].len = list[i + 1][j].len + 1;
      list[i][j].att = 0;
      return;
    } else
      check(str1, str2, list, i, k);
    if (list[i + 1][j].len + 1 < k - j + list[i][k].len) {
      list[i][j].len = list[i + 1][j].len + 1;
      list[i][j].att = 0;
    } else {
      list[i][j].len = k - j + list[i][k].len;
      list[i][j].att = k - j;
    }
  }
}

char *shortestCommonSupersequence(char *str1, char *str2) {
  int n1 = strlen(str1), n2 = strlen(str2);
  struct letters **list =
      (struct letters **)malloc((n1 + 1) * sizeof(struct letters *));
  for (int i = 0; i < n1; i++) {
    list[i] = (struct letters *)calloc(n2 + 1, sizeof(struct letters));
    list[i][n2].len = n1 - i + 1;
  }
  list[n1] = (struct letters *)malloc((n2 + 1) * sizeof(struct letters));
  for (int i = 0; i < n2; i++) {
    list[n1][i].len = n2 - i + 1;
    list[n1][i].att = 1;
  }
  list[n1][n2].len = 1;
  check(str1, str2, list, 0, 0);
  char *ans = (char *)malloc(list[0][0].len * sizeof(char));
  int cnt = 0, m = 0, n = 0;
  while (list[m][n].len != 1) {
    if (list[m][n].att == -1) {
      ans[cnt] = str1[m];
      cnt++, m++, n++;
    } else if (!list[m][n].att) {
      ans[cnt] = str1[m];
      cnt++, m++;
    } else {
      for (int k = list[m][n].att; k; k--) {
        ans[cnt] = str2[n];
        cnt++, n++;
      }
    }
  }
  ans[cnt] = '\0';
  for (int i = 0; i <= n1; i++)
    free(list[i]);
  free(list);
  return ans;
}

int main() {
  char *s11 = "abac", *s21 = "cab", *s12 = "aaaaaaaa", *s22 = "aaaaaaaa";
  printf("%s\n", shortestCommonSupersequence(s11, s21)); // expect: cabac
  printf("%s\n", shortestCommonSupersequence(s12, s22)); // expect: aaaaaaaa
}
