// 22. Generate Parentheses
#include "leetcode.h"

/*
 * given 'n' pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 */

char **generateParenthesis(int n, int *returnSize) {
  char ***dp = (char ***)malloc((n + 1) * sizeof(char **));
  int *sizes = (int *)calloc(n + 1, sizeof(int));
  dp[0] = (char **)malloc(sizeof(char *));
  dp[0][0] = strdup("");
  sizes[0] = 1;
  for (int i = 1; i <= n; i++) {
    int cap = 10000;
    dp[i] = (char **)malloc(cap * sizeof(char *));
    sizes[i] = 0;
    for (int j = 0; j < i; j++) {
      for (int l = 0; l < sizes[j]; l++) {
        for (int r = 0; r < sizes[i - 1 - j]; r++) {
          char *left = dp[j][l];
          char *right = dp[i - 1 - j][r];
          int len = strlen(left) + strlen(right) + 3;
          char *str = (char *)malloc(len * sizeof(char));
          sprintf(str, "(%s)%s", left, right);
          dp[i][sizes[i]++] = str;
        }
      }
    }
  }
  *returnSize = sizes[n];
  free(sizes);
  return dp[n];
}

int main() {
  int rs1, rs2;
  char *r1[] = {"((()))", "(()())", "(())()", "()(())", "()()()"};
  char *r2[] = {"()"};
  char **gp1 = generateParenthesis(3, &rs1);
  char **gp2 = generateParenthesis(1, &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%s ", gp1[i]);
    assert(!strcmp(gp1[i], r1[i]));
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%s ", gp2[i]);
    assert(!strcmp(gp2[i], r2[i]));
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(gp1[i]);
  free(gp1);
  for (int i = 0; i < rs2; i++)
    free(gp2[i]);
  free(gp2);
}
