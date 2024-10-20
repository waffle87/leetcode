// 1106. Parsing A Boolean Expression
#include "leetcode.h"

/*
 * a boolean expression is an expression that evaluates to either 'true' or
 * 'false'. it can be one of the following shapes:
 * - 't' that evaluates to true
 * - 'f' that evaluates to false
 * - '!(subExpr)' that evalutes to the logical not of the inner expression
 * 'subExpr'
 * - '&(subExpr1, subExpr2, ..., subExprn)' that evalutes to the logical AND of
 * the inner expressions 'subExpr1, subExpr2, ..., subExprn' where 'n >= 1'
 * - '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of
 * the inner expressions 'subExpr1, subExpr2, ..., subExprn' where 'n >= 1'
 * given a string 'expression' that represents a boolean expression, return the
 * evaluation of that expression
 */

void substr(char *dst, char *src, int start, int len) {
  strncpy(dst, src + start, len);
  dst[len] = '\0';
}

bool parseBoolExpr(char *expression) {
  int n = strlen(expression);
  if (n == 1)
    return expression[0] == 't';
  if (expression[0] == '!') {
    char sub_expr[n - 2];
    substr(sub_expr, expression, 2, n - 3);
    return !parseBoolExpr(sub_expr);
  }
  bool is_and = expression[0] == '&', ans = is_and;
  int i = 2, j = 2, cnt = 0;
  for (; ans == is_and && i < n; ++i) {
    if (expression[i] == '(')
      ++cnt;
    if (expression[i] == ')')
      --cnt;
    if (i == n - 1 || (expression[i] == ',' && !(cnt))) {
      char sub_expr[i - j + 1];
      substr(sub_expr, expression, j, i - 1);
      if (is_and)
        ans &= parseBoolExpr(sub_expr);
      else
        ans |= parseBoolExpr(sub_expr);
      j = i + 1;
    }
  }
  return ans;
}

int main() {
  char e1[] = {"&(|(f))"}, e2[] = {"|(f,f,f,t)"}, e3[] = {"!(&(f,t))"};
  printf("%d\n", parseBoolExpr(e1)); // expect: 0
  printf("%d\n", parseBoolExpr(e2)); // expect: 1
  printf("%d\n", parseBoolExpr(e3)); // expect: 1
}
