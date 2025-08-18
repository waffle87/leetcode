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

#define EPSILON 0.00000001

bool backtrack(double *cards, int cardsSize) {
  if (cardsSize == 1)
    return fabs(cards[0] - 24) < EPSILON;
  double *new = NULL;
  for (int i = 0; i + 1 < cardsSize; i++)
    for (int j = 0; j < cardsSize; j++) {
      int n = cardsSize - 1, newSize = 0;
      new = (double *)calloc(sizeof(double), n);
      for (int k = 0; k < cardsSize; k++)
        if (k != i && k != j)
          new[newSize++] = cards[k];
      new[newSize++] = cards[i] + cards[j];
      if (backtrack(new, newSize))
        return true;
      newSize--;
      new[newSize++] = cards[i] - cards[j];
      if (backtrack(new, newSize))
        return true;
      newSize--;
      new[newSize++] = cards[j] - cards[i];
      if (backtrack(new, newSize))
        return true;
      newSize--;
      new[newSize++] = cards[i] * cards[j];
      if (backtrack(new, newSize))
        return true;
      newSize--;
      new[newSize++] = cards[i] / cards[j];
      if (backtrack(new, newSize))
        return true;
      newSize--;
      new[newSize++] = cards[j] / cards[i];
      if (backtrack(new, newSize))
        return true;
    }
  if (new)
    free(new);
  return false;
}

bool judgePoint24(int *cards, int cardsSize) {
  double *newCards = (double *)calloc(sizeof(double), cardsSize);
  bool ans = backtrack(newCards, cardsSize);
  free(newCards);
  return ans;
}

int main() {
  int c1[] = {4, 1, 8, 7}, c2[] = {1, 2, 1, 2};
  printf("%d\n", judgePoint24(c1, ARRAY_SIZE(c1))); // expect: 1
  printf("%d\n", judgePoint24(c2, ARRAY_SIZE(c2))); // expect: 0
}
