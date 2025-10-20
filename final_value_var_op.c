// 2011. Final Value of Variable After Performing Operations
#include "leetcode.h"

/*
 * there is a programming language with only four operations and one variable
 * 'x': '++x' and 'x++' increments the value of the variable 'x' by 1, and '--x'
 * and 'x--' decrements the value of the variable 'x' by 1. initially, the value
 * of 'x' is 0. given an array of strings 'operations' containing a list of
 * operations, return the final value of 'x' after performing all the
 * operations.
 */

int finalValueAfterOperations(char **operations, int operationsSize) {
  int x = 0;
  for (int i = 0; i < operationsSize; i++) {
    char *op = operations[i];
    if (!strcmp(op, "X++") || !strcmp(op, "++X"))
      x++;
    else
      x--;
  }
  return x;
}

int main() {
  char *o1[] = {"--X", "X++", "X++"};
  char *o2[] = {"++X", "++X", "X++"};
  char *o3[] = {"X++", "++X", "--X", "X--"};
  printf("%d\n",
         finalValueAfterOperations((char **)o1, ARRAY_SIZE(o1))); // expect: 1
  printf("%d\n",
         finalValueAfterOperations((char **)o2, ARRAY_SIZE(o2))); // expect: 3
  printf("%d\n",
         finalValueAfterOperations((char **)o3, ARRAY_SIZE(o3))); // expect: 0
}
