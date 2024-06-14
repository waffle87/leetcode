// 779. K-th Symbol in Grammar
#include <stdio.h>
#include <stdlib.h>

/*
 * we build a table of 'n' rows (1-indexed) we start by writing 0 in the first
 * row. now in every subsequent row, we look at the previous row and replace
 * each occurence of zero with '01', and each occurence of 1 with '10'. for
 * example for 'n = 3', the first row is the 0, the second row is the 01, and
 * the third row is 0110. given two integer 'n' and 'k', return the k'th
 * (1-indexed) symbol in the n'th row of a table of 'n' rows.
 */

int kthGrammar(int n, int k) {
  if (n == 1)
    return 0;
  if (k % 2 == 1)
    return kthGrammar(n - 1, (k + 1) / 2);
  else
    return (kthGrammar(n - 1, k / 2) == 0) ? 1 : 0;
}

int main() {
  printf("%d\n", kthGrammar(1, 1)); // expect: 0
  printf("%d\n", kthGrammar(2, 1)); // expect: 0
  printf("%d\n", kthGrammar(2, 2)); // expect: 1
}
