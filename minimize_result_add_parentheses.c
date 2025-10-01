// 2232. Minimize Result by Adding Parentheses to Expression
#include "leetcode.h"

/*
 * you are given a 0-indexed string 'expression' of the form 'num1+num2' where
 * 'num1' and 'num2' represent integers. add a pair of parentheses to
 * 'expression' such that after the addition of parentheses, 'expression' is a
 * valid mathematical expression and evaluates to the smallest possible value.
 * the left parenthesis must be added to the left of '+', and the right
 * parenthesis must be added to the right of '+'. return 'expression' after
 * adding a pair of parentheses such that 'expression' evaluates to the smallest
 * possible value. if multiple answers that yield the same result, return any of
 * them.
 */

void helper(char *res, char *expression, int n, int pos) {
  int num = INT_MAX, l = 0, r = 0;
  for (int i = 0; i < pos; i++) {
    int lidx = i, a = 0, c = 0;
    for (int j = lidx; j < pos; j++) {
      a *= 10;
      a += (expression[j] - '0');
    }
    for (int j = 0; j < lidx; j++) {
      c *= 10;
      c += (expression[j] - '0');
    }
    if (!c)
      c++;
    for (int j = n - 1; j > pos; j--) {
      int ridx = j, b = 0, d = 0;
      for (int k = ridx; k > pos; k--)
        b += (expression[k] - '0') * pow(10, ridx - k);
      for (int k = ridx + 1; k < n; k++) {
        d *= 10;
        d += (expression[k] - '0');
      }
      if (!d)
        d++;
      int ans = c * (a + b) * d;
      if (ans < num) {
        num = ans;
        l = lidx;
        r = ridx;
      }
    }
  }
  int idx = 0;
  for (int i = 0; i < n + 3; i++) {
    if (i == l)
      res[i] = '(';
    else if (i == r + 2)
      res[i] = ')';
    else
      res[i] = expression[idx++];
  }
}

char *minimizeResult(char *expression) {
  int n = strlen(expression), pos = 0;
  for (int i = 0; i < n; i++)
    if (expression[i] == '+') {
      pos = i;
      break;
    }
  char *ans = (char *)calloc(n + 3, sizeof(char));
  helper(ans, expression, n, pos);
  return ans;
}

int main() {
  char *e1 = "247+38", *mr1 = minimizeResult(e1);
  char *e2 = "12+34", *mr2 = minimizeResult(e2);
  char *e3 = "999+999", *mr3 = minimizeResult(e3);
  printf("%s\n", mr1); // expect: 2(47+38)
  printf("%s\n", mr2); // expect: 1(2+3)4
  printf("%s\n", mr3); // expect: (999+999)
}
