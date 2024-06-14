// 808. Soup Servings
#include <stdio.h>
#include <stdlib.h>

/*
 * there are two types of soup: type a, and type b. initially, we have 'n' ml of
 * each type of soup. there are four kinds of operations:
 * 1. serve 100 ml of soup a and 0ml of soup b
 * 2. serve 75ml of soup a and 25ml of soup b
 * 3. serve 50ml of soup a and 50ml of soup b
 * 4. serve 25ml of soup a and 75ml of soup b
 * when we serve some soup, we give it to someone, and we no longer have it.
 * each turn, we will choose from the four operations with an equal probability
 * of '0.25'. if the remaining volume of soup is not enough to complete the
 * operation, we will serve as much as possible. we stop once we no longer have
 * some quantity of both types of soup. note that we do not have an operation
 * where all 100 ml's of soup b are used first. return the probability that soup
 * a will be empty first, plus half the probability that a and b become empty at
 * the same time. answers within '10^-5' of the actual answer will be accepted.
 */

double process(int a, int b, double **record) {
  if (a <= 0 && b <= 0)
    return 0.5;
  if (a <= 0)
    return 1.0;
  if (b <= 0)
    return 0;
  if (record[a][b])
    return record[a][b];
  record[a][b] =
      0.25 * (process(a - 4, b, record) + process(a - 3, b - 1, record) +
              process(a - 2, b - 2, record) + process(a - 1, b - 3, record));
  return record[a][b];
}

double soupServings(int n) {
  double **record = malloc(150 * sizeof(double *));
  for (int i = 0; i < 150; i++)
    record[i] = calloc(150, sizeof(double));
  double ans = n >= 3600 ? 1.0 : process((n + 24) / 25, (n + 24) / 25, record);
  for (int i = 0; i < 150; i++)
    free(record[i]);
  free(record);
  return ans;
}

int main() {
  printf("%f\n", soupServings(50));  // expect: 0.625000
  printf("%f\n", soupServings(100)); // expect: 0.71875
}
