// 301. Remove Invalid Parentheses
#include "leetcode.h"

/*
 * given a string 's' that contains parentheses and letters, remove the minimum
 * number of invalid parentheses to make the input string valid. return a list
 * of unique strings that are valid with the minimum number of removals. you may
 * return the answer in any order.
 */

bool valid(char *s) {
  int balance = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '(')
      balance++;
    else if (s[i] == ')')
      balance--;
    if (balance < 0)
      return false;
  }
  return !balance;
}

void backtrack(char *s, int start, int left, int right, char **res,
               int *res_size) {
  if (!left && !right) {
    if (valid(s)) {
      res[*res_size] = strdup(s);
      (*res_size)++;
    }
    return;
  }
  int n = strlen(s);
  for (int i = start; s[i]; i++) {
    if (i > start && s[i] == s[i - 1])
      continue;
    if (s[i] == '(' && left > 0) {
      char *s1 = (char *)malloc(n * sizeof(char));
      strncpy(s1, s, i);
      strcpy(s1 + i, s + i + 1);
      backtrack(s1, i, left - 1, right, res, res_size);
      free(s1);
    }
    if (s[i] == ')' && right > 0) {
      char *s1 = (char *)malloc(n * sizeof(char));
      strncpy(s1, s, i);
      strcpy(s1 + i, s + i + 1);
      backtrack(s1, i, left, right - 1, res, res_size);
      free(s1);
    }
  }
}

char **removeInvalidParentheses(char *s, int *returnSize) {
  int left = 0, right = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '(')
      left++;
    else if (s[i] == ')') {
      if (left > 0)
        left--;
      else
        right++;
    }
  }
  char **ans = (char **)malloc(1000 * sizeof(char *));
  *returnSize = 0;
  backtrack(s, 0, left, right, ans, returnSize);
  return ans;
}

int main() {
  char *s1 = "()())()", *r1[] = {"(())() ", "()()()"};
  char *s2 = "(a)())()", *r2[] = {"(a())() ", "(a)()()"};
  char *s3 = ")(", *r3[] = {""};
  int rs1, rs2, rs3;
  char **rip1 = removeInvalidParentheses(s1, &rs1);
  char **rip2 = removeInvalidParentheses(s2, &rs2);
  char **rip3 = removeInvalidParentheses(s3, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%s ", rip1[i]);
    assert(!strcmp(rip1[i], r1[i]));
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%s ", rip2[i]);
    assert(!strcmp(rip2[i], r2[i]));
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%s ", rip3[i]);
    assert(!strcmp(rip3[i], r3[i]));
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(rip1[i]);
  free(rip1);
  for (int i = 0; i < rs2; i++)
    free(rip2[i]);
  free(rip2);
  for (int i = 0; i < rs3; i++)
    free(rip3[i]);
  free(rip3);
}
