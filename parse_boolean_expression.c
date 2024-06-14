// 1106. Parsing A Boolean Expression
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

#define IS_VALUE(c) ((c) == 't' || (c) == 'f')
#define IS_OPERA(c) ((c) == '!' || (c) == '&' || (c) == '|')

static char *expr, *s;

bool parse() {
  if (IS_VALUE(*s))
    return (*s++) == 't';
  if (IS_OPERA(*s)) {
    char op = *s;
    s++;
    if (*s != '(') {
      fprintf(stderr, "error: unexpected char '%c' at pos %ld, expects '('\n",
              *s, s - expr);
      exit(1);
    }
    s++;
    bool b = false;
    if (op == '!')
      b = !parse();
    else {
      b = parse();
      while (*s == ',') {
        s++;
        bool n = parse();
        if (op == '&')
          b = b && n;
        else
          b = b || n;
      }
    }
    if (*s != ')') {
      fprintf(stderr, "error: unexpected char '%c' at pos %ld, expects ')'\n",
              *s, s - expr);
      exit(1);
    }
    s++;
    return b;
  }
  fprintf(stderr, "error: unexpected char '%c' at pos %ld\n", *s, s - expr);
  exit(1);
}

bool parseBoolExpr(char *expression) {
  expr = expression;
  s = expression;
  return parse();
}

int main() {
  char e1[] = {"&(|(f))"}, e2[] = {"|(f,f,f,t)"}, e3[] = {"!(&(f,t))"};
  printf("%d\n", parseBoolExpr(e1)); // expect: 0
  printf("%d\n", parseBoolExpr(e2)); // expect: 1
  printf("%d\n", parseBoolExpr(e3)); // expect: 1
}
