// 1249. Minimum Remove to Make Valid Parentheses
#include "leetcode.h"

/*
 * given a string s of '(' and ')' and lowercase english characters. your task
 * is to remove the minimum number of parentheses so that the resulting
 * parentheses string is valid and return any valid string. formally, a
 * parentheses string is valid if and only if it is the empty string, contains
 * only lowercase characters, or it can be written as AB where A and B are valid
 * strings, or it can be written as (A) where A is a valid string.
 */

char *minRemoveToMakeValid(char *s) {
  int n = strlen(s), size = 0, p = 0;
  bool *flag = calloc(n, sizeof(bool));
  int *stack = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stack[size] = i;
      size++;
    }
    if (s[i] == ')') {
      if (size)
        size--;
      else
        flag[i] = 1;
    }
  }
  for (int i = 0; i < size; i++)
    flag[stack[i]] = 1;
  char *ans = malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++)
    if (!flag[i])
      ans[p] = s[i], p++;
  ans[p] = '\0';
  return ans;
}

int main() {
  char *s1 = "lee(t(c)o)de)", *s2 = "a)b(c)d", *s3 = "))((";
  printf("%s\n", minRemoveToMakeValid(s1));
  printf("%s\n", minRemoveToMakeValid(s2));
  printf("%s\n", minRemoveToMakeValid(s3));
}
