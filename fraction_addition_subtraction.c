// 592. Fraction Addition and Subtraction
#include "leetcode.h"

/*
 * given a string 'expression' representing an expression of fraction addition
 * and subtraction, return the calculation result in string format. the final
 * result should an irreducible fraction. if your final result is an integer,
 * change it to the format of a fraction has a denominator 1. so in this case, 2
 * should be converted to "2/1"
 */

int gcd(int a, int b) {
  if (!(a % b))
    return b;
  return gcd(b, a % b);
}

int numerator(int i, char *exp) {
  char *tmp = "";
  while (exp[i] != '/') {
    tmp += exp[i];
    i++;
  }
  return atoi(tmp);
}

int denominator(int i, char *exp) {
  char *tmp = "";
  while (exp[i] != '/') {
    tmp += exp[i];
    i++;
  }
  return atoi(tmp);
}

char *fractionAddition(char *expression) {
  int s1 = 1, i = 0;
  if (expression[0] == '-') {
    s1 = -1;
    i++;
  }
  int n1 = numerator(i, expression);
  i++;
  int d1 = denominator(i, expression);
  while (i < strlen(expression)) {
    int s2 = expression[i] == '-' ? -1 : 1;
    i++;
    int n2 = numerator(i, expression);
    i++;
    int d2 = denominator(i, expression);
    int lcm = (d2 * d1) / gcd(d1, d2);
    n1 = (s1 * n1 * (lcm / d1) + s2 * n2 * (lcm / d2));
    d1 = lcm;
    if (n1 < 0) {
      s1 = -1;
      n1 *= -1;
    } else
      s1 = 1;
  }
  int g = gcd(n1, d1);
  if (g > 1) {
    n1 /= g;
    d1 /= g;
  }
  int len = 0;
  len += (s1 == -1) ? 1 : 0;
  len += snprintf(NULL, 0, "%d", n1);
  len += 1;
  len += snprintf(NULL, 0, "%d", d1);
  char *res = (char *)malloc(len + 1);
  res[0] = '\0';
  if (s1 == -1)
    strcat(res, "-");
  char buffer[50];
  sprintf(buffer, "%d", n1);
  strcat(res, buffer);
  strcat(res, "/");
  sprintf(buffer, "%d", d1);
  strcat(res, buffer);
  return res;
}

int main() {
  char *e1 = "-1/2+1/2", *e2 = "-1/2+1/2+1/3", *e3 = "1/3-1/2";
  printf("%s\n", fractionAddition(e1)); // expect: 0/1
  printf("%s\n", fractionAddition(e2)); // expect: 1/3
  printf("%s\n", fractionAddition(e3)); // expect: -1/6
}
