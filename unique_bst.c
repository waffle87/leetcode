// 96. Unique Binary Search Trees
#include <stdio.h>

/*
 * given an integer 'n', return the number of structurally unique BST's which
 * has exactly 'n' nodes of unique values from 1 to 'n'
 */

int numTrees(int n) {
  int rem[n + 1];
  if (!n)
    return 1;
  if (n == 1 || n == 2)
    return n;
  rem[0] = 1;
  rem[1] = 1;
  rem[2] = 2;
  for (int i = 3; i <= n; i++) {
    rem[i] = 0;
    for (int j = 1; j <= i; j++)
      rem[i] = rem[i] + rem[i - j] * rem[j - 1];
  }
  return rem[n];
}

int main() {
  printf("%d\n", numTrees(3)); // expect: 5
  printf("%d\n", numTrees(1)); // expect: 1
}
