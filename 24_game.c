// 679. 24 Game
#include "leetcode.h"

/*
 * given an integer array 'cards' of length 4. you have four cards, each
 * containing a number in the range '[1,9]'. you should arrange the numbers on
 * these cards in a mathematical expression using the operators '[+,-,*,/]' and
 * the parenthesis '(' and ')' to get value 24. you are restricted to the
 * following rules:
 * - the division operation represents real division, not integer division
 * - every operation done is between two numbers. in particular, we cannot use
 * '-' as a unary operator
 * - you cannot concatenate numbers together
 * return true if you can get such expression that evaluates to 24 and false
 * otherwise.
 */

float calculate(float n1, float n2, char operand) {
  switch (operand) {
  case '+':
    return n1 + n2;
  case '-':
    return n1 - n2;
  case '*':
    return n1 * n2;
  case '/':
    if (!n2)
      return -1;
    return n1 / n2;
  }
  return 0;
}

bool judgePoint24(int *cards, int cardsSize) {
  int i, j, k, l;
  int x, y, z;
  int t;
  int opersSize = 4;
  int sum = 6;
  float cal[3];
  int sign[3];
  float ans;
  char oper[4] = {'+', '-', '*', '/'};
  for (i = 0; i < cardsSize; i++)
    for (j = 0; j < cardsSize; j++) {
      if (j == i)
        continue;
      for (k = 0; k < cardsSize; k++) {
        if (k == i || k == j)
          continue;
        l = sum - (i + j + k);
        for (x = 0; x < opersSize; x++) {
          sign[0] = 0;
          if (x <= 1)
            sign[0] = 1;
          for (y = 0; y < opersSize; y++) {
            sign[1] = 0;
            if (y <= 1)
              sign[1] = 1;
            for (z = 0; z < opersSize; z++) {
              sign[2] = 0;
              if (z <= 1)
                sign[2] = 1;
              if ((sign[0] ^ sign[1]) || (sign[0] ^ sign[2]) ||
                  (sign[1] ^ sign[2])) {
                cal[0] = calculate(cards[i], cards[j], oper[x]);
                cal[1] = calculate(cal[0], cards[k], oper[y]);
                cal[2] = calculate(cal[1], cards[l], oper[z]);
                ans = cal[2] > 24 ? cal[2] - 24 : 24 - cal[2];
                if (ans < 0.0001)
                  return true;
                cal[0] = calculate(cards[i], cards[j], oper[x]);
                cal[2] = calculate(cards[k], cards[l], oper[z]);
                cal[1] = calculate(cal[0], cal[2], oper[y]);
                ans = cal[1] > 24 ? cal[1] - 24 : 24 - cal[1];
                if (ans < 0.0001)
                  return true;
                cal[1] = calculate(cards[j], cards[k], oper[y]);
                cal[0] = calculate(cards[i], cal[1], oper[x]);
                cal[2] = calculate(cal[0], cards[l], oper[z]);
                ans = cal[2] > 24 ? cal[2] - 24 : 24 - cal[2];
                if (ans < 0.0001)
                  return true;
                cal[1] = calculate(cards[j], cards[k], oper[y]);
                cal[2] = calculate(cal[1], cards[l], oper[z]);
                cal[0] = calculate(cards[i], cal[2], oper[x]);
                ans = cal[0] > 24 ? cal[0] - 24 : 24 - cal[0];
                if (ans < 0.0001)
                  return true;
                cal[2] = calculate(cards[k], cards[l], oper[z]);
                cal[1] = calculate(cards[j], cal[2], oper[y]);
                cal[0] = calculate(cards[i], cal[1], oper[x]);
                ans = cal[0] > 24 ? cal[0] - 24 : 24 - cal[0];
                if (ans < 0.0001)
                  return true;
              } else {
                cal[0] = calculate(cards[i], cards[j], oper[x]);
                cal[1] = calculate(cal[0], cards[k], oper[y]);
                cal[2] = calculate(cal[1], cards[l], oper[z]);
                ans = cal[2] > 24 ? cal[2] - 24 : 24 - cal[2];
                if (ans < 0.0001)
                  return true;
              }
            }
          }
        }
      }
    }
  return false;
}

int main() {
  int c1[] = {4, 1, 8, 7}, c2[] = {1, 2, 1, 2};
  printf("%d\n", judgePoint24(c1, ARRAY_SIZE(c1))); // expect: 1
  printf("%d\n", judgePoint24(c2, ARRAY_SIZE(c2))); // expect: 0
}
